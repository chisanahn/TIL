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

> CSS box model: CSS는 HTML의 요소들을 padding, borders, margins 등의 다양한 속성을 가진 하나의 box로 취급한다.

    HTML에서 요소(elements)와 태그(tags)
    : 혼용해서 쓰는 경우가 많기는 하지만 정확하게는 "요소 = 태그 + 그 사이의 내용"이다.

> box는 크게 두 가지 종류가 있다. block, inline  
> HTML의 모든 요소들은 default box type이 있는데 예를 들어 \<p>, \<h1> 등은 block-level elements, \<strong>, \<em> 등은 inline elements이다.

> CSS의 background-color 속성을 이용하면 각각의 box들의 영역을 더 직관적으로 이해할 수 있다.

- Block box들은 항상 그 전 block element의 밑에 위치한다. 이것을 HTML 문서의 "natural" 혹은 "static" flow라고 한다.
- Block box들의 너비는 부모 container에 의해 자동으로 결정된다.
- Block box들의 높이는 box안의 내용물을 기반으로 결정된다.
- Inline box들은 레이아웃을 결정하는데 사용하지 않는다. box 안의 내용물을 디자인하는데 사용된다.
- Inline box들의 너비는 그 안의 내용물을 기반으로 결정된다.

> CSS의 display 속성을 이용해 box type을 덮어씌울 수 있다.

```css
em,
strong {
  background-color: #b2d6ff;
  display: block;
}
```

> 기본적으로 inline boxes인 \<a>요소를 버튼으로 바꾸거나 \<img/> 요소를 관리할 떄 유용하게 사용할 수 있다.

- Margin > Border > Padding > Content

> **Content** - 요소 안의 글자, 사진 등의 내용물

> **Padding** - box 안의 content와 border 사이의 빈 공간

```css
h1 {
  padding: 50px;
}
```

> padding-top과 같은 속성을 사용해 더 세세하게 설정할 수 있다. 그리고 px뿐만 아니라 em 등 다양한 단위를 사용할 수 있다.  
> 또한, padding의 속성을 간편하게 정의할 수 있는 shorthand도 존재한다.

```css
h1 {
  padding: 20px 10px; /* Vertical  Horizontal */
}
p {
  padding: 20px 0 20px 10px; /* Top  Right  Bottom  Left */
}
```

> **Border** - box의 padding과 margin 사이의 선

> Border를 정의하기 위해서는 새로운 문법이 사용된다.  
> border: size, style, color

```css
h1 {
  border: 1px solid #5d6063;
}
```

> padding처럼 border-bottom과 같은 속성이 존재해 더 세세한 설정이 가능하다.

> border를 이용하면 box의 padding, margin을 명확하게 확인할 수 있어 디버깅을 할 때 유용하게 사용할 수 있다.

> **Margin** - box와 다른 box들 사이의 공간

```css
p {
  margin-bottom: 50px;
}
```

> margin도 마찬가지로 margin-bottom과 같은 속성이 존재해 세세한 설정이 가능하다.  
> 또한 padding처럼 shorthand가 존재한다.

> padding과 margin의 차이점
>
> 1. margin은 배경색이 항상 투명하다.
> 2. margin은 클릭영역에 포함되지 않는다.
> 3. margin collapse vertically

> inline element에서 상하 margin은 무시된다. 또한 inline element의 padding은 해당 inline element가 포함된 box들의 크기에 영향을 미치지도 않는다.
> 왜냐하면 inline element는 block box 안에 있는 내용물에 영향을 미치기 때문에 페이지의 레이아웃에 주는 영향이 제한적이기 때문이다.  
> 따라서 상하의 여백을 조절하기 위해서는 block-level element의 속성을 조절해야한다.(parent block box를 조절하거나 box type을 inline에서 block을 바꾼다.)

- vertical margin collapse

> 수직으로 겹치는 box들의 margin은 그 중에서 값이 더 큰 margin만 표시된다.
>
> 1. box사이에 보이지 않는 element를 추가해서 이를 막을 수 있다. (단, 높이가 0이 아니여야한다.)
> 2. padding이 사용되지 않는 경우 padding은 겹침 현상이 없으므로 padding을 사용한다.
> 3. 위나 아래 중 한가지 margin만 사용한다.
> 4. flexbox

- "container" element - \<div>, \<span>

> 일반적인 HTML의 element와 달리 오직 디자인에만 영향을 미치는 element  
> 따라서 페이지의 구조를 설계할때 정말 유용하다.

> \<div>는 block-level, \<span>은 inline

width, height property

box-sizing property  
box size에 border나 padding을 포함시킬지 설정 가능  
border-box를 사용하는 것이 더 직관적이긴 하다.

