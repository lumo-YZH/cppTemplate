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
ll f[30];
void solve()
{
    ll n;
    cin >> n;
    cout << f[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    f[0] = 1;
    for (ll i = 1; i <= 20; i++)
    {
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
        // cout << f[i] << '\n';
    }
    // cin>>T;
    while (T--)
    {
        solve();
    }
}