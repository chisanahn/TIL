# 2021 SW개발 능력향상 프로그램

ICPC 대회 준비

---

### 1주차 강의 - 정수론

이론 강의를 진행하기전 [Codeforces Round #713 (Div. 3)](https://codeforces.com/group/sPvRZDMiQz/contest/1512)를 1h30m 동안 풀어보는 시간을 가졌는데 7문제 중 3문제를 풀었다.

#### 소인수분해, 에라토스테네스의 체

- O(logn) 약수 찾기

> 어떤 정수 n, a, b에 대해서
> n = a\*b, a<=b이면 1<=a<=logn이 성립

> [BOJ 14563 완전수](https://www.acmicpc.net/problem/14563)

```c++
int sum=1;
for(int i=2; i*i<=x; i++) {
  if(x%i==0) {
    sum += i;
    if(i*i != x) {
      sum += x/i;
    }
  }
}
```

> 이렇게 코드를 작성하면 실패로 결과가 나온다.
> i=1부터 시작하고 마지막에 sum -= x를 해주는 대신 1은 모든 수의 약수니깐 sum에 1을 미리 넣어주고 i=2부터 시작하면 결과적으로 동일해야된다고 생각하는데 왜 실패가 나오는지 이유를 잘 모르겠다.

- 소수 판별

> [BOJ 1978 소수찾기](https://www.acmicpc.net/problem/1978)

> 약수 찾기를 응용해서 2부터 log n까지만 고려해주면 된다. (약수는 쌍을 이루는데 그 중 한 수는 log n보다 무조건 작거나 같다.)

- 소인수분해

> [BOJ 11653 소인수분해](https://www.acmicpc.net/problem/11653)

> 마지막에 남은 수를 출력하기 위해서 i<=n까지 for문을 돌렸었는데 i\*i<=n으로 하다가 맨 마지막에 남은 수가 1보다 크면 소인수로 간주하도록 코드를 짜면 실행시간을 단축시킬 수 있다.

> 소인수가 하나 나오면 N/=i를 하고 다시 int i=2부터 다시 시작할 수도 있지만 동일한 소인수가 여러개 있는 경우를 생각해서 while(N%i==0)으로 동일한 소인수인 경우를 한번에 처리하고 가는것이 실행시간을 단축시키는데 도움이 될 것 같다.

```c++
int N;
cin >> N;
for (int i = 2; i*i <= N; i++) {
  while (N % i == 0) {
    cout << i << "\n";
    N /= i;
  }
}
if(N>1) cout << N << "\n";
```

- 에라토스테네스의 체

> 2이상 n 이하인 모든 소수를 구하는 알고리즘  
> 수행 시간 O(n log log n)  
> O(n)으로 구현: https://cp-algorithms.com/algebra/prime-sieve-linear.html

> [BOJ 1929 소수 구하기](https://www.acmicpc.net/problem/1929)

> 수를 지워나갈때 배수의 제곱부터 시작하면된다.  
> 예를 들어 7의 배수를 지워나갈때 7x2가 아닌 7x7부터 시작하면 된다. 왜냐하면 7x2는 2의 배수이기 때문. 따라서 7보다 작은 수와의 곱은 이미 앞에서 지워졌다.  
> ( 32ms -> 16ms )

```c++
for (int i = 2; i * i <= n; i++)
  if (arr[i] == 1)
    for (int j = i * i; j < arr.size(); j += i)
      arr[j] = 0;
```

- 에라토스테네스의 체를 사용한 빠른 소인수 분해

> [BOJ 16563 어려운 소인수분해](https://www.acmicpc.net/problem/16563)  
> 런타임 에러 (OutOfBounds) - 문제 조건을 잘못 읽어서 자연수의 범위가 1000000까지인줄 알아서 난 오류

> 시간초과 - 기존 코드에서 입출력 최적화를 해주면 해결.

#### 입출력 최적화

```c++
  ios_base::sync_with_stdio(0);
  cin.tie(0);
```

알고리즘 문제를 풀 때는 싱글 쓰레드 환경을 사용하므로 위 코드로 동기화를 끊고 최적화해서 cin, cout을 쓰는게 시간적인 측면에서는 가장 좋을 것 같다. (동기화를 끊기 때문에 scanf, printf와 혼용하면 오답이 나올 수 있다.)  
참고: https://hegosumluxmundij.tistory.com/54

> 강사님의 코드 수행시간 개선(792ms -> 616ms)  
> 소수 구하기에서 했던 것처럼 배수의 제곱부터 시작하면 중복되는 반복을 피할 수 있어서 수행시간을 단축하는데에 도움이 된다.  
> 소수에 해당하는 부분에 0이 들어가기 때문에 나중에 별개로 처리해줘야하지만 나중에 정렬을 해줄 필요가 없어서 수행시간을 단축할 수 있다.

```c++
if (k > 1) cout << k << "\n";
```

- 연습문제

[BOJ 2312 수 복원하기](https://www.acmicpc.net/problem/2312) - 성공

> 에라토스테네스의 체를 활용하면 수행시간을 개선할 수 있을지도? 지금은 16ms

[BOJ 1929 소수 구하기](https://www.acmicpc.net/problem/1929)

> 이미 한번 풀어봤던 문제, [성공](https://www.acmicpc.net/submit/1929/32072578)  
> 저번에 제출했을때 16ms였는데 이번에는 20ms여서 확인해보니깐 이번에 풀때 처음에 1000000짜리 벡터를 초기화해놓고 사용해서 그랬다.

[BOJ 11689 GCD(n, k) = 1](https://www.acmicpc.net/problem/11689)

> **런타임 에러(bad_alloc)** - new 연산으로 메모리 할당이 실패하면 std::bad_alloc이라는 예외가 발생한다. 찾아보니 벡터를 너무 크게 선언해서 메모리 제한에 걸리면서 이러한 에러가 발생한 것 같다. (전역변수로 선언하면 할당되는 공간이 달라서 될때도 있다.)

> 시간초과 - 벡터를 사용해서 하나하나 돌리지말고 전체 개수에서 n과 서로수가 아닌수의 개수를 빼야할것같다. 입력의 크기가 10^12이므로 O(n) 알고리즘은 시간초과가 나올 것이다.

> [시간초과](https://www.acmicpc.net/submit/11689/32080194) - n의 약수로 서로수가 아닌수의 개수를 계산해봤지만 겹치는 경우를 고려하다보니 계산량이 많아진 것 같다.

#### 수행 시간 어림짐작하기

입력의 크기를 시간 복잡도에 대입했을때 그 값이 1억(10^8)을 넘어가면 시간 초과 가능성이 있다.

[BOJ 2960 RESETO](https://www.acmicpc.net/problem/2960)

> [성공](https://www.acmicpc.net/submit/2960/32082239)

[BOJ 1816 암호 키](https://www.acmicpc.net/problem/1816)

> [성공](https://www.acmicpc.net/status?user_id=dkscltks&problem_id=1816&from_mine=1)  
> 10^6까지 에라토스테네스의 체를 사용해서 소수를 구하고 그 소수들로 해당 수들을 나눠서 모든 소인수가 10^6보다 큰지 확인

[BOJ 9020 Goldbach's Conjecture](https://www.acmicpc.net/problem/9020)

> [성공](https://www.acmicpc.net/submit/9020/32084910)  
> 오.. 생각보다 cin, cout 최적화 여부가 수행시간에 영향을 많이 준다. 252ms -> 0ms

[BOJ 4948 Chebyshev's Theorem](https://www.acmicpc.net/problem/4948)

> 이미 한번 풀어본 문제, [성공](https://www.acmicpc.net/submit/4948/32095596)

[BOJ 1747 소수&팰린드롬](https://www.acmicpc.net/problem/1747)

> [실패](https://www.acmicpc.net/submit/1747/32097156) - 소수인지 체크하는 함수, 팰린드롬인지 체크하는 함수를 만들어서 N부터 1씩 증가시키면서 찾는 방식으로 구현했다. 시간초과는 나올 수도 있을거라고 생각했는데 그냥 틀렸다고 나와버려서 좀 막막하다.

[BOJ 어려운 소인수분해](https://www.acmicpc.net/problem/16563)

> 풀어본 적 있는 문제, [성공](https://www.acmicpc.net/submit/16563/32097917)  
> 예전에 풀었을때보다 수행시간이 더 오래 걸려서 확인해보니 벡터보다는 배열을 쓰는것이 더 빠르다.  
> 그리고 함수로 나눠서 구현하는 것보다 main 함수 안에서 구현하는것이 수행시간은 더 적게 나온다.

#### 모둘러 연산

> 아주 큰 정수가 계산 과정에 나오는 경우  
> 아주 작은 유리수를 다루는 경우

- 연산들의 구현(modular int)
  - 연산할때마다 결과에 모듈러 연산을 적용
  - 기초 연산들을 함수로 구현
  - Modular int 구조체를 만들어 사용  
    (보통 레퍼런스 노트를 가지고 문제를 풀 때 사용)

```c++
const long long MOD = 998244353;
//상수로 만들면 소수를 직접 입력하는 것보다 실수를 줄일 수 있다.
//C++에서는 const를 쓰는 것이 #define을 쓰는 것보다 수행시간이 빠르다.
long long madd(long long a, long long b) {
  return (a + b) % MOD;
}
long long msub(long long a, long long b) {
  return (a - b + MOD) % MOD;
}
long long mmul(long long a, long long b) {
  return (a * b) % MOD;
}
```

> 뺄셈의 경우 결과값이 음수가 될 수 있으므로 (a-b)%p의 경우 (a-b+p)%p로 게산하는것이 편리하다.

> 곱셈의 경우 오버플로우가 발생할 수 있어서 64-bit 정수 자료형(long long)을 사용하는 것이 안전하다.

> 나눗셈. 곡셈의 역원.  
> 조합론에서 큰 수로 이루어진 분수를 약분해야 할 때 유용하게 사용할 수 있다.  
> 페르마의 소정리 사용.

- 페르마의 소정리

> a^p = a mod p  
> a \* a^(p-2) = 1 mod p  
> 여기서 a^(p-2)를 a에 대한 곰셈의 역원이라고 한다.

> 미트마스크를 이용한 방식은 이해하지 못함.

[BOJ 13977 이항 계수와 쿼리](https://www.acmicpc.net/problem/13977)

> 예제를 출력할때 터무니 없이 큰 값이 나온다. <del>아직 모듈러 연산에서 곱셈 역원을 잘 이해하지 못해서 구현에 실패한 것 같다.</del> modpow 연산을 잘못 구현했었다.

> ![분할 정복을 통한 거듭제곱 예시](./pow_example.jpg)

> 시간초과 - 큰 수의 팩토리얼을 구하는 만큼 미리 팩토리얼을 구해서 배열로 저장해 놓아야 한다.
> (그런데 팩토리얼을 벡터로 저장하면 오류가 나지 않는데 배열로 저장하면 stack overflow 오류가 나는데 이유를 잘 모르겠다.)

```c++
ll fact[4000001];
fact[0] = 1;
for (int i = 1; i < 4000001; i++) {
  fact[i] = mmul(fact[i - 1], i, MOD);
}
```

> ![배열 사용시 stack overflow](./stack_overflow.png)

> 그리고 앞에서 쓴적이 있는 cin, cout 실행 시간 개선 코드를 추가해줘야한다.

```c++
  ios_base::sync_with_stdio(0);
  cin.tie(0);
```

#### 1주차 과제

[2020-2021 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules)](https://codeforces.com/group/sPvRZDMiQz/contest/1468)

> 14문제 중 3문제 해결. 3문제는 시도했지만 실패.

> F문제에서 시간 초과 오류가 났는데 알고리즘을 어떻게 개선해야 할지 감이 잡히지 않는다. 종만북 등의 방법을 통해 필수 알고리즘을 빨리 숙지해야 할 것 같다.

> C문제 풀어보기.  
> [우선순위 큐 사용해보기](https://codingdog.tistory.com/entry/c-priority-queue-%EC%98%88%EC%A0%9C-compare-%EA%B5%AC%EC%A1%B0%EC%B2%B4%EB%A7%8C-%EC%9E%98-%EC%A0%95%EC%9D%98%ED%95%A9%EC%8B%9C%EB%8B%A4)  
> 시간순, 금액순 우선순위큐 2개랑 주문을 받았는지 체크하는 벡터1개를 사용해서 구현.  
> test 6에서 실패  
> 3번웨이터가 손님의 돈이 같으면 더 빨리 온 손님을 받는다는 조건을 빼먹었다. **문제를 꼼꼼히 읽자...**

### 2주차 강의

#### 매개변수 탐색

[BOJ 1654 랜선자르기](https://www.acmicpc.net/problem/1654)

> 실패
>
> 1.  젤 긴 로프의 길이를 right의 초기값으로 사용해야 한다.
> 2.  로프의 개수가 N보다 클 경우에 left = half + 1로 설정하면 안된다. left = half.

[BOJ 2110 공유기 설치](https://www.acmicpc.net/problem/2110)

> 와 풀었다. 처음 풀어보는 유형이라 그런지 처음에는 어떻게 분할 정복으로 풀어야할지 감이 안 잡혔는데 그림 그려가면서 고민해보다가 결국 풀었다!  
> 가장 인접한 두 공유기 사이의 거리를 분할 정복을 통해 구하면 된다. 거리를 미리 정해두고 검증하는 방법.

#### 삼분 탐색

[BOJ 8986 전봇대](https://www.acmicpc.net/problem/8986)

#### 인터랙티브

[BOJ 19554 Guess the number](https://www.acmicpc.net/problem/19554)

> 실패 - 문제를 잘못 이해했었다...

> 1주차 과제 [F. Full Turn](https://codeforces.com/group/sPvRZDMiQz/contest/1468/problem/F)  
> 강사님의 설명을 들으니깐 풀이 자체는 동일한것같은데 구현을 잘못해서 틀린거같다.

- **실패** - int형을 쓰면 뒤쪽 test case에서 실패. override 때문이려나.
- **실패** - 벡터 크기를 통일하는 과정에서 예를 들어서 6, 14처럼 14가 6으로 나누어떨어지진 않지만 3, 7로 약분할 수 있는 경우를 고려하지 않았다.

**최대공약수(gcd) - 유클리드 알고리즘**

```c++
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b); // 만약 b가 a보다 크다면 이 과정에서 swap이 되므로 따로 예외처리를 해줄 필요가 없다.
}
```

그리고 절댓값을 구할때 abs를 사용하는 것보다는 따로 if문으로 처리하는 것이 수행시간이 더 빠르다.

- **시간초과** - vector를 이용해서 구현하면 시간초과. map을 이용해서 구현해야하는 것 같다.  
  같은 시야를 가진 사람들 묶어서 처리  
  map.find()활용.

**참고**: map에서 key값으로 구조체를 사용할떄 값이 2개이면 구조체대신 pair 클래스를 사용하자.

    map에서 key값으로 구조체를 활용하려면 < 연산자를 override 해주어야한다.
    왜냐하면 map에서 key 값은 이진트리에서 탐색을 할 수 있는 조건이 되어야 하기 때문에 대소 비교가 가능해야 한다.

```c++
bool operator<(const 클래스명& 변수명) const
{
  //비교구문을 통해 true, false를 반환
}
```

    pair 클래스의 경우 sort 알고리즘에 의해 정렬이 가능하기 때문에 2가지 값을 묶어서 사용할떄는 구조체보다 편리하게 사용할 수 있다.
    (첫번째 인자 기준, 첫번쨰가 같으면 두번째 인자로 판단)
