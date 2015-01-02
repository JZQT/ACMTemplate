/* 存图模板
 * 
 * 版本：
 * 链式前向星
 * 
 * 特点：
 * 不能直接判断重边
 * 耗内存较少
 * 
 * 题意：
 * 给一个n个点m条边的有向图
 * 按照邻接表方式输出该图信息
 * 
 * 数据：
 * N 表示图中节点的最大数量
 * M 表示图中边的最大数量
 * n 表示图中节点的数量         编号0~n-1
 * m 表示图中边的数量
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100001;
const int M = 300001;

struct Edge
{
    int to, next;
};

int head[N];
Edge e[M];
int n, m;

void InitRead();

void DataProcess();

//加边函数，按具体情况决定是否添加head指针和edge指针参数
inline void AddEdge(int a, int b, int id)
{
    e[id].to = b;
    e[id].next = head[a];
    head[a] = id;
    return;
}

int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        InitRead();
        DataProcess();
    }
    return 0;
}

void InitRead()
{
    memset(head, -1, sizeof(head)); //初始化前向星
    int a, b;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d", &a, &b);
        AddEdge(a, b, i);   //第i条边存储a->b的边信息
    }
    return;
}

void DataProcess()
{
    for (int i=0; i<n; ++i)
    {
        printf("%d : ", i);
        for (int j=head[i]; j!=-1; j=e[j].next)
        {
            printf("%d ", e[j].to);
        }
    }
    return;
}
