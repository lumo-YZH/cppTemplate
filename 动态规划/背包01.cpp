#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll p = 1e3 + 5;
ll v[p];
ll w[p];
ll dp[p][102];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, vv, t, k;
	t = 1;
	while (t--)
	{
		cin >> n >> vv;
		for (ll i = 1; i <= n; ++i)
			cin >> k >> v[i] >> w[i];
		for (ll i = 1; i <= n; ++i)
		{
			for (ll j = 0; j <= vv; ++j)
			{
				if (j < v[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
			}
		}
		cout << dp[n][vv] << '\n';
		// for(ll i=1;i<=n;i++)//滚动数组优化
		// {
		//     for (ll j = vv; j >= v[i];j--)//逆序遍历,f[j]先于f[j-v[i]]更新
		//         f[j] = max(f[j], f[j - v[i]] + w[i]);
		// }
		// cout << f[vv] << '\n';
	}
	return 0;
}