# 埃氏筛法

## 概述

**埃氏筛法**又称为**埃拉托斯特尼筛法**，是由埃及数学家埃拉托斯特尼(Eratosthenes)提出的一种简单鉴定素数的算法。

埃氏筛法的**原理**是**对于任意合数n都有不大于根号n的素因数**。

埃氏筛法的**思想**是**要得到自然数N以内的全部素数，必须将不大于根号N的所有素数的倍数剔除，剩下的就是素数**。

![埃氏筛法gif图](http://jzqt.esy.es/wp-content/uploads/Sieve_of_Eratosthenes_animation.gif)

## 实现

对于埃氏筛法的**算法步骤**，我们可以这样描述：

* 开始
* 设置[2,N]的所有数为素数
* 从2开始循环到不大于根号N的整数
    * 如果该数是素数
        * 将该数不大于N的倍数设置为合数
        * 将该数加入素数表
* 结束

对于以上的算法步骤，埃氏筛法的代码如下
```cpp
bool isprime[N];        //判断是否为素数
int primes[N], pn;      //素数表以及素数个数

void Eratosthenes(int maxn) //筛[0,maxn]以内的素数
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = falses;
    pn = 0;
    int cnt = (int)sqrt(maxn + 0.5) + 1;
    for (int i=2; i<cnt; ++i)
    {
        if (!isprime[i]) continue;
        primes[pn++] = i;
        for (int j=i+i; j<=maxn; j+=i)
        {
            isprime[j] = false;
        }
    }
    return;
}
```
