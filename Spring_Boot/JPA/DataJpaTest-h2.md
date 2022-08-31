## `@DataJpaTest`에서 h2 사용

`@DataJpaTest`를 수행할때 기본적으로 `h2`라는 in-memory database가 실행되게 된다.

> https://stackoverflow.com/questions/53002232/spring-boot-datajpatest-unit-test-reverting-to-h2-instead-of-mysql

그리고 `application.properties` 파일에서 `spring.jpa.database`을 따로 지정해주지 않는다면 target database가 자동으로 지정된다.

> https://docs.spring.io/spring-boot/docs/current/reference/html/application-properties.html#application-properties.data.spring.jpa.database

이때, `spring.jpa.database`으로 mysql을 명시적으로 지정해주게 된다면 test 실행시 테이블을 못찾는 오류가 발생한다.

하지만 찾아보니 in-memory database는 실제 RDB와 작동방식에서 차이가 있기 때문에 테스트 시에도 실제 동작환경과 동일한 RDB에서 실행되는 것이 좋다는 얘기가 있어서 테스트 수행 시에도 동일한 database에서 돌아가도록 설정해주는 것이 좋을 것 같다.

```java
@AutoConfigureTestDatabase(replace=Replace.NONE)
```

> https://www.google.com/search?q=Is+it+good+to+use+h2+database+for+testing&sxsrf=ALiCzsayccGLZ9uqEbTgkdafnePykB2nDw%3A1661947328351&ei=wE0PY9v0FMvQ2roPi8OU8Ak&ved=0ahUKEwjb1JChhPH5AhVLqFYBHYshBZ4Q4dUDCA4&uact=5&oq=Is+it+good+to+use+h2+database+for+testing&gs_lcp=Cgdnd3Mtd2l6EAM6BwgAEEcQsAM6BwgjELACECc6BQgAEIYDSgQIQRgASgQIRhgAUOEEWIIoYJ0paAFwAXgAgAGBAogB7BSSAQYwLjE3LjGYAQCgAQHIAQjAAQE&sclient=gws-wiz

아니면 `@DataJpaTest` 대신 `@SpringBootTest`를 통해서 환경을 모두 로딩해도 h2가 아닌 datasource로 설정되어 있는 database를 통해 테스트가 수행된다.