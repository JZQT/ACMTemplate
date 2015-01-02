/* 存图模板
 * 
 * 版本：
 * vector邻接表
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
#include <vector>

using namespace std;

const int N = 100001;

vector<int> e[N];
int n, m;

void InitRead();

void DataProcess();

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
    for (int i=0; i<n; ++i)     //初始化清空邻接表
    {
        e[i].clear();
    }
    int a, b;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);      //存储一条a->b的边
    }
    return;
}

void DataProcess()
{
    for (int i=0; i<n; ++i)
    {
        printf("%d : ", i);
        int size = e[i].size();
        for (int j=0; j<size; ++j)
        {
            printf("%d ", e[i][j]);
        }
    }
    return;
}
