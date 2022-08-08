# Problem C - N Queen

## 성공. 약 20분

한번에 성공하긴 했지만 그동안 풀어본 횟수에 비해선 푸는데 시간이 꽤 오래 걸린다.

<details><summary>소스코드</summary>

```java
import java.io.*;

public class Main {

    class Cor {
        public int r, c;

        public Cor(int r, int c) {
            this.r = r;
            this.c = c;
        }

        boolean isCrossed(Cor cor) {
            if (cor.r == this.r || cor.c == this.c) return true;
            if (Math.abs(cor.r - this.r) == Math.abs(cor.c - this.c)) return true;
            return false;
        }
    }

    int N;
    boolean[] colCheck;
    Cor[] cors;

    int f(int row) {
        if (row == N) {
            return 1;
        }

        int ret = 0;
        for (int col = 0; col < N; col++) {
            if (colCheck[col]) continue;

            Cor curCor = new Cor(row, col);
            boolean isCrossed = false;
            for (int r = 0; r < row; r++) {
                if (!cors[r].isCrossed(curCor)) continue;
                isCrossed = true;
                break;
            }
            if (isCrossed) continue;

            colCheck[col] = true;
            cors[row] = curCor;
            ret += f(row + 1);
            colCheck[col] = false;
        }
        return ret;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());
        colCheck = new boolean[N];
        cors = new Cor[N];

        int answer = f(0);
        System.out.println(answer);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>