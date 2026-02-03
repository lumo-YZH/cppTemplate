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
const ll M = 2e5 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll a[M];
struct node
{
    ll l, r;
    ll maxn, add, pos;
} tr[4 * M];
void pushup(ll u)
{
    // tr[u].maxn = max(tr[u << 1].maxn, tr[u << 1 | 1].maxn);
    if (tr[u << 1].maxn >= tr[u << 1 | 1].maxn)
    {
        tr[u].maxn = tr[u << 1].maxn;
        tr[u].pos = tr[u << 1].pos;
    }
    else
    {
        tr[u].maxn = tr[u << 1 | 1].maxn;
        tr[u].pos = tr[u << 1 | 1].pos;
    }
}
void pushdown(ll u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    left.add = (left.add + root.add);
    left.maxn = (left.maxn + root.add);

    right.add = (right.add + root.add);
    right.maxn = (right.maxn + root.add);
    root.add = 0;
}

void build(ll u, ll l, ll r)
{
    tr[u] = {l, r};
    if (l == r)
    {
        tr[u].maxn = 0;
        tr[u].pos = l;
        return;
    }
    ll mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

pair<ll, ll> query(ll u, ll l, ll r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return {tr[u].maxn, tr[u].pos};
    pushdown(u);
    ll mid = (tr[u].l + tr[u].r) >> 1;
    ll s = -1e18;
    ll p = -1;
    if (l <= mid)
    {
        auto [v, pp] = query(u << 1, l, r);
        if (v > s)
        {
            s = v;
            p = pp;
        }
    }
    if (r > mid)
    {
        auto [v, pp] = query(u << 1 | 1, l, r);
        if (v > s)
        {
            s = v;
            p = pp;
        }
    }
    return {s, p};
}

void modify(ll u, ll l, ll r, ll v)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].maxn = (tr[u].maxn + v);
        tr[u].add = (tr[u].add + v);
    }
    else
    {
        pushdown(u);
        ll mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, v);
        if (r > mid)
            modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> p(N);
    vector<vector<array<ll, 3>>> v(N);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]].push_back(i);
    }
    for (ll i = 1; i <= 1000000; i++)
    {
        if (p[i].size() >= 3)
        {
            ll m = p[i].size();
            ll s = p[i][0];
            ll e = p[i][m - 1];
            v[s + 1].push_back({p[i][1] + 1, e, 1});
            for (ll j = 1; j < m - 2; j++)
            {
                // cout << p[i][j] << '\n';
                v[p[i][j] + 1].push_back({p[i][j] + 1, e, -1});
                if (p[i][j + 1] + 1 <= e)
                {
                    v[p[i][j] + 1].push_back({p[i][j + 1] + 1, e, 1});
                }
                //
            }
            if (p[i][m - 2] + 1 <= n - 1)
                v[p[i][m - 2] + 1].push_back({p[i][m - 2] + 1, e, -1});
        }
    }
    ll ans = 0, L = -1, R = -1;
    build(1, 1, n);
    for (ll i = 2; i <= n - 1; i++)
    {
        for (auto [l, r, w] : v[i])
        {
            modify(1, l, r, w);
            // cout << l << ' ' << r << ' ' << w << "#\n";
        }
        auto [res, x] = query(1, i + 1, n);
        // cout << res << ' ' << x << '\n';
        if (res > ans)
        {
            ans = res;
            L = i;
            R = x;
        }
    }
    // ans = 0;
    // set<ll> s;
    // for (ll i = 1; i <= L - 1; i++)
    // {
    //     ll f = 0, ff = 0;
    //     for (auto q : p[a[i]])
    //     {
    //         if (q >= L && q < R)
    //             f = 1;
    //         if (q >= R && q <= n)
    //             ff = 1;
    //     }
    //     if (f && ff)
    //     {
    //         s.insert(a[i]);
    //     }
    // }
    cout << ans << '\n';
    if (L == -1 && R == -1)
        cout << 2 << ' ' << n << '\n';
    else
        cout << L << ' ' << R << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll T;
    T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}