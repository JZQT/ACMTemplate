# 欧几里得算法

## 概述
欧几里得算法又称为**辗转相除法**，用于计算两个**正整数**的**最大公约数**。

因欧几里得算法用于求最大公约数(greatest common divisor)，故常用`gcd`来表示。

用`gcd(a, b)`来表示a和b的最大公约数，那么欧几里得算法的计算原理依赖与下面的定理
```cpp
gcd(a, b) == gcd(b, a % b);     //a > b && a % b != 0
```
因此计算两个正整数的最大公约数的欧几里得算法函数可以这么写
```cpp
int Gcd(int a, int b)
{
    return b == 0 ? a : Gcd(b, a % b);
}
```

欧几里得算法还可用于计算**最小公倍数**(least common multiple)，用`lcm`来表示，其原理基于
```cpp
lcm(a, b) == a * b / gcd(a, b); //a > b && a % b != 0
```
因此计算两个正整数的最小公倍数的函数可以这么写
```cpp
int Lcm(int a, int b)
{
    return a / Gcd(a, b) * b;
}
```
**注意：先除后乘是为了避免数据范围溢出，由于`Gcd(a, b)`是最大公约数，因此除法必能整除。**

## 题集
|题号                   |备注                       |
|:----------------------|:--------------------------|
|[UVaOJ-11827][UVa11827]|需要字符串处理             |

[UVa11827]:http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2927
