// 2022-03-25 수치트리 구현을 위한 헤더파일

#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]);			// 수차 트리 구성
int EvaluateExpTree(BTreeNode* bt);			// 수치 트리 계산

void ShowPrefixTypeExp(BTreeNode* bt);		// 전위 표기법 기반 출력
void ShowInfixTypeExp(BTreeNode* bt);		// 중위 표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode* bt);		// 후위 표기법 기반 출력

#endif