# Ajax

Asynchronous JavaScript and XML

서버와 통신하는 과정을 비동기적으로 처리하기 위한 프로그래밍 개념

Ajax를 통해 웹페이지에 필요한 부분만 동적으로 수정하는 것이 가능하다.

이전에는 XML을 주로 사용했지만 현재는 JSON을 주로 사용하고 있다.

https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous

* https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous/Introducing

<br>

## Asynchronous JavaScript

자바스크립트는 기본적으로 싱글 쓰레드 언어이다.

하지만 동기적으로만 작업을 수행한다면 콜스택에서 작업이 수행되는동안 유저가 브라우저와 상호작용할 수 없는, **blocking**이라는 문제가 발생하게 된다.

따라서 JavaScript에서는 작업을 비동기적으로 처리할 수 있도록 여러 방법을 제공해준다.

* ### web API

  * ### async callback

    * event listener	

    * XMLHttpRequest

    * 일정 시간 뒤에 실행되는 함수

      이전에 말했듯이 자바스크립트는 싱글 쓰레드 언어이기 때문에 메인 쓰레드에 자리가 생겨야 실행될 수 있다. 따라서 사용자가 지정한 시간이 끝나더라도 메인 쓰레드에 자리가 없다면 곧바로 실행되지 않는다.

      또한 모든 작업은 메인 쓰레드에서 실행되기 때문에 남용할 경우 프로그램이 느려질 수 있으므로 주의해야 한다.
      
      * **`setTimeout()`**
      
        설정한 시간 뒤에 콜백 함수가 실행된다.
      
        `clearTimeout()`으로 실행 도중에 중지시킬 수 있다.
      
      * **`setInterval()`**
      
        설정한 시간 간격을 갖고 콜백 함수가 계속 실행된다.
      
        `clearInterval()`로 실행 도중에 중지시킬 수 있다.
      
      * **`requestAnimationFrame()`**
      
        애니메이션을 만들기에 최적화된 함수.
      
        기본적으로 화면이 repaint 되기 전 인자로 전달받은 콜백 함수를 실행시키고, 사용환경 등을 고려해서 60fps에 최대한 맞춰서 실행된다.
      
        인자로 전달할 콜백함수는 `timestamp`라는 `requestAnimationFrame()`이 시작된 시간을 parameter로 전달받아서 사용할 수 있다.
      
        `cancleAnimationFrame()`로 실행 도중에 중지시킬 수 있다.

  * ### fetch

    최근 XMLHttpRequest보다 많이 사용되는 Web API. Promise를 반환한다. 성공적으로 완료될 경우, response 객체를 반환한다.
    
    * response.ok
    * response.status

* ### Promises

  연산이 완료되기 전, 연산의 중간 상태를 나타내는 객체

  * pending : 작업이 처리되고 있는 상태
  * resolved : 작업이 완료된 상태
    * fulfilled : 작업 성공
    * rejects : 작업 실패
  
  async callback보다 에러 처리, 비동기 작업 연결 등의 작업이 편리하다.
  
  > callback 지옥을 피할 수 있다
  
  * **`then` block**은 연산이 성공적으로 완료될 경우 실행되고, 연산의 결과값을 매개변수로 전달받아 실행된다.
  
    `then` block은 새로운 Promise를 반환하기 때문에 여러 비동기 작업들이 순차적으로 실행되도록 만들 때 유용하게 사용할 수 있다.
  
  * **`catch` block**은 연산이 실패했을 경우 실행되고, 발생한 에러를 매개변수로 전달받아 실행된다.
  
  * **`finally` block**은 성공/실패 여부와 관계없이 마지막에 공통적으로 실행된다.
  
  **`Promise.all()`** 정적 메소드를 사용해서 여러 개의 비동기 작업을 묶어서 Promise를 생성할 수 있다. 즉, 여러 개의 비동기 작업이 성공해야 특정 작업이 수행되도록 만들 수 있다.
  
  **Promise() 생성자**를 사용해서 `setTimeout` 등 Promise를 반환하지 않는 Web API 들도 Promise를 이용해서 관리할 수 있다.
  
  * `resolve()`, `reject()`를 사용해서 Promise를 완료할 수 있다.
  
  ```javascript
  let timeoutPromise = new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve('Success!');
    }, 2000);
  });
  ```

##### Q. 싱글 쓰레드 언어인 JavaScript 내에서 이러한 비동기적인 작업들이 어떤 식으로 처리될까?

`setTimeout()`을 예로 들어서 설명하자면

1. `setTimeout()` 함수가 호출되어서 stack에 들어온다.

2. `setTimeout()` 함수는 web API이기 때문에 해당 함수는 브라우저에서 독립적으로 실행된다. (타이머가 동작한다)

   이로써 JavaScript는 `setTimeout()`에 대한 작업이 모두 완료되었다.

3. `setTimeout()`을 stack에서 제거하고, JavaScript는 다른 작업들을 이어서 처리한다.

4. 타이머가 종료되면 콜백함수가 `task queue`에 저장된다.

5. task queue와 stack을 관리하는 `event loop`에서 stack이 비어있다면 taskqueue에서 작업을 꺼내서 stack에 넣어준다.

6. 1번에서 `setTimteout()`의 인자로 전달된 콜백함수가 실행된다.

