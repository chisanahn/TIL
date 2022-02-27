# Event

<br>

## event handler & event listener

* `addEventListener()`를 이용해서 특정 이벤트에 대한 eventlistener를 추가할 수 있다.
* event가 발생하면 `Event` 객체가 eventlistener에 전달된다.
* `removeEventListener()`를 이용해서 특정 이벤트에 대한 eventlistener를 제거할 수 있다.

<br>

## event types

* ### mouse events

  * `click` = `mousedown` + `mouseup`

  * `dblclick`

  * `mouseenter`

  * `mouseleave`

  * `mousemove`

* ### form events

  * `submit`

  * `focus`

  * `blur`

  * ##### JS를 이용해서 form을 전송할때의 장점

    * 페이지 리로딩 x
    * JS로 입력값 검증 가능

* ### keyboard events

  * `keydown`
  * `keyup`
  * `keypress`

<br>

## property

* `target`
* `key`
* `code`

<br><br>

> **참고자료**
>
> Rascia T. Understanding Events in JavaScript. Digitalocean.com. Published June 19, 2018. Accessed February 13, 2022. https://www.digitalocean.com/community/tutorials/understanding-events-in-javascript