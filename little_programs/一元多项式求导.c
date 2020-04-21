/*设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）
输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0
*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int coe;
	int index;
	struct Node *next;
};
int main(void )
{
	char a[100];
	int  tem[5];
	int i,j;
	int c;
	int k=1;
	struct Node *t,*pHead;
	pHead=(struct Node*)malloc(sizeof(struct Node));
	pHead->next=NULL;
	printf("输入：\n");
	gets(a);
	i=0;
	t=pHead;
	while(a[i]!='\0')
	{
		j=0;
		while(a[i]!=' '&&a[i]!='\0')
		{
			tem[j]=a[i]-48;
			j++;
			i++;
		}
		if(k%2!=0)
		{
			t->next=(struct Node*)malloc(sizeof(struct Node));
			t=t->next;
			t->next=NULL;
			t->coe=0;
			if(i-j>0)
			{
				if(a[i-j-1]=='-')
					c=-1;
				else 
					c=1;
			}
			else 
				c=1;
			j--;
			while(j>-1)
			{
				t->coe+=tem[j]*c;
				c*=10;
				j--;
			}
		}
		else
		{
			t->index=0;
			if(i-j>0)
			{
				if(a[i-j-1]=='-')
					c=-1;
				else 
					c=1;
			}
			else
				c=1;
			j--;
			while(j>-1)
			{
				t->index+=tem[j]*c;
				c*=10;
				j--;
			}
		}
		while(a[i]==' '||a[i]=='-')
			i++;
		k++;
	}
	printf("输出:\n");
	t=pHead->next;
	while(t->index!=0)
	{
		printf("%d %d ",t->coe*t->index,t->index-1);
		t=t->next;
	}
	printf("\b");
	return 0;
}





