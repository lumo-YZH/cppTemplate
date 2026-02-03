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
ll x[N], y[N];
void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (ll i = 1; i <= n; i++)
    {
        ll fz = y[i], fm = 1;
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            fz = fz * (k - x[j]) % md;
            fm = fm * (x[i] - x[j]) % md;
        }
        ans = (ans + fz * (quickpow(fm, md - 2, md))) % md;
    }
    cout << (ans + md) % md << '\n';
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