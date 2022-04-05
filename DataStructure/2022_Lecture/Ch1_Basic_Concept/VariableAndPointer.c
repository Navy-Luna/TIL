// Chapter1_Basic_Concept의 Self Study를 위한 C파일
// Copyright By JYJ

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*	(1) 변수와 포인터의 활용01
		int i, *pi;
		pi = &i; // pi에 i의 주솟값이 들어간다.
		i = 10; *pi = 11;

		if (pi == NULL) // if(!pi)와 동치적 표현 -> pi가 Null이면 거짓인데 !에 의해 참으로 바뀜
			printf("Fail to allocate memory!\n");

		printf("%d %d", i, *pi);
	*/


	/*	(2) 변수와 포인터의 활용02
		int i, * pi;
		float f, * pf;
		pi = (int*)malloc(sizeof(int)); // malloc을 사용하여 새로운 메모리 공간을 할당 - 위에서의 차이는 i라는 기존의 것을 활용
		pf = (float*)malloc(sizeof(float));

		*pi = 1024;
		*pf = 3.14;

		printf("an integer = %d, a float = %f\n", *pi, *pf);
		free(pi); // 할당 후 사용이 끝난 메모리는 해제해야만 함 - 메모리 낭비를 막기 위해서
		free(pf);
	*/


	/*	(3) 메모리 동적 할당과 동시에 할당 성공여부 확인01
		int* pi;
		float* pf;

		if ((pi = (int*)malloc(sizeof(int))) == NULL || (pf = (float*)malloc(sizeof(float))) == NULL)
		{// 위와 다르게 따로 if 문에 넣은 이유는 할당하면서 할당이 성공했는지 확인하기 위함

			fprintf(stderr, "Insufficient memory"); // fprintf를 쓰면서 stderr를 사용하면 콘솔에 뒤의 string을 출력!
			exit(EXIT_FAILURE);
		}
		printf("memory is successfully allocated!");
	*/


	/*	(4) 메모리 동적 할당과 동시에 할당 성공여부 확인02
		int* pi;
		float* pf;

		if (!(pi = malloc(sizeof(int))) || !(pf = malloc(sizeof(float))))
		{ // 위의 == Null과의 차이는 type casting이 따로 필요 없음! pi의 자료형에 맞춰서 자동으로 type casting됨
			fprintf(stderr, "Insufficient memory!");
			exit(EXIT_FAILURE);
		}
	*/


	/*	(5) 메모리 동적 할당과 동시에 할당 성공여부 확인03 - 매크로 함수 이용(자주 사용/자료형 관계없이 사용가능해서 간편..02와 유사)
		#define MALLOC(p,s) \				// p와 s는 각각 포인터와 할당 size
			if(!((p) = malloc(s))) \		// 매크로 함수 여러줄을 쓸때는 끝에 \ 필요
			{ \
				fprintf(stderr, "Insufficient Error!); \
				exit(EXIT_FAILURE); \
			}

		MALLOC(pi,sizeof(int));
		MALLOC(pf,sizeof(float));			// 함수호출X : 전처리기가 미리 컴파일한 후에 "치환"을 하는거임 : 많이 쓸수록 손해..
	*/


	return 0;
}
