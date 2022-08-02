# 쿼드 트리 뒤집기

- ch6. 무식하게 풀기
- 난이도 : 하

https://algospot.com/judge/problem/read/QUADTREE

<br>

## 실패

분명 맞게 푼 것 같은데 어느 부분을 놓친건지 잘 모르겠다.

> 아니 분명 확인했다고 생각했는데 `StringBuilder`를 이용해서 마지막에 한번 출력할때 `System.out.println()`을 쓰면서 한줄이 추가로 출력되서 그런거였다.
>
> 한번도 아니고 여러번 확인했던거 같은데 잠이 부족해서 그런가..

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    String convert(String S) {
        if (S.length() == 1) return S;

        String[] subStrings = new String[4];
        int start = 1, end = 2, i = 1;

        for (int k = 0; k < 4; k++) {
            while (i < end) {
                if(S.charAt(i) == 'x') end+=4;
                i++;
            }
            subStrings[k] = convert(S.substring(start, end));
            start = end;
            end += 1;
        }
        return "x" + subStrings[2] + subStrings[3] + subStrings[0] + subStrings[1];
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            String picture = br.readLine();
            sb.append(convert(picture)).append("\n");
        }
        System.out.print(sb.toString());
        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>

<br>

## 책 참고해서 풀이 개선

생각하지도 못했던 더 간단하게 구현할 수 있는 방법이 있었다.

> 문자열을 탐색하는 변수를 전역변수로 선언해서 사용하는 방법

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    int i;
    String S;

    String convert() {
        if (S.charAt(i) != 'x') return S.charAt(i) + "";

        String[] subStrings = new String[4];
        for (int k = 0; k < 4; k++) {
            i++;
            subStrings[k] = convert();
        }
        return "x" + subStrings[2] + subStrings[3] + subStrings[0] + subStrings[1];
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            S = br.readLine();
            i = 0;
            sb.append(convert()).append("\n");
        }
        System.out.print(sb.toString());
        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}

```

</details>