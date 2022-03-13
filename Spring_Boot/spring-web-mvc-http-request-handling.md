## Spring Web MVC에서 HTTP Request를 처리하는 과정

게이트웨이에 대해서 공부하던 중 Spring에서 url별로 메소드를 맵핑될때에도 게이트웨이가 사용되는건가라는 생각이 들어서 관련 자료들을 찾아봤다.

<br>

https://spring.io/guides/gs/serving-web-content/

spring에서 HTTP request는 `controller`에 의해 처리된다.

그렇다면 `controller`가 게이트웨이의 역할도 수행하는건가?

<br>

https://medium.com/@kimddub/spring-%EC%8A%A4%ED%94%84%EB%A7%81-%EC%8B%9C%EC%9E%91%ED%95%98%EA%B8%B0-04-%EC%9B%B9-%EB%A7%A4%ED%95%91-%ED%95%84%ED%84%B0-6a9bf3255a10

최근 학교에서 JSP를 사용했는데 그때 어떤 식으로 url를 맵핑시켜야할지 잘 모르고 해맸는데 알고보니 web.xml에 파일에서 설정해줄 수 있다. 그리고 spring controller에서는 이것을 `@RequestMapping` 어노테이션을 통해 간단하게 설정할 수 있도록 지원해준다.

<br>

https://ibocon.tistory.com/208

Spring Web MVC는 `javax.servlet`을 기반으로 만들어진 프레임워크

**DispatcherServlet** : 네트워크 요청을 받아 분배하는 역할을 하는 클래스. Spring Web MVC에서 네트워크 요청을 처리하는데 핵심이 된다.

<br>

> 참고로 Spring의 경우 dispatcherServlet도 직접 만들어야 하고, Spring Boot의 경우 web starter를 추가하면 자동으로 설정된다.
>
> https://www.baeldung.com/spring-vs-spring-boot

<br>

Spring Cloud Gateway를 왜 써야하는지 좀 찾아보았다.

https://twofootdog.tistory.com/64

https://otrodevym.tistory.com/entry/spring-boot-%EC%84%A4%EC%A0%95%ED%95%98%EA%B8%B0-20-spring-cloud-gateway1-%EC%84%A4%EC%A0%95-%EB%B0%8F-%ED%85%8C%EC%8A%A4%ED%8A%B8-%EC%86%8C%EC%8A%A4 그림을 보면 왜 API Gateway가 필요한지 이해가 잘 된다.

DispatcherServlet은 하나의 프로그램 안에서 네트워크 요청에 따라 알맞은 메서드를 할당하고,

Gateway는 아예 다른 프로그램으로 요청을 분배한다는 점에서 다른 것 같다.

<br>

https://kadensungbincho.tistory.com/58

이외에도 좋은 자료가 많아서 추후에 다시 `spring에서 http 요청이 처리되는 구조`에 대해서 좀 더 찾아보면 도움이 될 것 같다.

