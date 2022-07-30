# 보글 게임

- ch6. 무식하게 풀기
- 난이도 : 하

<br>

왠지 DP로 해결할 수 있을 것 같아서 다시 도전해봤다.

```
dp[단어길이][y][x] = 가능 여부
```

## 성공

> 저번에 `JUNGOL` 사이트에서 `stream`이랑 `enhanced for 문`을 사용했을때 메모리 초과로 런타임 오류가 나오는 걸 본 뒤로, 
> 
> 알고리즘 문제를 풀때 가능하면 해당 방식을 사용하지 않고 풀려고 했는데 확실히 stream을 쓰는게 코드도 깔끔해지고 훨 편해서 고민이 된다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Cor {

    final int[] dr = {-1, 0, 1, 0, 1, 1, -1, -1};
    final int[] dc = {0, 1, 0, -1, 1, -1, 1, -1};

    public int r, c;

    public Cor(int r, int c) {
        this.r = r;
        this.c = c;
    }

    public Cor move(int dir) {
        int r = this.r + dr[dir];
        int c = this.c + dc[dir];
        return new Cor(r, c);
    }
}

class Main {

    final int SIZE = 5;

    final int TRUE = 1;
    final int FALSE = 0;

    char[][] board;
    int N;
    int[][][] dp;

    String search(String word) {
        initDP(word);
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (search(new Cor(r, c), word) == TRUE) return "YES";
            }
        }
        return "NO";
    }

    int search(Cor cor, String word) {
        if (board[cor.r][cor.c] != word.charAt(0)) return FALSE;
        if (word.length() == 1) return TRUE;

        if (dp[word.length()][cor.r][cor.c] != -1) {
            if (dp[word.length()][cor.r][cor.c] == TRUE) return TRUE;
            if (dp[word.length()][cor.r][cor.c] == FALSE) return FALSE;
        }

        for (int dir = 0; dir < 8; dir++) {
            Cor nextCor = cor.move(dir);

            if (isOutside(nextCor)) continue;

            if (search(nextCor, word.substring(1)) == TRUE) {
                return dp[word.length()][cor.r][cor.c] = TRUE;
            }
        }
        return dp[word.length()][cor.r][cor.c] = FALSE;
    }

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.r >= SIZE || cor.c < 0 || cor.c >= SIZE;
    }

    void initDP(String word) {
        dp = new int[word.length() + 1][SIZE][SIZE];
        for(int[][] a : dp) for(int[] b: a) Arrays.fill(b, -1);
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        board = new char[SIZE][SIZE];
        for (int test = 0; test < T; test++) {

            for (int r = 0; r < SIZE; r++) {
                board[r] = br.readLine().toCharArray();
            }

            N = Integer.parseInt(br.readLine());
            for (int n = 0; n < N; n++) {
                String word = br.readLine();
                sb.append(word).append(" ").append(search(word)).append("\n");
            }
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