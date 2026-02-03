#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = long double;
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
db trans(ll x, ll y)
{
    db r = sqrt(x * x + y * y);
    db o = atan2(y, x);
    // z = (o * 180) / M_PI;
    return o;
}
db a[N];
void solve()
{
    ll n, x, y, k;
    cin >> n >> k;
    set<db> s;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x >> y;
        db z = trans(x, y);
        a[i] = z;
    }
    sort(a + 1, a + 1 + n);
    for (ll i = n + 1; i <= 2 * n; i++)
        a[i] = a[i - n] + 2 * PI;
    db ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        db res = a[i + k] - a[i];
        ans = max(ans, res);
    }
    if (n == k)
        ans = 2 * PI;
    cout << fixed << setprecision(12) << ans << '\n';
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