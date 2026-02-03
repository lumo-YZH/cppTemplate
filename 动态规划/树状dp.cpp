// 公司有n个员工可以参加舞会，除了CEO每位员工有一位直属上司，
// 如果某员工的直属上司参加舞会，他就不会参加，每位员工
// 参加舞会会带来a[i]的快乐值，求其最大值。
// 5  员工数
// 1 2 3 1 第i个员工的上司
// 1 8 10 8 2  a[i]

// 18
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
struct node 
{
    ll where;
    struct node *next;
}*head[N],b[N];//head存放每个团体的头结点，b数组存每个结点
ll l,x,k,dp[N][2],a[N];//dp[i][0]代表第i个结点没有去，dp[i][0]代表去了

void makelist(ll x,ll y)
{
    b[++l].where=y;
    b[l].next=head[x];
    head[x]=&b[l];
}

void dfs(ll i)
{
    dp[i][1]=a[i];
    for(node *x= head[i];x;x=x->next)
    {
        dfs(x->where);
        dp[i][0]+=max(dp[x->where][0],dp[x->where][1]);
        dp[i][1]+=dp[x->where][0];
    }
}

int main()
{
   ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   ll t,n;
   t=1;
   //cin>>t;
   while(t--)
   {
       memset(dp,0,sizeof(dp));
       l=0;
       cin>>n;
       for(ll i=2;i<=n;i++)
       {
            cin>>k;
            makelist(k,i);
       }
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        dfs(1);
        cout<<max(dp[1][0],dp[1][1]);
   }
}