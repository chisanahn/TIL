# Spring jpa fetch

발단 : fetch join이 뭐지? 

자료를 찾아보다가 우선 jpa에서 fetchType이 무엇인지에 대해서 먼저 알아봐야겠다는 생각이 들었다.

<br>

## FetchType

https://ict-nroo.tistory.com/132

Entity간에 relation이 존재하는 경우, 연관된 entity를 어떻게 가져올지에 대한 전략

- FetchType.LAZY : 처음에는 가져오지 않고 추후에 해당 데이터에 대한 요청이 들어오면 그때 가져오는 방식

- FetchType.EAGER : 처음에 연관된 Entity를 모두 가져오는 방식

- 각각의 방식에 대한 장단점이 존재하지만 EAGER의 경우, 예상하지 못한 SQL이 발생하거나 JPQL에서 N+1 문제를 일으키는 등 치명적인 문제가 발생해서 실무에서는 가급적 LAZY를 사용한다고 한다.

  만약 연관된 entity를 함께 가져와야한다면, EAGER 대신 사용할 수 있는 방법이 여러가지 존재하고 그 중에서도 LAZY + fetch join 을 주로 사용한다고 한다

- @ManyToOne, @OnetoOne의 경우 기본값이 EAGER이므로 LAZY로 명시해줘야함에 주의.



## JPQL에서 N+1 문제

쿼리 1개로 인해서 N개의 추가적인 쿼리가 발생하는 경우

https://jojoldu.tistory.com/165

https://wwlee94.github.io/category/blog/spring-jpa-n+1-query/

- 추가적으로 자료를 찾아봤는데 LAZY에서도 하위 Entity를 조회한다면 N+1 문제가 발생한다.

- 그리고 Fetch join을 사용하는 경우 데이터가 중복 저장되는 문제가 발생해서 이 부분에 대한 처리가 추가적으로 필요하다고 한다.

- JPA에서 제공하는 페이징 API 사용도 불가능하다고 한다

- 처음에 좀 헷갈렸는데 FetchType.EAGER 를 사용하더라도 JPQL을 사용하지 않는다면 N+1 문제는 발색하지 않는다.