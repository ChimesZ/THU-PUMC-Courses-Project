#include "stdio.h"
void main()
{
	char c[100];
	char *p1,*p2;
	int i,m,n,p,num=0,alph=0;
	p1=c;p2=c;
	begin:
	m=0,n=0,p=0;
	printf("������һ��ͬʱ���С�e���͡�k�����ַ���\n");
	scanf("%s",c);
	for(i=0;c[i]!='\0';i++)
	{
		if(c[i]=='e')
			m=1;
		else if(c[i]=='k')
			n=1;
		else if(c[i]>='0'&&c[i]<='9')
			p=1;
	}
	if(m==0||n==0)
		goto begin;
	if(p==0)
		printf("����û������\n");
	else if(p==1)
	{
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]>='0'&&c[i]<='9')
				num++;
		}
		printf("���о�������%d��\n",num);
	}
	for(i=0;c[i]!='e'&&c[i]!='k';i++)
		p1++;
	p1;
	for(i=0;c[i]!='\0';i++)
		p2++;
	p2--;
	if(*p1=='e') 
		for(p2;*p2!='k';p2--);
	else if(*p1=='k')
		for(p2;*p2!='e';p2--);
	p1++;
	for(p1;p1<p2;p1++)
	{
		if((*p1>='a'&&*p1<='z')||(*p1>='A'&&*p1<='Z'))
			alph++;
	}
	printf("e��k֮�����ĸ��%d��\n",alph);
}
