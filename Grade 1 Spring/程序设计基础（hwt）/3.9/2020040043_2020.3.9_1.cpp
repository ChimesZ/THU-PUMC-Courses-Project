#include "stdio.h"
int main()
{
	int n;
	float result,i;
	printf("������������n\n");
	scanf("%d",&n);
	if(n>0)
	{   result=0.0;
		for(i=1.0;i<=n;i++)
		{
			result+=((i*i)/(i+1.0));}
		printf("���Ϊ  %f\n",result);
	
	}
	else 
	printf("�������");
	return 0;

}