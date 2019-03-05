#include<stdlib.h>
#include<stdio.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
#include<process.h>
void PrintChar(char *ch,UINT count,UINT x,UINT y);
void Operate();
void Map();
void ChangeNum(char a[4],int n);
void CreatNum(int a[][4],struct NODE *pHead);
void Show(int a[][4]);
void Insert(struct NODE *pHead,int a,int b);
void Delete(struct NODE  *pHead,int a,int b );
struct NODE
{
	int x;
	int y;
	struct NODE *next;
};
int iCount=16;
int main()
{
	Map();	
	Operate();
	
	return 0;
}
void ChangeNum(char a[4],int n)
{
	int temp;
	int i=3;
	if(n!=0)
	{
		while(n!=0)
		{
			temp=n/10;
			a[i]=n-temp*10+48;
			n=temp;
			i--;
		}
		while(i>=0)
		{
			a[i]=' ';
			i--;		
		}
	}
	else
	{
		for(i=0;i<4;i++)
			a[i]=' ';	
	}

		
}
void Map()
{
	int i;
	int j;
	for(i=0;i<=8;i+=2)
	{
		for(j=0;j<=20;j++)
			PrintChar("*",1,j,i);
	}
	for(i=0;i<=20;i+=5)
	{
		for(j=0;j<=8;j++)
			PrintChar("|",1,i,j);	
	}
}
void PrintChar(char *ch,UINT count,UINT x,UINT y)  
{                                                   /*在坐标(x,y)处输出字符串ch,
                                                     ch里有count个字符*/
	 HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD pos;
	 ULONG unuse;
	 pos.X=x;
	 pos.Y=y;
	 CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
	 GetConsoleScreenBufferInfo(h, &bInfo );
	 WriteConsoleOutputCharacterA(h,ch,count,pos,&unuse);
}
void Operate()
{
	int a[4][4];
	int (*p)[4];

	int i,j,k,h;
	struct NODE *pHead,*pEnd,*t;
	pHead=pEnd=(struct NODE*)malloc(sizeof(struct NODE));//建立链表保存没有数字的坐标

	char ch;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			a[i][j]=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			t=(struct NODE*)malloc(sizeof(struct NODE));
			t->x=i;
			t->y=j;
			pEnd->next=t;
			pEnd=t;
		}
	pEnd->next=NULL;
	CreatNum(a,pHead);
	CreatNum(a,pHead);
	Show(a);
	

	while(1)
	{
		while(!kbhit());
		while(kbhit())
			ch=getch();
	
		switch(ch)
		{
		case 77:       //right
			p=&a[0];
			for(i=0;i<4;i++)    //MERGE
			{
				for(j=3;j>0;j--)
				{
					h=j-1;
					if(*(*(p+i)+j))
					{while(h>=0&&*(*(p+i)+h)==0)h--;
					if(h>=0)
					{
						if(*(*(p+i)+h)==*(*(p+i)+j))
						{
						
							*(*(p+i)+j)*=2;
							*(*(p+i)+h)=0;
							iCount++;
							Insert(pHead,i,h);
						
						}
					
					}
					}
				
				}							
			}
			for(i=0;i<4;i++)       //MOVE
			{
				for(j=2;j>=0;j--)
				{
					k=0;
					if(*(*(p+i)+j)!=0)
					{
						for(h=j+1;h<=3;h++)
							if(*(*(p+i)+h)==0)
							{k++;}
						if(k)
						{
							*(*(p+i)+j+k)=*(*(p+i)+j);
							*(*(p+i)+j)=0;
							Delete(pHead,i,j+k);
							Insert(pHead,i,j);
							
						}						
					}
				
				}
						
			}			
			Show(a);
			break;
		case 75:              //left
			p=&a[0];
			for(i=0;i<4;i++)    //MERGE
			{
				for(j=3;j>0;j--)
				{
					h=j-1;
					if(*(*(p+i)+j))
					{
						while(h>=0&&*(*(p+i)+h)==0)h--;
						if(h>=0)
						{
							if(*(*(p+i)+h)==*(*(p+i)+j))
							{
								
								*(*(p+i)+j)*=2;
								*(*(p+i)+h)=0;
								iCount++;
								Insert(pHead,i,h);
						
							}
					
						}
					}
				}							
			}
			for(i=0;i<4;i++)  //Move
			{
				for(j=1;j<4;j++)
				{
					k=0;
					if(*(*(p+i)+j))
					{
						for(h=j-1;h>=0;h--)
							if(*(*(p+i)+h)==0)
							{k++;}
							if(k)
							{								
								*(*(p+i)+j-k)=*(*(p+i)+j);
								*(*(p+i)+j)=0;
								Delete(pHead,i,j-k);
								Insert(pHead,i,j);								
							}
					
					}
				
				
				}
			
			
			
			}
			Show(a);
			break;
		case 72:              //up
			for(j=0;j<4;j++)  //Merge
			{
				for(i=0;i<3;i++)
				{
					h=i+1;
					if(a[i][j])
					{
						while(h<4&&a[h][j]==0)h++;
						if(h<4)
						{
							if(a[i][j]==a[h][j])
							{
								
								a[i][j]*=2;
								a[h][j]=0;
								iCount++;
								Insert(pHead,h,j);
							
							}
						
						}
					
					}				
				}
					
			}
			for(j=0;j<4;j++) //Move
			{
				for(i=1;i<4;i++)
				{
					k=0;
					if(a[i][j])
					{
						for(h=i-1;h>=0;h--)
							if(a[h][j]==0)
							{k++;}
						if(k)
						{
							a[i-k][j]=a[i][j];
							a[i][j]=0;
							Delete(pHead,i-k,j);
							Insert(pHead,i,j);
						
						}
					
					}
				
				}
			
			
			}
			Show(a);
			break;
		case 80:               //down
			for(j=0;j<4;j++)   //Merge
			{
				for(i=0;i<4;i++)
				{
					h=i+1;
					if(a[i][j])
					{
						while(h<4&&a[h][j]==0)h++;
						if(h<4)
						{
							if(a[i][j]==a[h][j])
							{
								
								a[i][j]*=2;
								a[h][j]=0;
								iCount++;
								Insert(pHead,h,j);
							
							}
						
						}
					
					}				
				}
					
			}
			for(j=0;j<4;j++)
			{
				for(i=2;i>=0;i--)
				{
					k=0;
					if(a[i][j])
					{
						for(h=i+1;h<4;h++)
							if(a[h][j]==0)
							{k++;}
						if(k)
						{
							a[i+k][j]=a[i][j];
							a[i][j]=0;
							Delete(pHead,i+k,j);
							Insert(pHead,i,j);
						
						
						}
					
					
					}
				
				
				}
				
			}
			Show(a);
			break;
		}
		if(0==iCount)
		{system("cls");printf("GAME OVER  ");break;}

		CreatNum(a,pHead);
		Show(a);
	
	}


}
void CreatNum(int a[][4],struct NODE *pHead)
{
	int i=0;
	int b;
	int num;
	struct NODE *t,*t1;
	t=pHead;
	srand((unsigned)time( NULL ));
	num=rand()%100;
	if(num<90)
		num=2;
	else
		num=4;
	srand((unsigned)time( NULL ));
	b=rand()%iCount+1;
	while(i!=(b-1))
	{
		t=t->next;
		i++;
	}
	a[t->next->x][t->next->y]=num;
	t1=t->next;
	t->next=t1->next;
	free(t1);
	iCount--;
}
void Show(int a[][4])
{
	int i;
	int j;
	char p[4];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			ChangeNum(p,a[i][j]);
			PrintChar(p,4,5*j+1,2*i+1);
		
		}

}

void  Delete(struct NODE  *pHead,int a,int b )
{
	struct NODE *tq,*th;
	tq=pHead;
	th=pHead->next;
	while(th!=NULL)
	{
		if(th->x==a&&th->y==b)
			break;
		else
		{
			tq=tq->next;
			th=th->next;	
		}
	}
	tq->next=th->next;
	free(th);
}
void Insert(struct NODE *pHead,int a,int b)
{
	struct NODE *t;
	t=(struct NODE*)malloc(sizeof(struct NODE));
	t->x=a;
	t->y=b;
	t->next=pHead->next;
	pHead->next=t;
}