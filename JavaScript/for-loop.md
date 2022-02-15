# for 반복문

<br>

## for...in

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

* ### Array iteration

  index 순서대로 방문하는 것이 보장되지 않으므로 접근 순서가 중요할 경우 `Array.prototype.forEach()`나 `for...of`를 사용해야 한다.

* property name을 확인할 수 있기 때문에 디버깅에 유용하게 사용된다.

<br>

## for...of

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


<br><br>

> **참고자료**
>
> 1. for...in - JavaScript | MDN. Mozilla.org. Published January 5, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...in
> 2. for...of - JavaScript | MDN. Mozilla.org. Published January 21, 2022. Accessed February 3, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...of