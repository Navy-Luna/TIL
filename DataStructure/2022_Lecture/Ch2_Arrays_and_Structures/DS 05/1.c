// 2022.04.12 : Polynomial addition
// 두 다항식의 정보를 파일로부터 받아 다항식 더하기를 수행한 후 결과를 출력하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 100
#define COMPARE(x,y) (((x)>(y)) ? 1 : ((x)==(y)) ? 0 : -1)

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float coef;
	int exp;
}term;

term terms[MAX_TERMS];
int avail = 0;

void padd(int startA, int finishA, int startB, int finishB, int* startC, int* finishC);
void attach(float coefficient, int exponent);
void printPoly(int start, int finish);

int main()
{
	// 각 항의 시작과 끝을 기록할 변수
	int startA=0, finishA, startB, finishB, startC, finishC;

	// 파일로부터 정보를 읽어드리기(항의 개수)
	FILE* fp = fopen("input.txt", "r");

	fscanf(fp,"%d", &startB);
	finishA = startB - 1;
	fscanf(fp,"%d", &finishB);
	finishB = finishB + finishA;

	avail = finishB + 1;

	// 다항식 정보 받기
	for (int i = 0; i <= finishA; i++)
		fscanf(fp,"%f %d", &terms[i].coef, &terms[i].exp);
	for (int i = startB; i <= finishB; i++)
		fscanf(fp,"%f %d", &terms[i].coef, &terms[i].exp);

	// 다항식 더하기
	padd(startA, finishA, startB, finishB, &startC, &finishC);
	
	printf("two input polynomials ...\n");
	printf("A(x) = ");
	printPoly(startA, finishA);
	printf("B(x) = ");
	printPoly(startB, finishB);

	printf("\nthe result of polynomial addition ...\n");
	printf("C(x) = A(x) + B(x) =\n");
	printPoly(startC, finishC);

	fclose(fp);
	return 0;
}

/* 두 다항식의 덧셈을 구현하는 함수 : O(m+n) */
void padd(int startA, int finishA, int startB, int finishB, int* startC, int* finishC)
{
	*startC = avail;
	float sum = 0;

	while (startA <= finishA && startB <= finishB)
	{
		switch (COMPARE(terms[startA].exp, terms[startB].exp))
		{
		case 1: // a의 차수 > b의 차수
			attach(terms[startA].coef, terms[startA].exp);
			startA++;
			break;
		case 0: // a의 차수 = b의 차수
			sum = terms[startA].coef + terms[startB].coef;
			if (sum)
				attach(sum, terms[startA].exp);
			startA++; startB++;
			break;
		case -1: // a의 차수 < b의 차수
			attach(terms[startB].coef, terms[startB].exp);
			startB++;
			break;
		}
	}
	/* 남은 다항식들 털어내기 */
	for (; startA <= finishA; startA++) attach(terms[startA].coef, terms[startA].exp);
	for (; startB <= finishB; startB++) attach(terms[startB].coef, terms[startB].exp);

	*finishC = avail - 1;
}

/* 더하기의 결과값을 배열에 저장하는 함수 */
void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS)
	{ // 사용가능한 공간을 넘어갈 경우
		fprintf(stderr, "Insufficient Memory!");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].exp = exponent;
}

/* 하나의 다항식을 받아 출력하는 함수 */
void printPoly(int start, int finish)
{
	for (int i = start; i <= finish; i++)
	{
		if (terms[i].exp == 0)
			printf("  %+.1f", terms[i].coef);
		else
			printf("  %+.1fx^%d", terms[i].coef, terms[i].exp);
	}
	printf("\n");
}