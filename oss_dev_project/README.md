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



### http 연동

https://zetcode.com/java/getpostrequest/

https://www.baeldung.com/java-9-http-client#2-specifying-the-http-method

https://www.javaguides.net/2018/10/apache-httpclient-delete-http-request-example.html



### CRUD 예제

https://zetcode.com/java/getpostrequest/

> POJO <-> json을 쉽게 하려면 jackson-databind를 사용하는게 좋을 것 같고 maven이나 gradle을 사용해서 의존성 관리를 하는것이 좋을 것 같아서 maven 프로젝트로 변경했다.
>
> https://ifuwanna.tistory.com/298
>
> https://4urdev.tistory.com/92

* #### Create

  일정 추가

  > RequestParam이 아닌 RequestBody에 json형식으로 전달하기 때문에 RequestBody로 받아서 처리해야한다.
  >
  > @RequestBody
  >
  > https://stackabuse.com/get-http-post-body-in-spring/
  >
  > https://docs.oracle.com/en/java/javase/16/docs/api/java.net.http/java/net/http/HttpRequest.BodyPublishers.html
  >
  > 
  >
  > 생각해보니 httpclient로 post 요청을 보낼때에도 parameter를 이용할 수 있는 방법이 있을 것 같다. (하지만 기존에 사용하던 라이브러리랑 달라서 나중에 좀 더 찾아봐야겠다.)
  >
  > https://stackoverflow.com/questions/8120220/how-to-use-parameters-with-httppost

* #### Read

  일정 추가 시 자동으로 일정들 불러오기

  > 원래 정규식을 사용해서 json string에서 필요한 부분을 추출해서 사용했는데 jackson-databind을 통해 Map으로 변환해서 사용할 수 있다.
  >
  > https://mkyong.com/java/jackson-convert-json-array-string-to-list/
  >
  > 클래스를 새로 만들어서 사용하는건 오류가 나서 일단 Map<String, String> 배열로 구현했다.

* #### Update

  간단하게 delete할때랑 비슷하게 구현했다. 하지만 editable Jtable을 활용하면 더 직관적일거 같다. https://www.codejava.net/java-se/swing/editable-jtable-example

* #### Delete

  선택한 일정 삭제, 해당 일정의 id를 저장하고 있어야한다.
  
  https://stackoverflow.com/questions/1492217/how-to-make-a-columns-in-jtable-invisible-for-swing-java/1493233
  
  DELETE에 body 넣어서 보내는 방법 https://stackoverflow.com/questions/57389571/httprequest-delete-with-body



# REST API 문서 작성

참고자료: https://engineering.linecorp.com/ko/blog/document-engineering-api-documentation/

Swagger를 사용하는 것도 괜찮아보인다. https://kim-jong-hyun.tistory.com/49

github.io 이용. https://dreamgonfly.github.io/blog/jekyll-remote-theme/



API는 하나만 캡쳐해서 예시로 올리고, GET/POST/PUT/DELETE 별로 함수화해서 올려두는게 더 괜찮을 것 같다.



### API 문서 양식

Swing에서만 사용될 것이라 parameter는 따로 사용하지 않고 json 형식의 데이터만 사용한다.

````markdown
# 제목

### HTTP method / URI
`GET|POST|PUT|DELETE` `http://example.com/api/test`

### Request
설명
```json
예시
```

### Respond
설명
```json
예시
```
````



API 문서 링크 : https://1m1s.github.io/



## API 사용 안내

### 필요 라이브러리

request나 response가 모두 JSON 문자열 형태로 전달된다. 따라서 JSON <-> 객체 변환을 용이하게 하기 위해서 `jackson-databind` 라이브러리를 사용한다.

