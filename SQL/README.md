# sql 공부하다가 모르는 내용 정리

<br>

### JOIN

* `JOIN`이랑 `ON`이랑 무조건 같이 사용해야 되는줄 알았는데 아니였다.

  > 이 때문에 JOIN Type이 무슨 의미가 있는건지 착각했었다.

* Type에 따라서 컬럼값으로 null을 갖는 행이 생길 수 있다.

  기본 Type은 `INNER`로 겹치는 부분만 보여주기 때문에 그럴 일이 없다.

**참고자료**

> 1. MySQL Joins. W3schools.com. Published 2022. Accessed March 5, 2022. https://www.w3schools.com/mysql/mysql_join.asp
> 2. 미래학자. [MySQL] 7장 조인 : JOIN (INNER, LEFT, RIGHT). 미래학자. Published November 22, 2016. Accessed March 5, 2022. https://futurists.tistory.com/17