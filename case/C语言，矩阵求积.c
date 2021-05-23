#include<stdio.h>
#include<stdlib.h>
struct mal 
{
	int c;
	int r;
	int memb[100];

};
void Put(struct mal *p);
void Deal(int n,int b[],char a[],int *p);
int Cif(int n);
int Change(int a,int b[]);
void Show(struct mal *p);
void Calculate(struct mal *a,struct mal *b,struct mal *c);
int main()
{
	struct mal *a;
	struct mal *b;
	struct mal *p;
	printf("*******计算 整数矩阵A乘整数矩阵B*******\n");
	while(1)
	{
		a=(struct mal*)malloc(sizeof(struct mal));
		b=(struct mal*)malloc(sizeof(struct mal));
		p=(struct mal*)malloc(sizeof(struct mal));
		printf("输入A矩阵（元素不超过100个,‘回车’输入下一行，‘#’结束输入）：\n");
		Put(a);
		printf("输入B矩阵（元素不超过100个,‘回车’输入下一行，‘#’结束输入）：\n");
		Put(b);
		printf("\n");
		printf("--------------------------------------\n");
		Show(a);
		printf("--------------------------------------\n");
		printf("                X                 \n");
		printf("--------------------------------------\n");
		Show(b);
		printf("--------------------------------------\n");
		if(a->c!=b->r)
		{
			printf("A的列不等于B的行！");
			continue;
		}
		Calculate(a,b,p);
		printf("=\n");
		Show(p);
		printf("\n");
		free(a);
		free(b);
		free(p);
	}
	return 0;
}
void Put(struct mal *p)
{
	int i=0;
	int j=0;
	int k=0;
	int iC;
	int *t=&iC;
	char a[100];
	char pd;
	while(1)
	{
		gets(a);
	
		j++;
		Deal(i,p->memb,a,t);
		if(j==1)
			p->c=iC;
		if(j>1&&iC!=p->c)
		{
			printf("输入有误！重新输入该行：\n");
			j--;
			continue;
		}
		while(a[k]!='\0')
			k++;
		pd=a[k-1];
		if(pd=='#')
			break;
		else
		{
			k=0;
			i+=p->c;
		}		
	}
	p->r=j;

}
 void Deal(int n,int b[],char a[],int *p)
 {
	 int i=0;
	 int j=0;
	 int k=0;
	 int pi=n;
	 int temp[10];
	 while(a[i]!='#'&&a[i]!='\0')
	 {
		 while(a[i]=='-'||a[i]==' ')
			i++;
		 while(a[i]!=' '&&a[i]!='\0'&&a[i]!='#'&&a[i]!='-')
			{
				k++;
				temp[j]=a[i]-48;
				i++;
				j++;	
			}
		 if((i-k)==0)
			b[pi]=Change(k,temp);
		 else
		 {
			 if(a[i-k-1]=='-')
				b[pi]=-Change(k,temp);
			 else
				b[pi]=Change(k,temp);
		 }
		 pi++;
		 k=0;
		 j=0;
		 while(a[i]==' ')
			 i++;
	}
	 *p=pi-n;
 }
int Cif(int n)//求10的n次方
{
	int result=1;
	int i;
	for(i=0;i<n;i++)
	{
		result*=10;
	
	}
	return result;

}
int Change(int a,int b[])
{
	int result=0;
	int i;
	for(i=0;i<a;i++)
		result+=b[i]*Cif(a-i-1);
	return result;	
}
void Show(struct mal *p)
{
	int i;
	int j;
	for(j=0;j<p->r;j++)
	{
		for(i=0;i<p->c;i++)
			printf("%-7d   ",p->memb[i+j*p->c]);
		printf("\n");
	}

}
void Calculate(struct mal *a,struct mal *b,struct mal *p)
{
	int i,j,k;
	p->r=a->r;
	p->c=b->c;
	for(i=0;i<p->r*p->c;i++)
		p->memb[i]=0;
	for(i=0;i<a->r;i++)
		for(j=0;j<a->c;j++)
		{
			for(k=0;k<p->c;k++)
			{
				p->memb[i*p->c+k]+=a->memb[i*a->c+j]*b->memb[j*b->c+k];
			}
		}
	
}