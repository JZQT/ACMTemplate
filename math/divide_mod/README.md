# 整除与剩余

## 求模运算与求余运算

**求模运算**(modulo)与**求余运算**(remain)是不同的。

通常来说，我们指的`a mod b`运算是求**模**运算，它和求**余**运算在`a`和`b`都是**正整数**的情况下**完全没有区别**。
它们之间仅在`a`与`b`**异号**的情况下结果有区别。

对于**整数**`a`和`b`，求**模**运算和求**余**运算的方法都是两个步骤：

* 求整数商：`c = a / b`
* 计算模或者余数：`m = a - c * b`

在第一个步骤中，求**余**运算在取`c`的值时，向0方向舍入，求**模**运算则是向负无穷方向舍入。

比如计算`-10 mod 3`，求**余**运算算得的`c`的值为`-3`，而求**模**运算则为`-4`。因此最后计算的结果，求**余**运算为`-1`，而求**模**运算则为`2`。

因此，最后结论是，当`a`与`b`异号时，求**余**运算的结果与`a`同号，而求**模**运算的结果与`b`同号。

**注意：对于程序中的`%`运算符，在不同的环境中含义并不一样，比如在C/C++，JAVA，PHP等，`%`是求余运算，在Python中，`%`是求模运算。**

## 欧拉定理

### 概述

在数论中，**欧拉定理**，也称之为**费马-欧拉定理**，是一个关于同余的性质。

欧拉定理表示为：

若n和a都为正整数且n与a互质，那么![欧拉定理](http://7rfk4x.com1.z0.glb.clouddn.com/Euler_Theorem.jpg)，其中**φ(n)**为欧拉函数。

### 应用

利用欧拉定理，有一下推论以及应用

* 欧拉降幂：`a^b mod m = a^(b mod phi(m)) mod m`
* 如果`a`和`m`都是正整数且`a`与`m`互质(`m > 1`)，必有正整数`x`使得`a^x = 1(mod m)`，且满足该等式的最小正整数`x0`必满足`x0|phi(m)`

## 题集

|题号                   |备注                               |
|:----------------------|:----------------------------------|
|[POJ-1061][PKU1061]    |扩展欧几里德                       |
|[POJ-1995][PKU1995]    |水题，快速幂                       |
|[POJ-3070][PKU3070]    |水题，矩阵快速幂                   |
|[HDOJ-1395][HDU1395]   |欧拉定理                           |
|[HDOJ-1905][HDU1905]   |快速幂和判断素数                   |
|[HDOJ-1920][HDU1920]   |多个数LCM                          |
|[HDOJ-4965][HDU4965]   |好题，矩阵快速幂                   |
|[HDOJ-5019][HDU5019]   |求k大GCD                           |
|[UVaOJ-11827][UVa11827]|求GCD，需要字符串处理              |

[PKU1061]:http://poj.org/problem?id=1061
[PKU1995]:http://poj.org/problem?id=1995
[PKU3070]:http://poj.org/problem?id=3070
[HDU1905]:http://acm.hdu.edu.cn/showproblem.php?pid=1905
[HDU1920]:http://acm.hdu.edu.cn/showproblem.php?pid=1920
[HDU4965]:http://acm.hdu.edu.cn/showproblem.php?pid=4965
[HDU5019]:http://acm.hdu.edu.cn/showproblem.php?pid=5019
[UVa11827]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2927
