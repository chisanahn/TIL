# Problem B - 동전 자판기(下)

<br>

## 성공. 28분

500원은 100원 5개로 만들 수 있고,
100원은 50원 2개,
50원 = 10원 * 5,
10원 = 5원 * 2,
5원 = 1원 * 2

이런 식으로 금액이 높은 동전은 해당 동전보다 낮은 금액의 동전으로 나누어 떨어진다.

따라서 맨 처음, 금액이 높은 동전을 많이 사용해서 물건을 구입하고

사용된 동전 중에서 금액이 높은 동전을 금액이 낮은 동전으로 분해해가는 식으로 구현했다.

머릿속에서 정리가 잘안돼서 구현하는데 시간이 꽤 걸렸다.

<details><summary>소스코드</summary>

```java
import java.util.*;
import java.io.*;

public class Main {

    final int SORT_OF_COIN = 6;

    int productPrice;
    int[] priceOfCoins = {500, 100, 50, 10, 5, 1};
    int[] numOfCoins;
    int[] useOfCoins;

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        productPrice = Integer.parseInt(br.readLine());
        numOfCoins = new int[SORT_OF_COIN];
        useOfCoins = new int[SORT_OF_COIN];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < SORT_OF_COIN; i++) {
            numOfCoins[i] = Integer.parseInt(st.nextToken());
        }

        int leftPrice = productPrice;
        for (int coin = 0; coin < SORT_OF_COIN; coin++) {
            int use = leftPrice / priceOfCoins[coin];
            if(use > numOfCoins[coin]) use = numOfCoins[coin];

            leftPrice -= use * priceOfCoins[coin];
            numOfCoins[coin] -= use;
            useOfCoins[coin] += use;
        }

        for (int i = 1; i < SORT_OF_COIN; i++) {
            int distributePrice = useOfCoins[i - 1] * priceOfCoins[i - 1];
            if(distributePrice == 0) continue;

            int sum = 0;
            for (int coin = i; coin < SORT_OF_COIN; coin++) {
                sum += priceOfCoins[coin] * numOfCoins[coin];
            }
            sum -= sum % priceOfCoins[i - 1];

            distributePrice = Math.min(distributePrice, sum);
            useOfCoins[i - 1] -= distributePrice / priceOfCoins[i - 1];

            for (int coin = i; coin < SORT_OF_COIN; coin++) {
                int use = distributePrice / priceOfCoins[coin];
                if(use > numOfCoins[coin]) use = numOfCoins[coin];

                distributePrice -= use * priceOfCoins[coin];
                numOfCoins[coin] -= use;
                useOfCoins[coin] += use;
            }
        }

        System.out.println(Arrays.stream(useOfCoins).sum());
        Arrays.stream(useOfCoins).forEach(a -> System.out.print(a + " "));

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

</details>