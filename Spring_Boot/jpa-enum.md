## JPA에서 Enum 이용하기

https://techblog.woowahan.com/2600/

https://www.baeldung.com/jpa-persisting-enums-in-jpa

* @Enumerated 한계점
  * EnumType.STRING : enum type의 이름을 변경할 수 경우 데이터베이스가 깨진다.
  * EnumType.ORDINAL : enum type을 제거하거나 순서를 변경할 경우 데이터베이스가 깨진다.
* 대안
  * **@Converter 사용**

