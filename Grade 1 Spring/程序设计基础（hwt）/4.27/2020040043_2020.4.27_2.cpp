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
		printf("��������Ҫ�����N�Ĵ�С��N>=0����\n");
		scanf("%d",&i);
	}while(i<0);
	result[0]=f;
	result[1]=g;
	do
	{
		printf("������Ҫ��������У�����һ������1�����ж�������2�������������3\n");
		scanf("%d",&m);
	}while(m!=1&&m!=2&&m!=3);
	switch(m)
	{
		case 1: 
			printf("����1���Ϊ%ld\n",call(i,result[0]));break;
		case 2: 
			printf("����2���Ϊ%ld\n",call(i,result[1]));break;
		case 3: 
			{printf("����1���Ϊ%ld\n",call(i,result[0]));
			printf("����2���Ϊ%ld\n",call(i,result[1]));break;}

	}
	goto begin;
}