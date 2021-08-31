#include "stdio.h"
#include "string.h"
void main(int argc,char *argv[])
{
	int i,j,sign,point;
	if(argc!=3)
		printf("Error\n");
	else
	{
		if(strlen(argv[1])<strlen(argv[2]))
			printf("Error\n");
		else
		{
			for(i=0;i<=(strlen(argv[1])-strlen(argv[2]));i++)
			{
				point=i;
				sign=1;
				for(j=0;j<strlen(argv[2]);j++,point++)
				{
					if(*(argv[1]+point)!=*(argv[2]+j))
					{
						sign=0;
						break;
					}
				}
					if(sign==1)
						break;
			}
			if(sign==1)
				printf("Find!");
			else
				printf("Not Find!");
		}
	}
}