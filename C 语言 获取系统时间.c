#include<stdio.h>
#include<time.h>
void PrintChar(char *ch,UINT count,UINT x,UINT y);
int main()
{
	struct tm *sysTime;
	int miao;
	int i;
	time_t nowTime;
	time(&nowTime);
	sysTime=localtime(&nowTime);
	miao=sysTime->tm_sec;
	printf("现在时间：\n");
	printf("%d-%d-%d",1900+sysTime->tm_year,sysTime->tm_mon+1,sysTime->tm_mday);
	printf("\t%d:%d:",sysTime->tm_hour,sysTime->tm_min);
	if(sysTime->tm_sec<10)
		printf("0");
	printf("%d",sysTime->tm_sec);
	while(1)
	{
		time(&nowTime);
		sysTime=localtime(&nowTime);
		if(miao!=sysTime->tm_sec)
		{
			miao=sysTime->tm_sec;
			for(i=0;i<24;i++)
			{
				printf("\b");
			
			}
			printf("%d-%d-%d",1900+sysTime->tm_year,sysTime->tm_mon+1,sysTime->tm_mday);
			printf("\t%d:%d:",sysTime->tm_hour,sysTime->tm_min);
			if(sysTime->tm_sec<10)
				printf("0");
			printf("%d",sysTime->tm_sec);
		}
	}
	return 0;
}