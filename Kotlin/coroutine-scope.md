## `runBlocking` 안에서 `CoroutineScope`를 추가로 생성해서 사용하는 방법

Coroutine에서 예외처리에 대해서 공부하던 중 이해가 잘 되지 않는 부분이 생겼다.

> https://medium.com/androiddevelopers/exceptions-in-coroutines-ce8da1ec060c

`Supervisor Job`을 사용하는 예제 중에 이러한 예제가 나오는데 

```kotlin
// Scope handling coroutines for a particular layer of my app
val scope = CoroutineScope(SupervisorJob())
scope.launch {
    // Child 1
}
scope.launch {
    // Child 2
}
```

그런데 이상하게 scope.launch 안에 있는 코드가 잘 동작하지 않는다.

> 각각의 launch에서 `delay()` 없이 Exception만 테스트해보면 `Job()`과 `SupervisorJob()`을 사용했을때의 차이점은 잘 나타난다.

<br>

그래서 추가로 몇가지 예제를 만들어서 연습해봤다.

다음과 같이 코드를 작성했더니 `runBlocking`이 `scope.launch`가 끝나는 것을 기다리지 않고 그냥 종료되어 버린다.

```kotlin
suspend fun f() {
    val scope = CoroutineScope(SupervisorJob())
    scope.launch {
        delay(500)
        println("child1")
    }
    scope.launch {
        delay(1000)
        println("child2")
    }
    println("finish")
}

fun main() {
    val time = measureTimeMillis {
        runBlocking {
            launch { f() }
            launch {
                delay(750)
                println("child 1.5")
            }
        }
    }
    println("Execution time: ${time / 1000.0} seconds")
}
```

```
출력결과

finish
child1
child 1.5
Execution time: 0.804 seconds
```

저렇게 scope를 따로 만들어서 사용하지 말고 `supervisorScope`로 감싸서 사용하면 잘 동작한다.

```kotlin
suspend fun f() {
    supervisorScope {
        launch {
            delay(500)
            println("child1")
        }
        launch {
            delay(1000)
            println("child2")
        }
        println("finish")
    }
}

fun main() {
    val time = measureTimeMillis {
        runBlocking {
            launch { f() }
            launch {
                delay(750)
                println("child 1.5")
            }
        }
    }
    println("Execution time: ${time / 1000.0} seconds")
}
```

```
출력결과

finish
child1
child 1.5
child2
Execution time: 1.042 seconds
```

다음과 같이 while문에 가둬버려서 강제로 종료되지 않게 하는 방법도 있긴 하지만 좋은 방법처럼 보이진 않는다.

> 실행시간을 측정해보면 while문을 계속해서 돌면서 검사하기 때문에 비동기 함수처럼 작동하지 않는다.

```kotlin
suspend fun f() {
    val scope = CoroutineScope(SupervisorJob())
    val job = scope.launch {
        delay(500)
        println("child1")
    }
    val job2 = scope.launch {
        delay(1000)
        println("child2")
    }
    while(job.isActive || job2.isActive) {}
    println("finish")
}

fun main() {
    val time = measureTimeMillis {
        runBlocking {
            launch { f() }
            launch {
                delay(750)
                println("child 1.5")
            }
        }
    }
    println("Execution time: ${time / 1000.0} seconds")
}
```

```
출력결과

child1
child2
finish
child 1.5
Execution time: 1.815 seconds
```

<br>

개인적인 생각으로는 scope를 따로 만들어서 사용하다보니 `runBlocking`이 해당 coroutineScope가 끝날때까지 기다려주지 않고 종료되면서 그런 것 같다.

예제를 만들어서 테스트 해보니깐 부모-자식 관계가 성립하지 않는 것을 확인할 수 있다.

```kotlin
suspend fun f() {
    val scope = CoroutineScope(SupervisorJob())
    val job = scope.launch {
        delay(500)
        println("child1")
    }
    val job2 = scope.launch {
        delay(1000)
        println("child2")
    }
    println("finish")
}

fun main() {
    val time = measureTimeMillis {
        runBlocking {
            val job = launch { f() }
            delay(100)
            job.cancel()
            launch {
                delay(2000)
                println("child 1.5")
            }
        }
    }
    println("Execution time: ${time / 1000.0} seconds")
}
```
```
실행결과

finish
child1
child2
child 1.5
Execution time: 2.151 seconds
```

<br>

<del>그렇다면 runBlocking이 특정 coroutineScope가 끝날때까지 종료되지 않도록 하려면 어떻게 해야할까?

<del>특정 coroutine이 끝날때까지 기다리기 위해서는 async/await을 사용하면 될 것 같다.

<br>

coroutine에서 Job 간의 부모-자식 관계에 대해서 잘 정리되어 있는 자료를 찾았는데 올바르게 이해했다는 것을 확인할 수 있었다.

https://kt.academy/article/cc-job#:~:text=Structured%20concurrency%20mechanisms%20will%20not%20work%20if%20a%20new%20Job%20context%20replaces%20the%20one%20from%20the%20parent

추가로 해당 글에서 이해한 내용을 바탕으로 parentJob을 인자로 넘겨줘서 위에서 구현하려고 했던 동작을 구현해보았다.

```kotlin
suspend fun f(parentJob: Job) {
    val scope = CoroutineScope(Job(parentJob))
    val job1 = scope.launch {
        delay(500)
        println("child1 finish")
    }
    val job2 = scope.launch {
        delay(1000)
        println("child2 finish")
    }
    println("finish")

    job1.join()
    job2.join()
    scope.cancel()
    if (!parentJob.isActive) parentJob.cancel()
}

fun main() {
    val time = measureTimeMillis {
        runBlocking {
            val parentJob = launch {
                delay(300)
                println("parent job finish")
            }
            launch { f(parentJob) }
        }
    }
    println("Execution time: ${time / 1000.0} seconds")
}
```