#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}
int main()
{
    ll n,m;
    cin>>n>>m;
    cout<<gcd(n,m);
}
