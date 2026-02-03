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
const ll M = 1e7;
bool isprime[M + 1];
ll prime[M + 1], C[N];
ll cnt = 0, len = 1;
void eular()
{
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (ll i = 2; i <= M; ++i)
    {
        if (isprime[i])
            prime[++cnt] = i;
        for (ll j = 1; j <= cnt && i * prime[j] <= M; ++j)
        {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll get(ll n, ll p) // n!中的因子为p的个数
{
    ll res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    };
    return res;
}
ll getC(ll n, ll m, ll p) // C中因子为p的个数
{
    return get(n, p) - get(m, p) - get(n - m, p);
}
void mul(ll C[], ll p, ll &len)
{
    ll t = 0;
    for (ll i = 0; i < len; i++)
    {
        t += C[i] * p;
        C[i] = t % 10;
        t /= 10;
    }
    while (t)
    {
        C[len++] = t % 10;
        t /= 10;
    }
}
void solve()
{
    ll n, m;
    C[0] = 1, len = 1;
    cin >> n >> m; // 求C(n,m);
    for (ll i = 1; i <= cnt; i++)
    {
        ll p = prime[i];
        ll s = getC(n, m, p);
        while (s--)
            mul(C, p, len);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    eular();
    // cin>>T;
    while (T--)
    {
        solve();
    }
}