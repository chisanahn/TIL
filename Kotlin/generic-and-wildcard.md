# Kotlin - generics

kotlin에서 지네릭스를 공부하다가 JAVA에서의 지네릭스와 와일드 카드 개념이 헷갈려서 다시 정리

<br>

## JAVA - 와일드 카드

JAVA의 컴파일 단계에서 지네릭 타입의 타입 안정성을 보장해 주기 위한 개념

```
가장 좋은 오류는 컴파일 오류

- 인프런 김영한님 강의에서 들은 말
```

> 지네릭 타입의 배열을 선언할 수 없는 것도 타입 안정성을 보장하기 위함이다.

Produce, Consume 크게 2가지로 분류할 수 있다.

- Produce

  객체를 받아서 해당 객체에 읽기 연산을 수행하는 경우, 하위 타입의 객체를 받아올 수 있다.

  자바의 와일드 카드에선 `extend` 키워드로 명시해 줄 수 있다.

  ```java
  interface Collection<E> {
      void addAllFrom(Collection<? extends E> items);
  }

  void copyAll(Collection<Object> to, Collection<String> from) {
      to.addAllFrom(from);
  }
  ```

- Consume

  객체를 받아서 해당 객체에 쓰기 연산을 수행하는 경우, 상위 타입의 객체를 받아올 수 있다.

  자바의 와일드 카드에서는 `super` 키워드를 통해 명시해 줄 수 있다.

  ```java
  interface Collection<E> {
      void addAllTo(Collection<? super E> items);
  }

  void copyAll(Collection<Object> to, Collection<String> from) {
      from.addAllTo(to);
  }
  ```

처음 개념을 접하는 경우 순서가 많이 헷갈리는데, 다음과 같은 다형성을 생각해보면 쉽게 이해가 된다.

```java
String str = "abc";
Object a = str;
System.out.println(a.toString());
```

> 상위 클래스 타입의 참조변수로 하위 객체를 참조할 수 있지만, 반대는 가능하지 않다.

<br>

Kotlin에서는 `in`, `out` 키워드를 통해 타입 안정성을 보장해 준다.

## Declaration-site variance

```kotlin
interface Comparable<in T> {
    operator fun compareTo(other: T): Int
}

fun demo(x: Comparable<Number>) {
    x.compareTo(1.0) // 1.0 has type Double, which is a subtype of Number
    // Thus, you can assign x to a variable of type Comparable<Double>
    val y: Comparable<Double> = x // OK!
}
```

공식문서에 나온 예제를 보고 `y.compareTo()` 안에서 `Number`를 `Double`처럼 사용하기 때문에 `Double` 에는 존재하지 않고 `Double`에서만 존재하는 메서드를 사용한다면 오류가 발생하는게 아닌가? 싶었지만 

잘 생각해보면 잘못 생각했다는 것을 알 수 있다.

- 우선 `x`와 `y` 모두 `Comparable<T>`에서 정의된 메서드만 사용할 수 있기 때문에 `y`에서 `x`에 정의되어 있지 않은 메서드를 호출할 일은 없다.

- y는 x를 가리키는 참조변수에 불과하다. <br> 즉, `y.compareTo()`를 호출한다고 해도 내부적으로는 `x.compareTo()`가 호출되는 것과 동일하다.

- `y.compareTo()`는 매개변수로 `Double` 형을 요구한다. <br> 하지만 `y`가 실제로 가리키는 것은 `Comparable<Number>`타입의 `x`이다. <br> 하지만 `Number`는 `Double`의 상위 클래스이기 때문에 `Double`을 `Number`로 변환해서 사용할 수 있기 때문에 괜찮다.

  - `Number`는 `Double`의 상위 클래스이기 때문에 `Comparable<Number>`의 구현체에서 `compareTo()` 안에서 사용하는 property는 `Double`에도 모두 존재한다.

- 동일한 메소드가 중복적으로 선언되는 것이기 때문에 예를 들어 `Comparable<Number>`, `Comparable<Double>` 처럼 제네릭 타입만 다르고 동일한 interface를 동시에 2가지 이상 상속받을 수 없다.

하지만 반환하는 경우에는 Number를 Double로 형변환할 수 없기 때문에 오류가 발생한다.

> 이러한 경우는 컴파일러가 막아주도록 in 키워드를 사용한다.

<br>

`Comparable`을 구현한 예제를 만들어서 생각해보자.

