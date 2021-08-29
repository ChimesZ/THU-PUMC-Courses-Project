#include "stdio.h"
int main()
{
	int n;
	float result,i;
	printf("请输入正整数n\n");
	scanf("%d",&n);
	if(n>0)
	{   result=0.0;
		for(i=1.0;i<=n;i++)
		{
			result+=((i*i)/(i+1.0));}
		printf("结果为  %f\n",result);
	
	}
	else 
	printf("输入错误");
	return 0;

}