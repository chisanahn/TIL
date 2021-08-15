# 알고리즘 공부
- [종만북](https://github.com/chisan01/Algorithm/tree/master/JongmanBook)
- [ICPC 준비 - 2021 SW개발능력향상 프로그램](https://github.com/chisan01/Algorithm/tree/master/ICPC)
- [BOJ](https://github.com/chisan01/Algorithm/tree/master/BOJ)
- ## 기타

#### 입출력 최적화
```c++
  ios_base::sync_with_stdio(0);
  cin.tie(0);
```
> 알고리즘 문제를 풀 때는 싱글 쓰레드 환경을 사용하므로 위 코드로 동기화를 끊고 최적화해서 cin, cout을 쓰는게 시간적인 측면에서는 가장 좋을 것 같다. (동기화를 끊기 때문에 scanf, printf와 혼용하면 오답이 나올 수 있다.)  
참고: https://hegosumluxmundij.tistory.com/54     


#### 수행 시간 어림짐작하기
> 입력의 크기를 시간 복잡도에 대입했을때 그 값이 1억(10^8)을 넘어가면 시간 초과 가능성이 있다.     


#### 런타임 에러(bad_alloc)
> new 연산으로 메모리 할당이 실패하면 std::bad_alloc이라는 예외가 발생한다. 찾아보니 벡터를 너무 크게 선언해서 메모리 제한에 걸리면서 이러한 에러가 발생한 것 같다. (전역변수로 선언하면 할당되는 공간이 달라서 될때도 있다.)      


#### STL map에서 key 값으로 구조체 사용
> map에서 key 값으로 구조체를 사용하려면 < 연산자를 override 해줘야 한다.   
> 왜냐하면 map에서 기본적으로 key값을 기준으로 오름차순으로 정렬해서 저장하기 때문이다. 
```c++
bool operator<(const 클래스명& 변수명) const
{
  //비교구문을 통해 true, false를 반환
}
```
>  2개의 값을 묶는 경우 구조체보다 pair를 사용하는것이 훨씬 편하다.
왜냐하면 pair 클래스의 경우 sort 알고리즘에 의해 정렬이 가능하기 때문에 그냥 사용할 수 있다.   
(첫번째 인자 기준, 첫번째가 같으면 두번째 인자 기준으로 정렬한다.)

