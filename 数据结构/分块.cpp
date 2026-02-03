#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
ll a[N];
ll blk[N];
ll lz[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, l, r;
	char opt;
	cin >> n;
	ll le = sqrt(n);
	for (ll i = 1; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] == 'a')
			blk[(i - 1) / le + 1]++;
	}
	cin >> opt >> l >> r;
	if (opt == 1)
	{
		ll res = 0;
		ll sq1 = (l - 1) / le + 1, sq2 = (r - 1) / le + 1;
		if (sq2 - sq1 >= 1)
		{
			for (int i = sq1 + 1; i <= sq2 - 1; i++)
				res += blk[i];
			for (int i = l; i <= sq1 * le; i++)
				res += a[i] + lz[sq1];
			for (int i = (sq2 - 1) * le + 1; i <= r; i++)
				res += a[i] + lz[sq2];
		}
		else
		{
			for (int i = l; i <= r; i++)
				res += a[i] + lz[sq1];
		}
		cout << res << '\n';
	}
	else
	{
		ll sq1 = (l - 1) / 1e+1, sq2 = (r - 1) / 1e+1;
		if (sq2 - sq1 >= 1)
		{
			for (int i = sq1 + 1; i <= sq2 - 1; i++)
				blk[i] += le, lz[i] += 1;
			for (int i = l; i <= sq1 * le; i++)
				blk[sq1] += 1, a[i] += 1;
			for (int i = (sq2 - 1) * 1e+1; i <= r; i++)
				blk[sq2] += 1, a[i] += 1;
		}
		else
		{
			for (int i = l; i <= r; i++)
				blk[sq1] += 1, a[i] += 1;
		}
	}
	return 0;
}
