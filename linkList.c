#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>
/******************************************/
int ALLmathJudge() 
{//����������ֽ��з������жϸ�ʽ�Ƿ����
	int n=0;
	char a[100];
	int i =0,j=0;
	int sign = 0;
		scanf("%s", a);//��������n��ʮ�������֣��򷵻�1�����������Ĳ�����
	    for(;a[i]!='\0';i++)
		{
			if(a[i]>='0'&&a[i]<='9')//�õ�����a�е�0��9��Ԫ�ظ���sign
				sign++;
		}
		//printf("%d\n",sign);
		for(i=0;a[i]!='\0';i++)//�õ�����a��Ԫ�ظ���j
		{
			j++;
		}
			//	printf("%d\n",j);
			if(sign==j)	
			{
				for(i=0;a[i]!='\0';i++)
				{
					n*=10;
					n+=(a[i]-48);
					
				}
				return n;
				}
			else 
			{
				printf("�Ƿ����룬���������룡\n");ALLmathJudge();
			}

return n;
}
/******************************************/
int NumberJudge() {//����������ֽ��з������жϸ�ʽ�Ƿ�ȫΪʮ����
	int n;
	int sign = 0;
	int retur;
	do {
		sign = 0;
		retur = scanf("%d", &n);//��������n��ʮ�������֣��򷵻�1�����������Ĳ�����
		if (retur == 0) {		//����ѭ����ֱ�������n��ʮ�������֣����˳�ѭ��
			printf("\n�Ƿ����룬���������룡\n");
			for (; getchar() != '\n';);
			sign = -1;
		}
	} while (sign == -1);
	return n;
}
/*******************************************/
int Print(LinkList L)//���㵥����ĳ��ȣ�Ȼ�����������
{
int num=0;
LinkList p;
if(L==NULL)
{printf("����Ϊ�գ����ؽ�һ����\n");return 0;}

p=L->next;

	while(p)
	{
	num++;
	printf("%d  ",p->data);
	p=p->next;
	}
	printf("\n����Ϊ%d:\n",num);
	return 0;
}
/*********************************************/
void Tips()//��ӡѡ��˵�
{
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
printf("*****************************************\n");
printf("�����ּ�ѡ����Ӧ����\n");
printf("<1>���������:\n");

printf("<2>����������䳤��:\n");
printf("<3>ɾ����n�����:\n");
printf("<4>�Ķ���n����㴦��ֵΪx:\n");
printf("<5>������Ԫ������:\n");

printf("<6>��������:\n");
printf("<7>���ҵ�n����㴦��ֵ:\n");

printf("<8>�������������ֵΪX�Ľ�㣬ʹ��Ȼ����:\n");
printf("<9>����������:\n");
printf("<0>�˳�:\n");
printf("*****************************************\n");
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}
/*****************************************/

int InitList(LinkList L)//����һ����ͷ���ĵ�����
{
int n;
LinkList p,q;

if(L==NULL)
{L=(LinkList)malloc(sizeof(LNode));L->next=NULL;}
p=L;
printf("�����ʼ������\n");
printf("��������Ҫ��������ĳ���n�������и���Ԫ�ص�ֵ\n");
n=NumberJudge();
//printf("%d",n);
if(n<0){printf("The number out of bound!");return 0;	}
	while(n--)
	{
	q=(LinkList)malloc(sizeof(LNode));
	q->data=NumberJudge();
	q->next=NULL;
	p->next=q;
	p=q;
	}
	return 0;
}
/**************************************************/
int Delete(LinkList L,int x)//ɾ����n�����
{
int i=1;
LinkList p,q;
if(L==NULL)
{printf("����Ϊ�գ����ؽ�һ����\n");return 0;}

p=L;
if(x<0){printf("The number out of bound!");return 0;	}
	while( p->next&&i<x)
	{p=p->next;i++;}
		if(p->next)
		{
		q=p->next;
		p->next=q->next;
		free(q);
		printf("ɾ���ɹ�!!\n\n");
		return 0;
		}
		else
		{printf("������û��%d\n\n",x);
		return 0;	}
}
/*****************************************************/
int Find(LinkList L,int x)//���ҵ�n����㴦��ֵ
{
int i=1;
LinkList p;
if(L==NULL)
{printf("����Ϊ�գ����ؽ�һ����\n");return 0;}

if(x<0){printf("The number out of bound!");return 0;	}
p=L;
if(L=NULL){printf("����Ϊ��\n");}
	while( p->next&&i<x)
	{p=p->next;i++;}
		if(p->next)
		{printf("%d�Ľ��Ϊ:%d\n\n",x,p->next->data);return 0;}
		else
		{printf("û�ҵ�!!\n\n");return 0;}
	}
/**************************************************/
int Alter(LinkList L,int n,int x)//�Ķ���n����㴦��ֵΪx
{
int i=1;
LinkList p;
if(L==NULL)
{printf("����Ϊ�գ����ؽ�һ����\n");return 0;}


p=L;
if(n<0){printf("The number out of bound!");return 0;	}
while( p->next&&i<n)
{p=p->next;i++;}
if(p->next)
{
p->next->data=x;
printf("��%d���Ľ���Ѹ�Ϊ%d\n\n",n,p->next->data);
return 0;
}else
printf("û�ҵ�!!\n\n");
return 0;
}

/***********************************************/
void Insert(LinkList L,LinkList p)//�������������ֵΪX�Ľ�㣬ʹ��Ȼ����
{
LinkList s;
s=L;
while(s->next&&s->next->data <p->data)
s=s->next;

p->next=s->next;
s->next=p;
}
/**************************************************/
void Reverse(LinkList L)//�ѵ���������Ԫ������,������ͷ�巨��������!
{
LinkList p,s;
p=s=L->next;
L->next=NULL;
while(p)
{
s=s->next;
p->next=L->next;
L->next=p;
p=s;
}
printf("���óɹ�!!!\n\n");
}

/*****************************************************/
status Sort(LinkList L)//����������
{

LinkList s,r;
s=L->next;
L->next=NULL;
	while(s)
	{
	r=s;
	s=s->next;
	r->next=NULL;
	Insert(L,r);
	}
return OK;
}
/************************************************/
//��������
status DestroyList(LinkList L)  
{  
    LinkList p;  
    if(L==NULL)  
	{printf("����Ϊ�գ����ؽ�һ����\n");return OK;}  
    while(p)  
    {  
        p=L->next;  
        free(L);  
        L=p;  
    }

	printf("��ɾ����·\n");
    return OK;  
}

