/* 
   2022.04.11
   정적할당 배열, 동적할당 배열, 구조체 학습을 복습하기 위한 코드
   (1) 정적과 동적할당된 2차원 배열을 함수로 전달해보고 비교해봐라
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
	// 정적 할당의 2차원 배열(2행 3열)
	int ary2D[2][3] = { {1,2,3}, {4,5,6} };

	// 동적할당의 2차원 배열(2행 3열)
	int r, c;
	int** ary = (int**)malloc(2 * sizeof(int*));
	for (r = 0; r < 2; r++)
		ary[r] = (int*)malloc(3 * sizeof(int));

	for (r = 0; r < 2; r++)
		for (c = 0; c < 3; c++)
			ary[r][c] = r + c;

	// 정적할당 배열
	printf("sumAry2D_f1() %d\n", sumAry2D_f1(ary2D, 2, 3));
	printf("sumAry2D_f2() %d\n", sumAry2D_f2(ary2D, 2, 3));
	printf("sumAry2D_f3() %d\n", sumAry2D_f3(ary2D, 2, 3));

	// 동적할당 배열
	printf("sumAry2D_f4() %d\n", sumAry2D_f4(ary, 2, 3));
	printf("sumAry2D_f4() %d\n", sumAry2D_f5(&ary, 2, 3)); // 전달할 때는 삼중포인터로 받으니 &로 전달

	// 동적할당 배열을 f1-3에 전달할 수 있을까? 테스트해보자!
	// printf("sumAry2D_f1~f3() %d\n", sumAry2D_f1(ary,2,3)); -> 듣도보지도 못한 이상한 것으로 받아버림..ㅋㅋ

	// 정적할당 배열을 f4-5에 전달할 수 있을까? 테스트해보자!
	// printf("sumAry2D_f4~f5() %d\n", sumAry2D_f4(ary2D,2,3));

	freeAry2D(ary, 2);

	return 0;
}

void freeAry2D(int** ary, int row) // 2차원 동적할당 배열의 해제
{	/* 메모리를 할당할 때와는 반대로 해제를 진행해주면 된다. */
	for (int i = 0; i < row; i++)
		free(ary[i]);	// 행에 해당하는 각각의 1차원 배열 free

	free(ary);	// 행들을 가리켰던 포인터들의 모임을 free

	return;
}

int sumAry2D_f1(int a[][3], int row, int col)
{	/* 여기서 사용하는 a+1은 두번째 행의 시작에 대한 주솟값 */
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
{	/* 여기서 ary+1의 의미는 두번째 행의 주소를 담은 메모리의 주솟값 */
	/* 위의 의미와 비교.. 헷갈리면 그냥 깡으로 외우기 ^ㅁ^ */
	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += *(*(ary + i) + j);
	return sum;
}

int sumAry2D_f5(int*** ary, int row, int col)
{	/* 여기서 *ary의 의미는 첫번째 행의 주소를 담은 메모리의 주솟값 */
	/* 위와 다르게 변수를 전달할때는 주소 &를 붙여서 전달해야함을 기억하자! */

	int sum = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum += *(*(*ary + i) + j); // f4와 다른것은 ary(포인터를 한번 더 받았으니까)
	return sum;

	return 0;
}