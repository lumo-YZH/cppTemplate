#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
vector<ll> b(N + 1, 0);
vector<ll> cnt(N + 1, 0);
vector<vector<ll>> v(N + 1);

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        b[a[i]]++;

    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
            cnt[i] += b[j];
    }
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
            v[j].push_back(i);  
    }

    for (ll i = 0; i < n; i++)
    {
        ll ans = 1;
        for (ll j = v[a[i]].size() - 1; j >= 0; j--)
        {
            ll w = v[a[i]][j];
            if (cnt[w] >= k)
            {
                ans = w;
                break;
            }
        }
        cout << ans << '\n';
    }
}