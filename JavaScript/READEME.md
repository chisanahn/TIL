# JavaScript

## Array

* ### 선언방법

  ```js
  let arr = [];
  let arr2 = new Array();
  ```

### 

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

* `symbol.description`<br>description 반환

```js
let Sym1 = Symbol("Sym")
let Sym2 = Symbol("Sym")

console.log(Sym1 === Sym2) // returns "false"
```

주로 객체에 유니크한 property key를 추가하기 위해 사용된다. Symbol은 유일하기 때문에 행여나 동일한 key를 사용하는 property가 존재할 가능성을 없앨 수 있다.

* **hidden from any mechanisms** other code will typically use to access the object<br>예를 들어서 `for...in`이나 `Object.getOwnPropertyNames()`을 사용할때 Symbol을 key로 사용하는 property는 접근되지 않는다.

  이는 약한 캡슐화, 정보은닉을 가능하게 해준다.

* 객체에서 Symbol에 접근하기 위해서는 `Object.getOwnPropertySymbols()`를 사용해야 한다. Symbols

* **`Symbol.for("key")`**은 key값에 항상 똑같은 Symbol을 반환해준다. key 값에 매칭되는 Symbol이 없는 경우 새로 생성해서 **global Symbol registry**에 등록한다.

* 일반적인 객체와 달리 string으로 자동형변환 되지 않는다.<br>string으로 변환하고 싶다면 `symbol.toString()`을 이용해야 한다.

* 일반적인 wrapper class와 달리 **`new` keyword**를 사용하면 `TypeError`가 발생한다.

  ```js
  let sym = new Symbol(); // TypeError
  ```

<br>

> **참고자료**
>
> 1. Primitive - MDN Web Docs Glossary: Definitions of Web-related terms | MDN. Mozilla.org. Published October 8, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Glossary/Primitive
> 2. Symbol - MDN Web Docs Glossary: Definitions of Web-related terms | MDN. Mozilla.org. Published October 8, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Glossary/Symbol
> 3. Symbol - JavaScript | MDN. Mozilla.org. Published January 17, 2022. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol

### 

## object

### property

간단하게 object에 첨부된 변수라고 생각하면 된다

일반적인 JavaScript와 마찬가지로 이름은 camelCase를 따른다.

#### property name

property name으로 `string`이나 `symbol`을 사용할 수 있다.

#### property 접근방법

1. ##### dot notation

   ```javascript
   object.property
   ```

2. ##### bracket notation

   ```javascript
   object['property']
   ```

   * 괄호 안에 변수를 사용하는 것도 가능하다.<br>property name이 동적으로 결정될때 유용하게 사용할 수 있다.

     ```js
     let key = prompt('input key');
     obj[key] = prompt('input value');
     ```

   * 또한 bracket notation을 사용할 경우 identifier 규칙과 무관하게 정말 모든 문자열을 property name으로 사용할 수 있다.

     ```js
     const obj2 = {};
     obj2[' '] = 1234;
     obj2['123'] = 1234;
     obj2['$&#(!(@'] = "wow";
     ```

#### Enumerate the properties of an object

참고로 다음과 같은 방식에서 hidden properties에 접근하지는 않는다.

> hidden properties : prototype에 포함되어 있는 property

* `for...in`
* `Object.keys(o)`
* `Object.getOwnPropertyNames(o)`

#### Indexing object properties

object property를 index를 기반으로 정의했으면 추후에 index를 통해서만 접근할 수 있고, name을 기반으로 정의했다면 추후에 name을 통해서만 접근할 수 있다는데 무슨 말인지 잘 모르겠다.

> 실제로 실행시켜봤을때 별 다르

### object initializer

`,`로 여러가지 property를 구분해서 객체를 초기화 할 수 있다.

```js
const myCar = {
  make: 'Ford',
  model: 'Mustang',
  year: 1969
};
```

### Method binding

javascript에서 method는 객체에 종속되지 않는다.

정확히는 `this`가 가리키는 값이 함수가 호출될 때 정해진다.

<br>

> **참고자료**
>
> 1. Working with objects - JavaScript | MDN. Mozilla.org. Published January 7, 2022. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Working_with_Objects
> 2. Property accessors - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Property_Accessors

### 

## for 반복문

### for...in

### for...of

### 

## Function

### `this`

javascript에서 `this`가 가리키는 값은 함수가 어떻게 호출되느냐에 따라 달라진다.

* #### `bind()`

  함수가 호출되는 방식에 상관없이 `this`의 값을 설정할 수 있다.

* #### arrow function

  it retains the `this` value of the enclosing lexical context

> **참고자료**
>
> this - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this#method_binding

### Arrow Functions

* #### `this`

  arrow function에서 `this`는 lexical this. 즉, 상위 환경의 this를 그대로 계승한다.

  > **참고자료**
  >
  > 김솔샤르. [자바스크립트] arrow function과 this. 김솔샤르의 인사이트. Published August 12, 2018. Accessed February 1, 2022. https://kim-solshar.tistory.com/57

