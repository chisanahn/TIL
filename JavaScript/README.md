# JavaScript

 lightweight interpreted programming language

* 인터프리터 언어로 코드가 줄 단위로 바로바로 실행된다.
* 성능을 위해서 **just-in-time compiling** 기술을 사용한다.

> **참고자료**
>
> What is JavaScript? - Learn web development | MDN. Mozilla.org. Published December 28, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/What_is_JavaScript

<br><br>

## Array

* ### 선언방법

  ```js
  let arr = [];
  let arr2 = new Array();
  ```

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

### symbol

**primitive**의 한 종류. **유일성**이 보장되는 값이다.

`Symbol()` 을 이용해서 생성할 수 있고, description을 가질 수 있지만 디버깅 목적으로만 사용된다.

```js
let Sym1 = Symbol("Sym")
let Sym2 = Symbol("Sym")

console.log(Sym1 === Sym2) // returns "false"
```

* `symbol.description`<br>description 반환

* 일반적인 wrapper class와 달리 **`new` keyword**를 사용하면 `TypeError`가 발생한다.

  ```js
  let sym = new Symbol(); // TypeError
  ```

주로 객체에 유니크한 property key를 추가하기 위해 사용된다. Symbol은 유일하기 때문에 행여나 동일한 key를 사용하는 property가 존재할 가능성을 없앨 수 있다.

* **hidden from any mechanisms** other code will typically use to access the object<br>예를 들어서 `for...in`이나 `Object.getOwnPropertyNames()`을 사용할때 Symbol을 key로 사용하는 property는 접근되지 않는다.

  이는 약한 캡슐화, 정보은닉을 가능하게 해준다.

* 객체에서 Symbol에 접근하기 위해서는 `Object.getOwnPropertySymbols()`를 사용해야 한다. Symbols

* #### global Symbol registry

  key값마다 Symbol을 하나씩 등록해서 공유해서 사용할 수 있다.

  * **`Symbol.for("key")`**<br>key 값에 매칭되는 global symbol 반환<br>없는 경우 symbol을 새로 생성해서 global Symbol registry에 등록한다.
  * **`Symbol.keyFor(sym)`**<br>해당 symbol에 해당되는 shared symbol key 반환<br>없는 경우 undefined 반환

* **`Symbol.for("key")`**은 key값에 항상 똑같은 Symbol을 반환해준다. key 값에 매칭되는 Symbol이 없는 경우 새로 생성해서 **global Symbol registry**에 등록한다.

* 일반적인 객체와 달리 string으로 자동형변환 되지 않는다.<br>string으로 변환하고 싶다면 `symbol.toString()`을 이용해야 한다.

* #### Constants

  Symbol 클래스는 `well-known symbols`라고 불리는 상수들을 가지고 있다.

  * `Symbol.iterator`

    객체가 iterate되어야 할때 `@@iterator` 메소드가 호출된다.

    인자가 없고 interator를 반환하는 함수이다.

    예시: `Array.prototype[@@iterator]()`
    
    ```js
    var arr = ['a', 'b', 'c'];
    var eArr = arr[Symbol.iterator]();
    console.log(eArr.next().value); // a
    console.log(eArr.next().value); // b
    console.log(eArr.next().value); // c
    ```
    
    참고로 `Array.prototype.values()`와 동일한 함수다.
    
    ```js
    Array.prototype.values === Array.prototype[Symbol.iterator]      //true
    ```
  
  <br>

> **참고자료**
>
> 1. Primitive - MDN Web Docs Glossary: Definitions of Web-related terms | MDN. Mozilla.org. Published October 8, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Glossary/Primitive
> 2. Symbol - MDN Web Docs Glossary: Definitions of Web-related terms | MDN. Mozilla.org. Published October 8, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Glossary/Symbol
> 3. Symbol - JavaScript | MDN. Mozilla.org. Published January 17, 2022. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol
> 4. Symbol.for() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol/for
> 5. Symbol.keyFor() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol/keyFor
> 6. Symbol.iterator - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol/iterator
> 7. Array.prototype[@@iterator]() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/@@iterator

