// Chap1_Basic_Concept : Performace Analysis and Measurment
// input, increase, free�� ���� ��(��, ��ȯ ����)�� ���� �� �� ���¿� ���� �׸��� �׷���
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* alloc(int num)
{
	int* space;
	space = (int*)malloc(sizeof(int) * num);
	return space;
}

void input(int* p,int num, FILE* fp)
{
	for (int i = 0; i < num; i++)
		fscanf(fp, "%d", p+i);
}

void increase(int* p, int num)
{
	for (int i = 0; i < num; i++)
		p[i] += 1;
}

void output(int* p, int num, FILE* fo)
{
	fprintf(fo, "%d\n", num);

	for (int i = 0; i < num; i++)
		fprintf(fo, "%d ", *(p + i));
}



int main()
{
	int num, * pNum; // pNum�� �����Ҵ翡 ���� �迭

	FILE* fpIn = fopen("input.txt", "r");
	FILE* fpOut = fopen("output.txt", "w");

	fscanf(fpIn, "%d", &num);		// ������ ����
	pNum = alloc(num);				// space�� ����Ű�� �޸� �ּҰ� ���޵�
	input(pNum, num, fpIn);			// ���Ϸκ��� num�� ������ �Է�
	increase(pNum, num);			// �� �����͸� 1�� ������Ŵ
	output(pNum, num, fpOut);		// ������ �����͸� �������

	free(pNum);		// ���� �Ҵ�� ������ �������شٰ��ؼ� ���ÿ� �ִ� pNum(main�̶�� �Լ�)�� ������°� �ƴϴ�.
	fclose(fpIn);
	fclose(fpOut);

}

