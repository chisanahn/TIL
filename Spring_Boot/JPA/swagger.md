## API 문서를 위한 swagger

Spring에서는 `springfox-boot-starter`를 사용한다.
```gradle
implementation 'io.springfox:springfox-boot-starter:3.0.0'
```

주의 : Swagger 버전에 따라서 제공되는 UI 주소가 다르다.

> Swagger 2를 사용하는줄 알고 `http://localhost:8080/swagger-ui.html`에 접속했는데 401 unauthorized error가 나와서 한참을 헤맸다.

Swagger 3은 `http://localhost:8080/swagger-ui/index.html`을 사용한다.
