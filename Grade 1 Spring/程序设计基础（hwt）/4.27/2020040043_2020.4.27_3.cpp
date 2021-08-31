#include "stdio.h"
#include "stdlib.h"
void main()
{
	char c[4];
	char *p=NULL;
	int n,i,k;
	printf("输入一个字符串，字符串仅包含三个字符，首尾字符仅为大写字母或小写字母或数字，中间字符为“减号”符\n");
	scanf("%s",c);
	if((((c[0]>='0'&&c[0]<='9')&&(c[2]>='0'&&c[2]<='9'))||((c[0]>='a'&&c[0]<='z')&&(c[2]>='a'&&c[2]<='z'))||((c[0]>='A'&&c[0]<='Z')&&(c[2]>='A'&&c[2]<='Z')))&&(c[0]<c[2])&&c[1]=='-')
	{
		n=c[2]-c[0]+2;
		p=(char *)malloc((n)*sizeof(char));
		for(i=c[0],k=0;i<=c[2];i++,k++)
		{*(p+k)=(char)i;}
		*(p+k)='\0';
		printf("展开结果为%s\n",p);
	}
	else
		printf("输入错误，请重新输入");
free(p);
p=NULL;

}