#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t,a1,a2,b1,b2,x,y;
	cin>>t;
	while(t--)
	{
		cin>>a1>>b1>>a2>>b2>>x>>y;
		if(((a1-x)*(b2-y)-(a2-x)*(b1-y)==0)&&((a1-x)*(a2-x)+(b1-y)*(b2-y)<=0))
			cout<<"Yes"<<'\n';
		else
			cout<<"No"<<'\n';
		
	}
	return 0;
}

