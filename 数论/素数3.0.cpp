#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
const ll q = 1e9;
ll prime[q];
bool isprime[q + 1];
ll p = 0;
ll sieve(ll n)
{
	p = 0;
	for (ll i = 0; i <= n; i++)
		isprime[i] = true;
	isprime[0] = isprime[1] = false;
	for (ll i = 2; i <= n; i++)
	{
		if (isprime[i])
		{
			prime[p++] = i;
			for (ll j = i * i; j <= n; j += i)
				isprime[j] = false;
		}
	}
	return p;
}
ll a[100001];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, ans;
	while (cin >> n)
	{
		dbg(n);
	}
	return 0;
}
