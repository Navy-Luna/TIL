/*
	Chap1_Basic_Concept : C Programming Basic
	3���� �迭�� �μ��� ������ ������ Ÿ���� �Լ��� ����غ���
*/

#include <stdio.h>



int main()
{
	int ary3D[][2][3] = { { {1,2,3},{4, 5, 6} },{{7,8,9},{10,11,12}} };

	// ������ �Լ����� ��� ary�� int[3]* �� �Լ����ڸ� ����Ѵ�.
	printf("f1: %d\n", sumAry3D_f1(ary3D,2, 2, 3));
	printf("f2: %d\n", sumAry3D_f2(ary3D,2, 2, 3));
	printf("f3: %d\n", sumAry3D_f3(ary3D,2, 2, 3));
}

int sumAry3D_f1(int ary[][2][3],int sec, int row, int col) // �迭�� �Ķ����, ĭ?, ��, ��
{
	int sum = 0;

	for (int i = 0; i < sec; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				sum += ary[i][j][k];


	return sum;
}

int sumAry3D_f2(int(*ary)[2][3],int sec,int row, int col) // �迭�� ������, ��, ��
{
	int sum = 0;

	for (int i = 0; i < sec; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				sum += ary[i][j][k];
	
	return sum;
}

int sumAry3D_f3(int ary[2][2][3],int sec, int row, int col) // �迭�� ũ�Ⱑ ������ �Ķ����, ��, ��
{
	int sum = 0;

	for (int i = 0; i < sec; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				sum += ary[i][j][k];

	return sum;
}
