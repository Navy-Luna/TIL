# Queue(큐)
## 1. Queue란?
- 큐는 먼저 들어간 데이터가 먼저 나오는 방식임(Ex. 양쪽이 뚫려있는 관, 놀이공원 줄 등)
- 선입선출 방식 혹은 FIFO(First-in, First out)방식이라고도 불림
- 데이터의 위치에 따라 Front(제일 먼저 들어온 데이터), Rear(제일 나중에 들어온 데이터)가 존재한다.
- Enqueue(인큐 : 데이터를 새로 넣음.. 넣은 데이터는 Rear), Dequeue(디큐 : 데이터를 빼냄)과 같은 기능들이 있음
- 큐는 운영체제 및 네트워크 관련 소프트웨어 구현에 중요한 역할을 함 그리고 수학적으로 모델링 된 결과 확인을 위해 특정 상황을 시뮬레이션하는데 사용

<img src = "https://user-images.githubusercontent.com/97028605/155949166-dc3a09fd-8c8f-456f-98ed-d714269129a2.png" width=700px height=300px></img>

## 2. Queue의 구현
_큐(Queue)의 구현에는 앞에서 공부했던 Stack처럼 배열을 통한 구현과 연결리스트를 이용한 구현이 가능_
### 2.1. 배열을 이용한 구현(원형 큐: Circular Queue)
- 그림1처럼 Dequeue가 발생하면 front에 위치한 배열 원소를 빼내고 한칸씩 모두 앞으로 당기는 방법이 있음 -> 메모리 이동에 따른 overhead 발생
- 그림2와 같이 하나씩 움직이게 하지 않고 front가 가리키는 위치만 바꾸게 하면 배열 원소들을 이동시키는데 생기는 overhead를 줄일 수 있음
- 하지만 그림2도 좋은 방법이 아닌 것이 그림3처럼 Rear가 배열 끝에 위치할 경우 Front가 더 이상 움직이지 못함!
- 그림3의 위의 그림의 문제를 해결하기 위해 아래 그림처럼 다시 앞으로 보내는 방법이 있음 그게 바로 그림4의 원형큐(Circular Queue)
- 원형큐에 데이터가 들어가면 F(Front)와 R(Rear)가 같은 곳을 가리킴. 인큐 발생시 Rear가 시계방향으로 이동 후, 데이터 넣음 그리고 디큐 발생시 디큐에 위치한 데이터 삭제 후, 시계 방향 이동
- 그림4의 두번째(꽉 찬 상태)와 세번째(비어있는 상태)가 F와 R만으로 구분이 되질 않음.. 그래서 그림5처럼 "한 칸을 비워두고" 시작하는 방법을 이용(한 칸 메모리 낭비되더라도 이게 효율적)

<img src = "https://user-images.githubusercontent.com/97028605/155953597-e896f48f-c0e2-454e-8296-c430904c96cf.PNG" width=800px height=500px></img>

원형 큐가 텅빈 상태 : F와 R이 동일한 위치를 가리킨다 / 원형 큐가 꽉 찬 상태 : R이 가리키는 위치의 앞을 F가 가리킨다 -> 이 규칙을 기반으로 원형 큐를 구현
> [구현해 본 코드] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/CircularQueue.h) / [Source code](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/CircularQueue.c)
> / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/CircularQueueMain.c)

### 2.2. 연결리스트를 이용한 구현

스택은 push와 pop이 같은 위치에서 발생하지만 큐의 Dequeue와 Enqueue는 서로 다른 위치에서 발생한다. Front를 head 그리고 Rear를 tail로 하여 연결리스트를 구현하는 것과 같다.
Dequeue가 발생하면 header에 있던 노드가 제거되고 Enqueue가 발생하면 tail에 새로운 노드가 생기는 것을 기억하고 코드를 구현해야한다.

> [구현해 본 코드] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/ListBaseQueue.h) / [Source code](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/ListBaseQueue.c) / 
[Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/ListBaseQueueMain.c)

-------------------------------------
## 3. 덱(Deque)의 이해와 구현
덱과 큐의 차이점을 통해 이해해보자면 큐는 뒤로 추가되고 앞으로 나오는 선입선출 방식이지만 덱의 경우 앞으로도 뒤로도 추가될 수 있고 앞으로도 뒤로도 뺄 수 있는 자료구조이다. 그래서 덱(Deque)이라는 이름은 
double-ended queue의 줄임말을 이해할 수 있다. 즉, 스택(Stack)+큐(Queue)=덱(Deque)

<img src = "https://user-images.githubusercontent.com/97028605/155963419-b34b1f5d-7d0d-45ea-acde-ef201c37ca08.png" width=900px height=300px></img>

여기서 덱의 구현은 배열이나 연결리스트를 통해 구현할 수 있지만 양방향으로 추가와 제거가 가능하다는 점에서 "양방향 연결리스트"를 이용하여 구현해보고자 한다.(구현 기능 : 앞/뒤로 넣기, 앞/뒤로 빼기)
> [구현해 본 코드] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/Deque.h) / [Source code](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/Deque.c) / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/DequeMain.c)

추가로, 덱은 스택과 큐가 가진 기능을 모두 갖추고 있기 때문에 덱을 이용하여 큐를 구현할 수도 있다.
> [구현해 본 코드] [header file](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/DequeBaseQueue.h) / [Source code](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/DequeBaseQueue.c)
>  / [Main](https://github.com/Yn-Jy/TIL/blob/main/DataStructure/Queue/DequeBaseQueqeMain.c)
