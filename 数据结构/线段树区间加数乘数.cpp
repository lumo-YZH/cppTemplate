#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int mod = 1e9+7;
const int N = 1e5+5,M = 2e5+5;

int n,m,p=1e18;
int a[N];

struct node
{
	int l,r;
	ll sum,add,mul;
}tr[4*N];

void pushup(int u)
{
	tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum) % p;
}
//懒标记下传
void pushdown(int u)
{
	auto &root = tr[u],&left = tr[u<<1],&right = tr[u<<1|1];
	left.add = (left.add*root.mul+root.add)%p;
	left.mul = (left.mul*root.mul)%p;
	left.sum = (left.sum*root.mul+(left.r-left.l+1)*root.add)%p;
	
	right.add = (right.add*root.mul+root.add)%p;
	right.mul = (right.mul*root.mul)%p;
	right.sum = (right.sum*root.mul+(right.r-right.l+1)*root.add)%p;
	root.add = 0;
	root.mul = 1;
}

void build(int u,int l,int r)
{
	tr[u] = {l,r};
	tr[u].mul = 1;
	if(l==r) 
	{
		tr[u].sum = a[l]%p;
		return;
	}
	int mid = l + r >> 1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);//更新
}

int query(int u,int l,int r)
{
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	//访问到当前节点先懒标记下传
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	ll s = 0;
	if(l<=mid) s = (s+query(u<<1,l,r))%p;
	if(r>mid) s = (s+query(u<<1|1,l,r))%p;
	return s;
}

void modify1(int u,int l,int r,int v)
{
	if(tr[u].l >= l && tr[u].r <= r) 
	{
		tr[u].sum = (tr[u].sum+(tr[u].r-tr[u].l+1)*v)%p;
		tr[u].add = (tr[u].add + v)%p;
	}
	else
	{
		//访问到当前节点下传懒标记
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify1(u<<1,l,r,v);
		if(r > mid) modify1(u<<1|1,l,r,v);
		//更新完值向上传递变化
		pushup(u);
	}
}
void modify2(int u,int l,int r,int v)
{
	if(tr[u].l >= l && tr[u].r <= r) 
	{
		tr[u].add = (tr[u].add*v)%p;
		tr[u].sum = (tr[u].sum*v)%p;
		tr[u].mul = (tr[u].mul*v)%p;
	}
	else
	{
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify2(u<<1,l,r,v);
		if(r > mid) modify2(u<<1|1,l,r,v);
		pushup(u);
	}
}
void solve()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int x,y,k,f;
		cin>>f>>x>>y;
		if(f==3) cout<<query(1,x,y)<<'\n';
		else
		{
			cin>>k;
			if(f==1) modify2(1,x,y,k);
			else modify1(1,x,y,k);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;
//	cin>>_;
	_ = 1;
	while(_--)
	{
		solve();
	}
	return 0;
}