```css
div {
  width: 200px;
  box-sizing: border-box;
}
```

block-level 정렬

- auto-margins: 가운데 정렬, 젤 간단하다.

```css
div {
  width: 200px;
  box-sizing: border-box;
  margin: 20px auto;
}
```

- floats: 왼쪽/오른쪽 정렬
- flexbox: 종합

브라우저마다 기본 style이 있는데 통일성 있는 디자인을 위해서는 기본 style을 reset 하고 시작하는 것이 좋다.

```css
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}
```

### 6. CSS selectors

그동안 사용했던건 "type selector"

```css
p {
  font-size: 10px;
}
```

> "class selector"  
>  : 해당 클래스를 속성으로 가지고 있는 요소에만 적용이 된다.

클래스 이름이 문서에 직접적인 영향을 주진 않지만 개발의 편의성을 위해 적절한 이름을 붙이는 것이 좋다.

```html
<p class="synopsis"></p>
```

```css
.synopsis {
  font-style: italic;
}
```

> 8/11/2021 9:20PM - 서버 점검을 하는지 500 orgin error가 떴다.

클래스를 여러개 사용할 수 있다. 공백으로 구분해서 사용.  
적용되는 순서는 css 파일에서 정의된 순서. 뒤에서 정의된 클래스가 앞에서 정의된 클래스를 override. HTML 속성에서의 클래스의 순서는 상관없다.

```html
<div class="class1 class2">Contents</div>
```

HTML 요소 안의 요소를 특정해서 디자인하기 위해서 "descendant selectors"를 사용할 수 있다.

```css
.synopsis em {
  font-style: normal;
}

h1 em {
  /* Some other styles */
}
```

> "pseudo-classes"  
> : 유저의 동작에 따라 디자인을 설정. ex)하이퍼링크를 클릭하면 해당 링크의 색상 변경     
> 이 기능을 이용해서 색상을 바꾸면서 버튼에 눌린 것처럼 효과를 줄 수도 있는 등 페이지가 정말 다채로워지는걸 보면서 이런 기능을 구현하려면 JS가 필요한 줄 알았는데 CSS로만 이런 느낌을 낼 수 있다는걸 알고서 좀 놀랐다. 
    
- interactive-link

```css
a:link {
  color: #eeb75a;
  text-decoration: none;
}
a:visited {
  color: purple;
}
a:hover {
  color: aqua;
  text-decoration: underline;
}
a:active {
  color: red;
}
```

더 상세하게 설정할 수도 있음

```css
a:visited:hover {
  color: orange;
}
a:visited:active {
  color: red;
}
```

- interactive-button

```css
.button:link,
.button:visited {
  display: block;
  text-decoration: none;

  color: #fff;
  background-color: #5995da;
  font-weight: bold;
  padding: 20px;
  text-align: center;
  border: 2px solid #5d6063;
  border-radius: 5px;

  width: 200px;
  margin: 20px auto;
}

.button:hover,
.button:visited:hover {
  color: #fff;
  background-color: #76aeed;
}

.button:active,
.button:visited:active {
  color: #fff;
  background-color: #5995da;
}
```

- pseudo-classes for structure   
: HTML에 따로 클래스를 추가하지 않고도 특정 요소만 디자인하고 싶을 때에도 유용하게 사용할 수 있다.
```css
p:last-of-type {
  margin-bottom: 50px;
}
```
child selector를 사용해서 특정 container에만 적용할수도 있다.
```css
.page > p:first-of-type {
  color: #7E8184;
  font-style: italic;
}
```

- ID selectors   
: class selectors와 비슷하지만 ID selectors는 재사용이 되지 않는다.
```html
<a id='button-2' class='button'>Button Two</a>
```
```css
#button-2 {
  color: #5D6063;
}
```

- URL fragments   
: 페이지의 특정 부분을 가리키는 링크   
TIL을 작성할때 README.md에서도 이런 기능을 활용해서 목차를 만들 수 있다.
```html
<a href="#button-2">Go to Button Two</a>
```
ID selectors를 사용하면 안 좋은 이유 중에 하나이기도 하다.   
HTML과 CSS의 통일성을 해치면서 유지 보수가 어려워진다.


- CSS specificity
CSS는 기본적으로 위에서 아래 순으로 override 되면서 적용되는데   
그 이전에 selector의 종류에 따라서 우선순위가 결정된다.
* `#button-2`
* `.button:link`
* `a:link` and `.synpsis em`
* `.button`
* a

이러한 순서 때문에 개발하면서 굉장히 헷갈리는 경우가 많은데   
그래서 보통 "**BEM**"(class selector만을 사용) 등과 같은 방법을 주로 사용한다.