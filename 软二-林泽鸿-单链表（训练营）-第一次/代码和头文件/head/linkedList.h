#define ERROR 0
#define OK 1
typedef int status;
typedef int ElemType;
typedef struct Node
{
ElemType data;
struct Node *next;
} LNode,*LinkList;

extern int ALLmathJudge() ;
extern int NumberJudge();//对输入的数字进行分析，判断格式是否全为十进制
extern int Print(LinkList L);//计算单链表的长度，然后输出单链表
extern void Tips();//打印选择菜单
extern int InitList(LinkList L);//建立一个带头结点的单链表
extern int Delete(LinkList L,int x);//删除第n个结点
extern int Find(LinkList L,int x);//查找第n个结点处的值

extern int Alter(LinkList L,int n,int x);//改动第n个结点处的值为x
extern void Insert(LinkList L,LinkList p);//在升序链表插入值为X的结点，使仍然有序

extern void Reverse(LinkList L);//把单向链表中元素逆置,类似于头插法建立链表!

extern status Sort(LinkList L);//按升序排列

extern status DestroyList(LinkList L);
