package com.example.demo;

import org.springframework.data.jpa.repository.JpaRepository;

import com.example.demo.TodoList;
import org.springframework.stereotype.Repository;

@Repository
public interface TodoListRepository extends JpaRepository<TodoList, Integer> {
}
