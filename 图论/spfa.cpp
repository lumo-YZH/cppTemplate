#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e5+5;
typedef pair<ll,ll>PLL;
#define first fi
#define second se
vector<PLL> g[N];
ll d[N];

void spfa(ll start)
{
    memset(d,0x3f,sizeof d);
    bitset<N>vis;
    queue<int> q;
    q.push(1);
    d[1]=0;
    while(!q.empty())
	{
        ll t=q.front(); q.pop();
        vis[t]=false;
        for(auto&[v,w]:g[t])
		{
            // cnt[v]=cnt[t]+1;//判断有无负环
			// if(cnt[v]>=n)
			// 	return false;
            if(d[v]>d[t]+w)
			{
                d[v]=d[t]+w;
                if(!vis[v])
				{
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
}

void solve()
{
	ll n,m;
    cin>>n>>m;
    while(m--)
	{
        ll a,b,c; 
		cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    spfa();
    for(ll i=2;i<=n;i++)
	{
        cout<<d[i]<<'\n';
    }
    return ;
}

signed main ()
{
    ios::sync_with_stdio(0); 
    cin.tie(0),cout.tie(0);
    solve();
}