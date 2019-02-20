//二叉排序树：对于树上的任意节点，其上的数值大于其左子树的任意节点数值，小于其右子树的任意节点数值
//特点：中序遍历结果必是递增序列

//题目：
//输入一系列整数，建立二叉排序树，并进行前序、中序后序遍历
//输入：
//输入第一行包括一个整数n（1<=n<=100）。接下来的一行包括n个整数
//输出：
//可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对其进行前序、中序、后序遍历
//每种遍历结果输出一行，每行最后一个数据之后有一个空格
//提示：
//输入中可能有重复元素，但是输出的二叉排序树遍历序列中重复元素不用输出
#include <stdio.h>
#include <string.h>

struct Node
{
    Node* rchild;//右子树
    Node* lchild;//左子树
    int c;//数值
}Tree[110];//静态数组

int loc;//静态数组中被使用元素个数
Node* creat()
{//申请未使用的节点
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void preOrder(Node* T)
{//前序遍历
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
{//中序遍历
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
{//后序遍历
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
{//插入数字到二叉排序树中
    if(T == NULL)
    {//当前树为空
        T = creat();//建立节点
        T -> c = x;//保存数值
        return T;//返回根节点
    }
    else if(x < T -> c)
    {//比当前根节点数值小
        T -> lchild = insert(T -> lchild,x);//插入到左子树去
    }
    else if(x > T -> c)
    {//比当前根节点数值大
        T -> rchild = insert(T -> rchild,x);//插入到右子树去
    }
    //忽略相等的元素
    return T;//返回根节点
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        loc = 0;//初始化
        Node* T = NULL;//初始化二叉排序树
        for(int i = 0;i < n;i++)
        {
            int x;
            scanf("%d",&x);//输入数值
            T = insert(T,x);//插入二叉排序树
        }
        //printf("\n前序排序");
        preOrder(T);printf("\n");
        //printf("\n中序排序");
        inOrder(T);printf("\n");
        //printf("\n后序排序");
        postOrder(T);printf("\n");
    }
    return 0;
}
