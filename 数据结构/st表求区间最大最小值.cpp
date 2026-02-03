#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
ll lg[100001];
ll st[100001][10];
ll query(ll l,ll r)
{
	ll x=lg[r-1];
	return max(st[l][x],st[r-(1<<x)+1][x]);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,l,r;
	lg[1]=0;
	cin>>n>>m;
	for(ll i=2;i<=n;++i)
	{
		lg[i]=lg[i>>1]+1;
	}
	for(ll i=1;i<=n;++i)
		cin>>st[i][0];
	for(ll j=1;j<=lg[n];++j)
	{
		for(ll i=1;i+(1<<j)-1<=n;++i)
			st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
	}
	for(ll i=1;i<=m;++i)
	{
		cin>>l>>r;
		cout<<query(l,r)<<'\n';
	}
	return 0;
}

