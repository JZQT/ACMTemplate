# ACM_Template

> Created by JZQT on 2014-11-11.

## 概述
ACM模板知识库项目，包含**文档**和**代码**两类。供**学习**和**总结**之用。

* 文档

    对应的文件夹中的README.md文档，包含算法介绍以及讲解，题集，心得体会以及一些说明等。

* 代码

    C++代码文件，算法模板的代码实现。

**注意：由于仅用于ACM竞赛学习，对于有些知识点介绍不会全面彻底，比如C++STL中有许多东西没有讲到，有兴趣者可自行学习。**

## 分类说明

* [C++STL](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL "C++标准模板库")
    * [string](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/string "字符串类")
    * [sort](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/sort "快速排序算法")
    * [pair](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/pair "对组")
    * [queue](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/queue "队列")
    * [stack](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/C++STL/stack "栈")
    * vector
    * priority_queue
    * map
    * set
    * list
* [数据结构](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/data_structure "data_structure")
    * [幷查集](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/data_structure/union_find_set "union_find_set")
    * [字典树](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/data_structure/trie "trie")
    * 树状数组
    * 线段树
* [图论](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory "graph_theory")
    * [存图方式](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/save_graph "save_graph")
        * [邻接矩阵](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/save_graph/mat "adjacency_matrix(mat)")
        * [vector邻接表](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/save_graph/vec "vector(vec)")
        * [链式前向星](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/save_graph/qxx "(qxx)")
    * 最小生成树
        * kruskal算法
        * prim算法
    * [最短路](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/shortest_path "shortest_path")
        * [dijkstra算法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/shortest_path/dijkstra "dijkstra")
        * SPFA算法
        * floyd算法
    * [二分图](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/bipartite_graph "bipartite_graph")
        * [匈牙利算法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/bipartite_graph/hungary "hungary")
        * KM算法
    * 最近公共祖先
        * tarjan离线算法
    * [割点与割边](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/cut "cut")
        * [tarjan算法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/cut/tarjan "tarjan")
    * 双连通分量
        * tarjan算法
    * [强连通分量](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/strongly_connected_components "strongly_connected_components")
        * [tarjan算法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/graph_theory/strongly_connected_components/tarjan "tarjan")
    * 网络流
* [数学](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math "math")
    * [整除与剩余](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/divide_mod "divide and mod")
        * [快速幂](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/divide_mod/fast_power "fast_power")
        * [欧几里德算法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/divide_mod/gcd "Euclid_algorithm")
        * [扩展欧几里德算法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/divide_mod/exgcd "extended_Euclidean_algorithm")
    * [素数与函数](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function "prime and function")
        * 素性测试
        * [素数筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method "prime_sieve_method")
            * [埃氏筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method/Eratosthenes "Eratosthenes")
            * [快速线性筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method/fast_sieve "fast_sieve")
            * [区间筛法](https://coding.net/u/JZQT/p/ACM_Template/git/tree/master/math/prime_function/prime_sieve_method/interval_sieve "interval_sieve")
        * 分解质因数
* 计算几何

## 中英文对照表

**注：小括号内为别名或简写，英文并不一定是对应中文的翻译。**

|中文                   |English                                |
|:----------------------|:--------------------------------------|
|标准模板库             |standard_template_library(STL)         |
|数据结构               |data_structure                         |
|字符串                 |string                                 |
|队列                   |queue                                  |
|栈                     |stack                                  |
|优先队列               |priority_queue                         |
|集合                   |set                                    |
|映射                   |map                                    |
|哈希表                 |hash_table                             |
|幷查集                 |union_find_set                         |
|字典树                 |trie                                   |
|树状数组(二叉索引树)   |binary_indexed_tree                    |
|线段树                 |segment_tree                           |
|图论                   |graph_theory                           |
|存图方式               |save_graph                             |
|邻接矩阵               |adjacency_matrix(mat)                  |
|vector邻接表           |(vec)                                  |
|链式前向星             |(qxx)                                  |
|最小生成树             |minimum_spanning_tree(MST)             |
|最短路                 |shortest_path                          |
|二分图                 |bipartite_graph                        |
|匈牙利算法             |hungary                                |
|最近公共祖先           |least_common_ancestor(LCA)             |
|无向图                 |undirected_graph                       |
|双连通分量             |biconnected_components(bcc)            |
|割点(割顶)             |cut_point(cut_vertex)                  |
|割边(桥)               |cut_edge(bridge)                       |
|有向图                 |directed_graph                         |
|强连通分量             |strongly_connected_components(scc)     |
|数学                   |math                                   |
|整除与剩余             |(divide_mod)                           |
|快速幂                 |fast_power                             |
|最大公约数             |greatest_common_divisor(gcd)           |
|最小公倍数             |least_common_multiple(lcm)             |
|欧几里德算法           |Euclid_algorithm(gcd)                  |
|扩展欧几里德算法       |extended_Euclidean_algorithm(exgcd)    |
|素数(质数)与函数       |(prime_function)                       |
|素性测试               |primality_test                         |
|素数筛法               |prime_sieve_method                     |
|埃氏筛法               |Eratosthenes                           |
|快速线性筛法           |fast_sieve                             |
|区间筛法               |interval_sieve                         |
|分解质因数             |(factor)                               |
|计算几何               |computational_geometry                 |
