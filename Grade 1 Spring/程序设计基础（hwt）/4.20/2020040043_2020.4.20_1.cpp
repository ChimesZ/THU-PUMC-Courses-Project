#include "stdio.h"
#include "string.h"
#include "stdlib.h"
void main()
{
	int i,j,k=0,n=1;
	char *c;
	char s;
	c=(char*)malloc(n*sizeof(char));
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®\n");
	do
	{
		s=getchar();
		k++;
		if(k>n)
			c=(char*)realloc(c,(++n)*sizeof(char));
		c[k-1]=s;
	}while(s!='\n');
	c[k]='\0';
	for(i=0;i<k;i++)
		printf("%c",*(c+k-i-1));
	printf("\n");


	

}