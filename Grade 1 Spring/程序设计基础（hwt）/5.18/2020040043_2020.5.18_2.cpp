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
	printf("两字符串长度相同\n");
	else
	printf("两字符串长度不同\n");
	if(a.space==b.space)
	printf("两字符串空格数相同\n");
	else
	printf("两字符串空格数不同\n");
	if(a.alph==b.alph)
	printf("两字符串字母数相同\n");
	else
	printf("两字符串字母数不同\n");
	if(a.num==b.num)
	printf("两字符串数字数相同\n");
	else
	printf("两字符串数字数不同\n");
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
	printf("请输入第一个字符串：\n");
	gets(a);fflush(stdin);
	printf("请输入第二个字符串：\n");
	gets(b);fflush(stdin);
	len1=strlen(a);
	len2=strlen(b);
	record(a,&a1,len1);
	record(b,&b1,len2);
	comp(a1,b1);
}