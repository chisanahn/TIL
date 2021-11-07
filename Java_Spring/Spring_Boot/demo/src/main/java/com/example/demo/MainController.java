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

class delTodoList {
    private Integer id;

    public Integer getId() { return id; }
    public void setId(Integer id) { this.id = id; }
}

@Controller
@RequestMapping(path="/")
public class MainController {
    @Autowired
    private TodoListRepository todoListRepository;

    @PostMapping
    public @ResponseBody String addTodoList (@RequestBody TodoList t) {
        todoListRepository.save(t);
        return t.getTime() + " " +  t.getContent() + " Saved";
    }

    @GetMapping
    public @ResponseBody Iterable<TodoList> getAllTodoList() {
        return todoListRepository.findAll(Sort.by("time"));
    }

    @DeleteMapping
    public @ResponseBody ResponseEntity<String> delTodoList (@RequestBody delTodoList d) {
        Optional<TodoList> tmp = todoListRepository.findById(d.getId());

        if(tmp.isPresent()) {
            TodoList t = tmp.get();
            todoListRepository.deleteById(d.getId());
            return new ResponseEntity<String>(t.getTime() + " " +  t.getContent() + " Deleted", HttpStatus.OK);
        }
        else {
            return new ResponseEntity<String>("삭제할 항목이 없습니다.", HttpStatus.BAD_REQUEST);
        }
    }

    @PutMapping
    public @ResponseBody ResponseEntity<String> editTodoList (@RequestBody TodoList t) {
        Optional<TodoList> tmp = todoListRepository.findById(t.getId());
        String time = t.getTime();
        String content = t.getContent();

        if(tmp.isPresent()) {
            TodoList edited = tmp.get();
            if(!time.equals("")) edited.setTime(time);
            if(!content.equals("")) edited.setContent(content);
            todoListRepository.save(edited);

            if(time.equals("") && content.equals("")) return new ResponseEntity<String>("수정 내용이 없습니다.", HttpStatus.BAD_REQUEST);
            else return new ResponseEntity<String>(edited.getTime() + " " +  edited.getContent() + " Edited", HttpStatus.OK);
        }
        else {
            return new ResponseEntity<String>("수정할 항목이 없습니다.", HttpStatus.BAD_REQUEST);
        }
    }
}
