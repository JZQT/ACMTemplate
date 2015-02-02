# 素数筛法

## 概述

解决多个数是否是素数以及得到素数表这样的问题，有比素性测试更加高效的算法，那就是**素数筛法**，也称为**筛法**或**筛素数**。

素数筛法的**原理**是**每一个合数都有不为1和它本身的因数，靠这些因数来把合数筛去，剩下的就是素数了**。

简单的说，素数筛法就是利用因数筛去因数的倍数。

ACM竞赛中常用的素数筛法有三种

* [埃氏筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method/Eratosthenes "Eratosthenes")

    最古老也是最简单的筛法，算法易懂。

* [快速线性筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method/fast_sieve "fast_sieve")

    线性复杂度的改进筛法。

* [区间筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method/interval_sieve "interval_sieve")

    用来筛区间范围小但是区间端点值大的区间内素数。
