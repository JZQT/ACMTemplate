# C++STL字符串类模板string

## 概述
string类是C++的一种用于存储**字符串**对象的类型，在**命名空间std**中，被包含在`<string>`头文件里面。

string类可以用来存储字符串，在使用C++STL里面的许多模板的时候，使用**C风格**的字符串类型会有诸多不便，这个时候以string来存储字符串类型是一个不错的选择。

## 用法

#### 初始化与赋值
string类的构造函数使得它可以直接使用C风格的字符串来进行初始化，比如
```cpp
char str[] = "hello";

string x(str);
string y("hello");
```
这样构造出来的x对象与y对象的值是一样的。

当然也支持像C语言那样赋值初始化，比如
```cpp
char str[] = "hello";

string x = str;
string y = "hello";
```
这样的写法与上面的写法效果是一样的，但是上面的写法只能用来**初始化**，而这种写法可以随时用来**赋值**。

还可以直接用n个同样的字符初始化，比如
```cpp
string str(100, 'a');
```
这样构造出来的str对象是一个字符串长度为100，全部由小写字母a构成的字符串。

#### 输入输出
由于string属于C++语言的东西，所以string的输入输出方式一般是`cin`与`cout`，比如
```cpp
string str;
cin >> str;     //输入
cout << str;    //输出
```
不过也许你会不习惯，因为ACM里面一般是使用C语言的`scanf()`与`printf()`函数来输入输出的。

貌似无法使用`scanf()`函数来为string对象输入，不过可以这样子解决，比如
```cpp
char a[100];
string b;
scanf("%s", a);
b = a;
```
一般来说是不会遇到这样的情况的，在ACM中一般都是使用string作为某数据结构的模板类型之一，一般用不到string的输入。

如果你想用C语言的输出方式来输出string对象，它的成员函数`data()`和`c_str()`可以帮你解决这个问题，比如
```cpp
string str = "Hello World!"

printf("%s\n", str.data());
printf("%s\n", str.c_str());
```
两种方式效果完全一样，不过要注意，这两个成员函数返回的是**字符串常量**，不要使用字符串变量来存储，看下面的示例
```cpp
string str = "Hello World!"

char *pstr1 = str.data();           //编译出错
char *pstr2 = str.c_str();          //编译出错
const char *pstr3 = str.data();     //正常编译
const char *pstr4 = str.c_str();    //正常编译
```

#### 修改与访问
string类重载了`[]`运算符使得它与C风格的字符串一样可以**修改**和**访问**字符串中字符，比如
```cpp
string str = "Hello World!";
str[0] = 'X';
printf("%c\n", str[0]);
```
字符串下标依旧从0开始，熟悉C语言的字符串存储及使用的话对这些一定不陌生，是吧。
**注意：string的`[]`运算符与C语言一样不提供数组越界检查！**

如果想要获取string字符串的大小，就不能使用C语言的`strlen()`函数了，可以使用string自己的两个成员函数`size()`和`length()`，比如
```cpp
string str = "Hello World!";

printf("%d\n", str.length());
printf("%d\n", str.size());
```
这两个成员函数除了名字不同之外没有任何区别，都是返回字符串所占的**字节数**，之所以存在`size()`是为了保持与其他STL容器的一致。

string比较字符串是否相等以及字典序大小不能像C语言那样使用strcmp函数，string重载了`<`,`<=`,`>`,`>=`,`!=`,`==`这些运算符以方便字符串比较，比如
```cpp
string a = "abcd";
string b = "abc";

puts(a > b ? "a > b" : "a <= b");
puts(a == b ? "a == b" : "a != b");
```

想要在string字符串末尾追加字符串，不能像C语言那样使用字符串连接函数`strcat()`，不过string重载的`+=`运算符以及成员函数`append`可以解决这个问题，比如
```cpp
string a = "Hello ";
string b = "World!";
char c[] = "JZQT!";

a += b;
a += c;
a.append(b);    //append方式与+=方式效果一样
a.append(c);
```

清空字符串内容，也就是将字符串变为空串，使用string的成员函数`clear()`，同时可以使用成员函数`empty()`来判断string字符串是否为空，比如
```cpp
string str = "Hello";
str.clear();
puts(str.empty() ? "empty" : "noempty");
```
