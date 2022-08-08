# Problem F - 치즈

## 성공

그래프 탐색을 조금 응용하면 간단하게 해결할 수 있는 문제

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    class Cor {
        final int[] dr = {-1, 0, 1, 0};
        final int[] dc = {0, 1, 0, -1};

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

    final int EMPTY = 0;
    final int CHEESE = 1;

    int R, C;
    int[][] board;
    boolean[][] isVisited;

    int dfs(Cor cor) {
        isVisited[cor.r][cor.c] = true;
        if(board[cor.r][cor.c] == CHEESE) {
            board[cor.r][cor.c] = EMPTY;
            return 1;
        }

        int ret = 0;
        for (int dir = 0; dir < 4; dir++) {
            Cor nextCor = cor.move(dir);
            if(isOutside(nextCor)) continue;
            if(isVisited(nextCor)) continue;

            ret += dfs(nextCor);
        }
        return ret;
    }

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.r >= R || cor.c < 0 || cor.c >= C;
    }

    boolean isVisited(Cor cor) {
        return isVisited[cor.r][cor.c];
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new int[R][C];
        for (int i = 0; i < R; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        int cheeseCnt = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == CHEESE) cheeseCnt++;
            }
        }

        int time = 0;
        int lastCheeseCnt = 0;
        for (time = 1; ; time++) {
            isVisited = new boolean[R][C];
            lastCheeseCnt = dfs(new Cor(0, 0));
            cheeseCnt -= lastCheeseCnt;
            if (cheeseCnt == 0) break;
        }

        System.out.println(time);
        System.out.println(lastCheeseCnt);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>