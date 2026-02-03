#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
int a[N];
int n, m;

struct Node
{
    int l, r;
    ll sum;
    ll add;
} tr[N * 4];
;

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add += root.add, left.sum += (ll)(left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (ll)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}
void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, a[l], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int l, int r, int v)
{
    if (l <= tr[u].l && r >= tr[u].r)
    {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, v);
        if (r > mid)
            modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}

ll query(int u, int l, int r)
{
    if (l <= tr[u].l && r >= tr[u].r)
        return tr[u].sum;
    pushdown(u);
    ll v = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        v = query(u << 1, l, r);
    if (r > mid)
        v += query(u << 1 | 1, l, r);
    return v;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for (ll z = 1; z <= t; z++)
    {
        cin >> n;
        cout << "Case " << z << ":\n";
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        build(1, 1, n);

        int l, r;
        string s;
        while (1)
        {
            cin >> s;
            if (s == "End")
                break;
            cin >> l >> r;
            if (s == "Query")
                cout << query(1, l, r) << '\n';
            else if (s == "Add")
                modify(1, l, l, r);
            else
                modify(1, l, l, -r);
        }
    }
    return 0;
}