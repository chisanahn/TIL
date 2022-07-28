# A. 구구단

## 성공

간단한 구현 문제

하지만 출력방식이 단순하진 않아서 구현하는게 낯설다보니 시간이 좀 걸렸다.

<details><summary>소스코드</summary>

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            if (s < 2 || s > 9 || e < 2 || e > 9) {
                System.out.println("INPUT ERROR!");
                continue;
            }

            StringBuilder[] sbs = new StringBuilder[9];
            for (int i = 0; i < 9; i++) {
                sbs[i] = new StringBuilder();
            }

            while (true) {
                for (int i = 1; i <= 9; i++) {
                    sbs[i - 1].append(String.format("%d * %d = %2d", s, i, s * i));
                }

                if (s == e) break;
                for (StringBuilder sb : sbs) {
                    sb.append(" ".repeat(3));
                }

                if (s < e) s++;
                else s--;
            }

            for (StringBuilder sb : sbs) {
                System.out.println(sb.toString());
            }
            break;
        }

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>