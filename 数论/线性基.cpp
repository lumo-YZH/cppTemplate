#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const ll N = 1e6 + 10;
const ll INF = 0x3f3f3f3f3f;
const ll mod = 998244353;
ll n, m, k;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    auto query = [&](vector<ll> &f, ll x)
    {
        for (int i = 59; i >= 0; i--)
        {
            if ((x ^ f[i]) > x)
            {
                x ^= f[i];
            }
        }
        return x;
    };
    auto add = [&](vector<ll> &f, ll x)
    {
        for (int i = 59; i >= 0; i--)
        {
            if (x >> i & 1)
            {
                if (!f[i])
                {
                    f[i] = x;
                    return;
                }
                x ^= f[i];
            }
        }
    };
    auto dfs = [&](auto &&self, int i, vector<ll> f, ll x)
    {
        if (i >= n)
        {
            ans = max(ans, query(f, x));
            return;
        }
        if (i + 2 <= n)
        {
            self(self, i + 3, f, x ^ a[i + 1]);
        }
        add(f, a[i]);
        self(self, i + 2, move(f), x);
    };
    dfs(dfs, 0, vector<ll>(60), 0);
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
