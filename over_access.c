#include <stdio.h>
#include <string.h>
#include <stdint.h>


void set(const char *name);
void main()
{
	const char *str = "1234567890123456";
	set((const char *)__func__);


	
}


void set(const char *name)
{
	char num[12];
	printf("%d\r\n", strlen(name));	
	if(strlen(name) <16)
	{
		memcpy(num, name, 4);
	}
	else
	{
		
		printf("%d\r\n", __LINE__);	
	//	memcpy();
	}
}
