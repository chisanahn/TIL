## Exception test

JUnit에서 method에서 발생하는 Exception들을 체크할 수 있는 메소드를 제공해준다.

https://www.baeldung.com/junit-assert-exception

<br>

## JPA unit test

다른 테이블과 연관관계가 있는 테이블의 경우 unit test를 어떻게 작성할 수 있을지 감이 잘 안왔는데

연관된 테이블의 경우에는 해당 테이블의 메소드를 사용하는 것이 아니라 hard cording해서 내가 테스트하고자 하는 메소드만 unit test할 수 있을 것 같다.

> 이를 위해서라도 `@Entity`에 `@Builder`를 포함시켜서 작성하면 필요한 entity들을 직관적으로 생성할 수 있어서 좋은 것 같다.

그리고 유닛 테스트나 `@SpringBootTest`를 사용한 스프링 통합 테스트만 있는줄 알았는데

`@DataJpaTest`를 사용해서 JPA 관련 Component만 로드 시킬 수 있다고 한다.

> `@DataJpaTest`에 `@Transactional`도 포함하기 때문에 DB에 커밋되지 않고 롤백된다.
>
> 심지어 기본적으로 내장된 임베디드 데이터베이스를 사용해서 테스트를 진행한다고 한다.

그리고 `@ExtendWith(SpringExtension.class)`, `@ExtendWith(MockitoExtension.class)` 어노테이션을 사용하던데 이게 어떤건지에 대해서도 공부해봐야겠다.

> **참고자료**
>
> 1. Bluemiv. SpringBoot, Junit5에서 JPA Repository 테스트. MemoStack. Published January 6, 2021. Accessed April 4, 2022. https://memostack.tistory.com/195
> 2. DataJpaTest (Spring Boot 2.6.6 API). Spring.io. Published 2022. Accessed April 4, 2022. https://docs.spring.io/spring-boot/docs/current/api/org/springframework/boot/test/autoconfigure/orm/jpa/DataJpaTest.html
> 3. 준준영. 스프링 부트 테스트 : @DataJpaTest. 준영이의 웹 까페. Published October 8, 2019. Accessed April 4, 2022. https://webcoding-start.tistory.com/20

<br><br>

## Mock을 통한 test

`@Service`에서 `@Repository`를 사용하는 것처럼 테스트 환경을 구축하기가 어려운 경우, 이를 해결하기 위해서 `Mock` 즉, 가짜 객체를 만들어서 사용한다는 것 같다.

`Mockito`는 Mock을 생성해주는 프레임워크 중 하나.

- `@Mock`으로 가짜 객체를 생성하고
- `@InjectMock`으로 가짜 객체를 주입할 객체를 지정해서 사용한다.

> ex) Unit test를 위해서 가짜 `Repository` 객체를 만들고 `Service` 객체에 주입해서 사용한다.

- `given`을 사용해서 생성된 가짜 객체의 메소드의 반환값을 지정한다.


> **참고자료**
>
> 1. Bluemiv. SpringBoot, Junit5에서 Service 테스트. MemoStack. Published January 13, 2021. Accessed April 4, 2022. https://memostack.tistory.com/196
> 2. GOCHEAT. gocheat. [INFO] DEVELOP LOG. Published April 10, 2021. Accessed April 4, 2022. https://gocheat.github.io/spring/spring_test-1/
> 3. demonic_. [springboot] 데이터 사용 Service를 mockito로 테스트하기. side impact. Published February 11, 2020. Accessed April 4, 2022. https://lemontia.tistory.com/915

<br><br>