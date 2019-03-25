#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>
/******************************************/
int ALLmathJudge() 
{//对输入的数字进行分析，判断格式是否相符
	int n=0;
	char a[100];
	int i =0,j=0;
	int sign = 0;
		scanf("%s", a);//如果输入的n是十进制数字，则返回1（符合条件的参数）
	    for(;a[i]!='\0';i++)
		{
			if(a[i]>='0'&&a[i]<='9')//得到数组a中的0到9的元素个数sign
				sign++;
		}
		//printf("%d\n",sign);
		for(i=0;a[i]!='\0';i++)//得到数组a的元素个数j
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
				printf("非法输入，请重新输入！\n");ALLmathJudge();
			}

return n;
}
/******************************************/
int NumberJudge() {//对输入的数字进行分析，判断格式是否全为十进制
	int n;
	int sign = 0;
	int retur;
	do {
		sign = 0;
		retur = scanf("%d", &n);//如果输入的n是十进制数字，则返回1（符合条件的参数）
		if (retur == 0) {		//不断循环，直到输入的n是十进制数字，则退出循环
			printf("\n非法输入，请重新输入！\n");
			for (; getchar() != '\n';);
			sign = -1;
		}
	} while (sign == -1);
	return n;
}
/*******************************************/
int Print(LinkList L)//计算单链表的长度，然后输出单链表
{
int num=0;
LinkList p;
if(L==NULL)
{printf("链表为空，可重建一链表！\n");return 0;}

p=L->next;

	while(p)
	{
	num++;
	printf("%d  ",p->data);
	p=p->next;
	}
	printf("\n长度为%d:\n",num);
	return 0;
}
/*********************************************/
void Tips()//打印选择菜单
{
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
printf("*****************************************\n");
printf("按数字键选择相应操作\n");
printf("<1>构造空链表:\n");

printf("<2>输出单链表及其长度:\n");
printf("<3>删除第n个结点:\n");
printf("<4>改动第n个结点处的值为x:\n");
printf("<5>将表中元素逆置:\n");

printf("<6>销毁链表:\n");
printf("<7>查找第n个结点处的值:\n");

printf("<8>在升序链表插入值为X的结点，使仍然有序:\n");
printf("<9>按升序排列:\n");
printf("<0>退出:\n");
printf("*****************************************\n");
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}
/*****************************************/

int InitList(LinkList L)//建立一个带头结点的单链表
{
int n;
LinkList p,q;

if(L==NULL)
{L=(LinkList)malloc(sizeof(LNode));L->next=NULL;}
p=L;
printf("链表初始化操作\n");
printf("请输入所要创建链表的长度n和链表中各个元素的值\n");
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
int Delete(LinkList L,int x)//删除第n个结点
{
int i=1;
LinkList p,q;
if(L==NULL)
{printf("链表为空，可重建一链表！\n");return 0;}

p=L;
if(x<0){printf("The number out of bound!");return 0;	}
	while( p->next&&i<x)
	{p=p->next;i++;}
		if(p->next)
		{
		q=p->next;
		p->next=q->next;
		free(q);
		printf("删除成功!!\n\n");
		return 0;
		}
		else
		{printf("链表中没有%d\n\n",x);
		return 0;	}
}
/*****************************************************/
int Find(LinkList L,int x)//查找第n个结点处的值
{
int i=1;
LinkList p;
if(L==NULL)
{printf("链表为空，可重建一链表！\n");return 0;}

if(x<0){printf("The number out of bound!");return 0;	}
p=L;
if(L=NULL){printf("链表为空\n");}
	while( p->next&&i<x)
	{p=p->next;i++;}
		if(p->next)
		{printf("%d的结点为:%d\n\n",x,p->next->data);return 0;}
		else
		{printf("没找到!!\n\n");return 0;}
	}
/**************************************************/
int Alter(LinkList L,int n,int x)//改动第n个结点处的值为x
{
int i=1;
LinkList p;
if(L==NULL)
{printf("链表为空，可重建一链表！\n");return 0;}


p=L;
if(n<0){printf("The number out of bound!");return 0;	}
while( p->next&&i<n)
{p=p->next;i++;}
if(p->next)
{
p->next->data=x;
printf("第%d个的结点已改为%d\n\n",n,p->next->data);
return 0;
}else
printf("没找到!!\n\n");
return 0;
}

/***********************************************/
void Insert(LinkList L,LinkList p)//在升序链表插入值为X的结点，使仍然有序
{
LinkList s;
s=L;
while(s->next&&s->next->data <p->data)
s=s->next;

p->next=s->next;
s->next=p;
}
/**************************************************/
void Reverse(LinkList L)//把单向链表中元素逆置,类似于头插法建立链表!
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
printf("逆置成功!!!\n\n");
}

/*****************************************************/
status Sort(LinkList L)//按升序排列
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
//销毁链表
status DestroyList(LinkList L)  
{  
    LinkList p;  
    if(L==NULL)  
	{printf("链表为空，可重建一链表！\n");return OK;}  
    while(p)  
    {  
        p=L->next;  
        free(L);  
        L=p;  
    }

	printf("已删库跑路\n");
    return OK;  
}

