// Selection Sort(��������) ������ ���� �ҽ� �ڵ�
/*
  i. �迭�� ���� �� �ּڰ��� ã�� �� �տ� ���д�.   
  ii. �ι�° ���Ҹ� �������� ���� �迭 ��ҵ�� ũ�⸦ ���Ѵ�. ���� �ι�° �迭 ��Һ��� ���� ���� ������ switch   
  iii. ������ �Ǵ� ��ġ�� n-1�� ���������� ����..
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 101
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )

void sort(int list[], int n); // Selection_Sort

int main(void)
{
	int i, n;
	int list[MAX_SIZE];
	
	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);

	if (n<1 || n > MAX_SIZE) // �ƹ��͵� �Է�X Ȥ�� �ִ� �Է°����� ������
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 1000; // �����Լ� rand()�� ǥ������ 0~32767
	}

	sort(list, n);
	printf("Sorted Array : \n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

void sort(int list[], int n) // Selection_Sort
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;		// �ε����� Ȱ��
		for (j = i + 1; j < n; j++)
			if (list[min] > list[j]) // ���ĵ��� ���� �迭 �߿� ���� ���� ���� ã�Ƴ���.
				min = j;
		SWAP(list[min], list[i], temp); // ���ĵ��� ���� �迭�� ���� ó���� �� ���� ���� �������� �ٲ�
	}
}