/* 强连通分量tarjan算法模板缩点版本
 * N 表示图中节点的最大数量  
 * n 表示图中节点的数量    编号为1～n
 */

vector <int> e[N];  //vector邻接表存图
int dfn[N], low[N];
int stack[N], stop; //手写栈
bool instack[N];
int belong[N];      //存储该点属于哪一个强连通分量
int timer;          //时间戳
int sccn;           //强连通分量个数

void Init()
{
    memset(dfn, -1, sizeof(dfn));
    memset(instack, false, sizeof(vis));
    stop = timer = sccn = 0;
    for (int i=1; i<=n; ++i) e[i].clear();
    return;
}

void Tarjan(int x)
{
    int y;
    dfn[x] = low[x] = ++timer;
    stack[stop++] = x;
    instack[x] = true;;
    int size = e[x].size();
    for (int i=0; i<size; ++i)
    {
        y = e[x][i];
        if (!vis[y])
        {
            Tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (instack[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x])   //此时代表找到一个强连通分量
    {
        sccn++;
        do
        {
            y = stack[--stop];
            instack[y] = false;
            belong[y] = sccn;
        } while (x != y);
    }
    return;
}

void DataProcess()
{
    for (int i=1; i<=n; ++i)
    {
        if (dfn[i] == -1)
        {
            Tarjan(i);
        }
    }
    return;
}
