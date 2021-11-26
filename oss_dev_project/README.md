# Swing + mariaDB + Spring Boot

> 팀플(오픈소스 개발 프로젝트)
>
> 공부한 내용 정리



## 공부계획

간단한 todolist 앱 제작.

1. Swing 제작
2. Spring Boot로 백엔드 구축
3. Spring Boot에 MySQL 연동(mariaDB로 변경)
4. http 연동



## Swing

https://www.javatpoint.com/java-swing

> AWT 기반, 플랫폼 독립적, 더 가볍고 다양한 component, MVC

### 클래스 계층도

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

### component methods

public void add(Component c)

public void setSize(int width, int height)

public void setLayout(LayoutManager m)

public void setVisible(boolean b)

> default: false

### Create Frame

* create object of Frame class
* extending Frame class

### 간단한 TODO list 앱 만들어보기

* IntelliJ IDEA Swing GUI designer

  https://www.youtube.com/watch?v=-SmNpKskfJc

* 버튼 누르면 table row 추가

  https://stackoverflow.com/questions/22371720/how-to-add-row-dynamically-in-jtable

* 일정 삭제

  http://mauricemuteti.info/how-to-delete-or-remove-selected-row-from-jtable-in-netbeans-java-tutorial-source-code/

* JScrollPanel 안에 table을 추가해야 header가 표시된다.

  https://docs.oracle.com/javase/tutorial/uiswing/components/table.html#show



### http 연동

https://zetcode.com/java/getpostrequest/

https://www.baeldung.com/java-9-http-client#2-specifying-the-http-method

https://lts0606.tistory.com/455



### CRUD 예제

https://zetcode.com/java/getpostrequest/

> POJO <-> json을 쉽게 하려면 jackson-databind를 사용하는게 좋을 것 같고 maven이나 gradle을 사용해서 의존성 관리를 하는것이 좋을 것 같아서 maven 프로젝트로 변경했다.
>
> https://ifuwanna.tistory.com/298
>
> https://4urdev.tistory.com/92

* ##### Create

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
  >
  > 
  >
  > URI에 String으로 붙여서 사용하면 된다.

* ##### Read

  일정 추가 시 자동으로 일정들 불러오기

  > 원래 정규식을 사용해서 json string에서 필요한 부분을 추출해서 사용했는데 jackson-databind을 통해 Map으로 변환해서 사용할 수 있다.
  >
  > https://mkyong.com/java/jackson-convert-json-array-string-to-list/
  >
  > 클래스를 새로 만들어서 사용하는건 오류가 나서 일단 Map<String, String> 배열로 구현했다.

* ##### Update

  간단하게 delete할때랑 비슷하게 구현했다. 하지만 editable Jtable을 활용하면 더 직관적일거 같다. https://www.codejava.net/java-se/swing/editable-jtable-example

* ##### Delete

  선택한 일정 삭제, 해당 일정의 id를 저장하고 있어야한다.

  https://stackoverflow.com/questions/1492217/how-to-make-a-columns-in-jtable-invisible-for-swing-java/1493233

  DELETE에 body 넣어서 보내는 방법 https://stackoverflow.com/questions/57389571/httprequest-delete-with-body

원래 body만 사용하다가 수정 후 HTTP 메소드 별로 사용한 request

```
POST - @RequestParam
GET - x
PUT - @PathVariable + @RequestBody
DELETE - @PathVariable
```



### Json -> 객체

json nested object를 객체로 변환하는데 자꾸 오류가 생겨서 찾아봤는데 클래스만 잘 정의해두면 objectmapper가 알아서 잘 처리를 해준다.

오류가 났던 원인은 LocalDateTime의 deserialize가 제대로 이루어지지 않았던 것이다.

LocalDateTime 변수의 getter를 String을 받아서 `LocalDateTime.parse()` 메소드로 형변환해서 지정해주는 방식으로 수정해서 해결했다.

그리고 objectMapper에서 사용자 정의된 getter를 사용하려면 해당 클래스에 빈 생성자가 정의 되어 있어야 하는 것 같다. (해당 클래스의 맴버 객체의 생성자도 빈 생성자가 정의되어 있어야 한다.)



### 객체 -> Json (ObjectMapper)

LocalDateTime형 자료형이 객체로 전달되는 경우 server에서 deserialsize를 못해서 오류가 발생했다.

Json으로 파싱할때 문자형으로 파싱되도록 설정하는 방법 : https://sas-study.tistory.com/386




## Spring Boot

백엔드 구축 + MySQL 연동

https://github.com/chisan01/TIL/tree/main/Spring_Boot



## MySQL -> mariaDB

https://github.com/chisan01/TIL/tree/main/RDB

>MySQL은 무료로 사용하려면 GPL 라이선스를 따라야 한다.
>
>따라서 MariaDB를 사용하는 것으로 변경했다.



## DB 설계

처음에 [엑셀](https://docs.google.com/spreadsheets/d/1Uga-Tb9KF_MPLcB1_6BPCuiY6ssJBIthgssPOSd58qc/edit#gid=0)로 작업했다가 가독성이 너무 안 좋아서 `Lucidchart`을 이용해서 [ERD 다이어그램](https://github.com/chisan01/TIL/tree/main/oss_dev_project/1M1S_DB.pdf)으로 다시 만들었다.



## RESTful API 문서 작성

참고자료: https://engineering.linecorp.com/ko/blog/document-engineering-api-documentation/

Swagger를 사용하는 것도 괜찮아보인다. https://kim-jong-hyun.tistory.com/49

github.io을 이용하는게 디자인도 괜찮고 커스터마이징하기도 좋고 가장 간단할 것 같아서 github.io를 사용하기로 결정했다.

https://github.com/chisan01/TIL/tree/main/github.io

> 문서가 많아지다보니 확인하는데 어려움이 있어서 카테고리 별로 정리해서 표시하는 기능을 추가했다.



### API 문서 양식

참고한 API 문서 : https://docs.microsoft.com/ko-kr/rest/api/sql/2021-02-01-preview/job-versions/get

````markdown
# 제목

API 설명

`GET|POST|PUT|DELETE` `http://example.com/api/test`

### URI Parameter

| Name | In         | Required   | Type   | Description |
| ---- | ---------- | ---------- | ------ | ----------- |
| 이름 | path/query | true/false | 자료형 | 설명        |
| ...  |            |            |        |             |

### Request Body

| Name | Type   | Description |
| ---- | ------ | ----------- |
| 이름 | 자료형 | 설명        |
| ...  |        |             |

### Response

| Status code | Type   | Description |
| ----------- | ------ | ----------- |
| ex) 200 OK  | 자료형 | 설명        |
| ...         |        |             |

### 예제

#### Sample Request

`POST` `http://example.com/api/test`

Request Body

```json
{
    "name" : "Mr.Kim"
}
```

#### Sample Response

Status code: 200

```json
{
    "id" : 1,
    "name" : "Mr.Kim"
}
```
````



# Swing에서 http 연동하는 방법 문서화

https://github.com/1M1S/1M1S-client/issues/8

API는 하나만 캡쳐해서 예시로 올리고, GET/POST/PUT/DELETE 별로 함수화해서 올려두는게 더 괜찮을 것 같다.



