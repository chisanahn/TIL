## stateful한 Composable을 stateless하게 만들어서 재사용성 높이기

android에서는 `state`이라는 개념을 활용해서 변수를 관리한다.

state로 관리되는 변수의 값에 변화가 생긴다면 해당 변수를 사용하는 모든 Composable이 다시 recomposition 된다.

> `remember`라는 API를 이용해서 state를 만들어서 관리할 수 있다

이때 하나의 Composable이 아닌 여러 개의 Composable에서 사용중인 변수는 어떻게 관리해야되나 하는 궁금증이 생겼는데

`state-hoisting`이라는 개념을 통해서 이를 해결할 수 있다.

> - **Shareable**: Hoisted state can be shared with multiple composables. Say we wanted to name in a different composable, hoisting would allow us to do that.
>
> android 공식문서에서 나오는 `state-hoisting`의 특징 중 하나

<br>

https://developer.android.com/jetpack/compose/state#state-hoisting

