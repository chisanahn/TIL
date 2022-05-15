## breakpoint condition

breakpoint를 설정한뒤, breakpoint를 오른쪽 클릭하면 특정 조건에서만 break되도록 설정할 수 있다.

chrome 개발자 도구에서도 지원해주고 왠만한 IDE에서는 모두 지원해주는듯하다.

<br>

## Intellij console 한글 깨짐

Intellij에서 실행 결과 console 창에서 한글이 자꾸 깨져서 나왔는데 가상머신 환경설정에 인코딩설정을 추가해줬더니 해결됐다.

> **참고자료**
>
> https://baejangho.com/entry/IntelliJ-resolve-garbled-korean-problem

<br>

## Intellij 테스트 결과 출력 오류

테스트를 클래스 단위로 여러 개 돌릴시에 세부 테스트 결과가 제대로 나오지 않고 하나로 축약되어서 나오는 문제가 있었다.

Build Tools -> Gradle 설정에서 Run Tests using 값을 `Gradle`에서 `Intellij IDEA`로 바꿔주면 된다.

* 참고로 이렇게 설정하면 gradle을 통해서 컴파일 하지 않고 intellij에서 바로 컴파일하면서 컴파일 시간도 빨라진다고 한다.

> **참고자료**
>
> https://seosh817.tistory.com/183

<br><br>

# visual studio

##### # disable context menu for open in visual studio

https://developercommunity.visualstudio.com/t/disable-context-menu-for-open-in-visual-studio/26397
파일 탐색기에서 마우스 오른쪽 클릭을 했을때 `open in visual studio`가 안나오게 하는 방법. SHIFT키를 누르고 클릭해야만 나오게 설정할 수도 있다.
vscode, pycharm 등 다른 에디터의 경우도 비슷한 방법으로 설정할 수 있다.

##### # code formatting

`Shift+Alt+F`
https://code.visualstudio.com/docs/cpp/cpp-ide 

auto-formatting: setting -> editor.formatOnType

<br/>

# visual studio code

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

