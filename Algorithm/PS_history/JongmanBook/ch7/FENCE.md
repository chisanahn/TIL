# 울타리 잘라내기

- ch7. 분할 정복
- 난이도 : 중

https://algospot.com/judge/problem/read/FENCE

<br>

## 실패 - 시간초과

가운데 부분 포함 넓이를 계산할때 left 부터 right 범위를 고려하면 시간복잡도가 O(nlgn)인데,
실수로  전체 범위를 계산하면서 시간초과가 발생했었다.

<br>

## 실패

나름 분할정복으로 잘 풀었다고 생각했는데 오답이 나왔다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    int N;
    int[] H;

    int f(int L, int R) {
        if (L == R) return H[L];

        int mid = (L + R) / 2;
        int ret = f(L, mid);
        ret = Math.max(ret, f(mid + 1, R));

        int minH = Math.min(H[mid], H[mid + 1]);
        int size = 2;
        for (int i = mid - 1; i >= L; i--) {
            if (minH * size > Math.min(minH, H[i]) * (size + 1)) break;
            minH = Math.min(minH, H[i]);
            size++;
        }
        for (int i = mid + 2; i <= R; i++) {
            if (minH * size > Math.min(minH, H[i]) * (size + 1)) break;
            minH = Math.min(minH, H[i]);
            size++;
        }
        ret = Math.max(ret, minH * size);
        return ret;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {

            N = Integer.parseInt(br.readLine());
            H = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                H[i] = Integer.parseInt(st.nextToken());
            }

            int answer = f(0, N - 1);
            sb.append(answer).append("\n");
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

<br>

댓글을 보고 반례를 하나 찾았다.

```
1
5
1 2 3 4 5

답: 9
출력: 8
```

중간 부분을 탐색할때 순서가 중요하지 않을 줄 알았는데 중요하다.

<br>

반례를 하나 더 찾았다.

```
1
7
1 2 3 4 3 2 1

답: 10
출력: 9
```

`3432`는 `343`보다 작지만, `23432`는 `343`보다 크다

결국 모든 경우의 수를 고려해줘야할 것 같다.

<br>

## 결국 책보고 풀었다.

너무 복잡하게 생각했던 것 같다.

매번 큰 수를 고르면서 끝까지 탐색하면 된다.

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    int N;
    int[] H;

    int f(int L, int R) {
        if (L == R) return H[L];

        int mid = (L + R) / 2;
        int ret = f(L, mid);
        ret = Math.max(ret, f(mid + 1, R));

        int minH = Math.min(H[mid], H[mid + 1]);
        int size = 2;
        int left = mid - 1;
        int right = mid + 2;
        ret = Math.max(ret, minH * size);
        while (true) {
            if (right <= R && (left < L || H[left] < H[right])) {
                minH = Math.min(minH, H[right]);
                size++;
                right++;
            } else if (left >= L) {
                minH = Math.min(minH, H[left]);
                size++;
                left--;
            } else break;
            ret = Math.max(ret, minH * size);
        }
        return ret;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {

            N = Integer.parseInt(br.readLine());
            H = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                H[i] = Integer.parseInt(st.nextToken());
            }

            int answer = f(0, N - 1);
            sb.append(answer).append("\n");
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