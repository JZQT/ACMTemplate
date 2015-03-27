# 欧几里德算法及其扩展

---

## 最大公约数

---

## 最小公倍数

---

## 欧几里德算法

### 概述

**欧几里德算法**又称为**辗转相除法**，用于计算两个**正整数**的**最大公约数**(greatest common divisor)。

用$gcd(a,b)$来表示正整数a和b的最大公约数，欧几里德算法的原理依赖于以下性质
$$gcd(a,b) = gcd(b,a\ mod\ b), b \neq 0$$

### 计算最大公约数

因此**计算两个正整数的最大公约数**的函数代码如下
```cpp
int Gcd(int a, int b)
{
    return b == 0 ? a : Gcd(b, a % b);
}
```

### 计算最小公倍数

欧几里德算法还可用于计算**最小公倍数**(least common multiple)，用`lcm`来表示，其原理基于
$$lcm(a,b) = ab / gcd(a,b)$$

因此**计算两个正整数的最小公倍数**的函数代码如下
```cpp
int Lcm(int a, int b)
{
    return a / Gcd(a, b) * b;   //先除后乘避免数据范围溢出
}
```

---

## 扩展欧几里德算法

### 概述

**扩展欧几里德算法**可以在**求出a、b的最大公约数**的同时，**求出二元一次不定方程$ax + by = gcd(a,b)$的一组整数解(可以有负数或零解)**。

这里给出**贝祖定理**的定义：

> 对于两个不全为零的整数$a$、$b$，必然存在整数$x$、$y$使得$ax + by = gcd(a,b)$。

**贝祖定理**为**贝祖等式**$ax + by = gcd(a,b)$存在整数解提供了理论依据，下面给出扩展欧几里德算法的两种代码实现
```cpp
int ExGcd(int a, int b, int &x, int &y)             //有返回值版本，返回gcd(a,b)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int g = ExGcd(b, a % b, y, x);  //注意x和y的顺序
    y -= x * (a / b);
    return g;
}

void ExGcd(int a, int b, int &g, int &x, int &y)    //无返回值版本，函数运行完毕后g为gcd(a,b)
{
    if (b == 0)
    {
        g = a; x = 1; y = 0;
    }
    else
    {
        ExGcd(b, a % b, g, y, x);   //注意x和y的顺序
        y -= x * (a / b);
    }
    return;
}
```

实际上，扩展欧几里德算法求得的解只是方程$ax + by = gcd(a,b)$中的一组解。

设扩展欧几里德算法求的的一组解为$(x_0, y_0)$，用$g$来表示$gcd(a,b)$。
那么方程$ax + by = gcd(a,b)$真正的解为$(x_0 + \cfrac{kb}{g}, y_0 - \cfrac{ka}{g})$，其中$k \in Z$。

### 应用

扩展欧几里德算法有一下几种应用

* 求解二元一次不定方程$ax + by = c$
* 求解模线性方程(线性同余方程)
* 求乘法逆元
