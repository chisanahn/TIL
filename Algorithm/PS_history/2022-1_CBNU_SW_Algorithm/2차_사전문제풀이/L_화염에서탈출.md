# Problem L - 화염에서탈출(SLIKAR)

<br>

## 성공. 약26분

그래프 탐색 응용 문제. 재밌었다

매 시간마다 불이 옮겨붙는 위치를 탐색하고, 용사가 이동할 수 있는 위치를 탐색해 가는 식으로 구현했다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    enum DIR {UP, RIGHT, DOWN, LEFT}

    static class Cor {

        public final int[] dr = {-1, 0, 1, 0};
        public final int[] dc = {0, 1, 0, -1};

        public int r, c;

        public Cor(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public Cor go(DIR dir) {
            int r = this.r + dr[dir.ordinal()];
            int c = this.c + dc[dir.ordinal()];
            return new Cor(r, c);
        }
    }

    int sizeOfRow, sizeOfCol;
    char[][] map;
    boolean[][] isVisited;

    int bfs(Queue<Cor> humans, Queue<Cor> fires, int time) {
        if(humans.isEmpty()) return -1;

        Queue<Cor> nextFires = new LinkedList<>();
        while (!fires.isEmpty()) {
            Cor cur = fires.poll();

            for (DIR dir : DIR.values()) {
                Cor next = cur.go(dir);

                if(isOutside(next)) continue;
                if(map[next.r][next.c] != '.' && map[next.r][next.c] != 'S') continue;

                map[next.r][next.c] = '*';
                nextFires.add(next);
            }
        }

        Queue<Cor> nextHumans = new LinkedList<>();
        while (!humans.isEmpty()) {
            Cor cur = humans.poll();

            for (DIR dir : DIR.values()) {
                Cor next = cur.go(dir);

                if(isOutside(next)) continue;
                if(map[next.r][next.c] == 'D') return time + 1;
                if(map[next.r][next.c] != '.') continue;
                if(isVisited[next.r][next.c]) continue;

                isVisited[next.r][next.c] = true;
                nextHumans.add(next);
            }
        }

        return bfs(nextHumans, nextFires, time + 1);
    }

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.r >= sizeOfRow || cor.c < 0 || cor.c >= sizeOfCol;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        sizeOfRow = Integer.parseInt(st.nextToken());
        sizeOfCol = Integer.parseInt(st.nextToken());

        Queue<Cor> humans = new LinkedList<>();
        Queue<Cor> fires = new LinkedList<>();
        map = new char[sizeOfRow][sizeOfCol];
        for (int r = 0; r < sizeOfRow; r++) {
            String rows = br.readLine();
            for (int c = 0; c < sizeOfCol; c++) {
                map[r][c] = rows.charAt(c);
                if(map[r][c] == 'S') humans.add(new Cor(r, c));
                if(map[r][c] == '*') fires.add(new Cor(r, c));
            }
        }

        isVisited = new boolean[sizeOfRow][sizeOfCol];
        int answer = bfs(humans, fires, 0);
        System.out.println((answer == -1) ? "impossible" : answer);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>