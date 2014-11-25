//最大二分匹配
vector<int>g[1001];
int vis[1010], m[1010];
bool dfs(int now)
{
    for(int i = 0; i < g[now].size(); ++i)
    {
         if(!vis[g[now][i]])
         {
             vis[g[now][i]] = 1;
             if(m[g[now][i]] < 0 || dfs(m[g[now][i]])) {
                 m[g[now][i]] = now;   
                 return true;
             }
         }
    }
    return false;
}

