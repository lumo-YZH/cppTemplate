#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
ll a[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;
	while(cin>>n)
	{
		a[0]=1;
		ll len=1;
		for(ll i=2;i<=n;i++)
		{
			ll f=0;
			for(ll j=0;j<len;j++)
			{
				a[j]=a[j]*i+f;
				f=a[j]/10000;
				a[j]%=10000;
			}
			if(f)
				a[len++]=f;
		}
		cout<<a[len-1];
		for(ll i=len-2;i>=0;i--)
			cout<<setw(4)<<setfill('0')<<a[i];
		cout<<'\n';
	}
	return 0;
}


