#include<stdio.h>
int Cal(int a,int b,int c);
int Rec(int y);
int Add(int a,int b,int c);
int RecDate(int a,int b,int c);
int main()                       //以2016年11月28号为基准进行推算
{
	int iYear;
	int iMonth;
	int iDay;
	int iR;
	int pd;
	printf("***输入年、月、日，输出星期几：***");
	printf("\n----------------------------------\n");
	while(1)
	{
		printf("年：");
		scanf("%d",&iYear);
		printf("月：");
		scanf("%d",&iMonth);
		printf("日：");
		scanf("%d",&iDay);
        pd=RecDate(iYear,iMonth,iDay);
		if(pd==1)
		{
			printf("日期错误！\n");
			continue;
		}
		iR=Cal(iYear,iMonth,iDay);
		printf("%d年%d月%d日是星期",iYear,iMonth,iDay);
		switch(iR)
		{
			case 1:
				printf("一");
				break;
		
			case 2:
				printf("二");
				break;
			case 3:
				printf("三");
				break;
			case 4:
				printf("四");
				break;
			case 5:
				printf("五");
				break;
			case 6:
				printf("六");
				break;

			default:
				printf("天");
				break;

		}
		printf("\n----------------------\n");
	}
	return 0;
}
int Cal(int a,int b,int c)//定义函数，输入年月日，输出是星期几
{
	int iResult=1;
	int iSum;
	int iTemp;
	int k;
	if(a>2016)
	{
		iSum=33;
		iTemp=2017;
		while(iTemp<a)
		{
			k=Rec(iTemp);
			if(k=0)
				iSum+=365;
			else
				iSum+=366;
			iTemp++;		
		}
		iSum+=Add(a,b,c);	
	}
	else if(a==2016)
	{
		if(b>11)
		{
			iSum=2+c;
		
		}
		else if(b==11)
		{
			if(c>=28)
				iSum=c-28;
			else
				iSum=28-c;
		}
		else
		{
			iSum=Add(2016,11,28)-Add(a,b,c);
		
		}
	
	}
	else
	{
		k=Rec(a);
		if(k=0)
			iSum=365-Add(a,b,c);
		else
			iSum=366-Add(a,b,c);
		iTemp=a+1;
		while(iTemp<2016)
		{
			k=Rec(iTemp);
			if(k=0)
				iSum+=365;
			else
				iSum+=366;
			iTemp++;
		}
		iSum+=Add(2016,11,28);
	
	}
	iResult+=iSum%7;
	return	iResult;
}
int Rec(int y)//判断该年是否闰年，pd=1：闰年，pd=0：平年
{
	int pd;
	if((y%4==0&&y%100!=0)||(y%400==0))
		pd=1;
	else
		pd=0;
	return pd;
}
int Add(int a,int b,int c)//输入年月日，判断这天是该年的第几天
{
	int sum;
	int i=1;
	int pd;
	while(i<b)
	{
		switch(i)
		{	
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
				sum+=31;
				break;
			case 2:
				pd=Rec(a);
				if(pd=1)
					sum+=29;
				else
					sum+=28;
				break;
			default:
				sum+=30;
				break;
		}
		i++;
	}
	sum+=c;
	return sum;
}
int RecDate(int a,int b,int c)//判断输入的日期是否有误；
{
	int iPd;
	int result=0;
	if(b<1||b>12)
		result=1;
	else if(b==2)
	{
		iPd=Rec(a);
		if(iPd==1)
		{
			if(c<1||c>29)
				result=1;
		}
		else
		{
			if(c<1||c>28)
				result=1;
		}
	}
	else
	{
		if(c<1||c>31)
			result=1;
		if(c==31)
		{
			if(b!=1&&b!=3&&b!=5&&b!=7&&b!=8&&b!=10&&b!=12)
				result=1;
		
		}
	}
	return result;


}

