#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
typedef pair<ll, ll> PLL;
#define first fi
#define second se
ll a[N];
long long PowerMod(long long a, long long b, long long c)
{
    long long ans = 1;
    long long k;
    k = a;
    k = k % c;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * k) % c;
        b >>= 1;
        k = (k * k) % c;
    }
    return ans;
}
long long C(long long n, long long m, long long p)
{
    if (m > n)
        return 0;
    long long ans = 1;
    for (int i = 1; i <= m; i++)
    {
        long long a = (n + i - m) % p;
        long long b = i % p;
        ans = ans * (a * PowerMod(b, p - 2, p) % p) % p;
    }
    return ans;
}
long long Lucas(long long n, long long m, long long p) // (n,m)=(n/p,m/p)*(n%p,m%p),O(plogp+logp(n));
{
    if (m == 0)
        return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, n, m, md;
    t = 1;
    // cin>>t;
    while (t--)
    {
        cin >> n >> m >> md;
        cout << Lucas(n, m, md);
    }
}