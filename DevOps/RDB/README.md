## m1 mysql 설치
https://velog.io/@haleyjun/MySQL-Mac%EC%97%90-MySQL-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B0-M1%EC%B9%A9

<br>

## `order` 테이블 오류

`order`는 sql 예약어로 테이블명으로 order를 사용하면 sql문을 사용할때 오류가 발생한다.

> 오류의 원인을 찾기도 힘들다...

<br>

## user와 user profile을 하나의 테이블에 저장해도 될까?

성능, 유지보수를 고려해서 테이블을 분리해서 저장하는 것이 좋다.

* 자주 변경이 일어나는 정보들과 그렇지 않은 정보들을 구분해서 저장하면 정보의 특성에 맞게 최적화 할 수 있다.
* full-scan을 자주해야하는 테이블의 경우, 테이블의 크기가 커지면 성능에 안좋은 영향이 있을 수 있다.

> **참고자료**
>
> 1. https://stackoverflow.com/questions/3889797/mysql-user-profile-details-table-setup-best-practice
> 2. https://softwareengineering.stackexchange.com/questions/241089/keep-user-and-user-profile-in-different-tables
> 3. https://stackoverflow.com/questions/5671562/storing-user-profile-data-in-the-users-table-or-separate-profile-table

<br>

## 외래키를 Primary Key로 사용해도 될까?

1대1 관계에서는 사용해도 무관하다.

> **참고자료**
>
> https://stackoverflow.com/questions/10982992/is-it-fine-to-have-foreign-key-as-primary-key#:~:text=It%20is%20perfectly%20fine%20to,one%2Dto%2Dmany%20relationship.

<br>

## MySQL

설치

https://velog.io/@joajoa/MySQL-%EB%8B%A4%EC%9A%B4%EB%A1%9C%EB%93%9C-%EB%B0%8F-%EC%84%A4%EC%B9%98-%EB%B0%A9%EB%B2%95

https://www.mysqltutorial.org/what-is-mysql/

튜토리얼

https://opentutorials.org/course/195

https://www.mysqltutorial.org/



## MariaDB로 변경

카페에서 linux로 설치 시도. 책을 따라서 설치했는데 오류도 많이나고 결국 성공하지 못했다.

오랜만에 linux를 사용해서 그런지 명령어도 많이 낯설고 개념도 좀 헷갈려서 더 어려움을 겪었다.

[linux 사용자와 그룹](https://nolboo.kim/blog/2015/08/18/linux-users-groups/)

https://linuxize.com/post/how-to-install-mariadb-on-ubuntu-20-04/ 를 참고해서 다시 시도.

key를 받아오는 과정에서 오류가 발생하는데 검색해봐도 잘 나오지 않아서 wsl 설치를 잘못 했던것같다.

다음에 다시 해보기로 하고 일단 윈도우에 설치해서 사용하기로 했다.



## query문

#### RANK()

> https://www.google.com/search?q=mysql+%EC%88%9C%EC%9C%84%ED%91%9C&oq=mysql+%EC%88%9C%EC%9C%84%ED%91%9C&aqs=chrome..69i57j0i333l4.2460j0j7&sourceid=chrome&ie=UTF-8
>
> https://www.bloger.kr/51
>
> query문에서 처음보는 것들이 많아서 헤맸는데 잘 정리되어있는 블로그를 하나 찾았다. http://nodapiseverywhere.blogspot.com/2016/11/mysql-ranking-query.html 이 블로그에 댓글에서 알게된건데 mysql 0.8 업데이트 이후 RANK() 함수가 추가되었다.
>
> https://www.mysqltutorial.org/mysql-window-functions/mysql-rank-function/
>
> dense_rank() 함수를 사용하면 동점자들 처리가 더 간편하다.
>
> https://www.javatpoint.com/mysql-ranking-functions

#### 날짜 관련 함수

> http://happycgi.com/community/bbs_detail.php?bbs_num=43&tb=board_man_story

#### select로 받아올 row개수 제한

> https://dirask.com/posts/MySQL-select-first-N-rows-1GBgbj
>
> 뒤에 `LIMIT 개수`를 추가해주면 된다.

<br>

## 데이터 삭제시 외래키 고려

삭제할 데이터를 외래키로 사용하는 데이터가 있는 경우

1. 해당 데이터를 외래키로 사용하는 데이터부터 삭제
2. 남겨야 할 데이터의 경우 해당 데이터의 외래키 값을 다른 데이터를 가리키도록 변경.

> 예시 : 유저를 삭제하더라도 해당 유저의 게시글은 남기려면 기본 유저를 하나 만들어놔서 유저를 삭제하기 전 해당 유저의 게시글들의 member_id를 기본 유저로 교체해준다.

<br>

## Access Denied 에러

동기 도와주다가 알게 된 사실.

* 비밀번호를 잘못 입력한 경우에도 Access Denied 에러가 나므로 주의해서 입력하자...

그리고 삽질하는 과정에서 문득 이상한 생각이 들었다가 개념을 다시 정리하고 넘어갈 수 있었다.

예전에 팀 프로젝트에서 사용했던 계정으로 heidisql에 다시 접속해봤더니 데이터베이스가 하나만 나와서 데이터베이스 하나가 포트 번호 하나를 할당해서 사용하는걸로 잠시 착각했었다.

그런데 heidisql에서는 IP주소랑 포트번호, 유저, 비밀번호만 입력받고 따로 데이터베이스를 특정할 수 있는게 없어서 어 이게 뭐지..? 싶었고, 그래서 Spring Boot에서 따로 특정 database를 container처럼 포트 번호를 할당해서 사용하나? 했는데 Spring Boot가 실행되지 않더라도 독립적으로 멀쩡히 잘 작동한다. 그러다가 root 계정으로 로그인 해보고서야 잠시 착각하고 있었다는걸 알게되었다.

* 우선, MySQL은 엔진 자체가? 포트번호 3306번을 기본적으로 할당받고 (mongoDB는 기본적으로 7706번이였나 아무튼 DB 엔진별로 포트번호를 할당받는다.)

* heidisql에서 특정 유저로 로그인하게 되면 권한이 부여된 데이터베이스에 한해서만 보여진다.

  따라서 프로젝트를 할때 관련있는 데이터베이스에서만 권한이 부여된 유저를 따로 생성해서 관리하는 것이 편하다.
