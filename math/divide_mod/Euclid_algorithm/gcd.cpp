// 欧几里得算法模板
//
// 注意：
// 本算法适用于正整数
//
// 题意：
// 给两个正整数
// 输出这两个正整数的最大公约数及最小公倍数
// 
// 数据：
// x, y 代表两个正整数，范围不超过long long
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long Long;

Long Gcd(Long a, Long b);    //欧几里得算法求最大公约数

Long Lcm(Long a, Long b);    //求最小公倍数

int main()
{
    Long x, y;
    while (~scanf("%lld %lld", &x, &y))
    {
        printf("%lld %lld\n", Gcd(x, y), Lcm(x, y));
    }
    return 0;
}

Long Gcd(Long a, Long b)
{
    return b == 0 ? a : Gcd(b, a % b);
}

Long Lcm(Long a, Long b)
{
    return a / Gcd(a, b) * b;   //先除再乘避免类型范围溢出
}
