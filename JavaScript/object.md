# Object

object는 단순하게 생각하면 name-value pairs의 집합, 즉 property의 집합이라고 할 수 있다.

<br>

## Property

간단하게 object에 첨부된 변수라고 생각하면 된다

일반적인 JavaScript와 마찬가지로 이름은 camelCase를 따른다.

name과 value가 한 쌍을 이룬다.

<br>

### property name

key라고도 한다.

property name으로 `string`이나 `symbol`을 사용할 수 있다.

<br>

### property 접근 방법

#### 1. dot notation

```js
object.propertyName
```

#### 2. bracket notation

```js
object['propertyName']
```

괄호 안에 변수를 사용하는 것도 가능하다.<br>property name이 동적으로 결정될때 유용하게 사용할 수 있다.

```js
let key = prompt('input key');
obj[key] = prompt('input value');
```

또한 bracket notation을 사용할 경우 identifier 규칙과 무관하게 정말 모든 문자열을 property name으로 사용할 수 있다.

```js
const obj2 = {};
obj2[' '] = 1234;
obj2['123'] = 1234;
obj2['$&#(!(@'] = "wow";
```

<br>

### Property Descriptor

property의 설정을 담고 있는 객체.

property를 할당할때 property descriptor를 이용해서 property를 구체적으로 설정하기 위해서는 **`Object.defineProperty()`**를 사용해야 한다.

그 외에 object initializer를 사용하거나 dot notation, bracket notation을 사용해서 property를 할당하는 경우 기본적으로 **configurable**하고 **enumerable**하게 data property descriptor가 지정된다.

```js
const obj = {};
obj.a = 1234;
console.log(Object.getOwnPropertyDescriptor(obj, 'a'));
// { value: 1234,
//   writable: true,
//   enumerable: true,
//   configurable: true }
```

property descriptor는 크게 **data descriptor**와 **accessor descriptor**로 나뉜다.

* 공통적으로 갖는 `key`

  * **`configurable`** : descriptor 수정 가능 여부, 기본값은 `false`
  * **`enumerable`** : iteration 등의 작업을 수행할때 enumerable한 property만 반복하는 경우가 많다. 기본값은 `false`

* data descriptor만 갖는 `key`

  * **`value`** : property의 값. 기본값은 `undefined`
  * **`writable`** : `value` 수정 가능 여부. 기본값은 `false`

  ```js
  var o = {};
  
  Object.defineProperty(o, 'a', {
    value: 37,
    writable: true,
    enumerable: true,
    configurable: true
  });
  ```

* accessor descriptor만 갖는 `key`

  * **`get`** : getter 함수
  * **`set`** : setter 함수

  ```js
  var o = {};
  var bValue = 38;
  Object.defineProperty(o, 'b', {
    get() { return bValue; },
    set(newValue) { bValue = newValue; },
    enumerable: true,
    configurable: true
  });
  o.b;
  ```

* 2개의 property descriptor를 동시에 사용하면 TypeError가 발생한다.

  ```js
  Object.defineProperty(o, 'conflict', {
    value: 0x9f91102,
    get() { return 0xdeadbeef; }
  });
  // throws a TypeError
  ```

<br>

### Method

javascript에서 함수는 객체이기 때문에 property value로 함수도 가질 수 있다.

객체의 property로 존재하는 함수를 method라고 한다.

#### binding

javascript에서 method는 객체에 종속되지 않는다.

정확히는 `this`가 가리키는 값이 함수가 호출될 때 정해진다.

예를 들어 constructor에서 `this`는 새로 생성되는 객체의 인스턴스를 가리킨다.

#### method definintions

ES 2015부터 object initializer에서 method를 더 간단하게 정의할 수 있게 되었다.

기존 방식은 `property name: function(매개변수)` 형식으로 사용해야 했었는데

```js
const obj = {
    foo: function() {
        // ...
    }
}
```

이제는 `property name (매개변수)` 형식으로 `: function` 부분을 생략해서 간략하게 사용할 수 있다.

```js
const obj = {
    foo() {
        // ...
    }
}
```

또한 bracket notation을 활용할 수도 있다.

