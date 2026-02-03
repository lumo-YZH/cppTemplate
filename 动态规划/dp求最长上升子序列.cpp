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
    t=1;
	//cin>>t;
	while(t--)
	{
		ll ans=1;
		cin>>n;
		for(ll i=1;i<=n;++i)
			cin>>a[i];
		for(ll i=1;i<=n;i++)
		{
			dp[i]=1;
			for(ll j=1;j<i;++j)
			{
				if(a[j]<=a[i])
					dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

