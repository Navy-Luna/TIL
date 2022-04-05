# Ch1. Basic Concept

## 1.1 Overview: System Life Cycle
### Software development process(소프트웨어 개발 과정)

1. Requirement specification(요구사항 명세화) : 프로젝트의 목적을 정하고 명세화하여 명세서를 작성하는 단계
2. Problem Analysis(문제 분석) : 커다란 문제를 세부적으로 나누는 단계
3. System Design(시스템 디자인) : 프로그램에 필요한 Data Object를 정하고 Object에 사용할 Operation을 결정 - ADT(Abstract Data Type)을 정하고 Algorithm 명세화를 한다.(프로그램 언어와 무관하게 independent하게 진행된다.)
4. Coding&Refinement(코딩&개선) : Data Object를 표현할 것을 결정하고 실제로 알고리즘을 작성하는 단계
5. Verification(확인) : Correctness proofs/Testing/Error removal

## 1.2 Pointers and Dynamic Memory Allocation(포인터와 동적 메모리 할당)
- Pointer
  + & : the address operator(주소 연산자) - 변수에 붙이면 해당 정보가 저장된 메모리 주소를 확인 가능
  + \* : the dereferencing(or indirection) operator(역참조 주소 연산자) - 주소에 담겨있는 내용물을 확인 가능

[Variable And Pointer][https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch1_Basic_Concept/VariableAndPointer.c]

## 1.3 Algorithm Specification(알고리즘 상술)
### (1) Definitions of Algorithms(알고리즘의 정의)

  알고리즘은 어떤 특정 목적을 달성하기 위한 유한한 명령어의 집합, 일종의 문제해결을 위한 메뉴얼이나 절차, 문제풀이법이라고 보면 된다. 알고리즘에는 따라야할 5가지 조건이 있음
  - input(>=0) : 0개 이상의 input이 들어가야함
  - output(>0) : 1개 이상의 output(결과물)이 나와야한다. - input과는 구별됨
  - definiteness(명확성) : 수행 과정은 명확하고 모호하지 않은 명령어로 정의되어있어야한다.
  - finiteness(유한성) : 유한 개의 명령어가 유한시간 내에 수행되어야한다. 답도 없이 계속 이어지는건 안된다.. Ex) While(1){printf(".")}
  - effectiveness(유효성) : 모든 과정은 실현 가능(검증이 가능)해야만 한다 = 알고리즘의 모든 연산들이 사람이 종이와 연필을 이용해서 유한한 시간안에 정확하게 수행될 수 있을 정도로 단순하여야 한다.
  
### (2) How to describe an algorithm?(알고리즘의 표현방식)
  - Use a natural language like English(자연어를 사용한 기술)
  - Use graphic representations called flowcharts(순서도, 흐름도와 같은 그림)

### (3) Translating a Problem into an Algorithm(문제를 알고리즘으로 바꾸기)
  #### 1) Selection Sort(선택 정렬)
  
  *\<Description of a Problem\>*   
  1개 이상의 집합으로 이루어진 정수들을 정렬하는 문제(오름차순)  
  
  *\<A simple solution\>*   
  정렬이 안되있는 정수를 중에서 가장 작은 정수를 가져와 정렬된 리스트 바로 다음에 둔다.   
  
  i. 배열의 원소 중 최솟값을 찾아 맨 앞에 나둔다.   
  ii. 두번째 원소를 기준으로 뒤의 배열 요소들과 크기를 비교한다. 만약 두번째 배열 요소보다 작은 수가 나오면 switch   
  iii. 기준이 되는 위치가 n-1에 도달했을때 종료..
  
  <img src="https://user-images.githubusercontent.com/97028605/161677844-ee427e17-a237-4964-aa25-6861f60de749.png" width="400px" height="600px"></img>
  
  - 배열 원소 a와 b를 바꾸는 Swap의 구현(function, macro)
    + __Function__ : 사용할 때 swap(&a,&b)
    ```c
    void swap(int *x, int *y)
    { /* 배열이 int형이기 때문에 int형 포인터를 선언 */
        int temp = *x;  // temp는 임시 저장소
        *x = *y;        // x에 y의 값을 저장
        *y = temp;      // x에서 temp로 옮겨둔 값을 y에 저장
    }
    ```
    
    + __Macro__ : 사용할 때 SWAP(a,b,temp) -> ☆ 주소값 안넣어도 알아서 바뀌도록 처리
    ```c
    #define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )      // function과 다르게 어떤 data type으로도 가능
    ```
  
  > 구현한 코드 : https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch1_Basic_Concept/SelectionSort.c

 #### 2) Binary Search(이진 탐색)
  
  *\<Description of a Problem\>*   
  1개 이상의 원소로 이루어진 배열(단, 오름차순으로 정렬된 배열!!!!!)에서 특정 숫자를 찾아내야 한다. 
  
  *\<A simple solution\>*   
  찾아가는 범위를 절반씩 좁혀가면서 숫자를 찾아낸다. list[middle]을 활용  
  
  i. 배열의 처음과 끝을 first, last 그리고 middle = (first+last)/2로 정의   
  ii. 찾으려는 숫자와 list[middle]의 숫자크기를 비교   
  iii. 만약 searchnum == list[middle]이면 종료, searchnum이 더 크면 first = middle+1로 바꾸고 재탐색, 작으면 last = middle-1로 바꾸고 재탐색(오름차순일때..)


  <img src="https://user-images.githubusercontent.com/97028605/161685915-02c6cd69-2849-4af4-871c-1c96bcd7232c.png" width="400px" height="300px"></img>
  
  - 배열 원소 x와 y를 비교하는 Compare의 구현(function, macro)
    + __Function__
    ```c
    int compare(int x, int y)
    { /* 단순 비교만 하면 되기 때문에 일반 int형 사용 */
        if (x<y) return -1;   // y가 더 크면 음수 반환
        else if (x==y) return 0;
        else return 1; // x가 더 크면 양수 반환
    }
    ```
    
    + __Macro__
    ```c
    #define COMPARE(x,y) ( ((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1  )      // function과 다르게 어떤 data type으로도 가능
    ```

  > 구현한 코드 : https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch1_Basic_Concept/BinarySearch.c
  
