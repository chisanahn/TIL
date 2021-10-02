# 자바의 정석

자바가 C++을 참고해서 만들어졌다는 점을 새롭게 알게되었다.

최근에 알고리즘을 공부하면서 C++에 생각보다 기능이 되게 많아서 시간이 지나면서 업데이트 된건가 했는데 C++이 오히려 원조였다

## 00 자바의 역사

가전제품에 탑재될 소프트웨어 제작

-> C++ 사용 -> 부족함을 느낌

-> C++을 보완한 새로운 언어 개발 (Oak)

-> 인터넷의 등장 -> 운영체제에 독립적인 Oak가 이에 적합하다고 판단

-> 인터넷쪽으로 개발방향을 바꾸고 이름을 Java로 변경

인터넷 상에서 사운드와 애니메이션 등의 요소를 사용하기 위해선 자바로 작성된 애플릿을 사용해야 했기 때문에 큰 인기를 끌었다.

하지만 현재는 보안상의 이유로 애플릿은 더 이상 지원되지 않고 서버 쪽 프로그래밍과 안드로이드에서 주로 사용되고 있다.

## 01 Java 언어의 특징

1. 운영체제에 독립적

2. 객체지향언어

3. 비교적 배우기 쉽다.

   C++과 스몰톡이라는 객체지향언어의 장점은 취하면서 복잡하고 불필요한 부분을 제거하였다.

4. 자동 메모리 관리 - 가비지컬렉터

5. 네트워크, 분산처리 지원

   다양한 네트워크 프로그래밍 라이브러리 지원

6. 멀티쓰레드 지원

   일반적인 방식과 달리 시스템과 관계없이 구현 가능

7. 동적 로딩 지원

   애플리케이션의 변경사항이 발생해도 비교 적은 작업만으로 처리 가능

## 02 JVM

Java virtual machine

장점: 운영체제에 관계없이 실행이 가능하다. `Write once, run anywhere.`

JVM은 운영체제에 종속적이라 다양한 OS용 JVM이 존재한다.

단점: 실행시에 해석이 되고 JVM을 한번 거쳐서 실행되기 때문에 속도가 느리다. 하지만 JIT컴파일러와 향상된 최적화 기술을 통해 지금은 속도의 격차가 많이 줄었다.

### JVM의 메모리 구조

1. **메서드 영역 (method area)**

   클래스에 대한 정보(클래스 데이터), 클래스 변수가 저장되는 곳

   JVM의 종류에 따라 클래스가 필요할때 메모리에 로딩하는 경우, 프로그램이 시작될떄 미리 클래스들을 로딩하는 경우가 있다.

2. **힙 (heap)**

   인스턴스 변수들이 생성되는 공간

3. **호출스택(call stack / execution stack)**

   메서드의 작업에 필요한 메모리 공간.

   메서드의 지역변수, 연산의 중간결과 등을 저장하는데 사용된다.

   메서드가 작업을 마치면 할당되었던 메모리 공간은 반환되어 비워진다.

   ````
   나중에 호출된 메서드를 먼저 처리하기 때문에 스택을 사용하게 된다.
   ````

   `StackOverflowError`가 나오는 부분.

   ex) 함수를 너무 많이 호출했을때, 재귀함수가 무한루프에 빠졌을때 등



## path 환경변수

그동안 사용한적도 있고 어렴풋이 알고 있었지만 이번에 정확하게 알게되었다.

```
path는 OS가 파일의 위치(디렉토리)를 파악하는데 사용하는 경로(path)로, path에 디렉토리를 등록하면, 해당 디렉토리에 포함된 파일을 파일 경로없이 파일 이름만으로도 사용할 수 있게 된다.
```

## 03 Hello.java

### 클래스

자바에서 모든 코드는 반드시 클래스 안에 존재해야 한다.

이때 소스파일의 이름은 클래스의 이름과 일치해야 한다.

하나의 소스파일에 하나의 클래스가 있는것이 일반적이지만 2개 이상의 클래스가 있는 경우 public 클래스의 이름과 일치해야 하고, public 클래스가 없는 경우 어떤 클래스의 이름으로 해도 상관없다. 그리고 한 소스파일에 public 클래스는 하나만 존재한다.

소스파일과 달리 클래스파일은 클래스마다 하나씩 만들어진다.

클래스가 main 메서드를 반드시 가질 필요는 없지만 main 메서드는 java 애플리케이션의 시작점이므로 하나의 java 앱은 main 메서드를 포함한 클래스가 반드시 하나 있어야 한다.

### 실행과정

1. 필요한 클래스 로드
2. 클래스 파일 검사
3. 지정된 클래스에서 main 메서드 호출

### println()

print line

```java
System.out.println("x: "+10);
```

파이썬처럼 덧셈연산자를 이용해서 문자열을 합칠 수 있다.

### printf()

`println()`은 출력 형식을 따로 지정할 수 없다.

`printf()`는 지시자(specifier)를 통해 출력 형식을 지정해 줄 수 있다.

```java
// 정수형
System.out.printf("%5d", 10);
System.out.printf("%-5d", 10);
System.out.printf("%05d", 10);
// 16진수
System.out.printf("%x", 10);
System.out.printf("%#x", 10);
System.out.printf("%#X", 10);
// 2진수. 따로 지시자가 없기 때문에 문자열로 변환하는 메서드 이용
System.out.printf("%s", Integer.toBinaryString(10));

// 실수형
System.out.printf(".10f%n", 3.1452);
System.out.printf("14.10f%n", 3.1452);  //소수점 아래 10자리, 소수점 포함 4자리
System.out.printf("014.10f%n", 3.1452);

// 문자열
System.out.printf("%20s", "fejaklgjelkaw");
System.out.printf("%-20s", "fejaklgjelkaw");
System.out.printf("%.8s", "fejaklgjelkaw");
```

c언어와 대체로 비슷하지만 줄바꿈문자로 `%n`을 사용한다.

(`\n`을 사용할 수 있지만 OS마다 줄바꿈문자가 다를 수 있기 때문에 `%n`을 사용하는 것이 안전하다고 한다.)

문자열도 형식지정자를 사용할 수 있다.

실수형을 출력할때 소수점 자리수를 설정하면 반올림되어서 표시된다.

### 입력 - Scanner

```java
import java.util.*;

Scanner scanner = new Scanner(System.in);
String input = scanner.nextLine();	// Enter를 누르기 전까지 문자열로 입력받는다
int num = Integer.parseInt(input);
```

`nextInt()`나 `nextFloat()`와 같은 메서드들을 사용하면 변환하지 않고 바로 받을 수 있지만 연속적으로 값을 입력받기 까다롭기 때문에 `nextLine()`으로 입력받고 적절하게 변환해서 사용하는 것이 더 편하다.

### 입력 - 커맨드 라인 이용

터미널에서 프로그램을 실행할 때 클래스 이름 뒤에 공백문자로 구분하여 여러 개의 문자열을 프로그램에 전달할 수 있다. 공백이 있는 문자열은 큰 따옴표로 묶어서 입력한다.

전달된 문자열은 main 메서드의 args 매개변수에 전달된다.

## 04 변수

### a. 기본형

실제 값 저장, 총 8개

#### 논리형

`boolean`(1byte)

> 기본값: false
>
> 1bit로도 충분하지만 java에서 데이터를 다루는 최소단위가 1byte라 1byte의 크기를 갖는다.
>
> c++과는 달리 형변환을 지원하지 않는다.
>
> ```
> while(1)  // 불가.
> while(true)  // OK.
> ```

#### 문자형

`char`(2byte)

#### 정수형

`byte`(이진 데이터를 다룰때 사용, 1byte), `short`(C언어와의 호환을 위해 추가됨, 2byte)

> JVM의 피연산자 스택이 피연산자를 4byte 단위로 저장하기 때문에 계산시 4byte로 변환되어서 사용된다. 성능보다 저장공간을 절약하는 것이 더 중요할 때 사용

`int`(기본자료형, 4byte), `long`(8byte)

> 대부분의 경우 `int`를 사용하는 것이 효율적이다.
>
> int의 범위(약 +-20억)를 넘어가는 값을 다룰때 `long` 사용.
>
> long의 범위를 넘어가는 값을 다룬다면 `실수형`이나 `Biginteger 클래스` 사용.

> [c언어에서 int와 long의 차이](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=passith&logNo=70152718749)
> int는 CPU가 가장 효율적으로 다룰 수 있는 정수형으로 운영체제에 따라 32bit또는 64bit의 크기를 가지는데
> long은 크기가 4byte로 고정되어있다.

#### 값의범위

-2^(n-1)부터 2^(n-1)-1까지

2^10 = 1024, 10^3 = 1000으로 근사시켜서 값의 대략적인 범위를 짐작할 수 있다.

```
ex) int형의 범위: -2^31 ~ 2^31-1 대략적으로 2*10^9 정도의 음수/양수까지 표현할 수 있다.
```

#### 실수형

`float`(4byte, 정밀도 7자리. 소수점 이하 6자리), `double`(기본자료형, 8byte, 정밀도 15자리)

부동소수점(floating-point) 방식

`부호`, `지수`, `가수` 3부분으로 이루어진다.

또한 값의 범위 뿐만 아니라 정밀도도 중요하다.

`지수`에서 최소값, 최대값은 특별한 값을 위해 사용된다.

- NaN(Not a Number)
- 무한대(POSITIVE_INFINITY, NEGATIVE_INFINITY)

`지수` 부분에는 따로 부호 비트가 없기때문에 `bias 표현법`을 사용한다.

### b. 참조형

* `null`또는 객체의 주소를 값으로 갖는다.
* C언어와 달리 참조형 변수간의 연산을 할 수 없다.

```java
// 참조변수 초기화
Date today = new Date()
```

#### toString()

참조변수의 출력이나 덧셈연산자를 이용한 참조변수와 문자열의 결합에는 `toString()`이 자동적으로 호출되어 참조변수를 문자열로 대치한 후 처리한다.

모든 클래스의 조상인 Object 클래스에 정의된 것으로 모든 객체에 대해서도 `toString()`을 호출하는 것이 가능하다.

오버라이딩해서 원하는 문자열을 반환하도록 할 수 있다.

### c. 상수

java에서 상수는 `final`를 앞에 붙여서 사용한다.

```java
final int MAX_SPEED = 10;
```

### d. 리터럴

정확한 정의는 모르고 있었는데 프로그래밍에서 상수가 다른 의미로 사용되면서 우리가 일반적으로 사용하는 상수를 리터럴이라고 부르는 것이었다.

```
리터럴: 그 자체로 값을 의미하는 것.상수: 값을 한번만 저장할 수 있는 공간. 보통 리터럴에 의미있는 이름을 붙여서 사용하기 위해 쓰인다.-> 코드의 이해와 수정이 간편해진다.
```

#### 접미사

접미사를 사용해 자료형을 특정할 수 있다. 접미사를 사용하지 않는다면 기본자료형인 int와 double로 취급된다.

* `l, L` : long 타입 리터럴 (l은 숫자 1과 헷갈릴 우려가 있어 보통 L을 주로 사용한다.)
* `F, f `: float 타입 리터럴
* `0x, 0X` : 16진수 
* `0` : 8진수

