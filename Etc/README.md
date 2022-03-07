# 객체지향설계

## SOLID 5원칙

객체 지향 설계뿐만 아니라 애자일 개발에서도 핵심 철학을 형성한다

* ### Single-responsibility principle

  하나의 클래스가 하나의 책임만을 가져야 한다.

* ### Open-closed principle

  모든 클래스는 확장에는 열려있되, 수정에는 닫혀있어야 한다.

  다시말해 객체는 소스코드의 변화없이 확장이 가능해야 한다.

* ### Listov substitution principle

  클래스는 해당 클래스를 상속받은 클래스로 교체될 수 있어야 한다.

* ### Interface segregation principle

  인터페이스는 client의 요구사항에 맞게 최대한 세세하게 나눠져있는것이 좋다.

  객체지향 뿐만 아니라 분산시스템이나 마이크로서비스에서도 핵심적인 원칙이다.

* ### Dependency inversion principle

  구현체에 의존해서는 안된다. 인터페이스 등 추상적인 개념에 의존해야 한다.

  특히 high-level 모듈은 low-level 모듈을 import해서는 안된다.

  객체간의 결합도를 낮추기 위한 원칙이다.

  <br>

> **참고자료**
>
> 1. 대학생Devlog. [Java] 객체지향 설계 5원칙 - SOLID란 무엇일까? Gyun’s 개발일지. Published August 20, 2021. Accessed February 11, 2022. https://devlog-wjdrbs96.tistory.com/380
> 2. Wikipedia Contributors. SOLID. Wikipedia. Published February 1, 2022. Accessed February 11, 2022. https://en.wikipedia.org/wiki/SOLID
> 3. Wikipedia Contributors. Open–closed principle. Wikipedia. Published January 17, 2022. Accessed February 11, 2022. https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle
> 4. Wikipedia Contributors. Liskov substitution principle. Wikipedia. Published February 1, 2022. Accessed February 11, 2022. https://en.wikipedia.org/wiki/Liskov_substitution_principle

<br><br>

# 정규식

[강의](https://www.youtube.com/watch?v=t3M6toIflyQ) 및 연습

> https://regexone.com/
>
> https://regexone.com/problem/matching_decimal_numbers

<br><br>

# md 문법

## GitHub Profile 꾸미기

https://www.youtube.com/watch?v=ECuqb5Tv9qI&t=267s

백준 티어도 profile에서 보이도록 만들 수 있다.
https://haesoo9410.tistory.com/m/143

https://github.com/hammii
나중에 html로 좀 더 예쁘게 구성해봐야겠다.

## 접기/펼치기 버튼

<details><summary>접기/펼치기 버튼</summary>

html `<details>`, `<summary>` 태그 이용해서 접기/펼치기 버튼 만들기.

</details>

## 체크박스

`- [ ]`를 사용해서 체크박스를 만들 수 있다.

- [x] item1
- [ ] item2

<br/><br>

# window에서 z-shell 설치

가끔 유튜브 같은데서 디자인이 굉장히 예쁜 터미널을 사용하는 것을 봤는데 z shell이라는 것을 알게 되어서 적용해보기로 했다.
https://teddylee777.github.io/linux/linux%EC%97%90%EC%84%9C-%EA%B8%B0%EB%B3%B8%ED%84%B0%EB%AF%B8%EB%84%90-%EC%8A%A4%ED%83%80%EC%9D%BC%EB%A7%81%ED%95%98%EA%B8%B0

기본적으로 mac이나 linux 환경에서 설정하는 것이 더 쉬운 것 같다.
https://velog.io/@ehrbs2021/window%EC%97%90%EC%84%9C-Git-Bash%EC%97%90-oh-my-zsh-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0
https://gist.github.com/fworks/af4c896c9de47d827d4caa6fd7154b6b
https://github.com/diesire/git_bash_windows_powerline

기본적인 방법은 zsh를 설치하고 oh-my-zsh를 설치한뒤 .zshrc에서 테마를 agnoster로 바꿔주면 된다. 이때 power-line 폰트 설치를 안하면 폰트가 깨지는데 윈도우에서 이것을 하기가 좀 어려웠다.
https://velog.io/@cyongchoi/Window-Ubuntu-%ED%84%B0%EB%AF%B8%EB%84%90%EC%97%90-OH-MY-ZSH-%EC%84%A4%EC%B9%98%ED%95%98%EA%B8%B03
결국 다운받고 git bash 창에서 따로 폰트를 바꿔줘서 해결했다.

[색상 변경하는 방법](https://github.com/agnoster/agnoster-zsh-theme/issues/30)
solarize dark theme도 적용하고 싶어서 찾아보던중 Windows New Terminal이 괜찮아보였다. https://goax.tistory.com/11 시간될때 wsl도 다시 설치해봐야겠다는 생각도 들었다.

그리고 windows git bash에서 테마 변경은 그냥 UI로 하면 된다.

z shell로 변경하고 나니 git log 등의 명령어를 수행할때 다른 창으로 이동한뒤 q로 닫고 나면 내용이 보이지 않아서 불편했다.
git core.pager가 기본적으로 less로 설정되어 있는데 bash랑 달리 zsh를 사용하게 되면 pager로 열리게 된다. 따라서 설정을 조금 수정해주면 된다. https://serebrov.github.io/html/2014-01-04-git-log-and-less-keep-output.html

<br><br>

# 라이선스

MDN 공식문서를 참고해서 공부하고, TIL을 작성하던 도중 저작권에 대해 궁금해져서 MDN GitHub repository에 들어가서 확인해봤는데 글의 경우 `CC-BY-SA 2.5` 라이선스를 따르고, code example과 snippets의 경우 2010.08.20일 이후로 작성된 경우 `CC0` 라이선스를 따르고, 그 이전에 작성된 경우 `MIT` 라이선스를 따른다고 한다.

> 알고보니 MDN 홈페이지에서도 라이선스 관련 내용을 찾을 수 있다.

<br>

## CC

### CC BY-SA

저작자표시 - 동일조건변경허락

자유로운 이용이 가능하지만, 원저작자 및 출처를 표시해야 하고, 동일한 라이선스를 적용해야 한다는 제약이 있다.

### CC0

**저작권이 소멸된 저작물**로 정말 아무런 제약없이 누구나 자유롭게 이용할 수 있다.

<br>

## MIT

저작권 표시 및 허가 표시를 기재하고 사용해야 한다는 걸 제외하면 자유로운 이용이 가능하다.

<br>

> **참고자료**
>
> 1. mdn. content/LICENSE.md at main · mdn/content. GitHub. Published 2022. Accessed February 6, 2022. https://github.com/mdn/content/blob/main/LICENSE.md
> 2. \01. CC 라이선스. 크리에이티브 커먼즈 라이선스. Published 2022. Accessed February 6, 2022. http://ccl.cckorea.org/about/
> 3. 위키미디어 프로젝트 기여자. MIT 허가서. Wikipedia.org. Published July 22, 2007. Accessed February 6, 2022. https://ko.wikipedia.org/wiki/MIT_%ED%97%88%EA%B0%80%EC%84%9C#:~:text=MIT%20%ED%97%88%EA%B0%80%EC%84%9C(%EC%98%81%EC%96%B4%3A%20MIT%20License,License%EB%A1%9C%20%ED%91%9C%EA%B8%B0%EB%90%98%EA%B8%B0%EB%8F%84%20%ED%95%9C%EB%8B%A4.
> 4. About MDN Web Docs - The MDN project | MDN. Mozilla.org. Published February 3, 2022. Accessed February 6, 2022. https://developer.mozilla.org/en-US/docs/MDN/About
