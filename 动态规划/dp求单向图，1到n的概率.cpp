#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
db f[1005];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t, n,m;
	t = 1;
	//cin>>t;
	while (t--)
	{
		cin >> n >> m;
		vector<ll>c[1005];
		for (ll i = 1; i <= m; i++)
		{
			ll x, y;
			cin >> x >> y;
			c[x].push_back(y);
		}
		memset(f, 0, sizeof(f));
		f[1] = 1;
		for (ll i = 1; i < n; i++)
		{
			ll k = c[i].size();
			for (ll j = 0; j <k; j++)
			{
				f[c[i][j]] += f[i] / k;
			}
		}
		cout << setprecision(10) << fixed << f[n] <<'\n';
	}
	return 0;
}


