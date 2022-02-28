/*	@ 윤성우의 열혈 자료구조(윤성우 저) 참고
	2022-02-28 Monday
	배열 기반 구현 : 원형 큐를 구현하기 위한 헤더 파일
*/

#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE	1
#define FALSE	0

#define QUE_LEN	100 // 큐의 길이
typedef int Data;

typedef struct _cQueue
{
	int front;		// 제일 앞의 데이터 인덱스
	int rear;		// 제일 뒤의 데이터 인덱스
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);	// 큐 초기화
int QIsEmpty(Queue* pq);	// 큐 비어있는지 확인

void Enqueue(Queue* pq, Data data);	// 데이터 넣기
Data Dequeue(Queue* pq); // 데이터 출력
Data QPeek(Queue* pq); // 데이터 확인(먼저 넣은 것)

#endif