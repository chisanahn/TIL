# B. 문자마름모

## 성공

생각보다 이동방향을 구현하는것이 까다로워서 애를 먹었다.

단순한 예시에서 직접 좌표를 찍어보고나니 그나마 수월하게 구현할 수 있었다.

> 역시 아직 빡 구현 문제에서 많이 부족함을 느낀다.

<details><summary>소스코드</summary>

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

enum DIR {
    LEFT_DOWN, RIGHT_DOWN, RIGHT_UP, LEFT_UP
}

class Cor {
    final int[] dr = {1, 1, -1, -1};
    final int[] dc = {-1, 1, 1, -1};

    public int r, c;

    public Cor(int r, int c) {
        this.r = r;
        this.c = c;
    }

    public Cor move(DIR dir) {
        int r = this.r + dr[dir.ordinal()];
        int c = this.c + dc[dir.ordinal()];
        return new Cor(r, c);
    }
}

class Main {

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        char[][] board = new char[N * 2 - 1][N * 2 - 1];
        for (char[] rows : board) Arrays.fill(rows, ' ');
        int maxR = N * 2 - 2;
        int minC = 0;
        int maxC = N * 2 - 2;

        int cnt = 0;
        Cor curCor = new Cor(0, N - 1);
        DIR dir = DIR.LEFT_DOWN;
        while (true) {
            if (dir == DIR.LEFT_DOWN && curCor.c == minC) {
                minC++;
                dir = DIR.RIGHT_DOWN;
            } else if (dir == DIR.RIGHT_DOWN && curCor.r == maxR) {
                maxR--;
                dir = DIR.RIGHT_UP;
            } else if (dir == DIR.RIGHT_UP && curCor.c == maxC) {
                maxC--;
                dir = DIR.LEFT_UP;
            }
            if (board[curCor.r][curCor.c] != ' ') {
                dir = DIR.LEFT_DOWN;
                curCor.r++;
            }

            board[curCor.r][curCor.c] = (char) ('A' + cnt % 26);
            cnt++;

            if (curCor.r == N - 1 && curCor.c == N - 1) break;

            curCor = curCor.move(dir);
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            if (i < board.length - 1) System.out.println();
        }
        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>