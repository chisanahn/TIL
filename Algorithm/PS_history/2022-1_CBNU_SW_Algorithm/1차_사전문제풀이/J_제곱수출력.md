# Problem J - 제곱수 출력

## 성공. 약 10분

예전에 비슷한 문제를 풀어본 적이 있어서 헤매는 일 없이 빠르게 구현했다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    final int MOD = 20091024;

    long modPow(int x, int y) {
        if (y == 0) return 1;
        long ret = modPow(x, y / 2) % MOD;
        ret = ret * ret % MOD;
        if (y % 2 == 1) ret = (ret * x) % MOD;
        return ret % MOD;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());

        System.out.println(modPow(X, Y));

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>