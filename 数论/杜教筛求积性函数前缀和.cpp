#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 2e6 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll vis[N], prime[N], mu[N], phi[N], cnt;
map<ll, ll> mp_mu, mp_phi;
void init()
{
    mu[1] = phi[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
            prime[++cnt] = i, mu[i] = -1, phi[i] = i - 1;
        for (int j = 1; i * prime[j] < N; j++)
        {
            int p = prime[j];
            vis[i * p] = 1;
            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            mu[i * p] = -mu[i];
            phi[i * p] = phi[i] * (p - 1);
        }
    }
    for (int i = 1; i < N; i++)
        mu[i] += mu[i - 1], phi[i] += phi[i - 1];
}
ll Sphi(ll n)
{
    if (n < N)
        return phi[n];
    if (mp_phi[n])
        return mp_phi[n];
    ll ans = n * (n + 1) / 2;
    for (ll l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans -= Sphi(n / l) * (r - l + 1);
    }
    return mp_phi[n] = ans;
}
ll Smu(ll n)
{
    if (n < N)
        return mu[n];
    if (mp_mu[n])
        return mp_mu[n];
    ll ans = 1;
    for (ll l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans -= Smu(n / l) * (r - l + 1);
    }
    return mp_mu[n] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    cout << Sphi(n) << ' ' << Smu(n) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    init();
    T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}