/*������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�
�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
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
	printf("������Ҫ�����ַ���������");
	scanf("%d",&n);
	getchar();
	printf("�����ַ������س�����\n");
	for(i=0;i<n;i++)
		gets(a[i]);
	printf("�жϽ�����£�\n");
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






