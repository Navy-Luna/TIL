/*
	2022.04.12 : Mazing Problem
	정적배열을 이용한 미로탐색 프로그램을 작성해보자
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


int maze[10][10], mark[10][10]; // 미로와 마크
int EXIT_ROW, EXIT_COL; // 탈출 좌표

void push(element a);
element pop();
void path(void);

int main()
{
	FILE* fp = fopen("input2.txt", "r");


	// mark 초기화
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			mark[i][j] = 0;

	// m*p 사이즈 받기 = 출구 위치
	fscanf(fp, "%d %d", &EXIT_ROW, &EXIT_COL);

	// maze 초기화
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maze[i][j] = 1;

	// 파일로 부터 입력받은 부분만 바꿈
	for (int i = 1; i <= EXIT_ROW; i++)
		for (int j = 1; j <= EXIT_COL; j++)
			fscanf(fp, "%d", &maze[i][j]);

	// 경로 찾기
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

	/* 초반에 스택에 넣어두기 */
	stack[0].col = 1; stack[0].row = 1; stack[0].dir = 1;

	while (!found && top > -1)
	{
		/* 처음 pop 및 백트래킹을 위한 pop */
		position = pop();
		/* 현재 위치를 저장 */
		row = position.row; col = position.col;
		dir = position.dir;

		while (dir < 8 && !found)
		{	/* move in direction dir */
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			/* 다음 방향에 EXIT 위치해 있으면 종료 */
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