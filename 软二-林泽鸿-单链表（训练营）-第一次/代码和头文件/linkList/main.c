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
	{	//if(op<0||op>9){printf("�Ƿ����룬���������룡\n");}
		switch(op)
		{
		case 1:			//��������������Ԫ�غͳ���
		
			InitList(L);
				break;

		case 2://��������������Ԫ�غͳ���
			//printf("%d",op);
			Print(L);
				break;
		case 3:
			if(L==NULL)
			{printf("����Ϊ�գ����½�һ����\n");break;}

			printf("��������Ҫɾ�����Ľ����n:\n");
			x=NumberJudge();
		
			Delete(L,x);
				break;

		case 4:
			if(L==NULL)
			{printf("����Ϊ�գ����½�һ����\n");break;}
			do{
			printf("��������Ҫ�Ķ����Ľ����n(n��ҪΪ������):\n");
			n=NumberJudge();
			}while(n<=0);
			
			printf("������Ķ�֮���ֵx:\n");
			x=NumberJudge();
			Alter(L,n,x);
				break;
		case 5://��������
			if(L==NULL)
			{printf("����Ϊ�գ����½�һ����\n");break;}
			Reverse(L);
				break;
		case 6://��������
			if(L==NULL)
			{printf("����Ϊ�գ����½�һ����\n");break;}
			DestroyList(L);
			L=NULL;
				break;
		case 7:
			if(L==NULL)
			{printf("����Ϊ�գ����½�һ����\n");break;}
			printf("������Ҫ���ҵ�Ԫ���������еĽ����X:\n");
			x=NumberJudge();
			Find(L,x);
				break;
		case 8:
			if(L==NULL)
			{printf("����Ϊ�գ����½�һ����\n");break;}
			printf("������Ҫ�����Ԫ��X:\n");
			x=NumberJudge();
			p=(LinkList)malloc(sizeof(LNode));
			p->data=x;
			Insert(L,p);
			printf("����ɹ�!!!\n\n");
				break;
		case 9:
			if(L==NULL)
			{printf("����Ϊ�գ����½�һ����\n");break;}
			flag=Sort(L);
			if(flag)
			printf("����ɹ�!!\n");
				break;
		default :printf("\n\t�����������������룡\n\n");
		}
			Tips();
			op=NumberJudge();
	}
	return 0;
}
