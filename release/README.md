# docker

https://www.itworld.co.kr/news/215339

설치 : https://www.lainyzine.com/ko/article/a-complete-guide-to-how-to-install-docker-desktop-on-windows-10/

유튜브 강의 : https://www.youtube.com/watch?v=hWPv9LMlme8&t=1079s

주로 참고한 블로그 : https://ooeunz.tistory.com/68?category=821628

## 명령어

docker pull <이미지명>

docker image

* ls
* inspect
* search
* rm

docker ps

docker container

* run
* stop
* start
* restart
* rm
* logs -t <컨테이너 식별자>
* attach
* exec
* ls
* stats
* prune : 정지 중인 모든 컨테이너 삭제

### 옵션

> -a : all
>
> -l : last
>
> -i : interactive
>
> -t : 단말기 디바이스 사용
>
> --name : 컨테이너명 지정
>
> -d : 백그라운드에서 실행



### Nginx 서버 기동

#### -p 호스트의 포트 번호:컨테이너의 포트번호

```
docker container run --name webserver -d -p 80:80 nginx
```

container를 생성할때 -p 옵션을 통해서 직접 호스트:컨테이너 포트번호를 지정해 줄 수 있는데 이때 호스트에 80번 포트를 지정했더니 오류가 발생했다.

```
docker: Error response from daemon: Ports are not available: listen tcp 0.0.0.0:80: bind: An attempt was made to access a socket in a way forbidden by its access permissions.
```

아마도 윈도우 subsytem으로 wsl2를 설치하고 그 위에서 도커를 동작하다보니 윈도우에서 사용중인, 권한이 없는 포트를 사용하려고 할 때 이러한 오류가 발생하는 것 같다. https://studyforus.tistory.com/244

참고로 권한은 있지만 이미 할당된 포트를 할당받으려고 할 때는 다음과 같이 오류 로그가 나온다.

```
docker: Error response from daemon: driver failed programming external connectivity on endpoint webserver3 (54c62d2e0c2b059a10d3e27254bd624f2a7513014b6067a4b22fa9c8f7f25d61): Bind for 0.0.0.0:4567 failed: port is already allocated.
```

-p 옵션 대신 -P 옵션을 사용하면 임의의 사용가능한 호스트 포트 번호를 사용한다.



## Dockerfile

https://sas-study.tistory.com/399
https://spring.io/guides/topicals/spring-boot-docker/
docker hub에서 openjdk 버전 확인 https://hub.docker.com/_/openjdk

docker로 배포하기 전에 우선 jar파일로 빌드를 해야 한다. gradle을 사용하는 경우 다음과 같은 방법으로 빌드할 수 있다.

```
$ ./gradlew build
```

Dockerfile로 build를 하는데 자꾸 file을 찾을 수 없다고 나왔는데 알고보니 .dockerignore 파일에 build 디렉토리가 포함되어 있었다. 다행히 stackoverflow에 거의 똑같은 질문이 있어서 쉽게 찾았다.

```
ERROR [2/2] COPY ./build/libs/*.jar app.jar
```

```
lstat /var/lib/docker/tmp/buildkit-mount942646476/build/libs: no such file or directory
```

https://stackoverflow.com/questions/36180296/docker-lstat-no-such-file-or-directory-error-when-building-image-file-is-the

#### .dockerignore

어떤 파일들을 제외시켜야할지 아직 잘 모르겠어서 .gitignore 만들듯이 github.io에서 만들었는데 이미지 생성에 필요한 build 디렉터리도 제외시켜버려서 일단 구글링했을때 나오는 예시를 참고했다.
https://github.com/orzeh/spring-boot-gradle-docker-sample/blob/master/.dockerignore

#### 명령어

* FROM

* RUN

* CMD

* ENTRYPOINT

* ONBUILD

  > 이미지가 생성된 뒤에 실행되는 명령어

* ENV \<key> \<value>

  > 환경 변수 설정

* WORKDIR

* ADD

  > 이동뿐만 아니라 원격 파일의 다운로드, 아카이브의 압축 해제 등의 기능 지원.

* COPY

  > 단순히 이미지 안에 파일을 배치할 경우에 사용.

* EXPOSE <포트 번호>

  > 컨테이너의 공개포트번호 지정.

* ARG \<이름>=\<값>

  > dockerfile 안의 변수

* LABEL

  > 버전, 작성자 등의 정보를 제공할때 사용

* SHELL

  > linux의 경우 기본값 : ["/bin/sh", "-c"]