```
float pi = 3.14;  // 오류. float 타입 변수에 double 타입 리터럴을 저장하기 떄문float pi = 3.14f;  // OK.double pid = 3.14f;  // OK.
```

c언어나 다른 언어에서는 자동으로 형 변환이 이루어지는걸로 아는데 java는 아예 오류가 나기 때문에 더 유의해야 할 것 같다. (변수가 저장할 수 있는 값의 범위보다 더 큰 값을 저장하려는 경우 형변환을 생략하면 오류가 발생한다.)

java에서도 저장범위가 넓은 타입에 좁은 타입의 값을 저장하는 것은 허용된다.

float 형을 사용하는 경우만 주의해서 사용하면 될 것 같다.

\+ 변수의 범위 고려

#### 실수형 리터럴

- 10의 제곱을 나타내는 기호 `E, e`

  `3.14e3` == 3140.0

  `1e-3` == 0.001

* 기호p - 16진수 * 2의 제곱

  `0x1p2` == (1*16^0) * 2^2 == 1.0 * 4 == 4.0

#### 문자, 문자열 리터럴

빈 문자열 허용 ""

빈 문자 불가 ''

문자열 덧셈 연산자 지원

숫자를 문자열로 변환할때 빈문자열과 덧셈 연산자를 수행해서 쉽게 변환할 수 있다.

```java
String str = "Java" + 8.0;	// "Java8.0"String num = 17 + ""	// "17"
```

### 진법

에니악은 10진법을 사용했다는것을 처음 알았다. 하지만 전압을 10단계로 나누어 처리하는데 한계가 있어 에드박은 2진법을 사용해서 만들었다.

`word`: CPU가 한 번에 처리할 수 있는 데이터의 크기.

int형의 크기와 워드의 크기가 동일한 것 같아서 찾아봤는데 int와 word는 동일하지 않다. https://kldp.org/node/138360

`정수의 진법변환` 나눠서 변환(결과값 - 나머지)

`실수의 진법변환` 곱해서 변환(결과값 - 정수부)

###  2의 보수

어떤 수의 `n의 보수`는 더했을때 n이 되는 수

`2의 보수 관계` 역시 더했을 때 2가 되는 두 수의 관계를 말하며 2는 이진수로 10이다.

2진수로 10은 자리올림이 발생하고 0이 되는 수를 말한다.

따라서 2의 보수관계에 있는 두 수를 더하면 0이 된다.

이를 이용해서 대부분의 시스템들이 부호있는 정수를 `2의 보수법`으로 표현한다. 

어떤 수의 `1의 보수 + 1`은 `2의 보수`이다. 왜냐하면 자리올림이 발생하지만 오버플로우가 발생하면서 0이 되기 때문.

### 오버플로우

최대값 + 1 -> 최소값

최소값 - 1 -> 최대값

#### 부호없는 정수

2진수로 0이 될때 오버플로우 발생.

```java
1111  // 150000  // 0
```

#### 부호있는 정수

부호비트가 0에서 1이 될때 오버플로우가 발생.

```java
0111  // 71000  // -8
```



## 05 배열

```java
// 배열의 생성, 초기화
int[] arr = new int[5];  // OK.
int arr[] = new int[5];  // OK.
int[] arr = new int[]{ 10, 20, 30 };  // OK.
int[] arr = { 10, 20, 30 };  // OK.

// 생성과 동시에 초기화를 하는 경우에만 new int[] 부분을 생략할 수 있다.
int[] arr;
arr = new int[]{ 10, 20, 30 };  // OK.
arr = { 10, 20, 30 };  // Error.
```

각 배열요소는 기본값으로 0을 갖는다.

유효한 범위를 벗어난 값을 index로 사용했을때 컴파일에서 오류가 나지 않고 실행 시 오류가 나는 이유

> 배열의 index로 변수를 많이 사용하는데, 변수의 값은 실행 시에 결정되므로 컴파일러는 이 값의 범위를 확인할 수 없기 때문이다.

`Arrays.toString(배열이름)` 메서드를 사용해 배열의 모든 요소를 일정한 형식의 문자열로 출력할 수 있다.

배열을 그대로 출력하면 `타입@주소` 형식으로 출력된다 (`toString()` 메서드가 오버라이딩 되어있지 않아서 그런 것 같다)

예외적으로 char 배열은 print, println 로 출력하면 각 요소가 구분자 없이 그대로 출력된다.

배열의 길이의 최대값은 int타입의 최대값, 약 20억이다.

```java
arr.length;  // 배열의 길이, 상수이다.
```

배열은 한번 선언되고 나면 길이를 변경할 수 없다. 배열의 길이를 변경하기 위해서는 더 큰 길이의 배열을 새로 생성하고 기존 배열의 값을 새로운 배열에 복사해야 한다.

### 배열의 복사

깊은 복사를 하는 방법

* `clone()`
* `System.arraycopy(원본, 원본 시작인덱스, 목적지, 목적지 시작인덱스, 복사할 문자열의 길이)`

### 길이가 0인 배열

java에서는 길이가 0인 배열도 지원한다. 따라서 다른 언어와 달리 배열이 비어있는 경우를 따로 예외처리를 하지 않고 사용할 수 있어서 좀 더 간편하다.

```
ex. 입력값이 없는 경우 배열의 기본값은 null이라 배열을 생성하지 않는다면 다른 부분에서 예외가 날 수 있다.
이때 크기가 0인 배열을 생성해서 사용하면 따로 예외처리를 해주지 않아도 된다.
```

### 가변 배열

java에서는 2차원 이상의 배열을 `배열의 배열` 형태로 저장하기 때문에 다음과 같이 배열을 구성하는 것이 가능하다.

```java
int[][] arr = new int[3][];arr[0] = new int[5];arr[1] = new int[3];arr[2] = new int[4];
```

연습문제 - BOJ 14912 숫자 빈도수

연습문제 - BOJ 5691 Mean Median Problem

### 문자열

java에서는 char형 배열 대신 String 클래스로 문자열을 다룬다.

자세한 내용은 10. java.lang.package - `String 클래스` 참고



## 06 연산자

대입 연산자의 반환값은 저장된 값.

### 산술변환

1. 두 피연산자의 타입을 둘 중 큰 타입으로 일치시킨다.

2. 피연산자의 타입이 int보다 작은 타입이면 int로 변환한다.

   (int가 가장 효율적으로 처리할 수 있고 오버플로우를 방지하기 위해서)

```java
char c1 = 'a';char c2 = c1++;  // OK.char c3 = c1 + 1;  // 오류.char c4 = (char)(c1 + 1);  // OK.char c5 = 'a' + 1;  // OK.// 리터럴 간의 연산은 실행과정 동안 변하는 값이 아니기 때문에 컴파일 시 컴파일러가 계산해서 그 결과로 대체한다.
```

### 논리 연산자

OR연산의 경우 한쪽만 참이면 참이므로 좌측 피연산자가 참이면 우측 피연산자는 평가하지 않는다. 마찬가지로 AND연산의 경우 한쪽만 거짓이면 거짓이므로 좌측 피연산자가 거짓이면 우측 피연산자는 평가하지 않는다.

따라서 우측 피연산자를 잘 설정하면 연산 속도를 높일 수 있다.

#### 논리 부정 연산자

논리부정연산자 `!`를 적절히 사용해서 더 직관적인 조건식을 만들 수 있다.

```java
// 알파벳 소문자가 아닌 경우를 찾는 식ch < 'a' || ch > 'z'// 논리 부정 연산자를 이용하면 더 직관적이다.!('a' <= ch || ch <= 'z')
```

###  비트 연산자

비트OR연산자 `|`는 주로 특정 비트의 값을 변경할 때 사용한다.

```java
0xAB | 0xF = 0xAF
```

비트AND연산자 `&`는 주로 특정 비트의 값을 뽑아낼 때 사용한다.

```java
0xAB & 0xF = 0xB
```

비트XOR연산자 `^`는 같은 값을 두고 XOR연산을 수행하면 원래의 값으로 돌아오는 특징을 이용해서 간단한 암호화에 사용된다.

```java
0xAB ^ 0xF = 0xA40xA4 ^ 0xF = 0xAB
```

### 쉬프트 연산자

```java
x << n  // x*2^nx >> n  // x/2^n
```

쉬프트연산자와 &연산자를 이용해서 16진수를 끝에서부터 한짜리 뽑아내는 예제

```java
0xABCD & 0x000F == 0x000D  // D0xABCD >> 4 == 0x0ABC0x0ABC & 0x000F == 0x000C  // C0x0ABC >> 4 == 0x00AB0x00AB & 0x000F == 0x000B  // B0x00AB >> 4 == 0x000A0x000A & 0x000F == 0x000A  // A
```

### 삼항연산자

`조건식` ? `식1` : `식2`

참이면 `식1` return, 거짓이면 `식2` return

skstn

### 난수

`Math.random()` 사용.

0.0~1.0 사이의 double형 실수 반환. (1.0은 범위에 포함되지 않는다.)



## 07 반복문

### 향상된 for문

배열이나 컬렉션에 저장된 요소에 접근할 떄 기존보다 편리한 방법으로 처리할 수 있다.

```java
int arr[] = {10,20,30,40,50};
for(int a : arr) {   
    System.out.println(a);
}
```

c++에서 `for (auto& s : S)`랑 비슷하다.

하지만 c++과는 다르게 자로형도 직접 지정해줘야 하고 값을 변경하는 것은 가능하지 않다.

