# Swing + MySQL + Spring Boot

> 팀플(오픈소스 개발 프로젝트)
>
> 공부한 내용 정리



## 공부계획

간단한 todolist 앱 제작.

1. Swing 제작
2. Spring Boot로 백엔드 구축
3. Spring Boot에 MySQL 연동
4. http 연동



### Swing 제작

https://www.javatpoint.com/java-swing

> AWT 기반, 플랫폼 독립적, 더 가볍고 다양한 component, MVC

#### 클래스 계층도

Object

- Component

  - Container

    - Window
      - Frame, Dialog
    - Panel
      - Applet

  - JComponent

    > JFC - set of GUI components

    - JList, JTable, ....

#### component methods

public void add(Component c)

public void setSize(int width, int height)

public void setLayout(LayoutManager m)

public void setVisible(boolean b)

> default: false

#### Create Frame

* create object of Frame class
* extending Frame class

#### 간단한 TODO list 앱 만들어보기

* IntelliJ IDEA Swing GUI designer

  https://www.youtube.com/watch?v=-SmNpKskfJc

* 버튼 누르면 table row 추가

  https://stackoverflow.com/questions/22371720/how-to-add-row-dynamically-in-jtable

* 일정 삭제

  http://mauricemuteti.info/how-to-delete-or-remove-selected-row-from-jtable-in-netbeans-java-tutorial-source-code/

* JScrollPanel 안에 table을 추가해야 header가 표시된다.

  https://docs.oracle.com/javase/tutorial/uiswing/components/table.html#show

* 











Spring Boot로 백엔드 구축

https://github.com/chisan01/TIL/tree/main/Java_Spring



MySQL 연동 (시간이 된다면 +Docker)



http 연동

https://zetcode.com/java/getpostrequest/

