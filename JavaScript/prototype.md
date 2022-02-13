# Prototype and Inheritance

JavaScript는 **prototype** 기반 언어이다. 따라서 java 등의 class 기반 언어와는 좀 다르다.

java에서는 클래스 간의 상속관계가 형성되고, 해당 클래스로부터 인스턴스를 생성해서 사용했었다. 하지만 JavaScript에서는 객체마다 **prototype**이라고 불리는 객체와의 `link`를 private property로 가지고 있는데 이를 통해서 객체 간의 직접적인 상속 관계가 형성된다.

> ES6부터 `class`가 추가되었지만 이는 단순히 prototype을 class처럼 사용할 수 있게 해주는 syntactical sugar에 불과하다.

<br>

## Prototype

### prototype chain

prototype을 통해 형성된 상속 관계를 prototype chian이라고 한다.

JavaScript에서 객체의 property에 접근할때 객체 -> 객체의 prototype -> 연결된 객체의 prototype -> ... -> `null` 순으로 접근한다.

따라서 객체의 property가 prototype chain에 없어서 `null`에 도달했을 경우 `undefined`가 반환된다.

> 거의 모든 객체는 Object를 상속받아서 사용하기 때문에 `null`이전에 `Object.prototype`을 prototype chain에 가지고 있는 경우가 많다.

우리가 기본적으로 제공되는 `Array` 객체에서 `sort()` 등 다양한 메소드를 활용할 수 있는 이유도 `Array.prototype`에 이러한 메소드들이 정의되어 있기 때문이다.

```js
Object.getPrototypeOf(arr) === Array.prototype; // true
```

그리고 property 값을 수정할때에는 prototype chain을 타고가서 값을 찾지 않고 own property로만 취급한다는 점에 주의.

```js
const rect = {
  x: 10,
  y: 10,
  getSize() {
    return this.x * this.y;
  }
}

const rect2 = Object.create(rect);
console.log(rect.getSize()); // 10*10 = 100
console.log(rect2.getSize()); // 10*10 = 100

rect2.x = 5; // rect2에 x라는 own property가 생성되고 5라는 값이 할당됨
console.log(rect.getSize()); // 10*10 = 100
console.log(rect2.getSize()); // 5*10 = 50

Object.getPrototypeOf(rect2).y = 3;
console.log(rect.getSize()); // 10*3 = 30
console.log(rect2.getSize()); // 5*3 = 15

Object.getPrototypeOf(rect2).x = 3;
console.log(rect.getSize()); // 3*3 = 9
console.log(rect2.getSize()); // 5*3 = 15. 아까 rect2에 x라는 own property가 생성되었기 때문에 prototype인 rect의 x property 대신 자신의 x property를 사용하기 때문에 9가 아닌 15가 출력된다.
```

<br>

### `prototype` vs `[[prototype]]`

처음 공부한다면 헷갈리기 쉬운 개념

```js
console.log(Array.prototype.__proto__ === Object.prototype); // true
```

* **`Object.prototype`**

  해당 함수를 생성자로 갖는 객체를 가리키는 property

  ```js
  console.log(Array.prototype.constructor === Array); // true
  ```

* **`Object.[[prototype]]`**

  객체의 prototype을 저장하는 내부 property

  예전에는 웹브라우저와의 호환성을 위해 javascript 내에서 `__proto__`를 사용했었지만 현재는 사용이 권장되지 않는다. `Object.getPrototypeOf()`을 사용하자.
  
  ```js
  let arr = [];
  console.log(arr.__proto__ === Array.prototype); // true
  console.log(Object.getPrototypeOf(arr) === Array.prototype); // true
  ```
  
* 특히나 `constructor` 함수에서 헷갈리기 쉬우므로 주의하자.

  예를 들어 `constructor` function의 `[[prototype]`은 `Function.prototype`이다.

  ```js
  Object.getPrototypeOf(Array) === Function.prototype  // true
  Object.getPrototypeOf(Array) === Array.prototype     // false
  ```

<br>

