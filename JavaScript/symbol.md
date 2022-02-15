# symbol

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

<br>

## global Symbol registry

key값마다 Symbol을 하나씩 등록해서 공유해서 사용할 수 있다.

* **`Symbol.for("key")`**<br>key 값에 매칭되는 global symbol 반환<br>없는 경우 symbol을 새로 생성해서 global Symbol registry에 등록한다.
* **`Symbol.keyFor(sym)`**<br>해당 symbol에 해당되는 shared symbol key 반환<br>없는 경우 undefined 반환

* **`Symbol.for("key")`**은 key값에 항상 똑같은 Symbol을 반환해준다. key 값에 매칭되는 Symbol이 없는 경우 새로 생성해서 **global Symbol registry**에 등록한다.
* 일반적인 객체와 달리 string으로 자동형변환 되지 않는다.<br>string으로 변환하고 싶다면 `symbol.toString()`을 이용해야 한다.

<br>

## Constants

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

<br><br>

> **참고자료**
>
> 1. Symbol - MDN Web Docs Glossary: Definitions of Web-related terms | MDN. Mozilla.org. Published October 8, 2021. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Glossary/Symbol
> 2. Symbol - JavaScript | MDN. Mozilla.org. Published January 17, 2022. Accessed February 2, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol
> 3. Symbol.for() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol/for
> 4. Symbol.keyFor() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol/keyFor
> 5. Symbol.iterator - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol/iterator
> 6. Array.prototype[@@iterator]() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/@@iterator