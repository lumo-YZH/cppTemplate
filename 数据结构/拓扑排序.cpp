#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll n,m,ans[1001];
ll d[1001];
vector<ll> b[1001];
set<ll> st;
void toposort()
{
    ll num=0;
    for(ll i=1;i<=n;i++)
        if(d[i]==0)
            st.insert(i);
    while(!st.empty())
    {
        ll now=*st.begin();
        st.erase(st.begin());
        ans[++num]=now;
        for(auto f : b[now])
        {
            --d[f];
            if(!d[f])
                st.insert(f);
        }    
    } 
    for(ll i=1;i<num;i++)
        cout<<ans[i]<<' ';
    cout<<ans[num]<<'\n';           
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n>>m)
    {
        for(ll i=1;i<=n;i++)
        {
            b[i].clear();  
            d[i]=0;  
        }
    
        for(ll i=1;i<=m;i++)
        {
            ll u,v;
            cin>>u>>v;
            d[v]++;
            b[u].push_back(v);
        }
        toposort();
    }
    return 0;
}