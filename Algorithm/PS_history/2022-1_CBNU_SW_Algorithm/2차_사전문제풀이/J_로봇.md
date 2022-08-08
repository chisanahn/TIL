# Problem J - 로봇

<br>

## 80점

머리가 잘 안 돌아간다

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    enum DIR {LEFT, UP, RIGHT, DOWN}

    class Cor {
        public final int[] dr = {0, -1, 0, 1};
        public final int[] dc = {-1, 0, 1, 0};

        public int r, c;
        public DIR dir;
        public int orderCnt;

        public Cor(int r, int c, int dir) {
            this.r = r;
            this.c = c;
            switch (dir) {
                case 1:
                    this.dir = DIR.RIGHT;
                    break;
                case 2:
                    this.dir = DIR.LEFT;
                    break;
                case 3:
                    this.dir = DIR.DOWN;
                    break;
                case 4:
                    this.dir = DIR.UP;
                    break;
            }
            orderCnt = 0;
        }

        private Cor(int r, int c, DIR dir, int orderCnt) {
            this.r = r;
            this.c = c;
            this.dir = dir;
            this.orderCnt = orderCnt;
        }

        public Cor turnRight() {
            DIR dir = DIR.values()[(this.dir.ordinal() + 1) % 4];
            return new Cor(this.r, this.c, dir, orderCnt + 1);
        }

        public Cor turnLeft() {
            DIR dir = DIR.values()[(this.dir.ordinal() + 4 - 1) % 4];
            return new Cor(this.r, this.c, dir, orderCnt + 1);
        }

        public Cor move(int dist) {
            int r = this.r + dr[this.dir.ordinal()] * dist;
            int c = this.c + dc[this.dir.ordinal()] * dist;
            return new Cor(r, c, this.dir, orderCnt + 1);
        }

        public boolean equals(Cor cor) {
            return this.r == cor.r && this.c == cor.c && this.dir == cor.dir;
        }
    }

    int rSize, cSize;
    boolean[][] isRail;
    boolean[][] isVisited;
    Cor dest;

    int bfs(Cor startCor) {
        int minOrderCnt = 987654321;

        Queue<Cor> Q = new LinkedList<>();
        Q.add(startCor);
        while (!Q.isEmpty()) {
            Cor cor = Q.poll();
            if (cor.equals(dest)) {
                minOrderCnt = Math.min(minOrderCnt, cor.orderCnt);
                continue;
            }
            if (cor.turnLeft().equals(dest)) {
                minOrderCnt = Math.min(minOrderCnt, cor.orderCnt + 1);
                continue;
            }
            if (cor.turnRight().equals(dest)) {
                minOrderCnt = Math.min(minOrderCnt, cor.orderCnt + 1);
                continue;
            }
            if (cor.turnRight().turnRight().equals(dest)) {
                minOrderCnt = Math.min(minOrderCnt, cor.orderCnt + 2);
                continue;
            }

            for (int dist = 1; dist <= 3; dist++) {
                Cor nextCor = cor.move(dist);
                if (isOutside(nextCor) || !isRail[nextCor.r][nextCor.c]) break;
                if (isVisited[nextCor.r][nextCor.c]) continue;

                isVisited[nextCor.r][nextCor.c] = true;
                Q.add(nextCor);
            }
            for (int dist = 1; dist <= 3; dist++) {
                Cor nextCor = cor.turnLeft().move(dist);
                if (isOutside(nextCor) || !isRail[nextCor.r][nextCor.c]) break;
                if (isVisited[nextCor.r][nextCor.c]) continue;

                isVisited[nextCor.r][nextCor.c] = true;
                Q.add(nextCor);
            }
            for (int dist = 1; dist <= 3; dist++) {
                Cor nextCor = cor.turnRight().move(dist);
                if (isOutside(nextCor) || !isRail[nextCor.r][nextCor.c]) break;
                if (isVisited[nextCor.r][nextCor.c]) continue;

                isVisited[nextCor.r][nextCor.c] = true;
                Q.add(nextCor);
            }
            for (int dist = 1; dist <= 3; dist++) {
                Cor nextCor = cor.turnLeft().turnLeft().move(dist);
                if (isOutside(nextCor) || !isRail[nextCor.r][nextCor.c]) break;
                if (isVisited[nextCor.r][nextCor.c]) continue;

                isVisited[nextCor.r][nextCor.c] = true;
                Q.add(nextCor);
            }
        }
        return minOrderCnt;
    }

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.r >= rSize || cor.c < 0 || cor.c >= cSize;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        rSize = Integer.parseInt(st.nextToken());
        cSize = Integer.parseInt(st.nextToken());
        isRail = new boolean[rSize][cSize];
        for (int i = 0; i < rSize; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<cSize; j++){
                isRail[i][j] = Integer.parseInt(st.nextToken()) == 0;
            }
        }

        int r, c, dir;
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken()) - 1;
        c = Integer.parseInt(st.nextToken()) - 1;
        dir = Integer.parseInt(st.nextToken());
        Cor startCor = new Cor(r, c, dir);
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken()) - 1;
        c = Integer.parseInt(st.nextToken()) - 1;
        dir = Integer.parseInt(st.nextToken());
        dest = new Cor(r, c, dir);

        isVisited = new boolean[rSize][cSize];
        int answer = bfs(startCor);
        System.out.println(answer);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>

