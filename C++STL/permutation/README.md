# C++STL全排列函数

## 概述

函数`next_permutation`和`prev_permutation`是求排列的函数，可以用于遍历全排列。被包含在头文件`<algorithm>`中。

`next_permutation`函数是求当前排列的下一个排列，`prev_permutation`函数则是求上一个排列，刚好相反。

这两个函数的参数与`sort`函数一样，第一个参数是数组首地址，第二个参数是数组尾地址，区间是**左闭右开**的，并且可以自定义比较函数作为第三个参数。

## 用法

* `int`型的排列

    ```cpp
    int num[3] = {1, 2, 3};
    next_permutation(num, num+3);   //调用完函数后数组变成了下一个排列
    prev_permutation(num, num+3);   //调用这个函数就还原成了原来的排列
    ```

## 题集

|题号                   |备注                               |
|:----------------------|:----------------------------------|
|[POJ-1833][PKU1833]    |STL全排列水题                      |

[PKU1833]:http://poj.org/problem?id=1833 "排列"
