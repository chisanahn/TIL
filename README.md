# HTML_CSS 기초 공부

React를 공부하려고 공식 문서를 읽다가 그동안 HTML과 CSS에 대해서 수박 겉핥기 식으로만 공부하고 제대로 공부한 적이 없다는걸 깨닫고 기본기부터 다시 다지자는 생각으로 공부를 시작

참고자료: https://www.internetingishard.com/html-and-css/

---

### 1 ~ 3

일단 Skip. 나중에 여유 시간에 복습 겸 추가.

### 4. CSS 기초

CSS는 크게 SELECTOR / PROPERTY / VALUE로 구성된다.

ex) body 태그 안의 글자 색을 밝은빨간색으로 지정하는 코드.

    body {
      color: #FF0000;
    }

head 태그 안에서 link태그를 이용해 CSS와 HTML 파일을 연결한다.

    <link rel="stylesheet" href="style.css"/>

참고로 로고 설정과 폰트 설정은 다음과 같이 할 수 있다.

    <link rel="icon" href="https://image.flaticon.com/icons/png/512/1053/1053367.png" type="image/x-icon">

    <link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">

CSS와 브라우저는 직접적으로 연결되어 있지 않다. 이미지, JS 파일과 같은 다른 모든 파일들은 HTML을 통해서 간접적으로 연결되어 있다.

측정 단위로 px, em이 있는데
px는 pixel로 절대적인 수치, em은 현재 글자 크기를 나타낸다. 반응형 웹을 만들때 em을 유용하게 사용할 수 있을 것 같다.

    body {
      font-size: 18px;
    }

    h1 {
      font-size: 2em;
    }

불필요한 반복을 줄이기 위해 여러 요소들을 묶어서 사용할 수 있다.
multiple selectors

    h1, h2, h3, h4, h5, h6 {
      font-family: "Helvetica", "Arial", sans-serif;
    }

font-family는 CSS에 내장되어 있는 property로 글씨체를 정의하는데 사용된다. 유저마다 가지고 있는 글씨체가 다르기 때문에 여러 개의 값을 전달할 수 있다. 왼->오 순서로 유저가 가지고 있는 글씨체가 적용된다.

아무래도 유저가 가지고 있는 글씨체에 의존하면 한계가 있기 때문에 현재는 구글 폰트 등의 web font를 사용하는 것 같다.

ul, ol 리스트의 bullet icon을 변경할 수 있다.

    ul {
      list-style-type: circle;
    }

    ol {
      list-style-type: lower-roman;
    }