maven을 이용한다면 이것을 편리하게 관리할 수 있다. ([Intellij에서 maven 프로젝트로 변경하는 방법](https://ifuwanna.tistory.com/298))

```xml
<!--    jackson-databind 라이브러리 사용 -->
<dependencies>
    <dependency>
        <groupId>com.fasterxml.jackson.core</groupId>
        <artifactId>jackson-databind</artifactId>
        <version>2.9.9.3</version>
    </dependency>
</dependencies>
```

(gradle같은 다른 프로젝트 관리 도구를 사용해도 된다.)

HTTP request를 보내기 위해서 `java.net.http.HttpClient` 라이브러리를 사용하지만 java 11부터는 기본적으로 내장되어있다.



## CRUD 예제

[설명에서 사용된 CRUD 예제](https://github.com/chisan01/TIL/tree/main/oss_dev_project)

### 1. Create

API

````markdown
# 일정 생성 

### HTTP method / URI
`POST` `http://localhost:8080/add`

### Request
추가할 일정 전달
```json
{
	"time" : "6:00PM",
	"content" : "dinner"
}
```

### Response
```string

```
````

Swing에서 API 사용

```java
String time = timeText.getText();
String content = contentText.getText();

// json으로 전달할 내용 객체로 저장
var values = new HashMap<String, String>() {{
    put("time", time);
    put("content", content);
}};

// 발생하는 exception을 처리하기 위해 try-catch문 사용
try {
    var objectMapper = new ObjectMapper();
    // 위에서 저장된 객체 json으로 변환해서 저장
    String requestBody = objectMapper.writeValueAsString(values);
    System.out.println(requestBody);

    HttpClient client = HttpClient.newHttpClient();
    HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create("http://localhost:8080/"))  // 요청을 보낼 주소
        .header("Content-Type", "application/json; charset=UTF-8")  // content type, 인코딩형식 지정
        .POST(HttpRequest.BodyPublishers.ofString(requestBody))  // 전달할 json 지정
        .build();

    // response 저장
    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
    System.out.println(response.body());
}
catch (Exception error) {
    System.out.println("오류 발생");
};
```



### 2. Read

API

````markdown
# 모든 일정 가져오기

### HTTP method / URI
`GET` `http://localhost:8080/`

### Request
없음

### Respond
모든 일정
```json
[
    {
        "id": 1,
        "time": "3:00PM",
        "content": "workout"
    },
    {
        "id": 2,
        "time": "7:00PM",
        "content": "dinner"
    }
]
```
````

Swing에서 API 사용

```java
try {
    HttpClient client = HttpClient.newHttpClient();
    // IOException, InterruptedException 처리 필요.
    HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create("http://localhost:8080/"))  // 요청을 보낼 주소
        .build();

    // response 저장
    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

    // response.body()에 들어있는 json array -> 객체로 변환
    ObjectMapper mapper = new ObjectMapper();
    Map<String, String>[] M = mapper.readValue(response.body(), Map[].class);
    for(Map<String, String> m : M) {
        // Jtable에 일정 추가
        dtm.addRow(new Object[] {m.get("id"), m.get("time"), m.get("content")});
    }
}
catch (Exception error) {
    System.out.println("오류 발생");
};
```



### 3. Update

API

````markdown
# 일정 수정하기

### HTTP method / URI
`PUT` `http://localhost:8080/`

### Request
수정할 일정 id, 수정할 내용(time, content)
```json
{
	"id" : "1",
	"time" : "",
	"content" : "dinner"
}
```

### Respond
수정 요청 처리 여부 문자열로 반환
```string
6:00PM dinner Edited
```
````

Swing에서 API 사용

```java
//E Selected Row
int editRow = todoTable.getSelectedRow();
//Check if their is a row selected
if (editRow >= 0) {
    int editId = (int)todoTable.getModel().getValueAt(editRow, 0);
    // json으로 전달할 내용 객체로 저장
    var values = new HashMap<String, String>() {{
        put("time", timeText.getText());
        put("content", contentText.getText());
        put("id", Integer.toString(editId));
    }};

    // 발생하는 exception을 처리하기 위해 try-catch문 사용
    try {
        var objectMapper = new ObjectMapper();
        // 위에서 저장된 객체 json으로 변환해서 저장
        String requestBody = objectMapper.writeValueAsString(values);
        System.out.println(requestBody);

        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
            .uri(URI.create("http://localhost:8080/"))  // 요청을 보낼 주소
            .header("Content-Type", "application/json; charset=UTF-8")  // content type, 인코딩형식 지정
            .PUT(HttpRequest.BodyPublishers.ofString(requestBody)) // 전달할 json 지정
            .build();

        // response 저장
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println(response.body());
    }
    catch (Exception error) {
        System.out.println("오류 발생");
    };

    getTodoList(dtm);
    JOptionPane.showMessageDialog(null, "Edited");
} else {
    JOptionPane.showMessageDialog(null, "Unable To Edit");
}
```



### 4. Delete

API

````markdown
# 일정 수정하기

### HTTP method / URI
`DELETE` `http://localhost:8080/`

### Request
삭제할 일정 id
```json
{
	"id" : "1"
}
```

### Respond
삭제 요청 처리 여부 문자열로 반환
```string
6:00PM dinner Deleted
```
````

Swing에서 API 사용

```java
//Delete Selected Row
int delRow = todoTable.getSelectedRow();
//Check if their is a row selected
if (delRow >= 0) {
    int delId = (int)todoTable.getModel().getValueAt(delRow, 0);
    // json으로 전달할 내용 객체로 저장
    var values = new HashMap<String, String>() {{
        put("id", Integer.toString(delId));
    }};

    // 발생하는 exception을 처리하기 위해 try-catch문 사용
    try {
        var objectMapper = new ObjectMapper();
        // 위에서 저장된 객체 json으로 변환해서 저장
        String requestBody = objectMapper.writeValueAsString(values);
        System.out.println(requestBody);

        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
            .uri(URI.create("http://localhost:8080/"))  // 요청을 보낼 주소
            .header("Content-Type", "application/json; charset=UTF-8")  // content type, 인코딩형식 지정
            .method("DELETE", HttpRequest.BodyPublishers.ofString(requestBody))  // 전달할 json 지정
            .build();

        // response 저장
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        System.out.println(response.body());
    }
    catch (Exception error) {
        System.out.println("오류 발생");
    };

    getTodoList(dtm);
    JOptionPane.showMessageDialog(null, "Row Deleted");
} else {
    JOptionPane.showMessageDialog(null, "Unable To Delete");
}
```

