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