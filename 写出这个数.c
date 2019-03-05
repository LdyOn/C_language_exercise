/*读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。
输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
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
	printf("请输入一个数：");
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
	printf("\n各位数字之和：");
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



