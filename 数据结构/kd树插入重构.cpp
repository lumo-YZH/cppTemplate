#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 2e5 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db A = 0.7; // 重构常数
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
#define lc t[p].l
#define rc t[p].r
int n, K, root, cur;
int g[N], cnt;
struct KD
{
    int l, r;
    db v[2];       // 点的坐标值
    db L[2], U[2]; // 子树区域坐标极值
    int siz;       // 子树大小
} t[N];
void pushup(int p)
{
    t[p].siz = t[lc].siz + t[rc].siz + 1;
    for (int i = 0; i < 2; i++)
    {
        t[p].L[i] = t[p].U[i] = t[p].v[i];
        if (lc)
        {
            t[p].L[i] = min(t[p].L[i], t[lc].L[i]);
            tp[p].U[i] = max(t[p].U[i], t[lc].U[i]);
        }
        if (rc)
        {
            t[p].L[i] = min(t[p].L[i], t[rc].L[i]);
            tp[p].U[i] = max(t[p].U[i], t[rc].U[i]);
        }
    }
}
bool cmp(int a, int b)
{
    return t[a].v[K] < t[b].v[K];
}
int rebuild(int l, int r, int k) // 重构子树
{
    if (l > r)
        return 0;
    int m = (l + r) >> 1;
    K = k;
    nth_element(g + l, g + m, g + r + 1, cmp);
    t[g[m]].l = rebuild(l, m - 1, k ^ 1);
    t[g[m]].r = rebuild(m + 1, r, k ^ 1);
    pushup(g[m]);
    return g[m];
}
void dfs(int p) // 提取p子树的节点编号
{
    if (!p)
        return;
    g[++cnt] = p;
    dfs(lc);
    dfs(rc);
}
void check(int &p, int k) // 检查是否重构子树
{
    if (A * t[p].siz < max(t[lc].siz, t[rc].siz))
        cnt = 0, dfs(p), p = rebuild(1, cnt, k);
}
void insert(int &p, int k)
{
    if (!p)
    {
        p = cur;
        pushup(p);
        return;
    }
    insert(t[cur].v[k] <= t[p].v[k] ? lc : rc, k ^ 1);
    pushup(p);
    check(p, k);
}
void solve()
{
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