#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
ll a[100001];
ll d[100001];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,x;
	cin>>n>>m>>x;
	a[0]=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	while(m--)
	{
		ll l,r;
		cin>>l>>r;	
		d[l]+=x;
		d[r+1]-=x;
	}	
	for(ll i=1;i<=n;i++)
	{
		a[i]=a[i-1]+d[i];
		cout<<a[i]<<' ';
	}
	return 0;
}

