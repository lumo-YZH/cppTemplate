#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll n,m,sz;
ll color[N]; 
ll ans[N];
ll cnt[N];
ll sum;
struct node
{
	ll l,r,t,id;
}qq[N],qr[N];
void add(ll k)
{
	if(cnt[k]==0)
    {
		sum++;
	}
	cnt[k]++;
}
void del(ll k)
{
	cnt[k]--;
	if(cnt[k]==0)
		sum--;
}
void upd(ll x,ll y)
{
	if(qq[x].l<=qr[y].l&&qq[x].r>=qr[y].l)
    {
		add(qr[y].r);
		del(color[qr[y].l]);
	}
	swap(qr[y].r,color[qr[y].l]);
}
bool cmp(node a,node b)
{
	if(a.l/sz==b.l/sz)
    {
		if(a.r/sz==b.r/sz)
        {
			return a.t/sz<b.t/sz;
		}
		return a.r/sz<b.r/sz;
	}
	return a.l/sz<b.l/sz;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n)
    {
        sz=pow(n,2.0/3.0);
        sum=0;
        ll cntq=0;
        ll cntr=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>color[i];
            cnt[i]=0;
        }
        cin>>m;
        for(ll i=1;i<=m;i++)
        {
            ll a;
            ll l,r;
            cin>>l>>r;
            // if(a==1)
            // {
                cntq++;
                qq[cntq].l=l;
                qq[cntq].r=r;
                qq[cntq].id=cntq;
                qq[cntq].t=cntr;
            // }
            // else
            // {
            //     cntr++;
            //     qr[cntr].l=l;
            //     qr[cntr].r=r;
            // }
        }
        sort(qq+1,qq+1+cntq,cmp);
        ll curl=1,curr=0,curt=0;
        for(ll i=1;i<=cntq;i++)
        {
            ll l,r,t;
            l=qq[i].l;
            r=qq[i].r;
            t=qq[i].t;
            while(curl>l)
                add(color[--curl]);
            
            while(curl<l)
                del(color[curl++]);
            
            while(curr<r)
                add(color[++curr]);
            
            while(curr>r)
                del(color[curr--]);
            
            while(curt<t)
                upd(i,++curt);
            
            while(curt>t)
                upd(i,curt--);
            
            ans[qq[i].id]=sum;
        }
        for(ll i=1;i<=cntq;i++)
            cout<<ans[i]<<"\n";
    }
}