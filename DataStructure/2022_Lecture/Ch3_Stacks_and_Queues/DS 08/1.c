/*
	2022.04.12 : Mazing Problem
	�����迭�� �̿��� �̷�Ž�� ���α׷��� �ۼ��غ���
*/
#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	short int row;
	short int col;
	short int dir;

}element;

typedef struct
{
	short int vert;
	short int horiz;
}offsets;


offsets move[8] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
element stack[MAX_STACK_SIZE];
int top = -1;


int maze[10][10], mark[10][10]; // �̷ο� ��ũ
int EXIT_ROW, EXIT_COL; // Ż�� ��ǥ

void push(element a);
element pop();
void path(void);

int main()
{
	FILE* fp = fopen("input2.txt", "r");


	// mark �ʱ�ȭ
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			mark[i][j] = 0;

	// m*p ������ �ޱ� = �ⱸ ��ġ
	fscanf(fp, "%d %d", &EXIT_ROW, &EXIT_COL);

	// maze �ʱ�ȭ
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maze[i][j] = 1;

	// ���Ϸ� ���� �Է¹��� �κи� �ٲ�
	for (int i = 1; i <= EXIT_ROW; i++)
		for (int j = 1; j <= EXIT_COL; j++)
			fscanf(fp, "%d", &maze[i][j]);

	// ��� ã��
	path();

	return 0;
}

void path(void)
{
	int row, col, dir, found = FALSE;
	int nextRow, nextCol;
	element position;
	mark[1][1] = 1;
	top = 0;

	/* �ʹݿ� ���ÿ� �־�α� */
	stack[0].col = 1; stack[0].row = 1; stack[0].dir = 1;

	while (!found && top > -1)
	{
		/* ó�� pop �� ��Ʈ��ŷ�� ���� pop */
		position = pop();
		/* ���� ��ġ�� ���� */
		row = position.row; col = position.col;
		dir = position.dir;

		while (dir < 8 && !found)
		{	/* move in direction dir */
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			/* ���� ���⿡ EXIT ��ġ�� ������ ���� */
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
				found = TRUE;
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
			{
				mark[nextRow][nextCol] = 1;
				position.row = row; position.col = col;
				position.dir = dir + 1;
				
				push(position);

				row = nextRow;
				col = nextCol;
				dir = 0;
			}
			else ++dir;
		}
	}

	if (found)
	{
		printf("The path is:\n");
		printf("row   col\n");
		for (int i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else
		printf("The maze does not have a path\n");

	
}

void push(element a)
{
	if (top >= MAX_STACK_SIZE - 1)
	{
		printf("Stack is full!");
		exit(EXIT_FAILURE);
	}

	stack[++top] = a;
	return;
}

element pop()
{
	if (top == -1)
	{
		printf("Stack is empty!");
		exit(EXIT_FAILURE);
	}

	return stack[top--];
}