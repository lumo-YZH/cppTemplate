#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const ll N=1e3+10;
const ll mod=1e9+7;
ll n,m,s,t;
map<ll,ll>g[N];
ll dep[N];
bool bfs(){
    memset(dep,0,sizeof(dep));
    queue<ll> q;
    dep[s]=1;
    q.push(s);
    while(!q.empty()){
        ll u=q.front();
        for(auto it:g[u]){
            if(it.second>0&&dep[it.first]==0){
            //如果这条边没有被打断 && 这个点没有被搜索过
                dep[it.first]=dep[u]+1;
                q.push(it.first);
            }
        }
        q.pop();
    }
    return (dep[t]!=0); //判断图是否联通
}
ll dfs(ll x,ll flow){ //flow:当前路径的流量
    if(x==t){
        return flow;
    }
    for(auto it:g[x]){
        if(it.second>0&&dep[it.first]==dep[x]+1){
            ll d=dfs(it.first,min(flow,it.second));
            //计算这条路径上的最大流
            if(d>0){
                g[x][it.first]-=d; //正边
                if(g[x][it.first]==0)
                    g[x].erase(it.first);
                g[it.first][x]+=d; //反边
                return d;
            }
        }
    }
    return 0;
}
ll dinic(){
    ll ans=0;
    while(bfs()){ //图是联通的(有可行路径)
        ll x=1;
        while(x){
            x=dfs(s,LLINF);
            //搜索所有的可行路径并计算出其最大流，假设初始流量为无限大
            ans+=x;
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    s=1,t=m;
    for(ll i=1;i<=n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x][y]+=z;
    }
    cout<<dinic()<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T=1;   
    // cin>>T;
    while(T--) solve();
    return 0;
}