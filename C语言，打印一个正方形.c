#include<stdio.h>

int main()
{
	for(float y=0.0f;y>=-2.0f;y-=0.1f)
	{
		for(float x=0.0f;x<=2.0f;x+=0.05f)
		{
			putchar(x>=1&&x<=2&&y<=-1&&y>=-2?'*':' ');
		
		}
		putchar('\n');
	
	}

	return 0;
}