# Ch4. Linkded Lists
## 4.1 Singly Linked Lists and Chains
- Ordered List
  + Sequential Representation(Array)
    1. Sequential storage scheme
    2. Successive items of a list are located fixed distance apart(아이템이 연속적으로 특정 거리에 위치함)
    3. The order of elements is the same as in the ordered List(element의 순서가 ordered list와 동일함)
    4. Insertion and deletion of arbitrary elements become expensive(삭제와 삽입에 많은 data move를 요구함)
  + Linked Representation(Linked List) = Non-Sequential
    1. Successive item of list may be placed anywhere in memory(메모리 상에서 리스트가 임의의 위치에 저장됨)
    2. The order of elements is not the same as in the ordered List(element의 순서가 ordered list와 동일하지 않음)
    3. A Linked list is comprised of nodes(리스트는 데이터와 링크 field로 구성된 노드로 이루어짐)
    4. Insertion and deletion become easier(데이터의 움직임이 크게 없이 삭제와 삽입이 가능)

## 4.2 Representing Chains(Single Linked List) in C
__Defining a Node's Structure__
```c
  /* self-referential structure 사용 */
  typedef struct listNode *listPointer; // 아직 정의가 나오지 않았지만 컴파일러가 특정 type에대한 포인터는 미리 재정의 해줌
  typedef struct listNode
  {
    char data[4];
    listPointer link; // 다음 node로 가기위한 link
  }listNode;
```
__List Insertion__
```c
  /* insert a new node with data */
  void insert(listPointer *first, listPointer x)
  listPointer temp;
  MALLOC(temp, sizeof(*temp)); // 새로운 공간을 마련.. size 조절 주의
  temp->data = 50;
  if(*first) // 빈 리스트가 아닐 경우
  {
    temp->link = x->link; // x 다음에 삽입
    x->link = temp;
  }
  else // 빈 리스트
  {
    temp->link = NULL;
    *first = temp;
  }
```
__List Deletion__
```c
  void delete(listPointer *first, listPointer trail, listPointer x)
  { /* delete x from the list, trail is the preceding node */
    if(trail)
      trail->link = x->link;
    else
      *first = (*first)->link;
    free(x); // x에 해당하는 node를 삭제한다.
  }
```

## 4.3 Linked Stacks And Queues
스택과 큐를 리스트로 구현한다. 스택 앞에서 학습한 노드 Pointer에 대한 배열과 각 배열마다 리스트가 딸려있는 느낌으로 구현(그림 참고)
```c
  #define MAX_STACKS 10
  /* 리스트의 노드에 data역할을 할 구조체 정의 */
  typedef struct
  {
    int key
    /* otehr field */
  }element;
  
  typedef struct stack *stackPointer;
  typedef struct
  {
    element data;
    stackPointer link;
  }node;
  /* 스택포인터의 배열을 선언 : 단일 리스트로도 스택이 구현되는데 여러개하려고 배열 선언하는 느낌 */
  /* top 배열 원소에 대해 NULL로 초기화 필요 */
  stackPointer top[MAX_STACKS];

```
```c
  #define MAX_QUEUES 10
  /* 위의 element에 대한 정의는 그대로.. 단, 스택과는 다르게 2개의 리스트를 사용 */
  typedef struct queue *queuePointer;
  typedef struct queue
  {
    element data;
    queuePointer link;
  }
  /* front와 rear배열에 대해 NULL로 초기화 필요 */
  queuePointer front[MAX_QUEUES], rear[MAX_QUEUES];
```

<img src="https://user-images.githubusercontent.com/97028605/163159728-5cdf8fbf-4cfe-4eb1-a6af-f8030019e716.PNG" width="500px" height="400px"></img>
<img src="https://user-images.githubusercontent.com/97028605/163160684-fb450f67-9826-4087-8c4c-d0ead45e143b.PNG" width="500px" height="400px"></img>

## 4.4 Polynomials
앞에서 배운 정적/동적 배열을 사용한 polynomial을 연결리스트로 구현   
a와 b에 두개의 polynomial을 만들고 최고차항을 앞에서부터 비교..(배열과 방식은 유사) c에 attach함수를 사용하여 새로 만든 다항식을 붙여나감
```c
  typedef struct polyNode *polyPointer;
  typedef struct polyNode
  {
    int coef;  // 계수
    int expon; // 차수
    polyPointer link;
  }polyNode;
  polyPointer a,b;
```
다항식 list를 구현한 코드는 [DS 11](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch4_Linked_Lists/DS%2011/1.c)를 참고(padd & attach 함수에 주목)

- Analysis of padd
  1. 계수 더하기   
    다항식 A와 B의 항의 개수가 각각 m과 n개라고 할때, 더하기 횟수는 0<=number of coefficient addition <= min(m,n)
  2. 차수 비교   
    while loop가 돌때마다 한번의 comparsion이 발생함! 서로 차수가 모두 다를 경우에 worst하게 m+n번 일어날 수 있다.
  3. c에 새로운 노드 생성
    A와 B의 다항식의 차수가 모두 달라서 worst하게 m+n번 삽입이 발생할 수 있음
  4. 결론
    O(min(m,n)) + O(m+n) + O(m+n) = O(m+n) : time complexity of padd is O(m+n)