### 

## Script Loading Strategies

### internal script

* #### `DOMContentLoaded` event

  `DOMContentLoaded` event를 활용하여 DOM 생성이 완료된 후에야 실행되도록 만들 수 있다.

### external script

1. #### body 태그의 맨 마지막에 script 태그 두기

   예전에 주로 사용했던 방법. script를 만나면 HTML parsing을 멈추고 script르 다운 후 실행까지 진행한다.

   용량이 큰 사이트의 경우 성능이 안 좋아진다는 단점이 있다.

   이어서 소개할 2번과 3번은 script 파일 다운로드와 HTML parsing를 동기적으로 처리하기 때문에 1번에 비해 성능이 뛰어나다.

2. #### script 태그에 `async` attribute 추가

   script 파일을 다운이 완료되는대로 실행되기 때문에 독립적으로 동작하는 script의 경우에 유용하다. 그리고 실행하는 동안 나머지 다운로드는 멈춘다.

3. #### script 태그에 `defer` attribute 추가

   script 파일을 HTML parsing이 모두 끝난 후 순서대로 실행한다. script 실행 순서가 중요하거나 DOM 요소를 사용하는 경우 `defer`를 주로 사용한다.

   참고로 내부 script에서는 `defer`를 사용할 수 없다.

   <br>

> **참고자료**
>
> What is JavaScript? - Learn web development | MDN. Mozilla.org. Published December 28, 2021. Accessed January 27, 2022. https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/What_is_JavaScript

### 

## Prototypes and Inheritance

JavaScript는 **prototype-based language**이다.

**Prototype**을 통해 객체간의 연결이 형성된다.

### prototype chain

객체의 property나 method를 접근할때 객체 -> 객체의 prototype -> 연결된 객체의 prototype -> ... 순으로 접근한다.

예를 들어 기본으로 제공되는 `Array.prototype`의 경우 `Object.prototype`과 연결되어 있다.

```js
let arr = new Array();
let arrPrototype = Object.getPrototypeOf(arr); // Array.prototype
Object.getPrototypeOf(arrPrototype); // Object.prototype
```

모든 prototype chain의 끝은 `Object.prototype`이고, 여기서도 해당 property나 method를 찾지 못하면 `null`이 반환된다.

* #### `prototype.isPrototypeOf()` & `instanceof`

  객체의 prototype chain에 해당 prototype이 존재하는지, 즉 객체가 해당 prototype을 상속받았는지 체크해준다.

  ```js
  let arr = [];
  Array.prototype.isPrototypeOf(arr); // true
  Object.prototype.isPrototypeOf(arr); // true
  
  arr instanceof Array; // true
  arr instanceof Object; // true
  ```

* #### `Object.prototype`

  해당 함수로부터 생성된 객체의 prototype을 가리키는 property

  ```js
  console.log(Array.prototype.constructor === Array); // true
  ```

* #### `Object.__proto__`

  객체의 prototype을 저장하는 내부 property

  ```js
  let arr = [];
  console.log(arr.__proto__ === Array.prototype); // true
  ```

  ES2015부터 표준화되기 이전에 웹 호환성을 위해 사용된 레거시 기능으로 사용이 권장되지 않는다.

   `getPrototypeOf()`랑 `setPrototypeOf()`를 사용하자.

* #### `Object.getPrototypeOf()`

  객체의 prototype을 반환해준다.

  ```js
  let arr = [];
  console.log(Object.getPrototypeOf(arr) === Array.prototype); // true
  ```

* #### `Object.setPrototypeOf()`

  prototype을 동적으로 수정할 수 있다.

  ```js
  Object.setPrototypeOf(Worker.prototype, Person.prototype);
  ```

  하지만 JavaScript의 특성상 prototype을 동적으로 수정하는 작업이 굉장히 느리다고 한다. 따라서 성능을 위해서는 `Object.create()`를 사용하는 것을 권장한다고 한다.

* #### `Object.create()`

  지정된 프로토타입 객체 및 속성을 갖는 새 객체를 만든다.

  ```js
  Worker.prototype = Object.create(Person.prototype);
  Worker.prototype.constructor = Worker;
  ```

  새 객체가 생성되어 prototype으로 지정되기 때문에 단일 상속 용이다.

  ```
  console.log(Worker.prototype.__proto === Person.prototype); // false
  ```

  예를 들어 위 예제에서 Worker는 Person을 Deep Copy한 객체(내용만 같고 다른 객체)를 prototype으로 사용하기 때문에 Person과 Worker의 prototype은 연결되어 있지 않다.

  그런줄 알았지만 객체를 복사해서 넘겨주는 개념은 아닌 것 같다. `Worker.prototype.__proto__`에 Method를 추가했을경우 `Person.prototype`에서는 반영이 되지 않아서 깊은 복사가 일어나는 줄 알았는데

  `Person.prototype`에서 Method를 추가하면 `Worker.prototype.__proto__`에도 반영된다.

  좀 더 공부를 해봐야 할 것 같다.

  > 양찬우. JS 33 - 18.Object.create와 Object.assign, js에서 객체 복사하기. 우당탕탕 개발. Published June 3, 2021. Accessed February 1, 2022. https://oizys.tistory.com/53

