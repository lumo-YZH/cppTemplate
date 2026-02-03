#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
const int maxn = 1e5+10;

vector <int> G[maxn];
int n,m;//n为点的数量 m为边的数量
int vis[maxn],pei[maxn];//vis记录点是否被访问，pei存每个点所匹配的点

bool dfs(int u)
{
    for(int i=0;i<G[u].size();i++)//遍历与该点关联的所有点
    {
        int v=G[u][i];//所关联的点
        if(!vis[v])//没访问过
        {
            vis[v]=1;
            if(!pei[v]||dfs(pei[v]))//若关联的点没被匹配或者dfs返回true说明关联的点所匹配的点可以挪走，则把关联的点和传入的点匹配（即下面代码）
            {
                pei[v]=u;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int ans=0;
    for(int i=1;i<=n;i++)pei[i]=0;
    for(int i=1;i<=n;i++)//遍历所有的点
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;//如果有增广路则加一条匹配边
    }
    cout<<ans<<'\n';
}
int main()
{
    ll k,u,v;
    while(cin>>k)
    {
        if(k==0)break;
        cin>>m>>n;
        for(ll i=1;i<=n;i++)
            G[i].clear();
        while(k--)
        {
            cin>>u>>v;
            G[v].push_back(u);
        }
        solve();
    }
}