<br>

잘자고 새로운 마음으로 재도전

## 성공. 약 30분

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    enum DIR {NORTH, EAST, SOUTH, WEST}

    final int[] rotates = {-1, 1};

    static class Cor {
        public final int[] dr = {-1, 0, 1, 0};
        public final int[] dc = {0, 1, 0, -1};

        public int r, c;
        public DIR dir;
        public int orderCnt;

        public Cor(int r, int c, DIR dir, int orderCnt) {
            this.r = r;
            this.c = c;
            this.dir = dir;
            this.orderCnt = orderCnt;
        }

        public Cor(int r, int c, int dir) {
            this.r = r;
            this.c = c;
            switch (dir) {
                case 1:
                    this.dir = DIR.EAST;
                    break;
                case 2:
                    this.dir = DIR.WEST;
                    break;
                case 3:
                    this.dir = DIR.SOUTH;
                    break;
                case 4:
                    this.dir = DIR.NORTH;
                    break;
            }
            this.orderCnt = 0;
        }

        public Cor move(int dist) {
            int r = this.r + dr[dir.ordinal()] * dist;
            int c = this.c + dc[dir.ordinal()] * dist;
            return new Cor(r, c, dir, orderCnt + 1);
        }

        public Cor turn(int rotate) {
            DIR dir = DIR.values()[(this.dir.ordinal() + 4 + rotate) % 4];
            return new Cor(r, c, dir, orderCnt + 1);
        }

        public boolean equals(Cor cor) {
            return cor.r == this.r && cor.c == this.c && cor.dir == this.dir;
        }
    }

    int sizeOfRow, sizeOfCol;
    boolean[][] isRail;
    Cor dest;
    boolean[][][] isVisited;

    int bfs(Cor start) {
        isVisited = new boolean[sizeOfRow][sizeOfCol][DIR.values().length];

        Queue<Cor> Q = new LinkedList<>();
        Q.add(start);
        visit(start);

        while (!Q.isEmpty()) {
            Cor cor = Q.poll();
            if(cor.equals(dest)) return cor.orderCnt;

            for (int dist = 1; dist <= 3; dist++) {
                Cor nextCor = cor.move(dist);

                if(isOutside(nextCor) || !isRail[nextCor.r][nextCor.c]) break;
                if(isVisited(nextCor)) continue;

                visit(nextCor);
                Q.add(nextCor);
            }

            for (int rotate : rotates) {
                Cor nextCor = cor.turn(rotate);
                if(isVisited(nextCor)) continue;

                visit(nextCor);
                Q.add(nextCor);
            }
        }

        return -1;
    }

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.r >= sizeOfRow || cor.c < 0 || cor.c >= sizeOfCol;
    }

    boolean isVisited(Cor cor) {
        return isVisited[cor.r][cor.c][cor.dir.ordinal()];
    }

    void visit(Cor cor) {
        isVisited[cor.r][cor.c][cor.dir.ordinal()] = true;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        sizeOfRow = Integer.parseInt(st.nextToken());
        sizeOfCol = Integer.parseInt(st.nextToken());

        isRail = new boolean[sizeOfRow][sizeOfCol];
        for (int r = 0; r < sizeOfRow; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < sizeOfCol; c++) {
                isRail[r][c] = Integer.parseInt(st.nextToken()) == 0;
            }
        }

        st = new StringTokenizer(br.readLine());
        Cor start = new Cor(
                Integer.parseInt(st.nextToken()) - 1,
                Integer.parseInt(st.nextToken()) - 1,
                Integer.parseInt(st.nextToken()));

        st = new StringTokenizer(br.readLine());
        dest = new Cor(
                Integer.parseInt(st.nextToken()) - 1,
                Integer.parseInt(st.nextToken()) - 1,
                Integer.parseInt(st.nextToken()));

        int answer = bfs(start);
        System.out.println(answer);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>