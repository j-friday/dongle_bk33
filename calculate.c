#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>


void main()
{
	float vol = 0.0;
	char *p = "fueu74823";
	int i = 0;
	int k1;

	char num[64] = {};
	while(*p)
	{
		if(*p > '0' && *p < '9')
			num[i++] = *p;
		p++;
	}	

	printf("%s\r\n",(char *)num);	

	k1 = atoi(num);	
	printf("%d\r\n",k1);	
	/*calcalute*/
	vol = 1.05 *4.16 * (float) k1/255;
	printf("%lf\r\n",vol);	

	printf("==%3lf\r\n", vol);
	
}