```js
let propertyName = 'abc';

const obj = {
    [propertyName] () {
        // ...
    }
}
```

**주의** : method definitions로 정의된 함수는 constructor로 사용할 수 없다

[자세한 내용은 MDN 문서를 참고하자.](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Method_definitions)

#### getter & setter

`get` keyword를 이용해서 해당 property가 호출될때 해당 함수가 실행되도록 할 수 있다.

그리고 `set` keyword를 이용해서 해당 property의 값이 변경될때 해당 함수가 실행되도록 할 수 있다.

```js
const obj = {
	a: [1, 3, 2],
	get sortedA() {
		return this.a.sort((a, b) => a - b);
	},
	set setFirstItemOfA(newValue) {
		this.a[0] = newValue;
	}
};

obj.setFirstItemOfA = 10;

console.log(obj.a); // [ 10, 3, 2 ]

console.log(obj.sortedA); // [ 2, 3, 10 ]
```

<br>

### Enumerability and ownership of properties

property의 enumeraibility와 ownership에 따라 메소드별로 해당 property에 접근할 수 있는지 여부가 결정된다.

[MDN에 메소드별로 어떤 property들을 접근할 수 있는지 표 형식으로 잘 정리되어 있다](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Enumerability_and_ownership_of_properties#detection_table)

예를 들어서 설명하자면 `for...in`의 경우 enumerable하고 prototype으로부터 상속받은 property까지 포함해서 반복을 수행한다.

이때 Array에서 `for...in`을 사용하면 item의 key 값에 대해서 반복을 수행하는데 이때 method의 이름이 포함되지 않는 이유는 method는 non-enumerable property이기 때문이다.

```js
const arr = [1, 2, 3];

for (let item in arr) {
	console.log(item); // 0, 1, 2
}

console.log(Object.getOwnPropertyDescriptor(Array.prototype, 'fill'));
// { value: [λ: fill],
// 	 writable: true,
// 	 enumerable: false,
// 	 configurable: true }
```

<br>

### Indexing object properties

object property를 index를 기반으로 정의했으면 추후에 index를 통해서만 접근할 수 있고, name을 기반으로 정의했다면 추후에 name을 통해서만 접근할 수 있다는데 무슨 말인지 잘 모르겠다.

<br><br>

### property 관련 메서드

#### `Object.defineProperty()`

property descriptor를 이용해서 property를 좀 더 구체적으로 설정할 수 있다.

```js
Object.defineProperty(obj, prop, descriptor)
```

<br>

####  `Object.getOwnPropertyDescriptor()` 

객체의 own property의 descriptor 반환

```js
Object.getOwnPropertyDescriptor(obj, prop)
```

<br>

#### `Object.prototype.hasOwnProperty()`

객체가 해당 property를 own property로 가지고 있는지 여부를 반환

```js
hasOwnProperty(prop)
```

```js
const object1 = {};
object1.property1 = 42;

console.log(object1.hasOwnProperty('property1')); // true
```

다음과 같은 **문제점**이 있기 때문에 브라우저에서 지원해준다면 `Object.hasOwn()` 메소드를 사용하는 것이 좋다.

* `Object.create(null)`로 만들어진 경우 사용불가
* `hasOwnProperty`를 property name으로 사용자가 사용할 수 있다.

<br>

#### `Object.hasOwn()`

객체가 해당 property를 own property로 가지고 있는지 여부를 반환

`Object.prototype.hasOwnProperty()`을 대체하기 위해 만들어진 메소드

```js
Object.hasOwn(instance,prop)
```

다만, 브라우저에 따라 아직 지원해주지 않을 수 있다.

<br>

#### `Object.assign()`

sources에서 모든 enumerable own properties를 target에 복사한다.

```js
Object.assign(target, ...sources)
```

```js
const o1 = { a: 1, b: 1, c: 1 };
const o2 = { b: 2, c: 2 };
const o3 = { c: 3 };

const obj = Object.assign({}, o1, o2, o3);
console.log(obj); // { a: 1, b: 2, c: 3 }
```

<br>

#### `delete` operator

객체에서 property를 제거할 때 사용하는 연산자

non-configurable property는 삭제되지 않는다

```js
delete object.property
delete object['property']
```

<br>

#### `in` operator

객체에 property가 있는지 확인할 때 사용하는 연산자

```js
prop in object
```

* prototype chain까지 포함해서 체크한다

  ```js
  let trees = ['redwood', 'bay', 'cedar', 'oak', 'maple'];
  
  0 in trees; // true
  'length' in trees // true
  ```

* delete된 property에 대해서는 false를 리턴하지만, undefined에 대해서는 true를 리턴한다.

  ```js
  let mycar = {make: 'Honda', model: 'Accord', year: 1998};
  
  delete mycar.year;
  'year' in mycar; // false
  
  mycar.make = undefined;
  'make' in mycar;   // true
  ```

  배열의 empty slot에 대해서는 undefined임에도 불구하고 false가 리턴된다.

  ```js
  let empties = new Array(3)
  empties[2] // returns undefined
  2 in empties  // returns false
  ```

<br><br>

## 새로운 객체 생성하는 방법

### 0. 빈 객체 생성

빈 객체를 생성한 후 property를 추가하는 식으로 객체를 생성할 수 있다.

```js
const rect = new Object(); // const obj = {};

rect['x'] = 10;
rect.y = 10;
rect.getSize = function() {
    return this.x * this.y;
}
```

### 1. object initializer

`,`로 여러가지 property를 구분해서 객체를 초기화 할 수 있다.

```js
const rect = {
  x: 10,
  y: 10,
  getSize() {
    return this.x * this.y;
  }
}
```

### 2. Construction 함수 이용

```js
const MyRect = function (x, y) {
    this.x = x;
    this.y = y;
}

MyRect.prototype.getSize = function() {
    return this.x * this.y;
}

const rect = new MyRect(10, 20);
```



<br><br>

## Copy objects

### Shallow copy

동일한 object에 대해서 reference만 복사하는 것

### Deep copy

내용만 동일한 object를 새로만드는 것

<br><br>

## Destructing assignment

array의 value나 object의 property들을 쪼개서 개별적인 변수에 할당할 수 있다.

배열은 `[]`, 객체는 `{}`를 사용하는 것에 주의하자.

```js
const foo = ['one', 'two', 'three'];

const [red, yellow, green] = foo;
console.log(red); // "one"
console.log(yellow); // "two"
console.log(green); // "three"

({ a, b } = { a: 10, b: 20 });
console.log(a); // 10
console.log(b); // 20
```

여러 개의 변수에 동시에 값을 할당할때에도 유용하게 사용할 수 있다.

```js
let a, b;

[a, b] = [1, 2];
console.log(a); // 1
console.log(b); // 2
```

### Swapping variables

간단한 변수 간의 값 교환에도 활용할 수 있다.

```js
let a = 1, b = 3;
[a, b] = [b, a];
console.log(a); // 3
console.log(b); // 1

const arr = [1,2,3];
[arr[2], arr[1]] = [arr[1], arr[2]];
console.log(arr); // [1,3,2]
```

<br>



<br><br>

> **참고자료**
>
> 1. Working with objects - JavaScript | MDN. Mozilla.org. Published January 7, 2022. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Working_with_Objects
> 2. Property accessors - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Property_Accessors
> 3. Object.defineProperty() - JavaScript | MDN. Mozilla.org. Published September 19, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/defineProperty
> 4. Object.getOwnPropertyDescriptor() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/getOwnPropertyDescriptor
> 5. Object.assign() - JavaScript | MDN. Mozilla.org. Published September 17, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/assign
> 6. Object.prototype.hasOwnProperty() - JavaScript | MDN. Mozilla.org. Published September 7, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/hasOwnProperty
> 7. delete operator - JavaScript | MDN. Mozilla.org. Published January 24, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/delete
> 8. Destructuring assignment - JavaScript | MDN. Mozilla.org. Published January 19, 2022. Accessed February 4, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment
> 9. Method definitions - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 6, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Method_definitions
> 10. getter - JavaScript | MDN. Mozilla.org. Published January 19, 2022. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/get
> 11. setter - JavaScript | MDN. Mozilla.org. Published September 17, 2021. Accessed February 12, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/set
