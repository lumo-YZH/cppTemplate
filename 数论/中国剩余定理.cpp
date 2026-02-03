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
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d, x1, y1;
    d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}
ll CRT(ll m[], ll r[])
{
    ll M = 1, ans = 0;
    for (ll i = 1; i <= n; i++)
        M *= m[i];
    for (ll i = 1; i <= n; i++)
    {
        ll c = M / m[i], x, y;
        exgcd(c, m[i], x, y);
        ans = (ans + r[i] * c * x % M) % M;
    }
    return (ans % M + M) % M;
}
void solve()
{
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