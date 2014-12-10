/* 单源最短路dijkstra算法模板
 * 
 * 版本：
 * vector存图
 *
 * 注意：
 * 该算法适用于有向图和无向图
 *
 * 题意：
 * 在有向图中，给n个点和m条边，以及起点和终点。
 * 求从起点到终点花费的最小权值。
 * 如果不能从起点到达终点输出-1。
 * 可能有重边，但无自环。
 *
 * 数据：
 * N 表示图中节点的最大数量
 * M 表示图中边的最大数量
 * INF 表示两节点的边权为无限大（或者可以理解为两节点无直接相连的边）
 * n 表示图中节点的数量     编号1~n
 * m 表示图中边的数量
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1001;
const int INF = 0x3f3f3f3f;
const int inf = 0x3f;

struct edge     //定义边结构体
{
    int to;     //存储到达的点
    int len;    //存储边的权值
};

vector <edge> e[N];
int dis[N];     //dis[i]表示起点到i点花费的最小权值
int n, m, start, goal;

void InitRead();

void DataProcess();

void Dijkstra(int s);

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
    memset(dis, inf, sizeof(dis));
    for (int i=1; i<=n; ++i) e[i].clear();
    scanf("%d %d", &start, &goal);
    int a, b, c;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge temp = {b, c};
        e[a].push_back(temp);
    }
    return;
}

void DataProcess()
{
    Dijkstra(start);
    printf("%d\n", dis[goal] == INF ? -1 : dis[goal]);
    return;
}

void Dijkstra(int s)
{
    bool vis[N];
    memset(vis, false, sizeof(vis));
    dis[s] = 0;
    for (int i=1; i<=n; ++i)
    {
        int minl = INF;
        int k = 0;
        for (int j=1; j<=n; ++j)
        {
            if (!vis[j] && minl > dis[j])
            {
                minl = dis[k = j];
            }
        }
        vis[k] = true;
        int size = e[k].size();
        for (int j=0; j<size; ++j)
        {
            int to = e[k][j].to;
            int len = e[k][j].len;
            if (!vis[to] && dis[to] > dis[k] + len)
            {
                dis[to] = dis[k] + len;
            }
        }
    }
    return;
}
