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
extern int NumberJudge();//����������ֽ��з������жϸ�ʽ�Ƿ�ȫΪʮ����
extern int Print(LinkList L);//���㵥����ĳ��ȣ�Ȼ�����������
extern void Tips();//��ӡѡ��˵�
extern int InitList(LinkList L);//����һ����ͷ���ĵ�����
extern int Delete(LinkList L,int x);//ɾ����n�����
extern int Find(LinkList L,int x);//���ҵ�n����㴦��ֵ

extern int Alter(LinkList L,int n,int x);//�Ķ���n����㴦��ֵΪx
extern void Insert(LinkList L,LinkList p);//�������������ֵΪX�Ľ�㣬ʹ��Ȼ����

extern void Reverse(LinkList L);//�ѵ���������Ԫ������,������ͷ�巨��������!

extern status Sort(LinkList L);//����������

extern status DestroyList(LinkList L);
