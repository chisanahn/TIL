# Problem D - 해밀턴 순환회로

## 성공. 20분 정도

복잡한 그래프 문제인줄 알았는데 N이 최대 13으로, 단순 완탐을 통해서 해결되는 문제다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    final int INF = 987654321;

    int N;
    int[][] expense;

    int minPrice = INF;
    boolean[] visited;
    List<Integer> path;

    void dfs(int curLocation, int visitCnt, int price) {
        if(price >= minPrice) return;
        if(visitCnt == N) {
            if(expense[curLocation][0] != 0) {
                minPrice = Math.min(minPrice, price + expense[curLocation][0]);
            }
            return;
        }

        for (int nextLocation = 0; nextLocation < N; nextLocation++) {
            if(expense[curLocation][nextLocation] == 0) continue;
            if(visited[nextLocation]) continue;

            visited[nextLocation] = true;
            path.add(nextLocation);
            dfs(nextLocation, visitCnt + 1, price + expense[curLocation][nextLocation]);
            visited[nextLocation] = false;
            path.remove(path.size() - 1);
        }
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine().trim());
        expense = new int[N][N];
        for (int i = 0; i < N; i++) {
            expense[i] = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        visited = new boolean[N];

        visited[0] = true;
        path = new ArrayList<>();
        path.add(0);
        dfs(0, 1, 0);

        System.out.println((minPrice == INF) ? 0 : minPrice);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>