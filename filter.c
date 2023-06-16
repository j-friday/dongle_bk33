#include <stdio.h>
#include <string.h>
#include <stdint.h>


void main()
{
	uint8_t *a;
	char *p = NULL;
	char *dis = NULL;
	int i =0;
	p = "hello world";
	a = p;
	printf("%s\n", p);
	while(i<100)
	{
	dis = p +i++;
	printf("%c", dis);
	}
}

