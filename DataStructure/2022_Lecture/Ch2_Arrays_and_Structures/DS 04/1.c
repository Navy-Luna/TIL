/* 
   2022.04.11
   �����Ҵ� �迭, �����Ҵ� �迭, ����ü �н��� �����ϱ� ���� �ڵ�
   (1) ������ �����Ҵ�� 2���� �迭�� �Լ��� �����غ��� ���غ���
 */

#include <stdio.h>
#include <stdlib.h>

int sumAry2D_f1(int a[][3], int row, int col);
int sumAry2D_f2(int(*a)[3], int row, int col);
int sumAry2D_f3(int a[2][3], int row, int col);
int sumAry2D_f4(int** ary, int row, int col);
int sumAry2D_f5(int*** ary, int row, int col);
void freeAry2D(int** ary, int row);

int main()
{
	// ���� �Ҵ��� 2���� �迭(2�� 3��)
	int ary2D[2][3] = { {1,2,3}, {4,5,6} };

	// �����Ҵ��� 2���� �迭(2�� 3��)
	int r, c;
	int** ary = (int**)malloc(2 * sizeof(int*));
	for (r = 0; r < 2; r++)
		ary[r] = (int*)malloc(3 * sizeof(int));

	for (r = 0; r < 2; r++)
		for (c = 0; c < 3; c++)
			ary[r][c] = r + c;

	// �����Ҵ� �迭
	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 2, 3));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 2, 3));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, 2, 3));

	// �����Ҵ� �迭
	printf("sumAry2D_f4() %d\n", sumAry2D_f4(ary, 2, 3));
	printf("sumAry2D_f4() %d\n", sumAry2D_f5(&ary, 2, 3)); // ������ ���� ���������ͷ� ������ &�� ����

	// �����Ҵ� �迭�� f1-3�� ������ �� ������? �׽�Ʈ�غ���!
	// printf("sumAry2D_f1~f3() %d\n", sumAry2D_f1(ary,2,3)); -> �赵������ ���� �̻��� ������ �޾ƹ���..����

	// �����Ҵ� �迭�� f4-5�� ������ �� ������? �׽�Ʈ�غ���!
	// printf("sumAry2D_f4~f5() %d\n", sumAry2D_f4(ary2D,2,3));

	freeAry2D(ary, 2);

	return 0;
}

void freeAry2D(int** ary, int row) // 2���� �����Ҵ� �迭�� ����
{	/* �޸𸮸� �Ҵ��� ���ʹ� �ݴ�� ������ �������ָ� �ȴ�. */
	for (int i = 0; i < row; i++)
		free(ary[i]);	// �࿡ �ش��ϴ� ������ 1���� �迭 free

	free(ary);	// ����� �����״� �����͵��� ������ free

	return;
}

int sumAry2D_f1(int a[][3], int row, int col)
{	/* ���⼭ ����ϴ� a+1�� �ι�° ���� ���ۿ� ���� �ּڰ� */
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += a[i][j];
	return sum;
}

int sumAry2D_f2(int (*a)[3], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += a[i][j];
	return sum;
}

int sumAry2D_f3(int a[2][3], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += a[i][j];
	return sum;
}

int sumAry2D_f4(int** ary, int row, int col)
{	/* ���⼭ ary+1�� �ǹ̴� �ι�° ���� �ּҸ� ���� �޸��� �ּڰ� */
	/* ���� �ǹ̿� ��.. �򰥸��� �׳� ������ �ܿ�� ^��^ */
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += *(*(ary + i) + j);
	return sum;
}

int sumAry2D_f5(int*** ary, int row, int col)
{	/* ���⼭ *ary�� �ǹ̴� ù��° ���� �ּҸ� ���� �޸��� �ּڰ� */
	/* ���� �ٸ��� ������ �����Ҷ��� �ּ� &�� �ٿ��� �����ؾ����� �������! */

	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += *(*(*ary + i) + j); // f4�� �ٸ����� ary(�����͸� �ѹ� �� �޾����ϱ�)
	return sum;

	return 0;
}