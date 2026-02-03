#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const ll N = 1e6 + 5;
typedef pair<ll, ll>PLL;
struct node
{
	node *next;
	ll where;
}*first[100001],a[200001];
ll n, l, size[100001];
ll f[100001], v[100001];
bool b[100001];
void makelist(ll x, ll y)
{
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}
inline void up(ll i)
{
	size[i] = 1;
	b[i] = true;
	for (node *x = first[i]; x;  x = x->next)
	{
		if (!b[x->where])
		{
			up[x->where];
			size[i] += size[x->where];
			f[i] += f[x->where];
		}
	}
	f[i] += size[i] - 1;
}
inline void down(ll  i)
{
	b[i] = true;
	for (node *x = first[i]; x; x = x->next)
	{
		if (!b[x->where])
		{
			v[x->where] = v[i] + f[i] - f[x->where] - size[x->where] + n - size[x->where];
			down(x->where);
		}
	}
}
int main()
{
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(first, 0, sizeof(first));
	l = 0;
	cin >> n;
	for (ll i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		makelist(x, y);
		makelist(y, x);
	}
	memset(b, false, sizeof(b));
	up(1);
	memset(b, false, sizeof(b));
	down(1);
	for (ll i = 1; i <= n; i++)
	{
		cout << f[i] + v[i] <<'\n';
	}
}
