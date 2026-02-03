ll C(ll n, ll m)
{
	if (m > n)
		return 0;
	ll res = 0;
	res = jc[n] * jcn[n - m] % md * jcn[m] % md;
	return res;
}
init()
{
	jc[0] = 1, jcn[0] = 1, inv[1] = 1;
	for (ll i = 1; i < min(N, md); i++)
	{
		if (i >= 2)
			inv[i] = 1ll * (md - md / i) * inv[md % i] % md;
		jc[i] = (jc[i - 1] * i) % md;
		jcn[i] = inv[i] * jcn[i - 1] % md;
	}
}
ll lucas(ll n, ll m, ll p) //(n,m)=(n/p,m/p)*(n%p,m%p),O(plogp+logp(n));
{
	if (m == 0)
		return 1;
	return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}