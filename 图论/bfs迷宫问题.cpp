#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
typedef pair<ll,ll>PLL;
ll n,l,r,m;
ll d[1003][1003];
char g[1003][1003];
ll dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
ll bfs(ll u,ll v)
{
	queue<PLL>q;
	memset(d,-1,sizeof(d));
	d[u][v]=0;
	q.push({u,v});
	while(q.size())
	{
		auto t=q.front();
		q.pop();
		for(ll i=0;i<4;i++)
		{
			ll x=t.first+dx[i];
			ll y=t.second+dy[i];
			if(x>=1&&x<=n&&y>=1&&y<=m&&g[x][y]!='*'&&d[x][y]==-1)
			{
				d[x][y]=d[t.first][t.second]+1;
				q.push({x,y});
			}
		}
	}
	return d[l][r];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll a,b,x1,y1,x2,y2;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>g[i][j];
		}
	}
	cin>>x1>>y1>>x2>>y2;
    bfs(x1,y1);
    cout<<d[x2][y2]<<'\n';
}

