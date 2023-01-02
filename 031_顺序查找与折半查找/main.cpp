#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef int ElemType;

typedef struct 
{
	ElemType* elem; //����ָ��
	int TableLen;	//���涯̬��������Ԫ�صĸ���
}SSTable;

/// <summary>
/// ��ʼ�������ɶ�̬������������֤
/// </summary>
/// <param name="ST">Ҫ����Ľṹ��</param>
/// <param name="len">���鳤��</param>
void ST_Init(SSTable & ST,int len)
{
	ST.TableLen = len + 1;//�����ڱ�,�ڱ������ᱻkey����
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);//Ϊ��̬��������ռ�
	int i;
	srand(time(NULL));//crate srand
	for (size_t i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
	
}

//��������Ĵ�ӡ
void ST_print(SSTable ST)
{
	for (size_t i = 0; i <ST.TableLen ; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

// ����˳�����
int Search_Seq(SSTable ST,ElemType key)
{
	ST.elem[0] = key;//�� ST.elem[0] ��Ϊ�ڱ����洢key,key��ʵ������һ������ֵ���б��
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; --i);
	return i;
}

/// <summary>
/// Ϊ������׼��
/// </summary>
/// <param name="left">left��right����������Ԫ�صĵ�ֵַ</param>
/// <param name="right">left��right����������Ԫ�صĵ�ֵַ</param>
/// <returns>���ص���һ���ȽϺ��ֵ�������������</returns>
int compare(const void* left, const void* right)
{
	return *(ElemType*)left - *(ElemType*)right;
}

int Binary_Search(SSTable ST, ElemType key)
{
	// low ,high ,mid ����λ��
	int low = 0;
	int high = ST.TableLen - 1;
	int mid;
	while (high >= low)
	{
		mid = (high + low) / 2;
		if (ST.elem[mid] == key)
		{
			return mid;
		}
		else if (key >= ST.elem[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = high - 1;
		}
	}
	return -1;
}


int main()
{
	SSTable ST;
	ElemType key;
	int pos;

	//init
	ST_Init(ST,10);
	
	//print
	ST_print(ST);

	//search
	printf("��������Ҫ���ҵ�ֵ\n");
	scanf("%d", &key);
	pos = Search_Seq(ST, key);
	if (pos)
	{
		printf("%d\n", pos);
	}
	else
	{
		printf("����ʧ��\n");
	}

	qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);
	ST_print(ST);
	printf("���ֲ��ң�������Ҫ������keyֵ��\n");
	scanf("%d", &key);
	printf("\n");
	pos = Binary_Search(ST, key);
	if (pos!=-1)
	{
		printf("�ҵ���λ���ǣ�%d\n", pos);
	}
	else
	{
		printf("����ʧ��");
	}

	return 0;
}
