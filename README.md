# TIL

## Today I Learned

### React

참고 자료: https://www.taniarascia.com/getting-started-with-react/
- [HTML&CSS 기초다지기](https://github.com/chisan01/TIL/tree/main/HTML_CSS)

### [Algorithm](https://github.com/chisan01/TIL/tree/main/Algorithm)

- [종만북](https://github.com/chisan01/TIL/tree/main/Algorithm/JongmanBook)
- [ICPC 준비 - 2021 SW개발능력향상 프로그램](https://github.com/chisan01/TIL/tree/main/Algorithm/ICPC)
- [BOJ](https://github.com/chisan01/TIL/tree/main/Algorithm/BOJ)

### JavaScript

- node.js(스터디)

### Git
- 깃헙에 올린 저장소에서 특정 파일들을 제거하고 싶은데 그냥 제거하면 커밋내역이 남고 다 지우기에는 다른 커밋내역이 날라가서 방법을 찾아보니 [repository의 하위폴더를 분리해서 새로운 repository를 만드는 방법](https://sustainable-dev.tistory.com/119)이 있었다.   

- [Git Repository 합치기 (commit log 유지) - subtree 이용](http://yeoseon.kr/git-repository-habcigi-commit-log-yuji-subtree-iyong/)

### 기타
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