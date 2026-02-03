#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e5 + 5;
const ll md = 998244353;
const ll MOD = 1e18 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const ll PI = acos(-1);
const ll eps = 1e-6;
const ll E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
#define lc t[p].l
#define rc t[p].r
ll n, K, root, cur, ans1, ans2;
struct KD
{
    ll l, r;
    ll v[2];       // 点的坐标值
    ll L[2], U[2]; // 子树区域坐标极值
    bool operator<(const KD &b) const
    {
        return v[K] < b.v[K];
    }
} t[N];

ll dis(ll p)
{
    ll s = 0;
    for (ll i = 0; i < 2; i++)
        s += abs(t[cur].v[i] - t[p].v[i]);
    return s;
}
ll dis1(ll p) // 当前点到p子树区域的最小距离
{
    if (!p)
        return 1e18;
    ll s = 0;
    for (ll i = 0; i < 2; i++)
    {
        s += max(t[cur].v[i] - t[p].U[i], 0LL) +
             max(t[p].L[i] - t[cur].v[i], 0LL);
    }
    return s;
}
ll dis2(ll p) // 当前点到p子树区域的最大距离
{
    if (!p)
        return 0;
    ll s = 0;
    for (ll i = 0; i < 2; i++)
    {
        s += (max(t[cur].v[i] - t[p].L[i], t[p].U[i] - t[cur].v[i]));
    }
    return s;
}
void pushup(ll p) // 更新p子树区域的坐标范围
{
    for (ll i = 0; i < 2; i++)
    {
        t[p].L[i] = t[p].U[i] = t[p].v[i];
        if (lc)
        {
            t[p].L[i] = min(t[p].L[i], t[lc].L[i]);
            t[p].U[i] = max(t[p].U[i], t[lc].U[i]);
        }
        if (rc)
        {
            t[p].L[i] = min(t[p].L[i], t[rc].L[i]);
            t[p].U[i] = max(t[p].U[i], t[rc].U[i]);
        }
    }
}
ll build(ll l, ll r, ll k)
{
    if (l > r)
        return 0;
    ll m = (l + r) >> 1;
    K = k;
    nth_element(t + l, t + m, t + r + 1);
    t[m].l = build(l, m - 1, k ^ 1);
    t[m].r = build(m + 1, r, k ^ 1);
    pushup(m);
    return m;
}
void query1(ll p)
{
    if (!p)
        return;
    if (p != cur)
        ans1 = min(ans1, dis(p));
    ll dl = dis1(lc), dr = dis1(rc);
    if (dl < dr)
    {
        if (dl < ans1)
            query1(lc);
        if (dr < ans1)
            query1(rc);
    }
    else
    {
        if (dr < ans1)
            query1(rc);
        if (dl < ans1)
            query1(lc);
    }
}
void query2(ll p)
{
    if (!p)
        return;
    if (p != cur)
        ans2 = max(ans2, dis(p));
    ll dl = dis2(lc), dr = dis2(rc);
    if (dl > dr)
    {
        if (dl > ans2)
            query2(lc);
        if (dr > ans2)
            query2(rc);
    }
    else
    {
        if (dr > ans2)
            query2(rc);
        if (dl > ans2)
            query2(lc);
    }
}
void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> t[i].v[0] >> t[i].v[1];
    root = build(1, n, 0);
    ll ans = 1e18;
    for (cur = 1; cur <= n; cur++)
    {
        ans1 = 1e18, query1(root);
        ans2 = 0, query2(root);
        ans = min(ans, ans2 - ans1);
    }
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