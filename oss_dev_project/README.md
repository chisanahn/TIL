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



### Swing

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




### Spring Boot

백엔드 구축 + MySQL 연동

https://github.com/chisan01/TIL/tree/main/Java_Spring



### MySQL

설치

https://velog.io/@joajoa/MySQL-%EB%8B%A4%EC%9A%B4%EB%A1%9C%EB%93%9C-%EB%B0%8F-%EC%84%A4%EC%B9%98-%EB%B0%A9%EB%B2%95

https://www.mysqltutorial.org/what-is-mysql/

튜토리얼

https://opentutorials.org/course/195

https://www.mysqltutorial.org/

> MySQL은 무료로 사용하려면 GPL 라이선스를 따라야 한다.
>
> 따라서 MariaDB를 사용하는 것으로 변경했다.



### MariaDB로 변경

카페에서 linux로 설치 시도. 책을 따라서 설치했는데 오류도 많이나고 결국 성공하지 못했다.

오랜만에 linux를 사용해서 그런지 명령어도 많이 낯설고 개념도 좀 헷갈려서 더 어려움을 겪었다.

[linux 사용자와 그룹](https://nolboo.kim/blog/2015/08/18/linux-users-groups/)

https://linuxize.com/post/how-to-install-mariadb-on-ubuntu-20-04/ 를 참고해서 다시 시도.

key를 받아오는 과정에서 오류가 발생하는데 검색해봐도 잘 나오지 않아서 wsl 설치를 잘못 했던것같다.

다음에 다시 해보기로 하고 일단 윈도우에 설치해서 사용하기로 했다.



### CRUD 예제

https://zetcode.com/java/getpostrequest/

> POJO <-> json을 쉽게 하려면 jackson-databind를 사용하는게 좋을 것 같고 maven이나 gradle을 사용해서 의존성 관리를 하는것이 좋을 것 같아서 maven 프로젝트로 변경했다.
>
> https://ifuwanna.tistory.com/298



* Create : 일정 추가

  > RequestParam이 아닌 RequestBody에 json형식으로 전달하기 때문에 RequestBody로 받아서 처리해야한다.
  >
  > @RequestBody
  >
  > https://stackabuse.com/get-http-post-body-in-spring/
  >
  > https://docs.oracle.com/en/java/javase/16/docs/api/java.net.http/java/net/http/HttpRequest.BodyPublishers.html
  >
  > 

* Read : 일정 추가 시 자동으로 일정들 불러오기

* Update : editable Jtable 활용

  https://www.codejava.net/java-se/swing/editable-jtable-example

* Delete : 선택한 일정 삭제



### http 연동

https://zetcode.com/java/getpostrequest/

