Stack(스택)
=======
# 1. 스택이란?
## 1.1. 스택의 이해
- 스택은 선형 자료구조의 일종
- 스택은 먼저 들어간 데이터가 나중에 나오고 나중에 들어간 데이터가 먼저 나오는 특성을 지님
- '후입선출 방식의 자료구조' 혹은 'LIFO(Last-In, First-out)'이라고도 불린다.

## 1.2. 스택의 구현
스택에 필요한 기능은 크게 Push(데이터 넣기), Pop(데이터 뽑기), Peek(데이터 확인)으로 나뉜다. 이 3가지 기능을 구현하는 것이 Stack 자료구조 구현의 핵심이며 여기에 추가로 Stack의 선언 후에 
초기화하는 기능이나 스택이 비었는지 확인하는 기능을 추가할 수 있다. 스택을 구현하는 방법은 크게 "배열"을 기반으로 구현하는 방법과 "연결리스트"를 기반으로 구현하는 방법으로 나뉜다.
![Stack Pic](https://user-images.githubusercontent.com/97028605/155842823-5f1daec9-7070-49c7-838a-8d07873abdd4.jpeg)


* __배열을 이용한 구현방식__
1. 인덱스를 이용한 접근 방식으로 빠르게 접근 가능하지만 사용할 수 있는 양이 정해져있으며 메모리 낭비가 발생할 수 있음
2. 구현시에 Top(맨 꼭대기를 가리키는 인덱스)을 관리하는 것이 핵심

> [구현해 본 코드들] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/ArrayBaseStack.h)  / [Source file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/ArrayBaseStack.c) / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/ArrayBaseStackMain.c)


* __연결리스트를 이용한 구현방식__
1. 배열을 이용한 구현방식에 비해 메모리를 더 효율적으로 사용할 수 있음
2. 구현을 하며 메모리를 할당하고 free해주는 작업을 신경써줘야만 함(연결리스트 기반이기 때문)
3. 연결리스트에 새로운 노드를 추가할 때, head 부분에 계속해서 추가해주면 그것이 바로 우리가 구현하고자 하는 **스택**!

> [구현해 본 코드들] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/ListBaseStack.h) / [Source file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/ListBaseStack.c) / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/ListBaseStackMain.c)


----------------------------------------------------------------------
# 2. 심화 : 계산기 구현
## 1.1. 기본 개념
### * 수식 표기법의 종류
1. 전위 표기법(ex. +AB) : 연산자를 먼저 표시하고 연산에 필요한 피연산자를 나중에 표기하는 방법
2. 중위 표기법(ex. A+B) : 연산자를 두 피연산자 사이에 표기하는 방법으로 가장 일반적으로 사용되는 표현 방법
3. 후위 표기법(ex. AB+) : 연산에 필요한 피연산자를 먼저 표시하고 연산자를 나중에 표기하는 방법

우리에게 제일 익숙한 것은 중위 표기법이지만 스택을 통해서 식을 처리할 때 중위 표기법으로 표시된 식이 '연산 순서'를 포함하고 있지는 않다. 소괄화나 대괄호에 의해서 연산 순서가 달라지는데 중위
표기법으로 표현된 식의 경우에 처리하기가 매우 어렵다. 그래서 식 자체에 '연산 순서'를 포함하고 있는 전위 표기법이나 후위 표기법을 사용해야 한다.

Ex. 후위 표기법의 경우 ABC+/가 된 식이 있을 때, +가 /보다 앞에 위치함으로서 먼저 연산에 활용된다는 것을 알 수 있음


### * 후위 표기법 식 계산법
후위 표기법으로 표현된 식의 경우 연산자와 그 앞의 피연산자 2개를 묶어서 하나의 세트로 봐야됨. 예를 들어서 123+* 8+에서 + 연산이 맨 앞에 있으므로 +와 앞에 있는 2와 3을 활용하여 연산을
해주어야 된다.

> 123+* 8+ -> 15* 8+ -> 58+ -> 13 
> 
> [구현해 본 코드들] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/PostCalculator.h) / [Source file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/PostCalculator.c) / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/PostCalculatorMain.c)

### * 중위 표기법 식 연산 STEP
1. 중위 표기법 식을 후위 표기법 식으로 바꾼다.
2. 후위 표기법 식을 계산한다.
3. 계산한 결과를 출력한다.


