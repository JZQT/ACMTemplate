/* C++STL快排sort算法模板
 * 
 * 演示：
 * 使用无比较函数参数的sort进行整数升序排序
 * 自定义比较函数进行点结构体的排序，优先x坐标升序排序，其次y坐标降序排序
 * 
 * 数据：
 * N 代表需要排序的元素个数     编号0~n-1
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;

struct point
{
    int x, y;
};

int num[N] = {3, 5, 1, 8, 9, 2, 4, 7, 6, 0};
point obj[N] = {{1, 3}, {2, 1}, {4, 6}, {3, 7}, {2, 8},
                {5, 4}, {3, 9}, {4, 2}, {0, 1}, {5, 1}};

bool cmp(point a, point b)      //自定义比较函数，x坐标升序排，y坐标降序排
{
    return a.x == b.x ? a.y > b.y : a.x < b.x;
}

int main()
{
    sort(num, num+N);       //使用无比较函数参数sort
    for (int i=0; i<N; ++i)
    {
        printf("%d%c", num[i], i == N - 1 ? '\n' : ' ');
    }
    sort(obj, obj+N, cmp);  //使用自定义比较函数参数
    for (int i=0; i<N; ++i)
    {
        printf("(%d, %d)\n", obj[i].x, obj[i].y);
    }
    return 0;
}
