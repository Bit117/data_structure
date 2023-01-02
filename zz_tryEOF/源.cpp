#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//    int a = 0, b = 0, sum = 0;
//    //EOF尝试
//    //while (scanf("%d%d", &a, &b) != EOF)// 两行输入两个数，一直循环 输入 Ctrl+Z 才结束
//    //{
//    //    sum = a + b;
//    //    printf("%d\n", sum);
//    //}
//
//    ////赋值尝试
//    //a = 3;
//    //b = a;//新开辟空间
//    //a = 5;
//    ////b = 4;
//    //printf("%d\n", a);
//    //printf("%d\n", b);
//
//    //指针尝试
//    int* p;
//    p = &a;
//    printf("%d\n", *p);
//    return 0;
//}


#include <iostream>
#include <stdio.h>
#include "stdlib.h"
#include <string>
#include "string.h"
using namespace std;

typedef struct student
{
	/* data */
	string name;
	string clas;
	int age;
}stu, * pstu;



int main()
{
	stu s;
	//s = (stu)malloc(sizeof(stu));

	string sname = "ssss";
	s.name = "ssss";
	//s->clas[0] = 'c';
	//s->age = 16;


	/*printf("%s %s %d\n", s->name, s->clas, s->age);*/
	//printf("%s\n", s->name);
	cout << s.name << endl;

	int x = 2;
	int* p = &x;
	int* q = p;
	printf("%d\n", p);
	printf("%d\n", q);

	return 0;
}
