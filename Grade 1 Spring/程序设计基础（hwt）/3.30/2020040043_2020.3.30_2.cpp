#include "stdio.h"
#include "string.h"
void turn(char str[100])
{
	int i,j=0;
	for(i=0;i<20;i=i+1)
	{
		if(str[i]=='i'&&str[i+1]=='s')
		{
			str[i]='b';
			str[i+1]='e';
			j=1;
		}
	}
	if(j==0)
		printf("不存在is！\n");
	printf("%s\n",str);
}
int main()
{
	int len;
	char str[100];
	a:
	printf("请输入一个英文字符串\n");
	scanf("%s",str);
	len=strlen(str);
	if(len<=20)
		turn(str);
	else
	{
		printf("输入超过20，请重新输入！\n");
		goto a;
	}
	return 0;
}