#include "stdio.h"
#include "string.h"
int main()
{char c,ch[100];int i=0,n,m;
 printf("ÇëÊäÈë×Ö·û´®\n");
 while((c=getchar())!='\n')
	 {if(!((c>=97)&&(c<=122))) continue;
		{c=c-32;
		ch[i++]=c;
		}
	 }
ch[i]='\0';
n=strlen(ch);
for(m=n-1;m>=0;m--)
{printf("%c",ch[i=m]);}
return 0;
	}
	
