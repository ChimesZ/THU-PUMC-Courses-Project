#include "stdio.h"
long fac(int n)
{
	if(n==1)
		return 1;
	else
		return
		fac(n-1)*n;
}
long ind(int n)
{
	int i;
	long f=1;
			for(i=1;i<=n;i++)
		{
			f*=2;
		}
	return f;
}
void main()
{
	int n,i;
	long sum=0;
	do
	{
		printf("请输入一个大于0且小于5的整数\n");
		scanf("%d",&n);
	}while(n<0||n>4);
	for(i=1;i<=n;i++)
		sum=sum+fac(i)*ind(i);
	printf("S=%ld\n",sum);
}