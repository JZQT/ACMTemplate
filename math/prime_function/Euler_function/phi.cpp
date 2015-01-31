// 求欧拉函数单值算法模板
//
// 注意：
// 本算法适用与正整数
//
// 题意：
// 输入一个正整数x，输出它的欧拉函数值
//
// 数据：
// x 代表一个正整数，范围不超过long long
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long Long;

Long Phi(Long x);

int main()
{
    Long x;
    while (~scanf("%lld", &x))
    {
        printf("%lld\n", Phi(x));
    }
    return 0;
}

Long Phi(Long x)
{
    Long ans = x;
    for (int i=2; i*i<=x; ++i)
    {
        if (x % i == 0)
        {
            ans -= ans / i;         //由 ans = ans * (i - 1) / i; 化简而来
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans -= ans / x;
    return ans;
}
