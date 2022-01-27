# JavaScript

## script loading stratgies

### internal script

##### `DOMContentLoaded` event

`DOMContentLoaded` event를 활용하여 DOM 생성이 완료된 후에야 실행되도록 만들 수 있다.

### external script

##### 1. body 태그의 맨 마지막에 script 태그 두기

예전에 주로 사용했던 방법. 용량이 큰 사이트의 경우 성능이 안 좋아진다는 단점이 있다.

2번과 3번은 script 파일 다운로드와 HTML parsing를 같이 진행하기 때문에 성능에서 이점을 얻을 수 있다.

##### 2. script 태그에 `async` attribute 추가

script 파일을 다운이 완료되는대로 실행되기 때문에 독립적으로 동작하는 script의 경우에 유용하다. 그리고 실행하는 동안 나머지 다운로드는 멈춘다.

##### 3. script 태그에 `defer` attribute 추가

script 파일을 HTML parsing이 모두 끝난 후 순서대로 실행한다.

> **참고자료**
>
> 1. What is JavaScript? - Learn web development | MDN. Mozilla.org. Published December 28, 2021. Accessed January 27, 2022. https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/What_is_JavaScript

<br>

## Prototypes and Inheritance

JavaScript는 prototype-based language이다.

**Prototypes** : 모든 객체가 공유하는 것

따라서 

> **참고자료**
>
> Rascia T. Understanding Prototypes and Inheritance in JavaScript. DigitalOcean. Published January 12, 2018. Accessed January 27, 2022. https://www.digitalocean.com/community/tutorials/understanding-prototypes-and-inheritance-in-javascript

## Classes

ES6부터 추가된 개념. prototype과 inheritance에 대한 **syntactical sugar**



> **참고자료**
>
> Rascia T. Understanding Classes in JavaScript. DigitalOcean. Published May 4, 2018. Accessed January 27, 2022. https://www.digitalocean.com/community/tutorials/understanding-classes-in-javascript

<br>

* Event
* Closure
* asynchronous JavaScript