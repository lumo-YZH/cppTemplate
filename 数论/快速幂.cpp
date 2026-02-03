#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
ll quickpow(ll a, ll b, ll md)
{
	a %= md;
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % md;
		b >>= 1;
		a = (a * a) % md;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;
		cout << quickpow(a, b, 1000) << '\n';
	}
	return 0;
}
