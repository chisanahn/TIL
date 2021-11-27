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
