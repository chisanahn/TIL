## `yield()`

처음에는 어떤 경우에 해당 메소드를 사용하는지 잘 이해가 되지 않아서 추가적으로 자료를 찾아보았다.

- https://www.baeldung.com/kotlin/yield-function

  예제와 같이 설명해줘서 편하게 이해할 수 있었다.

작업 도중에 다른 작업을 수행하고 싶을때 `yield()` 함수를 호출해서 다른 작업에게 스레드를 넘겨준다.

하지만 일반적인 함수 호출 대신 `yield()`를 굳이 사용해야 하는 이유가 잘 와닿지 않았는데

- https://stackoverflow.com/questions/55129988/understanding-kotlins-yield-function

  > "return, and next time start from where you stopped"

`yield()`를 호출함으로써 여러 개의 작업들이 작업 도중에 자유롭게 교류할 수 있다.

> `yield()`를 사용하지 않는다면, 예를 들어서 단순히 함수 `A()` 안에서 함수 `B()`를 호출한다면 
>
> 함수 `B()`를 실행하는 도중에 다시 `A()`로 넘어와서 작업하고 다시 `B()`로 넘어가는 형식의 흐름은 불가능하다.

<br>

