# Ch3. Stacks and Queues
## 3.1 Stacks(스택)
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

## 3.2 Stacks Using Dynamic Arrays(동적 배열을 이용한 스택)
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

## 3.3 Queues & 3.4 Circular Queues(선형 큐와 환형 큐)
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

## 3.5 Mazing Problem(미로 문제)
입구에 위치한 쥐가 출구의 치즈를 찾기위해 길을 찾는 것처럼 미로 찾기를 실현하기 위한 알고리즘 -> 우리가 배운 Stack을 활용할 수 있다.
- Representation of a maze
  - A two-dimensional array, maze(2차원 array로 이루어진 미로)
  - 0 : 열려있는 길, 1 : 벽
- Assumption
  - Rat은 왼쪽 위에서 출발하고 오른쪽 아래에 출구가 있음
  - 아래 그림에는 나와있지 않지만 주변에 1로 둘러싸여 있음   
 <img src="https://user-images.githubusercontent.com/97028605/162968769-4a7d8e51-2c2d-4af3-93fe-1fbfd08acb9d.PNG" weight=400px height=250px></img>
- 쥐는 특정 위치에서 8가지 방향으로 상하좌우/대각선으로 움직일 수 있다.(그러기 위해서 미로 주변을 1로 둘러쌈! -> m\*p미로를 위해 (m+2)\*(p+2)미로를 만들면 된다.
- 미리 움직일 수 있는 방향에 대해 구조체 형태로 저장해둔다. 
```c
  typedef struct
  {
    short int vert; // 위쪽으론 -1, 아래쪽으로 1, 그대로 0
    short int horiz; // 왼쪽으로 -1, 오른쪽으로 1, 그대로 0
  }offsets;
  /* array of moves for each direction */
  offsets move[8]; // 북쪽을 0으로 해서 시계방향으로..
```
- 우리는 어느 choice가 best일지는 모르기 때문에 우리는 현재의 위치와 가능한 move들을 저장해둘 것임(나중에 갔다가 막혔을 때, 돌아올 수 있게!)
- 방문했던 지역에 대해서 표시하는 mark를 이용한다. maze\[row\]\[col]를 방문하면 mark\[row\]\[col]에 1을 표시해둠
```
   현 위치 (r,c)에서 탐색방향<8 이고 경로가 발견되지 않은 한 다음을 반복한다.
     현 위치 (r,c)에서 계산한 다음 위치 (nR, nC)에 대해
       (1) if 출구인 경우
         경로 발견! 종료!
       (2) else if 이동가능하고(해당 위치에서의 maze가 0) 이전에 방문하지 않은 경우(mark가 0)
         push(백트래킹 후 탐색할 위치와 방향) // push(r,c,d++)
	 다음위치 방문했음을 표시
	 다음위치로 이동
       (3) else
         탐색방향 증가 // d++
```
- 방문했던 지역에 대한 정보들 (row,col,next direction)에 대한 것을 stack에 저장한다.
```
  typedef struct
  {
    short int row;
    short int col;
    short int dir;  // next direction이 저장됨
  }element;
```
- 모든 지역을 방문했다고 했을때..(m\*p maze) worst case에 의한 time complexity는 O(mp)
- 최종적인 maze에 대한 구현은 DS08을 참고
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
