# JSP + tomcat + mySQL + ubuntu 배포

삽질 이력

배포할 서비스 : https://github.com/chisan01/balance_game_community

<br>

## 홈 서버 구축

* https://varins.com/library/server/install-ubuntu-server/#%eb%a9%94%ec%9d%b8%eb%b3%b4%eb%93%9c-bios-%ec%84%a4%ec%a0%95

  > 추후에 nginx를 사용해서 프록시를 구축해서 사용하는 연습도 해보면 좋을 것 같다.

* https://www.whatwant.com/m/entry/notebook-ubuntu-server

<br>

### linux server 설치

안 쓰던 구식 노트북에서 만약을 대비해서 윈도우를 살리기 위해서 디스크 파티션을 나눈 뒤에 설치해줬다.

https://ubuntu.com/server/docs/install/step-by-step

<br>

### 보안 설정

* 간단한 방화벽 설정 (UFW)

  https://webdir.tistory.com/206

* 해외 IP 차단

  https://shutcoding.tistory.com/24

* 공개키 생성 + 비밀번호 로그인 제한

  https://tttap.tistory.com/131

* 로그인 내역 확인 명령어 `last`

  https://www.baeldung.com/linux/last-command

* ssh 보안 설정

  https://zipi.me/601

<br>

### 공유기 포트포워딩 설정

우선 외부에서 우리 서버로 접속할 수 있도록 공유기에서 서버에 고정 IP를 할당해주고, 포트포워딩 설정을 해줬다.

우리집의 경우 SKT로 모뎀이 연결되어있어서 모뎀에서 해당 설정을 해줬다.

* 서버 관리를 위해서 22번 포트를 열어주고

  > 보안으로 인해서 외부적으로 노출되는 포트는 다른 포트를 사용했다.

* 배포할 서비스를 위해서 80번 포트를 열어줬다.

https://comterman.tistory.com/1408

<br><br>

## Docker 설정

docker compose 파일을 이용해서 db와 tomcat을 service로 만들었다.

https://slog.website/post/11

<br>

### Tomcat

tomcat의 경우 war 파일을 tomcat 내부 폴더에 옮겨서 실행하도록 `Dockerfile`을 만들었다.

`ADD`나 `COPY`를 이용해서 배포할 서비스의 `.war` 파일을 `/usr/local/tomcat/webapps`에 넣어주기만 하면 끝이다.

https://hiberstack.com/deploy-war-file-on-tomcat-docker-container/

<br>

#### .war 파일

프로젝트를 git clone 받아와서 gradle로 build하고 war파일을 만들려고 했다.

```bash
$ sudo apt install gradle
```

생각없이 추천되는 명령어로 설치했다가 4.4.1 버전이 깔려서 빌드 실패.

intellij에서 사용하고 있는 gradle 버전을 확인해서 다시 설치했다

https://yallalabs.com/devops/how-to-install-gradle-ubuntu-18-04-ubuntu-16-04/

이번에 build는 정상적으로 동작했지만 테스트 DB를 따로 설정해두지 않아서 테스트 케이스가 실패하면서 빌드가 되지 않았다.

서버에 테스트 DB까지 구축할 필요는 없을 것 같아서 일단 war 파일을 .gitignore에서 제외하고 commit 해서 배포했다.

> 추가로 서비스를 수정하고 나서 war 파일 build하는걸 깜빡하는 경우가 있으니 주의하자
>
> .war 파일만을 사용하기 때문에 build하지 않으면 수정하지 않은 것과 마찬가지

<br>

#### application context 설정 - url

기본적으로 war파일로 배포된 서비스는 war 파일명을 URL에 추가해서 사용해야 한다.

하지만 html이랑 jsp에서 절대경로를 사용하는데, Tomcat application context가 root가 아니라서 오류가 발생했다.

> intellij에서 절대 경로를 추천하지 않던 이유가 이거 때문인 것 같다.

그리고 사용성을 위해서라도 Tomcat의 application context를 수정하기로 생각했다.