* VOLUME

  > 이미지에 볼륨 할당.
  >
  > container로 생성될때 자동으로 해당 경로를 host에 연결한다.
  >
  > `/var/lib/docker/volumes/{volume_name}`
  >
  > volume 이름이 자동으로 생성되고 container가 삭제되었을때 데이터를 찾기가 힘들다는 단점이 있다. 이는 해당 container의 재사용성을 떨어뜨릴 수도 있다.



## Volume

container끼리 데이터를 공유할 때, 데이터를 영구적으로 저장해야 할때 사용된다.

호스트의 특정 공간에 공유할 폴더를 생성하는 방식으로 docker 상에서 이미지, 컨테이너, 네트워크와 비슷한 방식으로 관리된다는 이점이 있다.
Dockerfile에서 만들 경우 이름이 무작위로 생성되기 때문에 관리하기가 어렵다. 따로 volume을 만들어두고 container를 run할때 해당 volume을 사용하는 방법이 더 관리하기 좋다.

 `bind-mount`라는 방식도 있는데 이 방법은 Volume과 달리 container의 특정 폴더와 호스트의 특정 폴더를 맵핑해서 사용하는 방식이다.
docker가 관리를 해주진 않지만 로컬 개발 환경을 구성하는 경우 편리하게 사용할 수 있다.

`bind-mount`와 `volume` 모두 volume과 host를 우선적으로 데이터가 관리된다는 점은 동일하지만 `bind-mount`의 경우 만약 container에 host에는 없는 파일이 있다면 container를 실행시킨 후 해당 파일은 사라진다는 점에 주의해야 한다.

> 하지만 runtime 외의 시간에 데이터를 핸들링 하는 것 자체가 권장되지 않으므로 왠만해선 신경 쓸 일이 없다.)

https://0902.tistory.com/6
https://www.daleseo.com/docker-volumes-bind-mounts/
https://velog.io/@1-blue/docker-volume-%EC%82%AC%EC%9A%A9%EB%B2%95

https://darkrasid.github.io/docker/container/volume/2017/05/10/docker-volumes.html



## Docker Compose

https://docs.docker.com/compose/compose-file/compose-file-v3/

여러 컨테이너를 모아서 관리하기 위한 툴

`docker-compose.yml` 파일로 작성

#### yaml 문법

https://subicura.com/k8s/prepare/yaml.html#%E1%84%80%E1%85%B5%E1%84%87%E1%85%A9%E1%86%AB%E1%84%86%E1%85%AE%E1%86%AB%E1%84%87%E1%85%A5%E1%86%B8

- xx:yy 형식

  > 시간으로 해석된다.
  > 시간 외의 목적으로 기술할 경우 `""`로 묶어서 기술

- 배열 형식

  > 예시)
  >
  > environment:
  > 	\- NAME=Chisan Ahn
  > 	\- NICKNAME

- 해시 형식

  > 예시)
  >
  > environment:
  > 	NAME: Chisan Ahn
  > 	NICKNAME: 

#### docker-compose.yml 파일 구성

참고 : [docker-compose로 spring boot + mariaDB 배포하기](https://slog.website/post/11)
https://javatodev.com/docker-compose-for-spring-boot-with-mariadb/#da54d3217caf
https://javachoi.tistory.com/m/400

* services:

  * 서비스명:

    * build:

      * context:

        > 사용할 Dockerfile의 위치 지정.
        > Git 리포지토리의 URL도 사용가능.

      * dockerfile:

      * args:

        > 해시 형식으로 기술.
        > ex) NAME: Chisan Ahn 

    * command:
      entrypoint:

      > 컨테이너 안에서 작동하는 명령 지정
      > 베이스 이미지에 지정되어 있는 명령을 덮어씀.
      >
      > 배열 형식으로 기술.

    * links:

      > 컨테이너간 연결
      >
      > `docker-compose` v.2부턴 모든 컨테이너가 기본 네트워크에 연결되어서 링크가 거의 불필요하다.
      
    * ports:
    
      > <호스트 머신의 포트번호>:<컨테이너의 포트번호> or <컨테이너의 포트번호>
      >
      > 겹따옴표로 묶어서 배열 형식으로 기술.
    
    * expose:
    
      > 링크 기능을 사용하여 연결하는 컨테이너에게만 포트를 공개할 때 사용.
      >
      > ports와 마찬가지로 겹따옴표로 묶어서 배열 형식으로 기술.
    
    * depends_on:
    
      > 서비스 간의 의존관계 정의
      > (컨테이너의 시작순서)
      >
      > 배열 형식으로 기술.
    
    * environment: 
    
      > 컨테이너 환경 변수 지정
      >
      > 배열형식, 해시형식 둘 다 사용 가능.
    
    * env_file: 
    
      > 다른 파일에 환경변수를 정의해서 사용.
    
      > 비밀정보 관리 - 컨테이너 오케스트레이션 툴의 기능 사용 고려
    
    * cotainer_name: 
    
      > 컨테이너명 설정 (이름이 중복될 수 없다.)
    
    * labels:
    
      > 컨테이너 라벨 설정.
      >
      > 여러 개의 라벨을 붙일 경우 배열이나 해시형식으로 기술.
      >
      > 라벨 확인 명령어 : docker-compose config
    
    * volumes:
    
      > 볼륨 마운트 지정
      >
      > 배열 형식으로 기술.
      > `:ro`를 뒤에 붙여서 읽기 전용으로 마운트 할 수 있음.
    
    * volumes_from:
    
      > \- <컨테이너명>
      >
      > 해당 컨테이너의 모든 볼륨을 마운트한다.
      >
      > 배열 형식으로 기술.

