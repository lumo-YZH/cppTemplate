#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=2e4+5;
typedef pair<ll,ll>PLL;
ll b[N];
ll t,n,m,x,y,k;
vector<ll>edge[N];
ll dfs(ll x,ll c)
{
	if(x==k&&c==n)
		return 1;
	for(auto y:edge[x])
	{
		if(!b[y])
		{
			b[y]=1;
			if(dfs(y,c+1))
				return 1;
			b[y]=0;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	t=1;
	//cin>>t;
	while(t--)
	{
		cin>>n>>m;
		while(m--)
		{
			cin>>x>>y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		cin>>k;
		if(dfs(k,0))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}

