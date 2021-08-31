#include "stdio.h"
int main()
{char c;
int a=0,b=0,d=0,e=0;
printf("请输入一行字符（输入完成后使用Ctrl+Z结束）：\n");
	do
	{
	c=getchar();
	if((c>=48)&&(c<=57))
		a=a++;//数字数目
	else if(((c>=65)&&(c<=90))||((c>=97)&&(c<=122)))
		b=b++;//字母数目
	else if(c==32)
		d=d++;//空格数目
	}while(c!=EOF);
printf("数字的数目为%d,\n字母的数目为%d,\n空格的数目为%d\n",a,b,d);
return 0;
}