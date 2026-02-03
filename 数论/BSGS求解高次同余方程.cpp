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
// a^x=b(mod p),x×îÐ¡
ll bsgs(ll a, ll b, ll p)
{
    a %= p, b %= p;
    if (b == 1)
        return 0;
    ll m = ceil(sqrt(p));
    ll t = b;
    unordered_map<int, int> hash;
    hash[b] = 0;
    for (int j = 1; j < m; j++)
    {
        t = t * a % p;
        hash[t] = j;
    }
    ll mi = 1;
    for (int i = 1; i <= m; i++)
        mi = mi * a % p;
    t = 1;
    for (int i = 1; i <= m; i++)
    {
        t = t * mi % p;
        if (hash.count(t))
            return i * m - hash[t];
    }
    return -1;
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