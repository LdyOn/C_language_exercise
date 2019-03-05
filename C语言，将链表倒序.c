#include <stdio.h>
struct NODE
{
	int date;
	struct NODE *next;

}
int main()
{


	return 0;
}
struct NODE* InvertedOrder(struct NODE **head)
{
	struct NODE  *pEnd;
	struct NODE *thead;
	struct NODE *newEND,*;
	pEnd=*head;
	while(pEnd->next!=NULL)
		pEnd=pEnd->next;
	if(pEnd==*head)
		return;
	else 
	{thead=pEnd;newEND=pEnd;}

	while(pEnd!=*head)
	{	
		pEND=*head;
		while(pEnd->next!=NULL)
			pEnd=pEnd->next;
		newEND->next=pEnd;
		newEND=pEnd;
	}
	pEnd->next=NULL;
	*head=thead;
}