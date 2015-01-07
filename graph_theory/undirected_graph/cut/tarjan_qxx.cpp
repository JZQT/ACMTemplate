/* 求割顶和割边tarjan算法模板
 * 
 * 版本：
 * 链式前向星存图
 * 
 * 注意：
 * 本算法适用与无向图
 *
 * 题意：
 * 在一个无向图中，给n个点和m条边
 * 输出割点的编号以及割去该点后多出的连通分量个数
 * 输出割边连接的两个点的编号(要求左边的点编号比右边小)
 * 
 * 数据：
 * N 表示图中节点的最大数量
 * M 表示图中边的最大数量
 * n 表示图中节点的数量             编号1~n
 * m 表示图中边的数量
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100000;
const int M = 300000;

struct Edge
{
    int to, next;
    bool iscut;     //判断该边是否为桥
};

Edge e[M];
int head[N];
int dfn[N], low[N];
int add_block[N];   //割去该点后多出的连通分量个数，割点的值不为0
int timer;
int n, m;

void InitRead();

void DataProcess();

void Tarjan(int x, int fx);

inline void AddEdge(int from, int to, int id)
{
    e[id].to = to;
    e[id].next = head[from];
    head[from] = id;
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
    timer = 0;
    memset(head, -1, sizeof(head));
    memset(add_block, 0, sizeof(add_block));
    memset(dfn, 0, sizeof(dfn));
    int a, b;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d", &a, &b);
        AddEdge(a, b, i*2);
        AddEdge(b, a, i*2+1);
        e[i*2].iscut = false;       //初始化边不为割边
        e[i*2+1].iscut = false;
    }
    return;
}

void DataProcess()
{
    for (int i=1; i<=n; ++i)
    {
        if (!dfn[i]) Tarjan(i, i);
    }
    for (int i=1; i<=n; ++i)    //输出割点及其分割后多出的连通分量个数
    {
        printf("%d %d\n", i, add_block[i]);
    }
    for (int i=1; i<=n; ++i)    //输出割边
    {
        for (int j=head[i]; j!=-1; j=e[j].next)
        {
            if (e[j].iscut)
            {
                printf("%d %d\n", i, e[j].to);
            }
        }
    }
    return;
}

void Tarjan(int x, int fx)
{
    dfn[x] = low[x] = ++timer;
    int child = 0;
    for (int i=head[x]; i!=-1; i=e[i].next)
    {
        int y = e[i].to;
        if (!dfn[y])
        {
            child++;
            Tarjan(y, x);
            low[x] = min(low[x], low[y]);
            if (x != fx && low[y] >= dfn[x])    //非根节点的割点判断
            {
                add_block[x]++;
            }
            if (low[y] == dfn[y])   //割边的判断，有多种写法
            {
                e[i].iscut = true;
            }
        }
        else
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (x == fx && child > 1)   //根节点的割点判断
    {
        add_block[x] = child - 1;
    }
    return;
}
