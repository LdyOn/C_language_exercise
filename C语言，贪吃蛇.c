#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<time.h>
#include<stdlib.h>
#define RIGHT 100
#define LEFT  97
#define UP   119
#define DOWN  115

struct NODE 
{
	int x;
	int y;
	struct NODE *next;

};

void GameOver(struct NODE *head);
void ShowSnake(struct NODE *head);
char Status(struct NODE *head,struct NODE *food);
void Snake();
void Delay(int n);
void PrintChar(char *ch,UINT count,UINT x,UINT y);
int Start();
void Disapper(struct NODE *head);
void  ProduceFood(struct NODE *food,struct NODE *head);
int level;
int main()
{
	system("title 贪吃蛇");
	level=Start();
	Snake();
	return 0;
}
void PrintChar(char *ch,UINT count,UINT x,UINT y)  //在坐标(x,y)处输出字符串ch,ch里有count个字符
{
	 HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD pos;
	 ULONG unuse;
	 pos.X=x;
	 pos.Y=y;
	 CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
	 GetConsoleScreenBufferInfo(h, &bInfo );
	 WriteConsoleOutputCharacterA(h,ch,count,pos,&unuse);
}

void Snake()
{
	int tx1,ty1,tx2,ty2;

	char ch=100;        //标记方向
	char last;
	char stau;          //标记蛇的状态，正常‘N’，死亡‘D’，进食‘E’
	struct NODE *pHead;
	struct NODE *food,*temp1,*temp2,*temp3;
	food=(struct NODE*)malloc(sizeof(struct NODE));
	pHead=(struct NODE*)malloc(sizeof(struct NODE));
	pHead->next=NULL;
	food->next=NULL;
	srand((unsigned)time( NULL ));
	pHead->x=rand()%80;
	srand((unsigned)time( NULL ));
	pHead->y=rand()%20;
	ProduceFood(food,pHead);
	while(1)
	{
		last=ch;
		switch(ch)
		{	
		case 100: //右
			while(!kbhit())
			{
				pHead->x++;
		
				stau=Status(pHead,food);
				if('D'==stau)
				{
					for(int i=0;i<1000000000;i++);
					GameOver(pHead);
				}
				else if('E'==stau)
				{
					PrintChar(" ",1,food->x,food->y);
					pHead->x--;
					temp3=(struct NODE*)malloc(sizeof(struct NODE));
					temp3->next=NULL;							
					Disapper(pHead);
		
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					
					}
					temp3->x=tx1;   
					temp3->y=ty1;
					pHead->x++;
					temp2->next=temp3;				
					ShowSnake(pHead);
					ProduceFood(food,pHead);
				}
				else
				{
					pHead->x--;
					Disapper(pHead);
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					}
					pHead->x++;

					ShowSnake(pHead);
			
				}
				Delay(level);
			}
			break;
		case 97:            //左
			while(!kbhit())
			{
				pHead->x--;
		
				stau=Status(pHead,food);
				if('D'==stau)
				{
					for(int i=0;i<1000000000;i++);
					GameOver(pHead);
				}
				else if('E'==stau)
				{
					PrintChar(" ",1,food->x,food->y);
					pHead->x++;
					
					temp3=(struct NODE*)malloc(sizeof(struct NODE));
					temp3->next=NULL;
								
					Disapper(pHead);
		
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					}
					temp3->x=tx1;   
					temp3->y=ty1;
					pHead->x--;
					temp2->next=temp3;
					ShowSnake(pHead);
					ProduceFood(food,pHead);

				}
				else
				{
					pHead->x++;
					Disapper(pHead);
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					}
					pHead->x--;
					ShowSnake(pHead);
			
				}
				Delay(level);
			}
			break;
		case  119:            //上
			while(!kbhit())
			{
				pHead->y--;
		
				stau=Status(pHead,food);
				if('D'==stau)
				{
					for(int i=0;i<1000000000;i++);
					GameOver(pHead);
				}
				else if('E'==stau)
				{
					PrintChar(" ",1,food->x,food->y);
					pHead->y++;
					
					temp3=(struct NODE*)malloc(sizeof(struct NODE));
					temp3->next=NULL;								
					Disapper(pHead);
		
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					
					}
					temp3->x=tx1;   
					temp3->y=ty1;
					pHead->y--;
					temp2->next=temp3;
					ShowSnake(pHead);
					ProduceFood(food,pHead);

				}
				else
				{
					pHead->y++;
					Disapper(pHead);
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					
					}
					pHead->y--;
					ShowSnake(pHead);
			
				}
				Delay(level);
			}
			break;
		case  115:           //下
			while(!kbhit())
			{
				pHead->y++;
		
				stau=Status(pHead,food);
				if('D'==stau)
				{
					for(int i=0;i<1000000000;i++);
					GameOver(pHead);
				}
				else if('E'==stau)
				{
					PrintChar(" ",1,food->x,food->y);
					pHead->y--;
					temp3=(struct NODE*)malloc(sizeof(struct NODE));
					temp3->next=NULL;
								
					Disapper(pHead);
		
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					
					}
					temp3->x=tx1;   
					temp3->y=ty1;
					pHead->y++;
					temp2->next=temp3;
					ShowSnake(pHead);
					ProduceFood(food,pHead);

				}
				else
				{
					pHead->y--;
					Disapper(pHead);
					temp1=pHead->next;
					temp2=pHead;
					tx2=temp2->x;ty2=temp2->y;
					while(temp1!=NULL)
					{
						tx1=temp1->x;
						ty1=temp1->y;
						temp1->x=tx2;
						temp1->y=ty2;
						tx2=tx1;ty2=ty1;
						temp2=temp1;
						temp1=temp1->next;
					
					}
					pHead->y++;
					ShowSnake(pHead);
			
				}
				Delay(level);
			}
			break;
		}
		while(kbhit())
			ch=getch();
		if(pHead->next!=NULL)
		{
		
			if(last==100&&ch==97)
				ch=last;
			if(last==97&&ch==100)
				ch=last;
			if(last==115&&ch==119)
				ch=last;
			if(last==119&&ch==115)
				ch=last;
		
		}

	}

}
void Delay(int n)  //延时函数
{
	long i,j;
	if(1==n)
	{	
		i=100000000;
		j=100000000;
		while(i>0)i--;
		while(j>0)j--;
	}
	else if(3==n)
	{
		i=30000000;
		while(i>0)
			i--;	
	}
	else
	{
		i=100000000;
		while(i>0)
			i--;	
	}

}
int Start()
{
	char ch;
	PrintChar("Gluttonous  Snake",19,41,10);
	PrintChar("Seclet Level",15,41,12);	
	PrintChar("1 Simple",10,41,13);		
	PrintChar("2 Middle",10,41,14);
	PrintChar("3 Difficult",10,41,15);
	while(!kbhit());
	while(kbhit())ch=getch();
	system("cls");
	return  (ch-48);
}
char Status(struct NODE *head,struct NODE *food)
{
	struct NODE *t;
	t=head->next;
	if(head->x>100||head->x<0||head->y<0||head->y>30)//撞到边界
		return 'D';
	if(head->x==food->x&&head->y==food->y)   // eate food
		return 'E';
	while(t!=NULL)            
	{
		if(t->x==head->x&&t->y==head->y)
			break;
		t=t->next;
	}
	if(t!=NULL)
		return 'D';                //eate self
	return 'N';                    //normal
}
void ShowSnake(struct NODE *head)
{
	struct NODE *t;
	t=head;
	while(t!=NULL)
	{
		PrintChar("*",1,t->x,t->y);
		t=t->next;
	}
}	
void GameOver(struct NODE *head)
{
	struct NODE *a,*b;
	a=head;
	while(a!=NULL)
	{
		b=a->next;
		free(a);
		a=b;
	}
	system("cls");
	PrintChar("Game  Over",11,42,14);
	exit(1);

}
void Disapper(struct NODE *head)
{
	struct NODE *t;
	t=head;
	while(t!=NULL)
	{
		PrintChar(" ",1,t->x,t->y);
		t=t->next;
	
	}

}
void  ProduceFood(struct NODE *food,struct NODE *head)
{
	struct NODE *tem;
	tem=head;
	int i;	
	do
	{
		i=0;
		srand((unsigned)time( NULL ));
		food->x=rand()%100;
		srand((unsigned)time( NULL ));
		food->y=rand()%30;
		while(tem!=NULL)
		{
			if(tem->x==food->x&&tem->y==food->y)
				break;
			tem=tem->next;	
		}
		if(tem!=NULL)
			i=1;
	}while(i);		
	PrintChar("0",1,food->x,food->y);
}