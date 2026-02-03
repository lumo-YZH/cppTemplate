#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int INF=1e9;
const int MAXN=105;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b*x);
	return d;
}
void solve()
{
	ll a,b,c,x,y;
	scanf("%lld%lld%lld",&a,&b,&c);
	ll d=exgcd(a,b,x,y);
	if(c%d!=0)//不符合裴蜀定理，说明无整数解 
	{
		printf("-1\n");
		return ;
	}
	else
	{
		x=x*c/d;
		y=y*c/d;
		ll minx=(x%(b/d)+(b/d))%(b/d);//固定的取最小正整数解的方法，加了一次(b/d)是防止x为负数
		if(minx==0)
			minx+=b/d;//防止为0 
		ll miny=(y%(a/d)+(a/d))%(a/d);
		if(miny==0)
			miny+=a/d;//求y的最小正整数解的方法与求x相同
		ll maxx=(c-b*miny)/a;//将不定方程移下项就可以得到了。并且当x取最小值时，y取最大值，反之亦然
		ll maxy=(c-a*minx)/b;
		if(maxx<=0 || maxy<=0)//最大值小于等于0，说明无正整数解 
		{
			printf("%lld %lld\n",minx,miny);
			return ;
		} 
		int num=(maxx-minx)/(b/d)+1;//求出解的数量
		printf("%lld %lld %lld %lld %lld\n",num,minx,miny,maxx,maxy); 
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}