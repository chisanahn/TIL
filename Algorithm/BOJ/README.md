[BOJ 1181 단어 정렬](https://www.acmicpc.net/problem/1181)

> bubble_sort로 구현시 시간초과  
> merge_sort 복습

## solved.ac CLASS 2+

[BOJ 2751 수 정렬하기 2](https://www.acmicpc.net/problem/2751) - 해결(merge sort)

[BOJ 11866 요세푸스 문제 0](https://www.acmicpc.net/problem/11866) - 성공

[BOJ 9012 Parenthesis](https://www.acmicpc.net/problem/9012) - 성공

[BOJ 11650 좌표 정렬하기](https://www.acmicpc.net/problem/11650) - 성공

[BOJ 1181 단어 정렬](https://www.acmicpc.net/problem/1181) - 성공   
>직접 merge sort로 구현하려고 하니깐 머리도 아프고 오류도 계속 났는데 map을 이용하니깐 엄청 간단하게 구현할 수 있었다.

[BOJ 10814 나이순 정렬](https://www.acmicpc.net/problem/10814) - 성공

[BOJ 10866 덱](https://www.acmicpc.net/problem/10866) - 성공

[BOJ 1018 체스판 다시 칠하기](https://www.acmicpc.net/problem/1018) - 성공   
>https://www.acmicpc.net/submit/1018/32219355 성공한 코드들이랑 다를게 없는 거 같은데 채점해보면 틀렸다고 나온다.

[BOJ 15829 Hashing](https://www.acmicpc.net/problem/15829)   
> 성공 - modular 연산만 잘 알고 있다면 쉽게 풀수있는 것 같다.   

[BOJ 1436 영화감독 숌](https://www.acmicpc.net/problem/1436)
> 보류 - 몇번째 숫자를 어떻게 구해야할지 생각하기가 좀 어렵다.   
> 규칙을 어느정도 찾아서 구현하고 있는데 어우 어렵다..   
> 실패 - 실수로 7번째에 6660이 아니라 6000을 출력했다.   
> 실패 - 어디서 실패한건지 모르겠다. 오버플로우가 나서 그런가 해서 long long으로 바꿨는데 여전히 오답으로 나온다. 어디서 중복이 나는 경우를 고려하지 못한거같다.   

> https://st-lab.tistory.com/103    
찾아보니 브루트포스 알고리즘을 이용해서 문자열로 풀면 쉽게 풀 수 있는 문제인것 같다. 그리고 나처럼 int로 구간을 나눠서 푼 사람도 있어서 참고하려고 했는데 방식이 조금 달라서 내 방법으로 다시 첨부터 차근차근 해봤다.    

> 10000을 입력했을때 266799가 나와야하는데 2662666이 나오는걸보면 아무래도 중복해서 센 부분이 있는 것 같다.    
> 손으로 직접 써가면서 풀어봤는데 2860에서 원래 699666이 나와야되는데 이상한 값이 나오는것을 발견했다.    
> 계속 하면 할수록 예외 처리 해야되는게 새로 나와서 끝이 없다... 이문제에만 몇시간을 쓴건지 모르겠다.   

> 더 이상하는건 미련인 것 같아서 다른 사람의 코드를 참고해서 해결하기로 결정했다.   
그리고 앞으로도 문제를 해결할때는 한시간안에 못풀면 다른 사람의 코드를 참고하기로 결정했다.   


## 오늘의 교훈
> 알고리즘 문제를 풀때 어느정도 시간을 정해두고 정 안풀리면 다른 사람들 코드를 참고해서 공부하자.    
> 아직 모르는 알고리즘 개념도 많고 경험도 적어서 오래 고민하더라도 풀리지 않을 가능성이 높다. 그리고 그 시간에 다양한 문제를 풀어보는게 오히려 더 도움이 될 것 같다.   

> 어떤 블로그에서 알고리즘 문제 풀때 한문제를 너무 오래 붙잡고 있는것은 오히려 독이 된다고 시간을 정해두고 푸는 것이 좋다고 했는데 오늘 정말 뼈저리게 느낀다..    


[BOJ 2805 EXO](https://www.acmicpc.net/problem/2805)
> 성공. 중간에 자료형을 잘못써서 한번 틀리긴 했지만 그래도 최근에 분할 정복 문제를 많이 풀어봐서 그런가 수월하게 풀었다.

[BOJ 10989 수 정렬하기 3](https://www.acmicpc.net/problem/10989)
> 성공. 처음에 vector로 풀었다가 메모리 초과가 나서 map으로 다시 풀었다.

[BOJ 11651 좌표 정렬하기 2](https://www.acmicpc.net/problem/11651)
> 성공. 뭔가 꼼수인거 같기도 하지만 x랑 y 위치만 바꿔서 map이랑 pair 이용해서 풀었다.

[BOJ 1966 Printer Queue](https://www.acmicpc.net/problem/1966)
> 보류 - 조금 생각이 필요할 것 같다. 앞에 있는 우선순위가 낮은 수들을 뒤로 옮기는 과정에서 변동이 생겨서 단순히 우선순위큐를 써서 풀 수는 없는 것 같다.   
> 성공 - 큐에 우선순위와 인덱스를 저장해서 사용하고, 우선순위를 체크하기 위해서 크기 10짜리 벡터를 하나 만들어서 관리하는 방식으로 구현했다. 꽤 까다로웠다.

[BOJ 10773 Zero That Out](https://www.acmicpc.net/problem/10773)
> 성공. stack만 안다면 쉽게 풀 수 있는 문제인것 같다.

[BOJ 2108 통계학](https://www.acmicpc.net/problem/2108)
> 성공. 엄청 간단할 줄 알았는데 최빈값을 어떻게 구할지 생각이 잘 안나서 좀 힘들었다.

[BOJ 4949 The Balance of the World](https://www.acmicpc.net/problem/4949)
> 성공. 괄호 종류만 2개로 늘어나고 전에 풀어봤던 문제랑 비슷해서 수월하게 풀 수 있었다.

[BOJ 18111 마인크래프트](https://www.acmicpc.net/problem/18111)
> 성공. 28ms. map을 이용해서 풀었다.   
지금은 실버 정도 난이도가 나한테 잘 맞는 것 같다. 적당히 어려워서 고민을 좀 해야 풀리다보니 성취감도 느껴지고 좋다.

[BOJ 1874 스택 수열](https://www.acmicpc.net/problem/1874)
> 성공. 20ms. stack을 이용해서 직접 돌려보는 식으로 구현했다.

[BOJ 15353 큰 수 A+B(2)](https://www.acmicpc.net/problem/15353)
> 전에 이 문제를 푸느라 애먹었던 기억이 나서 다시 한번 풀어봤다.   
> 성공. 종만북에서 한번 풀어봐서 그런가 그래도 수월하게 풀었다.

[BOJ 7568 덩치](https://www.acmicpc.net/problem/7568)
> 성공. 입력의 크기가 작은걸 보고 O(n^2)으로 그냥 무식하게 풀어버려도 될 것 같아서 수월하게 풀었다.

## 브루트 포스 알고리즘 (종만북 - 무식하게 풀기)

모든 경우의 수를 탐색하는 알고리즘.     
대표적으로 순차 탐색, 깊이우선탐색(DFS), 너비우선탐색(BFS)을 사용한다.

문제 해결 방법
1. 주어진 문제를 선형 구조로 구조화한다.
2. 구조화된 문제공간을 적절한 방법으로 해를 구성할 때까지 탐색한다.
3. 구성된 해를 정리한다.

[BOJ 1436 영화감독 숌](https://www.acmicpc.net/problem/1436)     

브루트포스가 새로운 알고리즘인줄 알았는데 이미 종만북에서 봤었던 "무식하게 풀기"랑 이름만 다르고 내용은 같아서 그렇게 한번 풀어봤는데 아...? 그냥 무식하게 666부터 해당 숫자가 10000개가 나올때까지 for문 돌려서 배열에 저장해서 하니깐 성공했다.     
뭔가 좀 허무하긴 하지만 성공. solved.ac class 2++도 완료했다.    

[BOJ 9935 EXSPLOZIJA](https://www.acmicpc.net/problem/9935)     

작년에 시도해봤다가 못 풀었던 문제.      

메모리 초과. 입력되는 string의 길이도 긴데 재귀함수로 구현하면서 너무 많은 string을 사용해서 그런것같다.     
-> 검사 방식을 바꾸고 매개변수도 참조형으로 바꾸니깐 50%에서 메모리초과.      
-> 배열을 새로 만드는대신 erase 내장 함수 활용. 57%에서 시간초과.     
-> find랑 erase로 코드를 엄청 짧게 짤수있지만 2%에서 시간초과.        
-> stack을 활용해서 한번에 처리할 수 있지 않을까. 폭발물인지 검사하다가 끊겼는데 폭발물의 첫글자인경우는 이어서 셀 수 있다.     
-> Segfault. 폭발물이 중간에 끊겼을때 check를 0으로 초기화하지 않으면서 이상한 곳을 참조하면 오류가 났다.    
-> 시간초과. 아무래도 erase를 수행하면서 시간이 많이 걸리는것같다. erase대신 문자열을 deque에 저장해버리자.     
-> 성공. 36ms.    

[BOJ 9659 돌 게임 5](https://www.acmicpc.net/problem/9659)    

성공. 0ms. 규칙만 찾아낸다면 정말 쉬운 문제.    

[BOJ 1927 최소 힙](https://www.acmicpc.net/problem/1927)    

성공. priority_queue를 사용하면 쉽게 풀 수 있긴하다 (16ms)    

자료구조 복습겸 직접 heap을 구현.     

런타임에러(segfault).      

성공. 배열을 동적할당해서 썼다가 100000 크기 배열을 썼더니 성공했다.

### heap

    heap property(heap-order)를 만족하는 complete binary tree.

    heap property(heap-order)    
    : parent 노드가 child node보다 무조건 작다.


