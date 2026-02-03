#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
ll f[N],sizee[N];
ll find(ll x)
{
	if(f[x]==x)
		return x;
	else
		f[x]=find(f[x]);
	return f[x];
}
void merge(ll a,ll b)
{
	ll t1,t2;
	t1=find(a);
	t2=find(b);
	if(t1>t2)
		f[t1]=t2;
	else
		f[t2]=t1;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		f[i]=i;
		sizee[i]=1;
	}
 	while(m--)
	{
	 	string s;
		ll a,b;
		cin>>s;
		if(s=="C")
		{
		 	cin>>a>>b;
		 	if(find(a)==find(b))
			 	continue;
		 	sizee[find(b)]+=sizee[find(a)];
		 	f[find(a)]=find(b);
		}
		else if(s=="Q1")
		{
		 	cin>>a>>b;
		 	if(find(a)==find(b))
				cout<<"YES"<<'\n';
			else
				cout<<"NO"<<'\n';
		}
		else
		{
			cin>>a;
			cout<<sizee[find(a)]<<'\n';
 		}
 	}
	return 0;
}
