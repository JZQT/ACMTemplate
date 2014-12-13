/* 最大公约数及最小公倍数算法模板
 *
 * 版本：
 * 辗转相除法求最大公约数
 * 
 * 注意：
 * 本算法适用于正整数
 *
 * 题意：
 * 给两个正整数
 * 输出这两个正整数的最大公约数及最小公倍数
 * 
 * 数据：
 * x, y 代表两个正整数，范围不超过long long
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LONG;

inline LONG Gcd(LONG a, LONG b);    //辗转相除法求最大公约数

inline LONG Lcm(LONG a, LONG b);    //求最小公倍数

int main()
{
    LONG x, y;
    while (~scanf("%lld %lld", &x, &y))
    {
        printf("%lld %lld\n", Gcd(x, y), Lcm(x, y));
    }
    return 0;
}

inline LONG Gcd(LONG a, LONG b)
{
    return b == 0 ? a : Gcd(b, a % b);
}

inline LONG Lcm(LONG a, LONG b)
{
    return a / Gcd(a, b) * b;   //先乘再除可能导致类型范围溢出
}
