# Git

## squash merge시 주의할 점

알고리즘 스터디 할때 사용하는 리포지토리에서 README 수정이라서 간과했던 부분인데

일단 기본적으로 작업할때 따로 브랜치를 만들어서 작업하고 main 브랜치에 머지하는게 좋고

만약 `origin`의 main 브랜치에서 `upstream` main 브랜치에 PR을 날릴 경우 squash 머지를 사용하면 커밋 내역이 충돌날 수 있기 때문에 주의해야 한다.

> 그때 당시에는 커밋 내역을 깔끔하게 할 수 있을 것 같아서 squash 머지를 사용했는데 충돌나는건 미처 생각하지 못했다.

우선 지금은 아직 소스코드가 그런게 올라와있지 않은 상태라서 origin을 upstream 저장소로 덮어씌우는게 좋을 것 같다.

<br>

## git filter-branch

필터에 적용된 파일만 가지고 히스토리를 다시 구축할 수 있다.

* 디렉토리를 새로운 repostiory로 분리할때 사용할 수 있다.
* 모든 커밋에서 특정 파일을 제거할 수 있다.

> **참고자료**
>
> git filter-branch로 저장소 분리하기. git filter-branch로 저장소 분리하기 :: Outsider’s Dev Story. Outsider’s Dev Story. Published October 29, 2016. Accessed January 30, 2022. https://blog.outsider.ne.kr/1249

<br>

## 서브디렉토리 새로운 repository로 분리

subtree를 활용해서 서브디렉토리를 별도의 git repository로 분리할 수 있다.

> **참고자료**
>
> Junimo. 레포지토리의 하위폴더를 분리해서 새로운 레포지토리로 만들기. 지속가능한 개발 블로그. Published March 7, 2020. Accessed January 30, 2022. https://sustainable-dev.tistory.com/119

<br>

## 모든 커밋에서 특정 파일제거하기

```bash
$ git filter-branch --force --index-filter 'git rm --cached --ignore-unmatch 파일명' --prune-empty --tag-name-filter cat -- --all
```

> **참고자료**
>
> git 특정파일만 모든 커밋에서 제거하기. Velog.io. Published 2021. Accessed January 30, 2022. https://velog.io/@nohsangwoo/git-%ED%8A%B9%EC%A0%95%ED%8C%8C%EC%9D%BC%EB%A7%8C-%EB%AA%A8%EB%93%A0-%EC%BB%A4%EB%B0%8B%EC%97%90%EC%84%9C-%EC%A0%9C%EA%B1%B0%ED%95%98%EA%B8%B0

<br>

## commit log 유지하면서 repository 합치는 방법

* merge 할때 `--allow-unrelated-histories` 옵션을 사용해서 합칠 수 있다.

* subtree를 이용해서 합칠 수 있다.

  ```bash
  git subtree add --prefix=(해당 Repository 하위의 디렉터리 구조) (옮겨올 Repository 주소) (옮겨올 Repository의 branch)
  ```

> **참고자료**
>
> 1. Git - git-merge Documentation. Git-scm.com. Published 2022. Accessed January 30, 2022. https://git-scm.com/docs/git-merge#Documentation/git-merge.txt---allow-unrelated-histories
> 2. 

<br>

## rebase

rebase로 병합뿐만 아니라 과거 커밋들을 수정하거나 다른 브랜치들로 옮기는 등의 작업을 수행할 수 있다

> **참고자료**
>
> Git Rebase (1). Suhwan.dev. Published 2018. Accessed January 30, 2022. https://suhwan.dev/2018/01/21/Git-Rebase-1/

<br>

## --root

맨 처음 커밋을 가리키는 것

`git rebase -i --root`를 통해서 맨 처음 커밋까지 rebase 할 수 있다.

## git checkout --orphan

새로운 root commit 생성

> **참고자료**
>
> lxs. How do I git rebase the first commit? Stack Overflow. Published April 10, 2014. Accessed January 30, 2022. https://stackoverflow.com/questions/22992543/how-do-i-git-rebase-the-first-commit/23000315

<br>

## git branch -M

브랜치 이름변경

```bash
$ git branch (-m | -M) [<oldbranch>] <newbranch>
```

<br>

## git push -u

이 옵션을 한번 사용해서 push를 하고 나면 해당 branch의 `upstream branch`가 `branch.<name>.merge`에 추가된다.

한번 추가된 뒤로는 해당 브랜치에서 git push / git pull 등의 명령어를 인자없이 사용하면 `-u` 옵션을 주고 사용했던 `upstream branch`가 기본값으로 적용된다.

> **참고자료**
>
> Git - git-push Documentation. Git-scm.com. Published 2022. Accessed January 30, 2022. https://git-scm.com/docs/git-push#Documentation/git-push.txt--u

<br>

## 브랜치 컨벤션

GitHub의 경우 merge commit의 기본메시지가 `Merge pull request #[PR번호] from 리포지토리명/브랜치명`이라서 브랜치에 이슈번호를 명시해두면 merge commit이 issue에 연결된다.

<br>

## .gitignore

### 예외처리

한번 제외된 디렉토리 안의 내용물은 다시 추가되지 않는다. 따라서 다음과 같이 예외처리를 하더라도 exception.txt는 포함되지 않는다.

```
dir
!dir/exception.txt
```

따라서 폴더 내에서 특정 파일만 제외하기 위해서는 디렉토리를 추가하면 안되고 디렉토리의 내용물을 모두 추가한뒤 특정 파일에 예외처리를 해주는 방식을 사용해야 한다.

```
dir/**
!dir/exception.txt
```

### 이미 git에 추가되어있는 파일이나 디렉토리

이미 git에 추가되어있는 파일이나 디렉토리의 경우 .gitignore에 명시한다고 제거되지 않으므로 우선 commit tree에서 제거해줘야 한다.

```
$ git rm -r --cached <파일, 디렉토리명>
```

> **참고자료**
>
> 1. Shin H.gitignore로 무시된 디렉토리 안의 특정 파일만 추가하는 방법 - 신현석(Hyeonseok Shin). Hyeonseok.com. Published 2016. Accessed January 30, 2022. https://hyeonseok.com/blog/797
> 2. shin. git .ignore not working in a directory. Stack Overflow. Published May 17, 2011. Accessed January 30, 2022. https://stackoverflow.com/questions/6030530/git-ignore-not-working-in-a-directory

<br>

# git hook

CI/CD 적용할때 사용하는 것 같다. 나중에 좀 더 공부해보기.

<br>

# git sever

git을 원격으로 관리하기 위해서는 git hosting 서비스 또는 git server를 이용해야 한다. git hosting 서비스는 대표적으로 GitHub이 있고, git server는 GitLab을 이용하거나 직접 서버와 SSH를 이용해서 구축할 수 있다.

> **참고자료**
>
> HoodieJun. 나만의 git 서버 만들기 (100% private 모드). 후디준. Published March 25, 2021. Accessed January 30, 2022. https://hoodiejun.tistory.com/15

<br>

