#include<stdio.h>
#include<math.h>
int main()
{
	float a,A,V,S;
	printf("������߳�\n");
	scanf("%f",&a);
	A=sqrt(3.0)/4*a*a;
	V=A*a;
	S=2*A+3*a*a;
	printf("����׶���Ϊ%.3f,����׶�����Ϊ%.3f\n",S,V);
}