#include "stdio.h"
int main()
{char c;
int a=0,b=0,d=0,e=0;
printf("������һ���ַ���������ɺ�ʹ��Ctrl+Z��������\n");
	do
	{
	c=getchar();
	if((c>=48)&&(c<=57))
		a=a++;//������Ŀ
	else if(((c>=65)&&(c<=90))||((c>=97)&&(c<=122)))
		b=b++;//��ĸ��Ŀ
	else if(c==32)
		d=d++;//�ո���Ŀ
	}while(c!=EOF);
printf("���ֵ���ĿΪ%d,\n��ĸ����ĿΪ%d,\n�ո����ĿΪ%d\n",a,b,d);
return 0;
}