# C++标准模板库(Standard Template Library)

## 概述
> STL = Standard Template Library，标准模板库，惠普实验室开发的一系列软件的统称。
> 它是由Alexander Stepanov、Meng Lee和David R Musser在惠普实验室工作时所开发出来的。
> 这可能是一个历史上最令人兴奋的工具的最无聊的术语。
> 从根本上说，STL是一些“容器”的集合，这些“容器”有list,vector,set,map等，STL也是算法和其他一些组件的集合。
> 这里的“容器”和算法的集合指的是世界上很多聪明人很多年的杰作。STL的目的是标准化组件，这样就不用重新开发，可以使用现成的组件。
> STL现在是C++的一部分，因此不用额外安装什么。

以上内容摘至百度百科。

C++标准模板库(以下简称STL)由一系列头文件组成，里面包含多种常用的结构体、类、算法以及数据结构等。

ACM竞赛中常常要编写算法及数据结构等的代码，使用STL会使得编写这些代码更加方便，使得竞赛者可以花更多时间专注于如何解题而不是浪费时间在已经烂熟于心的算法及数据结构代码的编写上。

学会使用STL要求基本了解**面向对象程序设计**，了解**类**、**函数重载**、**运算符重载**、**模板**等知识点。

**注意：可能有些东西不属于STL但是属于C++标准库并且ACM比赛常用，故在此列入STL中。**

## 常用STL总览及简介

|名称                                                                                       |属于       |头文件         |简介                           |
|:------------------------------------------------------------------------------------------|:----------|:--------------|:------------------------------|
|[string](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/string "字符串类")|类         |`<string>`     |存储字符串的类                 |
|[sort](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/sort "快速排序算法")|算法       |`<algorithm>`  |快速排序算法                   |
|[pair](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/pair "对组")        |结构体     |`<algorithm>`  |对组，用于存储两个值的结构体   |
|queue                                                                                      |数据结构   |`<queue>`      |队列                           |
|stack                                                                                      |数据结构   |`<stack>`      |栈                             |
|vector                                                                                     |数据结构   |`<vector>`     |向量，可视做变长数组           |
|priority_queue                                                                             |数据结构   |`<queue>`      |优先队列                       |
|map                                                                                        |数据结构   |`<map>`        |映射，常用做哈希表             |
|set                                                                                        |数据结构   |`<set>`        |集合                           |
