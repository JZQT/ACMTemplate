# C++STL对组容器模板pair

## 概述
pair容器是C++STL中一种可以**捆绑两个值**的结构体，在**命名空间std**中，被包含在头文件`<utility>`里面，不过该头文件被`<algorithm>`头文件所包含，所以使用时只要包含`<algorithm>`头文件就可以了。

pair可以用来快速构造一个具有两个成员的类型，这两个成员的类型可以相同也可以不同。

## 用法

#### 构造
由于pair是C++STL的容器，因此需要提前声明需要构造的类型，比如当我们需要构造一个有字符串型和整型的pair，可以这样
```cpp
typedef pair<string, int> psi;      //方式一：先定义类型别名
psi x("JZQT", 1);

pair<string, int> y("jzqt", 2);     //方式二：直接定义变量
```
在`<>`中写好成员类型，这样就定义好了pair的类型。构造出来的两个变量x和y，它们都拥有一个字符串值和一个整数值。

**注意：`<>`内的类型是有先后顺序的。**

如果我们定义好pair变量但是不初始化，之后在赋值怎么办？函数`make_pair()`可以解决这个问题，比如
```cpp
typedef pair<string, int> psi;

psi pp;
pp = make_pair("string", 100);
```
这样就成功给pair类型赋值了。但是`make_pair()`函数里面的参数也是有**先后顺序**的，并且注意类型要匹配，下面有错误样例
```cpp
typedef pair<string, int> psi;

psi pp;
pp = make_pair(100, "string");      //错误
pp = make_pair("jzqt", "string");   //错误
pp = make_pair("string", 1.1);      //编译可能通过，但这是错误的
```

#### 访问
要访问pair的成员十分简单，pair只有两个成员，成员名分别为`first`和`second`，并且都是公有的权限，也就是说使用`.`运算符来访问它们。比如
```cpp
typedef pair<string, int> psi;

psi pp("JZQT", 54);
printf("%s %d\n", pp.first.data(), pp.second);
```
就是这么简单。
