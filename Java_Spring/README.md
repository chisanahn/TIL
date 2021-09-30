# Java Spring

## Spring Boot

Java Spring에서 다양한 설정들을 자동으로 관리해주는 등 Spring 보다 개발을 더 편리하게 진행할 수 있을 것 같아서 스프링 부트를 공부하게 되었다.

https://velog.io/@deannn/Spring-IntelliJ-Springboot-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EC%83%9D%EC%84%B1-%EB%B0%8F-%EC%8B%A4%ED%96%89

프로젝트 관리 툴

> Maven, Gradle

프로젝트 dependecies

> 웹 프로젝트의 경우 Spring Web은 필수.

참고: Intellij 커뮤니티 버전은 Spring initializer를 지원해주지 않는다.

https://velog.io/@deannn/Spring-IntelliJ-Springboot-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EC%83%9D%EC%84%B1-%EB%B0%8F-%EC%8B%A4%ED%96%89

따라서 Spring 공식 사이트에서 지원해주는 https://start.spring.io/를 사용한다.

Intellij에서 prebuilt shared indexes를 설치할 수 있다고 나왔는데 어떤건지 정확히는 잘 모르겠지만 Intellij에서 제공하는 인덱싱 기능을 한번만 설치하면 OS가 동일한 여러 컴퓨터에서 동일한 인덱싱을 사용할 수 있는 기능인 것 같다.

> 인덱싱은 class, method, object 등의 지도를 만들어서 IDE가 코드를 인식하고 여러 기능들을 지원하도록 하기 위한 기능인 것 같다.

https://blog.jetbrains.com/idea/2020/07/shared-indexes-plugin-unveiled/



https://spring.io/guides/gs/spring-boot/

https://jojoldu.tistory.com/250

```java
@RestController
public class MyController {
    
    @GetMapping("/")
    public String home() {
        retrun "This is home";
    }
    
    @GetMapping("/hi")
    public String hi() {
        return "Nice to meet you";
    }
}
```

@RestController

> = @Controller + @ResponseBody
>
> request를 받아서 처리할 수 있는 클래스임을 나타낸다.

@GetMapping("/")

> 메서드와 url 주소를 연결

application 실행 콘솔 명령어 - Gradle

> ./gradlew bootRun



https://spring.io/quickstart가 더 잘 정리되어 있는 것 같다.

> 프로젝트 관리 툴로 Gradle이 아닌 Maven을 사용하긴 한다.

```java
@SpringBootApplication
@RestController
public class DemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args);
	}

	@GetMapping("/")
	public String hello(@RequestParam(value = "name", defaultValue = "World") String name) {
		return String.format("Hello %s!", name);
	}
}
```

@GetMapping("주소")

메서드

> 메서드를 사용해 주소로 전달되는 request를 처리한다는 것을 나타내는 annotation.

@RequestParam(value="", defualtValue="") String name

> url 주소로 query 값을 전달받아 name 변수에 저장
>
> ex) /?name=Mike



https://spring.io/guides/gs/rest-service/