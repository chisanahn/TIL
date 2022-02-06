# Script Loading Strategies

script가 어떻게 loading 되느냐에 따라서 성능이 달라질 수 있고, 오류가 생길수도 있기 때문에 상황에 맞는 script loading strategy를 선택하는 것은 중요하다.

## internal script

### 0. `DOMContentLoaded` event

`DOMContentLoaded` event를 활용하여 DOM 생성이 완료된 후에 실행되도록 만들 수 있다.

```js
document.addEventListener('DOMContentLoaded', () => {
  ...
});
```

## external script

### 1. script 태그 위치

script를 만나면 HTML parsing을 멈추고 script를 다운 후 실행까지 진행하기 때문에 body 태그의 맨 마지막에 script 태그를 두는 방법.

예전에 주로 사용했던 방법으로 script의 용량이 큰 사이트의 경우 성능이 안 좋아진다는 단점이 있다.

이어서 소개할 2번과 3번은 script 파일 다운로드를 비동기적으로 처리하기 때문에 1번에 비해 성능이 뛰어나다.

### 2. `async`

script 태그에 `async` attribute를 추가하는 방법

```html
<script src="script.js" defer></script>
```

script 파일을 비동기적으로 다운받고, 다운이 완료되는대로 다른 작업을 멈추고 실행된다.

독립적으로 동작하는 script의 경우에 유용하다.

### 3. `defer`

script 태그에 `defer` attribute를 추가하는 방법

```html
<script src="script.js" defer></script>
```

script 파일을 비동기적으로 다운받고, 모든 작업이 끝난뒤에 html 파일에 나와있는 순서대로 실행된다.

script 실행 순서가 중요하거나 script 내에서 DOM 요소를 사용하는 경우에 주로 사용한다.

> 참고로 내부 script에서는 `defer`를 사용할 수 없다.

<br><br>

> **참고자료**
>
> What is JavaScript? - Learn web development | MDN. Mozilla.org. Published December 28, 2021. Accessed February 6, 2022. https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/What_is_JavaScript#script_loading_strategies