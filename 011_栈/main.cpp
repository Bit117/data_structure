#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MaxSize 50
//ջ

typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S)
{
	S.top = -1;//ջ����ʼΪ��
}

bool StackEmpty(SqStack S)
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}

bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)//S.data ������ MaxSize�Ǵ�С
	{
		return false;//stack is full
	}
	S.data[++S.top] = x; //��ջ��ֵ
	return true;
}

bool GetTop(SqStack S, ElemType& m)
{
	if (StackEmpty(S))
	{
		return false;
	}
	m = S.data[S.top]; //�õ�ջ��
	return true;
}

bool PrintStack(SqStack S, ElemType& m)
{
	if (StackEmpty(S))
	{
		return false;
	}

	m = S.data[S.top--];
}

bool Pop(SqStack& S, ElemType& m)
{
	if (StackEmpty(S))
	{
		return false;
	}
	m = S.data[S.top--]; //�õ�ջ����top--
	return true;
}

int main()
{
	//Init Stack
	SqStack S;
	InitStack(S);
	ElemType m;
	bool flag;
	// check if empty
	flag = StackEmpty(S);
	if (flag)
	{
		printf("ջ�ǿյ�\n");
	}

	//push stack
	//Push(S, 4);
	Push(S, 3);//��ջԪ��3
	Push(S, 4);//��ջԪ��4
	Push(S, 5);

	//get stack
	flag = GetTop(S, m);
	if (flag)
	{
		printf("top stcak is %d\n", m);
	}

	//pop stack
	flag = Pop(S, m);
	if (flag)
	{
		printf("pop stack is %d\n", m);
	}


	//try to print every value in stack
	for (size_t i = 0; i <= S.top; i++)
	{
		PrintStack(S, m);
		printf("pop stack is %d\n", m);
	}

	return 0;
}