### ★ Circular List Representation of Polynomials
- __Chain__   
마지막 노드의 link값이 null인 singly linked list형태
- __Circular list__   
마지막 노드의 link값이 제일 처음 노드인 first node를 가리키는 형태의 list
- __Available space list(Node Pool)__   
  + free를 시키지 않고 자유로운 상태의 노드들을 엮어둔 것.. 그냥 안쓰는거 주렁주렁 매달아둔 줄 같은 것으로 생각!
  + getNode(asl(=노드풀)의 노드를 주거나 비었으면 새로만듬)와 retNode(안쓰는 노드를 노드풀에 반환)
  + 이게 있으면 circular list를 삭제하는 효율적인 algorithm 구현이 가능함

Circular List를 이용한 polynomial addition 구현 코드는 [DS12](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/2022_Lecture/Ch4_Linked_Lists/DS%2012/1.c)를 참고!

## 4.5 Additional List Operation
### 4.5.1 Operation For Chains
1. invert함수(기존의 chain을 거꾸로한 chain을 만들어낸다.)
```c
  listPointer invert(listPointer lead) // lead는 제일 앞
  { /* invert the list pointed to by lead */
    listPointer afterhead, trail; // afterhead는 invert후의 head, trail은 그 다음
    afterhead = NULL;
    while(lead)
    { /* lead가 끝에 도달할때까지 반복 */
      trail = afterhead;
      afterhead = lead;
      lead = lead->link;
      afterhead->link = trail;
    }
    return afterhead;
    
  }
```
2. concatenate(두 개의 chain을 연결한다.)
```c
  listPointer concatenate(listPointer ptr1, listPointer ptr2)
  {
    /* 이렇게 대체할만한 애를 하나 만들어두는 것이 좋음 */
    listPointer temp;
    /* empty list인지 check */
    if(!ptr1) return ptr2;
    if(!ptr2) return ptr1;
    
    /* list의 끝에 도달하기 */
    for(temp=ptr1; temp->link; temp = temp->link);
    
    /* ptr1과 ptr2를 연결하기 */
    temp->link = ptr2;
    return ptr1;
  }
```
### 4.5.2 Operations For Circularly Linked Lists
1. insertFront(circular List의 맨 앞에 노드 추가하기)
```c
  void insertFront(listPointer *last, listPointer node)
  { /* last는 리스트 마지막을 가리킴 / node는 새로 추가한 것 */
    if(!(*last)) // 비어있는 경우
    {
      *last = node;
      node->link = node;
    }
    else
    {
      node->link = (*last)->link;
      (*last)->lin = node;
      // 만약 마지막에 추가하고 싶으면 *last = node;로 업데이트 필요!
      // header만 있는 경우에도 if문으로 따로 빼서 last에 대한 업데이트가 필요하다!(DS12 참고)
    }
  }
```
2. length(list길이 반환)
```c
  int length(listPointer last)
  {
    listPointer temp;
    int count = 0;
    if(last)
    {
      temp = last;
      do
      {
        count++;
        temp = temp->link;
      }while(temp!=last);
    } // 헤더가 있는 리스트의 경우 포함여부에 따라 길이 달라짐
    
    return count;
  }
```

## 4.8 Doubly Linked Lists
- Chain 그리고 Singly linked circular List의 한계를 극복하기위해 나타난 양방향 연결리스트(Doubly linked Lists)
  + 특정 노드를 찾아내기 위해서는 처음(first)부터 시작해서 찾아나가야한다.
  + 노드를 삭제하기위해서 바로 직전 노드를 알아야한다.
  + 양방향 리스트는 이러한 한계점을 어느정도 극복하게 해준다!

```c
  typedef struct node *nodePointer;
  typedef struct node
  {
    nodePointer llink; // 왼쪽 link
    element data;
    nodePointer rlink; // 오른쪽 link
  }node;
```
만약 헤더파일이 있는 양방향 연결리스트의 경우, 아래 그림처럼 rlink와 llink가 스스로를 가리키도록 설정해줘야한다.

<img src="https://user-images.githubusercontent.com/97028605/163177381-e3142a3c-4f6a-4689-b29a-a5709aa9c3ae.PNG" width="700px" height="550px"></img>

1. 양방향 연결리스트의 삽입
```c
  void dinsert(nodePointer node, nodePointer newnode)
  { /* insert newnode to the right of node : node 오른쪽에 newNode 위치시키기 */
    newnode->llink = node;
    newnode->rlink = node->rlink;
    
    // 기존 노드에 대해서도 link를 수정
    node->rlink->llink = newnode;
    node->rlink = newnode;
  }
```
2. 양방향 연결리스트의 삭제
```c
  void ddelete(nodePointer node, nodePointer deleted)
  { /* delete from the doubly linked list */
    if (node == deleted)
      printf("Deletion of header node not permitted.\n");
    else
    {
      deleted->llink->rlink = deleted->rlink;
      deleted->rlink->llink = deleted->llink;
      free(deleted);
    }
  }
```
---------------------------------------------------------------------------
# Reference
- Horowitz, Shani, & Anderson-Freed, ªFundamentals of data structures in Cª, (2nd edition) Silicon-press
