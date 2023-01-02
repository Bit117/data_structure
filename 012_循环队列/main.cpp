#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#define MaxSize 5
//
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

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

	printf("store queue is %d\n", x); //打印已经存储的
	return true;
}

bool DeQueue(SqQueue& S, ElemType &x)
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
	SqQueue S;
	bool flag;
	InitQueue(S);
	ElemType m;//store value of DeQueue 

	//check if empty
	flag = isEmpty(S);
	if (flag)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("queue is not empty\n");
	}

	//en queue
	EnQueue(S, 1);
	EnQueue(S, 2);
	EnQueue(S, 3);
	EnQueue(S, 1);

	//full queue try
	flag = EnQueue(S, 2);
	if (flag)
	{
		printf("EnQueue success\n");
	}
	else
	{
		printf("EnQueue fail\n");
	}

	//out queue
	flag = DeQueue(S, m);
	if (flag)
	{
		printf("DeQueue value is %d\n",m);
	}
	else
	{
		printf("DeQueue fail\n");
	}

	return 0;
}
