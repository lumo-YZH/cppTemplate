#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll x)
{
	if(x==1)return false;
	if(x==2||x==3)return true;
	if(x%6!=1&&x%6!=5)return false;
	for(int i=5;i*i<=x;i+=6)
	{
		if(x%i==0||x%(i+2)==0)return false;
	}
	return true;
}
const ll p=10000000;
ll a[10000001]={0};
ll b[10000001]={0};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(ll i=1;i<=p;i++)
	{
		string s=to_string(i);
		reverse(s.begin(),s.end());
		if(check(i)&&check(stoll(s)))
		{
			a[i]=1;
		}
		b[i]=a[i]+b[i-1];
	}
	ll t,l,r;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		cout<<b[r]-b[l-1]<<'\n';
	}
	return 0;
}

