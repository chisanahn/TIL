https://github.com/SAMMaru5/SAMMaruServer/pull/81

## static field는 `@Autowired` 사용을 지원하지 않는다.

값을 설정 파일에서 `@Value`를 통해 가져오는 방식을 사용했는데 static 필드로 지정해서 값이 잘못 불러와지는 오류가 있었다.

<br>

실제로 스프링을 실행시켜보면 INFO 로그에서 `Autowired annotation is not supported in static fields` 메시지를 확인할 수 있다.

> 왜 WARN이 아니라 INFO로 나오는걸까?

<br>

Spring은 class 레벨에서 동작하지 않고 instance (bena) 레벨에서 동작하기 때문이라고 한다.

> https://stackoverflow.com/questions/23014717/what-is-a-reason-of-warning-autowired-annotation-is-not-supported-on-static-fie

<br>

만약 static이나 final 필드에 `@Value`를 통해서 값을 주입하고 싶다면 생성자 주입나 setter 주입을 이용하면 된다.

> https://stackoverflow.com/questions/7130425/spring-property-injection-in-a-final-attribute-value-java

<br>

하지만 이 프로젝트에서 해당 static 필드를 별도로 사용할 일도 없고, 객체를 생성하지 않은 채로 static 필드를 사용하게 된다면 쓰레기 값이 사용되기 때문에 아예 static 필드를 제거함으로써 문제를 해결했다.

