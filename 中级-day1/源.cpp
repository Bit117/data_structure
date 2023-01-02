#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//

typedef struct student
{
	int num;
	char name[20];
	char sex;
}stu;

int main()
{
	stu s;
	scanf("%d%s %c", &s.num, s.name, &s.sex);
	printf("%d %s %c", s.num, s.name, s.sex);
	return 0;
}
