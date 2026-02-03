#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll a,m,b;
string s;
inline ll read(ll m){
	register ll x=0,f=0;
    ll n=s.size();
	for(ll i=0;i<n;i++)
    {
		x=x*10+s[i]-'0';
		if(x>=m) f=1;
		x%=m;
	}
	return x+(f==1?m:0);
}

ll phi(ll n){
	ll ans=n,m=sqrt(n);
	for(ll i=2;i<=m;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;	
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}

ll fast_pow(ll a,ll b,ll p){
	ll ret=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1) ret=ret*a%p;
	return ret;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>s>>m;
    b=read(phi(m));
    cout<<fast_pow(a,b,m);
    return 0;
}