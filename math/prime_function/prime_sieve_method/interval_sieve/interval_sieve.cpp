// 区间筛素数模板
//
// 题意：
// 给一个区间的左右端点l，r(1 <= l <= r <= INT_MAX 且 r - l <= 1000000)
// 输出这个区间内的素数
// 
// 数据：
// N 表示预处理筛素数的最大范围
// M 表示区间最大范围
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long Long;

const int N = 50001;
const int M = 1000001;

bool isprime[N];
int primes[N], pn;
bool notprime[M];
int range_primes[M], rn;
int l, r;

void InitRead();

void DataProcess();

void FastSieve(int maxn);

void IntervalSieve(int left, int right);

int main()
{
    InitRead();
    while (~scanf("%d %d", &l, &r))
    {
        DataProcess();
    }
    return 0;
}

void InitRead()
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    pn = 0;
    FastSieve(N);
    return;
}

void DataProcess()
{
    memset(notprime, false, sizeof(notprime));
    rn = 0;
    IntervalSieve(l, r);
    for (int i=0; i<rn; ++i)
    {
        printf("%d%c", range_primes[i], i == rn - 1 ? '\n' : ' ');
    }
    return;
}

void FastSieve(int maxn)
{
    for (int i=2; i<=maxn; ++i)
    {
        if (isprime[i]) primes[pn++] = i;
        for (int j=0; j<pn; ++j)
        {
            if (i * primes[j] > maxn) break;
            isprime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
    return;
}

void IntervalSieve(int left, int right)
{
    if (left < 2) left = 2;
    for (int i=0; i<pn; ++i)
    {
        if ((Long)primes[i] * primes[i] > right) break;
        int temp = left / primes[i] + left % primes[i] == 0 ? 0 : 1;
        if (temp == 1) temp = 2;
        for (int j=temp; (Long)j*primes[i]<=right; ++j)
        {
            if ((Long)j * primes[i] >= left)
            {
                notprime[(Long)j * primes[i] - left] = true;
            }
        }
    }
    int cnt = right - left + 1;
    for (int i=0; i<cnt; ++i)
    {
        if (!notprime[i])
        {
            range_primes[rn++] = left + i;
        }
    }
    return;
}
