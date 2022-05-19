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

<br><br>

### table을 초기화하고 싶은 경우

```sql
SET FOREIGN_KEY_CHECKS = 0;

TRUNCATE table1;
TRUNCATE table2;

SET FOREIGN_KEY_CHECKS = 1;
```

> **참고자료**
>
> https://stackoverflow.com/questions/5452760/how-to-truncate-a-foreign-key-constrained-table

<br><br>

### pivot

row data를 column으로 옮기고 싶을때 사용하는 방식

| id   | preference | preferenceCount |
| ---- | ---------- | --------------- |
| 1    | DISLIKE    | 2               |
| 1    | LIKE       | 3               |

이런 table에서 id별로 DISLIKE 개수와 LIKE 개수를 한 row에 표시하고 싶을때 pivot을 사용할 수 있다.

```sql
SELECT
	id,
	MAX(case when preference='DISLIKE' then preferenceCount ELSE 0 END) AS dislikeCount,
	MAX(case when preference='LIKE' then preferenceCount ELSE 0 END) AS likeCount
FROM table
GROUP BY id
```

실행 결과

| id   | dislikeCount | likeCount |
| ---- | ------------ | --------- |
| 1    | 2            | 3         |

> **참고자료**
>
> https://www.databasestar.com/mysql-pivot/

<br><br>

### insert or ignore into

field 값에 unique 제약을 부여했을때 `insert into` 대신 `insert or ignore into`를 사용하면 unique constraint failed exception이 뜨지 않도록 할 수 있다.

> **참고자료**
>
> https://stackoverflow.com/questions/65650852/how-to-handle-unique-constraint-failed-exception-in-sqlite
