/*
	Chap1_Basic_Concept : C Programming Basic
	2���� �迭�� �μ��� ������ ������ Ÿ���� �Լ��� ����غ���
*/

#include <stdio.h>

int sumAry2D_f1(int ary[][3], int row, int col); // �迭�� �Ķ����, ũ��
int sumAry2D_f2(int(*ary)[3], int row, int col); // �迭�� ������, ��, ��
int sumAry2D_f3(int ary[2][3], int row, int col); // �迭�� ũ�Ⱑ ������ �Ķ����, ��, ��

int main()
{
	int ary2D[][3] = {{1,2,3},{4, 5, 6}};

	// ������ �Լ����� ��� ary�� int[3]* �� �Լ����ڸ� ����Ѵ�.
	printf("f1: %d\n", sumAry2D_f1(ary2D, 2,3));
	printf("f2: %d\n", sumAry2D_f2(ary2D, 2,3));
	printf("f3: %d\n", sumAry2D_f3(ary2D, 2,3));
}

int sumAry2D_f1(int ary[][3], int row, int col) // �迭�� �Ķ����, ��, ��
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += ary[i][j];

	return sum;
}

int sumAry2D_f2(int (*ary)[3], int row, int col) // �迭�� ������, ��, ��
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += ary[i][j];

	return sum;
}

int sumAry2D_f3(int ary[2][3], int row, int col) // �迭�� ũ�Ⱑ ������ �Ķ����, ��, ��
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += ary[i][j];

	return sum;
}
