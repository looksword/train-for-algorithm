//二叉树遍历
//定义：
//前序遍历：先访问根，再访问其左子树，再访问其右子树
//中序遍历：先访问其左子树，再访问根，再访问其右子树
//后序遍历：先访问其左子树，再访问其右子树，再访问根
//题目：
//给定前序遍历和中序遍历能够确定唯一的后序遍历
//输入：
//两个字符串，其长度n均小于等于26
//第一行为前序遍历，第二行为中序遍历。结点名称以大写字母表示
//输出：
//输入样例可能有多组，对于每组测试样例，输出一行，为后序遍历字符串

#include <stdio.h>
#include <string.h>

struct Node
{//树结点结构体
    Node *rchild;//右子树指针
    Node *lchild;//左子树指针
    char c;//结点字符信息
}Tree[50];//静态内存分配数组

int loc;//静态数组中已经分配的结点个数

Node* creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];//返回指针，loc累加
}

char str1[30],str2[30];//保存前序和中序遍历结果字符串

void postOrder(Node *T)
{//后序遍历
    if(T -> lchild != NULL)
    {//遍历其左子树
        postOrder(T -> lchild);
    }
    if(T -> rchild != NULL)
    {//遍历其右子树
        postOrder(T -> rchild);
    }
    printf("%c",T -> c);//访问根
}

Node* build(int s1,int e1,int s2,int e2)
{//由字符串的前序和中序遍历还原树，并返回其根结点，前序为str1[s1]到str1[e1]，中序为str2[s2]到str2[e2]
    Node* ret = creat();//为该树根结点申请空间
    ret -> c = str1[s1];//前序遍历结果的第一个即为根节点
    int rootidx;//当前根节点在中序遍历的位置
    for(int i = s2;i <= e2;i++)
    {//获得当前根节点在中序遍历的位置
        if(str2[i] == str1[s1])
        {
            rootidx = i;
            break;
        }
    }
    if(rootidx != s2)
    {//还原左子树
        ret -> lchild = build(s1 + 1,s1 + (rootidx - s2),s2,rootidx - 1);
    }
    if(rootidx != e2)
    {//还原右子树
        ret -> rchild = build(s1 + (rootidx - s2) + 1,e1,rootidx + 1,e2);
    }
    return ret;
}

int main()
{
    while(scanf("%s",str1) != EOF)
    {
        scanf("%s",str2);//输入
        loc = 0;//初始化
        int L1 = strlen(str1);
        int L2 = strlen(str2);
        Node* T = build(0,L1 - 1,0,L2 - 1);//还原树
        postOrder(T);//后序遍历
        printf("\n");
    }
    return 0;
}
