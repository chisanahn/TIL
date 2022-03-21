# JavaScript

 lightweight interpreted programming language

* 인터프리터 언어로 코드가 줄 단위로 바로바로 실행된다.

* 성능을 위해서 **just-in-time compiling** 기술을 사용한다.

* ES6에서 많은 변화가 일어났기 때문에 최소한 ES6 (ES2015) 문법을 이해하고 있는 것이 좋다.

  > 채용공고만 보더라도 `ES6+`를 심심치않게 볼 수 있다.
  
  [ES6에 추가된 문법들을 간략하게 잘 설명해주는 글](https://www.taniarascia.com/es6-syntax-and-feature-overview/)이 있으니 참고하면 좋을 것 같다.

> **참고자료**
>
> 1. What is JavaScript? - Learn web development | MDN. Mozilla.org. Published December 28, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/What_is_JavaScript
> 2. Morelli B. JavaScript — WTF is ES6, ES8, ES 2017, ECMAScript… ? Medium. Published August 28, 2017. Accessed February 12, 2022. https://codeburst.io/javascript-wtf-is-es6-es8-es-2017-ecmascript-dca859e4821c
> 3. ES6 Syntax and Feature Overview. Taniarascia.com. Published 2015. Accessed February 12, 2022. https://www.taniarascia.com/es6-syntax-and-feature-overview/

<br>

### Types

* #### [Primitive](./primitive.md)

  * **Number**

    기본적으로 실수형식으로 저장된다

    * `toFixed()` : 설정한 소수점자리까지 반올림한 결과

    * `parseInt(string);`

    * `parseFloat(string);`

      parseInt나 parseFloat은 문자열에 숫자가 아닌 문자가 포함되어 있어도 그전까지의 숫자를 Number로 변환해서 리턴해준다.

    * `+ 'string'`

      string 앞에 `+`를 붙이면 Number로 변환된다.<br/>parseInt나 parseFloat와 달리 문자열에 숫자가 아닌 문자가 포함되어 있으면 NaN 리턴

    * `Number.isNan(value)`

      isNan(value)은 반환값이 직관적이지 않다

    * `isFinite(testValue)`

  * BigInt

  * **String** (UTF-16)

    * `length`
    * `String.prototype.charAt(index)`
    * `String.prototype.replace(searchFor, replaceWith)`
    * `String.prototype.toUpperCase()`

  * **null** : deliberate non-value

  * **undefined** : uninitialized variable

    > null이랑 undefined는 값이 아니라 Type의 일종임에 주의

  * **Boolean**

    * false : `false`, `0`, `""`(empty string), `NaN`, `null`, `undefined`
    * true : all values except false values

  * [**Symbol**](./symbol.md)

* #### Object

  * **Function**
  * [**Array**](./array.md)
  * [Date](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date)
  * [RegExp](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RegExp)
  * [Error](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Error)
  * Math
  * [**JSON**](./json.md)

> **참고자료**
>
> A re-introduction to JavaScript (JS tutorial) - JavaScript | MDN. Mozilla.org. Published February 18, 2022. Accessed March 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/A_re-introduction_to_JavaScript

<br>

### 변수

* `let` : 블록을 기준으로 범위가 설정되는 변수
* `const` : 블록을 기준으로 범위가 설정되는 상수
* `var` : 함수를 기준으로 범위가 설정되는 변수

원래는 `var` 밖에 없었고, 블록이 따로 범위를 갖지 않았고, `let`, `const`는 ECMAScript 2015에 처음 등장했다.

변수를 선언한채 값을 지정해주지 않는다면 변수의 타입은 `undefined`로 설정된다.

<br>

### Hoisting

`var`로 선언된 변수나 함수의 선언은 해당 scope의 맨 위로 옮겨진다.

변수의 경우 초기화는 되지 않는다.

> **참고자료**
>
> Rascia T. Understanding Variables, Scope, and Hoisting in JavaScript. Digitalocean.com. Published February 20, 2018. Accessed February 13, 2022. https://www.digitalocean.com/community/tutorials/understanding-variables-scope-hoisting-in-javascript

<br>

### Template literals

`\``으로 감싼 문자열

* 문자열에서 변수 값을 간단하게 사용할 수 있다.

  ```js
  let name = "Josh";
  let text = `Hi my name is ${name}`; // Hi my name is Josh
  ```

* 개행문자 `\n` 없이도 여러 줄로 이루어진 문자열을 다룰 수 있다.

  ```js
  let multilineText = `dsjkalf
  sdajkflds
  fdsajklf`;
  ```

> **참고자료**
>
> Template literals (Template strings) - JavaScript | MDN. Mozilla.org. Published February 18, 2022. Accessed March 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Template_literals#expression_interpolation

<br>

### 연산자

##### String + Number

String과 Number를 더하면 String이 반환된다.

```javascript
'3' + 4 + 5; // = "345"
3 + 4 + '5' // = "75"
```

##### 비교연산자

type까지 비교하기 위해서는 `===`를 사용해야 한다.

```javascript
123 == '123'; // true
123 === '123'; // false
```

##### 논리 연산자

```javascript
// null check
var name = o && o.getName();
// caching
var name  cachedName || (cachedName = getName());
```

왼쪽에서 -> 오른쪽 순서로 검사. 따라서 조건을 배치하는 순서에도 유의해서 작성해야 한다.

피연산자가 2개인 논리 연산의 경우 첫번째 피연산자만 가지고 결과가 나올 경우 첫번째 피연산자를 리턴한다.

* `expr1 && expr2` 반환값

  : `expr1`이 false일 경우 `expr1` 리턴. 그 외에는 `expr2` 리턴

* `expr1 || expr2` 반환값

  : `expr1`이 true일 경우 `expr1` 리턴, 그 외에는 `expr2` 리턴

> **참고자료**
>
> 1. 드림코딩 by 엘리. 자바스크립트 4. 코딩의 기본 operator, if, for loop 코드리뷰 팁 | 프론트엔드 개발자 입문편 (JavaScript ES6). *YouTube*. Published online April 15, 2020. Accessed March 1, 2022. https://www.youtube.com/watch?v=YBjufjBaxHo&t=478s
> 2. Expressions and operators - JavaScript | MDN. Mozilla.org. Published February 24, 2022. Accessed March 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Expressions_and_Operators#logical_operators

<br>

### 제어문

##### switch

문자열도 사용 가능하다.

```js
switch (action) {
    case 'draw':
        // action
        break;
    default:
        // action
}
```

##### [for 반복문](./for-loop.md)

* for...in
* for...of

<br>

### [Object](./object.md)

* **property**
  * property descriptor

* 객체 생성
* 객체 복사
* destructuring assignment

<br>

### [Immutability](./immutability.md)

<br>

### [Prototypes and Inheritance](./prototype.md)

<br>

### [Iteration](.)

<br>

### [Function](./function.md)

* arguments
  * rest parameter
  * `apply()`
* 익명함수
* IIFE (Immediately Invoked Function Expression)
* 재귀함수
* 화살표함수

* [**Closure**](./closure.md)
  * 활용방안
    * function factory
    * module design pattern - private methods
  * 반복문 안에서의 closure
  * 성능 고려

<br>

### [Ajax](./ajax.md)

<br>

### [Script Loading Strategies](./script_loading_strategies.md)

<br>

### Strict mode

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode

<br>

### Client-side web APIs

https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Client-side_web_APIs

<br>

### [Event](./event.md)

<br>

### Modules

* ##### [export](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/export)

* ##### [import](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/import)

<br>

### 기타

##### CSS vs JS animation performance

기본적으로 성능면에서 차이는 없지만 CSS의 경우 GPU를 통해 처리할 수 있기 때문에 성능면에서 더 뛰어나다. 따라서 가능한 CSS를 사용하는 것이 좋다.

> **참고자료**
>
> CSS and JavaScript animation performance - Web Performance | MDN. Mozilla.org. Published February 2, 2022. Accessed February 13, 2022. https://developer.mozilla.org/en-US/docs/Web/Performance/CSS_JavaScript_animation_performance

<br>

## JavaScript Scope와 Closure 기초

https://unikys.tistory.com/295

* 반복문 안에서 콜백 함수를 호출할때 발생하는 Scope 문제를 Closure를 이용해서 해결할 수 있다.

  with문을 이용해서도 해결할 수 있지만 with문은 사용안하는게 좋음. https://unikys.tistory.com/304
