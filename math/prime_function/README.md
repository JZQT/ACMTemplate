# 素数与函数

---

## 概述

**素数**又称为**质数**。

一个大于$1$的自然数，如果除了**$1$和它本身**之外，不能够被其他自然数**整除**，那么这个数就是**素数**，否则就是**合数**。

**任何一个合数都能够被分解成质因数(素因数)的乘积。**

与素数有关的ACM题一般涉及到以下几个方面

* 素性测试

    用于判断一个数是否为素数。

* [素数筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method "prime_sieve_method")

    可以用来获得素数表以及判断多个数是否为素数。

* [分解质因数](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/factor "factor")

    可将合数分解成质因数的乘积。

* [欧拉函数](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/Euler_function "Euler_function")

    计算不超过n且与n互质的正整数个数。

---

## 算术基本定理

**算术基本定理**又称为**唯一分解定理**，它可以表述为

> 任何一个大于1的自然数N，都可以唯一分解成有限个质数的乘积
>
> $N = P_{1}^{a_1}P_{2}^{a_2}P_{3}^{a_3} \cdots P_{n}^{a_n}$
>
> 其中$P_1 < P_2 < P_3 < \cdots < P_n$且均为质数，而$a_1, a_2, \cdots, a_n$都是正整数。

对于算术基本定理有以下推论及应用

* 对于一个大于$1$的自然数$N$，假设它的**正因子个数**表示为$d(N)$，那么

    $$d(N) = (1 + a_1)(1 + a_2)(1 + a_3) \cdots (1 + a_n)$$

* 对于一个大于$1$的自然数$N$，假设它的**全体正因数之和**表示为$\phi(N)$，那么

    $$\phi(N) = (1 + P_{1} + P_{1}^{2} + \cdots + P_{1}^{a_1})(1 + P_{2} + P_{2}^{2} + \cdots + P_{2}^{a_2}) \cdots (1 + P_{n} + P_{n}^{2} + \cdots + P_{n}^{a_n})$$
    或者
    $$\phi(N) = \cfrac{P_{1}^{a_{1} + 1} - 1}{P_{1} - 1} \cdot \cfrac{P_{2}^{a_{2} + 1} - 1}{P_{2} - 1} \cdots \cfrac{P_{n}^{a_{n} + 1} - 1}{P_{n} - 1}$$

* 对于$n!$的素因子分解中的素数$p$的幂为$[n/p] + [n/p^2] + [n/p^3] + \cdots$
* 利用算术基本定理可以重新定义整数$a$和$b$的最大公约数$gcd(a,b)$和最小公倍数$lcm(a,b)$并且证明$a \cdot b = gcd(a,b) \cdot lcm(a,b)$
* 可证明$\sqrt 2$是无理数
* 可证明素数个数无限

---

## 素数定理

**素数定理**是用来**描述素数的大致分布情况的**。

> 对于正实数x，定义π(x)为不大于x的素数个数，那么
>
> 当x趋近于∞时，π(x)与x/lnx的比例趋近与1。
> 
> 描述为 π(x) ~ x/lnx

**注意：素数定理的意思是当x趋近∞时，π(x)与x/lnx的比例趋近与1，但不代表x越大而越接近。**

下面给出一个素数定理的直观验证表(来自《算法竞赛入门经典》)

|X      |10^2|10^3|10^4|10^5|10^6 |10^7  |10^8   |
|:------|:--:|:--:|:--:|:--:|:---:|:----:|:-----:|
|π(x)   |25  |168 |1229|9592|78498|664579|5761455|
|x/lnx  |22  |145 |1086|8686|72382|620421|5428681|

素数定理对ACM竞赛有一个最直接的影响就是**我们可以预估N以内的素数个数，从而节省开素数表所需要的内存**。

---

## 哥德巴赫猜想

谈到素数就不得不谈到**哥德巴赫猜想**这个举世闻名的数论猜想。

在1742年哥德巴赫给欧拉的信中提出了这个猜想的最原始版本

> 任何一个大于2的整数都可以写成两个素数的和。

并且请欧拉证明，但是欧拉到死也没能证明这个猜想，不过欧拉在回信中提出了哥德巴赫猜想的一个等价版本

> 任何一个大于2的偶数都可以写成两个素数的和。

因为现今的数学界已经不使用**1也是素数**这个约定，因此现在常见的猜想陈述为欧拉版本，也称为**强哥德巴赫猜想**或**关于偶数的哥德巴赫猜想**。

