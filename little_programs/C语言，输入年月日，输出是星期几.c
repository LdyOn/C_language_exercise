#include<stdio.h>
int Cal(int a,int b,int c);
int Rec(int y);
int Add(int a,int b,int c);
int RecDate(int a,int b,int c);
int main()                       //��2016��11��28��Ϊ��׼��������
{
	int iYear;
	int iMonth;
	int iDay;
	int iR;
	int pd;
	printf("***�����ꡢ�¡��գ�������ڼ���***");
	printf("\n----------------------------------\n");
	while(1)
	{
		printf("�꣺");
		scanf("%d",&iYear);
		printf("�£�");
		scanf("%d",&iMonth);
		printf("�գ�");
		scanf("%d",&iDay);
        pd=RecDate(iYear,iMonth,iDay);
		if(pd==1)
		{
			printf("���ڴ���\n");
			continue;
		}
		iR=Cal(iYear,iMonth,iDay);
		printf("%d��%d��%d��������",iYear,iMonth,iDay);
		switch(iR)
		{
			case 1:
				printf("һ");
				break;
		
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("��");
				break;

			default:
				printf("��");
				break;

		}
		printf("\n----------------------\n");
	}
	return 0;
}
int Cal(int a,int b,int c)//���庯�������������գ���������ڼ�
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
int Rec(int y)//�жϸ����Ƿ����꣬pd=1�����꣬pd=0��ƽ��
{
	int pd;
	if((y%4==0&&y%100!=0)||(y%400==0))
		pd=1;
	else
		pd=0;
	return pd;
}
int Add(int a,int b,int c)//���������գ��ж������Ǹ���ĵڼ���
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
int RecDate(int a,int b,int c)//�ж�����������Ƿ�����
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

