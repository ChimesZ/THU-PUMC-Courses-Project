#include "stdio.h"
#include "string.h"
void turn(char str[100])
{
	int i,j=0;
	for(i=0;i<20;i=i+1)
	{
		if(str[i]=='i'&&str[i+1]=='s')
		{
			str[i]='b';
			str[i+1]='e';
			j=1;
		}
	}
	if(j==0)
		printf("������is��\n");
	printf("%s\n",str);
}
int main()
{
	int len;
	char str[100];
	a:
	printf("������һ��Ӣ���ַ���\n");
	scanf("%s",str);
	len=strlen(str);
	if(len<=20)
		turn(str);
	else
	{
		printf("���볬��20�����������룡\n");
		goto a;
	}
	return 0;
}