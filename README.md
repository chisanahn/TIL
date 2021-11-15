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

### Git 하위폴더 새로운 repository로 분리

깃헙에 올린 저장소에서 특정 파일들을 제거하고 싶은데 그냥 제거하면 커밋내역이 남고 다 지우기에는 다른 커밋내역이 날라가서 방법을 찾아보니 [repository의 하위폴더를 분리해서 새로운 repository를 만드는 방법](https://sustainable-dev.tistory.com/119)이 있었다.   

### Git commit log 유지하면서 repository 합치기

[Git Repository 합치기 (commit log 유지) - subtree 이용](http://yeoseon.kr/git-repository-habcigi-commit-log-yuji-subtree-iyong/)

### rebase

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



### md 접기/펼치기 버튼

<details>
    <summary>접기/펼치기 버튼</summary>
    <div markdown="1">
        html details 이용해서 접기/펼치기 버튼 만들기.
    </div>
</details>

https://inasie.github.io/it%EC%9D%BC%EB%B0%98/%EB%A7%88%ED%81%AC%EB%8B%A4%EC%9A%B4-expander-control/



### commit & push 자동화

TIL의 경우 commit 메시지에 크게 신경을 쓰지 않아도 되서 자동화를 한다면 편리할 것 같았다. 그리고 나와 같은 생각을 하는 사람이 꽤 많았다. 시간날때 적용해보기. https://www.google.com/search?q=%EC%BB%A4%EB%B0%8B+%EC%9E%90%EB%8F%99%ED%99%94&sxsrf=AOaemvI0loVgHelpvYazw8_bKmEG6ISKiA%3A1636527092821&ei=9GuLYf_iMa_d2roPyMiW6AE

우선 간단하게 매일 "년-월-일" 커밋 메시지를 하루의 마지막에 날리도록 만들었다. https://shlee0882.tistory.com/270

나중에 좀 더 구체적인 커밋 메시지를 자동화하려면 이 블로그를 참고하면 좋을 것 같다. https://velog.io/@janeljs/git-8

cron 윈도우 버전을 사용해서 자동화하려고 했지만 생각해보니깐 그 시간에 컴퓨터가 꺼져있다면 소용없다. 사람들이 서버를 따로 사용하는 이유도 이 때문인 것 같다. https://decdream08.tistory.com/67

CDP f1-micro와 같은 무료서버를 사용하는 방법이 있지만 생각해보니 서버에 파일을 따로 올려야 한다. https://sup2is.github.io/2020/08/07/auto-commit-and-push-script.html

윈도우 시작프로그램으로 지정해서 컴퓨터를 켰을때 그전 날 내용을 커밋&푸쉬 하는건 어떨까

> 문제점 : 중간에 컴퓨터를 껐다가 다시 키는 경우 커밋이 여러번 이루어질 수 있다.
>
> 윈도우 시작프로그램을 지정하되 같은 이름의 커밋 내역이 이미 존재하면 패스하도록 만들면 가장 좋을 것 같다.
>
> https://unix.stackexchange.com/questions/48535/can-grep-return-true-false-or-are-there-alternative-methods
>
> https://stackoverflow.com/questions/1706882/get-the-date-a-day-before-current-time-in-bash
>
> 성공.

GitHub에서 PR을 squash merge하면 일련의 커밋들을 하나로 합쳐서 할 수 있던데 이 방법을 응용해서 좀 더 구체적인 커밋 메시지를 날릴 수 있을 것 같다.

> 1. 커밋할 날짜를 바탕으로 브랜치 생성
>
>    ex) 2021-11-12
>
> 2. 디렉토리별로 add, 수정사항이 있는 폴더의 경우 수정된 md파일들의 디렉토리명을 커밋 메시지로 커밋.
>
> 3. 오늘 커밋된 내역들을 merge --squash로 하나로 묶어서 main에 push

생각하다보니 merge --squash를 안 하더라도 그냥 디렉토리별로 add 하면서 Tag같은 문자열에 하나씩 추가해서 커밋 메시지에 포함하면 될 것 같다.

[vi 들어가지 않고 commit 메시지에 줄바꿈 추가하는 방법](https://stackoverflow.com/questions/5064563/add-line-break-to-git-commit-m-from-the-command-line)

.bashrc에 zshell을 실행하는 옵션을 추가했더니 bash script가 제대로 실행되지 않아서 특정 폴더(여기서는 Startup)에서는 zshell을 실행하지 않도록 .bashrc를 좀 수정했다.



### Z shell 설치

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

