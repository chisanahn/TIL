## @JoinColumn default value

`@JoinColumn`으로 외래키 이름을 명시하지 않는 경우 JPA에서 다음과 같은 규칙으로 자동으로 외래키 이름을 지정해준다.

```
<field_name>_<id_column_name>
```

https://stackoverflow.com/questions/34788151/is-joincolumn-annotation-mandatory-in-hibernate

<br>


## JPA 사용시 테스트 코드에서 `@Transactional` 사용 주의

JPA에서 DB 데이터를 변경하는 경우에 `@Transactional`을 사용해야 한다고 한다.

이때, Test에서 테스트 코드가 수행된 후에 rollback이 되도록 하는 용도로도 `@Transactional`을 사용했던 것 같아서 좀 찾아봤는데

`@Service`에서는 `@Transactional`을 사용하지 않고 테스트코드에서만 `@Transactional`을 사용하면 테스트 코드는 통과하지만 실제 서비스에서는 오류가 발생하는 상황이 된다고 한다.

> **참고자료**
>
> ds_chanin. JPA 사용시 테스트 코드에서 @Transactional 주의하기. 자바봄. Published September 23, 2020. Accessed April 14, 2022. https://javabom.tistory.com/103

영속성 컨텍스트와 Lazy Loading이라는 단어가 나오는데 이게 뭔지 한번 공부해봐야할 것 같다.

* 영속성 컨텍스트 : https://velog.io/@neptunes032/JPA-%EC%98%81%EC%86%8D%EC%84%B1-%EC%BB%A8%ED%85%8D%EC%8A%A4%ED%8A%B8%EB%9E%80

이후에 https://velog.io/@giantim/5 글도 한번 다시 보면 좋을 것 같다.

<br><br>

## Entity에서 외래키에 대해서 id만 저장하는 것이 가능한가?

가능하다. 다만, hibernate의 장점을 누리기 위해선 object를 저장해서 사용하는 것이 더 좋다는 답변도 있고, lazy loading 같은 개념에 대해서 더 공부해봐야 어떤 장단점이 있는지 알 수 있을 것 같다.

> **참고자료**
>
> https://stackoverflow.com/questions/6311776/hibernate-foreign-keys-instead-of-entities/6312018#6312018
>
> https://stackoverflow.com/questions/2111294/is-it-possible-to-have-foreign-key-enforced-without-object-to-object-mapping?noredirect=1&lq=1

<br><br>

## Entity 생성, 업데이트 날짜 관련 Annotation

query가 실행됨에 따라 자동으로 timestamp 값을 업데이트해준다.

> 이런 것도 있다니 신기했다.

* `@CreationTimestamp`
* `@UpdateTimestamp`

https://velog.io/@koo8624/Spring-CreationTimestamp-UpdateTimestamp