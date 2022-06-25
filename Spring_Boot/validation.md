# Spring Boot Request Validation

검증하고 싶은 입력 객체에 대해서 해당 class에 여러 Annotation을 이용해서 validation 조건을 추가하고, Controller의 `@RequestBody` 뒤에 `@Valid` Annotation을 붙여서 검증할 수 있다.

`@Valid`는 java에서 기본적으로 제공되는 기능이고, Spring에서 지원해주는건 `@Validated`라고 봤는데 어떤 차이가 있는지는 아직 잘 모르겠다.

<br>

Controller 파라미터에 `BindingResult`를 추가해서 검증이 실패되었을때 에러처리를 따로 할 수 있다.

`BindingResult`를 파라미터에 정의하지 않는다면 `org.springframework.web.bind.MethodArgumentNotValidException`가 발생한다.

따라서 `@ControllerAdivce`와 `@ExceptionHandler`를 이용해서 전역 설정을 해주는 것 또한 가능하다.