#include "stdio.h"
#include "math.h"
#define PI 3.1415926
int main()
{
	int i,m=1,j;
	double x=PI/6,result=0.0,n=1.0,k=1.0;
	for(i=1;i<=100;i++)
	{
			for(m=1;m<=2*i-1;m++)
			{
				n=n*m;
				k=k*x;
			}
		if(k/n<1e-6) break;
		result=result-(k/n)*pow(-1.0,i);
		n=1;
		k=1;
	}
	printf("结果为%lf,共展开了%d项\n",result,i);
		return 0;

}