/*读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
输入格式：每个测试输入包含1个测试用例，格式为
  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112*/
#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[11];
	char stu_number[11];
	int score;
};
int main(void)
{
	int i,j,k;
	int n;
	int minPos,maxPos,min,max;
	char temp[11];
	struct student *pHead;
	printf("输入样例：\n");
	scanf("%d",&n);
	getchar();
	pHead=(struct student*)malloc(n*sizeof(struct student));
	for(i=0;i<n;i++)
	{
		gets(temp);
		j=0;
		k=0;
		while(temp[j]!=' ')
		{
			(pHead+i)->name[k]=temp[j];
			k++;
			j++;
		}
		(pHead+i)->name[k]='\0';
		while(temp[j]==' ')
			j++;
		k=0;
		while(temp[j]!=' ')
		{
			(pHead+i)->stu_number[k]=temp[j];
			k++;
			j++;
		}
		(pHead+i)->stu_number[k]='\0';
		while(temp[j]!='\0')
			j++;
		k=1;
		j--;
		(pHead+i)->score=0;
		while(temp[j]!=' ')
		{
			(pHead+i)->score+=(temp[j]-48)*k;
			k*=10;
			j--;
		}
	}
	maxPos=0;
	minPos=0;
	min=pHead->score;
	max=pHead->score;
	for(i=1;i<n;i++)
	{
		if(min>(pHead+i)->score)
		{
			minPos=i;
			min=(pHead+i)->score;
		}
		if(max<(pHead+i)->score)
		{
			maxPos=i;
			max=(pHead+i)->score;
		}
	}
	printf("输出样例：\n%s %s\n%s %s\n",(pHead+maxPos)->name,(pHead+maxPos)->stu_number,(pHead+minPos)->name,(pHead+minPos)->stu_number);
	return 0;
	
}













