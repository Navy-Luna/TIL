// 2022-03-25 ��ġƮ�� ������ ���� �������

#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]);			// ���� Ʈ�� ����
int EvaluateExpTree(BTreeNode* bt);			// ��ġ Ʈ�� ���

void ShowPrefixTypeExp(BTreeNode* bt);		// ���� ǥ��� ��� ���
void ShowInfixTypeExp(BTreeNode* bt);		// ���� ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode* bt);		// ���� ǥ��� ��� ���

#endif