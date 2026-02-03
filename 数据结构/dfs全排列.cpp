#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
ll n;
ll a[100];
ll b[100];
bool f[100];
void dfs(ll q)
{
		
	if(q==n+1)
	{
		cout<<a[1];
		for(ll i=2;i<=n;i++)
		{
			cout<<' '<<a[i];
		}
		cout<<'\n';
		return ;
	}
	for(ll i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			a[q]=b[i];
			f[i]=1;
			dfs(q+1);
			f[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll j=1;j<=n;j++)
		cin>>b[j];
	sort(b+1,b+n+1);
	dfs(1);
	return 0;
}
		// ll arr[] = {3,2,1};
        // cout<<"用prev_permutation对3 2 1的全排列"<<endl;
        // do
        // {
        //     cout << arr[0] << ' ' << arr[1] << ' ' << arr[2]<<'\n';
        // }
        // while ( prev_permutation(arr,arr+3) );
