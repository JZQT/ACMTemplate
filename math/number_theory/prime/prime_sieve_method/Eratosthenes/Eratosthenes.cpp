/* 埃氏筛法模板
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

const int N = 1000001;

bool isprime[N];    //是否为素数
int primes[N], pn;  //素数表与表中素数个数
int n;

void InitRead();

void DataProcess();

void Eratosthenes(int maxn);    //埃氏筛法筛[1,maxn)里的素数

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
    Eratosthenes(n + 1);    //筛[1,n]区间内的素数
    for (int i=0; i<pn; ++i)
    {
        printf("%d%c", primes[i], i == pn - 1 ? '\n' : ' ');    //输出素数表
    }
    return;
}

void Eratosthenes(int maxn)
{
    for (int i=2; i<maxn; ++i)
    {
        if (!isprime[i]) continue;  //筛出素数
        primes[pn++] = i;           //加入素数表
        for (int j=2*i; j<maxn; j+=i)  //标记该素数的倍数为合数
        {
            isprime[j] = false;
        }
    }
    return;
}
