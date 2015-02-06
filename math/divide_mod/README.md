# 整除与剩余

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
|[HDOJ-5019][HDU5019]   |求k大GCD                           |
|[UVaOJ-11827][UVa11827]|求GCD，需要字符串处理              |

[PKU1061]:http://poj.org/problem?id=1061
[PKU1995]:http://poj.org/problem?id=1995
[PKU3070]:http://poj.org/problem?id=3070
[HDU1905]:http://acm.hdu.edu.cn/showproblem.php?pid=1905
[HDU1920]:http://acm.hdu.edu.cn/showproblem.php?pid=1920
[HDU5019]:http://acm.hdu.edu.cn/showproblem.php?pid=5019
[UVa11827]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2927
