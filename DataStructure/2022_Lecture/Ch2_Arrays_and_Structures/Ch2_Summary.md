# Ch2. Arrays and Structures

## 2.1 Arrays(정적 할당 배열)
### \# Three perspectives of Arrays(배열에 관한 3가지 관점)
  - A consecutive set of memory locations : 연속된 메모리의 집합이다.
    * emphasis on implementation issuses
    * not always true
  - A set of pairs, <index, value> : 인덱스와 값이 쌍을 이루는 집합니다.
    * set of mappings or correspondence between index and values
  - ADT : more concerned with the operations that can be performed on an Array

```c
#include <stdio.h>

void changearray(int a[]);

int main()
{
	int a[3] = { 1,2,3 };
	changearray(a);
	printf("%d", a[2]);

	return 0;
}

// Array parameter가 call-by-value에 의해 전달되더라도 array의 값이 변화된다.
void changearray(int a[]) // 형식을 살펴보면 int* 형태로 전달된다.
{
	a[2] = 10; // *(a+2)=10과 같은 표현.. a+i에서 i는 크기는 자료형에 맞게 자동 계산된다.
	return;
}
```

## 2.2 Dynamically Allocated Arrays(동적 할당 배열)
malloc을 이용한 동적할당 배열(동적할당의 구현은 앞에서 배운 if와 매크로 함수를 이용)   
1) 1차원 배열
```c
  int i,n,*list; // 동적할당을 위한 int형 포인터 선언
  
  scanf("%d",&n);
  MALLOC(list, n*sizeof(int)); // int형 길이가 n인 1차원 배열
```
2) 2차원 배열   
2차원 배열은 배열들의 배열이다! 1차원 배열의 집합이라고 생각하면 됨
```c
  int** make2DArray(int rows, int cols)
  { /* create a two dimensional rows x cols array */
    int **x, i;
    
    /* get memory for row pointer */
    MALLOC(x, rows * sizeof(int*)); // 포인터는 64비트 아키텍쳐에서 고정적으로 4바이트.. 일종의 포인터 배열
    
    /* get memory for each row */
    for(i=0; i<rows; i++)
      MALLOC(x[i], cols * sizeof(int)); // int 대신에 **int 써도 동일한 표기
    return x;
  }
```
3) calloc   
공간을 할당해주면서 0으로 자동으로 초기화를 진행해준다. malloc과 다른점은 인수가 2개라는 점.. 두 인수를 곱해줌
```c
  /* 매트로 함수를 통한 구현 */
  #define CALLOC(p,n,s) { \
      if(!((p) = calloc(n,sizeof(s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
      } \ 
 }
```
4) realloc   
동적할당된 공간을 다시 공간을 할당해준다.
```c
  #define REALLOC(o, p, s) { \  // o는 할당 전의 메모리 크기, p는 새로 할당을 해줄 곳, s는 크기
      if(o = p && !(!((p) = realloc(o,s))) { \ // 데이터 유실을 피하기 위해 o=p가 존재하는 거지 둘이 비슷하긴 놈들임
         p = o; \   // 공간 할당에 실패했을 경우에 데이터를 복원
         fprintf(stderr, "Insufficient memory"); \
      }
```

## 2.3 Structures(구조체)   
- record라고도 부른다
- 서로 다른 데이터 타입을 모은 일종의 collection임
- 각각의 항목의 (자료형, 이름)으로 구성
- 각 멤버에 접근할때는 dot(.)를 사용한다.
- 구조체의 대입(A=B)는 가능하지만 동등성과 같은 비교는 불가능하다.(A==B 같은건 단순하게 불가능)
```c
  /* 구조체의 정의와 변수의 멤버 접근 예시 */
  struct {
    char name[10];
    int age;
    float salary;
    } person;   // 여기서 person은 variable을 바로 붙여준 것! : typedef가 없기 때문에 자료형 이름이 아님
    
 strcpy(person.name, "James");
 person.age = 10;
 person.salary = 35000;
 
 /* typedef를 통해 이름을 사용하는 경우 */
 typedef struct {
    char name[10];
    int age;
    float salary;
    } humanbeing; // 여기서 humanbeing은 variable이 아니라 자료형을 지칭! -> 위의 내용과 구분하자!
    
 /* 구조체 안에 구조체 */
 typedef struct {
    int month;
    int day;
    int year;
    } date;
 typedef struct {
    char name[10];
    date dob;	// 이 멤버 변수에 접근하기 위해선 dot(.)를 두번 사용하면 된다.
    } humanbeing;
    
 /* 자기참조 구조체 : 구조체의 정의 안에 구조체 포인터가 정의되어 있는 것 - 연결리스트의 기반이 됨 */
 typedef struct list {
 	char data;
	struct list *link;
	}list;
```

## 2.4 Polynomials(다항식)
+ Implementation of Ordered List(순서가 있는 리스트의 구현)
  - Array(정적 배열)
    * list의 element와 index를 짝지어 놓은 것
    * sequental mapping(순차적 매핑)
    * item을 찾거나 대체하거나 배열의 길이를 찾는 과정 등등이 일정한 시간(constant time)이 든다. -> 주소계산이 쉽게되기 때문이다!
    * 삽입과 삭제에서 문제가 생길 수 있음 : item들을 move하는 과정이 필요하기 때문!
  - Linked List(동적 배열)
    * Non-sequential mapping(비순차적 매핑)
    * Chapter4의 내용을 참고!

