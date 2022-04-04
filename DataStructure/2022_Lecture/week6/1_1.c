// 2020110249 윤주영
// 본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define _CRT_SECURE_NO_WARNINGS
#define MAX_EXPR_SIZE 80
#define MAX_STACK_SIZE 80

#include <stdio.h>
#include <stdlib.h>

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE]; // postfix expression

int top = -1;

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
precedence getToken(char* symbol, int* n);
int eval(void);
void push(int num);
int pop();

int main(void)
{
	FILE* fp;
	int i = 0;

	if ((fp = fopen("input.txt", "r")) == NULL)
	{
		fprintf(stderr, "Cannot open the file.");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%c ", &expr[i++]);
	while (!feof(fp))
		fscanf(fp, "%c ", &expr[i++]);


	printf("postfix expression : %s\n", expr);
	printf("the evaluation value : %d", eval());
	


	return 0;
}

int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
			push(symbol - '0');
		else
		{
			op2 = pop();
			op1 = pop();

			switch (token)
			{
			case plus: push(op1 + op2);
				break;
			case minus: push(op1 - op2);
				break;
			case times: push(op1 * op2);
				break;
			case divide: push(op1 / op2);
				break;
			case mod: push(op1 % op2);
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}


}

void push(int num)
{
	if (top == MAX_STACK_SIZE - 1)
		printf("Stack is full!");

	stack[++top] = num;
}

int pop()
{
	if (top == -1)
		printf("Stack is empty!");

	return stack[top--];
}
