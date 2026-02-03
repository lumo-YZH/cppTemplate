#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e5 + 5;
const ll md = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db eps = 1e-6;
const db E = 2.718281828459045;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
#define mid ((l + r) >> 1)
ll tree[22][N << 2], lazy[N << 2];
int n, m, x;

void push_up(int k)
{
    for (int i = 0; i < 22; i++)
    {
        tree[i][k] = tree[i][k << 1] + tree[i][k << 1 | 1];
    }
}

void push_down(int k, int son)
{
    if (lazy[k])
    {
        lazy[k << 1] ^= lazy[k];
        lazy[k << 1 | 1] ^= lazy[k];
        for (int i = 0; i < 22; i++)
        {
            if ((lazy[k] >> i) & 1)
            {
                tree[i][k << 1] = son - (son >> 1) - tree[i][k << 1];
                tree[i][k << 1 | 1] = (son >> 1) - tree[i][k << 1 | 1];
            }
        }
        lazy[k] = 0;
    }
}

void build(int l, int r, int k)
{
    if (l == r)
    {
        scanf("%d", &x);
        for (int i = 0; i < 22; i++)
        {
            if ((x >> i) & 1)
                tree[i][k] = 1;
        }
        return;
    }
    build(l, mid, k << 1);
    build(mid + 1, r, k << 1 | 1);
    push_up(k);
}

void update(int L, int R, int x, int l, int r, int k)
{
    if (L <= l && R >= r)
    {
        lazy[k] ^= x;
        for (int i = 0; i < 22; i++)
        {
            if ((x >> i) & 1)
            {
                tree[i][k] = r - l + 1 - tree[i][k];
            }
        }
        return;
    }
    push_down(k, r - l + 1);
    if (L <= mid)
        update(L, R, x, l, mid, k << 1);
    if (R > mid)
        update(L, R, x, mid + 1, r, k << 1 | 1);
    push_up(k);
}

ll query(int L, int R, int l, int r, int k)
{
    if (L <= l && R >= r)
    {
        ll cnt = 0;
        for (int i = 0; i < 22; i++)
        {
            cnt += tree[i][k] << i;
        }
        return cnt;
    }
    push_down(k, r - l + 1);
    ll ans = 0;
    if (L <= mid)
        ans += query(L, R, l, mid, k << 1);
    if (R > mid)
        ans += query(L, R, mid + 1, r, k << 1 | 1);
    return ans;
}

int main()
{
    int op, l, r, x;
    scanf("%d", &n);
    build(1, n, 1);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(l, r, 1, n, 1));
        }
        else
        {
            scanf("%d %d %d", &l, &r, &x);
            update(l, r, x, 1, n, 1);
        }
    }
    return 0;
}