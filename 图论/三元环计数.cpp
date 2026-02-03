#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 5;
int deg[MAXN], vis[MAXN];
vector<int> G[MAXN];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e(m);
    for (auto &[v, u] : e)
        cin >> v >> u, ++deg[v], ++deg[u];
    for (auto [v, u] : e)
    {
        if (deg[v] < deg[u] || deg[v] == deg[u] && v > u)
            swap(v, u);
        G[v].push_back(u); // 令度数小的点连向度数大的点，当然如果两个点度数一样，令编号小的点连向编号大的点。
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        for (auto u : G[i])
            vis[u] = i;
        for (auto u : G[i])
            for (auto w : G[u])
            {
                ans += (vis[w] == i);
            }
    }
    cout << ans << '\n';

    return 0;
}
