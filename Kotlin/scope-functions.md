## Scope functions 적절하게 사용하는 방법

when, run, apply, let, also

<br>

apply랑 run은 어떤 부분이 반환되는지에 차이가 있어서 그래도 구분이 잘되는데

run이랑 let은 호출한 객체를 참조하는 방법만 다르고 별 차이가 없는 것 같아서 인터넷을 좀 찾아봤다.

<br>

run을 사용하는 부분을 let으로도 동일하게 사용이 가능하지만 2가지 함수의 사용 방향을 분류함으로써 코드의 가독성을 높이기 위해서 이렇게 분류한 것 같다.

> Technically, functions are interchangeable in many cases, so the examples show the conventions that define the common usage style. (출처: Kotlin 공식문서)

- 해당 객체를 변수의 매개변수로 넘겨받아서 사용하는 것처럼 동작해야 하는 경우에는 `it`을 통해 해당 객체에 접근하는 let이나 also를 사용하자

- 해당 객체의 메소드처럼 동작하는 경우에는 `this`를 통해 해당 객체에 접근하는 run, apply를 사용하자

- when은 해당 객체에 접근하는 코드들을 묶어서 가독성을 향상시킬때 사용하자

  ```kotlin
  class a = A()
  println(a.name)
  a.cal()
  ```

  ```kotlin
  class a = A()
  when (a) {
    println(name)
    cal()
  }
  ```

이 외에도 공식문서를 보면 친절하게 예시와 함께 어떨때 이런걸 쓰면 좋은지 설명해주니 참고해보자

https://kotlinlang.org/docs/scope-functions.html#let