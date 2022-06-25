# B. Make It Increasing

그리드 문제인듯

## 성공. 12분 정도 소요

```java
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    int n;
    int[] arr;

    int calcMinOperation() {
        int ret = 0;
        for (int i = arr.length - 1; i > 0; i--) {
            if(arr[i] == 0) return -1;

            while(arr[i-1] >= arr[i]) {
                arr[i-1] /= 2;
                ret++;
            }
        }
        return ret;
    }

    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numberOfTest = Integer.parseInt(br.readLine());

        for (int test = 0; test < numberOfTest; test++) {
            n = Integer.parseInt(br.readLine());
            arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            System.out.println(calcMinOperation());
        }
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
```

