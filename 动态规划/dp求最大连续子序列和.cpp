#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll p=1e6+5;
ll a[p];
ll dp[p];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	for(ll i=1;i<=n;++i)
		cin>>a[i];
	dp[0]=0;
	ll maxx=a[1];
	for(ll i=1;i<=n;++i)
	{
		dp[i]=max(dp[i-1]+a[i],a[i]);
		maxx=max(dp[i],maxx);
	}
	cout<<maxx<<'\n';
}
	return 0;
}

