# Array

JavaScript에서 배열은 길이가 고정되어 있지 않고, Type에 관계없이 item을 넣을 수 있다.

```js
var a = ['dog', 'cat'];
a[100] = 3123124;
a.length; // 101
```

<br>

## 선언방법

```js
let arr = [];
let arr2 = new Array();
```

<br>

## Spread Syntax

```js
myFunction(...iterableObj);
```

배열을 분해해서 각각의 item들을 인자로 전달할 수 있다.

```js
let arr = [1, 2];
const sum = (a, b) => a + b;

console.log(sum(...arr)); // 3
```

> **참고자료**
>
> Spread syntax (...) - JavaScript | MDN. Mozilla.org. Published February 18, 2022. Accessed March 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Spread_syntax

<br>

## Methods

### mutator methods

* `isArray()` : 배열인지 아닌지 확인

* `sort(compareFunction(a, b))` : 정렬, `compareFunction(a, b)`는 optional

  `compareFunction(a, b)`의 반환값은 음수, 0, 양수로 나뉜다.

* `fill(value, start, end)` : `value`로 초기화. `start`, `end`는 optional..

* `splice(start, deleteCount, item1, item2, itemN)` : `start` 인덱스부터 `deleteCount`만큼 삭제하고 전달받은 `item`만큼 `start` 인덱스에 추가.

* `pop()` : 뒤에서 빼기

* `shift()` : 앞에서 빼기

* `push()` : 뒤에서 넣기

* `unshift()` : 앞에서 넣기

* `reverse()` : 순서 바꾸기

### accessor methods

* `concat(value0, value1, ... , valueN)` : array 여러개 연결

  인자 없이 `concat()`을 사용해서 해당 배열과 동일한 요소를 가진 새로운 배열을 만들 수도 있다. (깊은 복사)

* `join(separator)` : array -> string, `separator` optional

* `slice(start, end)` : `start`, `end`는 optional. 없으면 끝까지

  > ##### **`concat()` vs `slice()` for array copy**
  >
  > 성능면에서는 같지만 `slice()`가 애초에 배열을 복사하기 위해 나온 메소드이므로 좀 더 직관적이다.
  >
  > 또한 두 경우 모두 객체 요소는 reference를 복사하기 때문에 얕은 복사가 이루어진다는 점에 주의.

* `indexOf(searchElement, fromIndex)` : elementrk 처음 등장하는 위치를 찾는 메소드. `fromIndex`(검색을 시작할 인덱스) optional. 
* `lastIndexOf(searchElement, fromIndex)` : 마지막으로 등장하는 위치를 찾는다는 점을 제외하면 `indexOf()`와 동일.

### iteration methods

* `forEach(callbackFn)` : 모든 요소에 대해 `callbackFn` 수행. `for`문을 사용하는 것보다 가독성이 좋다.

* `map(callbackFn)` : 모든 요소에 대해 `callbackFn`을 수행하고, 반환값을 배열로 묶어서 반환.

* `filter(callbackFn)` : 모든 요소에 대해 `callbackFn`을 수행한 결과값이 true인 요소만 모아서 배열로 반환. 

* `reduce(function(previousValue, currentValue) { })` : 배열을 하나의 결과값으로 만드는 함수

* `find(callbackFn)` : `callbackFn`을 수행한 결과가 참인 맨 첫번째 요소를 반환.

* `findIndex()` : 요소의 값이 아닌 인덱스를 반환하는 점을 제외하면 `find()`와 동일

* `flat(depth)` : depth 기본값 1. depth만큼 subarray의 값을 배열로 다시 포함시킨 결과 반환

  ```js
  const arr = [1, 2, [3, 4, [5, 6]]];
  
  arr.flat(); // [1, 2, 3, 4, [5, 6]]
  
  arr.flat().flat(); // [1, 2, 3, 4, 5, 6]
  ```

<br><br>

> **참고자료**
>
> 1. Rascia T. How To Use Array Methods in JavaScript: Mutator Methods. Digitalocean.com. Published August 10, 2017. Accessed February 13, 2022. https://www.digitalocean.com/community/tutorials/how-to-use-array-methods-in-javascript-mutator-methods
> 2. Array.prototype.sort() - JavaScript | MDN. Mozilla.org. Published February 4, 2022. Accessed February 13, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort
> 3. Rascia T. How To Use Array Methods in JavaScript: Accessor Methods. Digitalocean.com. Published August 14, 2017. Accessed February 13, 2022. https://www.digitalocean.com/community/tutorials/how-to-use-array-methods-in-javascript-accessor-methods
> 4. caiwf. Javascript array copying, concat vs slice, which one is better? Stack Overflow. Published July 23, 2013. Accessed February 13, 2022. https://stackoverflow.com/questions/17803586/javascript-array-copying-concat-vs-slice-which-one-is-better
> 5. Array.prototype.findIndex() - JavaScript | MDN. Mozilla.org. Published February 4, 2022. Accessed February 13, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/findIndex