#include "stdio.h"
int main()
{
	int i,j,k,m,n,p,q,r=1,a[100],b[9];
	for(j=0,i=13;i<=31;i++,j++)
	{
		a[j]=i*i;
	}
	for(k=0;k<j-2;k++)
		for(m=k+1;m<j-1;m++)
			for(n=m+1;n<j;n++)
			{
				b[0]=(a[k]/100)%10;
				b[1]=(a[k]/10)%10;
				b[2]=a[k]%10;
				b[3]=(a[m]/100)%10;
				b[4]=(a[m]/10)%10;
				b[5]=a[m]%10;
				b[6]=(a[n]/100)%10;
				b[7]=(a[n]/10)%10;
				b[8]=a[n]%10;
				for(p=0;p<8;p++)
					for(q=p+1;q<9;q++)
					{
						if(b[p]==b[q]) {r=0; goto con;}	
					}
			if(r==1)
			printf("%d,%d,%d\n",a[k],a[m],a[n]);
			con: r=1;
			}
			
}