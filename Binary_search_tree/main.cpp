//题目：判断两序列是否为同一二叉搜索树
//输入：开始一个数n，（1<=n<=20）表示有n个需要判断，n=0的时候输入结束。
//      接下去一行是一个序列，序列长度小于10，包含0-9的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
//      接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
//输出：如果序列相同则输出YES，否则输出NO
#include <stdio.h>
#include <string.h>

struct Node
{//树节点结构体
    Node *lchild;
    Node *rchild;
    int c;
}Tree[110];
int loc;
Node *creat()
{//申请节点空间
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}
char str1[25],str2[25];//二叉搜索树的遍历结果（前序遍历和中序遍历的字符串连接）
int size1,size2;//在字符数组中的遍历得到字符个数
char *str;//当前字符串
int *size;//当前字符串中字符个数
void preOrder(Node* T)
{//前序遍历
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
{//中序遍历
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
    char tmp[12];
    while(scanf("%d",&n) != EOF && n != 0)
    {
        loc = 0;//初始化静态空间为未使用
        Node *T = NULL;
        scanf("%s",tmp);//输入字符串
        for(int i = 0;tmp[i] != 0;i++)
        {//建立二叉搜索树
            T = insert(T,tmp[i]-'0');//按顺序将数字插入二叉搜索树
        }
        size1 = 0;//保存在第一个字符串中的字符初始化为0
        str = str1;//将正在保存字符串设定为第一个字符串
        size = &size1;//将正在保存的字符串字符个数指针指向size1
        preOrder(T);//前序遍历
        inOrder(T);//中序遍历
        str1[size1] = 0;//字符串结尾添加空字符，方便使用字符串函数
        while(n-- != 0)
        {//输入n个其他字符串
            scanf("%s",tmp);//输入
            Node *T2 = NULL;
            for(int i = 0;tmp[i] != 0;i++)
            {//建立二叉搜索树
                T2 = insert(T2,tmp[i]-'0');//按顺序将数字插入二叉搜索树
            }
            size2 = 0;//第二个字符串中的字符初始化为0
            str = str2;//将正在保存字符串设定为第二个字符串
            size = &size2;//将正在保存的字符串字符个数指针指向size1
            preOrder(T2);//前序遍历
            inOrder(T2);//中序遍历
            str2[size2] = 0;//字符串结尾添加空字符，方便使用字符串函数
            puts(strcmp(str1,str2) == 0 ? "yes" : "NO");//比较两个遍历字符串，相同输出YES，否则输出NO
        }
    }
    return 0;
}
