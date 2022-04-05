// Chap1_Basic_Concept : Performace Analysis and Measurment
// input, increase, free가 실행 후(즉, 반환 직후)의 스택 및 힙 상태에 대한 그림을 그려라
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
	int num, * pNum; // pNum은 동적할당에 의한 배열

	FILE* fpIn = fopen("input.txt", "r");
	FILE* fpOut = fopen("output.txt", "w");

	fscanf(fpIn, "%d", &num);		// 데이터 갯수
	pNum = alloc(num);				// space가 가리키던 메모리 주소가 전달됨
	input(pNum, num, fpIn);			// 파일로부터 num개 데이터 입력
	increase(pNum, num);			// 각 데이터를 1씩 증가시킴
	output(pNum, num, fpOut);		// 증가된 데이터를 파일출력

	free(pNum);		// 힙에 할당된 공간을 해제해준다고해서 스택에 있는 pNum(main이라는 함수)이 사라지는건 아니다.
	fclose(fpIn);
	fclose(fpOut);

}

