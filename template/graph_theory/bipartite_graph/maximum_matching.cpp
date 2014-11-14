/* 求不带权的二分图的最大匹配数
 */

bool vis[N];
int match[N];       //匹配点
vector <int> e[N];  //邻接表

void Init()
{
    memset(match, -1, sizeof(match));   //初始化每个点都未被匹配
    for (int i=0; i<=n; ++i) e[i].clear();  //初始化邻接表
    return;
}

int DataProcess()       //求最大匹配数
{
    int ans = 0;    //最大匹配初始化为0
    for (int i=0; i<n; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (Dfs(i)) ans++;
    }
    return ans;     //如果0~n-1的点是二分图所有点，那么最大匹配为ans / 2
}

bool Dfs(int x)     //dfs求最大匹配
{
    int size = e[x].size();
    for (int i=0; i<size; ++i)
    {
        if (!vis[e[x][i]])
        {
            vis[e[x][i]] = true;
            if (match[e[x][i]] == -1 || Dfs(match[e[x][i]]))
            {
                match[e[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}