## 1.2. 중위 표기법을 후위 표기법으로 바꾸는 알고리즘
중위 표기법의 수식을 후위 표기법의 수식으로 바꾸기 위해서는 식이 포함된 배열(A)와 후위 표기법으로 바뀐 수식을 저장할 배열(B) 그리고 연산자들을 잠시 저장해 둘 Stack이 필요하다.
배열A의 숫자들을 B로 옮길 경우에는 그냥 옮기면 됨. 하지만 연산자는 우선 순위에 따라(곱하기,나누기 > 더하기,빼기 > 소괄호) 스택에 넣어둬야됨. Stack이 비어있을 때는 상관없이 push

Stack이 비어있지 않고 옮기려는 연산자가 Stack의 연산자보다 우선순위가 높으면 Stack에 Push 그렇지 않으면 Stack의 연산자를 B로 옮기고 A에서 옮기던 연산자를 Stack에 Push한다.(동일 우선순위의
연산자도 마찬가지로 처리) A에서 더 이상 옮길 것이 없다면 Stack의 것들을 모두 B로 이동시킴

* 피연산자는 그냥 옮긴다.
* 연산자는 Stack으로 옮긴다.
* 연산자가 Stack에 있다면 우선순위를 비교하여 처리방법을 결정한다.
* 마지막까지 Stack에 남아있는 연산자는 하나씩 꺼내서 옮긴다.

소괄호가 포함됐을땐 (가 입력되고 )가 입력되기 까지 기존의 방식을 유지하다가 )가 입력되면 Stack에 있는 연산자들을 하나씩 B로 모두 옮김
> [구현해 본 코드들] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/InfixToPostfix.h) / [Source file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/InfixToPostfix.c) / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/infixToPostfixMain.c)

## 1.3. 중위 표기법으로 표현된 식을 계산하는 코드
위에서 구현한 "중위표기법->후위표기법" 구현 코드와 "후위표기법 계산 코드"를 합쳐서 중위 표기법으로 구현된 식을 계산하는 코드를 만들어 냄
> [구현해 본 코드들] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/InfixCalculator.h) / [Source file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/infixCalculator.c) / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Stack/InfixCalculatorMain.c)
----------------------------------------------------------------------
# 3. 기타
## 1.1. 놓치거나 새롭게 알게된 것들
1. 후위 표기법으로 된 식을 계산할 때 스택에 1,-2라는 숫자가 있고 - 연산을 해야하는데 3이라는 예상결과값과는 다르게 -3이라는 결과값이 발생했음 -> Stack은 구조상 LIFO이기 때문에 먼저 튀어나온 숫자가 2번째 피연산자이고 나중에 튀어나온 피연산자가 1번재 피연산자임! 즉, 1-(-2)인데 stack의 구조를 생각하지 못하고 -2-1을 연산해서 발생해 버린 문제!!
2. InfixToPostfix.c 구현 과정에서 strcpy를 이용하여 exp(배열 포인터)에 chstr의 문자열을 복제해야하는 과정이 있었음. 복제 대상이 복제 되는 장소보다 메모리가 클 때, 메모리 Error가 발생하는데 코드를 구현하는 과정에서 메모리의 크기를 나타내는 sizeof가 아니라 strlen을 사용해서 해당 문제가 발생했음!! strlen은 배열의 길이를 돌려주고 sizeof은 해당 자료/자료형의 크기를 반환함!! exp는 길이가 5인 배열이고 chstr도 길이가 5인 배열이여서 strlen 결과 5가 나오지만 둘 다 배열 포인터이기 때문에 실제로는 메모리 용량이 8byte(64bit 아키텍쳐 아래에선 포인터의 크기는 8byte)임!
https://moscowmule.tistory.com/1
3. memset(void* memset(void* ptr, int value, size_t num) : memset 함수는 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수 : https://blockdmask.tistory.com/441
4. 문자를 숫자로 형변환하는 방법(별개의 라이브러리 함수 사용X, 아스키코드의 관점에서 접근) : https://apape1225.tistory.com/26

## 1.2. 앞으로 해 볼 것들
1. 원형 연결 리스트를 이용한 스택의 구현
2. 중위 표기법으로 된 수식을 전위 표기법으로 된 수식으로 바꾸어 계산하는 
