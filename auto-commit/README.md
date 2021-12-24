# commit & push 자동화

TIL의 경우 commit 메시지에 크게 신경을 쓰지 않아도 되서 자동화를 한다면 편리할 것 같았다. 그리고 나와 같은 생각을 하는 사람이 꽤 많았다. 시간날때 적용해보기. https://www.google.com/search?q=%EC%BB%A4%EB%B0%8B+%EC%9E%90%EB%8F%99%ED%99%94&sxsrf=AOaemvI0loVgHelpvYazw8_bKmEG6ISKiA%3A1636527092821&ei=9GuLYf_iMa_d2roPyMiW6AE



## bash script 작성

우선 간단하게 매일 "년-월-일" 커밋 메시지를 하루의 마지막에 날리도록 만들었다. https://shlee0882.tistory.com/270

나중에 좀 더 구체적인 커밋 메시지를 자동화하려면 이 블로그를 참고하면 좋을 것 같다. https://velog.io/@janeljs/git-8

GitHub에서 PR을 squash merge하면 일련의 커밋들을 하나로 합쳐서 할 수 있던데 이 방법을 응용해서 좀 더 구체적인 커밋 메시지를 날릴 수 있을 것 같다.

> 1. 커밋할 날짜를 바탕으로 브랜치 생성
>
>    ex) 2021-11-12
>
> 2. 디렉토리별로 add, 수정사항이 있는 폴더의 경우 수정된 md파일들의 디렉토리명을 커밋 메시지로 커밋.
>
> 3. 오늘 커밋된 내역들을 merge --squash로 하나로 묶어서 main에 push

생각하다보니 merge --squash를 안 하더라도 그냥 디렉토리별로 add 하면서 Tag같은 문자열에 하나씩 추가해서 커밋 메시지에 포함하면 될 것 같다.

[vi 들어가지 않고 commit 메시지에 줄바꿈 추가하는 방법](



## bash script 자동으로 실행시키는 방법

#### 1. cron 윈도우 버전

cron 윈도우 버전을 사용해서 자동화하려고 했지만 생각해보니깐 그 시간에 컴퓨터가 꺼져있다면 소용없다. 사람들이 서버를 따로 사용하는 이유도 이 때문인 것 같다. https://decdream08.tistory.com/67

#### 2. 서버 이용

CDP f1-micro와 같은 무료서버를 사용하는 방법이 있지만 생각해보니 서버에 파일을 따로 올려야 한다. https://sup2is.github.io/2020/08/07/auto-commit-and-push-script.html

#### 3. 윈도우 시작프로그램으로 지정

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



## zshell에서 실행되지 않는 오류

https://stackoverflow.com/questions/5064563/add-line-break-to-git-commit-m-from-the-command-line)

.bashrc에 zshell을 실행하는 옵션을 추가했더니 bash script가 제대로 실행되지 않아서 특정 폴더(여기서는 Startup)에서는 zshell을 실행하지 않도록 .bashrc를 좀 수정했다.

처음에 조건문으로 `if (cd | grep -q "Startup")`을 사용했는데 오늘 작동이 잘 안되서 생각해보니깐 `if (pwd | grep -q "Startup")`로 조건을 설정하는게 맞는것같다. 어제는 왜 정상적으로 작동했다고 생각했던거지 ㅋㅋ

`Startup` 폴더에 있지만 실행경로가 Startup폴더는 아닌 것 같다. 폴더에 직접 실행해보면 잘 동작하지만 시작프로그램으로 실행되었을때는 여전히 zshell로 실행된다.

bash script에 아예 cd문을 적어서 실행해야겠다.

> 생각해보니 cd문이 실행되기 전에 z shell이 실행되어서 불가능하다.

Startup폴더에 script 파일의 바로가기를 만들어서 넣어두고 .bashrc zshell 조건으로 `if(cd|grep -q "auto-commit")`을 사용했더니 정상적으로 작동한다.

