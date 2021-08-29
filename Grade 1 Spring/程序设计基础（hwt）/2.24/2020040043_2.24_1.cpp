#include "math.h"
#include "stdio.h"
int main()
{
	float a1,a2,b1,b2;
	printf("请分别输入复数1和复数2的实部与虚部，中间用空格隔开\n");
	scanf("%f%f%f%f",&a1,&b1,&a2,&b2);
	float aa,bb;
	aa=a1+a2;
	bb=b1+b2;
	printf("两复数和为%.3f+%.3fi\n",aa,bb);
	aa=a1-a2;
	bb=b1-b2;
	printf("两复数差为%.3f+%.3fi\n",aa,bb);
	aa=(a1*a2)-(b1*b2);
	bb=(b1*a2)+(a1*b2);
	printf("两复数积为%.3f+%.3fi\n",aa,bb);
	aa=((a1*a2)+(b1*b2))/((a2*a2)+(b2*b2));
	bb=((b1*a2)-(a1*b2))/((a2*a2)+(b2*b2));
	printf("两复数商为%.3f+%.3fi\n",aa,bb);
}