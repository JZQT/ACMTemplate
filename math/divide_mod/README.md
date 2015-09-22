# 整除与剩余

---

## 符号约定

假设$a$和$b$是两个整数且$b \neq 0$，如果存在整数$c$使得$a = bc$，那么我们就称$a$被$b$整除，或者$b$整除$a$，记作$b \mid a$。
此时也称为$a$是$b$的倍数，$b$是$a$的因数。而如果$b$不整除$a$，记作$b \nmid a$。

---

## 求模运算与求余运算

**求模运算**(modulo)与**求余运算**(remain)是不同的。

通常来说，我们指的$a\ mod\ b$运算是**求模**运算，它和**求余**运算在$a$和$b$都是**正整数**的情况下**完全没有区别**。
它们之间仅在$a$与$b$**异号**的情况下结果有区别。

对于**整数**$a$和$b$，**求模**运算和**求余**运算的方法都是两个步骤：

1. 求整数商：$c = a\ /\ b$
2. 计算模或者余数：$m = a - c \times b$

在第一个步骤中，**求余**运算在取$c$的值时，**向0方向舍入**，**求模**运算则是**向负无穷方向舍入**。

比如计算$-10\ mod\ 3$，**求余**运算算得的$c$的值为$-3$，而**求模**运算则为$-4$。因此最后计算的结果，**求余**运算为$-1$，而**求模**运算则为$2$。

最后结论是，当$a$与$b$异号时，**求余**运算的结果与$a$同号，而**求模**运算的结果与$b$同号。

**注意：对于程序中的`%`运算符，在不同的环境中含义并不一样，比如在C/C++，JAVA，PHP等，`%`是求余运算，在Python中，`%`是求模运算。**

---

## 剩余系与模运算

**剩余系**指的是**对于某个特定的正整数$n$，一个整数集中所有数模$n$所得的余数域**。

如果一个剩余系中包含了模$n$情况下所有可能的余数，那么这个剩余系就被称之为是模$n$的一个**完全剩余系**。
一般来说，模$n$的完全剩余系就是$\lbrace 0, 1, 2, ···, n-1 \rbrace$。

**简化剩余系**(简称**缩系**)又称**既约剩余系**，是完全剩余系中**与$n$互质**的元素。比如当$n = 12$时，缩系就是$\lbrace 1, 5, 7, 11 \rbrace$。

在这里，我们将模n的完全剩余系记作$Z_n$，缩系记作$Z_n^*$。

$Z_n$中的每一个元素都代表所有与它同余的整数。比如在$Z_5$中，$1$代表$\lbrace 1, 6, 11, ··· \rbrace$等所有模$5$余数为$1$的数。
$Z_n$中所有整数都代表一个同余等价类，因此**在剩余系下的运算都称之为模运算**，比如$Z_5$下的模加法$1 + 4 = 0$，模乘法$3 \times 4 = 2$。

---

## 同余

**同余**是**数论**上的一种**等价关系**。
如果两个整数$a$和$b$满足$m | (a - b)$(也有这样的说法，如果两个整数$a$和$b$对于模$m$的结果相同)，那么就称$a$和$b$对于模$m$同余。

$a$和$b$对于模$m$同余，记作$a \equiv b(mod\ m)$。其中符号$\equiv$称为**同余符号**。

对于**同余**这种等价关系，有以下性质

* 反身性：

    $$a \equiv a(mod\ m)$$

* 对称性：

    $$a \equiv b(mod\ m) \Rightarrow b \equiv a(mod\ m)$$

* 传递性：

    $$
    \begin{cases}
    a \equiv b(mod\ m) \\
    b \equiv c(mod\ m) \\
    \end{cases}
    \Rightarrow a \equiv c(mod\ m)
    $$

* 基本运算：

    $$
    \begin{cases}
    a \equiv b(mod\ m) \\
    c \equiv d(mod\ m) \\
    \end{cases}
    \Rightarrow
    \begin{cases}
    a \pm c \equiv b \pm d(mod\ m) \\
    ac \equiv bd(mod\ m) \\
    \end{cases}
    $$
    $$
    a \equiv b(mod\ m) \Rightarrow
    \begin{cases}
    an \equiv bn(mod\ m), \forall n \in \bf Z \\
    a^n \equiv b^n(mod\ m), \forall n \in \bf N^* \\
    \end{cases}
    $$

* 其他性质：

    $$
    \begin{cases}
    a \equiv b(mod\ m) \\
    n \mid m \\
    \end{cases}
    \Rightarrow a \equiv b(mod\ n)
    $$
    $$
    \begin{cases}
    ac \equiv bc(mod\ m) \\
    (c,m) = d \\
    \end{cases}
    \Rightarrow a \equiv b(mod\ m/d)
    $$
    $$
    a \equiv b(mod\ m) \Rightarrow (a,m) = (b,m)
    $$

---

## 欧拉定理

### 概述

在数论中，**欧拉定理**，也称之为**费马-欧拉定理**，是一个关于**同余**的性质。

欧拉定理表示为：

若$n$和$a$为**互质**的两个正整数，那么$a^{\varphi(n)} \equiv 1(mod\ n)$，其中$\varphi(n)$为欧拉函数。

