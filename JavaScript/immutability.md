# Immutability

## Primitive datatype

JavaScript에서 primitive datatype은 모두 immutable하다.

<br>

## Object

그리고 객체의 경우 내용을 수정할 수 없는 객체를 **immutable object**라고 한다.<br>immutable object를 사용함으로써 다음과 같은 장점을 얻을 수 있다.

* **성능 개선**<br>추후에 내용이 변경될 가능성이 없기 때문
* **메모리 사용량 감소**<br>동일한 내용의 객체를 여러 개 사용할 이유가 없다.
* **Thread-safety**<br>쓰레드가 immutable한 객체에 접근하더라도 객체의 내용이 변경되지 않기 때문에 다른 쓰레드에 영향을 미칠 가능성이 사라진다.

<br>

### `Object.freeze()`

객체가 더 이상 수정되지 못하도록 객체를 얼릴 수 있다.

`freeze`된 객체에 다음과 같은 작업을 시도할 경우, TypeError가 발생한다.

* 새로운 property 추가
* 기존에 있던 property 제거 혹은 수정
* prototype 변경

하지만 property가 참조하고 있는 object까지 freeze되지는 않는다는 것에 주의하자.

```js
const employee = {
  name: "Mayank",
  designation: "Developer",
  address: {
    street: "Rohini",
    city: "Delhi"
  }
};

Object.freeze(employee);

employee.name = "Dummy"; // fails silently in non-strict mode
employee.address.city = "Noida"; // attributes of child object can be modified

console.log(employee.address.city) // Output: "Noida"
```

<br>

> **참고자료**
>
> 1. Immutable - MDN Web Docs Glossary: Definitions of Web-related terms | MDN. Mozilla.org. Published October 8, 2021. Accessed February 6, 2022. https://developer.mozilla.org/en-US/docs/Glossary/Immutable
> 2. JavaScript Immutability. JavaScript Immutability. Published May 7, 2019. Accessed February 6, 2022. https://opentutorials.org/module/4075
> 3. Object.freeze() - JavaScript | MDN. Mozilla.org. Published July 20, 2021. Accessed February 6, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/freeze