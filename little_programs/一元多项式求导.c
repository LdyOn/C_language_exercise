/*��ƺ�����һԪ����ʽ�ĵ�������ע��xn��nΪ��������һ�׵���Ϊn*xn-1����
�����ʽ����ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���
�����ʽ������������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����
����������
3 4 -5 2 6 1 -2 0
���������
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
	printf("���룺\n");
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
	printf("���:\n");
	t=pHead->next;
	while(t->index!=0)
	{
		printf("%d %d ",t->coe*t->index,t->index-1);
		t=t->next;
	}
	printf("\b");
	return 0;
}





