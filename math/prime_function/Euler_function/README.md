# 欧拉函数

## 概述

**欧拉函数**，也称为**欧拉phi函数**，是**数论领域**中的欧拉函数。

欧拉函数的定义为：**对于正整数n，欧拉函数是不大于n的正整数中与n互质的数的个数**。

## 欧拉函数公式

> **phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * (1 - 1/p3) * ··· * (1 - 1/pk)**

也可写做

> **phi(n) = n * ((p1-1) / p1) * ((p2-1) / p2) * ((p3-1) / p3) * ··· * ((pk-1) / pk)**

其中p1, p2, ··· , pk为n分解出的不同的质因数。

## 欧拉函数值的定义

1. phi(1) = 1
2. 如果n是素数p的k次幂，那么 **phi(n) = p^k - p^(k-1) = (p-1) * p^(k-1)**
3. 如果m与n互质，那么 **phi(m*n) = phi(m) * phi(n)**

由**以上定义**可以**推导出欧拉函数的递推式**，如下

令**p是n的最小质因数**，如果**p^2****能整除n**，那么 **phi(n) = phi(n/p) * p**，否则 **phi(n) = phi(n/p) * (p-1)**

## ACM竞赛中的欧拉函数的求法

* 求单个数的欧拉函数值

    直接利用**欧拉函数公式**来求，由于需要用到分解质因数，因此代码几乎一样，**时间复杂度为O(√n)**。代码如下
    ```cpp
    int Phi(int x)
    {
        int ans = x;
        for (int i=2; i*i<=n; ++i)
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
    ```

* 求欧拉函数表

    利用**欧拉函数公式**以及**欧拉函数值的定义**使用筛法求出欧拉函数表，如同筛素数表一样，同样有**埃氏筛**和**线性筛**两种筛法。

    **埃氏筛**求欧拉函数表的**原理**是利用**欧拉函数公式**，**时间复杂度为O(nlogn)**，**只需要开一个phi数组**。代码如下
    ```cpp
    int phi[N];

    void GetPhi(int maxn)       //求[0,maxn)内的phi表
    {
        memset(phi, 0, sizeof(phi));
        phi[1] = 1;
        for (int i=2; i<maxn; ++i)
        {
            if (!phi[i])    //满足该条件为素数
            {
                for (int j=i; j<maxn; j+=i)
                {
                    if (!phi[j]) phi[j] = j;
                    phi[j] -= phi[j] / i;       //由 phi[j] = phi[j] / i * (i - 1); 化简而来
                }
            }
        }
        return;
    }
    ```

    **线性筛**求欧拉函数表的**原理**是利用**欧拉函数递推式**，**时间复杂度为O(n)**，**除了必要的phi数组还需要开isprime和primes数组**。代码如下
    ```cpp
    bool isprime[N];
    int primes[N], pn;
    int phi[N];

    void FastPhi(int maxn)      //求[0, maxn]的phi表以及素数表等
    {
        memset(isprime, true, sizeof(isprime));
        isprime[0] = isprime[1] = false;
        phi[1] = 1;
        pn = 0;
        for (int i=2; i<=maxn; ++i)
        {
            if (isprime[i])
            {
                primes[pn++] = i;
                phi[i] = i - 1;     //欧拉函数值的定义第二条
            }
            for (int j=0; j<pn; ++j)
            {
                if (i * primes[j] > maxn) break;
                isprime[i * primes[j]] = false;
                if (i % primes[j] == 0)
                {
                    phi[i * primes[j]] = phi[i] * primes[j];    //欧拉函数递推式
                    break;
                }
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);  //欧拉函数递推式
            }
        }
        return;
    }
    ```
