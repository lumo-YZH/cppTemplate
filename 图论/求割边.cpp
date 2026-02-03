#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e3 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second

ll f[N], tot = 0;
ll dfn[N], low[N];
ll ans = 1e18;

ll find(ll x)
{
	if(f[x]==x)
		return x;
	else
		f[x]=find(f[x]);
	return f[x];
}
struct edge
{
    ll  v,w, id;
};
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
vector<edge> g[N];

void tarjan(ll u, ll id) 
{
    dfn[u] = low[u] = ++tot;
    for (auto e : g[u]) 
    {
        if (e.id == id) continue; 
        
        if (!dfn[e.v]) 
        { 
            tarjan(e.v, e.id);
            low[u] = min(low[u], low[e.v]);
            if (low[e.v] > dfn[u]) 
            
                ans = min(ans, e.w);
        } 
        else 
        {
            low[u] = min(low[u], dfn[e.v]);
        }
    }
}

void solve()
{
    ll n, m;
    while(cin>>n>>m)
    {
        tot = 0, ans = 1e18;
        if(n==0&&m==0)
            break;
        for (ll i = 1; i <= n;i++)
        {
            f[i] = i ;
            dfn[i] = 0;
            g[i].clear();
        }
        for (ll i = 1; i <= m; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w, i});
            g[v].push_back({u, w, i});
            if(find(u)!=find(v))
            {
                merge(u, v);
            }
        }
        tarjan(1, -1);
        ll f = 0,ff=0;
        ll k = find(1);
        for (ll i = 2; i <= n;i++)
        {
            if(k!=find(i))
                ff = 1;
        }

        if (ff == 0)
        {

            if (ans == 1e18)
                cout << -1 << '\n';
            else if(ans == 0)
                cout << 1 << '\n';
            else
                cout << ans << '\n';
        }
        else
            cout << 0 << '\n';
        
    }

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll T;
    T = 1;
    //cin>>T;
    while (T--)
    {
        solve();
    }
}