### 관련 메소드

* **`prototype.isPrototypeOf()`**

  객체의 prototype chain에 해당 prototype이 존재하는지 반환

  (즉, 객체가 해당 prototype을 상속받았는지 여부를 반환해준다)

  ```js
  let arr = [];
  Array.prototype.isPrototypeOf(arr); // true
  ```

* **`instanceof`**

  object의 prototype chain에 해당 constructor가 존재하는지 여부를 반환

  ```js
  let arr = [];
  console.log(arr instanceof Array); // true
  ```

* **`Object.getPrototypeOf()`**

  객체의 prototype을 반환해준다.

  ```js
  let arr = [];
  console.log(Object.getPrototypeOf(arr) === Array.prototype); // true
  ```

* **`Object.setPrototypeOf()`**

  `obj`의 prototype을 `prototype`으로 설정한다.

  ```js
  Object.setPrototypeOf(obj, prototype)
  ```

  객체의 prototype을 동적으로 수정할 수 있다. 하지만 JavaScript engine이 property 접근을 최적화하는 방식의 특성상 prototype을 동적으로 수정하는 작업이 굉장히 느리기 때문에 성능을 위해서는 `Object.create()`를 사용해야 한다.

  > 처음에 잘못 이해했었는데 `Object.create()`는 해당 객체를 prototype으로 갖는 **새로운** 객체를 생성하는 것이기 때문에 기존에 존재하는 객체의 prototype을 수정해야만 하는 경우에는 `Object.setPrototypeOf()`를 사용해야 한다.

* **`Object.create()`**

  지정된 객체를 prototype을 갖는 새 객체를 만든다.

  ```js
  const obj = {};
  const obj2 = Object.create(obj);
  Object.getPrototypeOf(obj2) === obj; // true
  ```

  primitive wraper objects는 prototype으로 지정할 수 없다.

  또한 prototype으로 null을 지정할 수 있지만 `Object.prototype`의 함수들을 이용할 수 없기 때문에 이용에 주의해야 한다.

  ```js
  const obj = {};
  console.log("obj is: " + obj); // obj is: [object Object]
  
  const obj2 = Object.create(null);
  console.log("obj2 is: " + obj2); // Error
  ```

  * ##### Object.create()를 이용한  classical inheritance

    MDN 공식문서에 나와있는 예제

    ```js
    // Shape - superclass
    function Shape() {
      this.x = 0;
      this.y = 0;
    }
    
    // superclass method
    Shape.prototype.move = function(x, y) {
      this.x += x;
      this.y += y;
      console.info('Shape moved.');
    };
    
    // Rectangle - subclass
    function Rectangle() {
      Shape.call(this); // call super constructor.
    }
    
    // subclass extends superclass
    Rectangle.prototype = Object.create(Shape.prototype);
    
    //If you don't set Rectangle.prototype.constructor to Rectangle,
    //it will take the prototype.constructor of Shape (parent).
    //To avoid that, we set the prototype.constructor to Rectangle (child).
    Rectangle.prototype.constructor = Rectangle;
    
    var rect = new Rectangle();
    
    console.log('Is rect an instance of Rectangle?', rect instanceof Rectangle); // true
    console.log('Is rect an instance of Shape?', rect instanceof Shape); // true
    rect.move(1, 1); // Outputs, 'Shape moved.'
    ```

    위 예제에서의 prototype 연결 관계

    ![](./prototype_explain.png)

<br>

## Constructor functions

새로운 객체를 설계할때 사용되는 함수. 이름의 첫글자를 대문자로 사용하는것이 일반적이다.

instance 옆에서 `new` 연산자와 함께 사용된다. 이때 `new` 연산자는 `this`가 새롭게 생성되는 instance를 가리키도록 만들어준다.

```js
function Person(name, age) {
    this.name = name;
    this.age = age;
}

let joshua = new Person('Joshua', 23);
```

### Chain Constructor

`call()`을 활용해서 Constructor를 복사할 수 있다.

