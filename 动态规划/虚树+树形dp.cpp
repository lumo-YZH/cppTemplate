// 树链剖分+虚树+树形DP 110ms
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005, M = N * 2;
int h[N], to[M], ne[M], tot;
void add(int x, int y)
{ // 连边
    to[++tot] = y;
    ne[tot] = h[x];
    h[x] = tot;
}
int fa[N], dep[N], siz[N], son[N], tp[N]; // 重链
int dfn[N], cnt;                          // dfs序
int s[N], top;                            // 栈
int n, k, q, a[N], ans;

void dfs1(int x, int f)
{ // 树链剖分
    dfn[x] = ++cnt;
    dep[x] = dep[f] + 1;
    siz[x] = 1;
    fa[x] = f;
    for (int i = h[x]; i; i = ne[i])
    {
        int y = to[i];
        if (y == f)
            continue;
        dfs1(y, x);
        siz[x] += siz[y];
        if (siz[son[x]] < siz[y])
            son[x] = y;
    }
}
void dfs2(int x, int t)
{              // 树链剖分
    tp[x] = t; // 链头
    if (!son[x])
        return;
    dfs2(son[x], t); // 搜重儿子
    for (int i = h[x]; i; i = ne[i])
    {
        int y = to[i];
        if (!tp[y])
            dfs2(y, y); // 搜轻儿子
    }
}
int lca(int x, int y)
{ // 求lca
    while (tp[x] != tp[y])
    {
        if (dep[tp[x]] < dep[tp[y]])
            swap(x, y);
        x = fa[tp[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
int cmp(int a, int b)
{
    return dfn[a] < dfn[b];
}
void build()
{                                // 建虚树
    sort(a + 1, a + k + 1, cmp); // 按dfs序排序
    tot = 0;                     // 清空
    s[top = 1] = 1;              // 根节点入栈
    if (a[1] != 1)
        s[++top] = a[1];
    for (int i = 2; i <= k; i++)
    { // 枚举查询点
        int l = lca(s[top], a[i]);
        // 对当前链连边,top出栈
        while (top > 1 && dep[s[top - 1]] >= dep[l])
            add(s[top - 1], s[top]), top--;
        // 对lca和top连边,top出栈,lca入栈
        if (l != s[top])
            add(l, s[top]), s[top] = l;
        // 查询点入栈
        s[++top] = a[i];
    }
    while (top) // 对最后一条链连边,top出栈
        add(s[top - 1], s[top]), top--;
}
void DP(int x)
{ // 树形DP
    if (siz[x])
    { // x是查询点
        for (int i = h[x]; i; i = ne[i])
        {
            DP(to[i]);
            if (siz[to[i]])
                ans++, siz[to[i]] = 0;
        }
    }
    else
    { // x不是查询点
        for (int i = h[x]; i; i = ne[i])
        {
            DP(to[i]);
            siz[x] += siz[to[i]], siz[to[i]] = 0;
        }
        if (siz[x] > 1)
            ans++, siz[x] = 0;
    }
    h[x] = 0; // 清空
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    memset(h + 1, 0, n << 2);
    memset(siz + 1, 0, n << 2); // 清空
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &k);
        bool flag = 1;
        siz[1] = 0; // 清空
        for (int i = 1; i <= k; i++)
            scanf("%d", &a[i]), siz[a[i]] = 1;
        for (int i = 1; i <= k; i++)
            if (siz[fa[a[i]]])
            { // 无解
                while (k)
                    siz[a[k--]] = 0; // 清空
                puts("-1");
                flag = 0;
                break;
            }
        cout << flag << '\n';
        if (flag)
        {
            build();
            ans = 0;
            DP(1);
            printf("%d\n", ans);
        }
    }
    return 0;
}