# 1:1관계 in JPA

크게 2가지 방법이 있는듯

* Foreign Key를 이용한 양방향 관계

  > 단방향 관계는 JPA에서 지원하지 않는다고 한다.

  * 주 테이블에 외래키를 넣는 방법
  * 대상 테이블에 외래키를 넣는 방법

* shared primary key

근데 각각의 방법이 어떤 장단점이 있는지는 아직 잘 모르겠다.

나름대로 생각해보자면 FK를 이용해서 만들면 FK를 가지고 있는 쪽에서 교체하기에 용이할듯?

성능 상으로는 어떤게 이점을 가지고 있을라나

<br>

> **참고자료**
>
> 1. baeldung. One-to-One Relationship in JPA | Baeldung. Baeldung. Published December 8, 2018. Accessed April 3, 2022. https://www.baeldung.com/jpa-one-to-one
> 2. nroo. [JPA] @OneToOne, 일대일[1:1] 관계. 개발자의 기록습관. Published August 23, 2019. Accessed April 3, 2022. https://ict-nroo.tistory.com/126