```kotlin
public interface Comparable<in T> {
    public fun compareTo(other: T): Int
}

open class A(val value: Int = 0) : Comparable<A> {
    override fun compareTo(other: A): Int {
        return this.value - other.value
    }
}

// A를 상속받았기 때문에 Comparable<A>가 구현된 것이지, Comparable<B>를 구현한 것은 아니다.
class B(val value2: Int = 10) : A() {
    override fun compareTo(other: A): Int {
        println("call B.compareTo()")
        return value2;
    }
}

fun main() {
    demo(A())
    demo(B())
    demo2(A())
    demo2(B())
}

fun demo(x: Comparable<A>) {
    val a10 = A()
    val b0 = B()

    println(x.compareTo(a10))
    println(x.compareTo(b0))
    println()
}

fun demo2(x: Comparable<B>) {
    val a10 = A()
    val b0 = B()

//    println(x.compareTo(a10)) // error
    println(x.compareTo(b0))
    println()
}
```
여기서 `Comparable<in T>`에서 `in`을 제거하면 `demo()`를 호출할 때 모두 에러가 발생한다.

- `A`, `B` 모두 실제로 `Comparable<B>`를 구현한 클래스가 아니기 때문

- `in` 키워드를 사용했을때는 `B`가 `A`의 하위 클래스라 `Comparable<B>` 타입의 변수가 `Comparable<A>` 구현체를 참조할 수 있었기 때문에 오류가 발생하지 않았다.

<br>

이제 이해했다고 생각했는데 [udacity 강의 영상](https://learn.udacity.com/courses/ud9011/lessons/668f9007-e6eb-44f2-855b-8b63639ef294/concepts/6a44f1e5-1a8f-4a98-9c00-70decf7a6ec2)을 보니깐 또 헷갈린다...

> 예제에서 in이랑 out을 사용하는데 in이나 out만 삭제하면 오류가 발생하지만 둘다 삭제하더라도 잘 동작한다.

우선 강의에서 나온대로 단순하게 기억만 하고 나중에 다시 공식문서를 정독하면서 정리해봐야겠다.

> Out types can be used as return values
>
> In types can be used as parameters

<br>

[그 다음 강의](https://learn.udacity.com/courses/ud9011/lessons/668f9007-e6eb-44f2-855b-8b63639ef294/concepts/9e430996-f7a2-486f-a296-66a84aca4cf2)를 보고 나니깐 이해가 좀 더 잘 된다.



```kotlin
class Aquarium<out T : WaterSupply>(val waterSupply: T) {
    fun addWater() {
        check(!waterSupply.needsProcessed) { "water supply needs processed" }

        println("adding water from $waterSupply")
    }
}

fun isWaterClean(aquarium: Aquarium<WaterSupply>) {
    println("aquarium water is clean: ${aquarium.waterSupply.needsProcessed}")
}
fun genericExample() {
    val aquarium = Aquarium(TapWater())
    isWaterClean(aquarium)
}
```

> 위의 예제에서 `out`을 제거하면 `isWaterClean()`에서 `WaterSupply`의 하위 타입을 참조할 수 없어서 오류가 발생한다.

`out`과 `in` 키워드는 타입 매개변수 T가 해당 클래스 안에서 어떻게 사용되는지를 컴파일러에게 알려줌으로써 컴파일 단계에서 타입 안정성을 보장해준다.

- `out`의 경우 반환형또는 val 속성을 초기화할때 사용된다. 따라서 하위 타입의 객체를 넘겨받는 것이 가능하다.

- `in`의 경우 함수의 매개변수로 사용된다. 따라서 상위 타입의 객체를 넘겨받는 것이 가능하다.

<br><br>

참고자료

- https://kotlinlang.org/docs/generics.html#variance

- https://mangkyu.tistory.com/m/241

- https://pompitzz.github.io/blog/Java/whyCantCreateGenericsArray.html#%E1%84%8C%E1%85%A6%E1%84%82%E1%85%A6%E1%84%85%E1%85%B5%E1%86%A8-%E1%84%87%E1%85%A2%E1%84%8B%E1%85%A7%E1%86%AF%E1%84%8B%E1%85%B5-%E1%84%80%E1%85%A1%E1%84%82%E1%85%B3%E1%86%BC%E1%84%92%E1%85%A1%E1%84%83%E1%85%A1%E1%84%86%E1%85%A7%E1%86%AB-%E1%84%87%E1%85%A1%E1%86%AF%E1%84%89%E1%85%A2%E1%86%BC%E1%84%92%E1%85%A1%E1%86%AF-%E1%84%89%E1%85%AE-%E1%84%8B%E1%85%B5%E1%86%BB%E1%84%82%E1%85%B3%E1%86%AB-%E1%84%86%E1%85%AE%E1%86%AB%E1%84%8C%E1%85%A6%E1%84%8C%E1%85%A5%E1%86%B7