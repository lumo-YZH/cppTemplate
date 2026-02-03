#include <bits/stdc++.h>
#define MAXN 400500
using namespace std;
struct edge
{
    int to, nxt, val;
} e[MAXN];
int h[MAXN], cnt, dis[MAXN], tot, ans;
bool vis[MAXN];
void add(int from, int to, int value)
{
    e[++cnt].nxt = h[from];
    e[cnt].to = to;
    e[cnt].val = value;
    h[from] = cnt;
}
int n, m;
struct node
{
    int pos, dis;
    friend bool operator<(node a, node b)
    {
        return a.dis > b.dis;
    }
} tmp;
priority_queue<node> q;
void prim()
{
    for (int i = 1; i <= n; i++)
        dis[i] = 2147483647;
    dis[1] = 0;
    tmp.dis = 0;
    tmp.pos = 1;
    q.push(tmp);
    while (!q.empty())
    {
        tmp = q.top();
        q.pop();
        int u = tmp.pos;
        int d = tmp.dis;
        if (vis[u])
            continue;
        tot++;
        vis[u] = 1;
        ans += dis[u];
        for (int i = h[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            int w = e[i].val;
            if (dis[v] > w)
            {
                tmp.dis = dis[v] = w;
                tmp.pos = v;
                q.push(tmp);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    prim();
    if (tot == n)
        cout << ans;
    else
        puts("orz");
    return 0;
}