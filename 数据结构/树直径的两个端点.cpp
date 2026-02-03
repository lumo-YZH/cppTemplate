#include <bits/stdc++.h>
#define LL long long
const int kN = 2e5 + 10;
int n, m, rt, t0;
int edgenum, head[kN], v[kN << 1], ne[kN << 1];
int fa[kN], sz[kN], dep[kN], son[kN], top[kN];

std::vector<int> nodes[kN];
int nowlen, diameter[2], ans[kN];
inline int read()
{
    int f = 1, w = 0;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isdigit(ch); ch = getchar())
        w = (w << 3) + (w << 1) + (ch ^ '0');
    return f * w;
}
void Add(int u_, int v_)
{
    v[++edgenum] = v_;
    ne[edgenum] = head[u_];
    head[u_] = edgenum;
}
namespace Cut
{
    void Dfs1(int u_, int fa_)
    {
        sz[u_] = 1;
        fa[u_] = fa_;
        dep[u_] = dep[fa_] + 1;
        for (int i = head[u_]; i; i = ne[i])
        {
            int v_ = v[i];
            if (v_ == fa_)
                continue;
            Dfs1(v_, u_);
            sz[u_] += sz[v_];
            if (sz[v_] > sz[son[u_]])
                son[u_] = v_;
        }
    }
    void Dfs2(int u_, int top_)
    {
        top[u_] = top_;
        if (son[u_])
            Dfs2(son[u_], top_);
        for (int i = head[u_]; i; i = ne[i])
        {
            int v_ = v[i];
            if (v_ == fa[u_] || v_ == son[u_])
                continue;
            Dfs2(v_, v_);
        }
    }
    int Lca(int u_, int v_)
    {
        for (; top[u_] != top[v_]; u_ = fa[top[u_]])
        {
            if (dep[top[u_]] < dep[top[v_]])
                std::swap(u_, v_);
        }
        return dep[u_] < dep[v_] ? u_ : v_;
    }
}
void AddNode(int u_)
{
    int len[2] = {0};
    for (int i = 0; i < 2; ++i)
    {
        int lca = Cut::Lca(u_, diameter[i]);
        len[i] = dep[u_] + dep[diameter[i]] - 2 * dep[lca] + 1;
    }
    if (std::max(len[0], len[1]) <= nowlen)
        return;
    diameter[len[0] >= len[1]] = u_;
    nowlen = std::max(len[0], len[1]);
}
void Init()
{
    n = read();
    for (int i = 1; i < n; ++i)
    {
        int u_ = read(), v_ = read();
        Add(u_, v_), Add(v_, u_);
    }
    rt = read(), t0 = read();
    Cut::Dfs1(rt, 0), Cut::Dfs2(rt, rt);

    for (int i = 1; i <= n; ++i)
        nodes[dep[i] - 1].push_back(i);
    diameter[0] = diameter[1] = rt;
    nowlen = 1;
    for (int i = 1; i <= t0 - 1; ++i)
    {
        for (auto u_ : nodes[i])
            AddNode(u_);
    }
}
bool check(int speed_, int time_)
{
    return 1ll * speed_ * (time_ - t0) >= nowlen / 2ll;
}
int main()
{
    // freopen("1.txt", "r", stdin);
    Init();

    for (int i = t0, k = n; i <= 2 * n; ++i)
    {
        if (i <= n)
            for (auto u_ : nodes[i])
                AddNode(u_);
        while (k && check(k, i))
            ans[k--] = i;
    }
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " ";
    return 0;
}