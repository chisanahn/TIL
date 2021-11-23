# docker

https://www.itworld.co.kr/news/215339

설치 : https://www.lainyzine.com/ko/article/a-complete-guide-to-how-to-install-docker-desktop-on-windows-10/

유튜브 강의 : https://www.youtube.com/watch?v=hWPv9LMlme8&t=1079s

주로 참고한 블로그 : https://ooeunz.tistory.com/68?category=821628

## 명령어

dockr pull <이미지명>

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
docker-compose로 spring boot + mariaDB 배포하기 https://slog.website/post/11

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

### .dockerignore

어떤 파일들을 제외시켜야할지 아직 잘 모르겠어서 .gitignore 만들듯이 github.io에서 만들었는데 이미지 생성에 필요한 build 디렉터리도 제외시켜버려서 일단 구글링했을때 나오는 예시를 참고했다.
https://github.com/orzeh/spring-boot-gradle-docker-sample/blob/master/.dockerignore

### 명령어

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



## Spring Boot 도커 이미지 최적화

나중에 이것도 고려해본다면 좋을 것 같다.
https://ohjongsung.io/2019/10/20/spring-boot-%EB%8F%84%EC%BB%A4-%EC%9D%B4%EB%AF%B8%EC%A7%80-%EC%B5%9C%EC%A0%81%ED%99%94
https://perfectacle.github.io/2019/04/16/spring-boot-docker-image-optimization/





# AWS

https://ooeunz.tistory.com/70





# CI/CD

추후에 CI/CD를 사용하려면 GitHub-flow 브랜칭 전략을 사용하는게 좋을 것 같다. https://hellowoori.tistory.com/56

2020년 Git/GitHub 특강에서 강사님께서 추천해주신 블로그 https://42place.innovationacademy.kr/archives/5685





# DevOps

https://m.blog.naver.com/acornedu/221519913222

https://aws.amazon.com/ko/devops/what-is-devops/