* ### class

  ES6부터 추가된 개념. prototype과 inheritance에 대한 **syntactical sugar**

  코드를 더 직관적으로 작성할 수 있기 때문에 `class`를 주로 사용한다.

  > 특히 OOP에 익숙한 사람들에게 보다 직관적이다.

### Constructor functions

새로운 객체를 설계할때 사용되는 함수. 이름의 첫글자를 대문자로 사용하는것이 일반적이다.

instance 옆에서 `new` 연산자와 함께 사용된다. 이때 `new` 연산자는 constructor 함수에 기반하여 새로운 instance를 만들어준다.

```js
function Person(name, age) {
    this.name = name;
    this.age = age;
}

let joshua = new Person('Joshua', 23);
```

* #### `this` keyword

  constructor 함수 안에서 `this`는 새롭게 생성되는 instance를 가리킨다.

* #### Method

  효율성 증가와 코드 가독성을 위해 method는 따로 prototype에 추가하는 것이 일반적이다. prototype에 추가하고 나면 해당 prototype을 상속한 instance들은 모두 해당 method를 사용할 수 있다.

  ```js
  Person.prototype.introduce = function {
      return `Hi my name is ${this.name}!`;
  }
  
  joshua.introduce(); // Hi my name is Joshua!
  ```

  * ##### 이때 method를 arrow function으로 만들어서는 안된다는 것에 주의하자.

    arrow function의 특성상 `this`가 해당 객체가 아닌 전역 객체를 가리키게 된다.

* #### Chain Constructor

  `call()`을 활용해서 Constructor를 복사할 수 있다.

  ```js
  function Worker (name, age, job) {
      Person.call(this, name, age);
  
      this.job = job;
  }
  ```

  복사라고 표현한 이유는 `call()`을 사용했을때 prototype이 연결되지 않아서 별도로 연결해주어야 하기 때문이다.

### Class

ES6부터 추가된 개념. prototype과 inheritance에 대한 **syntactical sugar**

### `classical inheritance`와 `prototypal inheritance` 차이점

* https://stackoverflow.com/questions/19633762/classical-inheritance-vs-prototypal-inheritance-in-javascript/19640910#:~:text=Classical%20inheritance%20is%20limited%20to,also%20objects%20inheriting%20from%20prototypes.
* https://developer.mozilla.org/en-US/docs/Web/JavaScript/Inheritance_and_the_prototype_chain
* https://www.geeksforgeeks.org/explain-prototype-inheritance-in-javascript/

<br>

> **참고자료**
>
> 1. Rascia T. Understanding Prototypes and Inheritance in JavaScript. DigitalOcean. Published January 12, 2018. Accessed January 27, 2022. https://www.digitalocean.com/community/tutorials/understanding-prototypes-and-inheritance-in-javascript
> 2. Inheritance and the prototype chain - JavaScript | MDN. Mozilla.org. Published January 17, 2022. Accessed February 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Inheritance_and_the_prototype_chain
> 3. lukeaus. Object.getPrototypeOf() vs .prototype. Stack Overflow. Published August 3, 2016. Accessed February 1, 2022. https://stackoverflow.com/questions/38740610/object-getprototypeof-vs-prototype
> 4. Object.prototype.__proto__ - JavaScript | MDN. Mozilla.org. Published January 30, 2022. Accessed February 1, 2022. https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/proto
> 5. Object.getPrototypeOf() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getPrototypeOf
> 6. Object.setPrototypeOf() - JavaScript | MDN. Mozilla.org. Published February 2022. Accessed February 1, 2022. https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/setPrototypeOf
> 7. Object.create() - JavaScript | MDN. Mozilla.org. Published February 2022. Accessed February 1, 2022. https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/create
> 8. Jesus. Extends Object.setPrototypeOf() vs Object.create. Stack Overflow. Published October 14, 2019. Accessed February 1, 2022. https://stackoverflow.com/questions/58377377/extends-object-setprototypeof-vs-object-create
> 9. Matt. Understanding the difference between Object.create() and new SomeFunction(). Stack Overflow. Published November 12, 2010. Accessed February 1, 2022. https://stackoverflow.com/questions/4166616/understanding-the-difference-between-object-create-and-new-somefunction
> 10. Rascia T. Understanding Classes in JavaScript. DigitalOcean. Published May 4, 2018. Accessed January 27, 2022. https://www.digitalocean.com/community/tutorials/understanding-classes-in-javascript

### 

## Event

### 

## Closure

### 

## asynchronous JavaScript