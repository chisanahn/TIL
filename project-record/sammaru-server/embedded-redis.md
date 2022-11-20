## 로컬/통합 테스트 - 메모리 내장 Redis 사용 환경 구축

redis를 직접적으로 사용하는 일이 없도록 추상화하거나, test용 redis를 단순한 로컬용으로 바꿔서 사용하는게 좋을 것 같은데 아무래도 해본 적이 없어서 어려움도 많을 것 같고 이번 기회에 메모리내장 redis를 테스트 환경에서 사용할 수 있도록 구축해보려고 한다.

- https://jojoldu.tistory.com/297

[아슈](https://github.com/kstyrc/embedded-redis/issues/130)를 둘러보다가 새로운 방식도 하나 알게 되었다.

- [Test Containers](https://www.testcontainers.org/quickstart/junit_5_quickstart/)

docker로 간단하게 테스트 환경을 구축해서 사용하는 방식인 것 같은데 보다 정확한 환경에서 테스트를 수행할 수 있을 것 같지만 아무래도 시간이 좀 더 걸리지 않을까?

> 추후에 해당 방법을 도입하는 것도 고려해볼만한 것 같다

<br>

내장 redis를 사용하지 않고, `RestAssuredMockMvc`를 사용하면 `@WithSecurityContext`를 사용해서 인증 부분을 생략하고 테스트를 진행하는 방법도 있을 것 같다.

- https://github.com/spring-projects/spring-security/issues/3721

- https://www.youtube.com/watch?v=1rkoFTxJhNk&ab_channel=rieckpil

> 인증 부분이 생략되기 때문에 E2E 통합 테스트는 아니지만 그만큼 테스트 시간은 단축되기 때문에 이 방법도 고려해볼만한 것 같다.

<br>

## embedded redis 포트 충돌 문제 해결

`SpringBootTest`는 실행될때마다 새로운 스프링 테스트 컨텍스트를 생성한다.

따라서 embedded redis를 사용하는 통합 테스트 여러개를 동시에 돌릴 경우, `redisServer`를 하나 더 생성하게 되면서 포트 충돌이 발생하고, 테스트 코드가 정상적으로 동작하지 않게 된다.

실행할때마다 빈 포트번호를 찾아서 실행하는 방법도 있지만, 해당 방법은 터미널 명령어를 통해서 수행되기 때문에 운영체제에 종속적이라 별로 마음에 들지 않는 방법이었다.

<br>

### 방법 1.

우선, 각 테스트가 종료될때마다 해당 테스트에 사용한 embedded redis를 완전히 종료하면 되지 않을까 싶어서 방법을 강구해봤다.

`embeddedRedisConfig` bean을 강제적으로 삭제시켜서  embedded redis server를 완전히 종료시키는데는 성공했지만 



- https://stackoverflow.com/questions/6855811/how-can-i-remove-a-singleton-spring-bean-from-applicationcontext

```java
@Autowired
DefaultListableBeanFactory beanFactory;

@AfterEach
void tearDown() {
  beanFactory.removeBeanDefinition("embeddedRedisConfig");
}
```

동일한 테스트 클래스에서 여러 테스트 메소드를 수행하는 경우 동일한 ApplicationContext를 사용하다보니 `embeddedRedisConfig`를 다시 생성하지 않으면서 오류가 발생했다.



각각의 테스트 클래스 별로 bean을 제거해주면 해결될 것 같은데 static에서 `@Autowired`를 사용할 수 없었다.

그래서 `DirtiesContext`를 이용해서 테스트 메소드마다 ApplicationContext를 새로 사용하게 함으로써 해당 문제를 해결했다.

```java
@DirtiesContext(classMode = DirtiesContext.ClassMode.AFTER_EACH_TEST_METHOD)
```

<br>

### 방법 2.

추가로 [블로그 글](https://rogal.tistory.com/entry/Embedded-Redis-%EB%A5%BC-%EC%93%B0%EB%A9%B4%EC%84%9C-%EA%B2%AA%EC%9D%80-%EB%AC%B8%EC%A0%9C%EC%99%80-%ED%95%B4%EA%B2%B0%EB%B0%A9%EC%95%88#:~:text=%EB%A0%88%EB%94%94%EC%8A%A4%20%EC%84%9C%EB%B2%84%EB%A5%BC%20%EC%83%9D%EC%84%B1%ED%95%A0%20%EC%88%98%20%EC%97%86%EB%8B%A4%EB%A9%B4%20%EA%B7%B8%EB%83%A5%20%EB%AC%B4%EC%8B%9C%ED%95%98%EA%B3%A0%20%EC%A7%84%ED%96%89%ED%95%98%EB%8F%84%EB%A1%9D%20%ED%96%88%EB%8B%A4.)을 보고 redis server가 아직 종료되지 않은 경우 해당 redis server를 사용하면 된다는걸 깨달았다.

```java
try {
    redisServer.start();
} catch (RuntimeException e) {
}
```

<br>

여러 테스트가 동일한 redis server를 사용하게 되면서 추후에 문제가 발생할 수도 있다는 생각이 들었지만 당장은 문제가 발생하지 않고, 1번째 방법은 테스트마다 코드를 추가해줘야 하고, context를 새로 사용하기 때문에 실행시간 측면에서도 좋지 못해서 당분간 2번째 방법을 사용하려고 한다.