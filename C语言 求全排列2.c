#include<time.h>
#include <stdio.h>
#define N 5
int count=0;
void show(char a[]);
void swap(char *a,char *b);
void permgen(char a[],int n);

void show(char a[])

{
	int i;	
	for(i=0;i<N;i++)
	
	{
		printf("%c,",a[i]);
	}	
		printf("\n");
		count=count+1;

}


void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void permgen(char a[],int n)

{
	if(n<=1)		
		{show(a);return;}
	
	int i;	
	for(i=0;i<n;i++)	
	{
		swap(a+i,a+n-1);
		permgen(a,n-1);
		swap(a+i,a+n-1);
	}


}


int main()

{	
	clock_t finish;
	printf("hello world!\n");
	char a[N]={'a','b','c','d','e'};
	permgen(a,N);
	printf("The count =%d\n",count);
	finish=clock();
	printf("use time:%f",(double)finish/CLOCKS_PER_SEC);	
	return 0;
}
