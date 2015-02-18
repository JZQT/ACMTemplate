# 排列组合

## 隔板原理

**隔板原理**又称为**隔板法**和**插空法**，是排列组合的一种推广方法，主要是用于解决**不相邻组合**与**追加排列**的问题，可推广到**整数分拆**与**不定方程**的**可行解数**问题。

例题：把`n`个**相同**的小球放入`m`个**不同**的盒子里`(n >= m >= 1)`，要求每个盒子非空，请问有多少种不同的放法？

这是种常见的排列组合问题，解题方法是：把这`n`个小球排成一列，然后在小球与小球之间的`n-1`个空挡里放入`m-1`块隔板，这样就相当于把`n`个小球放进了`m`个盒子里，有$C^{m-1}_{n-1}$种不同的放置方法。
这种解题方法就称之为**隔板法**。