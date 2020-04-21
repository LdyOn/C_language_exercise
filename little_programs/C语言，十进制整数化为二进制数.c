#include<stdio.h>
void DealWith(int a[32],int n);
void GetComplement(int *a,int *b);
int main()
{
	int i;
	int num;
	int a[32];
	int b[32];
	printf("********输入整数，将整数化为二进制数*********\n");
	while(1)
	{
		printf("请输入整数：");
		scanf("%d",&num);
		printf("%d  化为二进制数为：",num);
		if(num<0)
		{
			num=-num;		
			DealWith(a,num);
			GetComplement(a,b);
			for(i=0;i<32;i++)
			{
				if(i%8==0)
					printf("  ");
				printf("%d",b[i]);
			}
		}
		else
		{
			DealWith(a,num);
			for(i=0;i<32;i++)
			{
				if(i%8==0)
					printf("  ");				
				printf("%d",a[i]);
			}
		}
		printf("\n");
	}
	



	return 0;
}
void DealWith(int a[32],int n)
{
	int i;
	int k=0;
	int t[32];
	for(i=0;i<32;i++)
		a[i]=0;
	while(n!=0)
	{
		t[k]=n%2;
		k++;
		n/=2;	
	}
	for(i=0;i<k;i++)
		a[31-i]=t[i];

}
void GetComplement(int *a,int *b)
{
	int i;
	int j=1;
	int temp;
	for(i=0;i<32;i++)
		b[i]=0;
	for(i=0;i<32;i++)
	{
		if(a[i]==0)
			a[i]=1;
		else
			a[i]=0;	
	}

	for(i=31;i>-1;i--)
	{
		temp=a[i]+j;
		if(temp==2)
		{
			j=1;
			b[i]=temp-2;
		}
		else
		{
			b[i]=temp;
			j=0;
		}
	
	}
}