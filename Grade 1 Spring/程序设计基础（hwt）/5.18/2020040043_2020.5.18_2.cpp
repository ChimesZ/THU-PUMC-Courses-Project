#include "stdio.h"
#include "string.h"

struct string 
{
	int len;
	int space;
	int alph;
	int num;
};

void comp(struct string a,struct string b)
{
	if(a.len==b.len)
	printf("���ַ���������ͬ\n");
	else
	printf("���ַ������Ȳ�ͬ\n");
	if(a.space==b.space)
	printf("���ַ����ո�����ͬ\n");
	else
	printf("���ַ����ո�����ͬ\n");
	if(a.alph==b.alph)
	printf("���ַ�����ĸ����ͬ\n");
	else
	printf("���ַ�����ĸ����ͬ\n");
	if(a.num==b.num)
	printf("���ַ�����������ͬ\n");
	else
	printf("���ַ�����������ͬ\n");
}

void record(char *c,struct string *a,int n)
{
	int i=0,len=0,space=0,alph=0,num=0;
	for(i=0;i<n;i++)
	{
		if(c[i]==32)
			space++;
		else if(c[i]>='0'&&c[i]<='9')
			num++;
		else if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))
			alph++;
	}
	a->len=n;
	a->num=num;
	a->space=space;
	a->alph=alph;
}

void main()
{
	char a[100],b[100];
	struct string a1,b1;
	int len1,len2;
	printf("�������һ���ַ�����\n");
	gets(a);fflush(stdin);
	printf("������ڶ����ַ�����\n");
	gets(b);fflush(stdin);
	len1=strlen(a);
	len2=strlen(b);
	record(a,&a1,len1);
	record(b,&b1,len2);
	comp(a1,b1);
}