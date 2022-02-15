# Function

JavaScript에선 함수도 기본적으로 객체이기 때문에 property들을 가질 수 있다. 대표적인 property로는 `prototype`이 있다.

* ### `name` property

  함수의 이름을 나타내는 property. 함수를 생성하는 방법에 따라 자동으로 지정된다.

## arguments

* ### Rest parameters

  여러 개의 인자를 **Array** 형태로 받는다.

  * 함수 인자 개수를 유연하게 가져갈 수 있다.
  * Array의 method를 사용할 수 있다.

  ```js
  function f(a, b, ...theArgs) {
    // ...
  }
  ```

<br>

## `this`

javascript에서 `this`가 가리키는 값은 함수가 어떻게 호출되느냐에 따라 달라진다.

* 기본적으로 `global object`로 autobinding된다.

  strict mode에서는 autobinding되지 않기 때문에 따로 지정하지 않는다면 `undefined` 값을 갖는다.

* ### `bind()`

  함수가 호출되는 방식에 상관없이 `this`의 값을 설정할 수 있다.

* ### arrow function

  arrow function에서 `this`는 lexical this. 즉, 상위 환경의 this를 그대로 계승한다.

<br>

## Arrow Functions

함수를 보다 간단하게 정의할 수 있는 방법. callback 함수를 인자로 넘겨줄때 주로 사용한다.

java에서는 `->`를 이용하던데 javascript에서는 `=>`를 이용한다. 나머지는 비슷한듯.

* #### `this`

  arrow function에서 `this`는 lexical this. 즉, 상위 환경의 this를 그대로 계승한다.

  > 따라서 메소드를 작성할때 arrow function을 사용하면 안된다. 왜냐하면 `this`가 해당 객체가 아닌 전역 객체를 가리키게 되기 때문이다.

<br><br>

> **참고자료**
>
> 1. this - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this#method_binding
> 2. 김솔샤르. [자바스크립트] arrow function과 this. 김솔샤르의 인사이트. Published August 12, 2018. Accessed February 1, 2022. https://kim-solshar.tistory.com/57
> 3. Rest parameters - JavaScript | MDN. Mozilla.org. Published January 7, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/rest_parameters
> 4. Function.name - JavaScript | MDN. Mozilla.org. Published January 28, 2022. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Function/name
> 5. Classes - JavaScript | MDN. Mozilla.org. Published January 19, 2022. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes