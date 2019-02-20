//有N个学生的数据，将学生数据按成绩高低排序，如果成绩相同则按姓名字符的字母序排序，
//如果姓名的字母序也相同则按照学生的年龄排序，并输出N个学生的排序后的信息
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct E
{
    char name[101];
    int age;
    int score;
	//定义该结构体的小于运算符
    bool operator < (const E &b)const
	{
        if(score != b.score)return score < b.score;
        int tmp = strcmp(name,b.name);
        if(tmp != 0)return tmp < 0;
        else return age < b.age;
	}
}buf[1000];

int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i++)
        {
            scanf("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);//输入
        }
        sort(buf,buf + n);
        for(int i = 0;i < n;i++)
        {
            printf("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);//输出
        }
    }
    return 0;
}
