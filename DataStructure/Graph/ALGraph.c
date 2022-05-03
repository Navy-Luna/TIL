// 2022.05.03 YJY : Graph 기본
// 무방향 그래프를 연결리스트를 기반으로 구현

#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph* pg, int nv)
{
	int i;
	
	// 정점의 수에 해당하는 길이의 "리스트 배열"을 생선한다.
	pg->adjList = (List*)malloc(sizeof(List) * nv);		// 간선 정보를 저장할 리스트
	pg->numV = nv;	  // 정점의 수
	pg->numE = 0;     // 초기의 간선 수는 0개

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

// 그래프 리소스의 해제
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);		// 동적으로 할당된 연결리스트의 소멸
}

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	// 정점 fromV의 연결 리스트에 정점 toV에 정보를 추가
	LInsert(&(pg->adjList[fromV]), toV);
	// 정점 toV의 연결 리스트에 정점 fromV에 정보를 추가
	LInsert(&(pg->adjList[toV]), fromV);

	// 양방향 그래프이므로 간선을 하나 추가
	pg->numE += 1;
}

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

		// 각 리스트 배열의 원소에 접근하여 리스트를 출력
		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}
