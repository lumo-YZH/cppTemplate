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
ll n, a[N], stk[N], ls[N], rs[N], siz[N], jc[N], jcn[N], inv[N];
ll L, R, ans = 0;
ll quickpow(ll a, ll b, ll md)
{
    a %= md;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % md;
        b >>= 1;
        a = (a * a) % md;
    }
    return ans;
}
ll C(ll n, ll m)
{
    if (m > n)
        return 0;
    ll res = 0;
    res = jc[n] * jcn[n - m] % md * jcn[m] % md;
    return res;
}
void init()
{
    jc[0] = 1, jcn[0] = 1, inv[1] = 1;
    for (ll i = 1; i < min(N, md); i++)
    {
        if (i >= 2)
            inv[i] = 1ll * (md - md / i) * inv[md % i] % md;
        jc[i] = (jc[i - 1] * i) % md;
        jcn[i] = inv[i] * jcn[i - 1] % md;
    }
}
void dfs(ll u, ll fa, ll d)
{
    siz[u] = 1;
    if (ls[u])
        dfs(ls[u], u, d + 1);
    if (rs[u])
        dfs(rs[u], u, d + 1);
    siz[u] += siz[ls[u]] + siz[rs[u]];
    // cout << u << ' ' << siz[ls[u]] <<' ' siz[rs[u]] << '\n';
    ll k = C(siz[u] + d - 1, d);
    ans = (ans + k) % md;
}
void solve()
{
    cin >> n;
    ll pos = 0, top = 0;
    ans = 0;
    ll s = 0;
    ll minn = 1e18;
    for (ll i = 1; i <= n; i++)
        ls[i] = 0, rs[i] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < minn)
        {
            minn = a[i];
            s = i;
        }
        pos = top;
        while (pos && a[stk[pos]] > a[i])
            pos--;
        if (pos)
            rs[stk[pos]] = i;
        if (pos < top)
            ls[i] = stk[pos + 1];
        stk[top = ++pos] = i;
    }
    s = stk[1];
    // cout << s << '\n';
    dfs(s, -1, 1);
    cout << ans + 1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll T;
    T = 1;
    init();
    cin >> T;
    while (T--)
    {
        solve();
    }
}
