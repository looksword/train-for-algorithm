//�������������������ϵ�����ڵ㣬���ϵ���ֵ������������������ڵ���ֵ��С����������������ڵ���ֵ
//�ص㣺�������������ǵ�������

//��Ŀ��
//����һϵ������������������������������ǰ������������
//���룺
//�����һ�а���һ������n��1<=n<=100������������һ�а���n������
//�����
//�����ж���������ݣ�����ÿ�����ݣ�����Ŀ�������ݽ���һ�����������������������ǰ�����򡢺������
//ÿ�ֱ���������һ�У�ÿ�����һ������֮����һ���ո�
//��ʾ��
//�����п������ظ�Ԫ�أ���������Ķ��������������������ظ�Ԫ�ز������
#include <stdio.h>
#include <string.h>

struct Node
{
    Node* rchild;//������
    Node* lchild;//������
    int c;//��ֵ
}Tree[110];//��̬����

int loc;//��̬�����б�ʹ��Ԫ�ظ���
Node* creat()
{//����δʹ�õĽڵ�
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void preOrder(Node* T)
{//ǰ�����
    printf("%d ",T -> c);
    if(T -> lchild != NULL)
    {
        preOrder(T -> lchild);
    }
    if(T -> rchild != NULL)
    {
        preOrder(T -> rchild);
    }
}
void inOrder(Node* T)
{//�������
    if(T -> lchild != NULL)
    {
        inOrder(T -> lchild);
    }
    printf("%d ",T -> c);
    if(T -> rchild != NULL)
    {
        inrder(T -> rchild);
    }
}
void postOrder(Node* T)
{//�������
    if(T -> lchild != NULL)
    {
        inOrder(T -> lchild);
    }
    if(T -> rchild != NULL)
    {
        inOrder(T -> rchild);
    }
    printf("%d ",T -> c);
}

Node* insert(Node* T,int x)
{//�������ֵ�������������
    if(T == NULL)
    {//��ǰ��Ϊ��
        T = creat();//�����ڵ�
        T -> c = x;//������ֵ
        return T;//���ظ��ڵ�
    }
    else if(x < T -> c)
    {//�ȵ�ǰ���ڵ���ֵС
        T -> lchild = insert(T -> lchild,x);//���뵽������ȥ
    }
    else if(x > T -> c)
    {//�ȵ�ǰ���ڵ���ֵ��
        T -> rchild = insert(T -> rchild,x);//���뵽������ȥ
    }
    //������ȵ�Ԫ��
    return T;//���ظ��ڵ�
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        loc = 0;//��ʼ��
        Node* T = NULL;//��ʼ������������
        for(int i = 0;i < n;i++)
        {
            int x;
            scanf("%d",&x);//������ֵ
            T = insert(T,x);//�������������
        }
        //printf("\nǰ������");
        preOrder(T);printf("\n");
        //printf("\n��������");
        inOrder(T);printf("\n");
        //printf("\n��������");
        postOrder(T);printf("\n");
    }
    return 0;
}
