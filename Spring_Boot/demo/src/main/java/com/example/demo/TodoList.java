package com.example.demo;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class TodoList {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer id;

    private String time;
    private String content;

    public Integer getId() { return id; }
    public void setId(Integer id) { this.id = id; }

    public String getTime() { return time; }
    public void setTime(String time) { this.time = time; }

    public String getContent() { return content; }
    public void setContent(String content) { this.content = content; }
}
