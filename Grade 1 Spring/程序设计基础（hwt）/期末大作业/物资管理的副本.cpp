#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

//�ṹ������
typedef struct
{
	char sourse[20];//��Դ
	char name[20];//��������
	int num;//����
	int year;//ʱ��
	int month;
	int day;
	int pyear; //������
	int pmonth;
	int pday;
	char range[100]; //ʹ�÷�Χ
	char orgn[100]; //������λ��Ϣ
}goodin;

typedef struct
{
	char sourse[20]; //��Դ
	char name[20]; //��������
	int num; //����
	int year; //ʱ��
	int month;
	int day;
	char state[20];  //����״̬
	char person1[20]; //��ȡ����Ϣ
	char person2[20]; //��������Ϣ
	char commt[100];  //������ʾ
}goodout;

typedef struct
{
	char name[20];  //ִ����
	char op[20];  //����
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	//����ʱ��
}trace;  //�ۼ�����

typedef struct 
{
	char name[20];
	char id[20];
	char sex[10];
	int year;
	int month;
	int day;
}persons; //��Ա��Ϣ

//�м����
int judge=0;//�ж�ʹ�������
int judge1=0;//�ж��Ƿ�����

//������������
void id(void); //ȷ�����
void welcome(void); //��ʼ����
void menug(void);  //���ڲ˵�
void menur(void);  //�����Ա�˵�
void menuc(void);  //������Ա�˵�
void menul(void);  //�쵼��Ա�˵�
void menuz(void);  //־Ը�߲˵�
void menuj(void);  //�����Ա�˵�
void menuh(void);  //��̨
void person(void); //��Ա��Ϣ��ʼ��
void personin(void);//��Ա��ְ
void personout(void);//��Ա��ְ
void personlist(void); //�鿴��Ա����
void goods(void);	//���ʳ�ʼ��
void goodsin(void);  //��⺯��
void goodsout(void); //���⺯��
void goodsinlist(void); //����¼
void goodsoutlist(void);//�����¼
void goodlist(void); //�鿴���
void storage(void);  //ֱ�Ӳ鿴���
void gsearch(void);   //��������˵�
void gsearch1(goodin *p,int n);  //�������������������
void gsearch2(goodin *p,int n);  //���վ�����λ�������
void goodsort1(void); //��������ʣ����������
void goodsort2(void); //�����������ʱ��������� 
void today(void);     //ÿ�ձ���
int interval(goodin *a);//��������2015��1��1��֮��ļ��
int interval2(goodin *a);
void tracelist(void); //������¼
int readfile1(void);  //����ļ���Ա��Ϣ�нṹ������
int readfile2(void);  //��������Ϣ�Ľṹ������
int readfile3(void);  //��ò�����¼�Ľṹ������
int readfile4(void);  //��ÿ����Ϣ�Ľṹ������
int readfile5(void);  //��ó�����Ϣ�Ľṹ������
void exit(void);  //�뿪����

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
	printf(" -----*****�� ӭ ʹ �� �� �� �� �� �� �� ϵ ͳ ! *****----- \n");
	printf("                              \n");
	printf("============================================================\n");
	printf("                              \n");
	printf(" �����Խ������²�����                    \n");
	printf("                              \n");
	printf("     1.  ���ڼ��                  \n");
	printf("                              \n");
	printf("     2.  �����Ա�����֤                   \n");
	printf("                              \n");
	printf("     0.  �˳�����                  \n");
	printf("                              \n");
	printf("============================================================\n");
	printf("������ѡ����Ҫ���еĲ����������������ǰ�����֣�");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");menug();break;
			case 2:system("CLS");id();break;
			case 0:system("CLS");exit();break;
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void id()
{
	int n,l;
	judge=0;
	printf(" ѡ����Ҫ��֤����ݣ�                    \n");
	printf("                              \n");
	printf("     1.  �����Ա               \n");
	printf("                              \n");
	printf("     2.  ������Ա                   \n");
	printf("                              \n");
	printf("     3.  ־Ը��               \n");
	printf("                              \n");
	printf("     4.  �ϼ��쵼��Ա                   \n");
	printf("                              \n");
	printf("     5.  �����Ա                   \n");
	printf("                              \n");
	printf("     6.  ��̨��Ա                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�                   \n");

	do
	{
		printf("������ѡ����Ҫ���еĲ����������������ǰ�����֣�\n");
		scanf("%d",&n);
	}while(n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=6&&n!=0);
	if(n==1) //�����Ա
	{
		printf("�������������Ӧ����Կ\n");
		scanf("%d",&l);
		if(l==100) //����
		{system("CLS");menur();}
		else
		{printf("������󣬷����ϼ��˵�\n");system("CLS");id();}
	}
	if(n==2)  //������Ա
	{
		printf("�������������Ӧ����Կ\n");
		scanf("%d",&l);
		if(l==200) //����
		{system("CLS");menuc();}
		else
		{printf("������󣬷����ϼ��˵�\n");system("CLS");id();}
	}
	if(n==3)  //־Ը��
	{
		printf("�������������Ӧ����Կ\n");
		scanf("%d",&l);
		if(l==300) //����
		{system("CLS");menuz();}
		else
		{printf("������󣬷����ϼ��˵�\n");system("CLS");id();}
	}
	if(n==4)  //�쵼��Ա
	{
		printf("�������������Ӧ����Կ\n");
		scanf("%d",&l);
		if(l==400)  //����
		{system("CLS");menul();}
		else
		{printf("������󣬷����ϼ��˵�\n");system("CLS");id();}
	}
	if(n==5)  //�����Ա
	{
		printf("�������������Ӧ����Կ\n");
		scanf("%d",&l);
		if(l==500)  //����
		{system("CLS");menuj();}
		else
		{printf("������󣬷����ϼ��˵�\n");system("CLS");id();}
	}
	if(n==6)  //��̨��Ա
	{
		printf("�������������Ӧ����Կ\n");
		scanf("%d",&l);
		if(l==600)  //����
		{system("CLS");menuh();}
		else
		{printf("������󣬷����ϼ��˵�\n");system("CLS");id();}
	}
	if(n==0) system("CLS");welcome();
}

