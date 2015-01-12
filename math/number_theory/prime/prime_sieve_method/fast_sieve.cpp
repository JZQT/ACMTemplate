/* 快速线性筛法模板
 * 
 * 题意：
 * 输出1~N之间的素数表
 * 
 * 数据：
 * N 表示素数的最大范围
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000001;

bool isprime[N];    //是否为素数
int primes[N], pn;  //素数表与表中素数个数

void InitRead();

void DataProcess();

int main()
{
    InitRead();
    DataProcess();
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
    for (int i=2; i<N; ++i)
    {
        if (isprime[i]) primes[pn++] = i;
        for (int j=0; j<pn && i*primes[j]<N; ++j)
        {
            isprime[i*primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
    for (int i=0; i<pn; ++i)
    {
        printf("%d ", primes[i]);
    }
    return;
}
