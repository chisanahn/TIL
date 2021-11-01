# TIL

Today I Learned

## [Algorithm](https://github.com/chisan01/TIL/tree/main/Algorithm)

- [종만북](https://github.com/chisan01/TIL/tree/main/Algorithm/JongmanBook)
- [ICPC 준비 - 2021 SW개발능력향상 프로그램](https://github.com/chisan01/TIL/tree/main/Algorithm/ICPC)
- [BOJ](https://github.com/chisan01/TIL/tree/main/Algorithm/BOJ)



## 웹/앱

개발 로드맵 참고 : https://roadmap.sh/

https://www.youtube.com/watch?v=NeEaTeYcFhE&list=PLv2d7VI9OotQ1F92Jp9Ce7ovHEsuRQB3Y



### JavaScript

* JS 기초 문법 공부 : https://www.youtube.com/playlist?list=PLv2d7VI9OotTVOL4QmPfvJWPJvkmv6h-2

- node.js
- mongoose



### React

참고 자료: https://www.taniarascia.com/getting-started-with-react/

- #### [HTML&CSS](https://github.com/chisan01/TIL/tree/main/HTML_CSS)



### [Java Spring](https://github.com/chisan01/TIL/tree/main/Java_Spring)

* Spring Boot



### [팀플 (오픈소스개발프로젝트)](https://github.com/chisan01/TIL/tree/main/oss_dev_project)

> Swing + MySQL + Spring Boot



### 기타

#### 정규식

[강의](https://www.youtube.com/watch?v=t3M6toIflyQ) 및 연습

> https://regexone.com/
>
> https://regexone.com/problem/matching_decimal_numbers

#### 디자인패턴

* **MVC 패턴**

  https://m.blog.naver.com/jhc9639/220967034588

  | 구성요소   | 역할                                                         |
  | ---------- | ------------------------------------------------------------ |
  | Model      | 각종 데이터 저장 및 관리                                     |
  | View       | 사용자에게 보여지는 부분                                     |
  | Controller | Model과 View의 중개자<br />- 사용자의 입력을 받아 데이터 변경<br />- 데이터 변경사항 View에 반영 |

  효율적인 역할 분담

  > 유지보수성, 확장성, 유연성 증가

  

## Git

- 깃헙에 올린 저장소에서 특정 파일들을 제거하고 싶은데 그냥 제거하면 커밋내역이 남고 다 지우기에는 다른 커밋내역이 날라가서 방법을 찾아보니 [repository의 하위폴더를 분리해서 새로운 repository를 만드는 방법](https://sustainable-dev.tistory.com/119)이 있었다.   

- [Git Repository 합치기 (commit log 유지) - subtree 이용](http://yeoseon.kr/git-repository-habcigi-commit-log-yuji-subtree-iyong/)

- #### rebase

  우아한형제들 기술블로그에서 git-flow 관련 글을 보다가 우연히 rebase에 관한 글을 읽었는데 rebase로 병합뿐만 아니라 과거 커밋들을 수정하거나 다른 브랜치들로 옮길 수도 있다는걸 알았다. https://suhwan.dev/2018/01/21/Git-Rebase-1/

  그 전에는 commit --amend로 바로 직전 커밋만 수정 가능하고 다른 작업은 못하는줄 알아서 한번 커밋할때 신중하게 해야되겠다고 생각했는데 이런 기능이 있을 줄이야...

  다음에 한번 rebase를 제대로 한번 사용해봐야겠다.

  > 단, 역시나 공동 프로젝트를 하는 경우에는 커밋내역이 꼬일 수 있기 때문에 안하는게 좋다.
  >
  > 로컬 저장소에서 작업을 할 때 일단 최대한 자잘하게 나눠서 커밋을 하고 나중에 push 하기 전에 너무 자잘한 커밋들을 하나로 묶는 등 커밋 내역을 한번 관리하는 식으로 하면 되지 않을까 싶다.

  

## 기타
- [disable context menu for open in visual studio](https://developercommunity.visualstudio.com/t/disable-context-menu-for-open-in-visual-studio/26397)   
파일 탐색기에서 마우스 오른쪽 클릭을 했을때 `open in visual studio`가 안나오게 하는 방법. SHIFT키를 누르고 클릭해야만 나오게 설정할 수도 있다.   
vscode, pycharm 등 다른 에디터의 경우도 비슷한 방법으로 설정할 수 있다.   

- [vs code에서 c/c++ 프로그래밍](https://webnautes.tistory.com/1158)
> visual studio는 c++로 알고리즘 문제풀때만 사용해서 TIL에도 더 편하게 작성하고 vscode에 더 익숙해질겸 설정해봤다.   
> 설정하는 도중 ctrl+alt+c를 누르면 모든 창이 닫혀버려서 당황했는데   
> 알고보니 winsplit revolution이라는 프로그램에서 그렇게 설정되어 있어서 그런것이었다.   
> 참고: https://www.sevenforums.com/general-discussion/107035-am-i-only-one-who-has-ctrl-alt-c-shortcut-3.html?s=6e564b46782027208221b4b938ecc884   
> 단축키 설정하는김에 기능을 한번 살펴보니깐 유용한 기능도 몇개 발견했다.   
> 창 최소화 단축키 / 창 투명도 조절 / 창 맨 위에 표시   
> 
> g++로 컴파일할때 경로에서 \가 없어지면서 오류가 났는데 기본 터미널을 bash에서 다시 powershell로 바뀌니깐 오류가 해결됐다.      
>
> 터미널에서 한글이 깨져서 보이는 오류. 기본 터미널을 cmd, encoding방식은 UTF-8로 설정해서 사용하니깐 한글이 제대로 출력됐다. https://meoru-tech.tistory.com/9     
> 하지만 빌드하고 터미널에서 따로 실행하면 한글이 잘 나오는데 execute를 통해서 제대로 실행이 되지 않았다.   
> tasks.json에서 실행하기 전에 cmd의 encoding 방식을 UTF-8로 설정하고 하면 잘 될것같아서 찾아봤다.
> 
> https://blog.naver.com/PostView.nhn?blogId=nuckly&logNo=222073264552&parentCategoryNo=&categoryNo=34&viewDate=&isShowPopularPosts=true&from=search   
> 
> https://stackoverflow.com/questions/60694901/vs-code-how-to-write-tasks-json-to-run-multiple-commands-in-a-single-task   
> 
> - [새 버전 VS Code 기본 터미널 변경하기](https://gitjaesung.github.io/terminal-seting)   
> -> 이 방법으로 하면 터미널을 열때는 잘 바뀌는데 execute로 실행할때는 cmd.exe를 바로 실행시켜버려서 적용이 안되는 것 같다.   
> 
> 결국 레지스트리에 cmd를 실행시키면 자동으로 `chcp 65001`이 실행되도록 Autorun항목을 추가했다. https://ryanking13.github.io/2018/09/03/cmd-deafult-command.html
> 
> [디버깅할때 WATCH에서 동적할당된 array 보는 방법](https://stackoverflow.com/questions/63278898/how-to-watch-char-values-of-strings-pointed-by-a-pointer-to-pointers-in-debugger)
> 
> [c++ code formatting](https://code.visualstudio.com/docs/cpp/cpp-ide) `Shift+Alt+F`
> auto-formatting: setting -> editor.formatOnType

- [git-bash 백슬래시 경로 인식 문제 해결](https://k-chan-l.github.io/etc/2021/03/07/vscode-errorcheck.html)    
> 이유는 모르겠지만 이 블로그를 참고해서 다시 기본 터미널을 git-bash로 설정해보다가 안되서 작은 따옴표로 감싸지 않고 그냥 해보니깐 성공했다.  
> 그리고 컴파일 후 실행에서 문제가 생겨서 이 부분은 블로그를 참고해서 해결했다.

### GitHub Profile 꾸미기

https://www.youtube.com/watch?v=ECuqb5Tv9qI&t=267s 참고



<details>
    <summary>접기/펼치기 버튼</summary>
    <div markdown="1">
        html details 이용해서 접기/펼치기 버튼 만들기.
    </div>
</details>

https://inasie.github.io/it%EC%9D%BC%EB%B0%98/%EB%A7%88%ED%81%AC%EB%8B%A4%EC%9A%B4-expander-control/

