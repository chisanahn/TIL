# Spring Boot

Java Spring에서 다양한 설정들을 자동으로 관리해주는 등 Spring 보다 개발을 더 편리하게 진행할 수 있을 것 같아서 스프링 부트를 공부하게 되었다.

https://velog.io/@deannn/Spring-IntelliJ-Springboot-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EC%83%9D%EC%84%B1-%EB%B0%8F-%EC%8B%A4%ED%96%89

프로젝트 관리 툴

> Maven, Gradle

프로젝트 dependecies

> 웹 프로젝트의 경우 Spring Web은 필수.

참고로 Intellij 커뮤니티 버전은 Spring initializer를 지원해주지 않는다. [참고](https://velog.io/@deannn/Spring-IntelliJ-Springboot-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EC%83%9D%EC%84%B1-%EB%B0%8F-%EC%8B%A4%ED%96%89). 따라서 Spring 공식 사이트에서 지원해주는 https://start.spring.io/를 사용한다.

Intellij에서 prebuilt shared indexes를 설치할 수 있다고 나왔는데 어떤건지 정확히는 잘 모르겠지만 Intellij에서 제공하는 인덱싱 기능을 한번만 설치하면 OS가 동일한 여러 컴퓨터에서 동일한 인덱싱을 사용할 수 있는 기능인 것 같다. [참고](https://blog.jetbrains.com/idea/2020/07/shared-indexes-plugin-unveiled/)

> 인덱싱은 class, method, object 등의 지도를 만들어서 IDE가 코드를 인식하고 여러 기능들을 지원하도록 하기 위한 기능인 것 같다.



## Annotations

[참고1](https://spring.io/guides/gs/spring-boot/) [참고2](https://jojoldu.tistory.com/250) [참고3](https://spring.io/quickstart)

[Building a RESTful Web Service](https://spring.io/guides/gs/rest-service/) <- 여기가 가장 잘 정리되어있다.

```java
@SpringBootApplication
public class DemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args);
	}
}
```

**@SpringBootApplication**

> = @configuration + @EnableAutoConfiguration + @ComponentScan
>
> bean 관련 설정 등 개발에 필요한 설정들을 자동으로 해준다.

```java
@RestController
public class GreetingController {

	private static final String template = "Hello, %s!";
	private final AtomicLong counter = new AtomicLong();

	@GetMapping("/greeting")
	public Greeting greeting(@RequestParam(value = "name", defaultValue = "World") String name) {
		return new Greeting(counter.incrementAndGet(), String.format(template, name));
	}
}
```

**@GetMapping("/주소")**

**method()**

> 주소로 오는 HTTP GET 요청들을 메서드와 연결. 
>
> @PostMapping
>
> @RequestMapping  // 기본적으로 GET, PUT, POST 등 모든 HTTP operations에 대해 동작한다.
>
> @RequestMapping(method=GET)

**@RequestParam(value="", defualtValue="") 변수**

> query string parameter와 변수를 묶어준다.
>
> https://www.baeldung.com/spring-request-param

**MVC controller와 RESTful web service controller의 차이**

> RESTful은 반환값을 HTML로 바꾸기 위해 view technology를 사용하지 않고 객체를 그대로 반환한다. (JSON으로 변환되어서 전달)

**@RestController** 

> = @Controller + @ResponseBody
>
> 클래스의 모든 메서드가 view 대신 domain object를 반환한다는 것을 나타냄.
>
> object를 JSON으로 변환할때 HttpMessageConverter를 사용한다.

**@ResponseBody**

> @RestController에 포함되어 있다.
>
> Spring MVC가 메서드에서 반환된 HttpEntity와 HttpEntity에 포함된 인스턴스를 render해서 바로 response에 전달하도록 한다.

**Spring's HTTP message converter support**

> Jackson JSON library
>
> 인스턴스들을 자동으로 JSON.Jackson 형식의 데이터로 바꿔준다.
>
> web starter에 의해 기본적으로 포함되어 있다.

**application 실행 콘솔 명령어 - Gradle**

> ```bash
> ./gradlew bootRun
> ```

**Build an executable JAR**

> 바로 실행할 수도 있고 JAR 파일을 만들어서 실행할 수도 있다.
>
> ```bash
> ./gradlew build
> 
> java -jar build/libs/gs-rest-service-0.1.0.jar
> ```



[Building a Hypermedia-Driven RESTful Web Service](https://spring.io/guides/gs/rest-hateoas/)

**HATEOAS** [wikipedia](https://en.wikipedia.org/wiki/HATEOAS) [참고2](https://joomn11.tistory.com/26) [참고3](https://wonit.tistory.com/454)

> Hypermedia(링크) as the Engine of Application State
>
> REST API를 잘 설계하기 위해 나온 개념. client와 server를 분리하여 독립적으로 발전하도록 한다.
>
> 클라이언트가 서버에 요청을 보내고 응답을 받을때 사용 가능한 다음 행동들에 대해서 각각의 URI를 hypermedia로 전달받아 동적인 상호작용이 가능하다.

> 응답을 전달할때 HAL 타입을 이용해서 리소스/링크로 분류해서 전달.

`Spring HATEOAS dependency` 사용

```java
public class Greeting extends RepresentationModel<Greeting> {

	private final String content;

	@JsonCreator
	public Greeting(@JsonProperty("content") String content) {
		this.content = content;
	}

	public String getContent() {
		return content;
	}
}
```

HATEOAS 타입에 맞춰 응답을 반환하기 위해서 RepresentationModel을 상속받아 클래스 생성.

[Jackson annotation 참고](https://www.baeldung.com/jackson-annotations)

**@JsonCreator**

> Jackson이 어떻게 JSON <-> POJO(Plain Old Java Object) 할지 정의.

**@JsonProperty("field")**

> Jackson이 JSON의 field와 POJO의 어떤 변수를 매칭시킬지 표시.



## MySQL 연동

https://spring.io/guides/gs/accessing-data-mysql/

https://memostack.tistory.com/163

SpringBoot에서 DB에 접근하기 위해 JPA, JDBC를 사용한다.

### 환경설정

spring boot의 기본 DB는 `H2`로 다른 DB를 사용하려면 `application.properties`를 수정해줘야 한다.

> 연결할 DB url, 유저명, 유저PW, 드라이버 등 명시
>
> ```java
> spring.datasource.url=jdbc.mysql://${MYSQL_HOST:localhost}:3306/db_example
> ```
>
> DB url을 명시할때 주석처럼 명시하기 때문에 빠뜨리지 않도록 주의하자.

https://www.mysqltutorial.org/

### JPA annotation

* `@Entity` : table 생성

* `@Id` : index primary key

* `@GeneratedValue` : Primary Key 전략 설정.

* `@Column` : DB Column을 명시

* `@JoinColumn` : 외래키, 단방향 관계

  > 맨 처음에 name 속성으로 참고할 PK 이름을 명시하는건줄 알았는데 `@Column`처럼 외래키 이름을 명시하는거였다.
  >
  > https://www.inflearn.com/questions/113969

  * mappedBy랑 함께 쓰면 양방향 관계.

    https://jaegukim.github.io/posts/joincolumn-vs-mappedby-orm%EC%9D%84-%EC%82%AC%EC%9A%A9%ED%95%A0%EB%95%8C-%EC%A3%BC%EC%9D%98%ED%95%A0%EC%A0%90/
  
* N:M 관계의 경우 연결 테이블을 추가해서 일대다, 다대일 관계로 구성하면 된다. https://ict-nroo.tistory.com/127

잘 정리되어 있는 글을 발견했다.

> https://velog.io/@leyuri/Spring-boot-JPA-%EC%96%B4%EB%85%B8%ED%85%8C%EC%9D%B4%EC%85%98-Entity-Table-Column-Id-Lombok

이때 Entity를 통해 실제로 생성되는 테이블 이름은 소문자로만 이루어지는 것 같다.

### JpaRepository

따로 쿼리문 작성없이 CRUD를 수행할 수 있게 해준다.

> https://stackoverflow.com/questions/14014086/what-is-difference-between-crudrepository-and-jparepository-interfaces-in-spring
>
> `JpaRepository` extends `PagingAndSortingRepository`
>
> `PagingAndSortingRepository` extends `CrudRepository`

```java
public interface UserRepository extends JpaRepository<Entity, PrimaryKey타입>
```

이때, Spring이 자동으로 해당 interface를 생성해준다. 이때 맨 앞의 대문자가 소문자로 바뀌어서 생성된다. 위의 예제의 경우 userRepository가 생성된다.

> 제대로 이해하려면 @Repository, @Autowired를 annotation을 알아야 하는데 Bean, 의존성 주입과 밀접한 관련이 있는 것 같아서 아직 잘 이해가 되지 않는다.
>
> https://galid1.tistory.com/512

* **Create** : `save()`
* **Read** : `findall()`, `findById()`
* **Update** : `findById()`로 객체를 가져와서 수정한뒤 `save()`
* **Delete** : `deleteById()`

> `findById()` 등의 메소드 리턴값이 Optional인데 어떻게 사용하는건지 아직 잘 모르겠다.
>
> https://zetcode.com/springboot/findbyid/
>
> -> isPresent()로 값이 존재하는지 확인하고 존재하면 get()으로 받아와서 사용하면 된다.



### MariaDB로 변경

https://goddaehee.tistory.com/205

MySQL이랑 거의 똑같아서 드라이버만 바꿔주면 되는 것 같다.



### query문

https://docs.spring.io/spring-data/jpa/docs/current/reference/html/#jpa.query-methods.query-creation

##### query creation from method names

> 함수명만 Entity 변수명과 일치하게 사용하면 된다.
>
> Member_id, MemberId 둘 다 정상적으로 동작했다.

##### `getById()` vs `findById()`

> 외래키를 사용할때는 `getById()`를 사용하면 될 것 같다.



## param vs query vs body

https://dar0m.tistory.com/222

> resource 식별 -> path variable
>
> 정렬&필터링 -> query
>
> 매우 많은 수의 인수 -> body



### Request Body

request body에서 항목이 비어있을 경우 자동으로 null 값이 지정된다. 지금까지 PUT 요청을 보낼때 수정하지 않더라도 빈문자열을 값으로 지정해서 보냈는데 알고보니 그럴 필요가 없었다.

심지어 LocalDateTime 값으로 빈문자열이 전달될 경우 null 값으로 처리하기 위해서 getter를 사용자 지정해서 처리해 줬는데 그럴 필요가 없었다.



## RESTful API 설계 가이드

https://sanghaklee.tistory.com/57

> URL Rules - 마지막에 `/` 포함하지 않는다.
>
> Cotent-Type 되도록 json으로 일치.
>
> - "일정 생성 완료"처럼 String으로 반환했었는데 생성된 일정을 반환하고 클라이언트에서 따로 처리할 수 있도록 하는게 더 좋을 것 같다.



# Talend API Tester

> REST api 테스트할때 유용한 크롬 확장 도구



앞으로 공부할때 참고할 자료 후보

https://www.youtube.com/watch?v=9SGDpanrc8U&t=197s

https://www.baeldung.com/spring-boot
