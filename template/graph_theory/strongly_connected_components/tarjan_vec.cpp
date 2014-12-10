/* 强连通分量tarjan算法模板
 * 版本：
 * vector存图
 * 缩点
 * 
 * 题意：在有向图中，给n个点m条边。
 * 求出其中强连通分量的个数。
 * 保证无重边与自环。
 * 
 * N 表示图中节点的最大数量
 * M 表示图中边的最大数量
 * n 表示图中节点的数量    编号1~n
 * m 表示图中边的数量
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100001;

vector <int> e[N];
int dfn[N], low[N];
int stack[N], stop; //手写栈
bool instack[N];    //判断该点是否在栈中
int belong[N];      //存储该点属于哪一个强连通分量
int timer;          //时间戳
int sccn;           //强连通分量个数
int n, m;

void InitRead();

void DataProcess();

void Tarjan(int x);

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
    memset(dfn, 0, sizeof(dfn));
    memset(instack, false, sizeof(instack));
    stop = timer = sccn = 0;
    for (int i=1; i<=n; ++i) e[i].clear();
    int a, b;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
    }
    return;
}

void DataProcess()
{
    for (int i=1; i<=n; ++i)
    {
        if (!dfn[i])
        {
            Tarjan(i);
        }
    }
    printf("%d\n", sccn);
    return;
}

void Tarjan(int x)
{
    int y;
    dfn[x] = low[x] = ++timer;
    stack[stop++] = x;
    instack[x] = true;;
    int size = e[x].size();
    for (int i=0; i<size; ++i)
    {
        y = e[x][i];
        if (!dfn[y])            //节点未遍历
        {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (instack[y])    //节点在栈中
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x])   //此时代表找到一个强连通分量
    {
        sccn++;
        do
        {
            y = stack[--stop];
            instack[y] = false;
            belong[y] = sccn;
        } while (x != y);
    }
    return;
}
