# Problem L - 쇠막대기

## 성공. 약 10분

단순한 구현 문제

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        int numOfLine = 0;
        long answer = 0;
        for (int i = 0; i < input.length(); i++) {
            if(input.charAt(i) == '(') {
                if(input.charAt(i+1) == ')') {
                    answer += numOfLine;
                    i++;
                } else {
                    numOfLine++;
                }
            } else {
                numOfLine--;
                answer++;
            }
        }
        System.out.println(answer);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>