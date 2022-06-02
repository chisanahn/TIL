# Properties file

database url, user, password 등 환경설정 data들을 관리하기 위한 파일

resources 폴더에 위치하고, 읽어올때는 classpath에서 읽어오면 된다.

```java
클래스명.class.getClassLoader().getResourceAsStream(파일명)
```

<br>

> **참고자료**
>
> https://mkyong.com/java/java-properties-file-examples/