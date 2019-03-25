#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
int op,x,flag,n;
LinkList L,p;
L=(LinkList)malloc(sizeof(LNode));
L->next=NULL;
L->data=-1;
Tips();
op=ALLmathJudge();
	while(op)
	{	//if(op<0||op>9){printf("非法输入，请重新输入！\n");}
		switch(op)
		{
		case 1:			//输出单链表的所有元素和长度
		
			InitList(L);
				break;

		case 2://输出单链表的所有元素和长度
			//printf("%d",op);
			Print(L);
				break;
		case 3:
			if(L==NULL)
			{printf("链表为空，可新建一链表！\n");break;}

			printf("请输入所要删除结点的结点数n:\n");
			x=NumberJudge();
		
			Delete(L,x);
				break;

		case 4:
			if(L==NULL)
			{printf("链表为空，可新建一链表！\n");break;}
			do{
			printf("请输入所要改动结点的结点数n(n需要为正整数):\n");
			n=NumberJudge();
			}while(n<=0);
			
			printf("请输入改动之后的值x:\n");
			x=NumberJudge();
			Alter(L,n,x);
				break;
		case 5://逆置链表
			if(L==NULL)
			{printf("链表为空，可新建一链表！\n");break;}
			Reverse(L);
				break;
		case 6://销毁链表
			if(L==NULL)
			{printf("链表为空，可新建一链表！\n");break;}
			DestroyList(L);
			L=NULL;
				break;
		case 7:
			if(L==NULL)
			{printf("链表为空，可新建一链表！\n");break;}
			printf("请输入要查找的元素在链表中的结点数X:\n");
			x=NumberJudge();
			Find(L,x);
				break;
		case 8:
			if(L==NULL)
			{printf("链表为空，可新建一链表！\n");break;}
			printf("请输入要插入的元素X:\n");
			x=NumberJudge();
			p=(LinkList)malloc(sizeof(LNode));
			p->data=x;
			Insert(L,p);
			printf("插入成功!!!\n\n");
				break;
		case 9:
			if(L==NULL)
			{printf("链表为空，可新建一链表！\n");break;}
			flag=Sort(L);
			if(flag)
			printf("排序成功!!\n");
				break;
		default :printf("\n\t输入有误，请重新输入！\n\n");
		}
			Tips();
			op=NumberJudge();
	}
	return 0;
}
