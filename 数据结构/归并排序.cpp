#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll p=1e6+5;
ll a[p],b[p];
ll ans;
void mergesort(ll l,ll r)
{
	if(l>=r)
		return;
	mergesort(l,(l+r)/2);
	mergesort((l+r)/2+1,r);
	ll cnt=0,p1=l,p2=(l+r)/2+1;
	while(p1<=(l+r)/2&&p2<=r)
	{
		if(a[p1]<a[p2])   
		{
			b[++cnt]=a[p2++];
			ans+=(l+r)/2-p1+1;
		}
		else
		{
			b[++cnt]=a[p1++];
		}
	}
	while(p1<=(l+r)/2)
		b[++cnt]=a[p1++];
	while(p2<=r)
		b[++cnt]=a[p2++];
	for(ll i=1;i<=cnt;i++)
		a[l+i-1]=b[i];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;++i)
			cin>>a[i];
		mergesort(1,n);
		cout<<ans<<'\n';
	}
	return 0;
}

