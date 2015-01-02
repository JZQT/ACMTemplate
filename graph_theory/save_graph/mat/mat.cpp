/* 存图模板
 * 
 * 版本：
 * 邻接矩阵
 * 
 * 特点：
 * 可直接判断重边
 * 耗内存较多
 * 
 * 题意：
 * 给一个n个点m条边的有向图
 * 每条边有一个非负整数权值
 * 按照邻接矩阵方式输出该图信息
 * 重边只存储权值最小的边
 * -1代表没有边
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

const int N = 1001;

int mat[N][N];
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
    memset(mat, -1, sizeof(mat));
    int a, b, c;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        mat[a][b] = mat[a][b] == -1 ? c : min(c, mat[a][b]);    //判重边
    }
    return;
}

void DataProcess()
{
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            printf("%d ", mat[i][j]);
        }
    }
    return;
}
