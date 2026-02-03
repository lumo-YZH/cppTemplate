#include <bits/stdc++.h>
#define M 2005
using namespace std;
int dp[M][M];
int v[M], w[M];
int n, m; // m储存容量，n储存数量
int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (j < v[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
		}
	}
	cout << dp[n][m];
	// for(ll i=1;i<=n;i++)
	// {
	// 	for (ll j = v[i]; j <= m;j++)//前往后更新,更新来自同行前面与上一行
	// 	{
	// 		f[j] = max(f[j], f[j - v[i]] + w[i]);
	// 	}
	// }
	// cout << f[m] << '\n';
	return 0;
}
