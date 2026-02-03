#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
typedef pair<ll, ll> PLL;
#define fi first
#define se second

struct edge
{
    ll to, next;
} G[N * 2];
ll head[N], num;

void add_edge(ll from, ll to)
{
    G[++num].next = head[from];
    G[num].to = to;
    head[from] = num;
}

ll siz[N];
ll depth[N];
ll son[N];
ll top[N];
ll father[N];

void dfs1(ll fa, ll cur, ll dd)
{
    father[cur] = fa;
    siz[cur] = 1;
    depth[cur] = dd;
    ll heavy = 0, hid = cur;
    for (ll i = head[cur]; i != -1; i = G[i].next)
    {
        ll to = G[i].to;
        if (fa != to)
        {
            dfs1(cur, to, dd + 1);
            siz[cur] += siz[to];
            if (siz[to] > heavy)
            {
                heavy = siz[to];
                hid = to;
            }
        }
    }
    son[cur] = hid;
}

void dfs2(ll cur, ll tt)
{
    top[cur] = tt;
    if (son[cur] != cur)
        dfs2(son[cur], tt);
    for (ll i = head[cur]; i != -1; i = G[i].next)
    {
        ll to = G[i].to;
        if (father[cur] != to && to != son[cur])
            dfs2(to, to);
    }
}

ll lca(ll u, ll v)
{
    while (top[u] != top[v])
    {
        if (depth[father[top[u]]] < depth[father[top[v]]])
            swap(u, v);
        if (u == father[top[u]]) // 特判，为整棵树的根结点
            return u;
        u = father[top[u]];
    }
    if (depth[u] < depth[v])
        return u;
    else
        return v;
}
void init()
{
    memset(head, -1, sizeof(head));
    num = 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    ll n, m, s;
    cin >> n >> m >> s;

    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }

    dfs1(s, s, 1);
    dfs2(s, s);

    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}
