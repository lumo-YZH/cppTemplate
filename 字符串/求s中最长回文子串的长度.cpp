#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
ll sublen(string s)
{
	if(s.size()<2)
		return s.size();
	ll max=1;
	for(ll i=0;i<s.size();i++)
	{
		for(ll j=s.size()-1;j>i;j--)
		{
			ll m=i;
			ll n=j;
			while(s[m]==s[n])
			{
				if(m>=n)
					break;
				else
				{
					m++;
					n--;
				}
			}
			if(m>=n&&n>=0&&max<j-i+1)
			{
				max=j-i+1;
				break;
			}
		}
		if(max==s.size())
			break;
	}
	return max;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	cout<<sublen(s);
	return 0;
}
