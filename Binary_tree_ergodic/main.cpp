//����������
//���壺
//ǰ��������ȷ��ʸ����ٷ��������������ٷ�����������
//����������ȷ��������������ٷ��ʸ����ٷ�����������
//����������ȷ��������������ٷ��������������ٷ��ʸ�
//��Ŀ��
//����ǰ���������������ܹ�ȷ��Ψһ�ĺ������
//���룺
//�����ַ������䳤��n��С�ڵ���26
//��һ��Ϊǰ��������ڶ���Ϊ�����������������Դ�д��ĸ��ʾ
//�����
//�������������ж��飬����ÿ��������������һ�У�Ϊ��������ַ���

#include <stdio.h>
#include <string.h>

struct Node
{//�����ṹ��
    Node *rchild;//������ָ��
    Node *lchild;//������ָ��
    char c;//����ַ���Ϣ
}Tree[50];//��̬�ڴ��������

int loc;//��̬�������Ѿ�����Ľ�����

Node* creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];//����ָ�룬loc�ۼ�
}

char str1[30],str2[30];//����ǰ��������������ַ���

void postOrder(Node *T)
{//�������
    if(T -> lchild != NULL)
    {//������������
        postOrder(T -> lchild);
    }
    if(T -> rchild != NULL)
    {//������������
        postOrder(T -> rchild);
    }
    printf("%c",T -> c);//���ʸ�
}

Node* build(int s1,int e1,int s2,int e2)
{//���ַ�����ǰ������������ԭ���������������㣬ǰ��Ϊstr1[s1]��str1[e1]������Ϊstr2[s2]��str2[e2]
    Node* ret = creat();//Ϊ�������������ռ�
    ret -> c = str1[s1];//ǰ���������ĵ�һ����Ϊ���ڵ�
    int rootidx;//��ǰ���ڵ������������λ��
    for(int i = s2;i <= e2;i++)
    {//��õ�ǰ���ڵ������������λ��
        if(str2[i] == str1[s1])
        {
            rootidx = i;
            break;
        }
    }
    if(rootidx != s2)
    {//��ԭ������
        ret -> lchild = build(s1 + 1,s1 + (rootidx - s2),s2,rootidx - 1);
    }
    if(rootidx != e2)
    {//��ԭ������
        ret -> rchild = build(s1 + (rootidx - s2) + 1,e1,rootidx + 1,e2);
    }
    return ret;
}

int main()
{
    while(scanf("%s",str1) != EOF)
    {
        scanf("%s",str2);//����
        loc = 0;//��ʼ��
        int L1 = strlen(str1);
        int L2 = strlen(str2);
        Node* T = build(0,L1 - 1,0,L2 - 1);//��ԭ��
        postOrder(T);//�������
        printf("\n");
    }
    return 0;
}
