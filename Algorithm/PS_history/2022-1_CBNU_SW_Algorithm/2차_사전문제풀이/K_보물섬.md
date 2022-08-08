# Problem K - 보물섬

<br>

## 성공. 13분 정도

입력의 크기가 작아서 모든 땅에서 bfs를 통해 최대거리를 탐색해보면 된다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    enum DIR {UP, RIGHT, DOWN, LEFT}

    static class Cor {

        public final int[] dr = {-1, 0, 1, 0};
        public final int[] dc = {0, 1, 0, -1};

        public int r, c, dist;

        public Cor(int r, int c, int dist) {
            this.r = r;
            this.c = c;
            this.dist = dist;
        }

        public Cor move(DIR dir) {
            int r = this.r + dr[dir.ordinal()];
            int c = this.c + dc[dir.ordinal()];
            return new Cor(r, c, dist + 1);
        }
    }

    int sizeOfRow, sizeOfCol;
    char[][] map;
    boolean[][] isVisited;

    int calDist(Cor start) {
        int maxDist = 0;

        Queue<Cor> Q = new LinkedList<>();
        Q.add(start);
        isVisited = new boolean[sizeOfRow][sizeOfCol];
        isVisited[start.r][start.c] = true;

        while (!Q.isEmpty()) {
            Cor cur = Q.poll();
            maxDist = Math.max(maxDist, cur.dist);

            for (DIR dir : DIR.values()) {
                Cor next = cur.move(dir);

                if (next.r < 0 || next.r >= sizeOfRow || next.c < 0 || next.c >= sizeOfCol) continue;
                if (isVisited[next.r][next.c]) continue;
                if (map[next.r][next.c] != 'L') continue;

                isVisited[next.r][next.c] = true;
                Q.add(next);
            }
        }
        return maxDist;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        sizeOfRow = Integer.parseInt(st.nextToken());
        sizeOfCol = Integer.parseInt(st.nextToken());

        map = new char[sizeOfRow][sizeOfCol];
        for (int r = 0; r < sizeOfRow; r++) {
            map[r] = br.readLine().toCharArray();
        }

        int answer = 0;
        for (int r = 0; r < sizeOfRow; r++) {
            for (int c = 0; c < sizeOfCol; c++) {
                if (map[r][c] != 'L') continue;
                answer = Math.max(answer, calDist(new Cor(r, c, 0)));
            }
        }
        System.out.println(answer);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>