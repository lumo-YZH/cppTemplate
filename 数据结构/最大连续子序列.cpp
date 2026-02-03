#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll a[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,n;
    t=1;
    while(1)
    {
        cin>>n;
        if(n==0)break;
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        ll ans=-1e18,l=1,r=1,x,y,sum=0;
        for(ll i=1;i<=n;i++)
        {
            if(sum<0)
            {
                sum=a[i];
                l=i;
            }
            else 
                sum+=a[i];
            if(sum>ans)
            {
                ans=sum;
                x=a[l],y=a[i];
            }
        }
        if(ans<0)
            cout<<0<<' '<<a[1]<<' '<<a[n]<<'\n';
        else 
            cout<<ans<<' '<<x<<' '<<y<<'\n';
    }
}