# GitHub

<br>

## branch protection rule

해당 브랜치로 merge 하기전에 무조건 PR을 생성하도록 하거나, 최소 1개의 approve를 받아야 PR을 머지시킬 수 있도록 하는 등 여러 규칙을 생성할 수 있다.

> **참고자료**
>
> Require multiple reviewers for pull requests | The GitHub Blog. The GitHub Blog. Published March 23, 2018. Accessed April 3, 2022. https://github.blog/2018-03-23-require-multiple-reviewers/#:~:text=To%20require%20multiple%20reviewers%20for,pull%20request%20to%20that%20branch.

<br>

## GitHub Pages

원래부터 TIL을 블로그화해서 기술 블로그를 만들 생각은 있었다.

그러던중 오픈소스개발프로젝트를 하던 도중  `github.io`를 이용해서 API 문서를 만들었고, 생각보다 기능도 많고 좋았다.

그동안 `github.io`로 기술블로그를 만들어서 운영하는 사람들을 많이 보기도 했고 나도 `github.io`로 기술블로그를 만들어봐야겠다는 생각을 했다.

API 문서를 만들때 참고했던 블로그 : https://dreamgonfly.github.io/blog/jekyll-remote-theme/

사이드바 추가 - 카테고리 표시 https://ansohxxn.github.io/blog/category/

> 프로필이 꺼져있으면 사이드바도 표시가 안된다.

나중에 시간날때 공부를 좀 더 해봐야 겠다는 생각이 들었다. https://ansohxxn.github.io/blog/jekyll-directory-structure/

* ### GitHub Pages Build 오류

갑자기 Page Build에서 오류가 났다.

```
GitHub Pages failed to build your site.
A file was included in _pages/categories/category-auth.md that is a symlink or does not exist in your _includes directory.
```

근데 또 이상한건 다시 push해보니깐 문제없이 잘된다.

그리고 user-post 게시글에서 user-post-post 게시글로 접속하면 404오류가 발생했는데 post 태그를 삭제하니깐 해결되었다.

이름이 비슷해서 인식오류가 생기는건가?

GET POST PUT DELETE 카테고리 링크가 실제로 존재하지 않아서 오류가 난다기에는 다른 파일들은 잘 들어가지고..

<br>

## Issue

* ### template

  * [GitHub 공식문서](https://docs.github.com/en/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository)
  * 본문 뿐만 아니라 제목, assginee 등 또한 설정이 가능하다.
  * GitHub에서 간단하게 만들 수 있다.

* ### Autolinked references and URLs

  * [GitHub 공식문서](https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/autolinked-references-and-urls#issues-and-pull-requests)

  * `#` + 이슈번호 or PR번호

  * issue의 경우 해당 issue를 참조한 커밋내역을 모아서 볼 수 있다.

    > squash나 rebase가 되면서 커밋 내역에서는 사라진 커밋들도 issue에서는 사라지지 않는다.

<br>

## Pull Requests

* ### Linking a pull request to an issue

  * [GItHub 공식문서](https://docs.github.com/en/issues/tracking-your-work-with-issues/linking-a-pull-request-to-an-issue)
  * PR 제목에 이슈번호를 넣어도 링크가 되진 않는다.
  * 다만 Close 등의 keyword를 통해 issue와 연결할 수 있다. 그리고 연결되고 나면 PR이 머지되면 issue도 자동으로 close된다.

* ### template

  * [GitHub 공식문서](https://docs.github.com/en/communities/using-templates-to-encourage-useful-issues-and-pull-requests/creating-a-pull-request-template-for-your-repository)
  * issue와 달리 본문에 대한 템플릿만 만들 수 있다.

* ### Merge Strategy

  * #### Merge Commit

    기본메시지가 `Merge pull request #[PR번호] from 리포지토리명/브랜치명`이기 때문에 브랜치명에 이슈번호를 넣으면 머지 커밋과 이슈를 간단하게 연결할 수 있다.

  * #### Rebase

  * #### Squash

  * GitHub repository 설정에서 어떤 전략들을 허용할지 선택할 수 있다.

<br>

## Discussions

* 게시판 같은 기능
* 정보 공유나 질문 등을 올릴때 활용하면 좋을 것 같다.

<br>

## Organizations

* organization은 무한대로 만들 수 있다.

<br>