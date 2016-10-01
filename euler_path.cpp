#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100+5;

//无向图打印欧拉路径或回路
//输入保证是一个n顶点,m条边的具有欧拉回路或欧拉路径的无向图

int n;//图中顶点,顶点编号1到n
int m;//图中边
int G[maxn][maxn];
int vis[maxn][maxn];//vis[i][j]==1表示i与j点直接存在一条边

//打印欧拉路径或欧拉回路(必须本图有欧拉路径或回路才行)
//打印的结果中最后一条边才是u开始的,打印的第一条边不一定是u开始的
//如果是打印欧拉路径,那么输入的u一定要是起点之一,即度数为奇数的点之一
//否则euler打印的的边不会构成欧拉路径,只不过是乱序打印图中所有的边而已
void euler(int u)
{
    for(int v=1;v<=n;v++)if(vis[u][v])
    {
        //递归思想,去掉了u与v这条边,
        //余图还是一个具有欧拉道路的图,且v变成一个起点了
        vis[u][v]=0;
        euler(v);
        printf("%d %d\n",u,v);
    }
}

//输出欧拉回路或路径上按顺序经过的节点
//u也必须要是起点之一,否则输出的也是乱序点而已
void euler_point(int u)
{
    for(int v=1;v<=n;v++)if(vis[u][v])
    {
        vis[u][v]=0;
        euler_point(v);
    }
    printf("%d\n",u);
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(G,0,sizeof(G));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u][v]=1;
            vis[u][v]=1;
        }

        int u;
        scanf("%d",&u);
        euler_point(u);

    }
    return 0;
}
