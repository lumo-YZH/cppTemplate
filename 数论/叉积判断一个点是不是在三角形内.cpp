#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
db pd(db x1,db y1,db x2,db y2,db x,db y)
{
	return (x2-x1)*(y-y1)-(y2-y1)*(x-x1);
}
db ans(db x1,db y1,db x2,db y2,db x3,db y3,db x,db y)
{
	if(pd(x1,y1,x3,y3,x2,y2)<0)
	{
		swap(x2,x3);
		swap(y2,y3);
	}
	if(pd(x1,y1,x2,y2,x,y)<=0&&pd(x2,y2,x3,y3,x,y)<=0&&pd(x3,y3,x1,y1,x,y)<=0)
		return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t,x1,y1,x2,y2,x3,y3,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x>>y;
		if(ans(x1,y1,x2,y2,x3,y3,x,y))
			cout<<"Yes"<<'\n';
		else
			cout<<"No"<<'\n';
	}
	return 0;
}

