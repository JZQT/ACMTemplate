/* 求不带权的二分图的最大匹配模板
 * N 代表二分图中某个点集的最大数量 
 * n 代表二分图中某个点集的数量   编号从0～n-1
 * 如果二分图中所有点的数量为n，那么求得的最大匹配为ans / 2
 */

vector <int> e[N];  //邻接表存图
bool vis[N];
int match[N];       //存储匹配点

void Init()
{
    memset(match, -1, sizeof(match));   //初始化每个点都未被匹配
    for (int i=0; i<n; ++i) e[i].clear();
    return;
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

int DataProcess()       //求最大匹配数
{
    int ans = 0;    //最大匹配初始化为0
    for (int i=0; i<n; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (Dfs(i)) ans++;
    }
    return ans;
}
