#include "stdio.h"
#include "stdlib.h"

void PrintArray(int *a,int n)
{
	int i;
	for(i=0;i<=n;i++)
		printf("%4d",a[i]);
	printf("\n");
}

void sort(int *a,int *b,int *c,int m,int n) //a,b分别为待排序的两个数列；m,n分别为其长度; c为申请好长度的空指针
{
	int i=0,j=0,k=0;
	do
	{
		if(a[j]<=b[k])
		{
			c[i]=a[j];  //将较小的一项填入新数列
			j++;
			printf("第%d次排序结果为：\n",i+1);
			PrintArray(c,i);
			i++;
		}
		else if(a[j]>b[k])
		{
			c[i]=b[k];
			k++;
			printf("第%d次排序结果为：\n",i+1);
			PrintArray(c,i);
			i++;
		}
	}while(j!=m&&k!=n);
	if(j==m)   //将剩余的所有项填到新数列之后
	{
		for(k;k<n;k++,i++)
			c[i]=b[k];
	}
	if(k==n)
	{
		for(j;j<m;j++,i++)
			c[i]=a[j];
	}
	printf("将剩余项填入得：\n");
	PrintArray(c,i-1);
}

void main()
{
	int *a,*b,*c,m,n,i;

	printf("请输入有序（从小到大）数列1的长度：\n");
	scanf("%d",&m);
	a=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
	{
		begin1: 
		printf("请输入数列1的第%d位\n",i+1);
		scanf("%d",a+i);
		if(*(a+i)<*a)
		{
			printf("请输入按照大小顺序排序的数列！\n");
			goto begin1;
		}
	}

	printf("请输入有序（从小到大）数列2的长度：\n");
	scanf("%d",&n);
	b=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		begin2: 
		printf("请输入数列2的第%d位\n",i+1);
		scanf("%d",b+i);
		if(*(b+i)<*b)
		{
			printf("请输入按照大小顺序排序的数列！\n");
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

