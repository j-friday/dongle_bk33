#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define LENGTH_BTADDR 20;
#define LENGTH_BTUUID 10;
#define LENGTH_BTSN   10;
#define LENGTH_BTNAME 11;
#define LENGTH_BTSTATU 11;

typedef struct BK_Info
{
	char Addr[32];
	char Uuid[32];
	char SN[32];
	char Name[32];
	char Version[32];
}BK_Info_T;

void main()
{
    char *buf="mac:12:32faioejMACfoaisj32rw^%&NAME=:12:32:15:33443";
	struct BK_Info *bkinfo;
	char infoline[1024] = {0};
	int i;
	int total;
	char commands[5][32] = {"AT+BLENAME\r\n", "AT+MAC\r\n","AT+SN\r\n","AT+UUID\r\n","AT+VERSION\r\n"};	
	char label[5][32] = {"NAME", "MAC","SN","UUID","VERSION"};	
	int lenlab[5];
	lenlab[0]=LENGTH_BTNAME;
	lenlab[1]=LENGTH_BTADDR;
	lenlab[2]=LENGTH_BTSN;
	lenlab[3]=LENGTH_BTUUID;
	lenlab[4]=LENGTH_BTSTATU;
// LENGTH_BTADDR, LENGTH_BTSN, LENGTH_BTUUID ,LENGTH_BTVERSION};	
	bkinfo = malloc(sizeof(struct BK_Info));
    char filter[256] ={0} ;
	int len = LENGTH_BTUUID;
	snprintf(bkinfo->Addr, 20, "%s", buf);
	snprintf(bkinfo->Uuid, len, "%s", strstr(buf,"mac"));
	snprintf(bkinfo->SN, 11,"%s", strchr(buf,':'));
	
	for(i = 0; i < 5;i++)
	{
		snprintf(bkinfo->Name, len, "%s" ,commands[i]);
	}

	len = lenlab[0]+strlen(label[i])+5;
	printf("==  %d %s\r\n", len,strstr(buf, label[0]) );
	printf("==  %d %s\r\n", len,strstr(buf, label[0]) );
	

	total = snprintf(infoline, len, "%s\r\n", strstr(buf, label[0]));
	printf("==  %d, %s\r\n", total, infoline);
	total += snprintf(infoline+total, len, "%s\r\n", strstr(buf, label[1]));
	
	printf("==  %d, %s\r\n", total, infoline+total);
	
	printf("== %s \n", infoline);
	free(bkinfo);

}