#### 명령어

docker compose

* up : 컨테이너 생성
* ps/logs : 컨테이너 확인
* run : 컨테이너에서 명령 실행
* start/stop/restart
* pause/unpause
* post/config
* kill/rm
* down

#### 처음 시도할때 놓쳤던 부분들

- db에서 MYSQL_ROOT_PASSWORD는 꼭 설정해줘야한다.

- 로컬에서 구성할때와 달리 스프링에서 db 연결 url을 실제 ip 주소가 아닌 서비스명을 넣어줘야 한다.

  그리고 원래 application.properties 파일에 db 관련 값들을 넣어줬는데 docker-compose.yml에 파일에 환경별수로 설정해주는게 더 좋을 것 같다.

  ```yaml
  environment:
      SPRING_DATASOURCE_URL: jdbc:mariadb://<서비스명>:<포트번호>/<DB명>?useUnicode=true
      SPRING_DATASOURCE_USERNAME: 유저명
      SPRING_DATASOURCE_PASSWORD: 비밀번호
  ```

#### 이미지 실행 후 DB에 직접 접근하는 방법

```
docker exec -it db /bin/bash
```

```
mysql -u <유저명> -p
> <비밀번호>
```





#### volume 설정

https://int-i.github.io/sql/2020-12-31/mysql-docker-compose/

엄밀히 말하자면 `volume`이 아니라 `bind-mount` 방식인거같다.

`volume`을 생성해서 연결하는 방식은 좀 더 알아보기.



#### image 이름 관련 이슈

docker-compose로 생성되는 이미지명 지정하는 방법 : https://stackoverflow.com/questions/32230577/how-do-i-define-the-name-of-image-built-with-docker-compose

그리고 dockerhub에 push 하려면 이미지 이름을 규칙에 맞게 생성해야 한다.
https://stackoverflow.com/questions/41984399/denied-requested-access-to-the-resource-is-denied-docker

docker image 이름 변경하는 방법 : https://stackoverflow.com/questions/25211198/docker-how-to-change-repository-name-or-rename-image

> image 이름이 tag인데 tag는 한 이미지가 여러개를 가질 수 있다.





#### 추후에 고려할점

DB를 server랑 연결할때 `ports`로 연결할지 `links`로 연결할지.

Docker 메모리 제한 설정해두기.

> 노트북에 부담이 많이 된다.



## 도커 허브 이용

docker-compose로 이미지를 생성한뒤 docker hub에 pull 한뒤 나중에 ec2에서 해당 image를 push 받아 사용한다.

https://www.lainyzine.com/ko/article/how-to-sign-in-to-docker-from-the-command-line/

```
$ docker login -u [ID]
Password:
```

Docker Hub 계정 생성 https://www.lainyzine.com/ko/article/how-to-create-a-docker-hub-account/

docker push

```
docker push 
```



## Spring Boot 도커 이미지 최적화

나중에 이것도 고려해본다면 좋을 것 같다.
https://ohjongsung.io/2019/10/20/spring-boot-%EB%8F%84%EC%BB%A4-%EC%9D%B4%EB%AF%B8%EC%A7%80-%EC%B5%9C%EC%A0%81%ED%99%94
https://perfectacle.github.io/2019/04/16/spring-boot-docker-image-optimization/



# AWS

https://ooeunz.tistory.com/70

EC2 튜토리얼 https://ooeunz.tistory.com/35?category=816210

보안 그룹 설정 https://us-east-2.console.aws.amazon.com/ec2/v2/home?region=us-east-2#LaunchInstanceWizard:

처음 instance 생성시 생성되는 유저명은 ubuntu의 경우 `ubuntu`이다. https://docs.aws.amazon.com/ko_kr/AWSEC2/latest/UserGuide/managing-users.html



