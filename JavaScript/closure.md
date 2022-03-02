# closure

함수와 해당 함수가 선언된 환경(scope)이 남아있는 것

> " A **closure** is the combination of a function bundled together (enclosed) with references to its surrounding state (the **lexical environment**). " - MDN 공식문서

```js
function makeFunc() {
  var name = 'Mozilla';
  function displayName() {
    alert(name);
  }
  return displayName;
}

var myFunc = makeFunc();
myFunc();

```

Closures are useful because they let you associate data (the lexical environment) with a function that operates on that data

Consequently, you can use a closure anywhere that you might normally use an object with only a single method.

<br>

## 활용방안

### function factory

```
function makeSizer(size) {
  return function() {
    document.body.style.fontSize = size + 'px';
  };
}

var size12 = makeSizer(12);
var size14 = makeSizer(14);
var size16 = makeSizer(16);
```

문득 이렇게 작성하면 안되나?라는 생각이 들었다.

```js
function makeSizer(size) {
  document.body.style.fontSize = size + 'px';
}

var size12 = makeSizer(12);
var size14 = makeSizer(14);
var size16 = makeSizer(16);
```

하지만 다시 잘 생각해보니 이건 단순히 함수를 호출해서 반환값을 변수에 넣는 것이다.<br/>(그리고 이 예시에서는 반환값이 없으로 변수 `size12`는 `undefined`일 것이다.)

function으로 감싸서 반환함으로써 함수를 반환하는 것이다.

<br>

### **Module Design Pattern - private methods**

JavaScript에서는 private 같은 접근 제어자가 없다.<br/>하지만 closure와 IIFE를 활용해 private methods를 만듦으로써 객체지향 프로그래밍처럼 data hiding과 encapsulation의 이점을 얻을 수 있다.

```js
var counter = (function() {
  var privateCounter = 0;
  function changeBy(val) {
    privateCounter += val;
  }

  return {
    increment: function() {
      changeBy(1);
    },

    decrement: function() {
      changeBy(-1);
    },

    value: function() {
      return privateCounter;
    }
  };
})();
```

<br>

## 반복문 안에서의 closure

**주의** : 반복문 안에 만들어진 모든 closure는 하나의 lexical environment를 공유한다.

```js
function showHelp(help) {
  document.getElementById('help').textContent = help;
}

function setupHelp() {
  var helpText = [
      {'id': 'email', 'help': 'Your e-mail address'},
      {'id': 'name', 'help': 'Your full name'},
      {'id': 'age', 'help': 'Your age (you must be over 16)'}
    ];

  for (var i = 0; i < helpText.length; i++) {
    var item = helpText[i];
    document.getElementById(item.id).onfocus = function() {
      showHelp(item.help);
    }
  }
}

setupHelp();
```

예를 들어서 이 예제에서 만들어진 3개의 closure는 모두 `helpText[helpText.length - 1]`을 `item`으로 갖는다.

이를 해결하기 위해서는 각각의 closure가 독립적인 lexical environment를 사용하도록 만들어주면 된다. 그리고 이는 여러가지 방법을 통해 구현 가능하다.

<details><summary>function factory를 추가로 만들어서 사용한다.</summary>


```js
function showHelp(help) {
  document.getElementById('help').textContent = help;
}

function makeHelpCallback(help) {
  return function() {
    showHelp(help);
  };
}

function setupHelp() {
  var helpText = [
      {'id': 'email', 'help': 'Your e-mail address'},
      {'id': 'name', 'help': 'Your full name'},
      {'id': 'age', 'help': 'Your age (you must be over 16)'}
    ];

  for (var i = 0; i < helpText.length; i++) {
    var item = helpText[i];
    document.getElementById(item.id).onfocus = makeHelpCallback(item.help);
  }
}

setupHelp();
```

</details>

<details><summary>anonymous closures를 사용한다.</summary>


```js
function showHelp(help) {
  document.getElementById('help').textContent = help;
}

function setupHelp() {
  var helpText = [
      {'id': 'email', 'help': 'Your e-mail address'},
      {'id': 'name', 'help': 'Your full name'},
      {'id': 'age', 'help': 'Your age (you must be over 16)'}
    ];

  for (var i = 0; i < helpText.length; i++) {
    (function() {
       var item = helpText[i];
       document.getElementById(item.id).onfocus = function() {
         showHelp(item.help);
       }
    })(); // Immediate event listener attachment with the current value of item (preserved until iteration).
  }
}

setupHelp();

```

</details>

<details><summary>var 대신 let을 사용해서 변수를 선언한다.</summary>


```js
function showHelp(help) {
  document.getElementById('help').textContent = help;
}

function setupHelp() {
  var helpText = [
      {'id': 'email', 'help': 'Your e-mail address'},
      {'id': 'name', 'help': 'Your full name'},
      {'id': 'age', 'help': 'Your age (you must be over 16)'}
    ];

  for (var i = 0; i < helpText.length; i++) {
    let item = helpText[i];
    document.getElementById(item.id).onfocus = function() {
      showHelp(item.help);
    }
  }
}

setupHelp();
```

```js
function showHelp(help) {
  document.getElementById('help').textContent = help;
}

function setupHelp() {
  var helpText = [
      {'id': 'email', 'help': 'Your e-mail address'},
      {'id': 'name', 'help': 'Your full name'},
      {'id': 'age', 'help': 'Your age (you must be over 16)'}
    ];

  for (let i = 0; i < helpText.length; i++) {
    document.getElementById(helpText[i].id).onfocus = function() {
      showHelp(helpText[i].help);
    }
  }
}

setupHelp();

```

</details><br>

여러 개의 예시를 들었지만 이외에도 `forEach()`를 사용하는 등의 방법이 더 있다.

핵심은 각각의 closure가 독립적인 lexical environment를 사용하도록 주의하는 것이다.

<br>

## 성능 고려

closure를 잘 사용하면 정말 유용하지만 closure가 많아질수록 프로세싱 성능과 메모리 소비량이 늘어나면서 script의 성능은 낮아진다.

따라서 closure를 꼭 사용해야하는 경우가 아니라면 일반적으로 객체의 prototype에 method를 추가해서 사용한다.

> prototype을 아예 재정의할수도 있지만 권장되지 않는다.

```js
function MyObject(name, message) {
  this.name = name.toString();
  this.message = message.toString();
}
MyObject.prototype.getName = function() {
  return this.name;
};
MyObject.prototype.getMessage = function() {
  return this.message;
};
```

<br><br>

> **참고자료**
>
> Closures - JavaScript | MDN. Mozilla.org. Published February 18, 2022. Accessed March 1, 2022. https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures

