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

* web API

  * async callback

    * event listener	

    * XMLHttpRequest

    * 일정 간격을 두고 실행되는 함수

      > 이전에 말했듯이 자바스크립트는 싱글 쓰레드 언어이기 때문에 메인 쓰레드에 자리가 생겨야 실행될 수 있다. 따라서 사용자가 지정한 시간이 끝나더라도 메인 쓰레드에 자리가 없다면 곧바로 실행되지 않는다.

      * setTimeOut()
      * setInterval()
      * requestAnimationFrame()
      * `clearInterval()`로 해당 API를 중간에 중지시킬 수 있다.

  * Promises

    * fetch

* Promises

  async callback보다 편리하다. (에러 처리, 작업 연결 등)

  * then
  * catch

##### Q. 이러한 비동기적인 작업들은 JavaScript 내에서 어떤 식으로 처리될까?

`setTimeout()`을 예로 들어서 설명하자면

1. `setTimeout()` 함수가 호출되어서 stack에 들어온다.

2. `setTimeout()` 함수는 web API이기 때문에 해당 함수는 브라우저에서 독립적으로 실행된다. (타이머가 동작한다)

   이로써 JavaScript는 `setTimeout()`에 대한 작업이 모두 완료되었다.

3. `setTimeout()`을 stack에서 제거하고, JavaScript는 다른 작업들을 이어서 처리한다.

4. 타이머가 종료되면 콜백함수가 `task queue`에 저장된다.

5. task queue와 stack을 관리하는 `event loop`에서 stack이 비어있다면 taskqueue에서 작업을 꺼내서 stack에 넣어준다.

6. 1번에서 `setTimteout()`의 인자로 전달된 콜백함수가 실행된다.

따라서 `setTimeout()`에 시간인자로 0을 전달하면 아무 의미가 없을 것 같아보여도 stack이 비어있을때까지 기다린 뒤, 작업이 수행되므로 많은 차이가 있다.

> JavaScript 내에서 비동기적인 함수들이 어떤식으로 동작하는지 의문을 갖고 찾아보던중 찾게 된 [유튜브 영상](https://www.youtube.com/watch?v=8aGhZQkoFbQ)이 이해하는데 많은 도움이 되었다.

##### Q. Promise라는 개념은 web api와는 다르게 동작하나?

##### Q. web API가 아닌 사용자 정의 함수 async, await 함수는 어떤 방식으로 처리될까?

promise는 aysnc operation을 보다 간편하게 처리하기 위한 도구에 불과하고 비동기적인 작업은 모두 web API를 통해서 이루어지는건가?

##### 

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