### 应用

利用欧拉定理，有以下推论以及应用

* 欧拉降幂：

    $$a^b \equiv a^{b\ mod\ \varphi(m)}(mod\ m)$$

* 如果$a$和$m$都是正整数且$a$与$m$互质$(m > 1)$，必有正整数$x$使得$a^x \equiv 1(mod\ m)$，且满足该等式的最小正整数$x_0$必能整除$\varphi(m)$，即$x_0 \mid \varphi(m)$

    **注意：枚举一个数的因子尽量不要用时间复杂度为$O(n)$的枚举算法，而要用$O(\sqrt n)$的算法，避免超时。**

---

## 费马小定理

**费马小定理**是**数论**中的一个重要定理，实际上它是**欧拉定理**(数论)的一个特殊情况。它的内容为

如果$p$是质数且$a$与$p$互质，那么$a^{p-1} \equiv 1(mod\ p)$。

费马小定理之所以是欧拉定理的一种特殊情况是因为素数$x$的欧拉函数值为$x-1$，所以当$p$为素数时可以直接将$p-1$代入欧拉定理的欧拉函数，就成了费马小定理。

---

## 题集

|题号                   |备注                                           |
|:----------------------|:----------------------------------------------|
|[POJ-1061][PKU1061]    |扩展欧几里德                                   |
|[POJ-1284][PKU1284]    |利用原根性质，欧拉函数                         |
|[POJ-1995][PKU1995]    |快速幂基础题                                   |
|[POJ-2115][PKU2115]    |线性同余方程基础题                             |
|[POJ-2773][PKU2773]    |好题，欧拉函数，需要思考GCD性质                |
|[POJ-3070][PKU3070]    |矩阵快速幂基础题                               |
|[POJ-3233][PKU3233]    |好题，矩阵快速幂，二分优化或者矩阵套矩阵优化   |
|[POJ-3358][PKU3358]    |好题，欧拉定理，同余运算性质                   |
|[HDOJ-1211][HDU1211]   |快速幂或同余方程，水题                         |
|[HDOJ-1395][HDU1395]   |欧拉定理                                       |
|[HDOJ-1420][HDU1420]   |快速幂基础题                                   |
|[HDOJ-1576][HDU1576]   |乘法逆元基础题                                 |
|[HDOJ-1577][HDU1577]   |GCD基础题                                      |
|[HDOJ-1905][HDU1905]   |快速幂和判断素数                               |
|[HDOJ-1920][HDU1920]   |多个数LCM                                      |
|[HDOJ-2035][HDU2035]   |快速幂基础题                                   |
|[HDOJ-2157][HDU2157]   |矩阵快速幂在有向图中的应用，经典题             |
|[HDOJ-4965][HDU4965]   |好题，矩阵快速幂，需要仔细思考优化             |
|[HDOJ-5019][HDU5019]   |求k大GCD                                       |
|[HDOJ-5171][HDU5171]   |好题，矩阵快速幂                               |
|[UVaOJ-11827][UVa11827]|求GCD，需要字符串处理                          |

[PKU1061]:http://poj.org/problem?id=1061 "青蛙的约会"
[PKU1284]:http://poj.org/problem?id=1284 "Primitive Roots"
[PKU1995]:http://poj.org/problem?id=1995 "Raising Modulo Numbers"
[PKU2115]:http://poj.org/problem?id=2115 "C Looooops"
[PKU2773]:http://poj.org/problem?id=2773 "Happy 2006"
[PKU3070]:http://poj.org/problem?id=3070 "Fibonacci"
[PKU3233]:http://poj.org/problem?id=3233 "Matrix Power Series"
[PKU3358]:http://poj.org/problem?id=3358 "Period of an Infinite Binary Expansion"
[HDU1211]:http://acm.hdu.edu.cn/showproblem.php?pid=1211 "RSA"
[HDU1395]:http://acm.hdu.edu.cn/showproblem.php?pid=1395 "2^x mod n = 1"
[HDU1420]:http://acm.hdu.edu.cn/showproblem.php?pid=1420 "Prepared for New Acmer"
[HDU1576]:http://acm.hdu.edu.cn/showproblem.php?pid=1576 "A/B"
[HDU1577]:http://acm.hdu.edu.cn/showproblem.php?pid=1577 "WisKey的眼神"
[HDU1905]:http://acm.hdu.edu.cn/showproblem.php?pid=1905 "Pseudoprime numbers"
[HDU1920]:http://acm.hdu.edu.cn/showproblem.php?pid=1920 "Jackpot"
[HDU2035]:http://acm.hdu.edu.cn/showproblem.php?pid=2035 "人见人爱A^B"
[HDU2157]:http://acm.hdu.edu.cn/showproblem.php?pid=2157 "How many ways??"
[HDU4965]:http://acm.hdu.edu.cn/showproblem.php?pid=4965 "Fast Matrix Calculation"
[HDU5019]:http://acm.hdu.edu.cn/showproblem.php?pid=5019 "Revenge of GCD"
[HDU5171]:http://acm.hdu.edu.cn/showproblem.php?pid=5171 "GTY's birthday gift"
[UVa11827]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2927
