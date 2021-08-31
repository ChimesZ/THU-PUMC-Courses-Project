#include "stdio.h"
int main()
{
	int i,j,k,result;
	printf("三位数水仙花数为：\n");
	for(i=1;i<=9;i++)
		for(j=0;j<=9;j++)
			for(k=0;k<=9;k++)
			{
				result=i*i*i+j*j*j+k*k*k;
				if((result==(i*100+j*10+k))&&(result<1000))
					printf("%d\n",result);
			}
	return 0;			
}