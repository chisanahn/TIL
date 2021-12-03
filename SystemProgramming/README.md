## 어셈블러 요약 정리

### 레지스터

**%eax** : 리턴 값으로 주로 사용
%edx, %ecx, %ebx, %esi, %edi

**%ebp** : base point
**%esp** : stack point
EFLAGS : condition codes
**%eip** : Instruction pointer



### 피연산자

상수 : $0x4
레지스터 : %eax
메모리 : (%eax)

> D(Rb, Ri, S) -> Rb + S\*Ri + D 
>
> ```
> 4(%eax, %edx, 4) = (%eax + 4*%edx + 4)
> ```



### instructions

> 기본적으로 피연산자를 src, dest 순으로 입력받는다.

**movl**

```
movl $0x4, %eax
movl $0x4, (%eax)
```

**Arithmetic/Logical**
addl, subl, mull, imull, sall, sarl, shrl, xorl, andl, orl
Dest만 받는 연산자 : incl, decl, negl, notl

**leal** : movl과 비슷하지만 주소값만 연산해서 전달한다.

```
leal (%edx, %eax, 2), %ecx
```



#### Condition

**cmpl** : `b-a`

```
cmpl b, a
```

**testl** : `a&b`

```
testl b, a
```

**jX**

> 주로 cmpl과 같이 사용된다.

jmp, je, jne
jg, jge, jl, jle
ja, jae, jb, jbe

```
cmpl b, a  // a : b
jle L9     // a <= b 이면 L9로 jump
```

setX : 거의 사용되지 않음.

```
setg %al
movzbl &al, %eax  #zero rest of %eax
```



#### Stack/함수 관련 instructions

**pushl** Src

**popl** Dest



**call** label

1. push %eip
2. Jump label

**ret**

1. pop R.A
2. jum R.A



### 함수 호출 과정

1. pushl `caller save reigster (%eax, %edx, %ecx)`

2. 매개변수들 push

3. call 함수주소

   1. push %eip
   2. Jump 함수주소

4. pushl %ebp

5. movl %esp, %ebp

6. pushl `callee save register (%ebx, %esi, %edi)` 

7. 함수의 body 부분

   <현재 메모리 스택 구조>

   |         ...          |
   | :------------------: |
   | caller save register |
   |       매개변수       |
   |    Return Address    |
   |       Old %ebp       |
   | callee save register |

8. callee save register 원상복구

   ```
   예시) movl -4 (%ebp), %ebx
   ```

9. movl %ebp, %esp

10. ebp 원상복구 `popl %ebp`

11. ret

    1. R.A pop `pop %eip`
    2. jump %eip

12. caller save register 원상복구



## gdb 사용법

> hw3 - binnary password 하면서 공부한 내용

https://oo7-0310.tistory.com/72
https://github.com/gurugio/book_assembly_64bit/blob/master/debuggdb.md

처음 보는 movabs는 64bit 값을 레지스터에 write할때 사용된다.

그리고 수업시간에 배웠던 %ebp, %eax랑 달리
%rbp, %rax 등은 64bit 레지스터다.

b <함수이름>

r

ni

```
info registers eip
// 레지스터 값 출력
```

```
x/16x $(메모리포인터)
// 메모리에 저장된 값 출력
```

```
info locals
// 지역변수 출력
```

https://woo-dev.tistory.com/122

```
rep stos %rax,%es:(%rdi)
// ecx 횟수만큼 반복해서 eax값을 rdi가 가리키는 메모리 공간에 복사
```

https://m.blog.naver.com/sheld2/221842896311



어우.. 봐도봐도 모르겠어서 youtube 영상을 좀 참고했다.
https://www.youtube.com/watch?v=VroEiMOJPm8

```
set disassembly-flavor intel
```

1. jmp를 따라 전체적인 흐름 파악하기.

> 암호를 피해서 로그인하는 방법이라서 



https://www.youtube.com/watch?v=jyOoUxzrtTw

아 찾았다.

레지스터 확인

```
set disassembly-flavor intel
disas main
b *main
b *main+35
info b
delete 1
delete
r
info reg rax
x/x $rax
x/s $rax
```

안보이던 레지스터에 저장된 문자열들이 보이기 시작했다.

checkpw를 호출하기 직전에 rax가 가리키는 메모리에 `iamnotyours`가 저장되어 있고 rdx가 가리키는 메모리에 사용자로부터입력받은암호가 저장되어 있다.



### 특정 명령어를 치면 gdb가 종료되는 문제

info registers 같은 명령어를 치면 gdb가 그냥 종료되어 버린다.

구글링을 좀 해보다가 잘 못 찾겠어서 stackoverflow에 질문해봤더니 8.2 이전버전에 있던 오류라고 버전을 업데이트 시켜주면 해결될 것이라는 답변을 받았다.
https://stackoverflow.com/questions/70173176/gdb-terminated-after-info-registers

하지만 window에서 gdb 8.2 이상 버전을 설치하는 방법을 찾기가 어려워서 포기하고 있다가 다시 생각나서 구글링을 해봤다.
https://stackoverflow.com/questions/67574925/update-gdb-version-on-windows-10
https://stackoverflow.com/questions/67848972/differences-between-msvcrt-ucrt-and-vcruntime-libraries

성공.

참고로 dev-c++ 설치할때 같이 설치되는 gdb 버전은 7.6.1인데 info registers를 입력하더라도 잘 동작한다.
