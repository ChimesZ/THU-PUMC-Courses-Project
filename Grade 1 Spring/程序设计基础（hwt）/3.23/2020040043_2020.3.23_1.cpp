#include "stdio.h"
int main ()
{
	int i,j,k,m,a[6];
	a[0]=6;a[5]=1; //·ÖÎöµÃ
	for(i=1;i<=4;i++)
	{
		a[i]=5;
		for(j=1;j<=4;j++)
		{
			if(j==i) continue;
			else a[j]=4;
			for(k=1;k<=4;k++)
			{
				if((k==j)||(k==i)) continue;
				else a[k]=3;
				for(m=1;m<=4;m++)
				{
					if((m==k)||(m==j)||(m==i)) continue;
					else a[m]=2;
					if(a[1]>a[2]&&a[3]>a[4]&&a[1]>a[4])
					printf("%d,%d,%d\n%d,%d,%d\n\n",a[0],a[1],a[2],a[3],a[4],a[5]);	
				}
			}
		}
	}
}