#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

//结构体声明
typedef struct
{
	char sourse[20];//来源
	char name[20];//物资名称
	int num;//数量
	int year;//时间
	int month;
	int day;
	int pyear; //保质期
	int pmonth;
	int pday;
	char range[100]; //使用范围
	char orgn[100]; //捐赠单位信息
}goodin;

typedef struct
{
	char sourse[20]; //来源
	char name[20]; //物资名称
	int num; //数量
	int year; //时间
	int month;
	int day;
	char state[20];  //领用状态
	char person1[20]; //领取人信息
	char person2[20]; //经手人信息
	char commt[100];  //领用批示
}goodout;

typedef struct
{
	char name[20];  //执行人
	char op[20];  //操作
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	//操作时间
}trace;  //痕迹管理

typedef struct 
{
	char name[20];
	char id[20];
	char sex[10];
	int year;
	int month;
	int day;
}persons; //人员信息

//中间变量
int judge=0;//判断使用者身份
int judge1=0;//判断是否留痕

//函数声明名称
void id(void); //确认身份
void welcome(void); //起始界面
void menug(void);  //公众菜单
void menur(void);  //入库人员菜单
void menuc(void);  //出库人员菜单
void menul(void);  //领导人员菜单
void menuz(void);  //志愿者菜单
void menuj(void);  //监察人员菜单
void menuh(void);  //后台
void person(void); //人员信息初始化
void personin(void);//人员入职
void personout(void);//人员离职
void personlist(void); //查看人员名单
void goods(void);	//物资初始化
void goodsin(void);  //入库函数
void goodsout(void); //出库函数
void goodsinlist(void); //入库记录
void goodsoutlist(void);//出库记录
void goodlist(void); //查看库存
void storage(void);  //直接查看库存
void gsearch(void);   //库存搜索菜单
void gsearch1(goodin *p,int n);  //按照物资名称搜索库存
void gsearch2(goodin *p,int n);  //按照捐赠单位搜索库存
void goodsort1(void); //根据物资剩余数量排序
void goodsort2(void); //根据物资入库时间进行排序 
void today(void);     //每日报表
int interval(goodin *a);//求日期与2015年1月1日之间的间隔
int interval2(goodin *a);
void tracelist(void); //操作记录
int readfile1(void);  //获得文件人员信息中结构体数量
int readfile2(void);  //获得入库信息的结构体数量
int readfile3(void);  //获得操作记录的结构体数量
int readfile4(void);  //获得库存信息的结构体数量
int readfile5(void);  //获得出库信息的结构体数量
void exit(void);  //离开程序

int main()
{
	welcome();
	return 0;
}

