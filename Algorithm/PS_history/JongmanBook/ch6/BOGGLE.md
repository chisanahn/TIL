# 보글 게임

ch.6 무식하게 풀기

https://algospot.com/judge/problem/read/BOGGLE

<br>

시간복잡도 분석

```
완전탐색으로 풀 경우 매번 8개의 경우의 수, 단어의 길이 최대 10
시작 칸 마다 8^10 = 2^30 = (2^10)^3 = 1024^3 = 약 10^9. 10억
게임판 총 25칸, 단어마다 250억

시간제한 - 단어마다 1초이므로 시간 초과
```

가지치기를 사용하면 시간복잡도가 줄어드니깐 가능하려나

<details><summary>시간초과 소스코드</summary>

```java
import java.io.*;
import java.util.*;

public class Main {

    String[] board;
    String[] words;

    int[] dx = {-1, -1, -1, 1, 1, 1, 0, 0};
    int[] dy = {-1, 0, 1, -1, 0, 1, 1, -1};

    boolean findWordInBoard(int x, int y, String word, int wordIndex) {
        // 게임판 범위를 벗어나는 경우
        if (x < 0 || y < 0 || x >= 5 || y >= 5) return false;
        if (board[y].charAt(x) != word.charAt(wordIndex)) return false;
        if (wordIndex == word.length() - 1) return true;

        for (int k = 0; k < 8; k++) {
            if (!findWordInBoard(x + dx[k], y + dy[k], word, wordIndex + 1)) continue;

            return true;
        }
        return false;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int numOfTest = Integer.parseInt(br.readLine());
        for (int test = 0; test < numOfTest; test++) {
            board = new String[5];
            for (int i = 0; i < 5; i++) {
                board[i] = br.readLine();
            }

            int numOfWord = Integer.parseInt(br.readLine());
            words = new String[numOfWord];
            for (int i = 0; i < numOfWord; i++) {
                words[i] = br.readLine();
            }

            for (String word : words) {
                boolean isWordInBoard = false;
                for (int y = 0; y < 5; y++) {
                    for (int x = 0; x < 5; x++) {
                        if (!findWordInBoard(x, y, word, 0)) continue;

                        isWordInBoard = true;
                        break;
                    }
                }
                if (isWordInBoard) bw.write(word + " YES\n");
                else bw.write(word + " NO\n");
            }
        }

        br.close();
        bw.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>

문제 `주의` 부분에서 나오듯이 6장의 뒷부분과 8장을 읽고 나서 재도전해봐야겠다.