目前尚未有人从理论上完全证明哥德巴赫猜想，不过根据计算机运行的结果表明，倘若有一个偶数不能够拆分成两个素数的和，那么这个偶数至少上百位！

因此，在ACM竞赛中(数据在64位整型范围内)，哥德巴赫猜想是成立的！

---

## 题集

|题号                   |备注                               |
|:----------------------|:----------------------------------|
|[POJ-1142][PKU1142]    |分解质因数，要注意细节问题         |
|[POJ-1365][PKU1365]    |分解质因数基础题，需要字符串处理   |
|[POJ-1411][PKU1411]    |不错的筛素数题，需要优化           |
|[POJ-2262][PKU2262]    |筛素数基础题，验证哥德巴赫猜想     |
|[POJ-2407][PKU2407]    |欧拉函数基础题                     |
|[POJ-2478][PKU2478]    |欧拉函数基础题                     |
|[POJ-2689][PKU2689]    |区间筛素数                         |
|[POJ-2739][PKU2739]    |筛素数基础题                       |
|[POJ-3090][PKU3090]    |欧拉函数基础题                     |
|[POJ-3518][PKU3518]    |筛素数基础题，需要打表             |
|[HDOJ-1164][HDU1164]   |分解质因数基础题                   |
|[HDOJ-1299][HDU1299]   |好题，唯一分解定理                 |
|[HDOJ-1397][HDU1397]   |哥德巴赫猜想水题                   |
|[HDOJ-1492][HDU1492]   |唯一分解定理基础题                 |
|[HDOJ-1787][HDU1787]   |欧拉函数基础题                     |
|[HDOJ-2098][HDU2098]   |素数基础题                         |
|[HDOJ-2136][HDU2136]   |筛素数的同时可计算答案             |
|[HDOJ-2161][HDU2161]   |水得无话可说                       |
|[HDOJ-2608][HDU2608]   |好题，唯一分解定理应用，推理       |
|[UVaOJ-10168][UVa10168]|好题，哥德巴赫猜想的推广           |
|[UVaOJ-10200][UVa10200]|需要四舍五入，坑                   |
|[UVaOJ-10539][UVa10539]|筛素数好题                         |
|[UVaOJ-10791][UVa10791]|好题，分解质因数                   |
|[UVaOJ-11752][UVa11752]|需要推理                           |

[PKU1142]:http://poj.org/problem?id=1142 "Smith Numbers"
[PKU1365]:http://poj.org/problem?id=1365 "Prime Land"
[PKU1411]:http://poj.org/problem?id=1411 "Calling Extraterrestrial Intelligence Again"
[PKU2262]:http://poj.org/problem?id=2262 "Goldbach's Conjecture"
[PKU2407]:http://poj.org/problem?id=2407 "Relatives"
[PKU2478]:http://poj.org/problem?id=2478 "Farey Sequence"
[PKU2689]:http://poj.org/problem?id=2689 "Prime Distance"
[PKU2739]:http://poj.org/problem?id=2739 "Sum of Consecutive Prime Numbers"
[PKU3090]:http://poj.org/problem?id=3090 "Visible Lattice Points"
[PKU3518]:http://poj.org/problem?id=3518 "Prime Gap"
[HDU1164]:http://acm.hdu.edu.cn/showproblem.php?pid=1164 "Eddy's research I"
[HDU1299]:http://acm.hdu.edu.cn/showproblem.php?pid=1299 "Diophantus of Alexandria"
[HDU1397]:http://acm.hdu.edu.cn/showproblem.php?pid=1397 "Goldbach's Conjecture"
[HDU1492]:http://acm.hdu.edu.cn/showproblem.php?pid=1492 "The number of divisors(约数) about Humble Numbers"
[HDU1787]:http://acm.hdu.edu.cn/showproblem.php?pid=1787 "GCD Again"
[HDU2098]:http://acm.hdu.edu.cn/showproblem.php?pid=2098 "分拆素数和"
[HDU2136]:http://acm.hdu.edu.cn/showproblem.php?pid=2136 "Largest prime factor"
[HDU2161]:http://acm.hdu.edu.cn/showproblem.php?pid=2161 "Primes"
[HDU2608]:http://acm.hdu.edu.cn/showproblem.php?pid=2608 "0 or 1"
[UVa10168]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1109
[UVa10200]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1141
[UVa10539]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1480
[UVa10791]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1732
[UVa11752]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2852
