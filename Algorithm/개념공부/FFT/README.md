# 고속 푸리에 변환(Fast Fourier Transform)

https://algospot.com/forum/read/1923/

종만북을 공부하던 중, FANMEETING 문제를 풀어보다가 큰 수의 곱셈을 할 때 카라츠바 알고리즘을 사용하면 `O(n^lg3)` 시간복잡도로 큰 수의 곱셈을 계산할 수 있지만 아무래도 `O(n^2)`과 드라마틱한 차이가 없다보니 c++이 아닌 java를 사용할 경우 통과되지 않는다고 한다.

하지만 FFT를 사용하면 `O(nlgn)`으로 큰 수의 곱셈을 수행할 수 있다는 글을 보고 해당 개념을 공부하게 되었다.

https://m.blog.naver.com/PostView.naver?blogId=kks227&logNo=221633584963&proxyReferer=

위의 블로그에 정말 잘 설명되어 있지만 아무래도 생소한 개념이라 초반에 이해하는데 어려움이 있었다.

<br>

#### FFT를 이용해서 두 다항식의 곱 `f(x)` * `g(x)` = `h(x)`을 빠르게 구하는 과정

1. `f(x)`, `g(x)`의 차수보다 큰 2의 제곱수를 n으로 둔다.

2. `f(x)`, `g(x)`에 대해서 서로 다른 n개의 `k, f(k), g(k)` 쌍을 구한다.

    > 이때 해당 쌍들을 빠르게 구하기 위해서 `n-th root of unity`의 특징과 `FFT`를 이용한다.

3. 2번 과정에서 얻은 쌍을 바탕으로 `k, h(k)` 쌍을 구한다.

    > `k, f(k) * g(k)`

2. 3번 과정에서 얻은 n개의 `k, h(k)`에 `IDFT`를 적용해서 다항식 `h(x)`를 얻어낸다.

    > 이때도 빠른 계산을 위해 FFT를 이용한다.

<br>

## FFT 예시

`n = 8`인 경우 예시

```
x0 = 1
x4 = -1

f(x0) = feven(x0^2) + x0 * fodd(x0^2)
f(x4) = feven(x4^2) + x4 * fodd(x4^2)
```

```
f(x4) = f(-x0) = feven(x0^2) - x0 * fodd(x0^2)
```

따라서 `f(x0)`과 `f(x4)` 모두 `feven(x0^2)`, `fodd(x0^2)`로부터 값을 구해낼 수 있다.

> `x0`과 `x4` 뿐만 아니라 모든 `x_k = - x_(k+n/2)`이므로
>
> `f(x_k)`과 `f(x_(k+n/2))` 모두 `feven(x_k^2)`, `fodd(x_k^2)`로부터 값을 구해낼 수 있다.

<br>

위의 예제에서 알 수 있듯이, `n = 8`인 경우를 예로 들면

`f(x0)` ~ `f(x7)`을 `feven(x0^2)`, `fodd(x0^2)`, ..., `feven(x3^2)`, `fodd(x3^2)` 값만을 가지고 구할 수 있다는 것을 알 수 있다.

그리고 `x0^2`, .. , `x3^2` 값을 나열해보면 `n = 4` 일때의 복소수들이다.

이런식으로 `n = 8` 인 경우에는 `n = 4` -> `n = 2` -> `n = 1` 이런 식으로 총 `log n` 번 해당 과정을 반복하게 되고 매 과정에서 `O(n)`이 걸리기 때문에 총 시간복잡도는 `O(nlgn)`

> 크기가 `f()`의 1/2인 `feven()`, `fodd()` 2개의 함수로 나뉘기 때문에 각 과정에서의 시간복잡도는 `O(n)`으로 일정하다.

<br>

## 복소수 구현

JAVA는 따로 지원해주지 않아서 직접 구현해서 사용해야 한다.

<br>

## 관련 문제 풀이

- [백준 - 큰 수 곱셈](../../PS_history/BOJ/BOJ_13277.md)

- [종만북 - FANMEETING](../../PS_history/JongmanBook/ch7/FANMEETING.md)