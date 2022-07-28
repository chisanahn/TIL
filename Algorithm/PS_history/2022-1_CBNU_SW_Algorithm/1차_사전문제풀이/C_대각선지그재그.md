# C. 대각선 지그재그

## 성공. 22분

중간부터 좌표 이동 방식이 한번 더 변경되는 점을 놓쳤다가 수정하느라 시간이 좀 걸렸다.

<details><summary>소스코드</summary>

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Cor {
    private final int[] dr = {1, -1};
    private final int[] dc = {-1, 1};

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

    int N;
    int[][] board;

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.c < 0 || cor.r >= N || cor.c >= N;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        Cor cor = new Cor(0, 0);
        int dir = 0;
        for (int i = 1; i <= N * N; i++) {
            board[cor.r][cor.c] = i;
            Cor nextCor = cor.move(dir);
            if (isOutside(nextCor)) {
                if (i < N * N / 2) {
                    if (dir == 0) cor.r++;
                    else cor.c++;
                } else {
                    if (dir == 0) cor.c++;
                    else cor.r++;
                }
                dir = (dir + 1) % 2;
            } else cor = nextCor;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>