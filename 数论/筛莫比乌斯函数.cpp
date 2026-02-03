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
const ll M = 1e7 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
typedef pair<ll, ll> PLL;
#define fi first
#define se second
vector<int> prime;
int vis[M], mu[M];
vector<int> G[N];
int a[N], b[N], cnt[N];

void getMu()
{
    mu[1] = 1;
    for (int i = 2; i <= M; ++i)
    {
        if (!vis[i])
        {
            prime.emplace_back(i);
            mu[i] = -1;
        }
        for (int j : prime)
        {
            if (i * j > M)
                break;
            vis[i * j] = 1;
            if (i % j == 0)
                mu[i * j] = 0;
            else
                mu[i * j] = -mu[i];
        }
    }
}
void solve()
{
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