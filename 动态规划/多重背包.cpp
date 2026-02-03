#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e3 + 5;
ll dp[N][100];
ll v[N];
ll w[N];
ll k[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t, n, vv;
	t = 1;
	while (t--)
	{
		cin >> n >> vv;
		for (ll i = 1; i <= n; ++i)
			cin >> k[i] >> v[i] >> w[i];
		for (ll i = 1; i <= n; ++i) // O(vv*sigma(k[i]))
		{
			for (ll j = 0; j <= vv; ++j)
			{
				for (ll s = 0; s <= k[i] && j >= s * v[i]; ++s)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - s * v[i]] + s * w[i]);
			}
		}
		cout << dp[n][vv] << '\n';
		for (ll i = 1; i <= n; i++) // O(vv*sigma(k[i]))
		{
			for (ll j = vv; j >= v[i]; j--) // 滚动数组
			{
				for (ll s = 0; s <= k[i] && s * v[i] <= j; s++) // 多个01背包
					f[j] = max(f[j], f[j - s * v[i]] + k * w[i]);
			}
		}

		// int num = 1;//二进制优化O(m*sigma(log(s)))
		// for (ll i = 1; i <= n; i++)
		// {
		// 	cin >> v >> w >> s;
		// 	for (ll j = 1; j <= s; j <<= 1)
		// 	{
		// 		vv[num] = j * v;
		// 		ww[num++] = j * w;
		// 		s -= j;
		// 	}
		// 	if (s)
		// 	{
		// 		vv[num] = s * v;
		// 		ww[num++] = s * w;
		// 	}
		// }
		// for (ll i = 1; i < num; i++)
		// {
		// 	for (ll j = m; j >= vv[i]; j--)
		// 		f[j] = max(f[j], f[j - vv[i]] + ww[i]);
		// }
		// cout << f[m];
	}
	return 0;
}
