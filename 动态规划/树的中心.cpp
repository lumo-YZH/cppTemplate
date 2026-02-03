#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll d1[N], d2[N], p1[N], up[N];
vector<vector<pair<ll, ll>>> g(N);
ll dfs_d(ll u, ll fa)
{
    d1[u] = 0, d2[u] = 0;
    for (auto [v, w] : g[u])
    {
        if (v == fa)
            continue;
        ll d = dfs_d(v, u) + w;
        if (d >= d1[u])
            d2[u] = d1[u], d1[u] = d, p1[u] = v;
        else if (d > d2[u])
            d2[u] = d;
    }
    return d1[u];
}

void dfs_u(ll u, ll fa)
{
    for (auto [v, w] : g[u])
    {
        if (v == fa)
            continue;
        if (p1[u] == v)
            up[v] = max(up[u], d2[u] + w);
        else
            up[v] = max(up[u], d1[u]) + w;
        dfs_u(v, u);
    }
}
void solve()
{
    ll n, u, v, w;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ll ans = 1e18;
    dfs_d(1, -1);
    dfs_u(1, -1);
    for (ll i = 1; i <= n; i++)
    {
        ans = min(ans, max(up[i], d1[i]));
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
}