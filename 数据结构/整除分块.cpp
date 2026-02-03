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
typedef pair<ll, ll> PLL;
#define fi first
#define se second

void solve()
{
    int n, l, r;
    int sum = 0;
    for (int l = 1; l <= n; l = r + 1)
    {
        int tmp = n / l;
        r = min(n, n / tmp);
        sum += (sum[r] - sum[l - 1]) * tmp * tmp;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
