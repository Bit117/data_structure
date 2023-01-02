#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef int ElemType;

typedef struct 
{
	ElemType* elem; //整形指针
	int TableLen;	//储存动态数组里面元素的个数
}SSTable;

/// <summary>
/// 初始化，生成动态随机数组进行验证
/// </summary>
/// <param name="ST">要放入的结构体</param>
/// <param name="len">数组长度</param>
void ST_Init(SSTable & ST,int len)
{
	ST.TableLen = len + 1;//申请哨兵,哨兵后续会被key覆盖
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);//为动态数组申请空间
	int i;
	srand(time(NULL));//crate srand
	for (size_t i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
	
}

//进行数组的打印
void ST_print(SSTable ST)
{
	for (size_t i = 0; i <ST.TableLen ; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

// 进行顺序查找
int Search_Seq(SSTable ST,ElemType key)
{
	ST.elem[0] = key;//让 ST.elem[0] 作为哨兵，存储key,key其实可以用一个特殊值进行标记
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; --i);
	return i;
}

/// <summary>
/// 为排序做准备
/// </summary>
/// <param name="left">left，right是任意两个元素的地址值</param>
/// <param name="right">left，right是任意两个元素的地址值</param>
/// <returns>返回的是一个比较后的值，导致如何排序</returns>
int compare(const void* left, const void* right)
{
	return *(ElemType*)left - *(ElemType*)right;
}

int Binary_Search(SSTable ST, ElemType key)
{
	// low ,high ,mid 都是位置
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
	printf("请输入想要查找的值\n");
	scanf("%d", &key);
	pos = Search_Seq(ST, key);
	if (pos)
	{
		printf("%d\n", pos);
	}
	else
	{
		printf("查找失败\n");
	}

	qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);
	ST_print(ST);
	printf("二分查找，请输入要搜索的key值：\n");
	scanf("%d", &key);
	printf("\n");
	pos = Binary_Search(ST, key);
	if (pos!=-1)
	{
		printf("找到的位置是：%d\n", pos);
	}
	else
	{
		printf("查找失败");
	}

	return 0;
}
