#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
ll a[N],b[N],c[N],d[N];
void quicksort(ll l,ll r)
{
	if(l>=r)
		return;
	ll mid=rand()%(r-l+1)+1,cnt1=0,cnt2=0,cnt3=0;
	for(ll i=l;i<=r;i++)
	{
		if(a[i]<a[mid])
			b[++cnt1]=a[i];
		else if(a[i]==a[mid])
			c[++cnt2]=a[i];
		else
			d[++cnt3]=a[i];
	}
	ll init=l-1;
	for(ll i=1;i<=cnt1;i++)
		a[++init]=b[i];
	for(ll i=1;i<=cnt2;i++)
		a[++init]=c[i];
	for(ll i=1;i<=cnt3;i++)
		a[++init]=d[i];
	quicksort(l,l+cnt1-1);
	quicksort(r-cnt3+1,r);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,t;
	t=1;
	while(t--)
	{
		cin>>n;
		for(ll i=1;i<=n;++i)
			cin>>a[i];
		quicksort(1,n);
		for(ll i=1;i<=n;++i)
			cout<<a[i]<<' ';
	}
	return 0;
}

