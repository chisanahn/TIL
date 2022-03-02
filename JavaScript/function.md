# Function

JavaScript에선 함수도 기본적으로 객체이기 때문에 property들을 가질 수 있다. 대표적인 property로는 `prototype`이 있다.

* ### `name` property

  함수의 이름을 나타내는 property. 함수를 생성하는 방법에 따라 자동으로 지정된다.
  
* ### scope

  Javascript에서 함수가 실행되면 `scope`라는 객체가 생성되어 해당 함수안에서 생성된 지역 변수들을 저장한다.

  다만 따로 scope에 저장된 값들을 확인하거나 수정할 수 있는 기능이 있진 않는다.

  원래대로라면 함수가 종료된 뒤에 `scope`는 JavaScript의 garbage collector에 의해 삭제된다. 다만, closure의 경우 `scope`가 제거되지 않은채 유지된다.

## parameters

* C나 Java와 달리 매개변수의 입력이 자유롭다.<br/>앞에서부터 차례대로 매칭시켜서 매개변수를 적게 넣은 경우 남은 매개변수들은 undefined로 정의되고, 많이 호출된 경우 남은 인자들은 무시된다.

  ```js
  function add(x, y) {
      return x + y;
  }
  
  add(1);  // x=1, y=undefined, 따라서 NaN이 반환된다.
  add(1, 2, 3);  // x=1, y=2, 3은 무시된다.
  ```
  
* #### default parameters

  인자가 전달되지 않았을때 사용할 기본값을 지정할 수 있다.
  
  ```js
  const sum = (a, b = 3) => a + b;
  
  console.log(sum(1)); // 3
  ```
  
* #### arguments

  기본적으로 함수가 호출되었을때 전달받은 모든 인자는 arguments에 저장된다.<br/>따라서 매개변수를 지정해두지 않았더라도 arguments를 이용해서 함수를 호출할때 전달받았던 모든 인자들을 불러올 수 있다.
  
  ```javascript
  function sum() {
      let ret = 0;
      for(const item of arguments) {
          ret += item;
      }
      return ret;
  }
  
  sum(1, 2, 3, 4, 5);  // 15
  ```
  
* #### Rest parameters

  여러 개의 인자를 **Array** 형태로 받는다.

  * 함수 인자 개수를 유연하게 가져갈 수 있다.
  * Array의 method를 사용할 수 있다.

  ```js
  function f(a, b, ...theArgs) {
    // ...
  }
  ```
  
* #### `apply()`

  array를 arguments 형식으로 받을 수 있게 도와주는 method

  예를 들어 위 예시에서 배열을 인자로 넘기고 싶을때 `avg.apply(null, [2, 3, 4, 5])` 형식으로 사용할 수 있다.

<br>

## `this`

javascript에서 `this`가 가리키는 값은 함수가 어떻게 호출되느냐에 따라 달라진다.

* 기본적으로 `global object`로 autobinding된다.

  strict mode에서는 autobinding되지 않기 때문에 따로 지정하지 않는다면 `undefined` 값을 갖는다.

* #### `bind()`

  함수가 호출되는 방식에 상관없이 `this`의 값을 설정할 수 있다.

* #### arrow function

  arrow function에서 `this`는 lexical this. 즉, 상위 환경의 this를 그대로 계승한다.

<br>

## anonymous functions

주로 다른 함수에 인자로 전달되거나 변수에 저장되어서 사용된다.

```js
let f = function(x, y) {
    return x + y;
}
```

<br>

## **IIFE**

Immediately Invoked Function Expression

일회용? 함수. closure를 만들때 유용하게 사용된다.

```js
(function () {
  statements
})();
```

<br>

## 재귀 함수

재귀적으로 함수를 만들기 위해서 함수에 이름을 붙일 수도 있다.<br/>이때 함수의 이름은 함수 안에서만 사용 가능하다.

> debugger에서도 함수의 이름이 표시된다.

```js
(function name() {
  statements
})();
```

<br>

## Arrow Functions

함수를 보다 간단하게 정의할 수 있는 방법. callback 함수를 인자로 넘겨줄때 주로 사용한다.

java에서는 `->`를 이용하던데 javascript에서는 `=>`를 이용한다. 나머지는 비슷한듯.

* #### `this`

  arrow function에서 `this`는 lexical this. 즉, 상위 환경의 this를 그대로 계승한다.

  > 따라서 메소드를 작성할때 arrow function을 사용하면 안된다. 왜냐하면 `this`가 해당 객체가 아닌 전역 객체를 가리키게 되기 때문이다.

<br>

## [Closure](./closure.md)

* 활용방안
  * function factory
  * module design pattern - private methods
* 반복문 안에서의 closure
* 성능 고려

<br><br>

> **참고자료**
>
> 1. this - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this#method_binding
> 2. 김솔샤르. [자바스크립트] arrow function과 this. 김솔샤르의 인사이트. Published August 12, 2018. Accessed February 1, 2022. https://kim-solshar.tistory.com/57
> 3. Rest parameters - JavaScript | MDN. Mozilla.org. Published January 7, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/rest_parameters
> 4. Function.name - JavaScript | MDN. Mozilla.org. Published January 28, 2022. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Function/name
> 5. Classes - JavaScript | MDN. Mozilla.org. Published January 19, 2022. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes
> 6. Function.prototype.apply() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed March 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Function/apply
> 7. Functions - JavaScript | MDN. Mozilla.org. Published February 7, 2022. Accessed March 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions#function_parameters