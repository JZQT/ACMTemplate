/* 最小生成树kruskal算法模板
 * 
 * 版本：
 * 邻接矩阵存图
 * 
 * 注意：
 * 本算法适用于无向图
 * 
 * 题意：
 * 在无向图中，给n个点和m条边以及边权
 * 求这个图的最小生成树的权值
 * 考虑重边
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
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1001;

struct Edge     //存储边的结构体
{
    int a, b;   //边连接的两点
    int w;      //边权
};

int mat[N][N];
Edge edge[N*N]; //存储边的数组
int en;         //去重后的边数
int father[N];
int n, m;

void InitRead();

void DataProcess();

int Find(int x);

void Union(int x, int y);

int Kruskal();

bool cmp(Edge a, Edge b)    //边的排序函数，升序排
{
    return a.w < b.w;
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
    en = 0;
    memset(mat, -1, sizeof(mat));
    for (int i=0; i<N; ++i) father[i] = i;
    int a, b, c;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        mat[a][b] = mat[b][a] = mat[a][b] == -1 ? c : min(mat[a][b], c);    //判重
    }
    return;
}

void DataProcess()
{
    for (int i=1; i<=n; ++i)        //用一维数组存储无向图的边
    {
        for (int j=1; j<i; ++j)
        {
            if (mat[i][j] == -1) continue;
            edge[en].a = i;
            edge[en].b = j;
            edge[en++].w = mat[i][j];
        }
    }
    printf("%d\n", Kruskal());
    return;
}

int Find(int x)
{
    return father[x] == x ? x : father[x] = Find(father[x]);
}

void Union(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    father[fx] = fy;
    return;
}

int Kruskal()
{
    int ans = 0;
    sort(edge, edge+en, cmp);
    for (int i=0; i<en; ++i)
    {
        if (Find(edge[i].a) != Find(edge[i].b))
        {
            Union(edge[i].a, edge[i].b);
            ans += edge[i].w;
        }
    }
    return ans;
}
