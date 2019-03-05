#include<stdio.h>

int  main()
{	
	for(float y=0.0f;y>=-5.0f;y-=0.1f)
	{
		for(float x=0.0f;x<=5.0f;x+=0.05f)
		{
			float a=x-3.0;
			float b=y+3.0;
			putchar(a*a+b*b<=4.0?'*':' ');
		
		}
		putchar('\n');
	
	}
	
	return 0;
}