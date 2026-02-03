#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 2e5 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
const ll M = 20;
ll ans = 0;
ll n, u, v;

vector<ll> g[N];
ll fa[N];
ll deep[N];
ll up[M][N];
vector<ll> k(N + 1, 0);

void bfs(ll s, ll n)
{
    fill(fa, fa + n + 1, 0);
    fill(deep, deep + n + 1, 0);
    queue<ll> q;
    q.push(s);
    fa[s] = 0;
    deep[s] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll v : g[u])
        {
            if (v != fa[u])
            {
                fa[v] = u;
                deep[v] = deep[u] + 1;
                q.push(v);
            }
        }
    }
}
ll dfs(ll u, ll fa)
{
    ll z = k[u];
    for (ll v : g[u])
    {
        if (v == fa)
            continue;
        z = max(z, dfs(v, u));
    }
    ans += z;
    return z;
}

void plca(ll n)
{
    for (ll i = 1; i <= n; ++i)
    {
        up[0][i] = fa[i];
    }
    for (ll k = 1; k < M; ++k)
    {
        for (ll i = 1; i <= n; ++i)
        {
            up[k][i] = up[k - 1][up[k - 1][i]];
        }
    }
}

ll lca(ll u, ll v)
{
    if (deep[u] < deep[v])
    {
        swap(u, v);
    }
    for (ll k = M - 1; k >= 0; --k)
    {
        if (deep[u] - (1 << k) >= deep[v])
        {
            u = up[k][u];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (ll k = M - 1; k >= 0; --k)
    {
        if (up[k][u] != up[k][v])
        {
            u = up[k][u];
            v = up[k][v];
        }
    }
    return fa[u];
}
void solve()
{
    cin >> n;
    for (ll i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(n, n);
    plca(n);

    ll p = 0;
    for (ll m = 1; m <= n; m++)
    {
        if (p == 0)
            p = m;
        else
            p = lca(p, m);
        if (p != 0)
            k[p] = max(k[p], m);
    }
    dfs(n, 0);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll T;
    T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
}
