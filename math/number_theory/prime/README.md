# 素数

## 概述
**素数**也称为**质数**，指的是**大于1**并且**因数只有1和它本身**的**整数**。

**除了1以外的非素数称为合数，1既不是素数也不是合数。**

**任何一个合数都能够被分解成质因数(素因数)的乘积。**

关于素数的ACM题一般涉及到以下几个方面

* 素性测试

    用于判断一个数是否为素数。

* [**素数筛法**](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/number_theory/prime/prime_sieve_method "prime_sieve_method")

    可以用来获得素数表以及判断多个数是否为素数。

* 分解质因数

    可将合数分解成质因数的乘积。

## 题集

|题号                   |备注                       |
|:----------------------|:--------------------------|
|[HDOJ-2136][HDU2136]   |可以一边筛素数一边算出答案 |
|[POJ-1411][PKU1411]    |不错的题，需要优化         |
|[POJ-2262][PKU2262]    |基础题，验证哥德巴赫猜想   |
|[POJ-2689][PKU2689]    |区间筛素数                 |
|[POJ-2739][PKU2739]    |基础题                     |
|[POJ-3518][PKU3518]    |基础题，需要打表           |
|[UVaOJ-10539][UVa10539]|需要思考，不仅仅是筛素数   |


[HDU2136]:http://acm.hdu.edu.cn/showproblem.php?pid=2136
[PKU1411]:http://poj.org/problem?id=1411
[PKU2262]:http://poj.org/problem?id=2262
[PKU2689]:http://poj.org/problem?id=2689
[PKU2739]:http://poj.org/problem?id=2739
[PKU3518]:http://poj.org/problem?id=3518
[UVa10539]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1480
