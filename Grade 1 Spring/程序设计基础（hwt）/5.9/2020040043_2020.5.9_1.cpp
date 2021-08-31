#include "stdio.h"
#include "stdlib.h"

void PrintArray(int *a,int n)
{
	int i;
	for(i=0;i<=n;i++)
		printf("%4d",a[i]);
	printf("\n");
}

void sort(int *a,int *b,int *c,int m,int n) //a,b�ֱ�Ϊ��������������У�m,n�ֱ�Ϊ�䳤��; cΪ����ó��ȵĿ�ָ��
{
	int i=0,j=0,k=0;
	do
	{
		if(a[j]<=b[k])
		{
			c[i]=a[j];  //����С��һ������������
			j++;
			printf("��%d��������Ϊ��\n",i+1);
			PrintArray(c,i);
			i++;
		}
		else if(a[j]>b[k])
		{
			c[i]=b[k];
			k++;
			printf("��%d��������Ϊ��\n",i+1);
			PrintArray(c,i);
			i++;
		}
	}while(j!=m&&k!=n);
	if(j==m)   //��ʣ����������������֮��
	{
		for(k;k<n;k++,i++)
			c[i]=b[k];
	}
	if(k==n)
	{
		for(j;j<m;j++,i++)
			c[i]=a[j];
	}
	printf("��ʣ��������ã�\n");
	PrintArray(c,i-1);
}

void main()
{
	int *a,*b,*c,m,n,i;

	printf("���������򣨴�С��������1�ĳ��ȣ�\n");
	scanf("%d",&m);
	a=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
	{
		begin1: 
		printf("����������1�ĵ�%dλ\n",i+1);
		scanf("%d",a+i);
		if(*(a+i)<*a)
		{
			printf("�����밴�մ�С˳����������У�\n");
			goto begin1;
		}
	}

	printf("���������򣨴�С��������2�ĳ��ȣ�\n");
	scanf("%d",&n);
	b=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		begin2: 
		printf("����������2�ĵ�%dλ\n",i+1);
		scanf("%d",b+i);
		if(*(b+i)<*b)
		{
			printf("�����밴�մ�С˳����������У�\n");
			goto begin2;
		}
	}

	c=(int *)malloc((n+m)*sizeof(int));
	sort(a,b,c,m,n);
	free(a);
	a=NULL;
	free(b);
	b=NULL;
	free(c);
	c=NULL;
}

