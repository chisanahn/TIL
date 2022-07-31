# 게임판 덮기

- ch6. 무식하게 풀기
- 난이도 : 하

<br>

## 실패

각 위치별로 4개의 경우의 수를 고려해보면 최대 5^50

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.StringTokenizer;

class Main {

    final int[] dy = {0, -1, 0, 1};
    final int[] dx = {-1, 0, 1, 0};

    int H, W;
    char[][] board;

    boolean isOutside(int y, int x) {
        return y < 0 || y >= H || x < 0 || x >= W;
    }

    int f(int y, int x, int whiteCnt) {
        if (whiteCnt % 3 != 0) return 0;
        if (whiteCnt == 0) return 1;
        if (isOutside(y, x)) return 0;

        int nextX = x + 1;
        int nextY = y;
        if (nextX == W) {
            nextX = 0;
            nextY++;
        }

        int ret = f(nextY, nextX, whiteCnt);

        if (board[y][x] == '#') return ret;

        for (int dir = 0; dir < 4; dir++) {
            int y2 = y + dy[dir];
            int x2 = x + dx[dir];
            int y3 = y + dy[(dir + 1) % 4];
            int x3 = x + dx[(dir + 1) % 4];

            if (isOutside(y2, x2) || isOutside(y3, x3)) continue;
            if (board[y2][x2] == '#' || board[y3][x3] == '#') continue;

            board[y][x] = '#';
            board[y2][x2] = '#';
            board[y3][x3] = '#';
            ret += f(nextY, nextX, whiteCnt - 3);
            board[y][x] = '.';
            board[y2][x2] = '.';
            board[y3][x3] = '.';
        }
        return ret;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int test = 0; test < T; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            board = new char[H][W];
            int whiteCnt = 0;
            for (int i = 0; i < H; i++) {
                String rows = br.readLine();
                for (int j = 0; j < W; j++) {
                    board[i][j] = rows.charAt(j);
                    if(board[i][j] == '.') whiteCnt++;
                }
            }

            if(whiteCnt % 3 != 0) sb.append("0\n");
            else {
                int answer = f(0, 0, whiteCnt);
                sb.append(answer).append("\n");
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

시간초과 없이 해결할 방법이 도저히 생각나지 않는다.

## 성공.

새로운 시각이 필요할 것 같아서 포기하고 있다가 책에서 일반적인 완전탐색으로 해결할 수 있다는 얘기를 보고 재도전해봤다.

원래 구현의 편의성을 위해서 탐색점을 기준으로 L자 모형을 4방향으로 회전시키면서 탐색하고, 해당 탐색점에 블록을 배치하지 않는 경우의 수까지 고려하는 식으로 구현했는데 이럴 경우, 고려하는 경우의 수가 최대 약 5^16으로 시간초과가 발생하게 된다.

> 로컬에서 돌려봤을때에도 마지막 예제 실행이 끝나지 않는걸 보면 구현 자체가 잘못된 것 같기도 하다.

하지만 도착 지점을 포함해서 블록을 무조건 놓는 식으로 탐색 방식을 변경해서 구현할 경우, 최대 경우의 수가 약 4^16으로 주어진 시간안에 해결할 수 있게 된다.

> 하얀색 블록이 최대 50개, 즉 블록을 최대 16개 배치해야하고, 블록마다 놓는 방식이 4가지므로 약 `4^16`

<details><summary>소스코드</summary>

```javaimport java.io.*;
import java.util.StringTokenizer;

class Main {

    int[][] dy = {{1, 1}, {1, 1}, {0, 1}, {0, 1}};
    int[][] dx = {{-1, 0}, {0, 1}, {1, 1}, {1, 0}};

    int H, W;
    char[][] board;

    boolean isOutside(int y, int x) {
        return y < 0 || y >= H || x < 0 || x >= W;
    }

    int f(int y, int x, int whiteCnt) {
        if (whiteCnt == 0) return 1;
        if (isOutside(y, x)) return 0;

        int nextX = x + 1;
        int nextY = y;
        if (nextX == W) {
            nextX = 0;
            nextY++;
        }

        if (board[y][x] == '#') return f(nextY, nextX, whiteCnt);

        board[y][x] = '#';
        int ret = 0;
        for (int dir = 0; dir < 4; dir++) {
            int y2 = y + dy[dir][0];
            int x2 = x + dx[dir][0];
            int y3 = y + dy[dir][1];
            int x3 = x + dx[dir][1];

            if (isOutside(y2, x2) || isOutside(y3, x3)) continue;
            if (board[y2][x2] == '#' || board[y3][x3] == '#') continue;

            board[y2][x2] = '#';
            board[y3][x3] = '#';
            ret += f(nextY, nextX, whiteCnt - 3);
            board[y2][x2] = '.';
            board[y3][x3] = '.';
        }
        board[y][x] = '.';
        return ret;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int test = 0; test < T; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            board = new char[H][W];
            int whiteCnt = 0;
            for (int i = 0; i < H; i++) {
                String rows = br.readLine();
                for (int j = 0; j < W; j++) {
                    board[i][j] = rows.charAt(j);
                    if(board[i][j] == '.') whiteCnt++;
                }
            }

            if(whiteCnt % 3 != 0) sb.append("0\n");
            else {
                int answer = f(0, 0, whiteCnt);
                sb.append(answer).append("\n");
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