void welcome()
{
	int n;
	printf("============================================================\n");
	printf("                              \n");
	printf(" -----*****欢 迎 使 用 疫 情 物 资 管 理 系 统 ! *****----- \n");
	printf("                              \n");
	printf("============================================================\n");
	printf("                              \n");
	printf(" 您可以进行以下操作：                    \n");
	printf("                              \n");
	printf("     1.  公众监管                  \n");
	printf("                              \n");
	printf("     2.  相关人员身份验证                   \n");
	printf("                              \n");
	printf("     0.  退出程序                  \n");
	printf("                              \n");
	printf("============================================================\n");
	printf("现在请选择您要进行的操作：（请输入操作前的数字）");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");menug();break;
			case 2:system("CLS");id();break;
			case 0:system("CLS");exit();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void id()
{
	int n,l;
	judge=0;
	printf(" 选择您要验证的身份：                    \n");
	printf("                              \n");
	printf("     1.  入库人员               \n");
	printf("                              \n");
	printf("     2.  出库人员                   \n");
	printf("                              \n");
	printf("     3.  志愿者               \n");
	printf("                              \n");
	printf("     4.  上级领导人员                   \n");
	printf("                              \n");
	printf("     5.  监察人员                   \n");
	printf("                              \n");
	printf("     6.  后台人员                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单                   \n");

	do
	{
		printf("现在请选择您要进行的操作：（请输入操作前的数字）\n");
		scanf("%d",&n);
	}while(n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=6&&n!=0);
	if(n==1) //入库人员
	{
		printf("请输入身份所对应的秘钥\n");
		scanf("%d",&l);
		if(l==100) //密码
		{system("CLS");menur();}
		else
		{printf("输入错误，返回上级菜单\n");system("CLS");id();}
	}
	if(n==2)  //出库人员
	{
		printf("请输入身份所对应的秘钥\n");
		scanf("%d",&l);
		if(l==200) //密码
		{system("CLS");menuc();}
		else
		{printf("输入错误，返回上级菜单\n");system("CLS");id();}
	}
	if(n==3)  //志愿者
	{
		printf("请输入身份所对应的秘钥\n");
		scanf("%d",&l);
		if(l==300) //密码
		{system("CLS");menuz();}
		else
		{printf("输入错误，返回上级菜单\n");system("CLS");id();}
	}
	if(n==4)  //领导人员
	{
		printf("请输入身份所对应的秘钥\n");
		scanf("%d",&l);
		if(l==400)  //密码
		{system("CLS");menul();}
		else
		{printf("输入错误，返回上级菜单\n");system("CLS");id();}
	}
	if(n==5)  //监察人员
	{
		printf("请输入身份所对应的秘钥\n");
		scanf("%d",&l);
		if(l==500)  //密码
		{system("CLS");menuj();}
		else
		{printf("输入错误，返回上级菜单\n");system("CLS");id();}
	}
	if(n==6)  //后台人员
	{
		printf("请输入身份所对应的秘钥\n");
		scanf("%d",&l);
		if(l==600)  //密码
		{system("CLS");menuh();}
		else
		{printf("输入错误，返回上级菜单\n");system("CLS");id();}
	}
	if(n==0) system("CLS");welcome();
}

void menug()
{
	int n;
	printf(" 选择您（公众）要进行的操作：                    \n");
	printf("                              \n");
	printf("     1.  出库记录              \n");
	printf("                              \n");
	printf("     2.  入库记录                   \n");
	printf("                              \n");
	printf("     3.  查看库存                   \n");
	printf("                              \n");
	printf("     4.  查看今日收支情况                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsoutlist();break;
			case 2:system("CLS");goodsinlist();break;
			case 3:system("CLS");goodlist();break;
			case 4:system("CLS");today();break;
			case 0:system("CLS");welcome();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void menur()
{
	int n;
	judge=1;
	printf(" 选择您（入库人员）要进行的操作：                    \n");
	printf("                              \n");
	printf("     1.  物资入库               \n");
	printf("                              \n");
	printf("     2.  查看库存                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsin();break;
			case 2:system("CLS");goodlist();break;
			case 0:system("CLS");id();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void menuc()
{
	int n;
	judge=2;
	printf(" 选择您（出库人员）要进行的操作：                    \n");
	printf("                              \n");
	printf("     1.  物资出库              \n");
	printf("                              \n");
	printf("     2.  查看库存                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsout();break;
			case 2:system("CLS");goodlist();break;
			case 0:system("CLS");id();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void menuz()
{
	int n;
	judge=3;
	printf(" 选择您（志愿者）要进行的操作：                    \n");
	printf("                              \n");
	printf("     1.  查看库存               \n");
	printf("                              \n");
	printf("     2.  人员信息                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodlist();break;
			case 2:system("CLS");personlist();break;
			case 0:system("CLS");id();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void menul()
{
	int n;
	judge=4;
	printf(" 选择您（领导人员）要进行的操作：                    \n");
	printf("                              \n");
	printf("     1.  出库记录              \n");
	printf("                              \n");
	printf("     2.  入库记录                   \n");
	printf("                              \n");
	printf("     3.  查看库存                   \n");
	printf("                              \n");
	printf("     4.  操作记录                   \n");
	printf("                              \n");
	printf("     5.  人员信息                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsoutlist();break;
			case 2:system("CLS");goodsinlist();break;
			case 3:system("CLS");goodlist();break;
			case 4:system("CLS");tracelist();break;
			case 5:system("CLS");personlist();break;
			case 0:system("CLS");id();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void menuj()
{
	int n;
	judge==5;
	printf(" 选择您（监察人员）要进行的操作：                    \n");
	printf("                              \n");
	printf("     1.  出库记录              \n");
	printf("                              \n");
	printf("     2.  入库记录                   \n");
	printf("                              \n");
	printf("     3.  查看库存                   \n");
	printf("                              \n");
	printf("     4.  操作记录                   \n");
	printf("                              \n");
	printf("     5.  人员信息                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsoutlist();break;
			case 2:system("CLS");goodsinlist();break;
			case 3:system("CLS");goodlist();break;
			case 4:system("CLS");tracelist();break;
			case 5:system("CLS");personlist();break;
			case 0:system("CLS");id();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void menuh()
{
	int n;
	judge=6;
	printf(" 选择您（后台人员）要进行的操作：                    \n");
	printf("                              \n");
	printf("     1.  出库记录              \n");
	printf("                              \n");
	printf("     2.  入库记录                   \n");
	printf("                              \n");
	printf("     3.  查看库存                   \n");
	printf("                              \n");
	printf("     4.  操作记录                   \n");
	printf("                              \n");
	printf("     5.  人员信息                   \n");
	printf("                              \n");
	printf("     6.  人员信息初始化                   \n");
	printf("                              \n");
	printf("     7.  人员入职                   \n");
	printf("                              \n");
	printf("     8.  人员离职                   \n");
	printf("                              \n");
	printf("     9.  物资初始化                  \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsoutlist();break;
			case 2:system("CLS");goodsinlist();break;
			case 3:system("CLS");goodlist();break;
			case 4:system("CLS");tracelist();break;
			case 5:system("CLS");personlist();break;
			case 6:system("CLS");person();break;
			case 7:system("CLS");personin();break;
			case 8:system("CLS");personout();break;
			case 9:system("CLS");goods();break;
			case 0:system("CLS");id();break;
			default :printf("没有此选项!\n 请重新输入!\n");
		}
	}
}

void goods()
{
	int n,i;
	FILE *fp;
	goodin *p;
	fp=fopen("物资库存.dat","wb");
	rewind(fp);
	printf("请输入你要输入的物资数量：\n");
	scanf("%d",&n);
	p=(goodin *)malloc(n*sizeof(goodin));
	for(i=0;i<n;i++)
	{
		printf("请输入第%d种物资的信息：\n",i+1);
		printf("请输入来源：\n");
		scanf("%s",&p[i].sourse);
		printf("请输入物资名称：\n");
		scanf("%s",&p[i].name);
		printf("请输入物资数量：\n");
		scanf("%d",&p[i].num);
		printf("请输入物资入库时间：（年月日之间用空格隔开 例:2020 5 18）\n");
		scanf("%d%d%d",&p[i].year,&p[i].month,&p[i].day);
		printf("请输入到期时间：（年月日之间用空格隔开 例:2020 5 18）\n");
		scanf("%d%d%d",&p[i].pyear,&p[i].pmonth,&p[i].pday);
		printf("请输入物资的使用范围\n");
		scanf("%s",&p[i].range);
		printf("请输入捐赠单位信息\n");
		scanf("%s",&p[i].orgn);
	}
	fwrite(p,sizeof(goodin),n,fp);
	fclose(fp);	
	printf("当前库存物资信息:（请仔细核对）\n");
	printf("来源     名称     数量     入库日期      保质期至      使用范围       捐赠单位信息\n");
	for(i=0;i<n;i++)
	{
		printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             %s\n",p[i].sourse,p[i].name,p[i].num,p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range,p[i].orgn);
	}
	free(p);
	printf("填写完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	menuh();
}

void goodsin()
{
	FILE *fp,*fp1,*fp2;
	int n,i,key;
	goodin *p;
	char a1[20]={"N95口罩"},b1[20]={"呼吸机"};
	
	trace t;
	char a[20]={"入库"};
	struct tm *tm_now;
	printf("请输入你的姓名：\n");
	scanf("%s",&t.name);
	fp1=fopen("操作记录.dat","ab+");
	time_t now;
    time(&now);
    tm_now=localtime(&now);
	t.year=tm_now->tm_year+1900; 
	t.month=tm_now->tm_mon+1;
	t.day=tm_now->tm_mday;
	t.hour=tm_now->tm_hour;
	t.min=tm_now->tm_min;
	t.sec=tm_now->tm_sec;
	strcpy(t.op,a);
	fwrite(&t,sizeof(trace),1,fp1);
	fclose(fp1);

	printf("请输入想要添加的物资的数量：\n");
	scanf("%d",&n);
	p=(goodin *)malloc(n*sizeof(goodin));
	fp=fopen("物资库存.dat","ab+");
		if(fp==NULL)
		{
			 printf("没有物资信息\n");
			 exit(0);
		}
	fp2=fopen("入库记录.dat","ab+");
	for(i=0;i<n;i++)
	{
		
		printf("请输入第%d种物资的信息：\n",i+1);
		printf("请输入来源：\n");
		scanf("%s",&p[i].sourse);
		printf("请输入物资名称：\n");
		scanf("%s",&p[i].name);
		if(strcmp(p[i].name,a1)==0||strcmp(p[i].name,b1)==0)   //敏感物资双重确认
		{
			do
			{
				printf("敏感物资！请输入上级领导人员秘钥：\n");
				scanf("%d",&key);
			}while(key!=400);
		}
		printf("请输入物资数量：\n");
		scanf("%d",&p[i].num);
		printf("请输入物资入库时间：（年月日之间用空格隔开 例:2020 5 18）\n");
		scanf("%d%d%d",&p[i].year,&p[i].month,&p[i].day);
		printf("请输入到期时间：（年月日之间用空格隔开 例:2020 5 18）\n");
		scanf("%d%d%d",&p[i].pyear,&p[i].pmonth,&p[i].pday);
		printf("请输入物资的使用范围\n");
		scanf("%s",&p[i].range);
		printf("请输入捐赠单位信息\n");
		scanf("%s",&p[i].orgn);
	}
	fwrite(p,sizeof(goodin),n,fp);
	fwrite(p,sizeof(goodin),n,fp2);
	fclose(fp);
	fclose(fp2);
	free(p); 
	printf("填写完成，请按回车返回上级菜单\n");
	getchar();getchar();
	{system("CLS");
	menur();}
}

void goodsinlist()
{
	int n,i;
	n=readfile2();
	printf("%d\n",n);
	FILE *fp,*fp1;

	char a[20]={"查看入库记录"};
	trace t;
	struct tm *tm_now;
	printf("请输入你的姓名：\n");
	scanf("%s",&t.name);
	fp1=fopen("操作记录.dat","ab+");
	time_t now;
    time(&now);
    tm_now=localtime(&now);
	t.year=tm_now->tm_year+1900; 
	t.month=tm_now->tm_mon+1;
	t.day=tm_now->tm_mday;
	t.hour=tm_now->tm_hour;
	t.min=tm_now->tm_min;
	t.sec=tm_now->tm_sec;
	strcpy(t.op,a);
	fwrite(&t,sizeof(trace),1,fp1);
	fclose(fp1);

	goodin *p;
	p=(goodin *)malloc(n*sizeof(goodin));
	fp=fopen("入库记录.dat","rb");
	if(fp==NULL)
	{
		printf("无法打开文件！\n");
		exit(0);
	}
	fread(p,sizeof(goodin),n,fp);
	fclose(fp);
	printf("======================================================================================\n");
	printf("来源           名称     数量     入库日期      保质期至      使用范围  \n");
	for(i=0;i<n;i++)
	{
		printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             \n",p[i].sourse,p[i].name,p[i].num,p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range);
	}
	free(p);
	printf("查看完成，请按回车返回上级菜单\n");
	getchar();getchar();
	if(judge==6)
	    {system("CLS");menuh();}
	else if(judge==5)
		{system("CLS");menuj();}
	else if(judge==4)
		{system("CLS");menul();}
	else if(judge==0)
		{system("CLS");menug();}
}

void goodsout()
{
	FILE *fp,*fp1,*fp2;

	char a[20]={"出库"};
	trace t;
	struct tm *tm_now;
	printf("请输入你的姓名：\n");
	scanf("%s",&t.name);
	fp1=fopen("操作记录.dat","ab+");
	time_t now;
    time(&now);
    tm_now=localtime(&now);
	t.year=tm_now->tm_year+1900; 
	t.month=tm_now->tm_mon+1;
	t.day=tm_now->tm_mday;
	t.hour=tm_now->tm_hour;
	t.min=tm_now->tm_min;
	t.sec=tm_now->tm_sec;
	strcpy(t.op,a);
	fwrite(&t,sizeof(trace),1,fp1);
	fclose(fp1);

	goodin *p,*m,temp1;
	goodout *q;
	int n1,n2;
	int i,j=0,sigh,k,h,*c,temp,flag,*inter;
	char a1[20]={"N95口罩"},b1[20]={"呼吸机"};
	int key;
	fp=fopen("物资库存.dat","rb");
	n1=readfile4();
	p=(goodin *)malloc(n1*sizeof(goodin));
	m=(goodin *)malloc(n1*sizeof(goodin));
	c=(int *)malloc(n1*sizeof(int));
	fread(p,sizeof(goodin),n1,fp);
	fclose(fp);
	fp2=fopen("出库记录.dat","ab+");
	printf("请输入你要移出的物资的数量：\n");
	scanf("%d",&n2);
	q=(goodout *)malloc(n2*sizeof(goodout));
	inter=(int *)malloc(n2*sizeof(int));
	for(i=0;i<n2;i++)
	{
		sigh=0;
		printf("请输入第%d种物资的信息：\n",i+1);
		printf("请输入物资名称\n");
		scanf("%s",&q[i].name);
		if(strcmp(q[i].name,a1)==0||strcmp(q[i].name,b1)==0)   //敏感物资双重确认
		{
			do
			{
				printf("敏感物资！请输入上级领导人员秘钥：\n");
				scanf("%d",&key);
			}while(key!=400);
		}
		printf("请输入物资数量\n");
		scanf("%d",&q[i].num);
		inter[i]=q[i].num;
		printf("请输入出库时间：（年月日之间用空格隔开 例:2020 5 18）\n");
		scanf("%d%d%d",&q[i].year,&q[i].month,&q[i].day);
		printf("请输入领用状态（已领用/未领用）\n");
		scanf("%s",&q[i].state);
		printf("请输入领用机构名称\n");
		scanf("%s",&q[i].person1);
		printf("请输入经手人姓名\n");
		scanf("%s",&q[i].person2);
		printf("请输入领用批示\n");
		scanf("%s",&q[i].commt);
		for(k=0;k<n1;k++)
		{
			if(strcmp(p[k].name,q[i].name)==0)
			{
				m[j]=p[k];
				j++;
				sigh=1;
			}
		}
		if(sigh==0)
		{
			printf("没有找到相关物资！\n");
			break;
		}
		else
		{
			for(k=0;k<j;k++)
			{
				c[k]=interval2(&m[k]);
			}
			for(k=0;k<j;k++)
			{
				flag=0;
				for(h=0;h<j-1-k;h++)
				{
					if(c[h]>c[h+1])
					{
						temp=c[h];
						c[h]=c[h+1];
						c[h+1]=temp;
						temp1=m[i];
						m[i]=m[i+1];
						m[i+1]=temp1;
						flag=1;
					}
				}
				if(flag==0)break;
			}
			int note=0;
			for(k=0;k<j;k++)
			{
				if(m[k].num>=inter[i])
				{
					m[k].num=m[k].num-inter[i];
					note=1;
					break;
				}
				else
				{
					inter[i]=inter[i]-m[k].num;
					m[k].num=0;
				}
			}
			if(note==0)
			{
				printf("物资剩余量不足！\n");
				break;
			}
			else
			{
				h=0;
				for(k=0;k<j;k++)
				{
					for(h=0;h<n1;h++)
					if((strcmp(p[h].name,m[k].name)==0)&&(p[h].pyear==m[k].pyear)&&(p[h].pmonth==m[k].pmonth)&&(p[h].pday==m[k].pday))
					{
						p[h].num=m[k].num;
					}
				}
			}
		}
		printf("成功出库！\n");
		fwrite(&q[i],sizeof(goodout),1,fp2);
		fp=fopen("物资库存.dat","wb");
		for(k=0;k<n1;k++)
			fwrite(&p[k],sizeof(goodin),1,fp);
		fclose(fp);
	}
	for(i=0;k<n1;k++)
		{
			printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             %s\n",
			p[i].sourse,p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range,p[i].orgn);
		}
	fclose(fp2);
	free(p);
	free(q);
	free(c);
	free(m);
	free(inter);
	printf("出库完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	menuc();
}

void goodsoutlist()
{
	FILE *fp,*fp1;
	int n,i;
	n=readfile5();
	printf("%d\n",n);

	char a[20]={"查看出库记录"};
	trace t;
	struct tm *tm_now;
	printf("请输入你的姓名：\n");
	scanf("%s",&t.name);
	fp1=fopen("操作记录.dat","ab+");
	time_t now;
    time(&now);
    tm_now=localtime(&now);
	t.year=tm_now->tm_year+1900; 
	t.month=tm_now->tm_mon+1;
	t.day=tm_now->tm_mday;
	t.hour=tm_now->tm_hour;
	t.min=tm_now->tm_min;
	t.sec=tm_now->tm_sec;
	strcpy(t.op,a);
	fwrite(&t,sizeof(trace),1,fp1);
	fclose(fp1);

	fp=fopen("出库记录.dat","rb");
	goodout *p;
	p=(goodout *)malloc(n*sizeof(goodout));
	fread(p,sizeof(goodout),n,fp);
	fclose(fp);
	printf("===================================================================================================\n");
	printf("名称     数量     出库日期      领用状态      领取单位信息         经手人信息          领用批示\n");
	for(i=0;i<n;i++)
	{
		printf("%s         %d       %d.%d.%d         %s             %s                  %s               %s\n",p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].state,p[i].person1,p[i].person2,p[i].commt);
	}
	free(p);
	printf("查看完成，请按回车返回上级菜单\n");
	getchar();getchar();
	if(judge==6)
	    {system("CLS");menuh();}
	else if(judge==5)
		{system("CLS");menuj();}
	else if(judge==4)
		{system("CLS");menul();}
	else if(judge==0)
		{system("CLS");menug();}
}

void goodlist()
{
	

	printf(" 选择查询物资的模式：                    \n");
	printf("                              \n");
	printf("     1.  直接查询              \n");
	printf("                              \n");
	printf("     2.  检索（仅支持物资名称检索与捐赠单位检索）                   \n");
	printf("                              \n");
	printf("     3.  按照剩余数量排序                   \n");
	printf("                              \n");
	printf("     4.  按照捐赠时间排序                   \n");
	printf("                              \n");
	printf("     0.  返回上级菜单                  \n");
	if(judge1==0)
	{FILE *fp1;
	char a[20]={"查看入库记录"};
	trace t;
	struct tm *tm_now;
	printf("请输入你的姓名：\n");
	scanf("%s",&t.name);
	fp1=fopen("操作记录.dat","ab+");
	time_t now;
    time(&now);
    tm_now=localtime(&now);
	t.year=tm_now->tm_year+1900; 
	t.month=tm_now->tm_mon+1;
	t.day=tm_now->tm_mday;
	t.hour=tm_now->tm_hour;
	t.min=tm_now->tm_min;
	t.sec=tm_now->tm_sec;
	strcpy(t.op,a);
	fwrite(&t,sizeof(trace),1,fp1);
	fclose(fp1);}
	judge1=0;
	printf("请输入你的选择：\n");
	int n;
	while(scanf("%d",&n)!=EOF)
	{switch(n)
	{
		case 1:system("CLS");storage();break;
		case 2:system("CLS");gsearch();break;
		case 3:system("CLS");goodsort1();break;
		case 4:system("CLS");goodsort2();break;
		case 0:
			{
			if(judge==0)
				{system("CLS");menug();}
			else if(judge==1)
				{system("CLS");menur();}
			else if(judge==2)
				{system("CLS");menuc();}
			else if(judge==3)
				{system("CLS");menuz();}
			else if(judge==4)
				{system("CLS");menul();}
			else if(judge==5)
				{system("CLS");menuj();}
			else if(judge==6)
				{system("CLS");menuh();}
			break;
			}
		default :printf("没有此选项!\n 请重新输入!\n");}
	}
}

void storage()
{
	judge1=1;
	int n,i;
	n=readfile4();
	printf("%d\n",n);
	FILE *fp;
	goodin *p;
	p=(goodin *)malloc(n*sizeof(goodin));
	fp=fopen("物资库存.dat","rb");
	if(fp==NULL)
	{
		printf("无法打开文件！\n");
		exit(0);
	}
	fread(p,sizeof(goodin),n,fp);
	fclose(fp);
	printf("======================================================================================\n");
	printf("来源               名称     数量     入库日期      保质期至      使用范围 \n");
	for(i=0;i<n;i++)
	{
		printf("%s          %s          %d           %d.%d.%d         %d.%d.%d            %s              \n",
			p[i].sourse,p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range);
	}
	free(p);
	printf("查看完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	goodlist();
}

void gsearch()
{
	judge1=1;
	printf(" 选择查询物资的模式：                    \n");
	printf("                              \n");
	printf("     1.  按物资名称查询              \n");
	printf("                              \n");
	printf("     2.  按来源查询                   \n");
	printf("                              \n");
	printf("     0.  返回上一级菜单                   \n");

	FILE *fp;
	fp=fopen("物资库存.dat","rb");
	goodin *p;
	int k;
	k=readfile4();
	p=(goodin *)malloc(k*sizeof(goodin));
	fread(p,sizeof(goodin),k,fp);
	fclose(fp);

	int n;
	while(scanf("%d",&n)!=EOF)
	switch(n)
	{
		case 1:system("CLS");gsearch1(p,k);break;
		case 2:system("CLS");gsearch2(p,k);break;
		case 0:system("CLS");goodlist();break;
		default :printf("没有此选项!\n 请重新输入!\n");
	}
	free(p);
}

void gsearch1(goodin *p,int n)
{
	char a[20];
	int i,sigh=0,m=0;
	printf("请输入您要检索的物资的名称：");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{
		if(strcmp(p[i].name,a)==0)
		{
				printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s            \n",
			p[i].sourse,p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range);
				sigh=1;
				m=m+p[i].num;
		}
	}
	if(sigh==0)
		printf("没有找到您所搜索的物资！\n");
	else
		printf("已找到！\n");
	if(m<=5)
		printf("该物资严重不足！\n");
	printf("查看完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	gsearch();
}

void gsearch2(goodin *p,int n)
{
	char a[20];
	int i,sigh=0;
	printf("请输入您要检索的捐赠单位名称：");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{
		if(strcmp(p[i].orgn,a)==0)
		{
				printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             %s\n",
			p[i].sourse,p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range,p[i].orgn);
				sigh=1;
		}
	}
	if(sigh==0)
		printf("没有找到您所搜索的物资！\n");
	else
		printf("已找到！\n");
	printf("查看完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	gsearch();
}

void goodsort1()
{
	judge1=1;
	int n,i,j;
	int flag;
	FILE *fp;
	fp=fopen("物资库存.dat","rb");
	goodin *p,temp;
	n=readfile4();
	printf("%d\n",n);
	p=(goodin *)malloc(n*sizeof(goodin));
	fread(p,sizeof(goodin),n,fp);
	fclose(fp);
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(p[j].num>p[j+1].num)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				flag=1;
			}
		}	
		if(flag==0)break;
	}
	printf("====================================================================================\n");
	for(i=0;i<n;i++)
	{
		printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             %s\n",
			p[i].sourse,p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range,p[i].orgn);
	}
	free(p);
	printf("请按回车返回上一级！\n");
	getchar();getchar();
	system("CLS");
	goodlist();
}

void goodsort2()
{
	judge1=1;
	int n,*m,i,flag,j,temp;
	goodin *p,temp1;
	FILE *fp;
	n=readfile4();
	fp=fopen("物资库存.dat","rb");
	p=(goodin *)malloc(n*sizeof(goodin));
	m=(int *)malloc(n*sizeof(int));
	fread(p,sizeof(goodin),n,fp);
	fclose(fp);
	for(i=0;i<n;i++)
	{
		m[i]=interval(&p[i]);
	}
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(m[j]>m[j+1])
			{
				temp=m[j];
				m[j]=m[j+1];
				m[j+1]=temp;
				flag=1;
				temp1=p[j];
				p[j]=p[j+1];
				p[j+1]=temp1;
				flag=1;
			}
		}if(flag==0)break;	
	}
	for(i=0;i<n;i++)
	{
		printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             %s\n",
			p[i].sourse,p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range,p[i].orgn);
	}
	free(p);
	printf("请按回车返回上一级！\n");
	getchar();getchar();
	system("CLS");
	goodlist();
}

void today()
{
	FILE *fp1,*fp2,*fp3;
	int i,n1,n2;

	trace t;
	char a[20]={"查看每日报表"};
	struct tm *tm_now;
	printf("请输入你的姓名：\n");
	scanf("%s",&t.name);
	fp1=fopen("操作记录.dat","ab+");
	time_t now;
    time(&now);
    tm_now=localtime(&now);
	t.year=tm_now->tm_year+1900; 
	t.month=tm_now->tm_mon+1;
	t.day=tm_now->tm_mday;
	t.hour=tm_now->tm_hour;
	t.min=tm_now->tm_min;
	t.sec=tm_now->tm_sec;
	strcpy(t.op,a);
	fwrite(&t,sizeof(trace),1,fp1);
	fclose(fp1);

	fp2=fopen("入库记录.dat","rb+");
	int sigh1=0;
	n1=readfile2();
	goodin *p;
	p=(goodin *)malloc(n1*sizeof(goodin));
	fread(p,sizeof(goodin),n1,fp2);
	fclose(fp2);
	printf("======================================================================================\n");
	printf("当日入库记录\n");
	printf("来源           名称     数量     入库日期      保质期至      使用范围       \n");
	 for(i=0;i<n1;i++)
	 {
		 if(p[i].year==t.year&&p[i].month==t.month&&p[i].day==t.day)
		 {
			 printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             \n",
				 p[i].sourse,p[i].name,p[i].num,
				 p[i].year,p[i].month,p[i].day,
				 p[i].pyear,p[i].pmonth,p[i].pday,p[i].range);
			 sigh1=1;
		 }
	 }
	 free(p);
	 if(sigh1==0)
		 printf("当日无入库记录！\n");
	 int sigh2=0;
	 fp3=fopen("出库记录.dat","rb");
	 goodout *q;
	 n2=readfile5();
	 q=(goodout *)malloc(n2*sizeof(goodout));
	 fread(q,sizeof(goodout),n2,fp3);
	 fclose(fp3);
	 printf("======================================================================================\n");
	 printf("当日出库记录\n");
	 printf("名称     数量     出库日期      领用状态      领取单位信息         经手人信息          领用批示\n");
	 for(i=0;i<n2;i++)
	 {
		 if(q[i].year==t.year&&q[i].month==t.month&&q[i].day==t.day)
		 {
			 printf("%s         %d       %d.%d.%d         %s             %s                  %s               %s\n",q[i].name,q[i].num,
				q[i].year,q[i].month,q[i].day,q[i].state,q[i].person1,q[i].person2,q[i].commt);
			sigh2=1;
		 }
	 }
	 free(q);
	 if(sigh2==0)
		 printf("当日无出库记录！\n");
	 printf("查看完成，请按回车返回上级菜单\n");
	 getchar();getchar();
	 system("CLS");
	 menug();
}

int interval(goodin *a)
{
	int day1,day2;
	int leap=0,i,n;
	static int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
							 {0,31,29,31,30,31,30,31,31,30,31,30,31}};
	static int year[6]={0,365,366,365,365,365};
	if(((a->year%4==0)&&(a->year%100!=0))||(a->year%100==0))
		leap=1;
	n=a->day;
	for(int i=1;i<a->month;i++)
		n+=month[leap][i];
	for(i=1;i<=(a->year-2015);i++)
		n+=year[i];
	return n;
}

int interval2(goodin *a)
{
	int day1,day2;
	int leap=0,i,n;
	static int month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
							 {0,31,29,31,30,31,30,31,31,30,31,30,31}};
	static int year[6]={0,365,366,365,365,365};
	if(((a->pyear%4==0)&&(a->pyear%100!=0))||(a->pyear%100==0))
		leap=1;
	n=a->pday;
	for(int i=1;i<a->pmonth;i++)
		n+=month[leap][i];
	for(i=2015;i<=a->pyear;i++)
	{
		if(((i%4==0)&&(i%100!=0))||(i%100==0))
			n+=366;
		else
			n+=365;
	}
	return n;
}

void person()
{
	int n,i;
	FILE *fp;
	persons p[10000];
	fp=fopen("人员信息.dat","wb");
	rewind(fp);
	printf("请输入你要输入的员工数量：\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个员工的信息：\n",i+1);
		printf("请输入员工姓名：\n");
		scanf("%s",&p[i].name);
		printf("请输入员工身份：\n");
		scanf("%s",&p[i].id);
		printf("请输入员工性别：（只能填入男或女）\n");
		scanf("%s",&p[i].sex);
		printf("请输入入职时间：（年月日之间用空格隔开 例:2020 5 18）\n");
		scanf("%d%d%d",&p[i].year,&p[i].month,&p[i].day);
	}
	fwrite(p,sizeof(persons),n,fp);
	fclose(fp);	
	printf("当前人员信息:（请仔细核对）\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n%s\n%s\n%d.%d.%d\n",p[i].name,p[i].id,p[i].sex,p[i].year,p[i].month,p[i].day);
	}
	printf("填写完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	menuh();
}

void personlist()
{
	int n,i;
	FILE *fp;
	persons m[100];
	fp=fopen("人员信息.dat","rb");
	n=readfile1();
	printf("%d\n",n);
	printf("=======================================================\n");
	fread(m,sizeof(persons),n,fp);
	printf("姓名      身份       性别      就职时间\n");
	for(i=0;i<n;i++)
	{
		printf("%s     %s     %s    %d.%d.%d\n",m[i].name,m[i].id,m[i].sex,m[i].year,m[i].month,m[i].day);
	}
	fclose(fp);
	printf("查看完成，请按回车返回上级菜单\n");
	getchar();getchar();
	if(judge==6)
	    {system("CLS");menuh();}
	else if(judge==5)
		{system("CLS");menuj();}
	else if(judge==4)
		{system("CLS");menul();}
	else if(judge==3)
		{system("CLS");menuz();}
}

void personin()
{
	FILE *fp;
	int n,i;
	persons *m;
	
	printf("请输入想要添加的员工的数量：\n");
	scanf("%d",&n);
	m=(persons *)malloc(n*sizeof(persons));
	fp=fopen("人员信息.dat","ab+");
	for(i=0;i<n;i++)
	{
		if(fp==NULL)
		{
			 printf("没有人员信息\n");
			 exit(0);
		}
		printf("请输入第%d个员工的信息：\n",i+1);
		printf("请输入员工姓名：\n");
		scanf("%s",&m[i].name);
		printf("请输入员工身份：\n");
		scanf("%s",&m[i].id);
		printf("请输入员工性别：（只能填入男或女）\n");
		scanf("%s",&m[i].sex);
		printf("请输入入职时间：（年月日之间用空格隔开 例:2020 5 18）\n");
		scanf("%d%d%d",&m[i].year,&m[i].month,&m[i].day);
	}
	fwrite(m,sizeof(persons),n,fp);
	fclose(fp);

	printf("填写完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	menuh();
}

void personout()
{
	
	int k,i,n,j,x,sigh;
	persons m[100],q;
	k=readfile1();
	printf("请输入要办理离职的人员数量：\n");
	scanf("%d",&n);
	FILE *fp;
	for(i=0;i<n;i++)
	{ 
		sigh=0;
		do
		{
			printf("请输入要办理离职的人员姓名：\n");
			scanf("%s",q.name);
			fp=fopen("人员信息.dat","rb+");
			for(i=0;i<k;i++)
			fread(&m[i],sizeof(persons),1,fp);
			fclose(fp);
			for(j=0;j<k;j++)
			{
				if(strcmp(q.name,m[j].name)==0)
				{   sigh=1;
					for(x=j;x<k;x++)
					{
						m[x]=m[x+1];
					}
					break;
				}
			}
		}while(sigh==0);
		fp=fopen("人员信息.dat","wb+");
		for(i=0;i<k-1;i++)
			fwrite(&m[i],sizeof(persons),1,fp);
		fclose(fp);
	}
	printf("离职完成，请按回车返回上级菜单\n");
	getchar();getchar();
	system("CLS");
	menuh();
}

void tracelist()
{
	int n,i;
	n=readfile3();
	printf("%d\n",n);
	FILE *fp,*fp1;

	char a[20]={"查看操作记录"};
	trace t,*p;
	struct tm *tm_now;
	printf("请输入你的姓名：\n");
	scanf("%s",&t.name);
	fp1=fopen("操作记录.dat","ab+");
	time_t now;
    time(&now);
    tm_now=localtime(&now);
	t.year=tm_now->tm_year+1900; 
	t.month=tm_now->tm_mon+1;
	t.day=tm_now->tm_mday;
	t.hour=tm_now->tm_hour;
	t.min=tm_now->tm_min;
	t.sec=tm_now->tm_sec;
	strcpy(t.op,a);
	fwrite(&t,sizeof(trace),1,fp1);
	fclose(fp1);

	fp=fopen("操作记录.dat","rb");
	p=(trace *)malloc(n*sizeof(trace));
	fread(p,sizeof(trace),n,fp);
	printf("=============================================\n");
	for(i=0;i<n;i++)
	{
		printf("%s     %s      %d-%d-%d %d:%d:%d\n",
			p[i].name,p[i].op,p[i].year, 
			p[i].month, p[i].day, p[i].hour, p[i].min, p[i].sec);
	}
	fclose(fp);
	free(p);
	printf("查看完成，请按回车返回上级菜单\n");
	getchar();getchar();
	if(judge==6)
	    {system("CLS");menuh();}
	else if(judge==5)
		{system("CLS");menuj();}
	else if(judge==4)
		{system("CLS");menul();}

}

int readfile1()
{
	int n=0;
	FILE *fp;
	fp=fopen("人员信息.dat","rb");
	persons m[1000];
	if(fp==NULL)
	{
	return n;
	}
	while(!feof(fp))
	{
		if(fread(&m[n],sizeof(persons),1,fp))
			n++;
	}
	fclose(fp);
	return n;
}

int readfile2()
{
	int n=0;
	FILE *fp;
	fp=fopen("入库记录.dat","rb");
	goodin m[1000];
	if(fp==NULL)
	{
	return n;
	}
	while(!feof(fp))
	{
		if(fread(&m[n],sizeof(goodin),1,fp))
			n++;
	}
	fclose(fp);
	return n;
}

int readfile3()
{
	int n=0;
	FILE *fp;
	fp=fopen("操作记录.dat","rb");
	trace m[1000];
	if(fp==NULL)
	{
	return n;
	}
	while(!feof(fp))
	{
		if(fread(&m[n],sizeof(trace),1,fp))
			n++;
	}
	fclose(fp);
	return n;
}

int readfile4()
{
	int n=0;
	FILE *fp;
	fp=fopen("物资库存.dat","rb");
	goodin m[1000];
	if(fp==NULL)
	{
	return n;
	}
	while(!feof(fp))
	{
		if(fread(&m[n],sizeof(goodin),1,fp))
			n++;
	}
	fclose(fp);
	return n;
}

int readfile5()
{
	int n=0;
	FILE *fp;
	fp=fopen("出库记录.dat","rb");
	goodout m[1000];
	if(fp==NULL)
	{
	return n;
	}
	while(!feof(fp))
	{
		if(fread(&m[n],sizeof(goodout),1,fp))
			n++;
	}
	fclose(fp);
	return n;
}

void exit()
{
 printf("==============================================================\n");
 printf("                               \n");
 printf("                               \n");
 printf("                               \n");
 printf("      感 谢 使 用 本 系 统 ！              \n");
 printf("                               \n");
 printf("       再 见 ！                     \n");
 printf("                               \n");
 printf("                               \n");
 printf("                               \n");
 printf("                               \n");
 printf("==============================================================\n");
 exit(0);
}


