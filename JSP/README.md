## intellj에서 tomcat, jsp 개발 초기 환경 설정

https://velog.io/@ruddms936/IntelliJ%EB%A1%9C-JSP-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EC%83%9D%EC%84%B1

https://suyeonchoi.tistory.com/m/33

intellij 버전 문제 때문인지 `javax.servlet:javax.servlet-api:4.0.1`를 설치했지만 여전히 new -> servlet 항목은 보이지 않았다.

`New Project -> Java Enterprise`를 전에 몇 번 시도해봤는데 오류가 나고 제대로 생성되지 않아서 이번이 마지막이라고 생각하고 만들어봤는데 성공적으로 만들어지고, New 항목에 servlet 항목도 보인다.

Ultimate 버전을 사용하는 경우 꼭 Java Enterprise로 프로젝트를 생성하는게 좋을 것 같다.

https://ishyeok.tistory.com/40

tomcat을 실행할때 intellij를 관리자 권한으로 실행하지 않으면 권한 관련해서 오류가 발생해서 intellij가 기본적으로 권리자 권한으로 실행되도록 설정했다.

하는김에 `Windows Terminal`도 관리자 권한으로 실행되도록 설정했다.

> https://pureinfotech.com/always-run-windows-terminal-administrator-windows-10/에서 Windows Terminal 실행프로그램 위치를 참고했다.

<br>

## jsp 에러

https://m.cafe.daum.net/mobilejavaprogram/Cn1Y/43?listURI=%2Fmobilejavaprogram%2FCn1Y

`org.apache.jasper.JasperException: /index.jsp (line: [1], column: [87]) equal symbol expected`

page 지시어 부분에 `"`가 빠져있다던지 문법적인 오류가 있으면 발생하는 오류

<br>

## url 맵핑

https://kamang-it.tistory.com/71

`web.xml` 파일에서 지정해 줄 수 있다.

* servlet의 경우

    ```xml
    <servlet>
        <servlet-name>Hello-Servlet</servlet-name>
        <servlet-class>Hello</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>Hello-Servlet</servlet-name>
        <url-pattern>/hello</url-pattern>
    </servlet-mapping>
    ```

* jsp의 경우

    ```xml
    <servlet>
        <servlet-name>hello2-jsp</servlet-name>
        <jsp-file>/hello2.jsp</jsp-file>
    </servlet>
    <servlet-mapping>
        <servlet-name>hello2-jsp</servlet-name>
        <url-pattern>/hello2</url-pattern>
    </servlet-mapping>
    ```

servlet의 경우, `@WebServlet` 어노테이션을 사용해서 `web.xml` 파일에 따로 설정할 필요 없이 java 파일 안에서 간단하게 설정할 수 있다.

```java
@WebServlet(name = "helloServlet", value = "/hello-servlet")
```

<br>
