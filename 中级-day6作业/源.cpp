#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MaxSize 50
//栈和队列

typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

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

void InitQueue(SqQueue& S)
{
	S.front = S.rear = 0; //这里需要赋初值
}

bool isEmpty(SqQueue S)
{
	if (S.front == S.rear)
	{
		return true;
	}
	return false;
}

bool EnQueue(SqQueue& S, ElemType x)
{
	//check if queue full
	if ((S.rear + 1) % MaxSize == S.front)
	{
		return false;
	}
	S.data[S.rear] = x; //Q.data[Q.rear++] = x 中的Q.rear++不对，因为是循环队列，不是简单的++
	S.rear = (S.rear + 1) % MaxSize;

	//printf("store queue is %d\n", x); //打印已经存储的
	return true;
}

bool DeQueue(SqQueue& S, ElemType& x)
{
	if (isEmpty(S))
	{
		return false;
	}
	x = S.data[S.front];
	S.front = (S.front + 1) % MaxSize;
	return true;
}

int main()
{
	//Init Stack
	SqStack S;
	InitStack(S);
	ElemType m;
	bool flag;
	for (size_t i = 0; i < 3; i++)
	{
		scanf("%d", &m);
		Push(S, m);//入栈元素m
	}
	for (size_t i = 0; i < 3; i++)
	{
		flag = Pop(S, m);
		if (flag)
		{
			printf(" %d", m);
		}
	}
	printf("\n");

	SqQueue Q;
	InitQueue(Q);
	int j = 0;
	for (size_t i = 0; i < 5; i++)
	{
		j++;
		if (j > 4)
		{
			printf("false\n");
			break;
		}
		scanf("%d", &m);
		EnQueue(Q, m);//入栈元素m
	}
	for (size_t i = 0; i < 4; i++)
	{
		flag = DeQueue(Q, m);
		printf(" %d", m);
	}
	//printf("\n");

	return 0;
}
