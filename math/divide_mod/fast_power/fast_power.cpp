// 快速幂模板
// 
// 版本：
// 快速乘实现快速幂
//
// 注意：
// 本算法适用于非负整数
// 0^0 == 1
// 
// 题意：
// 给三个非负整数x, y, m
// 输出 x^y % m
// 
// 数据：
// x, y, m 代表三个非负整数，范围不超过long long
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long Long;

//快速乘    求 a*b % mod
Long FastMul(Long a, Long b, Long mod);

//快速幂    求 a^b % mod
Long FastPow(Long a, Long b, Long mod);

int main()
{
    Long x, y, m;
    while (~scanf("%lld %lld %lld", &x, &y, &m))
    {
        printf("%lld\n", FastPow(x, y, m));
    }
    return 0;
}

Long FastMul(Long a, Long b, Long mod)
{
    Long ans = 0;
    a %= mod;
    b %= mod;
    while (b)
    {
        if (b & 1)
        {
            ans += a;
            ans %= mod;
        }
        b >>= 1;
        a <<= 1;
        a %= mod;
    }
    return ans;
}

Long FastPow(Long a, Long b, Long mod)
{
    Long ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1) ans = FastMul(ans, a, mod);
        a = FastMul(a, a, mod);
        b >>= 1;
    }
    return ans;
}
