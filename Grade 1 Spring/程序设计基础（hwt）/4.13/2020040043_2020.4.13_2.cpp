#include "stdio.h"
char m[100]={0};
char hex(int n)
{
	int j=0;
	if(n>15)
		j+=hex(n/16);
	if(n%16<10)
		m[j]=n%16+'0';
	else if(n%16>=10)
		m[j]='a'+(n%16)%10;
	return(j+1);
}
void main()
{
	int n;
	do
	{
		printf("������һ��С��1000��������\n");
		scanf("%d",&n);
	}while(n<0||n>=1000);
	hex(n);
	printf("hex=%s\n",m);
}