#include<stdio.h>
#include<stdlib.h>
struct code
{
	int iNumber;
	int b[30];
	int max;
};
int cal(int m,int n)
{
	int result=1;
	int i;
	int k=n-m;
	for(i=0;i<k;i++)
	{
		result=result*(n-i)/(1+i);
	}
	return result;
}
int Cmax(int n)
{
	int result;
	int i;
	result=cal(1,n);
	for(i=1;i<n;i++)
	{
		if(cal(i+1,n)>result)
			result=cal(i+1,n);		
	}
	return result;
}

int main()
{
	int n,x,y;
	int i,j,s,r,k;
	int *a;
	struct code* temp;
    struct code* last;
	printf("�����뼯�ϵ�Ԫ�ظ�����������30������");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	last=(struct code*)malloc(Cmax(n)*sizeof(struct code));

	printf("\n���ϵ�Ԫ�ظ�����%d\n",n);
	printf("���뼯��Ԫ�أ�\n");
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);	
		}
	printf("\n----����ļ���Ϊ----\n  {");
	for(i=0;i<n;i++)
		{
			if(i!=(n-1))
			{printf("%d  ",a[i]);}
			else
			{printf("%d}\n",a[i]);}	
		}

	printf("\n----���ϵ��Ӽ�----\n");
	printf("��0��Ԫ�ص��Ӽ����ռ�\n");
	
	for(s=0;s<n;s++)
	{
		last[s].b[0]=s;
		last[s].iNumber=1;
		last[s].max=s;
	}
	
	printf("��1��Ԫ�ص��Ӽ�:");
	for(s=0;s<n;s++)
	{
		printf("{");
		printf("%d  ",a[last[s].b[0]]);
		printf("}  ");
		if(s==n-1)printf("\n");
	}

	for(j=2;j<=n;j++)
	{
		y=0;
		temp=(struct code*)malloc(cal(j,n)*sizeof(struct code));
		for(k=0;k<cal(j-1,n);k++)
		{
			
			x=last[k].max;
			while(x<n-1)
			{
				temp[y].iNumber=j;
				for( r=0;r<j-1;r++)
				{
					temp[y].b[r]=last[k].b[r];
				
				}
				temp[y].b[j-1]=x+1;
				temp[y].max=x+1;
				x++;
				y++;
			}
					
		}
		printf("��%d��Ԫ�ص��Ӽ���",j);
		for(i=0;i<cal(j,n);i++)
		{
			printf("{");	
			for(s=0;s<j;s++)
			{
		       printf("%d ",a[temp[i].b[s]]);
			}
			printf("} ");
		
		}
		printf("\n");
        for(i=0;i<cal(j,n);i++)
		{
			last[i].iNumber=temp[i].iNumber;
			for(s=0;s<j;s++)
			{
				last[i].b[s]=temp[i].b[s];			
			}
			last[i].max=temp[i].max;		
		}	
		free(temp);
	}
	free(last);
	return 0;

}