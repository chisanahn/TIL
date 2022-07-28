# Problem H - Tutorial : 이진탐색(Binary Search-이진검색)

## 런타임 에러

<details><summary>소스코드</summary>

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    int[] A;

    int search(int q) {
        int left = 0;
        int right = A.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if(A[mid] == q) return mid;
            else if(A[mid] < q) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sizeOfA = Integer.parseInt(br.readLine());
        A = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int sizeOfQ = Integer.parseInt(br.readLine());
        int[] Q = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        StringBuilder sb = new StringBuilder();
        for (int q : Q) {
            sb.append(search(q)).append(" ");
        }
        System.out.println(sb);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>

<br>

## 성공

배열입력시에 `stream`을 사용하거나 `enhanced for 문`을 사용했더니 런타임 오류가 나는데 그 이유를 모르겠다.

> 허허

인터넷을 좀 찾아보니깐 java로 PS를 할때 메모리 제한이 빡센 경우 가끔 발생한다는 것 같다. ㄴㅇㄱ

> https://maetdori.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9B%94%EA%B0%84-%EC%BD%94%EB%93%9C-%EC%B1%8C%EB%A6%B0%EC%A7%80-%EC%8B%9C%EC%A6%8C2-%EB%AA%A8%EB%91%90-0%EC%9C%BC%EB%A1%9C-%EB%A7%8C%EB%93%A4%EA%B8%B0-JAVA

<details><summary>소스코드</summary>

```java
import java.io.*;
import java.util.*;

class Main {

    int[] A;

    int search(int q) {
        int left = 0;
        int right = A.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if(A[mid] == q) return mid;
            else if(A[mid] < q) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sizeOfA = Integer.parseInt(br.readLine());
        A = new int[sizeOfA];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < sizeOfA; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int sizeOfQ = Integer.parseInt(br.readLine());
        int[] Q = new int[sizeOfQ];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < sizeOfQ; i++) {
            Q[i] = Integer.parseInt(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < sizeOfQ; i++) {
            sb.append(search(Q[i])).append(" ");
        }
        System.out.println(sb);

        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}
```

</details>