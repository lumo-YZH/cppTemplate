#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int n, m;
int val[N];
vector<int> e[N];
int siz[N], son[N], dep[N], fa[N], top[N], dfn[N], res[N], inx[N], tim;

void dfs1(int u, int f)
{
    siz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (auto it : e[u])
    {
        if (it == f)
            continue;
        dfs1(it, u);
        siz[u] += siz[it];
        if (siz[it] > siz[son[u]])
            son[u] = it;
    }
}
void dfs2(int u, int topf)
{
    dfn[u] = ++tim;
    inx[tim] = u;
    top[u] = topf;
    if (!son[u])
        return;
    dfs2(son[u], topf);
    for (auto it : e[u])
    {
        if (it == fa[u] || it == son[u])
            continue;
        dfs2(it, it);
    }
}
/*线段树*/
int t[N << 2], laz[N << 2];

void up(int p)
{
    t[p] = max(t[p << 1], t[p << 1 | 1]);
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        t[p] = val[inx[l]];
        return;
    }
    laz[p] = 0;
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    up(p);
}
void pushdown(int p)
{
    if (laz[p])
    {
        t[p << 1] += laz[p];
        t[p << 1 | 1] += laz[p];
        laz[p << 1] += laz[p];
        laz[p << 1 | 1] += laz[p];
        laz[p] = 0;
    }
}
void update(int p, int l, int r, int L, int R, int x)
{
    if (L <= l && r <= R)
    {
        t[p] += x;
        laz[p] += x;
        return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if (L <= mid)
        update(p << 1, l, mid, L, R, x);
    if (mid < R)
        update(p << 1 | 1, mid + 1, r, L, R, x);
    up(p);
}
int query(int p, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return t[p];
    pushdown(p);
    int ans = 0;
    int mid = l + r >> 1;
    if (L <= mid)
        ans = max(ans, query(p << 1, l, mid, L, R));
    if (mid < R)
        ans = max(ans, query(p << 1 | 1, mid + 1, r, L, R));
    return ans;
}
// void LCA1(int x, int y, int z) // 将树从x到y结点最短路径上所有节点的值加上z
// {
//     while (top[x] != top[y])
//     {
//         if (dep[top[y]] > dep[top[x]])
//             swap(x, y);
//         update(1, 1, n, dfn[top[x]], dfn[x], z); //
//         x = fa[top[x]];
//     }
//     if (dep[x] > dep[y])
//         swap(x, y);
//     update(1, 1, n, dfn[x] + 1, dfn[y], z); //
// }
int LCA2(int x, int y) // 求树从x到y结点最短路径上所有节点的值之和；
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[y]] > dep[top[x]])
            swap(x, y);
        ans = max(ans, query(1, 1, n, dfn[top[x]], dfn[x]));
        ans = max(ans, val[top[x]] + res[fa[top[x]]]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    // cout << dfn[x] << ' ' << dfn[y] << '\n';
    // cout << query(1, 1, n, dfn[y], dfn[y]) << '#' << '\n';
    ans = max(ans, query(1, 1, n, dfn[x], dfn[y]));
    if (x == top[x])
        ans = max(ans, val[x] + res[fa[x]]);
    return ans;
}

void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
        son[i] = 0;
        dep[i] = 0;
        res[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    tim = 0;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    while (m--)
    {
        int x, y, z;
        cin >> z >> x >> y;
        if (z == 1)
        {
            cout << LCA2(x, y) << '\n';
        }
        else
        {
            if (fa[x])
            {
                // cout << x << ' ' << fa[x] << ' ' << y << '\n';
                // cout << query(1, 1, n, dfn[fa[x]], dfn[fa[x]]) << '\n';
                update(1, 1, n, dfn[fa[x]], dfn[fa[x]], y);
                // cout << query(1, 1, n, dfn[fa[x]], dfn[fa[x]]) << '\n';
                val[fa[x]] += y;
            }
            if (son[x])
                update(1, 1, n, dfn[son[x]], dfn[son[x]], y);
            res[x] += y;
            // cout << x << ' ' << res[x] << '#' << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
