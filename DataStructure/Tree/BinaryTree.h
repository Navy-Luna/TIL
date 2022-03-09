/*
	2022-03-09
	이진 트리구현을 위한 헤더 파일
*/
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode // 이진 트리의 노드를 표현한 구조체
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;

}BTreeNode;

BTreeNode* MakeBTreeNode(void); // 노드의 생성
BTData GetData(BTreeNode* bt);	// 노드의 데이터를 반환
void setData(BTreeNode* bt, BTData data); // 노드에 데이터를 저장

BTreeNode* GetLeftSubTree(BTreeNode* bt); // 왼쪽 서브 트리의 주소 값을 반환한다.
BTreeNode* GetRightSubTree(BTreeNode* bt); // 오른쪽 서브 트리의 주소 값을 반환한다.

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // 왼쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // 오른쪽 서브 트리를 연결한다.

#endif