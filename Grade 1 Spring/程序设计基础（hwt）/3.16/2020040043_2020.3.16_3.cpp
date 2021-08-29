#include "stdio.h"
#include "string.h"
int main()
{
	char str1[100],num[20],alph[20],c;
	int i=0,j=0,k=0,l=0,a=1,b=1,lennum,lenalph,lenstr1,m1,n1,temp1;
	printf("请输入20个（含）以内的字符\n");
	{
		while((c=getchar())!='\n'&&i<=20&&j<=20&&l<100)
			{
				str1[l++]=c;
				if((c>=48)&&(c<=57))
				{
					for(k=0;k<i;k++)
					{
						if(c!=num[k]) 
							{
								a=1;
									continue;}
						else if(num[k]==c) 
							{a=0;
							break;}
					}
					if(a==1) num[i++]=c;
				}
				else if(((c>=65)&&(c<=90))||((c>=97)&&(c<=122)))
			{	
				for(k=0;k<j;k++)
					{
						if(c!=alph[k]) 
							{
								b=1;
								continue;
							}
						else if(alph[k]==c) 
							{b=0;
							break;}
					}
					if(b==1) alph[j++]=c;

			}
				else str1[l++]=c;
		}
	}
		num[i]='\0';
		alph[j]='\0';
		str1[l]='\0';
		lenstr1=strlen(str1);
		if(lenstr1>20) {printf("输入错误，请输入20以内的字符串\n");goto end;}
	lennum=strlen(num);
	lenalph=strlen(alph);
	for(m1=0;m1<lennum-1;m1++)
	{
		for(n1=0;n1<lennum-1;n1++)
		{
			if(num[n1]>num[n1+1])
			{
				temp1=num[n1];
				num[n1]=num[n1+1];
				num[n1+1]=temp1;
			}
		}
	}
	printf("数字排列的结果为\n");
	for(n1=0;n1<lennum;n1++) { printf("%c",num[n1]);}
	printf("\n");
	for(m1=0;m1<lenalph-1;m1++)
	{
		for(n1=0;n1<lenalph-1;n1++)
		{
			if(alph[n1]>alph[n1+1])
			{
				temp1=alph[n1];
				alph[n1]=alph[n1+1];
				alph[n1+1]=temp1;
			}
		}
	}
	printf("字母排列的结果为\n");
	for(n1=0;n1<lenalph;n1++) { printf("%c",alph[n1]);}
	printf("\n");
end:
	return 0;
}