# C. Detective Task

단순? 구현 문제

## 성공. 21분 정도 소요.

```java
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {


    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfTest = Integer.parseInt(br.readLine());

        for (int test = 0; test < numberOfTest; test++) {
            String answerOfFriends = br.readLine();
            // 0 : no
            // 1 : yes
            // ? : can't remember
            // 도둑을 제외한 나머지 사람은 truth
            // 도둑은 truth 일수도 아닐수도 있음

            // 도둑 뒤에는 무조건 0
            // -> 마지막으로 나온 1만 도둑일 수 있음
            // -> 처음으로 나온 0이 도둑일 수 있음
            // -> 1보다 뒤 0보다 앞에 있는 ?

            int numberOfSuspected = 0;

            int lastIndexOfOne = -1;
            int firstIndexOfZero = -1;
            int numOfQuestionBtwLastOneAndFirstZero = 0;
            for (int i = 0; i < answerOfFriends.length(); i++) {
                if(answerOfFriends.charAt(i) == '?' && firstIndexOfZero == -1) {
                    numOfQuestionBtwLastOneAndFirstZero++;
                }
                if (answerOfFriends.charAt(i) == '1') {
                    if(lastIndexOfOne == -1) numberOfSuspected++;
                    lastIndexOfOne = i;
                    numOfQuestionBtwLastOneAndFirstZero = 0;
                }
                if (answerOfFriends.charAt(i) == '0' && firstIndexOfZero == -1) {
                    firstIndexOfZero = i;
                    numberOfSuspected++;
                }
            }
            numberOfSuspected += numOfQuestionBtwLastOneAndFirstZero;
            System.out.println(numberOfSuspected);
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

