#include "stdio.h"

struct time
{
	int year;
	int month;
	int day;
	int yearday;
};

void interval1(struct time *a)
{
	int day1,day2;
	int leap=0,i;
	static int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
							 {0,31,29,31,30,31,30,31,31,30,31,30,31}};
	static int year[6]={0,365,366,365,365,365};
	do{
		printf("请输入年份：\n");
		scanf("%d",&a->year);
	  }while(a->year>2020||a->year<2015);	
	if(a->year==2016)
		leap=1;
	do{
		printf("请输入月份：\n");
		scanf("%d",&a->month);
	  }while(a->month<1||a->month>12);
	if(a->month==1||a->month==3||a->month==5||a->month==7||a->month==8||a->month==10||a->month==12)
	{	do
		{
			printf("请输入日期：\n");
			scanf("%d",&a->day);
		}while(a->day<1||a->day>31);}
	else if(a->month==2)
	{
		if(leap==0)
		{	do
			{
				printf("请输入日期：\n");
				scanf("%d",&a->day);
			}while(a->day<1||a->day>28);}
		else
		{	do
			{
				printf("请输入日期：\n");
				scanf("%d",&a->day);
			}while(a->day<1||a->day>29);}
	}
	else
	{	do
		{
			printf("请输入日期：\n");
			scanf("%d",&a->day);
		}while(a->day<1||a->day>30);}
	a->yearday=a->day;
	for(int i=1;i<a->month;i++)
		a->yearday+=month[leap][i];
	for(i=1;i<=(a->year-2015);i++)
		a->yearday+=year[i];
}

int main()
{
	struct time a,b;
	printf("请输入第一个日期\n");
	interval1(&a);
	printf("请输入第二个日期\n");
	interval1(&b);
	if(a.yearday>=b.yearday)
		printf("两日期相距时间为%d天\n",(a.yearday-b.yearday));
	else if(a.yearday<b.yearday)
		printf("两日期相距时间为%d天\n",(b.yearday-a.yearday));
	return 0;
}