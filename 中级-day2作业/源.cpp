#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//

void print_char(char*& p)
{
	p = (char*)malloc(100);
	fgets(p, 100, stdin);
}

int main()
{
	char* p = NULL;
	print_char(p);
	puts(p);
	//printf("%s", p);
	return 0;
}
