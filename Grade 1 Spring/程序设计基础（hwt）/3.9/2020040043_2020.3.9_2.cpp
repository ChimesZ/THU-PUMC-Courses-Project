#include "stdio.h"
int main()
{
	int n,i;
	float h=80;
	printf("�����뵯������������ʮ��̨�ף�:\n");
	scanf("%d",&n);
	if(n>0&&n<11)
	{
		for(i=1;i<=n;i++)
		{
			h=(h+20)*2/3;
		}
		printf("�����߶�Ϊ��%.2fcm\n",h);
	}
	else printf("�����������������\n");
	return 0;
}