이때, `call()`을 사용하더라도 prototype이 연결되지는 않는다는 점에 주의하자.

```js
function Worker (name, age, job) {
    Person.call(this, name, age);

    this.job = job;
}
```

<br>

## Method

효율성 증가와 코드 가독성을 위해 method는 construction에 포함하지 않고 이후에 따로 prototype에 추가하는 것이 일반적이다.

prototype에 추가하고 나면 해당 prototype을 상속한 instance들은 모두 해당 method를 사용할 수 있다.

그리고 `this`의 특성상 `this`가 해당 메소드를 property로 갖는 객체를 가리키지 않고, 해당 메소드를 호출한 객체를 가리키기 때문에 자연스러운 상속이 가능하다.

```js
function Person(name, age) {
  this.name = name;
  this.age = age;
}
Person.prototype.introduce = function () {
  return `Hi my name is ${this.name}!`;
}

let joshua = new Person('Joshua', 23);
console.log(joshua.introduce()); // Hi my name is Joshua!

function Worker (name, age, job) {
  Person.call(this, name, age);

  this.job = job;
}

Object.setPrototypeOf(Worker.prototype, Person.prototype);

const james = new Worker('james', 24, 'programmer');
console.log(james.introduce()); // Hi my name is james!
```

**이때 method를 arrow function으로 만들어서는 안된다는 것에 주의하자.**<br>arrow function의 특성상 `this`가 해당 객체가 아닌 전역 객체를 가리키게 된다.

<br>

## Class

ES6부터 추가된 개념. prototype inheritance에 대한 **syntactical sugar**

Java 등의 클래스 기반 언어에 익숙하다면 `class`를 이용해 기존의 prototype inheritance를 보다 직관적인 문법으로 사용할 수 있다.

* 함수의 일종이다. 따라서 함수와 선언하는 방법도 비슷하고 `name` property도 갖는다.

* ### constructor

  * 해당 클래스의 instance를 생성할때 사용되는 특별한 메소드
  * class는 하나의 constructor만을 가질 수 있다.

* ### class body

  * strict mode에서 실행된다
  
* ### static

  * instance가 아닌 클래스가 자체적으로 갖는 property

    instance에서 호출할 수 없다.

  * `this`를 명시하지 않을 경우, class의 body 부분은 항상strict mode에서 처리되기 때문에 `this`로 `undefined`가 사용된다.
  
    ```js
    class Animal {
      speak() {
        return this;
      }
      static eat() {
        return this;
      }
    }
    
    let obj = new Animal();
    obj.speak(); // the Animal object
    let speak = obj.speak;
    speak(); // undefined
    
    Animal.eat() // class Animal
    let eat = Animal.eat;
    eat(); // undefined
    ```
  
  * static initialization block들을 통해 유연하게 static property들을 초기화 할 수 있다.
  
    > 단 safari, samsung internet 등 static initialization block이 지원되지 않는 브라우저가 꽤 있기 때문에 사용에 주의하는게 좋을 것 같다.
    
    ```js
    class ClassWithStaticInitializationBlock {
      static staticProperty1 = 'Property 1';
      static staticProperty2;
      static {
        this.staticProperty2 = 'Property 2';
      }
    }
    ```
    
  
* ### field declarations

  * instance property들을 명시적으로 선언할 수 있다.

  * default값을 지정하는 것도 가능하다.

  * fields 앞에 `#`을 붙여서 private하게 선언할 수 있다.

    그리고 private field는 field declaration을 통해서만 선언할 수 있다.

    ```js
    class MyClass {
        a = 0;
        #b;
        constructor(a, b) {
            this.a = a;
            this.b = b;
        }
    }
    ```

