/* 单源最短路dijkstra算法模板
 * 
 * 版本：
 * 邻接矩阵存图
 *
 * 注意：
 * 该算法适用于有向图和无向图
 *
 * 题意：
 * 在无向图中，给n个点和m条边，以及起点和终点。
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

using namespace std;

const int N = 1001;
const int INF = 0x3f3f3f3f;
const int inf = 0x3f;

int map[N][N];
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
    memset(map, inf, sizeof(map));
    scanf("%d %d", &start, &goal);
    int a, b, c;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        //不会存储重边，只存储最短的边
        map[a][b] = map[b][a] = min(map[a][b], c);
    }
    return;
}

void DataProcess()
{
    Dijkstra(start);
    printf("%d\n", dis[goal]);
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
        vis[k] = true;      //表示从起点到k的最短路找到了
        for (int j=1; j<=n; ++j)
        {
            if (!vis[j] && dis[j] > dis[k] + map[k][j])
            {
                dis[j] = dis[k] + map[k][j];
            }
        }
    }
    return;
}
