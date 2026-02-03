#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll n,maxn;
ll a[N], b[N], f[N];
ll lowbit(ll x)
{
	return x&(-x);
}
void modify(ll x, ll u)
{
	for(; x <= maxn; x += lowbit(x)) 
        f[x] = max(f[x], u);
}

ll query(ll x)
{
	ll ans = 0;
	for(; x; x -= lowbit(x)) 
        ans = max(ans, f[x]);

	return ans;
}



int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    while(cin>>n)
    {
        ll ans=0;
        maxn=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]++;
            maxn=max(maxn,a[i]);
        }
        for(ll i=1;i<=maxn;i++)
            f[i]=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>b[i];
            ll k=query(a[i]);
            modify(a[i],b[i]+k);
            ans=max(ans,b[i]+k);
        }
        cout<<ans<<'\n';
    }

	return 0;
}