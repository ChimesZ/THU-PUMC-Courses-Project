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
	printf("������һ��Ӣ�ģ���ĸ֮���ÿո���������Ȳ�����100���ַ���\n");
	gets(str);
	}while(strlen(str)>100);
	y=seq(str);
	if(y==0)
		printf("�����к�a�ĵ���\n");
	else if(y==1);
	{
		for(x=begin;x<end;x++)
			printf("%c",str[x]);
		printf("\n");
	}
}