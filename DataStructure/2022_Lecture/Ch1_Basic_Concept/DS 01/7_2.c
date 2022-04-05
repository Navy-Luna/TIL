/*
	Chap1_Basic_Concept : C Programming Basic

	������ ���� ���α׷��� �ΰ��� �������� �ۼ��ϱ�
	1) ����ڷκ��� �������� ����(n)�� �Է¹޴´�.
	2) ���� ������ n�� �߻����� 1���� �迭�� �����Ѵ�.
	3) 1���� �迭�� ���� "��������(selection sort)"�� �����Ѵ�.
	4) ����ڷκ��� ������ ������ �Է¹޴´�
	5) �Է¹��� ������ �迭�� �ִ��� ����Ž��(binary Search)�� �����Ͽ� �� ����� ����Ѵ�.
*/

////////////////////////////////////
// ��ũ�� �Լ��� �̿��� compare�� swap ����
////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )
#define COMPARE(x,y) ( ((x)>(y)) ? 1 : ((x)=(y)) ? 0 : -1)

#include <stdio.h>
#include <stdlib.h>


void sort(int list[], int n);
int search(int list[], int searchnum, int start, int last);

int main()
{
	int ary[100];

	int searchnum;
	int n; // �Է¹��� ���� ����

	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) // 0~999������ ���ڸ� �޴´�.
		ary[i] = rand() % 1000;

	for (int i = 0; i < n; i++) // ������ �迭 ���
		printf("%d ", ary[i]);
	printf("\n\n");

	sort(ary, n); // ���� ����

	printf("Sorted array:\n"); // ���ĵ� �迭 ���
	for (int i = 0; i < n; i++)
		printf("%d ", ary[i]);
	printf("\n");

	printf("\nEnter the number to search : ");
	scanf("%d", &searchnum); // ã�� ���� �Է�

	if (search(ary, searchnum, 0, n - 1) != -1)
		printf("The search number is present in ary[%d]", search(ary, searchnum, 0, n - 1));
	else
		printf("The search number is not present");

	return 0;
}

void sort(int list[], int n) // ��������( �迭�� �迭�� ���� ���� )
{
	int min, temp;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list[min] > list[j])
				min = j;
		}
		SWAP(list[min], list[i], temp); // �ּڰ� �ִ°� ��������..! ��ũ�� �Լ��� �׳� �ٲ�!!!!!!!!!!!!
	}
}



int search(int list[], int searchnum, int start, int last) // ���� Ž��
{

	while (start <= last)
	{
		int mid = (start + last) / 2;
		switch (COMPARE(searchnum, list[mid]))
		{
		case 0:
			return mid;
		case 1:
			start = mid + 1;
			break;
		case -1:
			last = mid - 1;
			break;
		}
	}
	return -1;
}