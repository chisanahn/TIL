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



### git branch -M

브랜치 이름변경

```
git branch (-m | -M) [<oldbranch>] <newbranch>
```



### git push -u

이 옵션을 주면 push 한 곳의 주소가 자동으로 upstream에 추가되기 때문에 한번 `git push -u` 를 사용하고 나면 그 뒤로는 `git push` 만 입력해도 된다는 것 같다.
https://git-scm.com/docs/git-push#Documentation/git-push.txt--u



### git 브랜칭 전략

개인프로젝트를 할때는 main, feature 브랜치 정도로 나눠두고 main 브랜치 기준으로 CI/CD를 구축해두고 feature 브랜치에서 브랜치를 만들어서 기능을 만들고 배포가 필요할때 main에 머지하는 정도로 관리하면 좋을 것 같다.

그리고 이번에 팀플하면서 브랜치이름으로 `prefix/{#이슈변호}` 형식을 사용했는데 직관성이 떨어져서 이게 맞나 싶었다.

브랜치에 이슈번호를 명시해둠으로써 얻는 이점이 뭔지 알아볼 필요가 있을 것 같다.



## githook

CI/CD 적용할때 사용하는 것 같다. 나중에 좀 더 공부해보기.



## git sever

처음에는 이게 뭔가 싶었는데 애초에 git은 버전관리 오픈소스 소프트웨어이고, 이걸 원격으로 관리하기 위해서 github 같은 git hosting 서비스를 사용하거나 git server를 이용해야 한다.
기본적으로 git으로 관리하는걸 github이나 gitlab 같은 git server에 올려서 원격 리포지터리를 생성한다. 공개하고 싶지 않은 개인 프로젝트를 생성할때 gitlab을 사용하거나 개인적으로 git server를 만들어서 운영하는 것 같다.
https://hoodiejun.tistory.com/15
https://teamlab.github.io/jekyllDecent/blog/tutorials/%EB%82%98%EB%A7%8C%EC%9D%98-Git-%EC%84%9C%EB%B2%84-Gitlab-%EA%B5%AC%EC%B6%95

> 토이 프로젝트를 만들때 한번 git server도 만들어보면 좋을 것 같다.



