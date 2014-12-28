/* 快速幂取模算法模板
 * 
 * 版本：
 * 快速乘求快速幂
 *
 * 注意：
 * 本算法适用于非负整数
 * 0^0 == 1
 * 
 * 题意：
 * 给三个非负整数x, y, m
 * 输出 x^y % m
 * 
 * 数据：
 * x, y m代表三个非负整数，范围不超过long long
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LONG;

//快速乘    求 a*b % mod
LONG FastMul(LONG a, LONG b, LONG mod);

//快速幂    求 a^b % mod
LONG FastPow(LONG a, LONG b, LONG mod);

int main()
{
    LONG x, y, m;
    while (~scanf("%lld %lld %lld", &x, &y, &m))
    {
        printf("%lld\n", FastPow(x, y, m));
    }
    return 0;
}

LONG FastMul(LONG a, LONG b, LONG mod)
{
    LONG ans = 0;
    a %= mod, b %= mod;
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

LONG FastPow(LONG a, LONG b, LONG mod)
{
    LONG ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1) ans = FastMul(ans, a, mod);
        b >>= 1;
        a = FastMul(a, a, mod);
    }
    return ans;
}
