#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e4+5;
typedef pair<ll,ll>PLL;
ll b[N];
vector<ll>edge[N];
struct node
{
	ll x,y;
}a[N];
ll c[1000][1000];
void bfs(ll x)
{
	b[x]=1;
	for(auto y:edge[x])
	{
		if(!b[y])
		{
			bfs(y);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t,n,m,x,y;
	t=1;
	//cin>>t;
	while(t--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(a[i].x==a[j].x||a[i].y==a[j].y)
				{
					edge[i].push_back(j);
					edge[i].push_back(j);
				}
			}
		}
		memset(b,0,sizeof (b));
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(!b[i])
			{
				bfs(i);
				++ans;
			}
		}
		cout<<ans-1<<'\n';
	}
}