### A Problem Requiring Ordered Lists
- Manipulation of symbolic polynomails(다항식의 조작) : (Ex) A(x) = 3x^20+5x^5+4 / B(x) = x^4+10x^3+3x^2+1
- degree : 최고차항
- assumption : 내림차순으로 중복된 차수의 항은 존재하지 않는다고 생각

### ☆ Polynomial Addition(다항식 더하기의 구현)
1. 두항을 최고차항을 비교하여 같은지를 본다.
2.1 두항이 같은 경우에 두 항의 계수를 더하고 C(x)에 옮겨준다. - 단, 합이 0이면 옮기지 않는다.
2.2 두항 중 하나가 더 클 경우 더 큰 항을 C(x)로 옮겨준다.
3. 1~2.2 과정을 반복
4. 남은 항들을 모두 C(x)로 옮겨준다.
```c
  #define MAX_DEGREE 101
  /* 다항식의 구현은 구조체를 사용 */
  
  // 구현 방법1
  typedef struct
  {
    float coef[MAX_DEGREE]
    int degree; // 최고차항의 차수
  }
```
최고차항이 너무 크면 계수=0인 항들이 너무나도 많아지게 된다. (Ex) 2x^1000+2x^2+1   
최고차항이 너무 작으면 그만큼 안쓰는 배열 공간이 너무 많아짐(정적배열을 사용하기 때문) (Ex) x^3+1
```c
  #define MAX_TERMS 100
  
  // 구현 방법2
  typedef struct
  {
    float coef;
    int expo;
  }term;

  // 하나의 배열을 사용하여 다항식 더하기를 구현
  term terms[MAX_TERMS];
  int avail = 0; // 더하기 결과값을 저장할 수 있는 시작 공간
```
<img src="https://user-images.githubusercontent.com/97028605/162855224-c1bb3d3a-8312-4e0d-8848-5d844def3d6c.PNG" weight=300px height=500px></img>

위에 대한 자세한 내용은 [DS05 1.c](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch2_Arrays_and_Structures/DS%2005/1.c) 내용을 참고

## 2.5 Sparse Matrix(희소행렬)
m\*n의 행렬에서 0의 개수가 많은(비어있는) 행렬을 희소행렬이라고 한다. 희소행렬의 표현은 <row, col, value>의 3-triple형태로 표현됨
```c
  define MAX_TERMS 101 // 최대 숫자개수보다 하나 더 공간을 마련
  typedef struct
  {
    int row;
    int col;
    int value;
  }term;
  term a[MAX_TERMS]; // 구조체 배열을 선언 -> 대부분의 행렬이 비어있기 때문에 비어있지 않은 행렬을 기록한다.
```
![IMG_0783](https://user-images.githubusercontent.com/97028605/162862160-cb30c156-1426-4c74-923e-5a454eb36986.PNG)

- 첫번째에는 행의 갯수, 열의 갯수, 값이 들어있는 항의 개수에 대한 정보를 기록함
- 행 우선으로 저장(row major ordering)

### Transpoing a Matrix(전치행렬 만들기)
__알고리즘 1__  
```
    for each row i of original matrix   
      take element <i, j, value> and store it   
      as element <j, i, value> of the transpose;
```
행과 열을 숫자를 바꿔서 row major ordering에 맞게 재정렬해준다. 하지만 element의 move가 많이 발생할 수 있기때문에 overhead가 커질 수 있음! 그래서 알고리즘2와 같은 방법을 사용해 볼 생각임

__알고리즘 2__
```
    for all elements in column j of origianl matrix
      place element <i, j, value> in
      element <j, i, value> of the transpose
```
column에 대해서 모두 scan을 해서 작은 행부터 찾아 다른 행렬에 저장을 한다. 모든 column index에 대한 탐색시간 overhead가 발생할 수 있다.   
알고리즘2에 대한 자세한 내용은 DS05 2.c 를 참고

+ Analysis of transpose
  - loop에 의해 처리시간이 결정된다.
  - 나머지는 constant time이 소모됨
  - Time complexity : O(columns\*elements) -> Sparse Matrix가 아니라 꽉 차있다면 소요시간이 column^2\*elements정도로 늘어난다.
  - 경우에 따라서는 2D array형태로 처리하는게 더 빠를 수 있음

__★ 알고리즘 3 : Fast Transpose of a sparse matrix__

<img src="https://user-images.githubusercontent.com/97028605/162870334-d7bc9002-23c3-40c7-845b-8247b9921973.PNG" weight=800px height = 600px></img>   
위와 같이 희소행렬이 전치했을때의 행렬의 행에 해당하는 index들과 그 개수들을 기록하는 배열이 존재한다!   
startingPosition은 이 전 index의 startingPosition과 index의 갯수를 지칭하는 rowTerm의 합으로 이루어진다.(탐색이 진행될 수록 기록하는 행렬을 업데이트!)   
알고리즘3에 대한 자세한 내용은 DS05 3.c 를 참고

+ Analysis of fastTranspose
  - 네 번의 loop에 의한 시간
  - loop안의 내용들에 대해서는 constant time이 소요됨
  - Time complexity : O(columns+elements) -> 이때, elements=columns\*rows라면 2D Array와 처리 시간이 같아짐
  - 하지만 element < colums\*rows라면 더 적은 시간이 소요된다.
  - fastTranspose 알고리즘은 공간과 시간을 절약하기에 매우 좋은 선택!
