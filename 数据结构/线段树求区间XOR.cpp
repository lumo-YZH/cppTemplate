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
    ll xor_val;
};

Node tr[N * 4];

void pushup(int u)
{
    tr[u].xor_val = tr[u << 1].xor_val ^ tr[u << 1 | 1].xor_val;
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, a[l]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int idx, int v)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].xor_val = v;
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (idx <= mid)
            modify(u << 1, idx, v);
        else
            modify(u << 1 | 1, idx, v);
        pushup(u);
    }
}

ll query(int u, int l, int r)
{
    if (l <= tr[u].l && r >= tr[u].r)
        return tr[u].xor_val;
    ll v = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        v ^= query(u << 1, l, r);
    if (r > mid)
        v ^= query(u << 1 | 1, l, r);
    return v;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, q, x, y;
    cin >> t;
    for (ll z = 1; z <= t; ++z)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        build(1, 1, n);

        int op;
        string s;
        while (q--)
        {
            cin >> op >> x >> y;

            if (op == 1)
                modify(1, x, y);
            else
            {
                cout << query(1, x, y) << ' ';
                if (query(1, x, y) != 0)
                    cout << "lonely" << '\n';
                else
                    cout << "happy" << '\n';
            }
        }
    }
    return 0;
}
