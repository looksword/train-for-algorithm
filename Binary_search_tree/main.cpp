//��Ŀ���ж��������Ƿ�Ϊͬһ����������
//���룺��ʼһ����n����1<=n<=20����ʾ��n����Ҫ�жϣ�n=0��ʱ�����������
//      ����ȥһ����һ�����У����г���С��10������0-9�����֣�û���ظ����֣�����������п��Թ����һ�Ŷ�����������
//      ����ȥ��n����n�����У�ÿ�����и�ʽ����һ������һ�������ж������������Ƿ������ͬһ�Ŷ�����������
//��������������ͬ�����YES���������NO
#include <stdio.h>
#include <string.h>

struct Node
{//���ڵ�ṹ��
    Node *lchild;
    Node *rchild;
    int c;
}Tree[110];
int loc;
Node *creat()
{//����ڵ�ռ�
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}
char str1[25],str2[25];//�����������ı��������ǰ�����������������ַ������ӣ�
int size1,size2;//���ַ������еı����õ��ַ�����
char *str;//��ǰ�ַ���
int *size;//��ǰ�ַ������ַ�����
void preOrder(Node* T)
{//ǰ�����
    if(T -> lchild != NULL)
    {
        preOrder(T -> lchild);
    }
    if(T -> rchild != NULL)
    {
        preOrder(T -> rchild);
    }
    str[(*size)++] = T -> c + '0';
}
void inOrder(Node* T)
{//�������
    if(T -> lchild != NULL)
    {
        inOrder(T -> lchild);
    }
    str[(*size)++] = T -> c + '0';
    if(T -> rchild != NULL)
    {
        inOrder(T -> rchild);
    }
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
    char tmp[12];
    while(scanf("%d",&n) != EOF && n != 0)
    {
        loc = 0;//��ʼ����̬�ռ�Ϊδʹ��
        Node *T = NULL;
        scanf("%s",tmp);//�����ַ���
        for(int i = 0;tmp[i] != 0;i++)
        {//��������������
            T = insert(T,tmp[i]-'0');//��˳�����ֲ������������
        }
        size1 = 0;//�����ڵ�һ���ַ����е��ַ���ʼ��Ϊ0
        str = str1;//�����ڱ����ַ����趨Ϊ��һ���ַ���
        size = &size1;//�����ڱ�����ַ����ַ�����ָ��ָ��size1
        preOrder(T);//ǰ�����
        inOrder(T);//�������
        str1[size1] = 0;//�ַ�����β���ӿ��ַ�������ʹ���ַ�������
        while(n-- != 0)
        {//����n�������ַ���
            scanf("%s",tmp);//����
            Node *T2 = NULL;
            for(int i = 0;tmp[i] != 0;i++)
            {//��������������
                T2 = insert(T2,tmp[i]-'0');//��˳�����ֲ������������
            }
            size2 = 0;//�ڶ����ַ����е��ַ���ʼ��Ϊ0
            str = str2;//�����ڱ����ַ����趨Ϊ�ڶ����ַ���
            size = &size2;//�����ڱ�����ַ����ַ�����ָ��ָ��size1
            preOrder(T2);//ǰ�����
            inOrder(T2);//�������
            str2[size2] = 0;//�ַ�����β���ӿ��ַ�������ʹ���ַ�������
            puts(strcmp(str1,str2) == 0 ? "yes" : "NO");//�Ƚ����������ַ�������ͬ���YES���������NO
        }
    }
    return 0;
}