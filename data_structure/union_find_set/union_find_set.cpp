/* 幷查集算法模板
 *
 * 版本：
 * 递归Find函数
 * 普通合并函数
 *
 * 题意：
 * 给n个点m个操作
 * 初始每个点单独一个集合
 * 两种操作
 * 1 a b 代表合并a与b
 * 2 a b 代表查询a与b是否在同一个集合，是则输出Yes，否则No
 *
 * 数据：
 * N 表示点的最大数量
 * M 表示操作的最大数量
 * n 表示点的数量   编号1~n
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 10000;

int father[N];
int n, m;

void InitRead();

void DataProcess();

int Find(int x);

void Union(int x, int y);

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
    for (int i=0; i<N; ++i)
    {
        father[i] = i;
    }
    return;
}

void DataProcess()
{
    int a, b, c;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1)
        {
            Union(b, c);
        }
        else
        {
            puts(Find(b) == Find(c) ? "Yes" : "No");
        }
    }
    return;
}

int Find(int x)
{
    return x == father[x] ? x : father[x] = Find(father[x]);
}

void Union(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    father[fx] = fy;
    return;
}
