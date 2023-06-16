#include <stdio.h>
#include <string.h>

#define LENGTH_BTADDR 20;
#define LENGTH_BTUUID 10;
#define LENGTH_BTSN   10;
#define LENGTH_BTNAME 11;
#define LENGTH_BTSTATU 11;

enum TYPE_BTDATA
{
	TYPE_ADDR,
	TYPE_UUID,
	TYPE_SNUM,
 	TYPE_NAME,
	TYPE_STATU,
};
void filt(char *typeStr, char *str, char ch, int type);
void main()
{
	char cmds[100];
    char *buf="mac:12:32faioejfoaisj32rw^%&^%*f=:12:32:15:33";
    char filter[256] ={0} ;

	filt(filter, buf, '=', 0);	
	sprintf(cmds, "AT+ADCEN\r\n");
	printf("%s\n",(char *)cmds);
	sprintf(cmds, "AT+ADCHello\r\n");
	printf("%s\n",(char *)cmds);
	sprintf(cmds, "AT+ADCEN\r\n");

	printf("%s\n",(char *)cmds);
}

void filt(char *typeStr, char *str, char ch, int type)
{

	char *str2 = NULL;
	int len = 0;
	printf("%d\n", __LINE__);
	str2 = strchr((char *)str, ':');
	switch(type)
	{
		case TYPE_ADDR:
			len  = LENGTH_BTADDR;
		case TYPE_UUID:
			len  = LENGTH_BTUUID;
		case TYPE_SNUM:
			len  = LENGTH_BTSN;
		case TYPE_NAME:
			len  = LENGTH_BTNAME;
		case TYPE_STATU:
			len  = LENGTH_BTSTATU;
		default:
			len = LENGTH_BTADDR;
	}
	
	printf("%d\n", __LINE__);
	//printf("%d %d\n", __LINE__,strlen(str2));
	/* Filter by type length*/
	if(str2 != NULL)
	//if(strlen(str2) >= len)
	{
		
		strncpy(typeStr, str2, len+1);	// copy length+1 data
	}
	else
		typeStr = "";
}
