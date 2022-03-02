# Iteration

## Iteration protocols

* https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Iterators_and_Generators#iterables

* https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Iteration_protocols#the_iterable_protocol

* https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Generator

* https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/function*

ECMAScript 2015부터 추가된 개념

#### The iterable protocol

객체가 iterable 하기 위해서는 `@@iterator` 메소드를 구현해야만 한다.

Array나 Map의 경우 기본적으로 해당 메소드가 구현되어져 있다.

`Symbol.iterator`

#### Spread syntax (...)

`iterable`한 Object 앞에 `...`을 붙여서 여러 인자로 나눠서 전달할 수 있다.

* 함수호출시 사용

  Object의 모든 element를 함수에 인자로 전달한다.

  `Function.prototype.apply()` 대신 유용하게 사용할 수 있다.

  ```js
  myFunction(...iterableObj);
  // pass all elements of iterableObj as arguments to function myFunction
  ```

* For array literals:

  ```js
  [...iterableObj, '4', 'five', 6]; // combine two arrays by inserting all elements from iterableObj
  ```

* For object literals (new in ECMAScript 2018):

  ```js
  let objClone = { ...obj }; // pass all key:value pairs from an object
  ```

<br>

> **참고자료**
>
> 1. Iteration protocols - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Iteration_protocols#the_iterable_protocol
> 2. Spread syntax (...) - JavaScript | MDN. Mozilla.org. Published January 21, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Spread_syntax
> 3. 