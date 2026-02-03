#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
ll a[N], b[N];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t, n;
	cin >> t;
	while (t--)
	{
		db sum = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n;
		for (ll i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		for (ll i = 0; i <= n - 1; i++)
			sum += (a[i] * b[i + 1] - a[i + 1] * b[i]);
		sum += (a[n - 1] * b[0] - b[n - 1] * a[0]);
		db ans = 0.5 * fabs(sum);
		cout << fixed << setprecision(0) << ans << '\n';
	}
	return 0;
}
