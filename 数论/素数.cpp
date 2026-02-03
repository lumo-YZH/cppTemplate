#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const ll M=1e10;
bool isprime[M+1];
ll prime[M+1];
ll cnt=0;
void eular()
{
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(ll i=2;i<=M;++i)
	{
		if(isprime[i])
			prime[++cnt]=i;
		for(ll j=1;j<=cnt&&i*prime[j]<=M;++j)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
 }
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>m;
		if(isprime[m])
			cout<<"Yes"<<'\n';
		else
			cout<<"No"<<'\n';
	}
	return 0;
}