기존에 존재하던 `/usr/local/tomcat/webapps/ROOT` 폴더명을 변경하고, `.war` 파일의 이름을 `ROOT.war`로 변경해서 넣어주면 된다.

* `Dockerfile` 다음과 같이 수정

    ```
    ADD ./build/libs/balance_game_community-1.0-SNAPSHOT.war /usr/local/tomcat/webapps/ROOT.war
    ```
* 실행 중인 tomcat container 내부에서 명령어 실행
    ```
    $ sudo docker exec -it bgc_app /bin/bash
    $ mv /usr/local/tomcat/webapps/ROOT /usr/local/tomcat/webapps/ROOT-temp
    ```

https://www.lifencoding.com/web/28?p=1

<br>

### DB

#### root password 설정

잘 작동했지만 DB 관련 설정을 몇가지 빼먹어서 정상적으로 동작하지 않았다.

```
 Database is uninitialized and password option is not specified
balance_game_community-database-1     |     You need to specify one of the following:
balance_game_community-database-1     |     - MYSQL_ROOT_PASSWORD
balance_game_community-database-1     |     - MYSQL_ALLOW_EMPTY_PASSWORD
balance_game_community-database-1     |     - MYSQL_RANDOM_ROOT_PASSWORD
```

docker compose 파일에 DB root password 환경변수를 추가해주고 다시 실행하면 된다.

```yaml
environment:
- MYSQL_ROOT_PASSWORD=1234
```

<br>

#### database가 생성되지 않는 오류

```
java.sql.SQLException: Access denied for user 'balance_game_community'@'172.19.0.3' (using password: YES)
```

database 연결 부분에서 오류가 나서 mysql 컨테이너에 직접 접속해서 확인해보니 database 자체가 아예 생성되지 않았다.

```
docker exec -it <컨테이너명> /bin/bash
```

`docker-compose.yml` file에서 DB 데이터를 volume을 할당해서 관리하는데 맨 처음에 해당 폴더가 비어있지 않으면 데이터베이스가 정상적으로 초기화되지 않는다고 한다.

https://github.com/MariaDB/mariadb-docker/issues/68

해당 폴더를 지우고 하니깐 database가 정상적으로 생성된다.

하지만 table 만드는걸 깜빡해서 `docker-entrypint-initdb.d`를 설정해줬다.

https://judo0179.tistory.com/69

<br>

#### database 설정

* ##### `lower_case_table_names` 설정 오류

    window desktop에 mysql을 설치하면 기본적으로 테이블명이 대소문자 구분없이 저장되도록 설정되어 있다.

    하지만 linux의 경우 종종 이 설정이 다르게 되어있어서 오류가 발생한다.
    
    > 나도 개발할 때와 달리 table명에 대소문자가 구분되어서 저장되면서 오류가 발생했다.
    >
    > 그래서 init.sql에서 테이블명을 소문자만 사용하도록 수정했지만, 이제는 table이 제대로 생성되지 않는 문제가 생겼었다.
    >
    > 그래서 사용된 sql 문에서 table명을 대소문자가 구분되도록 수정하려다가 `대소문자 구분 옵션`이 있는걸 알게되어서 쉽게 해결했다.

    `lower_case_table_names` 값을 `1`로 바꿔주면 된다.

    https://cloud-oky.tistory.com/326

    그리고 `docker-compose.yml` file에 volume을 할당해서 데이터베이스 설정 파일을 간편하게 관리할 수 있다.
    
    https://int-i.github.io/sql/2020-12-31/mysql-docker-compose/

<br>

* ##### `sql_mode` 설정 오류

  `SELECT list is not in GROUP BY clause and contains nonaggregated column 'b.difficulty' which is not functionally dependent on columns in GROUP BY clause; this is incompatible with sql_mode=only_full_group_by` 오류가 나서 관련 설정도 추가해줬다.

  https://stackoverflow.com/questions/41887460/select-list-is-not-in-group-by-clause-and-contains-nonaggregated-column-inc

<br>

## 성공!