void menug()
{
	int n;
	printf(" ѡ���������ڣ�Ҫ���еĲ�����                    \n");
	printf("                              \n");
	printf("     1.  �����¼              \n");
	printf("                              \n");
	printf("     2.  ����¼                   \n");
	printf("                              \n");
	printf("     3.  �鿴���                   \n");
	printf("                              \n");
	printf("     4.  �鿴������֧���                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsoutlist();break;
			case 2:system("CLS");goodsinlist();break;
			case 3:system("CLS");goodlist();break;
			case 4:system("CLS");today();break;
			case 0:system("CLS");welcome();break;
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void menur()
{
	int n;
	judge=1;
	printf(" ѡ�����������Ա��Ҫ���еĲ�����                    \n");
	printf("                              \n");
	printf("     1.  �������               \n");
	printf("                              \n");
	printf("     2.  �鿴���                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsin();break;
			case 2:system("CLS");goodlist();break;
			case 0:system("CLS");id();break;
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void menuc()
{
	int n;
	judge=2;
	printf(" ѡ������������Ա��Ҫ���еĲ�����                    \n");
	printf("                              \n");
	printf("     1.  ���ʳ���              \n");
	printf("                              \n");
	printf("     2.  �鿴���                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodsout();break;
			case 2:system("CLS");goodlist();break;
			case 0:system("CLS");id();break;
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void menuz()
{
	int n;
	judge=3;
	printf(" ѡ������־Ը�ߣ�Ҫ���еĲ�����                    \n");
	printf("                              \n");
	printf("     1.  �鿴���               \n");
	printf("                              \n");
	printf("     2.  ��Ա��Ϣ                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�               \n");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 1:system("CLS");goodlist();break;
			case 2:system("CLS");personlist();break;
			case 0:system("CLS");id();break;
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void menul()
{
	int n;
	judge=4;
	printf(" ѡ�������쵼��Ա��Ҫ���еĲ�����                    \n");
	printf("                              \n");
	printf("     1.  �����¼              \n");
	printf("                              \n");
	printf("     2.  ����¼                   \n");
	printf("                              \n");
	printf("     3.  �鿴���                   \n");
	printf("                              \n");
	printf("     4.  ������¼                   \n");
	printf("                              \n");
	printf("     5.  ��Ա��Ϣ                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�               \n");
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
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void menuj()
{
	int n;
	judge==5;
	printf(" ѡ�����������Ա��Ҫ���еĲ�����                    \n");
	printf("                              \n");
	printf("     1.  �����¼              \n");
	printf("                              \n");
	printf("     2.  ����¼                   \n");
	printf("                              \n");
	printf("     3.  �鿴���                   \n");
	printf("                              \n");
	printf("     4.  ������¼                   \n");
	printf("                              \n");
	printf("     5.  ��Ա��Ϣ                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�               \n");
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
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void menuh()
{
	int n;
	judge=6;
	printf(" ѡ��������̨��Ա��Ҫ���еĲ�����                    \n");
	printf("                              \n");
	printf("     1.  �����¼              \n");
	printf("                              \n");
	printf("     2.  ����¼                   \n");
	printf("                              \n");
	printf("     3.  �鿴���                   \n");
	printf("                              \n");
	printf("     4.  ������¼                   \n");
	printf("                              \n");
	printf("     5.  ��Ա��Ϣ                   \n");
	printf("                              \n");
	printf("     6.  ��Ա��Ϣ��ʼ��                   \n");
	printf("                              \n");
	printf("     7.  ��Ա��ְ                   \n");
	printf("                              \n");
	printf("     8.  ��Ա��ְ                   \n");
	printf("                              \n");
	printf("     9.  ���ʳ�ʼ��                  \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�               \n");
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
			default :printf("û�д�ѡ��!\n ����������!\n");
		}
	}
}

void goods()
{
	int n,i;
	FILE *fp;
	goodin *p;
	fp=fopen("���ʿ��.dat","wb");
	rewind(fp);
	printf("��������Ҫ���������������\n");
	scanf("%d",&n);
	p=(goodin *)malloc(n*sizeof(goodin));
	for(i=0;i<n;i++)
	{
		printf("�������%d�����ʵ���Ϣ��\n",i+1);
		printf("��������Դ��\n");
		scanf("%s",&p[i].sourse);
		printf("�������������ƣ�\n");
		scanf("%s",&p[i].name);
		printf("����������������\n");
		scanf("%d",&p[i].num);
		printf("�������������ʱ�䣺��������֮���ÿո���� ��:2020 5 18��\n");
		scanf("%d%d%d",&p[i].year,&p[i].month,&p[i].day);
		printf("�����뵽��ʱ�䣺��������֮���ÿո���� ��:2020 5 18��\n");
		scanf("%d%d%d",&p[i].pyear,&p[i].pmonth,&p[i].pday);
		printf("���������ʵ�ʹ�÷�Χ\n");
		scanf("%s",&p[i].range);
		printf("�����������λ��Ϣ\n");
		scanf("%s",&p[i].orgn);
	}
	fwrite(p,sizeof(goodin),n,fp);
	fclose(fp);	
	printf("��ǰ���������Ϣ:������ϸ�˶ԣ�\n");
	printf("��Դ     ����     ����     �������      ��������      ʹ�÷�Χ       ������λ��Ϣ\n");
	for(i=0;i<n;i++)
	{
		printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             %s\n",p[i].sourse,p[i].name,p[i].num,p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range,p[i].orgn);
	}
	free(p);
	printf("��д��ɣ��밴�س������ϼ��˵�\n");
	getchar();getchar();
	system("CLS");
	menuh();
}

void goodsin()
{
	FILE *fp,*fp1,*fp2;
	int n,i,key;
	goodin *p;
	char a1[20]={"N95����"},b1[20]={"������"};
	
	trace t;
	char a[20]={"���"};
	struct tm *tm_now;
	printf("���������������\n");
	scanf("%s",&t.name);
	fp1=fopen("������¼.dat","ab+");
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

	printf("��������Ҫ��ӵ����ʵ�������\n");
	scanf("%d",&n);
	p=(goodin *)malloc(n*sizeof(goodin));
	fp=fopen("���ʿ��.dat","ab+");
		if(fp==NULL)
		{
			 printf("û��������Ϣ\n");
			 exit(0);
		}
	fp2=fopen("����¼.dat","ab+");
	for(i=0;i<n;i++)
	{
		
		printf("�������%d�����ʵ���Ϣ��\n",i+1);
		printf("��������Դ��\n");
		scanf("%s",&p[i].sourse);
		printf("�������������ƣ�\n");
		scanf("%s",&p[i].name);
		if(strcmp(p[i].name,a1)==0||strcmp(p[i].name,b1)==0)   //��������˫��ȷ��
		{
			do
			{
				printf("�������ʣ��������ϼ��쵼��Ա��Կ��\n");
				scanf("%d",&key);
			}while(key!=400);
		}
		printf("����������������\n");
		scanf("%d",&p[i].num);
		printf("�������������ʱ�䣺��������֮���ÿո���� ��:2020 5 18��\n");
		scanf("%d%d%d",&p[i].year,&p[i].month,&p[i].day);
		printf("�����뵽��ʱ�䣺��������֮���ÿո���� ��:2020 5 18��\n");
		scanf("%d%d%d",&p[i].pyear,&p[i].pmonth,&p[i].pday);
		printf("���������ʵ�ʹ�÷�Χ\n");
		scanf("%s",&p[i].range);
		printf("�����������λ��Ϣ\n");
		scanf("%s",&p[i].orgn);
	}
	fwrite(p,sizeof(goodin),n,fp);
	fwrite(p,sizeof(goodin),n,fp2);
	fclose(fp);
	fclose(fp2);
	free(p); 
	printf("��д��ɣ��밴�س������ϼ��˵�\n");
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

	char a[20]={"�鿴����¼"};
	trace t;
	struct tm *tm_now;
	printf("���������������\n");
	scanf("%s",&t.name);
	fp1=fopen("������¼.dat","ab+");
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
	fp=fopen("����¼.dat","rb");
	if(fp==NULL)
	{
		printf("�޷����ļ���\n");
		exit(0);
	}
	fread(p,sizeof(goodin),n,fp);
	fclose(fp);
	printf("======================================================================================\n");
	printf("��Դ           ����     ����     �������      ��������      ʹ�÷�Χ  \n");
	for(i=0;i<n;i++)
	{
		printf("%s        %s       %d       %d.%d.%d      %d.%d.%d      %s             \n",p[i].sourse,p[i].name,p[i].num,p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range);
	}
	free(p);
	printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
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

	char a[20]={"����"};
	trace t;
	struct tm *tm_now;
	printf("���������������\n");
	scanf("%s",&t.name);
	fp1=fopen("������¼.dat","ab+");
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
	char a1[20]={"N95����"},b1[20]={"������"};
	int key;
	fp=fopen("���ʿ��.dat","rb");
	n1=readfile4();
	p=(goodin *)malloc(n1*sizeof(goodin));
	m=(goodin *)malloc(n1*sizeof(goodin));
	c=(int *)malloc(n1*sizeof(int));
	fread(p,sizeof(goodin),n1,fp);
	fclose(fp);
	fp2=fopen("�����¼.dat","ab+");
	printf("��������Ҫ�Ƴ������ʵ�������\n");
	scanf("%d",&n2);
	q=(goodout *)malloc(n2*sizeof(goodout));
	inter=(int *)malloc(n2*sizeof(int));
	for(i=0;i<n2;i++)
	{
		sigh=0;
		printf("�������%d�����ʵ���Ϣ��\n",i+1);
		printf("��������������\n");
		scanf("%s",&q[i].name);
		if(strcmp(q[i].name,a1)==0||strcmp(q[i].name,b1)==0)   //��������˫��ȷ��
		{
			do
			{
				printf("�������ʣ��������ϼ��쵼��Ա��Կ��\n");
				scanf("%d",&key);
			}while(key!=400);
		}
		printf("��������������\n");
		scanf("%d",&q[i].num);
		inter[i]=q[i].num;
		printf("���������ʱ�䣺��������֮���ÿո���� ��:2020 5 18��\n");
		scanf("%d%d%d",&q[i].year,&q[i].month,&q[i].day);
		printf("����������״̬��������/δ���ã�\n");
		scanf("%s",&q[i].state);
		printf("���������û�������\n");
		scanf("%s",&q[i].person1);
		printf("�����뾭��������\n");
		scanf("%s",&q[i].person2);
		printf("������������ʾ\n");
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
			printf("û���ҵ�������ʣ�\n");
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
				printf("����ʣ�������㣡\n");
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
		printf("�ɹ����⣡\n");
		fwrite(&q[i],sizeof(goodout),1,fp2);
		fp=fopen("���ʿ��.dat","wb");
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
	printf("������ɣ��밴�س������ϼ��˵�\n");
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

	char a[20]={"�鿴�����¼"};
	trace t;
	struct tm *tm_now;
	printf("���������������\n");
	scanf("%s",&t.name);
	fp1=fopen("������¼.dat","ab+");
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

	fp=fopen("�����¼.dat","rb");
	goodout *p;
	p=(goodout *)malloc(n*sizeof(goodout));
	fread(p,sizeof(goodout),n,fp);
	fclose(fp);
	printf("===================================================================================================\n");
	printf("����     ����     ��������      ����״̬      ��ȡ��λ��Ϣ         ��������Ϣ          ������ʾ\n");
	for(i=0;i<n;i++)
	{
		printf("%s         %d       %d.%d.%d         %s             %s                  %s               %s\n",p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].state,p[i].person1,p[i].person2,p[i].commt);
	}
	free(p);
	printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
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
	

	printf(" ѡ���ѯ���ʵ�ģʽ��                    \n");
	printf("                              \n");
	printf("     1.  ֱ�Ӳ�ѯ              \n");
	printf("                              \n");
	printf("     2.  ��������֧���������Ƽ����������λ������                   \n");
	printf("                              \n");
	printf("     3.  ����ʣ����������                   \n");
	printf("                              \n");
	printf("     4.  ���վ���ʱ������                   \n");
	printf("                              \n");
	printf("     0.  �����ϼ��˵�                  \n");
	if(judge1==0)
	{FILE *fp1;
	char a[20]={"�鿴����¼"};
	trace t;
	struct tm *tm_now;
	printf("���������������\n");
	scanf("%s",&t.name);
	fp1=fopen("������¼.dat","ab+");
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
	printf("���������ѡ��\n");
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
		default :printf("û�д�ѡ��!\n ����������!\n");}
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
	fp=fopen("���ʿ��.dat","rb");
	if(fp==NULL)
	{
		printf("�޷����ļ���\n");
		exit(0);
	}
	fread(p,sizeof(goodin),n,fp);
	fclose(fp);
	printf("======================================================================================\n");
	printf("��Դ               ����     ����     �������      ��������      ʹ�÷�Χ \n");
	for(i=0;i<n;i++)
	{
		printf("%s          %s          %d           %d.%d.%d         %d.%d.%d            %s              \n",
			p[i].sourse,p[i].name,p[i].num,
			p[i].year,p[i].month,p[i].day,p[i].pyear,p[i].pmonth,p[i].pday,p[i].range);
	}
	free(p);
	printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
	getchar();getchar();
	system("CLS");
	goodlist();
}

void gsearch()
{
	judge1=1;
	printf(" ѡ���ѯ���ʵ�ģʽ��                    \n");
	printf("                              \n");
	printf("     1.  ���������Ʋ�ѯ              \n");
	printf("                              \n");
	printf("     2.  ����Դ��ѯ                   \n");
	printf("                              \n");
	printf("     0.  ������һ���˵�                   \n");

	FILE *fp;
	fp=fopen("���ʿ��.dat","rb");
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
		default :printf("û�д�ѡ��!\n ����������!\n");
	}
	free(p);
}

void gsearch1(goodin *p,int n)
{
	char a[20];
	int i,sigh=0,m=0;
	printf("��������Ҫ���������ʵ����ƣ�");
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
		printf("û���ҵ��������������ʣ�\n");
	else
		printf("���ҵ���\n");
	if(m<=5)
		printf("���������ز��㣡\n");
	printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
	getchar();getchar();
	system("CLS");
	gsearch();
}

void gsearch2(goodin *p,int n)
{
	char a[20];
	int i,sigh=0;
	printf("��������Ҫ�����ľ�����λ���ƣ�");
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
		printf("û���ҵ��������������ʣ�\n");
	else
		printf("���ҵ���\n");
	printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
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
	fp=fopen("���ʿ��.dat","rb");
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
	printf("�밴�س�������һ����\n");
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
	fp=fopen("���ʿ��.dat","rb");
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
	printf("�밴�س�������һ����\n");
	getchar();getchar();
	system("CLS");
	goodlist();
}

void today()
{
	FILE *fp1,*fp2,*fp3;
	int i,n1,n2;

	trace t;
	char a[20]={"�鿴ÿ�ձ���"};
	struct tm *tm_now;
	printf("���������������\n");
	scanf("%s",&t.name);
	fp1=fopen("������¼.dat","ab+");
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

	fp2=fopen("����¼.dat","rb+");
	int sigh1=0;
	n1=readfile2();
	goodin *p;
	p=(goodin *)malloc(n1*sizeof(goodin));
	fread(p,sizeof(goodin),n1,fp2);
	fclose(fp2);
	printf("======================================================================================\n");
	printf("��������¼\n");
	printf("��Դ           ����     ����     �������      ��������      ʹ�÷�Χ       \n");
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
		 printf("����������¼��\n");
	 int sigh2=0;
	 fp3=fopen("�����¼.dat","rb");
	 goodout *q;
	 n2=readfile5();
	 q=(goodout *)malloc(n2*sizeof(goodout));
	 fread(q,sizeof(goodout),n2,fp3);
	 fclose(fp3);
	 printf("======================================================================================\n");
	 printf("���ճ����¼\n");
	 printf("����     ����     ��������      ����״̬      ��ȡ��λ��Ϣ         ��������Ϣ          ������ʾ\n");
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
		 printf("�����޳����¼��\n");
	 printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
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
	fp=fopen("��Ա��Ϣ.dat","wb");
	rewind(fp);
	printf("��������Ҫ�����Ա��������\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("�������%d��Ա������Ϣ��\n",i+1);
		printf("������Ա��������\n");
		scanf("%s",&p[i].name);
		printf("������Ա����ݣ�\n");
		scanf("%s",&p[i].id);
		printf("������Ա���Ա𣺣�ֻ�������л�Ů��\n");
		scanf("%s",&p[i].sex);
		printf("��������ְʱ�䣺��������֮���ÿո���� ��:2020 5 18��\n");
		scanf("%d%d%d",&p[i].year,&p[i].month,&p[i].day);
	}
	fwrite(p,sizeof(persons),n,fp);
	fclose(fp);	
	printf("��ǰ��Ա��Ϣ:������ϸ�˶ԣ�\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n%s\n%s\n%d.%d.%d\n",p[i].name,p[i].id,p[i].sex,p[i].year,p[i].month,p[i].day);
	}
	printf("��д��ɣ��밴�س������ϼ��˵�\n");
	getchar();getchar();
	system("CLS");
	menuh();
}

void personlist()
{
	int n,i;
	FILE *fp;
	persons m[100];
	fp=fopen("��Ա��Ϣ.dat","rb");
	n=readfile1();
	printf("%d\n",n);
	printf("=======================================================\n");
	fread(m,sizeof(persons),n,fp);
	printf("����      ���       �Ա�      ��ְʱ��\n");
	for(i=0;i<n;i++)
	{
		printf("%s     %s     %s    %d.%d.%d\n",m[i].name,m[i].id,m[i].sex,m[i].year,m[i].month,m[i].day);
	}
	fclose(fp);
	printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
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
	
	printf("��������Ҫ��ӵ�Ա����������\n");
	scanf("%d",&n);
	m=(persons *)malloc(n*sizeof(persons));
	fp=fopen("��Ա��Ϣ.dat","ab+");
	for(i=0;i<n;i++)
	{
		if(fp==NULL)
		{
			 printf("û����Ա��Ϣ\n");
			 exit(0);
		}
		printf("�������%d��Ա������Ϣ��\n",i+1);
		printf("������Ա��������\n");
		scanf("%s",&m[i].name);
		printf("������Ա����ݣ�\n");
		scanf("%s",&m[i].id);
		printf("������Ա���Ա𣺣�ֻ�������л�Ů��\n");
		scanf("%s",&m[i].sex);
		printf("��������ְʱ�䣺��������֮���ÿո���� ��:2020 5 18��\n");
		scanf("%d%d%d",&m[i].year,&m[i].month,&m[i].day);
	}
	fwrite(m,sizeof(persons),n,fp);
	fclose(fp);

	printf("��д��ɣ��밴�س������ϼ��˵�\n");
	getchar();getchar();
	system("CLS");
	menuh();
}

void personout()
{
	
	int k,i,n,j,x,sigh;
	persons m[100],q;
	k=readfile1();
	printf("������Ҫ������ְ����Ա������\n");
	scanf("%d",&n);
	FILE *fp;
	for(i=0;i<n;i++)
	{ 
		sigh=0;
		do
		{
			printf("������Ҫ������ְ����Ա������\n");
			scanf("%s",q.name);
			fp=fopen("��Ա��Ϣ.dat","rb+");
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
		fp=fopen("��Ա��Ϣ.dat","wb+");
		for(i=0;i<k-1;i++)
			fwrite(&m[i],sizeof(persons),1,fp);
		fclose(fp);
	}
	printf("��ְ��ɣ��밴�س������ϼ��˵�\n");
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

	char a[20]={"�鿴������¼"};
	trace t,*p;
	struct tm *tm_now;
	printf("���������������\n");
	scanf("%s",&t.name);
	fp1=fopen("������¼.dat","ab+");
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

	fp=fopen("������¼.dat","rb");
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
	printf("�鿴��ɣ��밴�س������ϼ��˵�\n");
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
	fp=fopen("��Ա��Ϣ.dat","rb");
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
	fp=fopen("����¼.dat","rb");
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
	fp=fopen("������¼.dat","rb");
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
	fp=fopen("���ʿ��.dat","rb");
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
	fp=fopen("�����¼.dat","rb");
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
 printf("      �� л ʹ �� �� ϵ ͳ ��              \n");
 printf("                               \n");
 printf("       �� �� ��                     \n");
 printf("                               \n");
 printf("                               \n");
 printf("                               \n");
 printf("                               \n");
 printf("==============================================================\n");
 exit(0);
}