## 1.4 Data Abstraction   
Data Type(데이터 타입)이란 object의 collection이자 object에 사용할 수 있는 operation의 연산자 집합이다. (약간 숫자가 집합이면 거기에 쓰는 +,-들..)
모든 programming language는 기본적인 "predefined data types"와 새롭게 정의해서 만드는 "user defined data type"이 존재한다.   

### ★ Abstract Data Type(ADT)?
  Data Type인데 거기에 속하는 object나 작동하는 operation이 구체적으로 어떻게 작동하는지에 초점을 두지않고 독립적인 방식으로 정리되는 Data 자료형이다!(특정 Programming Language에 독립적이다!) -> 약간 Object에는 뭐가 있고 operation의 기능에 관해 간단히 설명해 둔 개념서? 설명서? 같은 느낌으로 표현해 둔다.
  
  - ADT의 operation의 종류
    + Creator/Constructor : 지정된 타입에 대한 새로운 인스턴스를 만들어낸다.
    + Transformers : 기존에 있던 자료형 인스턴스를 활용하여 새로운 인스턴스를 만들어낸다.
    + Observers/reporters : 인스턴스에 관한 정보들을 제공해준다. 하지만 내부 정보를 변경하는 것은 불가능하다.
    
 ### 정리
  \- Primitive Data Type(implicit operation)   
  \- Abstract Data Type(explicit operation)
  
  \- Data Structure(자료구조) = Data Type(데이터 타입) + Storage Structure(저장공간의 구조)   
  \- Program(프로그램) = Data Structure(자료구조) + Algorithm(알고리즘)
  
-------------------------------------------------------------------------------------------------------------------

## 1.5 Performace Analysis(성능 분석)
 * Performace Evaluation(성능평가)
    + Performace Analysis(성능분석 - time과 space로 추정하며 machine independent하다.)
      - Space Complexity(공간복잡도) : 프로그램이 running 하는데 필요한 메모리 요구량
      - Time Complexity(시간복잡도) : 프로그램이 running 하는데 필요한 계산 시간 양
    + Performace measurment(성능측정 - machine dependent하다.)
    
 ### 1.5.1 Space Complexity
 > S(p) = c + Sp(I)

 - S(p) : 프로그램 P의 전체 space 요구량
 - c : constant하게(고정되게) 요구되는 space 요구량
 - Sp(I) : 인스턴스 I(예를 들어, 배열)를 처리하며 변화가능한 space 요구량 ~ 인스턴트 I의 I/O와 관련된 number, size, value의 영향을 받는다.   

Sp(I)에서 길이가 n인 배열을 처리할 때, n은 instance characteristic이며 오직 n에만 영향을 받는다면 Sp(n)으로 적을 수도 있다. Sp가 space complexity를 analysis하는데 가장 중요하게 봐야할 부분!

```c
  // 실행할 때마다 다른 크기의 메모리 용량이 필요한 것이 아니다. 따라서 Sabc(I)=0
  float abc(float a, float b, float c)
  {
     return a+b+b*c+(a+b-c)/(a+b) + 4.00;
  }
```

```c
  // 전달되는 n에 따라 사용하는 용량은 다르겠지만 실행마다 바뀐다는 느낌은 아님! -> 추가 용량 사용이 없음.. Ssum(I) = 0
  float sum(float list[], int n)
  {
     float tempsum = 0;
     int i;
     for(int i=0; i<n; i++)
       tempsum += list[i];
     return tempsum
  }
```

```c
  /* 아래와 같이 함수가 recursive하게 불려질 때, 컴파일러는 각 recursive call마다 스택 공간에 저장을 해야함! 
     -> 추가 용량 사용이 n에 따라 변화한다. Srsum(I) > 0 */
  float rsum(float list[], int n)
  {
     if (n) return rsum(list,n-1) + list[n-1];
     return 0;
  }
```
 
### 1.5.2 Time Complexity
와 뭐야

-------------------------------------------------------------------------------------------------------------------


# Additional Study
## 난수 생성 in C Programming   
  무작위로 생성되는 수를 "난수"라고 한다. 이런 난수를 C언어에서 만들어내는게 <stdlib.h> 라이브러리에 포함되어있는 rand()함수   
  1. rand() 함수는 0~32767의 숫자를 만들어냄
  2. 하지만 프로그램 실행시마다 일정한 숫자를 만들어냄 -> 이를 위해서 사용하는게 srand() 이용하는데 srand는 rand에 특정 시드값을 부여
  3. srand(숫자).. 만약 더 랜덤한 수를 만들어내고 싶다면 srand(time())을 사용(time 함수는 time.h 라이브러리에 존재)
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  
  int main()
  {
      // srand(10) : seed 값이 10으로 고정된 채 출력
      // srand(time()) : 시간에 따라 바뀌는 숫자에 의해 랜덤한 숫자 출력
      
      for(int i=0; i<10; i++)
        printf("%d",rand()%10+1);   // rand함수를 이용하여 1~10까지 숫자를 10개 출력
    
      return 0;
  }
  ```

# Reference
- Horowitz, Shani, & Anderson-Freed, ªFundamentals of data structures in Cª, (2nd edition) Silicon-press
- 선택정렬 : https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html
- 난수생성 : https://yeolco.tistory.com/64
