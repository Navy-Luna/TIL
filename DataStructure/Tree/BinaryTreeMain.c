/*
	2022-03-09
	구현한 이진 트리가 작동하는지 확인하는 main
*/


#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	printf("%d \n",
		GetData(GetLeftSubTree(bt1)));
	printf("%d \n",
		GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	return 0;
}