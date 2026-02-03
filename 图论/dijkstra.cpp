#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
ll n,k,m,d[N],x,y,z,sum,f[N];
bool vis[N];
struct edge
{
	ll u,w;
    // bool operator < (const edge &a)const
    // {
    //     if(w==a.w)
    //         return u<a.u;
    //     return w<a.w;
    // }
};
vector<edge>b[N];
priority_queue<pair<ll,ll>>q;
void dijkstra(ll start)
{
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    q.push({0,start});
    d[start]=0;
	while(!q.empty())
    {
		x=q.top().second,sum=q.top().first;
		q.pop();
        if(vis[x])continue;
           vis[x]=1;
		for(int i=0;i<b[x].size();i++)
      	{
			y=b[x][i].u,z=b[x][i].w;
			if(d[x]+z<d[y])
         	{
				d[y]=d[x]+z;
				q.push({-d[y],y});
			}
		}
	}
}

signed main()
{
	cin>>n>>m;
    ll s=2*n+1;
    for(ll i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        b[x].push_back({y,z});
        b[y].push_back({x,z});
        b[x].push_back({x+n,0});
        b[y].push_back({y+n,0});
        b[x].push_back({y+n,0});
        b[y].push_back({x+n,0});
        b[x+n].push_back({y+n,z});
        b[y+n].push_back({x+n,z});
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>k;
        b[s].push_back({i,k});
    }
    dijkstra(s);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ans=max(ans,d[i+n]);
    }
    cout<<ans<<'\n';
   
}