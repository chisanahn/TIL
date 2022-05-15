## object를 생성하거나 업데이트 하는 경우 해당 object를 http response에 포함시켜야 하나?

가능하다. 사용 용이성 vs 네트워크 사이즈의 차이.

다만, 꼭 필요한 경우가 아니면 불필요한 네트워크 사용량을 줄이기 위해서 보내지 않는 것이 좋다.

> **참고자료**
>
> https://softwareengineering.stackexchange.com/questions/314066/restful-api-should-i-be-returning-the-object-that-was-created-updated