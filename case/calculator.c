#include<stdio.h>
#include<stdlib.h>
struct num //定义结构体保存字符串之后化为数
{
	int a;
	int b;
	int ab[25];
};
struct node //定义链表节点
{
	int pd;//1：符号，2：数；
	double m;
	char sign;
	struct node *last;
	struct node *next;
};
struct node* deal_with(char a[]);
double array_change_num(struct num x);
double cif(int n);
void calculate_1(struct node *head);
void calculate(struct node *head);
int main()
{
	int i=0;
	char a[100];
	struct node *pHead;
	printf("*****************************\n");
	printf("*       这是一个计算器      *\n");
	printf("*****************************\n");
	while(1)
	{
		printf("请输入表达式，回车键结束：\n");
		gets(a);
		printf("=");
		pHead=deal_with(a);
		while(pHead->next!=NULL)
		{
			calculate(pHead);
		}
		printf("%f",pHead->m);
		printf("\n");
		free(pHead);
	}
	return 0;
}
double cif(int n)//求10的n次方
{
	double result=1.0;
	int i;
	for(i=0;i<n;i++)
	{
		result*=10.0;
	
	}
	return result;

}
struct node* deal_with(char a[])  //处理表达式
{
	int i=0;
	int j;
	int k;
	struct num temp;
	struct node *t;
	struct node *head;
	struct node *end;
	head=end=(struct node*)malloc(sizeof(struct node));						
	while(a[i]!='\0')//遍历a[]中的每一个字符，创建双向链表
	{
		if(a[i]=='+'||a[i]=='-')
		{
			if(i==0)
				i++;
			else
			{
				if(a[i-1]=='(')
					i++;
				else
				{
					t=(struct node*)malloc(sizeof(struct node));
					t->pd=1;
					t->sign=a[i];
					t->last=end;
					end->next=t;
					end=t;
					i++;
				}		
			}
		}
		else if(a[i]=='*'||a[i]=='/')
		{
			t=(struct node*)malloc(sizeof(struct node));
			t->pd=1;
			t->sign=a[i];
			t->last=end;
			end->next=t;
			end=t;
			i++;		
		}
		else if(a[i]=='('||a[i]==')')
		{
			t=(struct node*)malloc(sizeof(struct node));
			t->pd=1;
			t->sign=a[i];
			t->last=end;
			end->next=t;
			end=t;
			i++;		
		}
		else
		{
			temp.a=0;
			temp.b=0;
			for(j=0;j<25;j++)
				temp.ab[j]=0;
			k=0;               //k记录实数的位数		
			while(a[i]!='('&&a[i]!=')'&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='\0')
			{
				k++;
				i++;
			
			}
			for(j=i-k;j<i;j++)//计算实数整数位数
			{
				if(a[j]=='.')
					break;
				temp.a++;
			}
			if(temp.a!=k)
				temp.b=k-temp.a-1;//小数位数
			else
				temp.b=0;
			for(j=i-k;j<i-k+temp.a;j++)
			{temp.ab[j-i+k]=a[j]-48;}
			for(j=i-k+temp.a+1;j<i;j++)
			{temp.ab[j-i+k-1]=a[j]-48;}

			t=(struct node*)malloc(sizeof(struct node));
			t->pd=2;
			t->sign='#';
			if((i-k)>1)
			{
				if(a[i-k-1]=='-')
				{
					if(a[i-k-2]=='(')
						t->m=-array_change_num(temp);
					else 
						t->m=array_change_num(temp);
				}
				else if(a[i-k-1]=='+')
					t->m=array_change_num(temp);
				else if(a[i-k-1]=='*')
					t->m=array_change_num(temp);
				else
					t->m=array_change_num(temp);
			}
			else if(i-k==1)
			{
				if(a[0]=='-')
					t->m=-array_change_num(temp);
				else
					t->m=array_change_num(temp);
			}
			else
			t->m=array_change_num(temp);
			t->last=end;
			end->next=t;
			end=t;
		}
	}
	head=head->next;
	head->last=NULL;
	end->next=NULL;
	return head;
}
double array_change_num(struct num x)//结构体化为实数
{
	int i;
	int temp;
	double result=0;
	for(i=0;i<x.a;i++)
	{temp=x.ab[i];result+=(double)temp*cif(x.a-1-i);}
	for(i=0;i<x.b;i++)
	{temp=x.ab[x.a+i];result+=(double)temp/cif(i+1);}
	return result;

}
void calculate_1(struct node *head)//计算没有括号的表达式
{
	struct node *t,*result;
	t=head;	
	while(t->sign!='*'&&t->sign!='/'&&t->next!=NULL)
		t=t->next;		
	if(t!=NULL&&t->sign=='*')
	{
		if(t->last->last!=NULL)
		{
			result=(struct node*)malloc(sizeof(struct node ));
			result->pd=2;
			result->m=t->last->m*t->next->m;
			result->last=t->last->last;
			result->next=t->next->next;
			t->last->last->next=result;
			if(t->next->next!=NULL)
				t->next->next->last=result;
			free(t->last);
			free(t->next);
			free(t);

		}
		else
		{
			head->m=(t->last->m)*(t->next->m);
			head->next=t->next->next;
			if(t->next->next!=NULL)
				t->next->next->last=head;
			free(t->next);
			free(t);
		
		}
				
	}
	else if(t!=NULL&&t->sign=='/')
	{
		if(t->last->last!=NULL)
		{
			result=(struct node*)malloc(sizeof(struct node ));
			result->pd=2;
			result->m=(t->last->m)/(t->next->m);
			result->last=t->last->last;
			result->next=t->next->next;
			t->last->last->next=result;
			if(t->next->next!=NULL)
				t->next->next->last=result;
			free(t->last);
			free(t->next);
			free(t);	
		}
		else
		{
			head->m=t->last->m/t->next->m;
			head->next=t->next->next;
			if(t->next->next!=NULL)
				t->next->next->last=head;
			free(t->next);
			free(t);	
		}
	
	}
	else 
	{
		t=head;
		while(t->next!=NULL&&t->sign!='+'&&t->sign!='-')
		{
			t=t->next;		
		}
		if(t!=NULL&&t->sign=='+')
		{
			if(t->last->last!=NULL)
			{
				result=(struct node*)malloc(sizeof(struct node ));
				result->pd=2;
				result->m=(t->last->m)+(t->next->m);
				result->last=t->last->last;
				result->next=t->next->next;
				t->last->last->next=result;
				if(t->next->next!=NULL)
					t->next->next->last=result;
				free(t->last);
				free(t->next);
				free(t);
			}
			else
			{
				head->m=t->last->m+t->next->m;
				head->next=t->next->next;
				if(t->next->next!=NULL)
					t->next->next->last=head;
				free(t->next);
				free(t);
			}
		}

		else //if(t!=NULL&&t->sign=='-')
		{
			if(t->last->last!=NULL)
			{
				result=(struct node*)malloc(sizeof(struct node ));
				result->pd=2;
				result->m=(t->last->m)-(t->next->m);
				result->last=t->last->last;
				result->next=t->next->next;
				t->last->last->next=result;
				if(t->next->next!=NULL)
					t->next->next->last=result;
				free(t->last);
				free(t->next);
				free(t);

			}
			else
			{
				head->m=t->last->m-t->next->m;
				head->next=t->next->next;
				if(t->next->next!=NULL)
					t->next->next->last=head;
				free(t->next);
				free(t);
			}
		}
	
	}
	
	
}
void calculate(struct node *head)            //一般的表达式计算
{
	struct node *t1,*t2,*tHead;	
	t2=head;
	while(t2->next!=NULL&&t2->sign!=')')
		t2=t2->next;
	if(t2->sign==')')
	{
		t1=t2;
		while(t1->sign!='(')
			t1=t1->last;
		if(t1->last!=NULL)
		{
			tHead=t1->next;
			t2->last->next=NULL;
			tHead->last=NULL;
			while(tHead->next!=NULL)
			{
				calculate_1(tHead);
			}
			tHead->last=t1->last;
			t1->last->next=tHead;
			tHead->next=t2->next;
			if(t2->next!=NULL)
				t2->next->last=tHead;
			free(t1);
			free(t2);
		}
		else
		{		
			tHead=head->next;
			tHead->last=NULL;
			t2->last->next=NULL;			
			if(t2->next!=NULL)
				t2->next->last=head;		
			while(tHead->next!=NULL)
			{
				calculate_1(tHead);
			}
			head->pd=2;
			head->sign='#';
			head->next=t2->next;
			if(t2->next!=NULL)
				t2->next->last=head;
			head->m=tHead->m;
			free(tHead);
			free(t2);
		}
	}
	else
	{
		while(head->next!=NULL)
			calculate_1(head);	
	}		
}
