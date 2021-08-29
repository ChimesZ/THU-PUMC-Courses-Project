#include "stdio.h"
#include "string.h"
int begin,end;
int seq(char str[100])
{
	int i,j,k,m=0,y=0,length=0;
	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]==32||str[i]=='\0')
		{
			for(j=m;j<i;j++)
			{
				if(str[j]==97)
				{
					if(i-m>length)
					{
						length=i-m;
						begin=m;
						end=i;
					}
					y=1;
				}
			}
			m=i+1;
		}
	}
	return(y);
}
void main()
{
	char str[100];
	int y,x;
	do{
	printf("请输入一串英文，字母之间用空格隔开，长度不超过100个字符：\n");
	gets(str);
	}while(strlen(str)>100);
	y=seq(str);
	if(y==0)
		printf("不具有含a的单词\n");
	else if(y==1);
	{
		for(x=begin;x<end;x++)
			printf("%c",str[x]);
		printf("\n");
	}
}