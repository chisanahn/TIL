2022.02.14 ~ 2022.02.16 충북대학교 모바일 실무 특강 들으면서 공부한 내용 정리

# 모바일 어플리케이션 개발

## 어플리케이션 개발방법

* ### Native

  특정 하드웨어나 OS에서 외적인 지원 없이 그대로 실행

  * Kotlin, Swift
  * 장점
    * 네이티브한 기능 사용 가능 -> 유저 사용성 최적화
  * 단점
    * OS별로 유지보수를 해줘야함.

* ### Hybird

  웹 어플리케이션을 웹뷰를 통해 모바일에서 띄우는 형태

  * PhoneHap, CORDOVA
  * 단점
    * 네이티브 기능 사용 불가
    * 웹뷰의 한계로 인한 성능 문제

* ### Cross-platform

  하나의 언어로 여러 운영체제에서 동작하는 앱

  * React Native, Flutter
  * 단점
    * 디버깅이 까다로움
    * 새로운 네이티브 API가 나오더라도 지원되는데 시간이 걸림

<br>

## 기획

* flow chart 구상
* 디자인

<br>

# Flutter

* ### 크로스 플랫폼

  iOS, Android, Web, Desktop에서 동작 가능.

* ### UI Framework

  * Widget
  * Layout

* Dart라는 언어 사용

* Engine이 C/C++로 개발되어서 성능이 좋다.

* React Native보다 나중에 출시. 하지만 점점 Flutter의 입지가 높아지고 있음. [구글 트렌드를 이용해서 살펴 본 Flutter vs React Native](https://trends.google.co.kr/trends/explore?date=today%205-y&q=Flutter,React%20Native)

<br>

## Flutter & Android Studio 설치

* window search bar에 `env`를 검색하면 환경변수설정 창이 나온다.
* `flutter doctor` 명령어로 flutter 개발환경 점검
* android studio 설정에서 `Android SDK Command Line Tools` 활성화 하기

<br>

## Widget

* Flutter에서 UI를 구성하는 모든 기본 단위 요소

* 눈에 보이지 않는 padding, margin 같은 요소, 만들어진 화면 또는 프로그램도 포함해서 모두 위젯으로 취급한다.

* 트리 구조로 계층적인 관계를 형성

* 위젯의 종류

  * Stateless Widget : 정적인 위젯. ex) 로고, 앱 타이틀 등

  * Stateful Widget : 동적인 위젯. ex) 체크박스, 라디오버튼 등

  * MaterialApp : 내비게이터, 앱 전반적인 테마 설정

    > 안드로이드에서만 적용됨
    >
    > iOS의 경우 CupertinoApp으로 진행

  * Scaffold : 화면의 구조 설정

  * Layout Widget

    * Container
    * Center
    * Padding
    * SafeArea
    * Column & Row
    * Expanded
    * Stack
    * SizedBox

<br>

## Responsive Design

현재 기기의 크기를 받아와서 사용할 수 있다.

```dart
Size _size = MediaQuery.of(context).size;
```

<br>

## flutter pub

설치

```bash
$ flutter pub add cloud_firestore
```

제거

```
$ flutter pub remove cloud_firestore
```

<br>

## 생명주기

https://devmg.tistory.com/186

* `setState()`를 사용해야 화면이 다시 구축되면서 변경 사항이 반영된다.

<br>

## FlutterFire

flutter firebase 연동

공식문서 : https://firebase.flutter.dev/docs/overview

### 관련 API

* cloud_firestore
* firebase_auth
* firebase_core

### email/password 인증 관련 doc

* https://firebase.flutter.dev/docs/auth/usage#emailpassword-registration--sign-in

### FirebaseAuthException

* Error code 모음

  https://firebase.google.com/docs/auth/admin/errors

  * email-already-in-use
  * weak-password
  * invalid-email

<br>

## 개발환경 관련 오류

### Shader Compilation error

flutter를 실행시킬때 동작하는데 크게 문제는 없지만 `Shader compilation error`가 발생하길래 찾아서 해결했다.

emulator에서 OpenGL ES AP level 설정을 `Compatibitlity`로 바꾸면 된다.

https://stackoverflow.com/questions/58380329/flutter-1-9-d-skia-5106-shader-compilation-error

### app\build.gradle 관련 초기 설정 오류

https://ilsognobella.tistory.com/29

<br>

## Dart 문법

* Null safety
  * 해당 객체가 무조건 `null`이 아닌 경우 객체 뒤에 `!`를 붙여서 null safety를 해제할 수 있다.

<br>

## IDE

* ### TODO

  주석에 TODO를 넣어서 작성하면 모아서 확인할 수 있다. (Android studio, Intellij, vscode 등에서 지원)

  ```dart
  //TODO 어쩌구저쩌구
  ```

* ### emulator

  Galaxy Developer 홈페이지에서 각 기종별 인치, 해상도 뿐만 아니라 emualtor skin도 다운받아서 사용할 수 있다.

### Android Studio

* 일단 어플 개발에 있어서 필수적인 IDE. 하지만 zoom이랑 함께 사용했더니 정말 버벅거린다.

### VS code

* #### emulator

  vscode에서 개발할때 emulator는 어떻게 사용해야되나 싶었는데 android studio의 emulator를 가져다 쓸 수 있다.

* #### wrapping with widget

  android studio에서 `Alt+Enter`를 이용해서 사용하던 기능인데 vscode에서는 refactoring으로 해당 기능을 사용할 수 있다.

  refactoring 단축키는 `Ctrl+Shift+R`

  https://stackoverflow.com/questions/52379831/how-to-surround-flutter-widget-in-vscode

* #### 메소드로 이동

  `Ctrl+P` 눌러서 명령팔레트로 이동 후 `#`을 입력한 뒤 메소드 이름 검색.

  https://stackoverflow.com/questions/45440198/how-search-for-method-in-vscode
  
* #### Quick fix

  const 추가 등의 작업을 빠르게 수행할 수 있다.

  단축키 `Ctrl+,`. 

<br>

## 상태관리 라이브러리 getX

https://pub.dev/packages/get

* 상태관리자

* 반응형 상태관리자

  stateless widget에서도 변화를 줄 수 있다.

* Stream Builder보다 더 간편하게 실시간 데이터 변경사항을 처리할 수 있다.

React에도 `Redux`라고 상태관리라이브러리가 있는데 react와 flutter에서 상태가 동일한 개념일지, `Redux`와 `getX`가 언어가 다르고 비슷한 기능을 수행한는건지 궁금해졌다.

<br>

## Google play store에 앱출시

https://play.google.com/console/about/?utm_source=google&utm_medium=cpc&utm_campaign=Console2020-Branded&utm_term=google%20play%20console%7ce&utm_content=454036411622&gclid=Cj0KCQiAu62QBhC7ARIsALXijXTftvBqRaAUIweLw-yvJxrbkAho92eh1VPrKzP7a7mDZY4fCN3woNwaAh-zEALw_wcB