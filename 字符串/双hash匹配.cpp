#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 2e5 + 5;
typedef pair<ll, ll> PLL;
#define first fi
#define second se
const ll P1 = 131, P2 = 233;
const ll mod1 = 1e9 + 7, mod2 = 1e9 + 9;
ll h1[N], h2[N];
ll p1[N], p2[N];

ll get_hash1(ll l, ll r)
{
  return ((h1[r] - h1[l - 1] * p1[r - l + 1]) % mod1 + mod1) % mod1;
}
ll get_hash2(ll l, ll r)
{
  return ((h2[r] - h2[l - 1] * p2[r - l + 1]) % mod2 + mod2) % mod2;
}
ll gets1(string s)
{
  ll res = 0;
  ll m = s.size();
  for (ll i = 1; i <= m; ++i)
  {
    res = (res * P1 + (ll)s[i]) % mod1;
    cout << s[i] << '\n';
  }
  return res;
}
ll gets2(string s)
{
  ll res = 0;
  ll m = s.size();
  for (ll i = 1; i <= m; ++i)
  {
    res = (res * P2 + (ll)s[i]) % mod2;
  }
  return res;
}
int main()
{
  ll n, m, q;
  string s1, s2;
  cin >> s1 >> s2;
  n = s1.size(), m = s2.size();
  s1 = '@' + s1, s2 = '@' + s2;
  p1[0] = 1, p2[0] = 1;
  for (ll i = 1; i <= m; i++)
  {
    p1[i] = (p1[i - 1] * P1) % mod1;
    h1[i] = (h1[i - 1] * P1 + (ll)s2[i]) % mod1;
  }
  for (ll i = 1; i <= m; i++)
  {
    p2[i] = (p2[i - 1] * P2) % mod2;
    h2[i] = (h2[i - 1] * P2 + (ll)s2[i]) % mod2;
  }
  ll x = get_hash1(1, m), y = get_hash2(1, m);
  for (ll i = 1; i <= n; i++)
  {
    p1[i] = (p1[i - 1] * P1) % mod1;
    h1[i] = (h1[i - 1] * P1 + (ll)s1[i]) % mod1;
  }
  for (ll i = 1; i <= n; i++)
  {
    p2[i] = (p2[i - 1] * P2) % mod2;
    h2[i] = (h2[i - 1] * P2 + (ll)s1[i]) % mod2;
  }
  ll ans = 0;
  for (ll i = 1; i + m - 1 <= n; i++)
  {
    if (get_hash1(i, i + m - 1) == x && get_hash2(i, i + m - 1) == y)
      ans++;
  }
  cout << ans << '\n';
  return 0;
}