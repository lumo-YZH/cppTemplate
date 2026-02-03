#include<iostream>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
ll a[N],b[N],f[1005][1005];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t, n,m;
	t = 1;
	//cin>>t;
	while (t--)
	{
		cin >> n >> m;
		for (ll i = 1; i <= n; i++)
			cin >> a[i];
		for (ll j = 1; j <= m; j++)
			cin >> b[j];
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= m; j++)
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
					if (a[i] == b[j])
						f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
		}
		cout << f[n][m];
	}
	return 0;
}


