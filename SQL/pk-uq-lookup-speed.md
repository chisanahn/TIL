## Is there a difference between finding by primary key vs finding by unique column?

프로젝트를 진행하다가 문득 다음과 같은 의문이 생겼다.

`PRIMARY KEY` 항목을 기준으로 DB를 조회할때랑 `UNIQUE` 항목을 기준으로 DB를 조회할때랑 성능 차이가 존재할까?

PK가 왠지 더 빠를 것 같았지만 확실하게 하기 위해서 인터넷을 찾아보았다.

https://stackoverflow.com/questions/59325634/is-there-a-difference-between-finding-by-primary-key-vs-finding-by-unique-column

아직 배경지식이 부족해서 완전히 이해하진 못했지만 둘 다 Integer일 경우에는 성능 차이가 존재하지 않고, Integer를 대상으로 하는 검색이 String보다 빠르다고 한다.

Indexing과 clustered Indexing에 대해서 공부한 뒤에 다시 알아보면 좋을 것 같다.