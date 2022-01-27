# 정규식

[강의](https://www.youtube.com/watch?v=t3M6toIflyQ) 및 연습

> https://regexone.com/
>
> https://regexone.com/problem/matching_decimal_numbers

<br>

# md 문법

## GitHub Profile 꾸미기

https://www.youtube.com/watch?v=ECuqb5Tv9qI&t=267s

백준 티어도 profile에서 보이도록 만들 수 있다.
https://haesoo9410.tistory.com/m/143

https://github.com/hammii
나중에 html로 좀 더 예쁘게 구성해봐야겠다.

## 접기/펼치기 버튼

<details><summary>접기/펼치기 버튼</summary>

html `<details>`, `<summary>` 태그 이용해서 접기/펼치기 버튼 만들기.

</details>

## 체크박스

`- [ ]`를 사용해서 체크박스를 만들 수 있다.

- [x] item1
- [ ] item2

<br/>

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

