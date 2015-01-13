/* 快速线性筛法模板
 * 
 * 题意：
 * 输出1~n之间的素数表
 * 
 * 数据：
 * N 表示n的最大值
 * n 表示筛素数的最大范围
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000001;

bool isprime[N];    //是否为素数
int primes[N], pn;  //素数表与表中素数个数
int n;

void InitRead();

void DataProcess();

void FastSieve(int maxn);   //快速线性筛法筛出区间[1,maxn)内的素数表

int main()
{
    while (~scanf("%d", &n))
    {
        InitRead();
        DataProcess();
    }
    return 0;
}

void InitRead()
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    pn = 0;
    return;
}

void DataProcess()
{
    FastSieve(n + 1);   //这是筛[1, n]区间内的素数
    for (int i=0; i<pn; ++i)
    {
        printf("%d%c", primes[i], i == pn - 1 ? '\n' : ' ');
    }
    return;
}

void FastSieve(int maxn)
{
    for (int i=2; i<maxn; ++i)
    {
        if (isprime[i]) primes[pn++] = i;
        for (int j=0; j<pn; ++j)
        {
            if (i * primes[j] >= maxn) break;
            isprime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
    return;
}
