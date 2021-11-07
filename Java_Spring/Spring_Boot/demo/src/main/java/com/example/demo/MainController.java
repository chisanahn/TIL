package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Sort;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import java.util.Optional;

@Controller
@RequestMapping
public class MainController {
    @Autowired
    private TodoListRepository todoListRepository;

    @PostMapping
    public @ResponseBody ResponseEntity<TodoList> addTodoList (@RequestParam String time, @RequestParam String content) {
        TodoList t = new TodoList();
        t.setTime(time);
        t.setContent(content);
        todoListRepository.save(t);
        return new ResponseEntity<TodoList>(t, HttpStatus.OK);
    }

    @GetMapping
    public @ResponseBody Iterable<TodoList> getAllTodoList() {
        return todoListRepository.findAll(Sort.by("time"));
    }

    @DeleteMapping("/{id}")
    public @ResponseBody ResponseEntity<TodoList> delTodoList (@PathVariable(name="id") int delId) {
        Optional<TodoList> tmp = todoListRepository.findById(delId);

        if(tmp.isPresent()) {
            TodoList t = tmp.get();
            todoListRepository.deleteById(delId);
            return new ResponseEntity<TodoList>(t, HttpStatus.OK);
        }
        else {
            return new ResponseEntity<TodoList>(HttpStatus.BAD_REQUEST);
        }
    }

    @PutMapping("/{editId}")
    public @ResponseBody ResponseEntity<TodoList> editTodoList (@PathVariable int editId, @RequestBody TodoList t) {
        Optional<TodoList> tmp = todoListRepository.findById(editId);
        String time = t.getTime();
        String content = t.getContent();

        if(tmp.isPresent()) {
            TodoList edited = tmp.get();
            if(!time.equals("")) edited.setTime(time);
            if(!content.equals("")) edited.setContent(content);
            todoListRepository.save(edited);

            if(time.equals("") && content.equals("")) return new ResponseEntity<TodoList>(HttpStatus.BAD_REQUEST);
            else return new ResponseEntity<TodoList>(edited, HttpStatus.OK);
        }
        else {
            return new ResponseEntity<TodoList>(HttpStatus.BAD_REQUEST);
        }
    }
}
