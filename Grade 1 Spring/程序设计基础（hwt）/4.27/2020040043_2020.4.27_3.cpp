#include "stdio.h"
#include "stdlib.h"
void main()
{
	char c[4];
	char *p=NULL;
	int n,i,k;
	printf("����һ���ַ������ַ��������������ַ�����β�ַ���Ϊ��д��ĸ��Сд��ĸ�����֣��м��ַ�Ϊ�����š���\n");
	scanf("%s",c);
	if((((c[0]>='0'&&c[0]<='9')&&(c[2]>='0'&&c[2]<='9'))||((c[0]>='a'&&c[0]<='z')&&(c[2]>='a'&&c[2]<='z'))||((c[0]>='A'&&c[0]<='Z')&&(c[2]>='A'&&c[2]<='Z')))&&(c[0]<c[2])&&c[1]=='-')
	{
		n=c[2]-c[0]+2;
		p=(char *)malloc((n)*sizeof(char));
		for(i=c[0],k=0;i<=c[2];i++,k++)
		{*(p+k)=(char)i;}
		*(p+k)='\0';
		printf("չ�����Ϊ%s\n",p);
	}
	else
		printf("�����������������");
free(p);
p=NULL;

}