* ### sub classing with `extends`

  * 클래스 간의 상속 관계를 위해 `extends` 키워드가 제공된다.

  * `extends` 키워드를 사용해 상속받은 클래스를 명시하면, `super` 키워드를 통해 부모 클래스의 constructor를 사용할 수 있다. 그리고 부모 클래스가 자식 클래스의 prototype으로 자동으로 지정된다.

  * `extends` 키워드는 클래스에서만 사용이 가능하고 construct가 가능하지 않은 객체는 상속받을 수 없다.

  * 추가 개념

    * `Symbol.species`를 이용해서 `map()` 등의 함수 결과가 도출될때 사용할 constructor 함수를 지정할 수 있다.

    * 기본적으로 javascript는 다중상속을 지원하지 않지만 superclass를 입력받아서 해당 superclass를 상속받은 subclass를 반환하는 함수를 이용해 여러 개의 tooling 클래스를 상속받은 `mix-in`을 구현할 수 있다.

      ```js
      let calculatorMixin = Base => class extends Base {
        calc() { }
      };
      
      let randomizerMixin = Base => class extends Base {
        randomize() { }
      };
      
      class Foo { }
      class Bar extends calculatorMixin(randomizerMixin(Foo)) { }
      ```

* ### `super` keyword

  * constructor 뿐만 아니라 다른 메소드 또한 불러올 수 있다.

* 그리고 동일한 이름의 클래스를 여러 번 선언할 수 없다.

* 위의 `Person`, `Worker` 예제를 `class`를 이용해 작성한 코드를 보면서 확인해보자.

  ```js
  class Person {
  	constructor(name, age) {
  		this.name = name;
  		this.age = age;
  	}
  
  	introduce() {
  		return `Hi my name is ${this.name}!`;
  	}
  }
  
  let joshua = new Person("Joshua", 23);
  console.log(joshua.introduce()); // Hi my name is Joshua!
  
  class Worker extends Person {
    constructor(name, age, job) {
      super(name, age);
      this.job = job;
    }
  }
  
  const james = new Worker("james", 24, "programmer");
  console.log(james.introduce()); // Hi my name is james!
  ```


> **참고자료**
>
> 1. Classes - JavaScript | MDN. Mozilla.org. Published January 19, 2022. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes
> 2. Class static initialization blocks - JavaScript | MDN. Mozilla.org. Published January 19, 2022. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes/Class_static_initialization_blocks

<br>

## prototypal inheritance

javascript는 prototype 기반 언어로 prototypal inheritance를 지원한다. 이는 java 등의 언어에서 지원하는 classical inheritance와 차이점이 있다.

* https://stackoverflow.com/questions/19633762/classical-inheritance-vs-prototypal-inheritance-in-javascript/19640910#:~:text=Classical%20inheritance%20is%20limited%20to,also%20objects%20inheriting%20from%20prototypes.

  * https://stackoverflow.com/questions/2800964/benefits-of-prototypal-inheritance-over-classical

    * 초기에 만들어질때 java와 비슷해 보이기 위해 constructor 패턴을 사용해서 만들어졌지만 prototypal 패턴을 사용함으로써 얻을수있는 이점이 더 많다.

    * ### dynamic

      실행 중에 prototype의 property를 자유롭게 추가, 수정할 수 있다.

    * ### powerful & less redundant

      다중 상속이 가능하기 때문

    * ### simple

      객체와 객체간의 연결만이 존재한다

  * http://aaditmshah.github.io/why-prototypal-inheritance-matters/

    `new` keyword를 사용해서 객체를 생성하면 `apply()`를 사용할 수 없는 등 javascript의 함수형 측면을 활용할 수 없다.

    따라서 prototypal inheritance를 이용하고, `new` keyword는 가급적 사용하지 않는 것이 좋다고 한다.

* `📕 객체지향의 사실과 오해`를 읽다가 생각 난건데 클래스간에 상속 관계가 형성되는 것이 아니라 객체 간에 상속 관계가 형성되는 것이기 때문에 상위 객체가 변동되면 하위 객체에 직접적인 영향이 있다는 차이점도 있을 것 같다.

  > 클래스 간의 상속관계가 있더라도 해당 클래스로부터 생성된 객체끼리는 상태가 변동되더라도 서로 영향을 주지 않을 거라는 생각이 들었다.

<br><br>

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
