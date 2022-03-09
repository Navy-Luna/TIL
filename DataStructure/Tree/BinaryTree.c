/*
	2022-03-09
	이진 트리구현을 위한 소스 코드
*/

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void) // 트리 노드 초기화
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode* bt) // 데이터 가져오기
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) // 데이터 설정
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) // 왼쪽 주솟값 반환
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) // 오른쪽 주솟값 반환
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}
