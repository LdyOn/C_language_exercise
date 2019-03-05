#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10
struct	FOOTPRINT
{
	char cord[N];
};
void StrCopy(char *a,char *b);
int Match(char *p,struct FOOTPRINT *a);
void Show(struct RESULT *result);
void Delete(char *p,char a);
void Add(char a,struct FOOTPRINT *p);
int iCount=1;
int main()
{
	clock_t start,finish;
	start=clock();
	char *seek;
	char *head;
	char *mhou;
	int i,j,n;
	struct FOOTPRINT  *cur;

	printf("输入字符串(不超过10个)：\n");
	
	head=(char*)malloc(sizeof(char));
	mhou=(char*)malloc(sizeof(char));
	gets(head);
	printf("全排列：\n");

	i=0;
	while(*(head+i)!='\0')
		i++;
	n=i;


	cur=(struct FOOTPRINT* )malloc(n*sizeof(struct FOOTPRINT));
	i=0;
	while(*(head+i)!='\0')
	{
		(cur+i)->cord[0]=*(head+i);
		(cur+i)->cord[1]='\0';
		i++;
	
	}
	printf("%s\t",head);
	seek=head+n-1;

	while(1)
	{

		StrCopy(seek,mhou);
		i=0;
		while(*(mhou+i)!='\0')
		{
			*seek=*(mhou+i);
			if(!Match(seek,cur+(seek-head)))
			{
				Add(*seek,cur+(seek-head));
				for(j=seek-head+1;j<n;j++)
				{
					cur[j].cord[0]='\0';
				
				}
				Delete(mhou,*seek);
				seek++;
				while(seek<=head+n-1)
				{
					*seek=*mhou;
					Delete(mhou,*mhou);
					Add(*seek,cur+(seek-head));
					seek++;										
				}
				iCount++;			
				printf("%s\t",head);
				if(iCount%5==0)
					printf("\n");
				seek=head+n-1;
				break;
			}					
			i++;						
		}
		if(seek!=head+n-1)
			*seek=*mhou;
		if(seek==head)
			break;
		seek--;
	}
	finish=clock();
	free(cur);
	printf("\niCount=%d\n",iCount);
	printf("use time:%f  ",(double)(finish-start)/CLOCKS_PER_SEC);
	return 0;
}
void StrCopy(char *a,char *b)
{
	int i=0;
	while(*(a+i)!='\0')
	{
		*(b+i)=*(a+i);
		i++;	
	}
	*(b+i)='\0';

}
int Match(char *p,struct FOOTPRINT *a)
{
	int i=0;
	while(a->cord[i]!='\0')
	{
		if(*p==a->cord[i])
			return 1;
		i++;
	
	}
			
	return 0;
}
void Delete(char *p,char a)
{
	int i=0;
	while(*(p+i)!=a)
		i++;
	while(*(p+i+1)!='\0')
	{
		*(p+i)=*(p+i+1);
		i++;	
	}
	*(p+i)='\0';
}
void Add(char a,struct FOOTPRINT *p)
{
	int i=0;
	while(p->cord[i]!='\0')
		i++;
	p->cord[i+1]='\0';
	while(i>0)
	{
		p->cord[i]=p->cord[i-1];
		i--;	
	}
	p->cord[0]=a;
}