따라서 `setTimeout()`에 시간인자로 0을 전달하면 아무 의미가 없을 것 같아보여도 stack이 비어있을때까지 기다린 뒤, 작업이 수행되므로 많은 차이가 있다.

> JavaScript 내에서 비동기적인 함수들이 어떤식으로 동작하는지 의문을 갖고 찾아보던중 찾게 된 [유튜브 영상](https://www.youtube.com/watch?v=8aGhZQkoFbQ)이 이해하는데 많은 도움이 되었다.

<br>

##### Q. Promise라는 개념은 web api와는 다르게 동작하나?

##### Q. web API가 아닌 사용자 정의 함수 async, await 함수는 어떤 방식으로 처리될까?

promise는 aysnc operation을 보다 간편하게 처리하기 위한 도구에 불과하고 비동기적인 작업은 모두 web API를 통해서 이루어지는건가?

<br>

##### Q. `setTimeout()`을 재귀적으로 호출 vs `setInterval()`

* **`setInterval()`**

  콜백 함수가 실행되는 시간을 기준으로 동작

  따라서 콜백 함수가 다시 실행되기까지 걸리는 시간이 설정한 시간보다 짧을 수 있다.

* **`setTimeout()` 재귀적 사용**

  콜백 함수가 종료되는 시간을 기준으로 동작

  콜백 함수가 다시 실행되기까지 걸리는 시간이 무조건 설정한 시간보다 길다.
  
  <br>

##### Q. setTimeout() 콜백 함수에 parameter 전달시 주의사항

```js
setTimeout(() => cancelAnimationFrame(rAf), 1000);
```

```js
setTimeout(cancelAnimationFrame, 1000, rAf);
```

```js
setTimeout(alert, 1000, "Hello");
```

1, 3번째 코드는 잘 동작하는데, 2번째 코드는 잘 동작하지 않는다.

어떻게 구글링을 해야할지도 감이 잘 안 잡혀서 stackoverflow에 질문을 올렸다. https://stackoverflow.com/questions/71273265/why-using-cancelanimationframe-as-callback-at-settimeout-not-working

* 2번째처럼 콜백함수를 전달할 경우 `rAf`가 `setTimeout()`이 호출됐을 때의 값으로 고정되기 때문에 타이머가 끝난뒤에는 `rAf`와 콜백함수가 가리키는 코드가 달라지고, 정상적으로 동작하지 않게 된다.
* arrow 함수를 사용할 경우, 타이머가 끝난뒤에 `rAf`가 호출되기 때문에 원하는 결과를 얻을 수 있다.

따라서 콜백 함수에 전달하는 매개변수의 값이 타이머가 동작하는 도중 값이 바뀔 가능성이 있는 경우, 화살표 함수나 익명 함수로 감싸서 사용해야 한다.

<br><br>

> **참고자료**
>
> 1. Wikipedia Contributors. Ajax (programming). Wikipedia. Published January 20, 2022. Accessed February 6, 2022. https://en.wikipedia.org/wiki/Ajax_(programming)
> 2. Asynchronous JavaScript - Learn web development | MDN. Mozilla.org. Published October 8, 2021. Accessed February 19, 2022. https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous
> 3. Ahuja M. How are Promises implemented in Javascript without threads. Stack Overflow. Published August 1, 2014. Accessed February 19, 2022. https://stackoverflow.com/questions/25082867/how-are-promises-implemented-in-javascript-without-threads
> 4. punjani. How does JavaScript handle AJAX responses in the background? Stack Overflow. Published September 27, 2011. Accessed February 19, 2022. https://stackoverflow.com/questions/7575589/how-does-javascript-handle-ajax-responses-in-the-background/7575649#7575649
> 5. Barbour B. If Javascript Is Single Threaded, How Is It Asynchronous? DEV Community. Published June 3, 2019. Accessed February 19, 2022. https://dev.to/bbarbour/if-javascript-is-single-threaded-how-is-it-asynchronous-56gd
> 6. JSConf. What the heck is the event loop anyway? | Philip Roberts | JSConf EU. *YouTube*. Published online October 9, 2014. Accessed February 19, 2022. https://www.youtube.com/watch?v=8aGhZQkoFbQ
> 7. Latentflip.com. Published 2022. Accessed February 19, 2022. http://latentflip.com/loupe/?code=JC5vbignYnV0dG9uJywgJ2NsaWNrJywgZnVuY3Rpb24gb25DbGljaygpIHsKICAgIHNldFRpbWVvdXQoZnVuY3Rpb24gdGltZXIoKSB7CiAgICAgICAgY29uc29sZS5sb2coJ1lvdSBjbGlja2VkIHRoZSBidXR0b24hJyk7ICAgIAogICAgfSwgMjAwMCk7Cn0pOwoKY29uc29sZS5sb2coIkhpISIpOwoKc2V0VGltZW91dChmdW5jdGlvbiB0aW1lb3V0KCkgewogICAgY29uc29sZS5sb2coIkNsaWNrIHRoZSBidXR0b24hIik7Cn0sIDUwMDApOwoKY29uc29sZS5sb2coIldlbGNvbWUgdG8gbG91cGUuIik7!!!PGJ1dHRvbj5DbGljayBtZSE8L2J1dHRvbj4%3D