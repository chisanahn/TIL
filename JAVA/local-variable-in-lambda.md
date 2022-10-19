kotlin에서 함수형 언어 개념을 공부하다가 JAVA의 람다식 개념이 헷갈려서 복습

함수형 인터페이스를 도입해서 JAVA에서도 함수형 프로그래밍이 가능하도록 한 것이 바로 Lambda

그런데 공부를 하다가 잘 이해가 안 되는 부분이 있었다.

## Lambda에서 사용되는 local 변수가 final이거나 effectivley final이어야 하는 이유

static variable이나 instance variable은 상수로 간주되지 않는데 왜 local variable만 상수로 간주되어야 하는건지 잘 이해가 되지 않았다.

https://www.baeldung.com/java-lambda-effectively-final-local-variables


위의 자료를 참고해서 간단하게 요약하자면 다음과 같다.

<br>

Lambda가 언제 호출되리라는 보장이 없기 때문에 Lambda에서 사용중인 local variable이 garbage collector에 의해 사라지고 난 뒤에 Lambda가 호출될 수 있다.

이러한 이유로 Lambda 안에서 실제로는 local variable이 아니라 해당 변수 값을 복사해서 상수처럼 사용한다.

```java
@FunctionalInterface
interface MyFunction {
    void myMethod();
}

class MyClass {
    int val = 20;

    void method(int i) {
        int val = 30;
        int[] arr = {1};

        MyFunction f = () -> {
            System.out.println("i = " + ++i); // compile error
            System.out.println("val = " + ++val); // compile error
            System.out.println("++arr[0] = " + ++arr[0]); // okay
            System.out.println("this.val = " + ++this.val); // okay
        };

        f.myMethod();
    }
}
```

이때, local variable은 stack memory 영역에 저장되지만, 배열은 instance variable이나 static variable처럼 heap memory 영역에 저장되기 때문에 사용이 가능하다.

> stack memory는 함수가 종료된 뒤에 gc에 의해 빠르게 정리된다.
>
> 반면, heap은 더 이상 해당 객체를 참조하는 변수가 없을 경우에 정리되는 것 같다.
> 
> - https://stackoverflow.com/questions/2524792/does-a-garbage-collector-collect-stack-memory-heap-memory-or-both
> 
> - https://www.digitalocean.com/community/tutorials/java-heap-space-vs-stack-memory

하지만 멀티쓰레딩 환경에서 결과를 예측할 수 없기 때문에 사용하지 않는 것이 좋다.