#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e5 + 5;
typedef pair<ll, ll> PLL;
#define fi first
#define se second
ll n, m, k, p, f, ff = 0, l, r, x, y, q, u, cnt, ma;
const int maxn = 100010;
int a[maxn + 2], s[maxn + 2];
struct tee
{
	ll l, r;
	ll suma, sums, add;
} t[4 * maxn + 2];
void build(int p, int l, int r)
{
	t[p].l = l, t[p].r = r;
	if (l == r)
	{
		t[p].suma = a[l];
		t[p].sums = s[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].suma = (t[p << 1].suma + t[p << 1 | 1].suma);
	t[p].sums = (t[p << 1].sums + t[p << 1 | 1].sums);
}
void spread(int p)
{
	if (t[p].add)
	{
		t[p << 1].suma += t[p].add * t[p << 1].sums;
		t[p << 1 | 1].suma += t[p].add * t[p << 1 | 1].sums;
		t[p << 1].add += t[p].add;
		t[p << 1 | 1].add += t[p].add;
		t[p].add = 0;
	}
}
void change(int p, int x, int y)
{
	if (x == t[p].l && t[p].r == x)
	{
		t[p].sums = y;
		return;
	}
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid)
		change(p << 1, x, y);
	if (x > mid)
		change(p << 1 | 1, x, y);
	//t[p].suma = (t[p << 1].suma + t[p << 1 | 1].suma);
	t[p].sums = (t[p << 1].sums + t[p << 1 | 1].sums);
}
void adds(int p, int x, int y, int k)
{
	if (x <= t[p].l && t[p].r <= y)
	{
		t[p].suma = (t[p].suma + k * t[p].sums);
		t[p].add = (t[p].add + k);
		return;
	}
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid)
		adds(p << 1, x, y, k);
	if (y > mid)
		adds(p << 1 | 1, x, y, k);
	t[p].suma = (t[p << 1].suma + t[p << 1 | 1].suma);
	t[p].sums = (t[p << 1].sums + t[p << 1 | 1].sums);
}
ll ask(int p, int x, int y)
{
	ll ans = 0;
	if (x <= t[p].l && t[p].r <= y)
		return t[p].suma;
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid)
		ans = (ans + ask(p << 1, x, y));
	if (y > mid)
		ans = (ans + ask(p << 1 | 1, x, y));
	return ans;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	build(1, 1, n);
	while (q--)
	{
		cin >> k;
		if (k == 1)
		{
			cin >> x;
			//s[x] = 0;
			change(1, x, 0);
		}
		else if (k == 2)
		{
			cin >> x;
			//s[x] = 1;
			change(1, x, 1);
		}
		else if (k == 3)
		{
			cin >> l >> r >> x;
			adds(1, l, r, x);
		}
		else
		{
			cin >> l >> r;
			cout<<ask(1, l, r)<<"\n";
		}
	}
}