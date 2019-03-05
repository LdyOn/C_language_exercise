/*“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/
#include<stdio.h>
#include<string.h>
int Rec(char *c);
int Pan(char a[]);
int main()
{
	int i;
	char a[10][100];
	int n;
	printf("输入需要检测的字符串个数：");
	scanf("%d",&n);
	getchar();
	printf("输入字符串，回车结束\n");
	for(i=0;i<n;i++)
		gets(a[i]);
	printf("判断结果如下：\n");
	for(i=0;i<n;i++)
	{
		if(Rec(a[i]))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
int Pan(char a[])
{
	int i;
	i=0;
	while(a[i]!='\0')
	{
		if(a[i]!='A')
			break;
		i++;
	}
	if(a[i]=='\0')
		return 1;
	else
		return 0;
	
	
}
int Rec(char *c)
{
	int i=0;
	int iP,iT;
	iP=100;
	iT=100;
	char sFor[100];
	char sMid[100];
	char sBac[100];
	char sTemp[100];
	int L_sFor;
	int L_sH;
	
	while(*(c+i)!='\0')
	{
		if(*(c+i)=='P')
			iP=i;
		if(*(c+i)=='T')
			iT=i;
		i++;
	}
	if(iP==100||iT==100)
		return 0;
	if(iT<iP)
		return 0;
	i=0;
	while(i<iP)
	{
		sFor[i]=*(c+i);
		i++;
	}
	sFor[i]='\0';
	i++;
	while(i<iT)
	{
		sMid[i-iP-1]=*(c+i);
		i++;	
	}
	sMid[i-iP-1]='\0';
	i++;
	while(*(c+i)!='\0')
	{
		sBac[i-iT-1]=*(c+i);
		i++;
	}
	sBac[i-iT-1]='\0';
	if((iT-iP)==2){
		if(*(c+iP+1)=='A')
		{
			if(sBac[0]=='\0'&&sFor[0]=='\0')
				return 1;
			else if(!strcmp(sBac,sFor)){	
				if(Pan(sFor))
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
		
	}
    else {
		if(Pan(sFor)&&Pan(sMid)&&Pan(sBac))
		{
			strcpy(sTemp,c);
			L_sFor=strlen(sFor);
			L_sH=strlen(sTemp);
			sTemp[L_sH-L_sFor]='\0';
			i=iT;
			while(sTemp[i]!='\0')
			{
				sTemp[i-1]=sTemp[i];
				i++;			
			}
			sTemp[i-1]='\0';
			return Rec(sTemp);
		}
	else 
		return 0;	
	}
	
}






