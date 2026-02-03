#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n,m,a[500005],tree[500005],x,u,v;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int k)//显然，x点对 x+lowbit(x) 有贡献，那么就可以递归下去直到 x 加到 x>n
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int ser(int x)//求sum 1~x
{
	int ans=0;
	while(x>0)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i],add(i,a[i]);
	for(int i=1;i<=m;i++)
	{
		cin>>x>>u>>v;
		if(x==1)
		{
			add(u,v);
		}
		else
		{
			cout<<ser(v)-ser(u-1)<<'\n';
		}
	}
}