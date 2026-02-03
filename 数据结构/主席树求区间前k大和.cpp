#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
#define mid (l + r) / 2
const ll N = 3e5 + 10;
ll n, m, q, tot = 0;
ll a[N], b[N];
ll T[N], sum[N * 20], ls[N * 20], rs[N * 20];
ll s[N * 20];

ll built(ll l, ll r)
{
    ll node = tot++;
    if (l < r)
    {
        ls[node] = built(l, mid);
        rs[node] = built(mid + 1, r);
    }
    return node;
}

ll update(ll pre, ll l, ll r, ll x)
{
    ll node = tot++;
    ls[node] = ls[pre];
    rs[node] = rs[pre];
    sum[node] = sum[pre] + 1;
    s[node] = s[pre] + b[x];
    if (l < r)
    {
        if (x <= mid)
            ls[node] = update(ls[pre], l, mid, x);
        else
            rs[node] = update(rs[pre], mid + 1, r, x);
    }
    return node;
}
ll query1(ll u, ll v, ll l, ll r, ll k) // 求第k大元素
{
    if (l == r)
        return b[l];
    ll cnt = sum[rs[v]] - sum[rs[u]];
    if (cnt >= k)
    {
        return query(rs[u], rs[v], mid + 1, r, k);
    }
    else
    {
        return query(ls[u], ls[v], l, mid, k - cnt);
    }
}
// 查询区间 [l, r] 内大于 x 的元素个数
ll queryGreater(ll u, ll v, ll l, ll r, ll x)
{
    if (l == r)
        return (b[l] > x) ? (sum[v] - sum[u]) : 0;
    ll mid = (l + r) >> 1;
    if (b[mid] <= x)
        return queryGreater(rs[u], rs[v], mid + 1, r, x);
    else
        return (sum[rs[v]] - sum[rs[u]]) + queryGreater(ls[u], ls[v], l, mid, x);
}

ll query(ll u, ll v, ll l, ll r, ll k)
{
    if (l == r)
        return b[l] * k;
    ll cnt = sum[rs[v]] - sum[rs[u]];
    if (cnt >= k)
    {
        return query(rs[u], rs[v], mid + 1, r, k);
    }
    else
    {
        ll res = s[rs[v]] - s[rs[u]];
        return res + query(ls[u], ls[v], l, mid, k - cnt);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        tot = 0;
        memset(T, 0, sizeof(T));
        memset(sum, 0, sizeof(sum));
        memset(ls, 0, sizeof(ls));
        memset(rs, 0, sizeof(rs));
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        m = unique(b + 1, b + 1 + n) - b - 1;
        T[0] = built(1, m);
        for (ll i = 1; i <= n; i++)
        {
            a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
            T[i] = update(T[i - 1], 1, m, a[i]);
        }
        cin >> q;
        while (q--)
        {
            ll l, r, k;
            cin >> l >> r >> k;
            ll ans = query(T[l - 1], T[r], 1, m, k);
            k = r - l + 1;
            ans += k * (k + 1) * (2 * k + 1) / 6;
            cout << ans << '\n';
        }
    }
    return 0;
}
