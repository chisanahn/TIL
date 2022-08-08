# Problem H - 장기

<br>

## 성공

방문 여부를 queue에 넣기 전에 체크함으로써 사용되는 메모리를 줄일 수 있다.

> queue에서 꺼낼 때 방문 여부를 체크하면 런타임 에러가 발생한다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Cor {
    final int[] dr = {-1, -2, -2, -1, 1, 2, 2, 1};
    final int[] dc = {-2, -1, 1, 2, 2, 1, -1, -2};

    public int r, c, cnt;

    public Cor(int r, int c, int cnt) {
        this.r = r;
        this.c = c;
        this.cnt = cnt;
    }

    public Cor move(int dir) {
        int r = this.r + dr[dir];
        int c = this.c + dc[dir];
        return new Cor(r, c, this.cnt + 1);
    }

    public boolean equals(Cor cor) {
        return this.r == cor.r && this.c == cor.c;
    }
}

class Main {

    int R, C;
    Cor attacker, object;

    int f() {
        boolean[][] isVisited = new boolean[R][C];
        Queue<Cor> Q = new LinkedList<>();
        Q.add(attacker);
        isVisited[attacker.r][attacker.c] = true;

        while (!Q.isEmpty()) {
            Cor cur = Q.poll();
            if(cur.equals(object)) {
                return cur.cnt;
            }
            for (int dir = 0; dir < 8; dir++) {
                Cor next = cur.move(dir);
                if(isOutside(next)) continue;
                if(isVisited[next.r][next.c]) continue;
                if(next.equals(object)) return next.cnt;
                Q.add(next);
                isVisited[next.r][next.c] = true;
            }
        }
        return 0;
    }

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.r >= R || cor.c < 0 || cor.c >= C;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int r1 = Integer.parseInt(st.nextToken()) - 1;
        int c1 = Integer.parseInt(st.nextToken()) - 1;
        attacker = new Cor(r1, c1, 0);
        int r2 = Integer.parseInt(st.nextToken()) - 1;
        int c2 = Integer.parseInt(st.nextToken()) - 1;
        object = new Cor(r2, c2, 0);

        int answer = f();
        System.out.println(answer);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>