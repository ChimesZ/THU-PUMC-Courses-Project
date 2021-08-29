#include "stdio.h"
void main()
{
	char a[50],b[50],c[100];
	char *pa=a,*pb=b,*pc=c;
	int i;
	printf("ÇëÊäÈëÁ½¸ö×Ö·û´®£º\n");
	scanf("%s",a);
	scanf("%s",b);
	for(i=0;a[i]!='\0';i++)
		pa++;
	for(i=0;b[i]!='\0';i++)
	{
		*pa=b[i];pa++;
	}
	*pa='\0';
	for(i=0;a[i]!='\0';i++)
	{
		*pc=a[i];pc++;
	}
	*pc='\0';
	printf("%s",c);
}