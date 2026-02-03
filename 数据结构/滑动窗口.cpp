#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
ll a[N];
map<ll,ll>mp;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	ll l=1,r=1;
	while(r<=n)
	{
		ll k1=a[r];
		mp[k1]++;
		r++;
		while(mp[k1]>1)
		{
			ll k2=a[l];
			mp[k2]--;
			l++;
		}
		ans=max(ans,r-l);
	}
	cout<<ans;	
	return 0;
}


