# C++STL队列容器模板queue

---

## 概述

**队列**是一种线性表**数据结构**。
在队列这种数据结构中，最先插入在元素将是最先被删除；反之最后插入的元素将最后被删除。
因此队列又称为“**先进先出**”(FIFO—first in first out)的线性表。

C++STL里实现了这种数据结构的容器，类名为`queue`，在命名空间`std`中，被包含在头文件`<queue>`里面。

通常我们可以使用C++STL中的`queue`来快速构造一个保存指定类型的队列数据结构，为程序的编写提供了很大的方便。

---

## 用法

要**定义一个存储指定类型的队列**，比如int型，如下
```cpp
queue<int> q;
```
这样，就定义了一个存储int型元素的队列，`q`就是这个队列的变量名。

一开始定义好队列的时候，队列里面没有任何元素，也就是说这个队列为空队列。

如果要**判断一个队列是否为空**，可以用到队列的成员函数`empty()`，这个函数的返回值是**布尔类型**，示例如下
```cpp
if (q.empty())      //队列为空
{
    puts("The queue is empty.");
}
else                //队列非空
{
    puts("The queue not empty.");
}
```
这样来判断队列`q`是否为空队列。

如果还想要**获取队列里的元素个数**，使用队列的成员函数`size()`，它返回队列里的元素个数。示例如下
```cpp
printf("%d\n", q.size());   //输出队列q中的元素个数
```

要**将一个元素放进队列里面**，使用队列的成员函数`push()`，它的参数为要放进队列的元素的**值**。示例如下
```cpp
q.push(100);        //将100放进队列
```
这样就将元素放进队列里面了，**注意类型要匹配**。

如果要**访问队首或队尾元素**，队列的两个成员函数`front()`和`back()`可以解决这个问题，它们分别返回队首和队尾元素的**引用**。示例如下
```cpp
printf("%d %d\n", q.front(), q.back());     //输出队首和队尾元素
```
**注意：这两个函数是不会弹出队列中的元素的，只是返回对应元素的引用而已。**

要弹出元素的话也只能**弹出队首元素**，因为这是队列的性质。这个功能由成员函数`pop()`来完成。示例如下
```cpp
q.pop();    //弹出队首元素
```
这个成员函数没有返回值也没有参数，反正使用了这个成员函数那么队首元素就被弹出队列，后一个元素成为新的队首元素。
