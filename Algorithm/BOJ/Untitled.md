# [백준] 카드 게임

Gold 3

https://www.acmicpc.net/problem/11062

<br>

작년 여름방학때 진행했던 알고리즘 특강에서 강사님께서 만들어주신 백준 문제집으로 DP 연습하는 중

## 성공 (아마 1시간 정도?)

```
dp[startIndex][endIndex] = 현재 사람이 얻을 수 있는 최종점수의 최댓값
```

표를 만들어서 그려보니깐 점화식을 생각해내는데 많은 도움이 되었다.

> 1 2 5 2 예제의 경우 다음과 같이 dp 배열이 저장된다.

|  1   |  2   |  6   |  6   |
| :--: | :--: | :--: | :--: |
|  X   |  2   |  5   |  4   |
|  X   |  X   |  5   |  5   |
|  X   |  X   |  X   |  2   |

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // dp[startIndex][endIndex] = 현재 사람이 얻을 수 있는 점수의 최대값.

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            int cardNumber = Integer.parseInt(br.readLine());
            int[] cards = new int[cardNumber];
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < cardNumber; i++) {
                cards[i] = Integer.parseInt(st.nextToken());
            }

            int[][] dp = new int[cardNumber][cardNumber];
            int[][] sum = new int[cardNumber][cardNumber];
            for (int[] d : dp) Arrays.fill(d, -1);
            for (int i = 0; i < cardNumber; i++) {
                // base case
                dp[i][i] = cards[i];
                sum[i][i] = cards[i];
            }

            for (int i = 0; i < cardNumber; i++) {
                for (int j = i + 1; j < cardNumber; j++) {
                    sum[i][j] = sum[i][j - 1] + cards[j];
                }
            }

            for (int len = 1; len < cardNumber; len++) {
                for (int startIndex = 0; startIndex + len < cardNumber; startIndex++) {
                    int endIndex = startIndex + len;
                    dp[startIndex][endIndex] = sum[startIndex][endIndex] - Math.min(dp[startIndex][endIndex - 1], dp[startIndex + 1][endIndex]);
                }
            }

            System.out.println(dp[0][cardNumber - 1]);
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

