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

- [HTML&CSS](https://github.com/chisan01/TIL/tree/main/HTML_CSS)

### Java Spring

* [Spring Boot](https://github.com/chisan01/TIL/tree/main/Spring_Boot)

### [Release](https://github.com/chisan01/TIL/tree/main/release)

- Docker
- AWS ec2



### [팀플 (오픈소스개발프로젝트)](https://github.com/chisan01/TIL/tree/main/oss_dev_project)

- Swing
- RDB(mariaDB) 설계
- API 설계 및 문서화
- java http 연동



## Git

> https://github.com/chisan01/TIL/tree/main/Git



## 기타 등등



### 정규식

[강의](https://www.youtube.com/watch?v=t3M6toIflyQ) 및 연습

> https://regexone.com/
>
> https://regexone.com/problem/matching_decimal_numbers



### 디자인패턴

* **MVC 패턴**

  https://m.blog.naver.com/jhc9639/220967034588

  | 구성요소   | 역할                                                         |
  | ---------- | ------------------------------------------------------------ |
  | Model      | 각종 데이터 저장 및 관리                                     |
  | View       | 사용자에게 보여지는 부분                                     |
  | Controller | Model과 View의 중개자<br />- 사용자의 입력을 받아 데이터 변경<br />- 데이터 변경사항 View에 반영 |

  효율적인 역할 분담

  > 유지보수성, 확장성, 유연성 증가




### GitHub Profile 꾸미기

https://www.youtube.com/watch?v=ECuqb5Tv9qI&t=267s

백준 티어도 profile에서 보이도록 만들 수 있다.
https://haesoo9410.tistory.com/m/143



### md 접기/펼치기 버튼

<details>
    <summary>접기/펼치기 버튼</summary>
    <div markdown="1">
        html details 이용해서 접기/펼치기 버튼 만들기.
    </div>
</details>


https://inasie.github.io/it%EC%9D%BC%EB%B0%98/%EB%A7%88%ED%81%AC%EB%8B%A4%EC%9A%B4-expander-control/



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



### editor 설정
#### visual studio

##### # disable context menu for open in visual studio

https://developercommunity.visualstudio.com/t/disable-context-menu-for-open-in-visual-studio/26397
파일 탐색기에서 마우스 오른쪽 클릭을 했을때 `open in visual studio`가 안나오게 하는 방법. SHIFT키를 누르고 클릭해야만 나오게 설정할 수도 있다.
vscode, pycharm 등 다른 에디터의 경우도 비슷한 방법으로 설정할 수 있다.

##### # code formatting

`Shift+Alt+F`
https://code.visualstudio.com/docs/cpp/cpp-ide 

auto-formatting: setting -> editor.formatOnType

#### visual studio code

vs code에서 c/c++ 프로그래밍

https://webnautes.tistory.com/1158
visual studio는 c++로 알고리즘 문제풀때만 사용해서 TIL에도 더 편하게 작성하고 vscode에 더 익숙해질겸 설정해봤다.

설정하는 도중 ctrl+alt+c를 누르면 모든 창이 닫혀버려서 당황했는데 
알고보니 **winsplit revolution**이라는 프로그램에서 그렇게 설정되어 있어서 그런것이었다. 
참고: https://www.sevenforums.com/general-discussion/107035-am-i-only-one-who-has-ctrl-alt-c-shortcut-3.html?s=6e564b46782027208221b4b938ecc884 
단축키 설정하는김에 기능을 한번 살펴보니깐 유용한 기능도 몇개 발견했다. 
창 최소화 단축키 / 창 투명도 조절 / 창 맨 위에 표시

##### # git bash 백슬래시 경로 인식 문제  

g++로 컴파일할때 경로에서 \가 없어지면서 오류가 났는데 기본 터미널을 bash에서 다시 powershell로 바뀌니깐 오류가 해결됐다.

이유는 모르겠지만 다시 기본 터미널을 git-bash로 설정해보다가 안되서 작은 따옴표로 감싸지 않고 그냥 해보니깐 성공했다.
그리고 컴파일 후 실행에서 문제가 생겨서 이 부분은 블로그를 참고해서 해결했다.
https://k-chan-l.github.io/etc/2021/03/07/vscode-errorcheck.html

##### # 터미널에서 한글이 깨져서 보이는 오류

기본 터미널을 cmd, encoding방식은 UTF-8로 설정해서 사용하니깐 한글이 제대로 출력됐다. https://meoru-tech.tistory.com/9
하지만 빌드하고 터미널에서 따로 실행하면 한글이 잘 나오는데 execute를 통해서 제대로 실행이 되지 않았다.
tasks.json에서 실행하기 전에 cmd의 encoding 방식을 UTF-8로 설정하고 하면 잘 될것같아서 찾아봤다.

https://blog.naver.com/PostView.nhn?blogId=nuckly&logNo=222073264552&parentCategoryNo=&categoryNo=34&viewDate=&isShowPopularPosts=true&from=search   

https://stackoverflow.com/questions/60694901/vs-code-how-to-write-tasks-json-to-run-multiple-commands-in-a-single-task   

[새 버전 VS Code 기본 터미널 변경하기](https://gitjaesung.github.io/terminal-seting)   

> 이 방법으로 하면 터미널을 열때는 잘 바뀌는데 execute로 실행할때는 cmd.exe를 바로 실행시켜버려서 적용이 안되는 것 같다.   

결국 레지스트리에 cmd를 실행시키면 자동으로 `chcp 65001`이 실행되도록 Autorun항목을 추가했다. https://ryanking13.github.io/2018/09/03/cmd-deafult-command.html

##### # 디버깅할때 WATCH에서 동적할당된 array 보는 방법

https://stackoverflow.com/questions/63278898/how-to-watch-char-values-of-strings-pointed-by-a-pointer-to-pointers-in-debugger

