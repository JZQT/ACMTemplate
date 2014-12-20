/* 求二分图最大匹配匈牙利算法模板
 * 
 * 版本：
 * vector存图
 *
 * 注意：
 * 如果对二分图所有点进行处理之后，得到的答案为二分图最大匹配的两倍。
 * 如果对二分图某一个点集进行处理，得到的答案刚好为二分图最大匹配数。
 * 
 * 题意：
 * 在一个无向二分图中，给n个点和m条边。
 * 求这个二分图的最大匹配数。
 * 
 * 数据：
 * N 表示图中节点的最大数量 
 * M 表示图中边的最大数量 
 * n 表示图中节点的数量     编号0~n-1
 * m 表示图中边的数量
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10000;

vector <int> e[N];
bool vis[N];
int match[N];       //存储匹配点
int n, m;

void InitRead();

void DataProcess();

int Hungary();

bool Dfs(int x);    //dfs找未匹配点或增广路

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
    memset(match, -1, sizeof(match));   //初始化每个点都未被匹配
    for (int i=0; i<n; ++i)
    {
        e[i].clear();
    }
    int a, b;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    return;
}

void DataProcess()
{
    printf("%d\n", Hungary());
    return;
}

int Hungary()
{
    int ans = 0;
    for (int i=0; i<n; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (Dfs(i)) ans++;
    }
    return ans / 2; //如果对二分图其中一个点集做Hungary算法，返回ans
}

bool Dfs(int x)
{
    int size = e[x].size();
    for (int i=0; i<size; ++i)
    {
        if (!vis[e[x][i]])
        {
            vis[e[x][i]] = true;
            if (match[e[x][i]] == -1 || Dfs(match[e[x][i]]))
            {
                match[e[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}
