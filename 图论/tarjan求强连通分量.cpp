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
vector<vector<ll>> g(N);
ll dfn[N], low[N], tot;
ll stk[N], instk[N], top;
ll scc[N], siz[N], cnt;
ll vis[N];
void tarjan(ll x) // O(n+m)
{
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    vis[x] = 1;
    for (ll y : g[x])
    {
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (instk[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x])
    {
        ll y;
        ++cnt;
        do
        {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        } while (y != x);
    }
}
void solve()
{
    ll n, m, u, v;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            tarjan(i);
    }
    ll ans = 0;
    for (ll i = 1; i <= cnt; i++)
    {
        if (siz[i] > 1)
            ans++;
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