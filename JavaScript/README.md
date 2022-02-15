# JavaScript

 lightweight interpreted programming language

* 인터프리터 언어로 코드가 줄 단위로 바로바로 실행된다.

* 성능을 위해서 **just-in-time compiling** 기술을 사용한다.

* ES6에서 많은 변화가 일어났기 때문에 최소한 ES6 (ES2015) 문법을 이해하고 있는 것이 좋다.

  > 채용공고만 보더라도 `ES6+`를 심심치않게 볼 수 있다.

> **참고자료**
>
> 1. What is JavaScript? - Learn web development | MDN. Mozilla.org. Published December 28, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/What_is_JavaScript
> 2. Morelli B. JavaScript — WTF is ES6, ES8, ES 2017, ECMAScript… ? Medium. Published August 28, 2017. Accessed February 12, 2022. https://codeburst.io/javascript-wtf-is-es6-es8-es-2017-ecmascript-dca859e4821c
> 3. ES6 Syntax and Feature Overview. Taniarascia.com. Published 2015. Accessed February 12, 2022. https://www.taniarascia.com/es6-syntax-and-feature-overview/

<br><br>

## Types

* ### Primitive

  * #### Number

  * #### BigInt

  * #### String 

  * #### null

  * #### undefined

  * #### Boolean

  * #### [Symbol](./symbol.md)

* ### Object

  * #### Function

  * #### Array

  * #### Date

  * #### RegExp

  * #### Error

  * #### Math

<br><br>

## Hoisting

`var`로 선언된 변수나 함수의 선언은 해당 scope의 맨 위로 옮겨진다.

변수의 경우 초기화는 되지 않는다.

> **참고자료**
>
> Rascia T. Understanding Variables, Scope, and Hoisting in JavaScript. Digitalocean.com. Published February 20, 2018. Accessed February 13, 2022. https://www.digitalocean.com/community/tutorials/understanding-variables-scope-hoisting-in-javascript

<br><br>

## Primitive

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

<br><br>

## Object

* ### [property](./object-property.md)

* ### JSON

  JavaScript Object Notation

  * ##### 일반적인 JavaScript 객체와의 차이점

    * key가 quotes로 둘러싸여 있다.

    * function을 value로 가질 수 없는 등 value에 제약이 있다.

  * ##### JSON methods

    * `JSON.stringify()` : JSON 객체 -> JSON 문자열

    * `JSON.parse()` : JSON 문자열 -> JSON 객체
    
      <br>
  
  > **참고자료**
  >
  > Tagliaferri L. How To Work with JSON in JavaScript. Digitalocean.com. Published December 9, 2016. Accessed February 13, 2022. https://www.digitalocean.com/community/tutorials/how-to-work-with-json-in-javascript

<br><br>

## [Immutability](./immutability.md)

<br><br>

## [Prototypes and Inheritance](./prototype.md)

<br><br>

## Iteration

### Iteration protocols

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

<br><br>

## [for 반복문](./for-loop.md)

* for...in
* for...of

<br><br>

## [Array](./array.md)

<br><br>

## [Function](./funct)

<br><br>

## Closure

<br><br>

## [Ajax](./ajax.md)

<br><br>

## [Script Loading Strategies](./script_loading_strategies.md)

<br><br>

## Strict mode

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode

<br><br>

## Client-side web APIs

https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Client-side_web_APIs

<br><br>

## [Event](./event.md)

<br><br>

## 기타

### CSS vs JS animation performance

기본적으로 성능면에서 차이는 없지만 CSS의 경우 GPU를 통해 처리할 수 있기 때문에 성능면에서 더 뛰어나다. 따라서 가능한 CSS를 사용하는 것이 좋다.

> **참고자료**
>
> CSS and JavaScript animation performance - Web Performance | MDN. Mozilla.org. Published February 2, 2022. Accessed February 13, 2022. https://developer.mozilla.org/en-US/docs/Web/Performance/CSS_JavaScript_animation_performance

