#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MaxSize 50
//栈

typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S)
{
	S.top = -1;//栈初初始为空
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
	if (S.top == MaxSize - 1)//S.data 是数组 MaxSize是大小
	{
		return false;//stack is full
	}
	S.data[++S.top] = x; //给栈赋值
	return true;
}

bool GetTop(SqStack S, ElemType& m)
{
	if (StackEmpty(S))
	{
		return false;
	}
	m = S.data[S.top]; //拿到栈顶
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
	m = S.data[S.top--]; //拿到栈顶，top--
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
		printf("栈是空的\n");
	}

	//push stack
	//Push(S, 4);
	Push(S, 3);//入栈元素3
	Push(S, 4);//入栈元素4
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
