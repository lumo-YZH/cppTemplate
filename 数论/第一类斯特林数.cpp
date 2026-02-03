#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 5e4 + 5;
const ll M = 210;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll S[N][M], C[M][M]; // s[n][m]将n个数划分成m个非空的全排列
void init()
{
    S[0][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            S[i][j] = (S[i - 1][j - 1] + (i - 1) * S[i - 1][j]) % MOD;
    for (int i = 0; i < M; i++)
        C[i][0] = 1;
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
}
void solve()
{
    ll n, a, b, ans = 0;
    cin >> n >> a >> b;
    ans = S[n - 1][a + b - 2] * C[a + b - 2][a - 1] % MOD;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    init();
    cin >> T;
    while (T--)
    {
        solve();
    }
}