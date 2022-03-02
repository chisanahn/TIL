# Primitive

객체가 아닌 데이터. primitive value, primitive data type이라고도 한다.

* 총 7개가 존재한다. string, number, bigint, boolean, undefined, symbol, null

* 모든 primitive는 **immutable**이다.

  primitive가 할당된 변수와 primitive를 헷갈리지 않도록 주의하자.

  primitive를 저장하는 변수는 새로운 primitive를 할당받을 수 있다. 하지만 primitive 그 자체는 객체와 달리 수정이 불가능하다.

  ```js
  let a = "str";
  console.log(a); // str
  
  a.toUpperCase();
  console.log(a); // str
  
  a = a.toUpperCase();
  console.log(a); // str
  ```

* ### Wrapper Objects

  primitive value를 저장하기 위한 객체

  객체에 저장된 primitive value를 반환하는 `valueOf()` 메소드를 공통적으로 가지고 있다.

<br>

> **참고자료**
>
> Primitive - MDN Web Docs Glossary: Definitions of Web-related terms | MDN. Mozilla.org. Published October 8, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Glossary/Primitive