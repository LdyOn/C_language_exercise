/*����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�
�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10^100��
�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�
����������
1234567890987654321123456789
���������
yi san wu*/
#include<stdio.h>
int Pweishu(int num);
void Show(int a[],int w);
int main()
{
	int add=0;
	int a[3];
	int i=0;
	int yu=10;
	int di=1;
	char  shu[100];
	printf("������һ������");
	gets(shu);
	while(shu[i]!='\0'){
		add+=shu[i]-48;
		i++;
	}
	for(i=2;i>-1;i--)
	{
		a[i]=(add%yu)/di;
		yu*=10;
		di*=10;
	}
	Show(a,Pweishu(add));
	return 0;
}
int Pweishu(int num)
{
	int result=0;
	int n;
	n=num;
	while(n!=0){
		result++;
		n/=10;
	}
	return result;
}
void Show(int a[],int w)
{
	int i;
	printf("\n��λ����֮�ͣ�");
	for(i=3-w;i<3;i++)
		switch(a[i])
		{
			case 0:
			printf("ling ");
			break;
			case 1:
			printf("yi ");
			break;
			case 2:
			printf("er ");
			break;
			case 3:
			printf("san ");
			break;
			case 4:
			printf("si ");
			break;
			case 5:
			printf("wu ");
			break;
			case 6:
			printf("liu ");
			break;
			case 7:
			printf("qi ");
			break;
			case 8:
			printf("ba ");
			break;
			case 9:
			printf("jiu ");
			break;
		}
	printf("\b ");
	return;	
}



