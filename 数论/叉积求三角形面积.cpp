#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e2 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll x[N], y[N];
db cross(ll x1, ll y1, ll x2, ll y2)
{
    return x1 * y2 - y1 * x2;
}
db cal(ll i, ll j, ll k)
{
    ll x1 = x[j] - x[i];
    ll y1 = y[j] - y[i];
    ll x2 = x[k] - x[i];
    ll y2 = y[k] - y[i];
    db z = cross(x1, y1, x2, y2);
    if (z == 0)
        return 1e18;
    db res = 0.5 * fabs(z);
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    db ans = 1e18;
    for (ll i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            for (ll k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                ans = min(ans, cal(i, j, k));
            }
        }
    }
    if (ans == 1e18)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}