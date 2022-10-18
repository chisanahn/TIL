kotlin에서 지네릭스를 공부하다가 JAVA에서의 지네릭스와 와일드 카드 개념이 헷갈려서 다시 정리

<br>

## 와일드 카드

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

참고자료

- https://kotlinlang.org/docs/generics.html#variance

- https://mangkyu.tistory.com/m/241

- https://pompitzz.github.io/blog/Java/whyCantCreateGenericsArray.html#%E1%84%8C%E1%85%A6%E1%84%82%E1%85%A6%E1%84%85%E1%85%B5%E1%86%A8-%E1%84%87%E1%85%A2%E1%84%8B%E1%85%A7%E1%86%AF%E1%84%8B%E1%85%B5-%E1%84%80%E1%85%A1%E1%84%82%E1%85%B3%E1%86%BC%E1%84%92%E1%85%A1%E1%84%83%E1%85%A1%E1%84%86%E1%85%A7%E1%86%AB-%E1%84%87%E1%85%A1%E1%86%AF%E1%84%89%E1%85%A2%E1%86%BC%E1%84%92%E1%85%A1%E1%86%AF-%E1%84%89%E1%85%AE-%E1%84%8B%E1%85%B5%E1%86%BB%E1%84%82%E1%85%B3%E1%86%AB-%E1%84%86%E1%85%AE%E1%86%AB%E1%84%8C%E1%85%A6%E1%84%8C%E1%85%A5%E1%86%B7