<br><br>

## Object

<br><br>

## [Immutability](./immutability.md)

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

## for 반복문

### for...in

객체의 enumerable property에 대해서 반복을 실행한다. (Symbol은 제외)

상속받은 property에도 접근한다.

```js
for (variable in object) {
    // statement
}
```

`variable`에는 `propertyName`이 할당된다.

```js
var obj = {a: 1, b: 2, c: 3};

for (const prop in obj) {
  console.log(`obj.${prop} = ${obj[prop]}`);
}

// Output:
// "obj.a = 1"
// "obj.b = 2"
// "obj.c = 3"
```

* 메소드도 일종의 property이다. 하지만 예를 들어 String의 경우 `indexOf()` 등의 메소드는 non-enumerable property로 정의되어 있기 때문에 접근되지 않는다.

* 반복 도중에 현재 방문한 property 외에 해당 객체의 property를 추가, 수정, 삭제하면 오류가 날 수 있으므로 하지 않는 것이 좋다.

* #### Array iteration

  index 순서대로 방문하는 것이 보장되지 않으므로 접근 순서가 중요할 경우 `Array.prototype.forEach()`나 `for...of`를 사용해야 한다.

* property name을 확인할 수 있기 때문에 디버깅에 유용하게 사용된다.

### for...of

iterable한 객체에 대해서 iterable을 수행하는 반복문을 만든다.

> 예전에는 `for...of`가 property value에 대해서 반복을 수행하는건줄 알았는데 이는 iterable object가 어떻게 정의되어 있는가에 따라 다르다.

```js
for (variable of iterable) {
  statement
}
```

* `NodeList` 등의 `DOM collection`에 대해서도 수행할 수 있다.

  ```js
  const articleParagraphs = document.querySelectorAll('article > p');
  
  for (const paragraph of articleParagraphs) {
    paragraph.classList.add('read');
  }
  ```

* generators에 대해서도 수행할 수 있다.

  ```js
  function* fibonacci() { // a generator function
    let [prev, curr] = [0, 1];
    while (true) {
      [prev, curr] = [curr, prev + curr];
      yield curr;
    }
  }
  
  for (const n of fibonacci()) {
    console.log(n);
    // truncate the sequence at 1000
    if (n >= 1000) {
      break;
    }
  }
  ```


<br>

> **참고자료**
>
> 1. for...in - JavaScript | MDN. Mozilla.org. Published January 5, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...in
> 2. for...of - JavaScript | MDN. Mozilla.org. Published January 21, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...of

<br><br>

## Function

### `this`

javascript에서 `this`가 가리키는 값은 함수가 어떻게 호출되느냐에 따라 달라진다.

* #### `bind()`

  함수가 호출되는 방식에 상관없이 `this`의 값을 설정할 수 있다.

* #### arrow function

  it retains the `this` value of the enclosing lexical context

### Arrow Functions

* #### `this`

  arrow function에서 `this`는 lexical this. 즉, 상위 환경의 this를 그대로 계승한다.

### arguments

* #### Rest parameters

  여러 개의 인자를 **Array** 형태로 받는다.

  * 함수 인자 개수를 유연하게 가져갈 수 있다.
  * Array의 method를 사용할 수 있다.

  ```js
  function f(a, b, ...theArgs) {
    // ...
  }
  ```

<br>

> **참고자료**
>
> 1. this - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this#method_binding
> 2. 김솔샤르. [자바스크립트] arrow function과 this. 김솔샤르의 인사이트. Published August 12, 2018. Accessed February 1, 2022. https://kim-solshar.tistory.com/57
> 3. Rest parameters - JavaScript | MDN. Mozilla.org. Published January 7, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/rest_parameters

<br><br>

## [Script Loading Strategies](./script_loading_strategies.md)

<br><br>

## [Prototypes and Inheritance](./prototype.md)

<br><br>

## Event

<br><br>

## Closure

<br><br>

## [Ajax](./ajax.md)

<br><br>

## Strict mode

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode

<br><br>

## Client-side web APIs

https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Client-side_web_APIs