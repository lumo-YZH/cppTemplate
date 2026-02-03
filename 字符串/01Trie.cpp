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
int n, a[N];
int ch[N * 31][2], idx = 0;
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = x >> i & 1;
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = x >> i & 1;
        if (ch[p][!j])
        {
            res += 1 << i;
            p = ch[p][!j];
        }
        else
            p = ch[p][j];
    }
    return res;
}
void solve()
{
    cin >> n;
    idx = 0;
    memset(ch, 0, sizeof(ch));
    for (int i = 1; i <= n; i++)
        cin >> a[i], insert(a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) // 求n个整数的异或和有哪些
        ans = max(ans, query(a[i]));
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