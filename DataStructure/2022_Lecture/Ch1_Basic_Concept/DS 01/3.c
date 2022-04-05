/*
	Chap1_Basic_Concept : C Programming Basic
	1���� �迭�� �μ��� ������ ������ Ÿ���� �Լ��� ����غ���
*/

#include <stdio.h>

int sumAry1D_f1(int ary[], int size); // �迭�� �Ķ����, ũ��
int sumAry1D_f2(int* ary, int size);  // �迭�� ������, ũ��
int sumAry1D_f3(int ary[6], int size); // �迭 ũ�� �� ������, ũ��

int main()
{
	int ary1D[] = { 1,2,3,4,5,6 };

	// �� �Լ� ��� ary�� int* ���·� �Լ����ڸ� �޴´�.
	printf("f1: %d\n", sumAry1D_f1(ary1D, 6));
	printf("f2: %d\n", sumAry1D_f2(ary1D, 6));
	printf("f3: %d\n", sumAry1D_f3(ary1D, 6));
}

int sumAry1D_f1(int ary[], int size) // �迭�� �Ķ����, ũ��
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ary[i];

	return sum;
}

int sumAry1D_f2(int* ary, int size)  // �迭�� ������, ũ��
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ary[i];

	return sum;
}

int sumAry1D_f3(int ary[6], int size) // �迭 ũ�� �� ������, ũ��
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += ary[i];

	return sum;
}