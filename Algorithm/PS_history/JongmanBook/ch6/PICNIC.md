# 소풍

- ch6. 무식하게 풀기
- 난이도 : 하

https://algospot.com/judge/problem/read/PICNIC

<br>

## 성공

n의 크기가 작아서 완전탐색으로 구현할 수 있다는걸 확신할 수 있었다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    int N, M;
    List<List<Integer>> friendList;
    boolean[] checked;

    int count(int idx) {
        if(idx == N) return 1;
        if(checked[idx]) return count(idx + 1);

        checked[idx] = true;
        int ret = 0;
        for (int friend : friendList.get(idx)) {
            if(checked[friend]) continue;

            checked[friend] = true;
            ret += count(idx + 1);
            checked[friend] = false;
        }
        checked[idx] = false;
        return ret;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int test = 0; test < T; test++) {

            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            friendList = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                friendList.add(new ArrayList<>());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                int student1 = Integer.parseInt(st.nextToken());
                int student2 = Integer.parseInt(st.nextToken());
                friendList.get(student1).add(student2);
                friendList.get(student2).add(student1);
            }

            checked = new boolean[N];
            sb.append(count(0)).append("\n");
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