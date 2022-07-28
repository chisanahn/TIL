# G. 로또

## 성공. 13분

재귀함수를 통해서 조합을 구현했는데 숫자가 2자리 수인 경우를 생각하지 못해서 한번 틀렸다.

```
void recur(int i, String combination)
```

<details><summary> 소스코드 </summary>

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    int K;
    int[] S;

    void recur(int i, int cnt, String combination) {
        if(cnt == 6) {
            System.out.println(combination);
            return;
        }
        if(i >= K) return;

        recur(i + 1, cnt + 1,combination + S[i] + " ");
        recur(i + 1, cnt, combination);
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());
        S = new int[K];
        for (int i = 0; i < K; i++) {
            S[i] = Integer.parseInt(st.nextToken());
        }

        recur(0, 0, "");

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>