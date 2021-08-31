#include "stdio.h"
long call(int n,long(*func)(int))
{
	return((*func)(n));
}
long f(int n)
{
	if(n<0)
		return 0;
	else if(n==0)
		return 1;
	else if(n==1)
		return 2;
	else if(n>1) return
		2*f(n-1)+f(n-2);
}
long g(int n)
{
	if(n<0)
		return 0;
	else if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else if(n>1) return
		2*g(n-2)+g(n-1);
}
void main()
{
	int i,m;
	long (*result[2])(int); 
	begin:
	do
	{
		printf("请输入需要计算的N的大小（N>=0）：\n");
		scanf("%d",&i);
	}while(i<0);
	result[0]=f;
	result[1]=g;
	do
	{
		printf("请输入要计算的数列，数列一请输入1；数列二请输入2；都输出请输入3\n");
		scanf("%d",&m);
	}while(m!=1&&m!=2&&m!=3);
	switch(m)
	{
		case 1: 
			printf("数列1结果为%ld\n",call(i,result[0]));break;
		case 2: 
			printf("数列2结果为%ld\n",call(i,result[1]));break;
		case 3: 
			{printf("数列1结果为%ld\n",call(i,result[0]));
			printf("数列2结果为%ld\n",call(i,result[1]));break;}

	}
	goto begin;
}