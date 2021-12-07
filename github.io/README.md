원래부터 TIL을 블로그화해서 기술 블로그를 만들 생각은 있었다.

그러던중 오픈소스개발프로젝트를 하던 도중  `github.io`를 이용해서 API 문서를 만들었고, 생각보다 기능도 많고 좋았다.

그동안 `github.io`로 기술블로그를 만들어서 운영하는 사람들을 많이 보기도 했고 나도 `github.io`로 기술블로그를 만들어봐야겠다는 생각을 했다.



API 문서를 만들때 참고했던 블로그 : https://dreamgonfly.github.io/blog/jekyll-remote-theme/



사이드바 추가 - 카테고리 표시

https://ansohxxn.github.io/blog/category/

> 프로필이 꺼져있으면 사이드바도 표시가 안된다.



나중에 시간날때 공부를 좀 더 해봐야 겠다는 생각이 들었다.

https://ansohxxn.github.io/blog/jekyll-directory-structure/



### GitHub Pages Build 오류

갑자기 Page Build에서 오류가 났다.

```
GitHub Pages failed to build your site.
A file was included in _pages/categories/category-auth.md that is a symlink or does not exist in your _includes directory.
```

근데 또 이상한건 다시 push해보니깐 문제없이 잘된다.



그리고 user-post 게시글에서 user-post-post 게시글로 접속하면 404오류가 발생했는데 post 태그를 삭제하니깐 해결되었다.

이름이 비슷해서 인식오류가 생기는건가?

GET POST PUT DELETE 카테고리 링크가 실제로 존재하지 않아서 오류가 난다기에는 다른 파일들은 잘 들어가지고..