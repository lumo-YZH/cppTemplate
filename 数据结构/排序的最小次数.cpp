#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
ll f(vector<ll> a)
{
    vector<ll>tmp=a;
    map<ll,ll>mp;
    ll ans=0;
    sort(tmp.begin(),tmp.end());
    for(ll i=0; i<tmp.size(); i++)
        mp[tmp[i]]=i;
    for(ll i=0; i<a.size(); i++)
        while(i!=mp[a[i]])
        {
            ans++;
            swap(a[i],a[mp[a[i]]]);
        }
    return ans;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,k;
	vector<ll>a;
	while(cin>>n)
	{
		a.clear();
		for(ll i=1;i<=n;i++)
		{
			cin>>k;
			a.push_back(k);
		}
		cout<<f(a)<<'\n';
	}
	return 0;
}
