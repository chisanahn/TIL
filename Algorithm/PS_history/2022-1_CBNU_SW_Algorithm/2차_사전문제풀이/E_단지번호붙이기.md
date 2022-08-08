# Problem E - 단지번호붙이기

## 성공. 21분

중간에 구현 실수를 해서 디버깅하느라 불필요한 시간이 소모되었고,

결과를 오름차순 정렬해야하는걸 깜빡해서 한번 틀렸다.

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

    int N;
    int[][] map;
    boolean[][] isVisited;

    List<Integer> group;

    int dfs(Cor cor) {
        isVisited[cor.r][cor.c] = true;

        int ret = 1;
        for (int dir = 0; dir < 4; dir++) {
            Cor nextCor = cor.move(dir);
            if(isOutside(nextCor)) continue;
            if(isVisited(nextCor)) continue;
            if(map[nextCor.r][nextCor.c] != 1) continue;

            ret += dfs(nextCor);
        }
        return ret;
    }

    boolean isOutside(Cor cor) {
        return cor.r < 0 || cor.r >= N || cor.c < 0 || cor.c >= N;
    }

    boolean isVisited(Cor cor) {
        return isVisited[cor.r][cor.c];
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for (int i = 0; i < N; i++) {
            map[i] = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();
        }
        isVisited = new boolean[N][N];

        group = new ArrayList<>();
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if(map[r][c] != 1) continue;
                if(isVisited[r][c]) continue;

                group.add(dfs(new Cor(r, c)));
            }
        }

        System.out.println(group.size());
        group.forEach(System.out::println);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>