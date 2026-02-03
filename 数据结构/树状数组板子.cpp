#include<bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod=998244353;
constexpr int N=1e5+10;

ll f[N],g[N];

struct BIT {
    vector<ll> tree;
    ll n;
    ll lowbit(ll x){
        return x&(-x);
    }
    BIT(ll size):n(size),tree(size+1,0) {}

    void add(ll x,ll v){
        for(ll i=x;i<=n;i+=lowbit(i)) tree[i]=(tree[i]+v)%mod;
    }

    void update(ll l,ll r,ll x){
        add(l,x);
        add(r+1,-x);
    }  

    ll getsum(ll x) {
        ll ans=0;
        for (ll i=x;i;i-=lowbit(i)){
            ans=(ans+tree[i])%mod;
        }
        return ans;
    }

    ll query(ll l,ll r) {
        return getsum(r)-getsum(l-1);
    }
};

void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>f[i];
	// for(int i=1;i<=n;i++) cin>>g[i];

	BIT F(n),G(n);

	for(int i=1;i<=n;i++){
		F.add(i,f[i]);
		// G.add(i,g[n-i+1]);
	}

	ll ans=0,sum=0;
	for(int i=1;i<=n;i++){
		ans=(ans+sum*g[i]%mod)%mod;
		sum=(sum+f[i])%mod;
	}
	sum=0;
	for(int i=n;i>=1;i--){
		sum=(sum+g[i])%mod;
		ans=(ans+sum*f[i]%mod)%mod;
	}

	// ans=(ans+ans)%mod;
	// cout<<"ans="<<ans<<'\n';

	while(q--){
		int t,i,x,j;
		cin>>t;
		if(t==1){
			cin>>i>>x;
			F.add(i,x);
		}
		if(t==2)
		{
			cin>>i;
			cout<<F.getsum(i)<<'\n';
		}
		else 
		{
			cin>>i>>j>>x;
			F.query(i,j);
		}
		// cout<<ans<<'\n';
	}	
}

int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

	int t=1;
	// cin>>t;
	while(t--) solve();

	return 0;
}