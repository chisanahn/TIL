# Problem I - 색종이 만들기(영역구분)

## 성공. 27분

좌표를 어떻게 설정하지 고민하느라 시간이 좀 걸렸다.

> 그나마 그림을 그려보면서 헤매는 일 없이 한번에 구현했다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    int N;
    int[][] arr;
    int[][] sum;

    int white, blue;

    void f(int y1, int x1, int y2, int x2) {
        int squareSize = (x2 - x1 + 1) * (y2 - y1 + 1);
        int curSum = sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1 - 1][x1 - 1];

        if(curSum == 0) white++;
        else if(curSum == squareSize) blue++;
        else {
            int y3 = (y1 + y2) / 2;
            int x3 = (x1 + x2) / 2;

            f(y1, x1, y3, x3);
            f(y1, x3 + 1, y3, x2);
            f(y3 + 1, x1, y2, x3);
            f(y3 + 1, x3 + 1, y2, x2);
        }
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        sum = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i - 1][j - 1];
            }
        }

        white = 0;
        blue = 0;
        f(1, 1, N, N);

        System.out.println(white);
        System.out.println(blue);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>