로컬에서는 이미지가 잘 동작해서 괜찮을 줄 알았는데 EC2에 올려서 배포하니깐 DB랑 제대로 연결이 안되면서 오류가 난다.

```
java.sql.SQLNonTransientConnectionException: Could not connect to address=(host=localhost)(port=3306)(type=master) : Socket fail to connect to host:localhost, port:3306. Connection refused (Connection refused)
```

인터넷에 검색해봐도 docker-compose에서 컨테이너별로 포트를 할당하는 예제를 찾기가 어려워서 결국 어제는 해결하지 못했다.

우선 로컬에서 DB를 지운채로 docker-compose 환경을 구성해보고 docker-compose 배포 예제를 좀 더 찾아봐야겠다. https://www.google.com/search?q=docker+compose+%EB%B0%B0%ED%8F%AC&oq=docker+compose+%EB%B0%B0%ED%8F%AC&aqs=chrome..69i57j69i59j0i5i30j0i8i30j69i61l3.4530j0j7&sourceid=chrome&ie=UTF-8

만약 결국 해결하지 못하면 DB를 따로 분리해서 관리하는 방법을 시도해보는게 좋을 것 같다. https://velog.io/@dohaeng0/AWS%EC%97%90-Spring-Boot-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EB%B0%B0%ED%8F%AC-1-RDS-MySQL-%EC%84%B8%ED%8C%85



우선 배포를 더 해보기 전에 docker-compose 파일 문법부터 자세하게 알고 넘어가는게 좋을 것 같아서 찾아봤다.
https://nirsa.tistory.com/79
https://jojoldu.tistory.com/587

* 포트번호를 입력할때 따옴표로 묶는걸 깜빡했었다. `"3306:3306"`
* version으로 명시하는게 생성할 이미지의 버전인줄 알고 0.1로 명시했었는데 docker-compose 버전이였다 ㅋㅋㅋㅋㅋ version 2부터 depends_on 명령과 networking이 추가되었기 때문에 이 부분에서 오류가 났던것 같다. https://meetup.toast.com/posts/277 `version: "0.1"`

* 처음에 조금 햇갈렸는데 docker compose의 버전과 docker compose file format 버전이 따로 있다.
  https://docs.docker.com/compose/compose-file/compose-versioning/

  ```
  In addition to Compose file format versions shown in the table, the Compose itself is on a release schedule, as shown in Compose releases, but file format versions do not necessarily increment with each release. For example, Compose file format 3.0 was first introduced in Compose release 1.10.0, and versioned gradually in subsequent releases.
  
  The latest Compose file format is defined by the Compose Specification and is implemented by Docker Compose 1.27.0+.
  ```

  현재 latest 버전은 v2.2.1이고 window의 경우 docker desktop에 포함되어 있다.

  리눅스의 경우 별도로 설치해줘야 한다. ec2에 이전에 1.24.0 버전을 설치해서 v1.27.0로 다시 설치해줬다.
  https://stackoverflow.com/questions/49839028/how-to-upgrade-docker-compose-to-latest-version
  https://docs.docker.com/compose/install/
  https://github.com/docker/compose
  latest는 v2.1.1인데 다운이 잘 안되서 일단 docker compose file format을 모두 지원하는 1.27.0을 설치했다.
  
  docker compose file fomat의 경우 version 3 공식 문서가 가장 잘 정리되어있는거 같아서 그 중 최신버전인 3.9를 사용하기로 결정했다.
  https://docs.docker.com/compose/compose-file/compose-file-v3/
  
* 네트워크 관련 설정 옵션. 읽어보면 도움이 될 것 같다.
  https://meetup.toast.com/posts/277

* 



DB 외부 접속 관련해서 설정을 해줘야 되나 하는 생각이 들기도 했다.
https://docs.3rdeyesys.com/5.database/ncp_database_mariadb_access_from_remote_ubuntu/

하지만 일단 서버와 DB는 docker-compose로 묶여있기때문에 굳이 외부 접속이 필요할 것 같진 않을거같다.



# CI/CD

추후에 CI/CD를 사용하려면 GitHub-flow 브랜칭 전략을 사용하는게 좋을 것 같다. https://hellowoori.tistory.com/56

2020년 Git/GitHub 특강에서 강사님께서 추천해주신 블로그 https://42place.innovationacademy.kr/archives/5685

[CI Tool 비교](https://elfinlas.github.io/2019/08/14/ci-tool/)



# DevOps

https://m.blog.naver.com/acornedu/221519913222

https://aws.amazon.com/ko/devops/what-is-devops/

