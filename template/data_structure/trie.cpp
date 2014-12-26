/* trie(字典树)算法模板
 * 
 * 版本：
 * 静态trie
 *
 * 题意：
 * 给n个字符串和m个询问
 * 每个询问输入一个字符串
 * 询问在前面的n个字符串中有几个字符串以该字符串为前缀
 * 每一个字符串中的字符均为小写字母
 * 
 * 数据：
 * N 表示字符串的最大数量
 * M 表示字符串的最大长度
 * n 表示字符串的数量
 * m 表示询问的次数
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10001;
const int M = 100;

struct Trie     //定义Trie节点结构体
{
    int chid[26];   //后续节点，因为字符为小写字母，所以是数组长度26
    int num;        //存储前缀出现次数
    void init()
    {
        memset(chid, -1, sizeof(chid));
        num = 0;
    }
};

Trie trie[10*N];
char str[M];
int cnt;    //trie新节点编号
int n, m;

void InitRead();

void DataProcess();

void Insert(char s[]);  //将一个字符串插入trie中

int Query(char s[]);    //查询一个字符串成为前缀的次数

inline int GetID(char ch)   //获取一个字符在chid中的编号
{
    return ch - 'a';
}

int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        InitRead();
        DataProcess();
    }
    return 0;
}

void InitRead()
{
    trie[0].init();
    cnt = 0;
    for (int i=0; i<n; ++i)
    {
        scanf("%s", str);
        Insert(str);
    }
    return;
}

void DataProcess()
{
    for (int i=0; i<m; ++i)
    {
        scanf("%s", str);
        printf("%d\n", Query(str));
    }
    return;
}

void Insert(char s[])
{
    int len = strlen(s);
    int id = 0;     //trie节点编号，初始为0代表root节点
    int chnum;
    for (int i=0; i<len; ++i)
    {
        chnum = GetID(s[i]);
        if (trie[id].chid[chnum] == -1)
        {
            trie[id].chid[chnum] = ++cnt;   //增加新节点
            trie[cnt].init();               //初始化新节点
        }
        id = trie[id].chid[chnum];
        trie[id].num++;     //计算一次前缀
    }
    return;
}

int Query(char s[])
{
    int len = strlen(s);
    int id = 0;
    int chnum;
    for (int i=0; i<len; ++i)
    {
        chnum = GetID(s[i]);
        if (trie[id].chid[chnum] == -1) //该前缀未出现过
        {
            return 0;
        }
        id = trie[id].chid[chnum];
    }
    return trie[id].num;
}
