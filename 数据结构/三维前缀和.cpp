#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, t, x, y, m;
ll a[105][105][105] = {0};
ll s[105][105][105] = {0};
int main()
{
	ll i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				cin >> a[i][j][k];
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k <= n; k++)
			{
				s[i][j][k] = a[i][j][k] + s[i][j][k - 1] + s[i][j - 1][k] + s[i - 1][j][k] - s[i][j - 1][k - 1] - s[i - 1][j][k - 1] - s[i - 1][j - 1][k] + s[i - 1][j - 1][k - 1];
			}
		}
	}
	ll q;
	cin >> q;
	while (q--)
	{
		ll xl, yl, zl, xr, yr, zr, sum;
		cin >> xl >> xr >> yl >> yr >> zl >> zr;
		sum = s[xr][yr][zr] - s[xl - 1][yr][zr] - s[xr][yl - 1][zr] - s[xr][yr][zl - 1] + s[xr][yl - 1][zl - 1] + s[xl - 1][yr][zl - 1] + s[xl - 1][yl - 1][zr] - s[xl - 1][yl - 1][zl - 1];
		cout << sum << "\n";
	}
}
