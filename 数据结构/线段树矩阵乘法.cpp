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
const ll inf = -1e18;
typedef pair<ll, ll> PLL;
#define fi first
#define se second

struct Mat
{
    ll a[4][4];
    Mat()
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                a[i][j] = inf;
    }
};

Mat mul(const Mat &A, const Mat &B)
{
    Mat C;
    for (int i = 0; i < 4; ++i)
        for (int k = 0; k < 4; ++k)
            for (int j = 0; j < 4; ++j)
                if (A.a[i][j] != inf && B.a[j][k] != inf)
                    C.a[i][k] = max(C.a[i][k], A.a[i][j] + B.a[j][k]);
    return C;
}

Mat toMat(ll v)
{
    Mat M;
    for (int s = 0; s < 4; ++s)
        M.a[s][0] = 0;
    for (int s = 0; s < 3; ++s)
        M.a[s][s + 1] = v;
    return M;
}

struct Node
{
    int l, r;
    Mat mat;
} tr[4 * N];

int n, q;
ll a[N];

void pushup(int u)
{
    tr[u].mat = mul(tr[u << 1].mat, tr[u << 1 | 1].mat);
}

void build(int u, int l, int r)
{
    tr[u].l = l;
    tr[u].r = r;
    if (l == r)
    {
        tr[u].mat = toMat(a[l]);
        return;
    }
    int m = (l + r) >> 1;
    build(u << 1, l, m);
    build(u << 1 | 1, m + 1, r);
    pushup(u);
}

void modify(int u, int pos, ll val)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].mat = toMat(val);
        return;
    }
    int m = (tr[u].l + tr[u].r) >> 1;
    if (pos <= m)
        modify(u << 1, pos, val);
    else
        modify(u << 1 | 1, pos, val);
    pushup(u);
}

ll ssolve()
{
    Mat M = tr[1].mat;
    ll ans = inf;
    for (int s = 0; s < 4; ++s)
        ans = max(ans, M.a[s][s]);
    return max(ans, 0LL);
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);
    cout << ssolve() << '\n';
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        a[x] = y;
        modify(1, x, y);
        cout << ssolve() << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
