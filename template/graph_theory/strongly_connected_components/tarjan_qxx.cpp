/* 强连通分量tarjan算法模板
 *
 * 版本：
 * 链式前向星存图
 * 强连通分量缩点
 * 建强连通分量图
 * 
 * 注意：
 * 本算法适用于有向图
 *
 * 题意：
 * 在有向图中，给n个点m条边。
 * 求缩点后强连通分量图中的最长路径权值（关键路径）。
 * 每个强连通分量的权值为每个点的权值和。
 * 
 * 数据：
 * N 表示图中节点的最大数量
 * M 表示图中边的最大数量
 * n 表示图中节点的数量             编号1~n
 * m 表示图中边的数量
 * sccn 表示图中强连通分量的数量    编号1~sccn
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
    int to;
    int next;
};

Edge e[M], scce[M];
int head[N], scchead[N];
int dfn[N], low[N];
int stack[N], stop;     //手写栈
bool instack[N];        //判断该点是否在栈中
int belong[N];          //存储该点属于哪一个强连通分量
int timer;              //时间戳
int sccn;               //强连通分量个数
int indeg[N];           //存储强连通点的入度
int weight[N];          //点权值
int sccw[N];            //强连通分量权值
int sccen;              //强连通图的边数
int ans;
int n, m;

inline void AddEdge(Edge edge[], int h[], int from, int to, int x);

void InitRead();

void DataProcess();

void Tarjan(int x);

void Dfs(int x, int w); //dfs求强连通分量图的最长路径，可dp优化

int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        InitRead();
        DataProcess();
    }
    return 0;
}

inline void AddEdge(Edge edge[], int h[], int from, int to, int id)
{
    edge[id].to = to;
    edge[id].next = h[from];
    h[from] = id;
    return;
}

void InitRead()
{
    sccen = ans = stop = timer = sccn = 0;
    memset(head, -1, sizeof(head));
    memset(scchead, -1, sizeof(scchead));
    memset(dfn, 0, sizeof(dfn));
    memset(instack, false, sizeof(instack));
    memset(indeg, 0, sizeof(indeg));
    for (int i=1; i<=n; ++i) 
    {
        scanf("%d", &weight[i]);    //输入点权
    }
    int a, b;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d", &a, &b);
        AddEdge(e, head, a, b, i);
    }
    return;
}

void DataProcess()
{
    for (int i=1; i<=n; ++i)    //Tarjan求强连通分量并缩点
    {
        if (!dfn[i])
        {
            Tarjan(i);
        }
    }
    for (int i=1; i<=n; ++i)    //缩点后建强连通分量图
    {
        for (int j=head[i]; j!=-1; j=e[j].next)
        {
            if (belong[i] != belong[e[j].to])
            {
                //注意这里的强连通的编号是belong[i]而不是i
                indeg[belong[e[j].to]]++;
                AddEdge(scce, scchead, belong[i], belong[e[j].to], sccen++);
            }
        }
    }
    for (int i=1; i<=sccn; ++i) //从入度为0处开始Dfs求解
    {
        if (indeg[i] == 0) 
        {
            Dfs(i, sccw[i]);
        }
    }
    printf("%d\n", ans);
    return;
}

void Tarjan(int x)
{
    int y;
    dfn[x] = low[x] = ++timer;
    stack[stop++] = x;
    instack[x] = true;
    for (int i=head[x]; i!=-1; i=e[i].next)
    {
        y = e[i].to;
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
        int w = 0;  //开始计算该强连通分量的权值
        do
        {
            y = stack[--stop];
            instack[y] = false;
            belong[y] = sccn;
            w += weight[y];
        } while (x != y);
        sccw[sccn] = w;
    }
    return;
}

void Dfs(int x, int w)
{
    if (scchead[x] == -1) ans = max(ans, w);
    for (int i=scchead[x]; i!=-1; i=scce[i].next)
    {
        Dfs(scce[i].to, w + sccw[scce[i].to]);
    }
    return;
}
