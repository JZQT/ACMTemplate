# 素数与函数

## 概述

**素数**也称为**质数**。

一个大于1的自然数，如果除了**1和它本身**之外，不能够被其他自然数**整除**，那么这个数就是**素数**，否则就是**合数**。

**任何一个合数都能够被分解成质因数(素因数)的乘积。**

关于素数的ACM题一般涉及到以下几个方面

* 素性测试

    用于判断一个数是否为素数。

* [素数筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method "prime_sieve_method")

    可以用来获得素数表以及判断多个数是否为素数。

* 分解质因数

    可将合数分解成质因数的乘积。

## 哥德巴赫猜想

谈到素数就不得不谈到**哥德巴赫猜想**这个举世闻名的数论猜想。

在1742年哥德巴赫给欧拉的信中提出了这个猜想的最原始版本

> 任何一个大于2的整数都可以写成两个素数的和。

并且请欧拉证明，但是欧拉到死也没能证明这个猜想，不过欧拉在回信中提出了哥德巴赫猜想的一个等价版本

> 任何一个大于2的偶数都可以写成两个素数的和。

因为现今的数学界已经不使用**1也是素数**这个约定，因此现在常见的猜想陈述为欧拉版本，也称为**强哥德巴赫猜想**或**关于偶数的哥德巴赫猜想**。

目前尚未有人从理论上完全证明哥德巴赫猜想，不过根据计算机运行的结果表明，倘若有一个偶数不能够拆分成两个素数的和，那么这个偶数至少上百位！

因此，在ACM竞赛中(数据在64位整型范围内)，哥德巴赫猜想是成立的！

## 题集

|题号                   |备注                               |
|:----------------------|:----------------------------------|
|[POJ-1142][PKU1142]    |分解质因数，要注意细节问题         |
|[POJ-1411][PKU1411]    |不错的筛素数题，需要优化           |
|[POJ-2262][PKU2262]    |筛素数基础题，验证哥德巴赫猜想     |
|[POJ-2689][PKU2689]    |区间筛素数                         |
|[POJ-2739][PKU2739]    |筛素数水题                         |
|[POJ-3518][PKU3518]    |筛素数水题，需要打表               |
|[HDOJ-2161][HDU2161]   |水得无话可说                       |
|[HDOJ-2136][HDU2136]   |筛素数的同时可计算答案             |
|[UVaOJ-10168][UVa10168]|好题，哥德巴赫猜想的推广           |
|[UVaOJ-10200][UVa10200]|需要四舍五入，坑                   |
|[UVaOJ-10539][UVa10539]|筛素数好题                         |
|[UVaOJ-10791][UVa10791]|好题，分解质因数                   |
|[UVaOJ-11752][UVa11752]|需要推理                           |

[PKU1142]:http://poj.org/problem?id=1142
[PKU1411]:http://poj.org/problem?id=1411
[PKU2262]:http://poj.org/problem?id=2262
[PKU2689]:http://poj.org/problem?id=2689
[PKU2739]:http://poj.org/problem?id=2739
[PKU3518]:http://poj.org/problem?id=3518
[HDU2161]:http://acm.hdu.edu.cn/showproblem.php?pid=2161
[HDU2136]:http://acm.hdu.edu.cn/showproblem.php?pid=2136
[UVa10168]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1109
[UVa10200]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1141
[UVa10539]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1480
[UVa10791]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1732
[UVa11752]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2852
