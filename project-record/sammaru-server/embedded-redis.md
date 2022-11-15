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