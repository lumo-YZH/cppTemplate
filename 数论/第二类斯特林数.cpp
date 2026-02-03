#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 55;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
int S[N][N][100], len[N][N]; // s[n][m]n个人占m个房子,高精度
void add(int x, int y)
{
    len[x][y] = max(len[x - 1][y - 1], len[x - 1][y]);
    for (int i = 0; i < len[x][y]; i++)
    {
        S[x][y][i] += S[x - 1][y - 1][i] + y * S[x - 1][y][i];
        S[x][y][i + 1] += S[x][y][i] / 10;
        S[x][y][i] %= 10;
    }
    while (S[x][y][len[x][y]])
    {
        S[x][y][len[x][y] + 1] += S[x][y][len[x][y]] / 10;
        S[x][y][len[x][y]] %= 10;
        len[x][y]++;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    S[0][0][0] = 1;
    len[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            add(i, j);
    if (!len[n][m])
        cout << 0;
    for (int i = len[n][m] - 1; i >= 0; i--)
        cout << S[n][m][i];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
}