# Ch3. Stacks and Queues
## 3.1 Stacks
- Linear List(=Ordered List)
- 한쪽 끝은 top이라고 한다.(제일 최근에 Input된 것)
- 다른 한쪽 끝은 bottom이라고 한다.(제일 예전에 Input된 것)
- 추가와 제거는 한쪽 끝인 top에서만 이루어짐
- 스택은 LIFO(Last-in, First-out) List

```c
  /* 정적할당 배열을 사용하여 구현한 스택 */
  #define MAX_STACK_SIZE 100
  typedef struct
  {
    int key;
  }element;
  element stack[MAX_STACK_SIZE]; // 구조체 배열을 사용(스택 역할)
  int top = -1; // 탑의 사용으로 스택이 차있는지 비어있는지를 판단한다.
```

## 3.2 Stacks Using Dynamic Arrays
정적으로 할당한 배열을 동적으로 할당한 것밖에 차이가 없음 -> 공간할당이 자유로운 것이 장점
```c
  /* 정적할당과 다른 것은 배열의 확정성 정도! */
  typedef struct
  {
    int key;
  }element;
  element *stack;
  MALLOC(stack, sizeof(*stack)); // *stack하면 element 자료형 크기로 들어간다.
  int capacity = 1; // 최대용량 -> 위와는 다르게 늘리고 줄일 수 있음
  int top = -1;
```

## 3.3 Queues
- Linear list(=Ordered List)
- 한쪽 끝은 front라고 불림(front end)
- 한쪽 끝은 rear라고 불림(rear end)
- Addition(추가)는 rear에서만 이루어진다.
- Removal(제거)는 front에서만 이루어진다.
- 큐는 FIFO(First-in, First-out) list이다.

### Representations of Queue
+ Sequential representation(1D Array를 활용)
+ Circular representation : Circular Queue(1D Array를 활용, 선형큐보다 더 효율적)

1. Sequential Representation([DS07 2.c](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch3_Stacks_and_Queues/DS%2006-07/2.c))
```c
  #define MAX_QUEUE_SIZE 100
  typedef struct
  {
    int key;
  }element;
  element queue[MAX_QUEUE_SIZE];
  int rear = -1;
  int front = -1;
```
선형큐에서 rear가 맨뒤에 도달하고 더이상 front가 일어나지 않는 상황 -> 추가로 push가 일어날 경우, 공간 확보를 위해 shift로 인한 time consuming이 발생할 수 있다.
발생할 수 있는 worst time complexity는 O(MAX_QUEUE_SIZE)

2. Circular Queue([DS07 3.c](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch3_Stacks_and_Queues/DS%2006-07/3.c))
- front는 첫번째 원소로부터 반시계방향으로 한칸 위치
- rear는 마지막 element를 가리킨다.
- 하지만 empty와 full를 구분하는 상황에서 문제가 발생할 수 있다.
  + (b) : 4번의 addition -> Queue full, front==rear
  + (c) : 3번의 deletion -> Queue empty, front==rear
 
<img src="https://user-images.githubusercontent.com/97028605/162914576-762abe79-3ae3-45cf-ab11-ff1e550625a7.PNG" weight=500px height=300px></img>   
그래서 Rear다음에 Front가 위치했을 때, 큐의 전체크기를 늘려주자!(동적할당을 이용)
__________________________________________________________________________________
# Additional Study
## strtok, sscanf, strcmp
```c
int main()
{
	char input[80];
	char* delimiter = " \n";  // 자르는 기준을 여러개 넣을 수 있음! 여기서는 공백과 줄바꿈
	char* op = NULL;
	element student;

	while (1)
	{
		gets(input);
		op = strtok(input, delimiter);

		if (!strcmp(op, "push"))
		{
			sscanf(input + strlen(op) + 1, "%d%s", &student.id, student.name);
			push(student);
		}

	 }

	return 0;
}
```
 + strtok
   - strtok는 문자열 자르기 함수(<string.h> include필요) 첫번째 문자열을 두번재의 것들을 기준으로 자른다
   - strtok는 뒤의 기준문자열을 만나면 해당 부분을 \0로 만들고 다음으로 넘어간다.
   - 이전 문자열을 똑같이 자르고 싶으면 strtok(NULL, delimiter)를 사용
 + strcmp
   - strcmp는 두 문자열이 같을때는 0을 반환하며 대소문자를 구분한다.
   - 대소문자를 구분하지 않으러면 stricmp를 대신 사용한다.
 + sscanf
   - 맨앞의 \*str에 해당하는 문자열을 지정된 형식으로 읽어 변수에 저장하는데 사용하는 함수
   - \0가 포함되어 잘리면 저렇게 +를 이용하면 되는듯?


# Reference
- Horowitz, Shani, & Anderson-Freed, ªFundamentals of data structures in Cª, (2nd edition) Silicon-press
- \[c/c++\] strtok 함수(문자열 자르기에 대해서) https://blockdmask.tistory.com/382
- \[c/c++\] c언어 공백문자 포함한 문자열을 입력하는 법 https://omyodevelop.tistory.com/120
