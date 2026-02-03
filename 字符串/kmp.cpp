#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll a[N];
ll kmp(string text, string pattern)
{
    ll n = text.size(), m = pattern.size();
    if (m == 0)
        return 0;
    vector<ll> nxt(m);
    for (ll i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = nxt[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        nxt[i] = j;
    }
    for (ll i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && text[i] != pattern[j])
            j = nxt[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m)
            return i - m + 1;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    t = 1;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (kmp(s1, s2) != -1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}