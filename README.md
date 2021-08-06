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

list-style-type: none을 사용하면 아이콘이 표시되지 않는다.

잘 짜여진 HTML은 검색 엔진이 문서의 구조를 쉽게 파악할 수 있도록 한다. 그리고 잘 짜여진 CSS는 문서를 사람들이 보기 좋게 시각화한다.

특정 이미지를 사용하기 위해서 list-style-image property를 사용할 수 있다.

link 태그를 이용해서 한 CSS 파일을 여러 HTML 파일에서 사용할 수 있다. 그리고 웹의 통일성을 위해 모든 웹 페이지에 적용할 한 개의 CSS 파일(global css styles)은 있는 것이 좋다. 그리고 이때 root-relative 경로를 사용하는것이 직관적이다.

글자에서 밑줄 표시 설정.

```css
a {
  text-decoration: none;
}
```

line-through 값을 사용하면 글자의 가운데에 선을 그을 수도 있다. 하지만 문서의 의미는 HTML을 통해 전달되어야 하므로 <ins>\<ins></ins>(삽입된 구문 표시)나 <del>\<del></del>(삭제된 구문 표시) 태그를 사용해서 표현하는 것이 좋다.

글자 정렬 설정.

```css
p {
  text-align: left;
}
```

글자 굵기 설정.

```css
h1,
h2,
h3,
h4,
h5,
h6 {
  font-weight: normal;
}
```

CSS 코드는 .css 파일 말고도 다양한 곳에서 적용될 수 있다.

- The browser’s default stylesheet
- User-defined stylesheets
- External stylesheets (that’s us)
- Page-specific styles (that’s also us)
- Inline styles (that could be us, but it never should be)

아래로 갈수록 우선적으로 적용된다. 예를 들어 브라우저의 default 스타일은 inline 스타일에 의해 무시된다.

각각의 HTML 문서에 page-specific styles를 적용하기 위해 \<style>태그를 사용한다.

```html
<head>
  <meta charset="UTF-8" />
  <title>Dummy</title>
  <link rel="stylesheet" href="styles.css" />
  <style>
    body {
      color: #0000ff; /* Blue */
    }
  </style>
</head>
```

다른 문서에서 동일한 디자인을 사용하기 위해서는 복사 붙여넣기를 통해서 옮겨야 하기 때문에 유지보수가 어렵다는 단점이 있다.  
따라서 급할 때가 아니라면 .css 파일을 사용하는 것이 대부분 더 좋다.

태그 안의 style 속성에 CSS를 지정해 줄 수도 있다.(Inline styles)

```html
<p>
  Want to try crossing out an
  <a href="nowhere.html" style="color: #990000; text-decoration: line-through;"
    >obsolete link</a
  >? This is your chance!
</p>
```

하지만 page-specific styles과 같은 이유로 최대한 사용을 지양해야 한다. 오히려 inline styles는 태그마다 따로 정의되어있기 때문에 유지보수가 더욱 어려워진다.  
이러한 이유로 특정 태그에 한해서 디자인을 적용하기 위해서 CSS classes를 inline styles 대신 사용한다.

하나의 HTML 문서에 여러 개의 CSS 파일을 적용할때 link 태그의 순서가 중요하다. 나중에 오는 파일이 그 앞의 파일들을 덮어씌운다. 따라서 기본적인 CSS 파일들을 앞에 배치하는 것이 일반적이다.

```html
<head>
  <link rel="stylesheet" href="styles.css" />
  <link rel="stylesheet" href="blog.css" />
</head>
```

### 5. CSS layout 관련