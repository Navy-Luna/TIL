/*
	2022-03-09
	���� Ʈ�������� ���� ��� ����
*/
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode // ���� Ʈ���� ��带 ǥ���� ����ü
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;

}BTreeNode;

BTreeNode* MakeBTreeNode(void); // ����� ����
BTData GetData(BTreeNode* bt);	// ����� �����͸� ��ȯ
void setData(BTreeNode* bt, BTData data); // ��忡 �����͸� ����

BTreeNode* GetLeftSubTree(BTreeNode* bt); // ���� ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode* GetRightSubTree(BTreeNode* bt); // ������ ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // ���� ���� Ʈ���� �����Ѵ�.
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // ������ ���� Ʈ���� �����Ѵ�.

#endif