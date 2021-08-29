#include "stdio.h"
int main()
{
	int n,i;
	float h=80;
	printf("请输入弹跳次数（共有十个台阶）:\n");
	scanf("%d",&n);
	if(n>0&&n<11)
	{
		for(i=1;i<=n;i++)
		{
			h=(h+20)*2/3;
		}
		printf("弹跳高度为：%.2fcm\n",h);
	}
	else printf("输入错误，请重新输入\n");
	return 0;
}