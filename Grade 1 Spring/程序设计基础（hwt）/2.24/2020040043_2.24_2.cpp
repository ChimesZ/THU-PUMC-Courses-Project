#include<stdio.h>
#include<math.h>
int main()
{
	float a,A,V,S;
	printf("请输入边长\n");
	scanf("%f",&a);
	A=sqrt(3.0)/4*a*a;
	V=A*a;
	S=2*A+3*a*a;
	printf("三棱锥面积为%.3f,三棱锥的体积为%.3f\n",S,V);
}