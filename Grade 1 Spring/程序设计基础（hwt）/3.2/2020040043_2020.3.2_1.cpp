#include "stdio.h"
int main()
{float a,b,c,d,result1,result2,result;
	printf("�������ĸ�������ͬ��ʵ�����ÿո����\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	if((a==0)&&(b==0)&&(c==0)&&(d==0))
	{}
	else
	{if((a>=-1e6)&&(a<=1e6)&&(b>=-1e6)&&(b<=1e6)&&(c>=-1e6)&&(c<=1e6)&&(d>=-1e6)&&(d<=1e6))
		{result1=a>=b? a:b;
		 result2=c>=d? c:d;
		 result=result1>=result2? result1:result2;
		 printf("������Ϊ%f\n",result);
		}
	else  printf("����\n");
	}




}