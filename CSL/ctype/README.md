# ctype.h

## 概述

`ctype.h`是C标准库中的头文件，里面定义了一些C语言字符分类的函数，用于判断字符是否属于特定的字符类别，比如字母，数字，控制字符等。

## 部分常用函数表

|函数原型               |函数功能                        |返回值                            |
|:----------------------|:-------------------------------|:---------------------------------|
|`int isalpha(char ch);`|检查`ch`是否为**字母**          |是返回**非0**，否则为**0**        |
|`int isdigit(char ch);`|检查`ch`是否为**数字**          |是返回**非0**，否则为**0**        |
|`int islower(char ch);`|检查`ch`是否为**小写字母**      |是返回**非0**，否则为**0**        |
|`int issuper(char ch);`|检查`ch`是否为**大写字母**      |是返回**非0**，否则为**0**        |
|`int isalnum(char ch);`|检查`ch`是否为**字母**或**数字**|是返回**非0**，否则为**0**        |
|`int tolower(char ch);`|将`ch`转换为对应**小写字母**    |返回对应**小写字母**              |
|`int tosuper(char ch);`|将`ch`转换成对应**大写字母**    |返回对应**大写字母**              |
