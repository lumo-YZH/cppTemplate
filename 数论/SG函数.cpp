#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e3 + 5;
const db PI = acos(-1);
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll a[N], f[N];
int SG[N], S[N], ans[N];
void sgk(int x)
{
    for (int i = 1; i <= N; i++)
    {
        memset(S, 0, sizeof(S));
        for (int j = 1; j <= 20 && f[j] <= i; j++)
            S[SG[i - f[j]]] = 1;
        for (int j = 0; j <= N; j++)
        {
            if (!S[j])
            {
                SG[i] = j;
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (ll i = 1; i <= 1001; i++)
        ans[i] = SG[i];
    ll t, n, m, p;
    while (cin >> m >> n >> p)
    {
        if (m == 0 && n == 0 && p == 0)
            break;
        // cout<<ans[m]<<' '<<ans[n]<<' '<<ans[p]<<'\n';
        if ((ans[m] ^ ans[n] ^ ans[p]))
            cout << "Fibo\n";
        else
            cout << "Nacci\n";
    }
}