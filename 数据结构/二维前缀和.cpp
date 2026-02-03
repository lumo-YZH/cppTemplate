/*s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
ll a[1001][1001];
ll s[1001][1001];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k, m, x1, y1, x2, y2;
	cin >> n >> m >> k;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
	}
	while (k--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}
