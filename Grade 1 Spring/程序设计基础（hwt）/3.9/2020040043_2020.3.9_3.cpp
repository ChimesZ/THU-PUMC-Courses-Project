#include "stdio.h"
int main()
{
	int b,c,i=0;
	for(b=0;b<=50;b++)
	{
		for(c=0;c<=20;c++)
		{
				if(((2*b+5*c+(50-b-c))==100)&&((50-b-c)>=0))
					i++;
		}

	}
	printf("50个砝码存在的组合有%d个\n",i);
	i=0;
	for(c=0;c<=20;c++)
	{
		for(b=0;b<=30;b++)
		{
				if(((2*b+5*c+(30-b-c))==100)&&((30-b-c)>=0))
					i++;
		}

	}
	printf("30个砝码存在的组合有%d个\n",i);

}