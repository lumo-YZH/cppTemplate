#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2005;
using PII = pair<int, int>;
vector<PII> G[N];
int d[N];
bitset<N> vis;
void dijkstra(int s){
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    vis.reset();
    int flg = 1;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.emplace(0, s);
    while (!q.empty())
    {
        int v = q.top().second;
        q.pop();
        if (!flg && v == s)
            break;
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto [w, u] : G[v]){
            if (!vis[u] && d[v] + w < d[u]){
                d[u] = d[v] + w;
                q.emplace(d[u], u);
            }
        }
        if (flg){
            vis[s] = 0, d[s] = 0x3f3f3f3f;
            flg = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, c, ans = 0;
    cin >> n >> m ;
    for (int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        if (w <= c)
            G[x].emplace_back(w, y);
    }
    int mn = 0x3f3f3f3f;
    for (int v = 1; v <= n; v++){// Ê±¼ä¸´ÔÓ¶ÈO(n(n+m)log(n))
        dijkstra(v);
        mn = min(mn, d[v]);
    }
    cout << mn;
    return 0;
}