[BOJ 2577 숫자의 개수](https://www.acmicpc.net/problem/2577)

### 이름 붙은 반복문

break, continue문은 근접한 단 하나의 반복문만 벗어날 수 있기 때문에 반복문에 이름을 붙이고 break문과 continue문에 이름을 지정하고 사용해서 둘 이상의 반복문을 벗어날 수 있다.

```java
Loop1 : while(true) {
    while(true) {        
        break Loop1;    
    }
}
```

## 08 객체지향언어

### a. 객체지향이론

```기본개념
<기본개념>
실제 세계는 사물(객체)로 이루어져 있으며, 발생하는 모든 사건들은 사물간의 상호작용이다.
```

과학실험 등 모의실험을 위해 가상세계를 컴퓨터에 구현하기 위한 노력으로 탄생하였다.

실제 사물의 속성과 기능을 분석한 다음, 데이터(변수)와 함수로 정의해서 가상세계를 구현하고 모의 실험을 하는데 사용되었다.

이후 1960s 객체지향이론을 프로그래밍언어에 적용한 `시뮬라`가 처음 등장했다. 하지만 그 당시 에는 `FORTRAN` 등 절차적 언어들이 주로 사용되었다.

시간이 지나면서 프로그램의 규모가 커지고 사용자들의 요구가 빠르게 변화해가면서 절차적언어의 한계를 느끼고 객체지향언어의 입지가 점차 커지다가 `java`의 등장 이후 널리 사용되게 되었다.

### b. 객체지향언어

```
기존의 언어에 몇 가지 규칙들을 추가해 코드 간에 관계를 형성해
보다 유기적으로 프로그램을 구성하는 것이 가능해진 언어
```

#### 재사용성, 유지보수, 중복된 코드 제거

중복된 코드 제거 - 코드의 신뢰성을 높여주고 오류의 발생 가능성을 줄여준다.

프로그램의 개발과 유지보수에 드는 시간과 비용을 획기적으로 개선하였다.

```
재사용성을 높이고 중복을 제거하는 것이 객체지향프로그래밍이 추구하는 궁극적인 목표이다.
```



* **클래스** - 객체를 정의해 놓은 것. 객체를 만들때 사용.

  `인스턴스화(instantiate)`

  > 클래스로부터 객체를 만드는 과정

  `인스턴스(instance)`

  >  클래스로부터 만들어진 객체. 어떤 클래스로부터 만들어진 것인지를 강조.
  >
  > ```
  > String num = new String("java");
  > ```
  >
  > num은 객체다. / num은 String 클래스의 인스터스이다.
  >
  > 이때 num 자체는 객체가 아니고 객체를 참조하는 변수이다. new 연산자를 통해 객체가 생성되고 해당 객체의 주소를 참조형 변수를 통해 가리키는 것이다.

* **객체** - 실제로 존재하는 것.

  * 유형의 객체
  * 무형의 객체 - 개념, 논리 같은 것들도 객체로 간주된다.

  속성, 기능을 갖는다. 객체지향언어에서는 **멤버변수**, **메서드**라고 불린다.

  > 객체는 참조변수를 통해서만 다룰 수 있다.
  >
  > 이때 객체와 참조변수의 타입이 일치해야한다.


연습문제 - BOJ 4673 Self Numbers

 배열 생성은 [], 객체 생성은 ()

```java
String[] arr = new String[2];
arr[0] = new String("first");
arr[1] = "second";  // String 클래스는 유일하게 객체를 생성할때 new 생략 가능.
```

### c. 변수

* 멤버변수

  클래스 내부에서 선언된다. 초기화를 하지 않는다면 기본값을 갖는다.

  * **인스턴스 변수**

    인스턴스가 생성될 때 생성.

  * **클래스변수**

    해당 클래스의 모든 인스턴스가 공유하는 변수. 인스턴스가 없어도 사용할 수 있다.

    `클래스이름.클래스변수` (인스턴스 변수처럼 참조형 변수를 통해서도 사용할 수 있다)

    static을 자료형 앞에 붙여서 사용. 앞에 `public`을 붙이면 `전역변수`의 성격을 갖는다.

    클래스가 메모리에 올라갈 때 생성. (참조변수의 선언이나 객체의 생성과 같이 클래스의 정보가 필요할 때 클래스는 메모리에 로딩된다.)

* **지역변수**

  메서드 내에 선언된 변수. 메서드가 실행될 때 생성.
  
  초기화를 하지 않으면 사용할 수 없다. (멤버변수와 달리 자동으로 기본값으로 초기화되지 않는다)

```java
class EX {
	int a;  // 지역변수 - 인스턴스변수
    static int b;  // 지역변수 - 클래스변수
    void method() {
		int c;  // 지역변수
    }
}
```

#### 초기화

지역변수의 경우 초기화를 하지 않으면 사용할 수 없기 때문에 초기화가 필수적이다.

멤버변수, 배열의 경우 초기화를 하지 않더라도 자동적으로 변수의 자료형에 맞는 기본값으로 초기화된다. 따라서 초기화도 선택적이고 여러가지 방법이 존재한다.

##### 1. 명시적 초기화

> 변수를 선언과 동시에 초기화하는 것
>
> ```java
> int a = 10;
> ```

##### 2. 초기화 블럭

> ```java
> class Ex {
>     /* 명시적 초기화 */
>     
>     static { /* 클래스 초기화 블럭 */ }
>     
>     { /* 인스턴스 초기화 블럭*/ }
>     
>     ...
> }
> ```
>
> 메서드처럼 조건문, 반복문 등을 사용할 수 있어 초기화 작업이 복잡한 경우 유용하게 사용된다.
>
> **클래스 초기화 블럭** - 클래스가 메모리에 처음 로딩될 때 한번만 수행된다.
>
> **인스턴스 초기화 블럭** - 인스턴스를 생성할 때마다 수행된다. 생성자보다 먼저 수행되기 때문에 주로 모든 생성자에서 공통으로 수행해야 하는 코드를 넣는다.

##### 3. 생성자

> 인스턴스가 생성될 때 호출되는 "인스턴스 초기화 메서드". 뒤에서 자세히 다룬다.

##### 초기화 순서

> 1. 클래스변수 초기화
> 2. 인스턴스변수 초기화
>
> 기본값 -> 명시적 초기화 -> 초기화 블럭 -> 생성자(클래스변수는 포함 x)



### d. 메서드

내부적인 동작 과정을 몰라도 입출력만 알고있다면 사용할 수 있기 때문에 `블랙박스`라고도 한다.

대표적인 장점 3가지

1. 높은 재사용성
2. 중복된 코드 제거 -> 유지 보수 굿
3. 프로그램의 구조화 -> 유지 보수 굿

선언부와 구현부

인자와 매개변수

같은 클래스 내의 메서드끼리는 참조변수를 사용하지 않고도 호출이 가능하지만 static 메서드는 같은 클래스 내의 인스턴스 메서드를 호출할 수 없다.

하지만 일반적으로 클래스멤버는 인스턴스멤버를 참조 또는 호출하지 않는다.

#### 클래스 메서드(static 메서드)

클래스 변수와 마찬가지로 객체를 생성하지 않고 호출할 수 있는 메서드

클래스 메서드도 클래스변수처럼`클래스이름.메서드이름` 으로 사용할 수 있다.

또한 인스턴스메서드에 비해 호출시간이 짧다.

이러한 점 때문에 인스턴스 변수를 사용하지 않는다면 보통 static 메서드를 사용한다.

#### 매개변수의 유효성 검사

부적절한 값이 매개변수로 전달되는 경우 매개변수의 값을 보정하거나, 메서드를 종료하는 등 예외 처리를 해주어야 한다.

#### 참조형 매개변수

c나 c++과 달리 참조형변수나 포인터변수가 따로 존재하지 않는다.

따라서 예를 들어 int형 참조형 매개변수를 사용하고 싶다면 길이가 1인 int형 배열을 사용한다.

그리고 구조체나 클래스도 항상 주소값으로 전달된다. (C나 C++에서는 포인터를 사용하지 않는다면 값이 복사되서 들어간다.) 

#### 오버로딩

한 클래스 내에 같은 이름의 메서드를 여러 개 정의하는 것.

(단, 구분을 위하여 매개변수의 개수 또는 타입이 달라야 한다.)

다른 타입의 매개변수로 동일한 기능을 수행할때 유용하게 사용할 수 있다.

-> 개발 편의성, 사용자 편의성 증가

```java
int add(int a, int b);
long add(long a, long b);
long add(int[] a);
```

#### 가변인자

매개변수 개수를 고정적으로 정의해줄 수 있다. 

`타입... 변수명`으로 사용하며 매개변수 중에서 제일 마지막에 선언해야 한다.

```java
String func(int a, String... str);
```

가변인자에 해당하는 인자의 개수 0, 1, 2, ... 뭐든 가능하다. 또한 배열도 인자가 될 수 있다.

가변인자는 내부적으로 배열을 사용한다. 하지만 배열을 매개변수로 사용하는 경우와 달리 인자를 생략할 수 있어 더 간편하다.

### e. 생성자

인스턴스가 생성될 때 호출되는 "인스턴스 초기화 메서드"

주의할 점

1. 생성자의 이름은 클래스의 이름과 같아야 한다.
2. 생성자는 리턴 값이 없다. (void도 앞에 붙이지 않는다.)
3. 생성자 또한 다른 메서드와 마찬가지로 오버로딩이 가능하다.

```java
class Ex{
    Ex() {  // 생성자.
        ...
    }
    EX(int a, int b) {  // 생성자.
		...
    }
    ...
}
```

#### default 생성자

클래스 내에 생성자가 하나도 없다면 컴파일러가 자동적으로 기본 생성자를 추가해준다.

```
클래스이름() {}
```

주의: 한 개 이상의 생성자가 정의되어있는 경우 default 생성자는 생성되지 않는다.

#### 생성자에서 다른 생성자 호출하기

같은 클래스의 멤버들 간에 서로 호출할 수 있는 것처럼 생성자 간에도 서로 호출이 가능하다.

1. 생성자의 이름으로 클래스이름 대신 this를 사용한다.
2. 반드시 첫 줄에서만 호출이 가능하다.

```java
class Ex{
    Ex(int a) {
        this(a, 0);
    }
    Ex(int a, int b) {
        ...
    }
    ...
}
```

#### 참조변수 this

인스턴스 자기 자신을 가리키는 참조변수.

인스턴스변수는 `this.인스턴스변수` 형식으로 사용해서 매개변수와 구분되도록 하는 것이 좋다.

특히나 생성자의 경우 매개변수로 인스턴스변수들의 초기값을 제공받는 경우가 많기 때문에

생성자의 매개변수와 인스턴스변수의 이름을 동일하게 사용하고 `this.인스턴스변수`로 구분하는게 더 직관적인 경우가 많다.

#### 생성자를 이용한 인스턴스의 복사

```java
class Ex {
  	int a;
    int b;
    Ex() {
        this(0, 0);
    }
    Ex(int a, int b) {
		this.a = a;
        this.b = b;
    }
    Ex(Ex e) {
        // a = e.a;
        // b = e.b;
        // 가능하면 기존 코드를 재활용하여 유기적으로 구성하는 것이 좋다.
        this(e.a, e.b);
    }
}
```



### f. 클래스 간의 관계 - 상속

**is-a 관계**

클래스의 이름 뒤에 상속받고자 하는 클래스의 이름을 키워드 `extends`와 함께 써주면 된다.

```java
class Child extends Parents {
    ...
}
```

부모클래스 - 자식클래스

자식클래스는 부모클래스의 모든 멤버를 상속받는다. 단, static 멤버는 상속받지 않는다. (참고자료: https://jinyoungchoi95.tistory.com/16)

static 멤버들은 자신들이 정의된 클래스에 묶여있다고 생각하면 좋다.

따라서 클래스간의 상속관계를 맺어 주면 자식클래스의 공통적인 부분은 부모클래스에서 관리하고 자식클래스는 자신에 정의된 멤버들만 관리하면 되므로 각 클래스의 코드가 적어져서 관리가 쉬워진다.

```
객체지향 프로그래밍에 있어서 프로그램을 구성하는 클래스들을 분석하여 적절한 상속관게를 맺어주는 것이 가장 중요하다.
```



#### 오버라이딩

부모클래스에서 상속받은 메서드를 자식클래스에서 내용을 변경하는 것.

##### 오버라이딩의 조건

0. 이름, 매개변수, 반환타입이 부모클래스의 메서드와 동일해야 한다. (선언부가 일치해야 한다.)
1. 접근 제어자를 부모클래스의 메서드보다 좁은 범위로 변경할 수 없다.
2. 부모클래스의 메서드보다 많은 수의 예외를 선언할 수 없다.
3. 메서드의 종류를 변경할 수 없다. (인스턴스, static)

##### 공변 반환타입

JDK 1.5부터 부모 메서드의 반환타입을 자식 클래스 타입으로 변경할 수 있다.

메서드를 오버라이딩할때 반환값을 바꾸기 위해서 유용하게 사용한다.

캡슐화.



#### 단일 상속

C++과 달리 다중 상속은 가능하지 않다.

다중상속을 허용하면 복잡한 클래스를 쉽게 작성할 수 있다는 장점이 있지만

상속받는 클래스들에서 이름이 중복되는 멤버가 있을 경우 처리 하기가 복잡해진다는 단점이 있다.

따라서 자바는 클래스 간의 관계를 보다 명확히하고 코드의 신뢰성을 높이기 위해 단일 상속만을 허용한다.

인터페이스를 이용하면 다중상속이 가능하지만 거의 사용하지 않는다.

보통 두 개의 클래스로부터 상속받아야하는 경우, 비중이 더 높은 클래스를 부모 클래스로 상속받고 다른 클래스를 멤버변수로 포함시키는 것이 일반적이다.

#### Object 클래스

모든 클래스의 조상. 상속계측도 최상위 클래스

다른 클래스로부터 상속을 받지 않을 경우 컴파일러가 자동으로 `extends Object`를 추가한다.

`toString()`, `equals(Object o)`와 같은 메서드들이 Object 클래스에 정의되어 있다.

자세한 내용은 10. java.lang 패키지 - `Object 클래스` 참고

#### super

자식 클래스에서 부모 클래스로부터 상속받은 멤버를 참조하는데 사용되는 참조변수

super를 이용해서 구별할 수 있기 때문에 부모 클래스에 선언된 멤버변수와 같은 이름의 멤버변수를 자식 클래스에서 중복해서 정의하는 것이 가능하다.

변수만이 아니라 메서드 역시 super를 써서 호출할 수 있다.

자식 클래스에서 오버라이딩을 한 메서드의 경우 super를 써서 부모 클래스의 메서드(오버라이딩 되지 않은)를 호출할 수 있다.

상속받은 멤버인지 구별하는데 사용된다는 점을 제외하곤 super와 this는 근본적으로 같다.

#### super()

자식 클래스에서 부모 클래스의 멤버가 사용될 수 있기 때문에 자식 클래스의 생성자를 호출하면 부모 클래스 멤버의 초기화 작업이 수행되어야 한다.

부모 클래스의 멤버변수는 부모 클래스의 생성자에 의해 초기화 되도록 해야 한다.

````
Object 클래스를 제외한 모든 클래스의 생성자 첫줄에 this() 또는 super()를 호출해야 한다. 그렇지 않으면 컴파일러가 자동으로 super();를 생성자의 첫줄에 삽입한다.
````



### g. 클래스 간의 관계 - 포함

**has-a 관계**

한 클래스의 멤버변수로 다른 클래스 타입의 참조변수를 사용하는 것.

부품 단위로 나눠서 클래스를 만들고 조립해서 사용한다고 생각하면 될 것 같다.

```java
class Car {
    Engine e = new Engine();
    Door[] d = new Door[4];
    ...
}
```



### h. 패키지

클래스의 묶음. 클래스의 효율적인 관리가 가능해진다.

클래스의 이름이 동일하더라도 다른 패키지에 속해있다면 구별이 가능하다.

```
클래스 - 파일
패키지 - 디렉터리
```

디렉터리가 하위 디렉터리를 가질 수 있는 것처럼 패키지도  하위 패키지를 가질 수 있다.

```java
java.lang.String
/* java/lang/String.class */
```

#### 패키지 선언

소스코드의 맨 위에서 한번만 선언할 수 있다.

```java
package 패키지명;
```

모든 클래스는 반드시 하나의 패키지에 속해야 한다.

따로 패키지를 선언하지 않는 경우, java에서 기본으로 제공하는 `unnamed package`에 자동으로 속하게 된다.

```bash
javac -d <패키지의 루트디렉토리> 파일명.java
```

컴파일을 할때 -d 옵션을 주면 패키지와 일치하는 디렉토리에 클래스 파일을 생성하고 디렉토리가 없는 경우 자동으로 생성한다.

새로운 패키지를 만드는 경우 JVM이 패키지를 찾을 수 있도록 루트 디렉토리를 클래스패스에 포함시켜야한다.

기본적으로 현재 디렉토리가 클래스패스로 지정되어있다. 또한, JDK에 기본적으로 설정되어있는 클래스패스를 이용하면 따로 설정하지 않아도 된다.

#### import

다른 패키지의 클래스를 사용할때 import문으로 사용하고자 하는 클래스의 패키지를 미리 명시해두면 패키지 명을 생략하고 클래스를 사용할 수 있다.

```java
import java.util.*;

Scanner scanner = new Scanner(System.in);
```

##### static import

static 멤버변수를 클래스명을 생략하고 사용할 수 있게 해준다.

```java
import static java.lang.System.out;
// System.out을 클래스명을 생략하고 out만으로 사용할 수 있다
```



### i. 제어자

#### 접근제어자

**캡슐화**를 위해 사용된다.

> 1. 클래스 내부 데이터를 보호하기 위해서
>
> ```
> 멤버변수를 private이나 protected로 제한하고 멤버변수의 값을 읽고 변경할 수 있는 public 메서드(getter, setter)를 제공한다면
> 변수에 실수로 이상한 값이 할당되는 것을 막을 수 있다
> ```
>
> 2. 내부 작업에서만 사용되는 멤버들을 가림으로써 복잡성을 줄이기 위해서
>
> ```
> 만일 메서드의 접근지정자가 private이라면 수정하고 나서 해당 클래스만 점검하면 된다.
> 이첢 접근지정자를 적절히 사용하면 유지보수가 간편해질 수 있다.
> ```

**public**: 전체

**protected**: 자손클래스&같은 패키지

**default**(접근제어자를 따로 지정하지 않는 경우): 같은 패키지

**private**: 같은 클래스

> 생성자를 private으로 지정하고 따로 인스턴스를 생성해서 반환해주는 public static 메서드를 사용해서 생성할 수 있는 인스턴스의 개수를 제한할 수 있다.
>
> 생성자가 private인 경우 상속할 수 없기 때문에 `final` 클래스로 명시하는 것이 좋다.
>
> ```
> java에서 기본적으로 제공하는 Math 클래스의 경우 몇 개의 상수와 static 메서드만으로 구성되어 있기 때문에 불필요한 접근을 막기 위해 생성자의 접근 지정자를 private으로 지정하였다.
> ```

클래스의 경우 public, default 접근제어자 사용 가능

> 한 파일에 여러 클래스를 선언할 경우 public 클래스는 하나만 있어야 한다. 이때, main 메서드가 있는 클래스는 무조건 public 클래스로 접근제어자를 생략하더라도 public으로 인식된다.

#### 그 외

##### `static`

##### `final`

final 클래스는 상속될 수 없고 final 메서드는 오버라이딩을 통해 재정의 될 수 없다.

java에서는 final 멤버변수도 생성자에서 다른 변수처럼 초기화 하는 것이 가능하다.

##### `abstract`

추상클래스, 추상메서드를 선언하는데 사용된다.

> 이 밖에도 native, transient, synchronized, volatile, strictfp 제어자가 있다.

클래스의 제어자



#### 주의할 점

1. 메서드에 `static`와 `abstract`를 함께 사용할 수 없다.
2. 클래스에 `abstract`와 `final`을 동시에 사용할 수 없다.
3. `abstract`메서드의 접근 제어자가 `private` 일 수 없다.
4. 메서드에 `private`과 `final`을 같이 사용할 필요는 없다.



### j. 다형성

부모클래스 타입의 참조변수로 자식클래스의 인스턴스를 참조할 수 있다.

단, 부모클래스로부터 상속받은 멤버만 사용할 수 있다.

> 메서드의 경우 참조변수의 타입에 관계없이 실제 인스턴스의 메서드가 호출된다.
>
> static 메서드는 참조변수의 타입에 영향을 받기 때문에 '클래스명.메서드()'로 호출해야한다.
>
> 이름이 중복되는 멤버변수의 경우 참조변수의 타입에 따라 달라진다. 따라서 매개변수는 private으로 접근을 제어하고 public 메서드에서 super, this를 활용해서 나타내는 것이 일반적이다.

#### 형변한

`업캐스팅` 자식 -> 부모 (형변환 생략가능)

`다운캐스팅` 부모 -> 자식 (형변환 생략불가)

```
이때 참조변수의 타입이 변환되는 것이지 인스턴스 자체에는 아무런 영향을 미치지 않는다.
```

또한, 부모타입의 인스턴스를 자식타입의 참조변수를 참조하는 것은 허용되지 않기 때문에 실행 시 오류가 난다.

( 자식타입의 인스턴스를 부모타입의 참조변수로 참조하고 있을때, 형 변환을 통해 자식타입의 참조변수에 부모타입의 참조변수를 대입하는 것은 가능하다.)

#### instanceof 연산자

참조변수가 참조하고 있는 인스턴스의 실제 타입을 알아보기 위한 연산자

```
참조변수 instanceof 타입명  // return값 true, false
```

실제 인스턴스와 같은 타입뿐만 아니라 해당 인스턴스의 부모타입 instanceof 연산에도 true를 반환한다.

-> instanceof 연산 결과가 true인 타입으로 형변환을 해도 아무 문제가 없다.

```java
// 다형성을 이용해서 자식타입의 인스턴스들을 부모타입의 참조변수로 묶어서 처리하는 것이 가능하다.
class Product {
    int price;
    Product(int price) { this.price = price; }
}
class TV extends Product {
    TV() { super(10); }
}
class PC extends Product {
    PC() { super(20); }
}

Class Consumer {
    int money = 100;
    int count = 0;
    void buy(Product p) {
		if(money >= p.price) {
            money -= p.price;
            count++;
        }
    }
}

// 또한 조상타입의 참조변수로 자손타입의 객체를 참조하는 것이 가능하므로, 여러 종류의 객체를 공통 조상으로 묶어서 하나의 배열로 다루는 것이 가능하다.
Product p[] = new Product[10];
p[0] = new TV();
p[1] = new PC();
```

Object 타입 참조변수를 사용하면 모든 타입의 인스턴스를 처리할 수 있다.



### k. 추상화

기존의 클래스의 공통부분을 뽑아내서 조상 클래스를 만드는 것.

(공통조상을 통해 여러 객체들을 하나의 배열로 관리할 수 있다.)

상속의 반대라고 생각해도 무방할 것 같다.

#### 추상클래스

추상 메서드를 가지고 있는 클래스. 인스턴스를 생성할 수 없다.

추상메서드가 없더라도 인스턴스 생성을 방지하기 위해 추상클래스를 사용하는 경우도 있다.

#### 추상메서드

미완성 메서드

```java
abstract 리턴타입 메서드이름();
// 추상 메서드는 구현부가 없으므로 {}대신 ;을 뒤에 붙여 문장의 끝을 나타낸다.
```

추상메서드를 사용하지 않고 구현부가 비어있는 메서드를 사용해도 되지만

추상메서드를 사용하는 경우 상속받은 자식클래스에서 오버라이딩 하지 않는다면 오류가 나기 때문에 실수를 줄일 수 있다.

추상메서드는 자식클래스가 자신의 클래스에 알맞게 반드시 구현해야한다는 의미가 담겨있는 것이기도 하다.

### l. 인터페이스

일종의 추상클래스. 하지만 추상화 정도가 높아서 오직 추상메서드와 상수만을 멤버로 가질 수 있다. 따라서 인터페이스명으로 able을 붙이는 경우가 많다. 또한 `class` 대신 `interface` 키워드를 사용하며 클래스와 다르게 취급한다.

```java
interface 인터페이스이름 {
    int a = 10;  // public static final int a = 10;
    // 모든 변수는 제어자로 public static final을 사용해야 하고, 따라서 이를 생략할수도 있다. 생략된 경우 컴파일러가 자동으로 추가해준다.

    void func();  // public abstract void func();
    // 모든 메서드는 제어자로 public abstract를 사용해야 하고, 변수와 마찬가지로 생략할 수 있다.
   	// 제어자를 생략한 경우도 마찬가지로 오버라이딩을 할때 접근제어자를 public으로 사용해야 하는 점에 주의하자.
}
```

#### 상속

인터페이스로부터만 상속받을 수 있으며 클래스와는 달리 다중상속이 가능하다. 하지만 거의 사용하지 않는다.

```java
interface C extends A, B {
    
}
```

보통 두 개의 클래스로부터 상속받아야하는 경우, 비중이 더 높은 클래스를 부모 클래스로 상속받고 다른 클래스를 멤버변수로 포함시키는 것이 일반적이다.

이때 멤버변수로 포함되는 클래스의 메서드를 가지고 있는 인터페이스를 만들고 구현을 받아서 사용하면 다형성도 이용할 수 있고 편리하다.

```java
class A { }
class B { }
interface IB { }

class C extends A implements IB {
    
}
```

#### 구현

```java
class 클래스명 implements 인터페이스명 {
    
}
```

상속과 구현을 동시에 하는 것 또한 가능하다.

```java
class 클래스명 extends 부모클래스명 implements 인터페이스명 {
    
}
```

#### 다형성

클래스처럼 인터페이스 타입 참조변수로 해당 인터페이스를 구현한 클래스들을 참조하는 것이 가능하다.

따라서 매개변수 타입, 리턴타입으로 인터페이스의 타입을 지정하는 것 또한 가능하다. (한 메서드에서 동일한 인터페이스를 구현한 다양한 종류의 클래스들을 리턴할 수 있다.)

또한, 인터페이스 타입의 참조변수로도 Object 클래스에 정의된 메서드를 호출할 수 있다.

#### 장점 

* ##### 실제 구현에 독립적인 프로그래밍이 가능하다

  예를 들어 자바에서 제공하고 있는 데이터베이스와 관련된 인터페이스를 사용하면 특정 데이터베이스에 종속되지 않는 프로그램을 제작할 수 있다.

* ##### 부모클래스가 다른 클래스들간의 관계를 형성할 수 있다

  부모클래스는 다르지만 같은 속성을 가지고 있는 자식클래스, 부모 클래스는 같지만 다른 속성을 가지고 있는 자식클래스들을 손쉽게 묶어서 처리할 수 있다.

  상속과 구현이 동시에 가능한 점, 인터페이스의 다형성을 이용한다.

#### static, 디폴트 메서드

JDK 1.8부터 인터페이스에서 추상 메서드 외에도 static, 디폴트 메서드를 선언하는 것이 가능해졌다.

* static 메서드

  인스턴스와 독립적이라 사용하는데 문제는 없지만 자바의 규칙을 단순화하기 위해서 사용할 수 없었다.

  따라서 별도의 클래스에 인스턴스와 관련된 static 메서드를 선언해야 했는데 대표적으로 java.util.Collection인터페이스의 static 메서드는 Collections라는 별도의 클래스를 통해 관리한다.

  ```java
  public static void function() {
      
  }
  // 접근 지정자로 public을 사용하며 생략 가능하다.
  ```

* 디폴트 메서드

  클래스와 달리 인터페이스의 경우 메서드를 추후에 추가하면 해당 인터페이스를 구현한 모든 클래스에 대해 해당 메서드를 추가적으로 구현해주어야 하는데 이때 구현하지 않을 경우 기본적으로 적용되는 메서드를 선언할 수 있게 되었다.

  앞에 default를 붙여 사용한다.

  ```java
  public default void function() {
      
  }
  // 접근 지정자로 public을 사용하며 생략 가능하다.
  ```




### m. 내부 클래스

외부에 불필요한 클래스를 감춤으로써 코드의 복잡성을 줄일 수 있다(캡슐화)

변수처럼 선언위치에 따라 `인스턴스`, `스태틱`, `지역` 내부 클래스로 나뉘며 변수와 동일한 유효범위와 접근성을 갖는다.

추가로 `익명` 내부 클래스는 선언과 객체의 생성을 동시에 하는 클래스이다.

#### static

내부 클래스의 경우 외부 클래스가 선언되어야 생성되므로 static 클래스가 아니면 static 멤버를 가질 수 없다.

final static 변수는 기본적으로 상수이기 때문에 모든 내부 클래스에서 정의할 수 있다.

지역 클래스는 해당 메서드의 지역변수의 값을 변경할 수 없다. 왜냐하면 메서드가 수행을 마친 후 지역 클래스의 인스턴스가 소멸된 지역변수를 참조하려는 경우가 발생할 수 있기 때문이다.

지역 클래스가 참조하는 지역 변수는 final이 붙지 않더라도 상수로 간주된다.

> 뒤에서 나오는 람다식도 마찬가지다.

#### 컴파일 - 클래스 파일명

`외부클래스명$내부클래스명.class`

지역내부 클래스의 경우 다른 메서드에 같은 이름의 내부클래스가 존재할 수 있기 때문에 내부 클래스명 앞에 숫자가 붙는다.

`외부클래스명$1내부클래스명.class`

#### 외부클래스명.this

내부 클래스에서 외부 클래스의 지역변수를 참조하는 방법.

#### 익명 클래스

선언과 객체를 동시에 하는 오직 하나의 객체만을 생성할 수 있는 일회용 클래스.

상속할 부모클래스나 구현할 인터페이스를 한가지 사용하여 정의한다.

```java
new 부모클래스명/인터페이스명 () {
    
}
```

이름이 없기 때문에 익명 내부 클래스의 경우 `외부클래스명$숫자.class`의 형태로 클래스 파일명이 결정된다.

> 보통 일회용으로 사용되는 클래스를 익명 클래스로 변경해서 사용하는 것 같다.



## 09 예외처리

### 오류의 종류

컴파일, 런타임, 논리적 오류

그 중 실행시 발생할 수 있는 오류를 에러, 예외로 구분한다.

#### 에러

`OutOfMemoryError`나 `StackOverflowError`와 같이 일단 발생하면 복구할 수 없는 심각한 오류

#### 예외

발생하더라도 수습될 수 있는 비교적 덜 심각한 것.

프로그램의 비정상 종료를 막고 정상적인 실행상태를 유지하기 위해 보통 프로그래머가 미리 예외처리를 해준다.

java에서는 실행 시 발생할 수 있는 오류들을 클래스로 정의했다. 따라서 Exception와 Error 클래스 역시 Object 클래스의 자식클래스다.

```
Object > Throwable > Exception, Error
```

모든 예외의 최고 조상은 Exception 클래스.

### unchecked Exception

주로 프로그래머의 실수에 의해서 발생할 수 있는 예외. 프로그래밍 요소들과 관계가 깊다.

컴파일러가 예외처리를 확인하지 않는다.

ArrayIndexOutOfBoundsException 등의 클래스들이 있고 RuntimeException 클래스를 공통조상으로 갖는다.

### checked Exception

컴파일러가 예외처리를 확인하기 때문에 예외처리를 필수로 해야 한다.

프로그램 사용자들의 동작에 의해서 발생하는 경우가 많다.

IOException, ClassNotFoundException 등이 있다.

### try-catch문

```java
try {
    // 예외가 발생할 가능성이 있는 문장들
} catch (ArithmeticException e) {
    // 예외가 발생했을 경우, 예외를 처리하기 위한 문장들
} catch (Exception e) {
    // 1개 이상의 catch 블럭이 있을 수 있다.
}
```

예외가 발생하면 첫번째 catch 블럭부터 괄호 내에 선언된 참조변수의 종류와 발생한 예외에 instaceof 연산자를 이용해서 검사하고 동일하면 해당 catch문을 실행한다.

모든 예외의 최고 조상인 Exception 클래스를 사용하면 모든 예외에 대해서 해당 catch 문이 실행되도록 할 수 있다.

#### printStackTrace(), getMessage()

catch 블럭의 괄호에 선언된 참조변수를 통해 생성된 예외 클래스의 인스턴스에 접근할 수 있다.

```java
catch (Exception e) {
	// 예외발생 당시의 Call Stack에 있었던 메서드의 정보와 예외 메시지.
    println(e.printStackTrace());
    
    // 발생한 예외클래스의 인스턴스에 저장된 메시지.
	println("예외메시지 : " + e.getMessage());
}
```

#### 멀티 catch 블럭

```java
try {
} catch (ExceptionA | ExceptionB e) {
    
}
```

JDK 1.7부터 `|`로 여러 예외 클래스를 묶어서 사용할 수 있다.

단, 예외 클래스가 상속 관계에 있을 경우 에러가 난다.

그리고 예외 클래스의 공통 조상에 선언된 메서드만 사용할 수 있다.

(앞에서 배웠던 상속을 생각해보면 이유를 쉽게 알 수 있을 것이다.)

#### finally

try-catch 문의 끝에 선택적으로 덧붙여 사용할 수 있는 코드

예외 발생여부에 관계없이 실행되는 부분이다.

```java
try {
    return;
} catch (Exception e) {
    
} finally {
    
}
```

참고로 try나 catch 문 안에서 해당 메서드를 종료하는 부분이 있더라도 메서드가 종료되기 전에 finally 문이 실행된다.

> finally 블럭 내에서 retrun문을 사용할 경우 try블럭이나 catch블럭의 return 문 다음에 수행되기 때문에 최종적으로 fianlly 블럭 내의 return 문의 값이 반환된다.

### 예외 발생시키기 - throw

```java
Exception e = new Exception("에러 메시지");
throw e;
```

### 메서드에 예외 선언

메서드의 선언부에 키워드 throws를 사용해서 메서드 내에 발생할 수 있는 예외를 적어준다.

```java
void method() throws ExceptionA, ExceptionB, ... {
    
}
```

해당 메서드에 예외를 선언하면 해당 메서드에서 예외를 처리하지 않아도 된다. 단, 언젠가는 반드시 해당 예외가 처리되어야 한다.

보통 RuntimeException클래스들은 적지 않고 반드시 처리해주어야 하는 예외들만 선언해준다.

### try-with-resources

자동 자원 반환

```java
try (FileInputStream fis = new FileInputStream("sample.txt");
    DataInputStream dis = new DataInputStream(fis)) {
    
} catch (EOFException e) {
    
} catch (IOException e) {
    
}
```

try블럭의 괄호 안에 객체를 생성하는 문장을 넣으면, try블럭을 벗어나는 순간 해당 객체의 close()가 자동으로 호출된다.

단, AutoCloseable 인터페이스를 구현한 클래스의 객체만 자동으로 close()가 호출될 수 있다.

이미 예외가 발생하고 close()에서 예외가 발생한 경우 close()에서 발생한 예외를 억제된 예외로 다룬다. 억제된 예외는 실제 발생된 예외에 저장되어 관리된다.

>  두 예외가 동시에 발생할 수 없기 때문에 try-catch 문의 경우 먼저 발생한 예외는 무시된다.
>
> Throwable 인터페이스에 억제된 예외와 관련된 메소드가 정의되어 있다.

### 사용자정의 예외

기존 예외 클래스를 상속받아 사용자정의 예외를 만들 수 있다.

```java
class MyException extends Exception {
    MyException (String msg) {
        super(msg);
    }
}
```

보통 예외처리를 선택적으로 할 수 있도록 RuntimeException을 상속받아서 unchecked Exception으로 만든다.

> Exception을 상속받아서 checked예외를 만들어서 사용하면 예외처리가 불필요한 경우에도 예외 처리를 해야되서 코드가 복잡해질수있다.

### exception re-throwing

예외를 처리한 후에 인위적으로 다시 발생시키는 방법

하나의 예외에 대해서 예외가 발생한 메서드와 이를 호출한 메서드 양쪽 모두에서 처리해줘야 할 작업이 있을 때 사용된다.

```java
class Ex {
    public static void main(String[] args) {
        try {
            method();
        } catch (Exception e) {
            
        }
    }
    
    static void method() throws Exception {
        try {
            throw new Exception();
        } catch (Exception e) {
            // 예외처리 후 다시 발생.
            throw e;
        }
    }
}
```

예외 되던지기를 하는 경우, catch 블럭 내에 retrun 문이 없어도 된다.

### chained exception

한 예외가 다른 예외를 발생시키는 경우

```java
try {
    
} catch (Exception_A ae) {
    Exception_C ce = new Exception_C("발생된 예외");
    ce.initCause(ae);  // 원인 예외 지정
    throw ce;
} catch (Exception_B be) {
    Exception_C ce = new Exception_C("발생된 예외");
    ce.initCause(be);  // 원인 예외 지정
    throw ce;
}
```

Exception 클래스의 조상인 Throwable 클래스에 정의되어 있는 관련 메서드

* 원인 예외 지정 - Throwable initCause (Throwable cause)
* 원인 예외 반환 - Throwable getCause()

#### 사용하는 이유

1. 여러가지 예외를 하나의 예외로 묶어서 다루기 위해서

   > 공통 조상 클래스로 묶기에는 상속관계를 변경해야 해서 불편하다.

2. checked 예외를 unchecked 예외로 바꾸기 위해서

   ```java
   throw new RuntimeException(new Exception("원인 예외"));
   ```

   > 참고로 RuntimeException의 생성자를 이용해서 원인 예외를 등록할 수 있다.

## 10 java.lang package

가장 기본이 되는 패키지. import문 없이 사용할 수 있다.

### Object 클래스

#### 주요메서드

##### equals(Object obj)

> equals도 == 연산자와 마찬가지로 객체의 값을 비교할 때 주소값을 비교한다.
>
> 하지만 equals는 메서드이기 때문에 오버라이딩이 가능하다는 차이점이 있다.
>
> String 클래스의 equals()는 주소값이 아닌 실제 값을 비교하도록 오버라이딩이 되어있다.

##### hashcode()

> 해시함수를 구현한 것. 객체의 주소에 따라 해시코드를 만들어 반환한다.
>
> 경우에 따라 오버라이딩해서 사용한다. (ex. 주소가 아닌 객체의 값으로 객체를 비교하는 경우)

##### toString()

> 인스턴스에 대한 정보를 문자열로 제공
>
> ```java
> public String toString() {
>     // 기본적으로 정의된 내용
>     return getClass().getName()+"@"+Integer.toHexString(hashCode());
> }
> ```
>
> 일반적으로 객체의 값에 맞게 오버라이딩해서 사용한다.

##### clone()

> 자신을 복제하여 새로운 인스턴스 생성.
>
> 기본적으로 얕은 복사로 구현되어 있기 때문에 깊은 복사가 필요한 경우 오버라이딩해서 사용한다. 대표적으로 배열의 clone()
>
> ```
> 얕은 복사 : 단순히 객체의 참조변수가 갖는 주소값 복사 -> 같은 객체를 가리킴.
> 깊은 복사 : 객체의 값을 복사해서 새로운 객체 생성 -> 다른 객체를 가리킴.
> ```
>
> Cloneable 인터페이스를 구현해야 한다. (해당 클래스의 복제를 허용한다는 의미)
>
> ```java
> public class Object {
>     protected native Object clone() throws CloneNotSupportedException;
> }
> ```
>
> 반드시 예외처리를 해주어야 하고, 보통 공변 반환타입을 사용한다.
>
> ```java
> class Ex implements Cloneable {
>     MyClass m;
>     int a;
>     
>     // 생성자 등 ...
>     
>     public Ex clone() {
>         Object obj = null;
>         try {
>             obj = super.clone();
>         } catch (CloneNotSupportedException e) {}
>         
>         // 깊은 복사
>  		Ex e = (Ex)obj;
>         e.m = MyClass(this.m);
>     }
> }
> ```

##### getClass()

> 해당 클래스의 Class 객체 반환
>
> ##### Class 객체
>
> > 클래스의 모든 정보를 담고 있는 객체. 클래스가 메모리에 로드될때 Class 객체로 저장된다고 생각하면 될 것 같다.



### wrapper 클래스

기본형 값을 객체로 다루기 위한 클래스.

> Boolean, Character, Byte, Short, Integer, Long, Float, Double

큰 범위의 정수와 부동 소수점값을 다루기 위한 클래스

> BigInteger, BigDecimal

#### 메서드

* equals()

* compareTo()

* 문자열 숫자로 변환

  * wrapper클래스.parse자료형(String s)

    > Integer.parseInt("100")

  * wrapper클래스.valueOf(String s)

    > 반환값이 wrapper클래스이다.
    >
    > 오토박싱에 의해 기본형으로 변환되야 하기 때문에 parse타입보다 성능이 조금 느리다.

    ```java
    int a1 = Integer.parseInt("100");
    int a2 = Integer.valueOf("100");  // 오토박싱에 의해 wrapper class -> 기본형으로 자동 변환된다.
    
    int c = Integer.parseInt("FF", 16);  // 10진수가 아닌 다른 진법의 숫자도 변환이 가능하다.
    
    // 정수형 외에도 동일하다.
    boolean b1 = Boolean.parseBoolean("true");
    boolean b2 = Boolean.valueOf("true");
    ```

#### static 상수

* MAX_VALUE
* MIN_VALUE
* SIZE
* BYTES
* TYPE

#### Number 클래스

추상클래스. Boolean, Character를 제외한 wrapper 클래스들의 조상클래스.

#### 오토박싱 & 언박싱

`오토박싱`: 기본형 값을 래퍼 클래스의 객체로 자동 변환해주는 것

`언박싱`: 오토박싱의 반대

컴파일러가 자동으로 추가해준다.



### String 클래스

char 배열 + 기능(메서드)

이때 String 객체는 내용을 변경할 수 없다. 따라서 문자열을 다루는 작업이 많은 경우에는 StringBuffer를 사용한다.

```java
String s1 = new String("abc");
String s2 = "abc";  // 객체 중 String만 new를 사용하지 않고 간단하게 객체생성 가능.
// 단순히 new 연산자를 생략하고 사용할 수 있는것인줄 알았는데 문자열 리터럴을 참조하는 것이다.
// 따라서 엄밀히 얘기하면 new 연산자를 사용하는 것과 다르다.
// 아래의 예시를 통해서 확인할 수 있다.
String s3 = "abc";
System.out.println(s1 == s3);  // false.
System.out.println(s2 == s3);  // true. 같은 문자열 리터럴을 참조하고 있다.
```

#### 문자열 리터럴

자바 소스파일에 포함된 문자열 리터럴들은 컴파일 시에 클래스 파일에 저장된다.

따라서 기본적으로 문자열 리터럴도 String 인스턴스이다.

#### 빈 문자열

`String s = ""`는 내부적으로 길이가 0인 char형 배열을 저장하고 있다.

#### 생성자

* String(String s)
* String(char[] value)
* String(StringBuffer buf)

#### 메서드

* char charAt(int index)

  > C++과는 달리 괄호연산자 `[]`를 기본적으로 지원하지 않는다.

* int compareTo(String str)

* String concat(String str)

* boolean contains(CharSequence s)

  > CharSequence는 String의 subclass. 따라서 String을 매개변수로 사용하는 것이 가능하다.

* boolean endsWith(String suffix)

* boolean equals(Object obj)

* boolean equalsIgnoreCase(Object obj)

* int indexOf(int ch)

  > 확장된 유니코드를 다루기 위해서 int형 매개변수를 사용한다.

* int indexOf(int ch, int pos)

* int indexOf(String str)

* String intern()

* int lastIndexOf(int ch)

* int lastIndexOf(String str)

* int length()

  > 일반적인 배열처럼 length 멤버변수를 갖지 않고
  >
  > length() 메서드를 갖는다.

* String replace(char old, char new)

* String replace(CharSequence old, CharSequence new)

* String replaceAll(String regex, String replacement)

* String replaceFirst(String regex, String replacement)

  > replace와 replaceAll의 차이점 : `regex`(정규식) 사용 유무
  >
  > https://stackoverflow.com/questions/10827872/difference-between-string-replace-and-replaceall

* String[] split(String regex)

* String[] split(String regex, int limit)

* boolean startsWith(String prefix)

* String substring(int begin)

* String substring(int begin, int end)

  > end는 범위에 포함되지 않는다.

* String toLowerCase()

* String toUpperCase()

* String toString()

* String trim()

  > 양 옆에 있는 공백을 제거한 결과값 반환

* char[] toCharArray()

##### 문자열 결합

* String.join()

  ```java
  String[] arr = {"10", "20", "30"};
  String str = String.join(", ", arr); // 10, 20, 30
  String str2 = String.join(", ", arr[0], arr[1], arr[2]);
  ```

* java.util.StringJoiner 클래스

  ```java
  StringJoiner sj = new StringJoiner(",", "[", "]");
  String[] arr = {"10", "20", "30"};
  for(String a : arr)
      sj.add(a);
  System.out.println(sj.toString()); // [10,20,30]
  ```

##### 문자 인코딩 변환

```java
byte[] utf8_str = "가".getBytes("UTF-8");
String str = new String(utf_str, "UTF-8");
```

##### String.format()

형식화된 문자열 생성. printf문과 사용법이 동일하다.

```java
String str = String.format("%d + %d = %d", 3, 5, 3+5);
```

##### 기본형 -> String

* 숫자 + 빈문자열
* String.valueOf()

```java
int a = 100;
String s1 = a+"";
String s2 = String.valueOf(a);
```

##### String -> 기본형

wrapper 클래스 메서드 사용

* parse자료형(String s)
* valueOf(String s)

문자열을 숫자로 변환할때 예외(NumberFormat Exception)이 발생하기 쉬우므로 주의해야 한다.

### StringBuffer 클래스

내부적으로 문자열편집을 위한 공간(buffer)을 가지고 있어 문자열 편집이 가능하다.

이때 buffer로 배열을 사용하기 때문에 처음 인스턴스를 생성할때 생성자에 충분한 길이를 넣어주는 것이 좋다.

> 배열의 길이를 변경하기 위해선 배열을 새로 생성하고 기존 값을 복사해서 넣는 과정을 거쳐야 하기 때문에 비효율적이다.

#### 생성자

* StringBuffer()
* StringBuffer(int length)
* StringBuffer(String str)

```java
public StringBuffer(int length) {
    value = new char[length];
    shared = false;
}
public StringBuffer() {
    this(16);
}
public StringBuffer(String str) {
    this(str.length() + 16);
    append(str);
}
```

#### 메서드

* StringBuffer append(boolean b), StringBuffer append(String str), ...

  > 매개변수로 입력된 값을 문자열로 변환하여 buffer 뒤에 추가한다.
  >
  > 자신의 주소를 반환하기 때문에 연속적인 호출이 가능하다.
  >
  > ```java
  > StringBuffer sb = new StringBuffer("abc");
  > sb.append("123").append("abc");  // abc123abc
  > ```

* StringBuffer insert(int pos, boolean b), ...

* StringBuffer replace(int start, int end, String str)

* void setCharAt(int index, char ch)

* StringBuffer delete(int start, int end)

* StringBuffer deleteCharAt(int index)

* StringBuffer reverse()

* int capacity()

  > 버퍼 크기

* int length()

  > 버퍼에 담긴 문자열의 길이

* void setLength(int newLength)

  > 길이를 늘리는 경우 나머지 공간을 널문자로 채운다.

* char charAt(int index)

* String toString()

* String substring(int start)

* String substring(int start, int end)

#### StringBuffer 비교

String처럼 equals()가 오버라이딩 되어있지 않다. 따라서 실제 내용을 비교하기 위해선 String으로 형변환을 하고 equals() 메서드를 이용해야 한다.

#### StringBuilder

StringBuffer에서 쓰레드의 동기화만 뺀 클래스.

StringBuffer는 멀티쓰레드에 안전하도록 동기화되어 있지만, 동기화로 인해 성능이 떨어진다. 따라서 멀티쓰레드로 작성된 프로그램이 아닌 경우 StringBuffer 대신 StringBuilder를 사용하는 것이 좋다.

다만, StringBuffer도 충분히 성능이 좋기 때문에 성능향상이 필요한 경우에만 교체하면 된다.

### Math 클래스

클래스 내에 정적 메서드와 2개의 상수밖에 없다. 생성자의 접근 제어자도 private이다.

#### 상수

> E - 자연로그
>
> PI - 원주율

#### 메서드

> abs(절대값), ceil(올림), floor(버림), round(반올림), rint
>
> ```
> round - 소수점 첫째자리에서 반올림한 정수값 반환
> 
> n번째 자리에서 반올림을 하고 싶다면, 10의 n-1제곱으로 곱해주고 반올림한 뒤 다시 나눠주면 된다.
> 
> ex) 둘째자리 반올림
> round(n*10)/10.0
> ```
>
> ```
> // rint - 주어진 값과 가장 가까운 정수값 double 형으로 반환
> 
> rint(2.5) = 2
> round(2.5) = 3
> 
> rint(-1.5) = -2
> rint(-1.5) = -1
> ```
>
> min, max
>
> random - 0.0~1.0 사이의 값 리턴

#### 삼각함수, 지수, 로그 관련 메서드

> sqrt, pow, log, log10, sin, asin, toRadians, ...
>
> atan2 - 직각삼각형에서 두 변의 길이를 입력하면 끼인각을 return

#### 예외를 발생시키는 메서드 - 오버플로우 체크

오버플로우가 발생하면 `ArithmeticException`을 발생시킨다.

>  addExact, subtractExact, ...

#### StrictMath 클래스

OS 의존성을 제거한 대신 성능이 조금 저하된 Math클래스



### 기타 유용한 클래스

#### java.util.Objects

##### static 메서드

###### isNull, nonNull

###### requireNonNull

> 매개변수 유효성 검사를 간편하게 할 수 있다.

###### compare

> 두 객체의 비교기준으로  Comparator를 매개변수로 전달받아 사용한다

###### equals, toString, hashCode

> Object클래스의 메서드 + null 검사
>
> 추가 기능
>
> * 둘 다 null일때도 참이 반환된다.
>
> * 널일때 대신 사용할 값을 지정할 수 있다.
> * 널일때는 0을 반환한다.

###### deepEquals

> 객체를 재귀적으로 비교 -> 다차원 배열도 비교가 가능하다.



#### java.util.Random

Math.random()는 내부적으로 이 클래스의 인스턴스를 생성해서 사용한다.

기본적으로 seed 값은 System.currentTimeMillis()이 사용되고 변경할 수 있다.

> Random(), Random(long seed)
>
> new Random().nextInt(6);
>
> new Random().nextDouble();
>
> ...



#### java.util.regex패키지 - 정규식

Patter 인스턴스를 생성해 정규식을 정의하고 Matcher 인스턴스로 정규식을 데이터와 비교한다.

정규식은 https://regexone.com/ 참고

> String[] data = {"cat", ... };
>
> Pattern p = Patter.compile("c[a-z]*");
>
> Matcher m = p.matcher(data[i]);

##### Matcher 메서드

> **m.matches()** - 정규식과 매칭되는 부분이 있는지 체크
>
> **m.find()**
>
> **m.group(int i)** - 그룹 반환. group(0)이나 group()은 매칭된 부분 전체 반환
>
> **m.start()** - 정규식과 매칭된 부분 시작점
>
> **m.end()** - 다음 m.find() 시작점
>
> **m.appendReplacement(sb, s)** - m.find() 시작점부터 m.start()전까지 StringBuffer sb에 저장후 sb에 String s를 덧붙인다.
>
> **m.appendTail(sb)** - 마지막으로 치환된 이후의 부분을 sb에 덧붙인다.



#### java.util.Scanner

다양한 생성자를 지원해 String, File, InputStream 등 다양한 곳에서 입력을 받을 수 있다

라인단위의 검색, 구분자에 정규식 표현을 사용할 수 있다.

##### 구분자를 기준으로 문자열 자르는 방법

* String의 `split(String regex)`

* Scanner의 `useDelimiter(String regex)`

  ```java
  Scanner sc = new Scanner(new File("sample.txt"));
  while(sc.hasNextLine()) {
      String line = sc.nextLine();
      Scanner sc2 = new Scanner(line).useDelimiter(" ");
      while(sc2.hasNextInt()) {
          
      }
  }
  ```

* java.util.StringTokenizer클래스

  `split()`은 빈 문자열도 토큰으로 인식하지만 `StringTokenizer`는 빈 문자열을 토큰으로 인식하지 않는다.

  `split()`은 결과값을 배열에 담아 반환하고 `StringTokenizer`는 데이터를 토큰으로 잘라 바로바로 반환하기 때문에 성능은 `split()`이 조금 떨어진다.

##### StringTokenizer 클래스

`StringTokenizer(String str, String delim)`

`StringTokenizer(String str, String delim, boolean returnDelim)`

`int countTokens()`

`boolean hasMoreTokens()`

`String nextToken()`

```java
StringTokenizer st = new StringTokenizer(source, " ");
while(st.hasMoreTokens())
    System.out.println(st.nextToken());
```

이때 구분자로 문자열을 전달하더라도 각각의 문자들을 하나의 구분자로 사용한다. 정규식에서 대괄호라고 생각하면 될거같다. `[abc]`



#### java.math.BigInteger 클래스

wrapper 클래스. 최대 60억 자리까지 표현할 수 있다.

2의 보수를 사용하고, 내부적으로 int 배열을 사용해 값을 다룬다.

> final int signum;
>
> final int[] mag;

##### 생성자

문자열, n진수 문자열, 숫자를 이용해 생성할 수 있다.

> new BigInteger("1231415");

##### 메서드

> 문자열, byte[]로 변환 : toString(), toString(int radix), toByteArray()\
>
> 기본형으로 변환 : intValue(), ..., intValueExact(), ...
>
> 연산 : add(BigInteger val), ...
>
> 연산결과로 새로운 인스턴스가 반환된다.

##### 비트연산메서드

워낙 큰 숫자를 다루다보니 성능을 위해 비트연산을 활용하는 것이 권장된다.

> bitCount(), bitLength()
>
> testBit(int n), setBit(int n), clearBit(int n), flipBit(int n)

#### java.math.BigDecimal 클래스

큰 실수를 저장하기 위한 클래스. 정수 * 10^(-scale) 형태로 값을 표현한다.

정수부분의 값은 BigInteger로 저장한다.

> private final BigInteger intVal;
>
> private final int scale;
>
> private transient int precision;

##### 생성자

문자열, double, int, long을 이용해서 생성할 수 있다.

> new BigDecimal("123.543");

이때 double을 이용해서 생성하면 10진수<->2진수로 변환하는 과정에서 오차가 발생할 수 있다.

##### 메서드

> 문자열로 변환 : toPlainString(), toString()
>
> intValue(), ..., intValueExact(), ...
>
> add(BigDecimal val), ...
>
> 연산결과로 새로운 인스턴스가 반환되고, 연산에 따라 scale, precision 또한 달라질 수 있다.

##### 나눗셈 - 반올림 모드

나눗셈의 경우 오차가 발생할 가능성이 높기 때문에 결과를 어디서 반올림할 것인지 지정할 수 있다.

결과가 무한소수인 경우, 반올림 모드를 지정하지 않으면 오류가 발생한다.

> divide(BigDecimal divisor)
>
> divide(divisor, int roundingMode)
>
> divide(divisor, RoundingMode roundingMode)
>
> divide(divisor, int scale, int roundingMode)
>
> divide(divisor, int scale, RoundingMode roundingMode)
>
> divide(divistor, MathContext mc)

###### 열거형 RoundingMode

>  CEILING, FLOOR, UP, DOWN, HALF_UP, HALF_EVEN, HALF_DOWN, UNNECESSARY

###### MathContext

정밀도(precision) + 반올림 모드

> new MathContext(2, HALF_UP)

이때 scale은 소수점이하만 포함한 자리수, precision은 정수부분까지 모두 포함한 자리수이다.

##### scale 변경 - 10의 거듭제곱 곱셈/나눗셈

10의 거듭제곱으로 나누거나 곱하는 경우 자리수만 변경하면 동일한 결과를 얻을 수 있다.

단, 자리수를 낮추는 경우는 divide()처럼 오류가 날 수 있으므로 반올림 모드를 정해줘야 한다.

> setScale(int newScale)
>
> setScale(int newScale, int roundingMode)
>
> setScale(int newScale, RoundingMode roundingMode)



## 11 Comparator

**String.CASE_INSENSITIVE_ORDER**

> 대소문자 구분 없이 문자비교
>
> String클래스에 상수로 정의되어 있는 Comparator



## 12 지네릭스(Generics)

객체의 타입을 컴파일시 체크 -> 타입 안정성 확보

C++의 템플릿과 비슷

> 기존에 다양한 타입의 객체를 하나의 메서드로 다루려면 Object 등 공통 조상 클래스를 사용해야 했는데, 이때 타입의 안정성을 확보하려면 추가적인 작업이 필요했다. **이를 개선하기 위하여 나온것이 지네릭스**

### 지네릭 타입의 제거

컴파일러는 지네릭 타입을 이용해서 소스파일을 체크하고, 필요한 곳에 형변환을 넣어준뒤 지네릭 타입을 제거한다.

> 목적: 이전의 소스 코드와의 호환성 유지

<T\>의 경우 Object로 치환, <T extends Box\>인 경우 Box로 치환된다. + 타입을 일치하기 위한 형반환

> 타입 변수에 타입이 대입된 후 컴파일이 되는 줄 알았는데 그 이전에 컴파일이 이루어진다. 따라서 원시 타입을 사용해서 코드를 작성하는 것과 결과물은 같다. 하지만 언젠가는 새로운 기능을 위해 원시 타입이 지원되지 않을 가능성이 높으므로 가능하면 원시 타입은 사용하지 않는 것이 좋다.

### 주의사항

* 지네릭 클래스에서 static 멤버에 타입 변수 사용 불가능

  > 지네릭스는 기본적으로 인스턴스별로 동작하도록 만든 기능이라 타입 변수는 인스턴스 변수로 간주된다.

* 타입 변수는 new 연산자(배열), instanceof 연산자 사용불가

  > 컴파일 시 타입이 뭔지 정해져 있지 않기 때문에 오류가 난다.
  >
  > ```java
  > class Sample<T> {
  > T[] arr = new T[5];  // 에러.
  > }
  > ```
  >
  > 지네릭 배열을 생성하기 위해선 Object 배열을 생성해서 복사한 다음 형변환해서 사용하는 방법 등을 사용해야 한다.
  >
  > ```java
  > class Sample<T> {
  > ArrayList<T> list = new ArrayList<T>();
  > }
  > ```
  >
  > 이런 식으로 지네릭 인스턴스를 생성할 때 타입 변수를 사용하는 것은 가능하다.
  >
  > *인스턴스를 생성할때도 컴파일 시 타입이 뭔지 정해져 있지 않기 때문에 오류가 나야된다고 생각했는데 이유를 잘 모르겠다. 타입 변수를 직접적으로 사용하는 것은 불가능하지만 타입 변수를 대입해서 사용하는것은 괜찮은건가?*
  

### 타입변수의 생략

지네릭 클래스의 객체를 생성할때 참조변수와 생성자에 대입된 타입이 일치해야된다.

대입되는 타입은 상속관계이더라도 불가. 지네릭 클래스가 상속관계에 있는것은 괜찮다.

> 대입되는 타입이 상속관계더라도 생성되는 클래스는 상속관계에 있지 않게된다.

```java
Box<Fruit> appleBox = new Box<Apple>(); // X
Box<Apple> appleBox = new FruitBox<Apple>();
```

객체 생성이 완료된 지네릭 클래스의 메서드의 매개변수에는 자식 클래스가 들어갈 수 있다.

```java
Box<Fruit> fruitBox = new Box<Fruit>();
fruitBox.add(new Apple());
```

> 클래스가 생성되면서 지네릭 타입의 제거가 일어나므로 생성된 클래스는 일반적인 클래스와 동일하다.

### 제한된 지네릭 클래스

```java
class Sample<T extends 클래스명> {}
```

```java
class Sample<T extends 인터페이스명> {}
```

```java
class Sample<T extends 클래스명 & 인터페이스명> {}
```

### 와일드카드

지네릭 클래스가 매개변수로 들어가는 경우 지네릭 타입이 다른 것만으로는 오버로딩이 성립하지 않는다.

이때 와일드 카드를 사용하면 대입할 수 있는 타입 변수의 범위를 지정할 수 있다.

```java
class Juicer {
    // static에 타입 변수 사용불가능
    static Juice makeJuice(FruitBox<T> box) {} // X
    // 오버로딩이 아닌 메서드 중복 정의
    static Juice makeJuice(FruitBox<Fruit> box) {}
    static Juice makeJuice(FruitBox<Fruit> box) {} // X
    // 와일드 카드
    static Juice makeJuice(FruitBox<? extends Fruit> box) {}
}
```

```
<?>            제한 없음. = <? extends Object>
<? extends T>  하한 제한. T와 그 자식들만 가능
<? super T>    상한 제한. T와 그 조상들만 가능
```

대표적으로 Comparator는 주로 <? extends T>를 사용한다.

### 지네릭 메서드

메서드 내에서만 사용되는 타입 변수를 정할 수 있다.

```
static <T extends Fruit> Juice makeJuice(FruitBox<T> box) {}
```

호출할때 타입 변수에 타입을 대입해서 사용해야 하지만 대부분의 경우 컴파일러가 타입을 추정할 수 있기 때문에 생략이 가능하다.

```
FruitBox<Fruit> fruitBox = new FruitBox<Fruit>();
System.out.println(Juicer.<Fruit>makeJuice());
System.out.println(Juicer.makeJuice()); // 타입 추정 가능 -> 생략 가능
```

주의: 타입을 생략할 수 없다면 참조변수나 클래스 이름 또한 생략할 수 없다. 

### 형변환

**raw타입 <-> 지네릭 타입**

> raw타입: 타입 변수로 아무것도 넣지 않은 것
>
> 가능하지만 경고발생

**지네릭 타입 <-> 지네릭 타입**

```
<Object> <-> <String>
```

> 불가

**지네릭 타입 <-> 와일드카드**

```
Box<String> -> Box<? extends Object>
```

> 가능. 다형성 확보
>
> <- 도 가능하지만 확인되지 않은 형변환이라는 경고 발생

와일드카드 <-> 와일드카드

```
<? extends String> <-> <? extends Object>
```

> 가능.  미확정타입 형변환 경고



## 13 Annotation





## 14 람다식

메서드를 하나의 식으로 표현한 것. **익명함수**

> 익명 클래스의 객체를 이용해서 표현한다.

람다식의 도입으로 자바는 객체지향언어인 동시에 함수형 언어가 되었다.

### 선언형식

이름과 반환타입이 없고, 선언부와 몸통 사이에 ->를 추가한다.

```java
(int a, int b) -> {
    return a > b ? a : b;
}
```

괄호 안의 문장이 하나인 경우

```java
(int a, int b) -> System.out.println(a+b)
```

괄호 안에 return문만 하나 있는 경우

```
(int a, int b) -> a > b ? a : b
```

매개변수의 타입의 추론이 가능한 경우 (대부분의 경우 추론 가능)

```java
(a, b) -> a > b ? a : b
```

이때, 매개변수가 하나 뿐이라면 괄호까지 생략할 수 있다.

```java
a -> a * a
```

### 함수형 인터페이스

람다식과 동등한 메서드가 정의되어 있는 클래스나 인터페이스의 참조변수를 통해 람다식을 참조할 수 있다.

이때, 람다식을 다루기 위한 인터페이스를 `함수형 인터페이스`라고 한다.

> 함수형 인터페이스에는 추상 메서드가 오직 하나만 존재할 수 있다.

#### 형변환

람다식은 오직 `함수형 인터페이스`로 형변환을 할 수 있고 이는 생략 가능하다.

> 일반적인 익명 클래스와 달리 객체의 타입이 `외부클래스이름$$Lamda$번호`로 생성된다.

`@FunctionalInterface`

> annotation. 컴파일러가 함수형 인터페이스를 올바르게 정의하였는지 확인해준다.

```java
@FunctionalInterface
interface Ex {
    public abstract int max(int a, int b);
}
Ex f = (int a, int b) -> a > b ? a : b;
```

### 변수처럼 메서드 사용 가능

`함수형 인터페이스`와 `람다식`을 이용해서 함수를 변수처럼 다루는 것이 가능해졌다.

> 실제로는 익명 객체를 전달하는 것이긴 하지만 코드가 훨씬 간결하고 이해하기 쉬워졌다.

1. 클래스없이 메서드 사용 가능

2. 매개변수로 메서드 전달 가능

```
Collections.sort(list, new Comparator<String>() {
    public int compare(String s1, String s2) {
        return s2.compareTo(s1);
    }
})
```

이러한 식을 람다식을 사용하면 더 간단하게 바꿀 수 있다.

```java
Collections.sort(list, (s1, s2) -> s2.compareTo(s1))
```

### 외부 변수 참조 규칙

1. 익명 클래스처럼 참조하는 지역변수는 상수로 간주된다.
2. 외부 지역변수와 같은 이름의 람다식 매개변수를 사용할 수 없다.

### java.util.function 패키지

자주 쓰이는 형식의 메서드를 정의해 놓은 함수형 인터페이스

> Function<T, R> - R apply(T t)
>
> Predicate<T> - boolean test(T t)
>
> ....
>
> ```java
> Predicate<String> isEmptyStr = s -> s.length() == 0;
> if(isEmptyStr.test(s))
> ```

직접 만들어서 사용할 수도 있다.

```java
@FunctionalInterface
interface MyFunction<T, U, V, R> {
    R apply(T t, U u, V v);
}
```

#### UnaryOperator, BinaryOperator

Function 함수형 인터페이스의 변형으로 매개변수와 타입이 모두 일치한다.

#### 컬렉션 프레임워크 인터페이스

컬렉션 프레임워크 인터페이스의 디폴트 메서드들 중 함수형 인터페이스를 매개변수로 사용하는 것들이 있다.

> Map - void forEach(BiConsumer<k, B> action), ...
>
> ```java
> Map<String, String> map = new HashMap<>();
> map.forEach((k,v)->System.out.println(k + ", " + v));
> ```

#### 기본형을 사용하는 함수형 인터페이스

Wrapper 클래스 대신 기본형을 사용하는 함수형 인터페이스. 성능 개선.

> AToBFunction, ToBFunction, AFunction,ObjAFunction, ...
>
> ```java
> IntUnaryOperator op = i -> i/10*10;
> // 타입이 정해져있으므로 i/10*10과 같은 연산이 가능
> ```
>

#### 디폴트 메서드, static 메서드

* Function의 합성

  > andThen, compose, identity
  >
  > ```
  > default <V> Function<T, V> andThen(Function<? super R, ? extends V> after)
  > ```
  >
  > ....

* Predicate의 결합

  > and, or, negate, isEqual
  >
  > ```
  > static <T> Predicate<T> isEqual(Object targetRef)
  > ```
  >
  > ....

* ....

### 메서드 참조

람다식이 하나의 메서드만 호출하는 경우 더 간단히 표현하는 방법

람다식을 마치 static 변수처럼 다룰 수 있어 코드를 간략화 할때 유용하다.

* static 메서드 참조

  ```java
  클래스명::메서드명
  ```

* 인스턴스메서드 참조

  ```java
  클래스명::메서드명
  ```

* 특정 객체 인스턴스메서드 참조

  ```ㅓㅁㅍㅁ
  참조변수::메서드명
  ```

#### 생성자의 메서드 참조

```java
클래스명::new
```

매개변수가 있는 생성자라면 매개변수에 따라 알맞은 함수형 인터페이스를 사용한다. 필요에 따라 새로 정의해서 사용한다.



## 스트림





## # 자료구조

### Vector 클래스

동적으로 크기가 관리되는 객체배열

* Vector()

* boolean add(Object o)

* boolean remove(Object o)

* boolean isEmpty()

* Object get(int index)

* int size()

* Collections.reverse(Vector v)

  > 순서 뒤집기

* Collections.sort(Vector v)

  > 정렬하기(오름차순)
  >
  > 내림차순으로 정렬하기 위해선 Comparator 인터페이스를 구현하고 compare method를 override한 클래스를 만들고 클래스의 인스턴스를 두번째 인자로 전달해줘야 한다.

