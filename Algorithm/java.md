# JAVA 알고리즘 문제 풀이 TIP

<br>

### `Scanner` 대신 `BufferedReader` & `StringTokenizer`

BufferedReader를 버퍼를 이용해서 입출력을 실행하기 때문에 Scanner에 비해서 실행시간이 상당히 빠르다.

> **참고**
>
> 양햄찌(jhnyang. [Java 자바 입출력] BufferedReader/BufferedWriter. 양햄찌가 만드는 세상. Published February 19, 2019. Accessed April 20, 2022. https://jhnyang.tistory.com/92

일반적인 경우 Scanner로 풀어도 문제의 성공여부에는 큰 영향이 없는데, 혹시 모르니 `BufferedReader`랑 `StringTokenizer` 사용에 익숙해지자.

```java
// 최근 풀었던 알고리즘 문제에서 BufferedReader랑 StringTokenizer 사용한 예시
public class BOJ_13460 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        String[] board = new String[N];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine();
        }
    }
}
```

<br>

### sort() 사용자 정의 comparator

```java
// 순서가 반대면 내림차순
sort((a, b) -> {
    return b - a;
});

// 순서가 그대로면 오름차순
sort((a, b) -> {
    return a - b;
});
```

<br>

## StringBuilder

String은 immutable object라서 문자열에 대한 연산을 수행할때 StringBuilder를 사용하는 것이 성능 면에서 더 좋다.

> **참고자료**
>
> 하드러너. 자바 StringBuilder 사용법 및 사용하는 이유. 하드러너. Published April 9, 2018. Accessed April 20, 2022. https://hardlearner.tistory.com/288

<br>



