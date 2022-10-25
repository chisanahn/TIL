## 배열 복사하기

### subList()는 복사가 아닌 view를 반환한다

> Returns a view of the portion of this list ...
> 
> [kotlin 공식문서](https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-list/sub-list.html)

kotlin을 공부하다가 갑자기 궁금증이 들어서 확인해봤는데 koltin이랑 JAVA에서 `subList()`는 값을 복사해서 새로운 배열을 생성하는게 아니라 view를 반환해주는 것이기 때문에 이에 주의해서 사용해야 한다.

```kotlin
class A(sourceArr: MutableList<Int>) {
    val arr: MutableList<Int>
    init {
        arr = sourceArr.subList(0, 2)
        arr[0] = 1
    }
}

fun main(args: Array<String>) {
    val arr = mutableListOf(0, 0, 0)
    val a = A(arr)

    println(a.arr) // [1, 0]
    println(arr) // [1, 0, 0]
}
```

> 참고로 JAVA의 `subList()`도 동일하게 view를 반환한다.
>
> https://docs.oracle.com/javase/8/docs/api/java/util/List.html#subList-int-int-

<br>

### `toList()`를 통한 복사
kotlin에서 `List`는 `toList()`를 사용해서 쉽게 복사할 수 있다.

```kotlin
class A(sourceArr: MutableList<Int>) {
    val arr: MutableList<Int>
    init {
        arr = sourceArr.toMutableList()
        arr[0] = 1
    }
}

fun main(args: Array<String>) {
    val arr = mutableListOf(0, 0, 0)
    val a = A(arr)

    println(arr) // [0, 0, 0]
    println(a.arr) // [1, 0, 0]
}
```