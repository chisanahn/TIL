## rest-assured

이번에 [백명석님의 ATDD 예제 repo](
https://github.com/msbaek/atdd-example)를 보고 ATDD를 한번 적용해봐야겠다는 생각에 도입해봤다.

하지만 다음과 같은 문제에 봉착했다.

**test와 rest-assured가 별도의 context에서 동작하는 것 같다**

- test에서 in-memory database인 h2 데이터베이스를 사용하기 때문에 미리 데이터를 저장하더라도 테스트에서 사용하지 못한다.

- 인증 정보와 같은 부분을 mock을 통해서 처리하지 못한다.

<br>

이것저것해보다가 원인을 찾았다

> 어쩐지 test와 rest-assured가 별도의 context에서 존재한다고 구글링하니깐 정보가 많이 안 나오더라...

`@SpringBootTest`랑 `@Transactional`을 같이 사용했더니 해당 오류가 발생한다.

> `@BeforeEach`에서 초기 데이터를 insert하는 부분이 `@Transaction`으로 처리되서 그런게 아닐까 싶다.

하지만 여전히 `@WithSecurityContext`는 여전히 적용되지 않는다...

아마도 SecurityContext는 요청마다 새로 생성되는 부분이라 그런 것 같다.

> 이 부분은 어떻게 해결할 수 있을까.. 많이 검색해봤지만 감도 잘 오지 않아서 우선 다른 방법으로 시도해보려고 한다.

<br>

우선 실제로 로그인 요청을 보내고 accessToken 값을 받아서 사용하도록 변경했는데 이번에는 500 오류가 발생했다.

login 로직에서 redis에 직접적으로 접근하는 부분이 있는데, 현재 로컬 환경에서는 redis 환경 설정이 되어 있지 않아서 오류가 발생하는 것이었다.

> [로컬/테스트 환경에서 내장 메모리 redis를 사용하도록 개발환경을 구축함으로써 해결했다.](./embedded-redis.md)