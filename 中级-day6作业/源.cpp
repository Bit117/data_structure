#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MaxSize 50
//ջ�Ͷ���

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

void InitQueue(SqQueue& S)
{
	S.front = S.rear = 0; //������Ҫ����ֵ
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
	S.data[S.rear] = x; //Q.data[Q.rear++] = x �е�Q.rear++���ԣ���Ϊ��ѭ�����У����Ǽ򵥵�++
	S.rear = (S.rear + 1) % MaxSize;

	//printf("store queue is %d\n", x); //��ӡ�Ѿ��洢��
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
		Push(S, m);//��ջԪ��m
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
		EnQueue(Q, m);//��ջԪ��m
	}
	for (size_t i = 0; i < 4; i++)
	{
		flag = DeQueue(Q, m);
		printf(" %d", m);
	}
	//printf("\n");

	return 0;
}
