# E. 숫자 고르기

## 성공



<details><summary>소스코드</summary>

```java
import java.io.*;

class Main {

    int N;
    int[] A;
    boolean[] isInGroup;
    int groupSize;

    boolean checkCycle(int start) {
        boolean[] isVisited = new boolean[N];
        int cur = start;
        while (true) {
            if(isVisited[cur]) {
                return false;
            }
            isVisited[cur] = true;
            cur = A[cur];
            if(cur == start) {
                isVisited[cur] = true;
                return true;
            }
        }
    }

    void addCycleToGroup(int start) {
        int cur = start;
        while (true) {
            isInGroup[cur] = true;
            cur = A[cur];
            groupSize++;
            if(cur == start) return;
        }
    }

    void printGroup() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if(isInGroup[i]) {
                sb.append((i+1) + "\n");
            }
        }
        System.out.println(groupSize);
        System.out.print(sb.toString());
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(br.readLine()) - 1;
        }
        isInGroup = new boolean[N];
        groupSize = 0;

        for (int i = 0; i < N; i++) {
            if(isInGroup[i]) continue;

            if (checkCycle(i)) addCycleToGroup(i);
        }
        printGroup();

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>