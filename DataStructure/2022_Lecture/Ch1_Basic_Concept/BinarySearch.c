// Binary Search ������ ���� �ڵ�
/*
  i. �迭�� ó���� ���� first, last �׸��� middle = (first+last)/2�� ����   
  ii. ã������ ���ڿ� list[middle]�� ����ũ�⸦ ��   
  iii. ���� searchnum == list[middle]�̸� ����, searchnum�� �� ũ�� first = middle+1�� �ٲٰ� ��Ž��
	   ������ last = middle-1�� �ٲٰ� ��Ž��(���������϶�..)
*/

#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) ( ((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1 )


int main()
{
	int searchnum = 3;
	int searchnum2 = 20;
	int list[10] = { 1,3,4,5,6,7,8,9,10,17 };

	int result = binsearch(list, searchnum, 0, 9);
	int result2 = binsearch(list, searchnum2, 0, 9);

	if (result == -1)
		printf("Cannot find number...\n");
	else
		printf("Number is found in index = %d\n", result);

	if (result2 == -1)
		printf("Cannot find number...\n");
	else
		printf("Number is found in index = %d", result2);

	return 0;
}

int binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (COMPARE(searchnum, list[middle]))
		{
		case 1: // ����� ȣ���� ����� ��� binsearch(list, searchnum, middle+1, right);
			left = middle + 1;	// ã������ ���� middle�� �������� ����
			break;
		case 0:
			return middle; // ã���� �ش� �ε��� ��ȯ
		case -1: // ����� ȣ���� ����� ��� binsearch(list, searchnum, left, middle-1);
			right = middle - 1;
			break;
		}
	}

	return -1; // ã�� ���� ���


}

