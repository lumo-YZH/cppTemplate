#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll n, m;          
ll w[N],a[N];
struct Node{
    ll l, r;
    ll sum, d;
}tr[4 * N];

ll gcd(ll a, ll b) 
{
    return b ? gcd(b, a % b) : a;
}

void pushup(Node &u, Node &l, Node &r)  
{
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(ll u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(ll u, ll l, ll r)         
{
    tr[u].l = l, tr[u].r = r;
    if ( l == r ) 
        tr[u].d = w[l] - w[l - 1], tr[u].sum = w[l] - w[l - 1];
    else
    {
        ll mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(ll u, ll x, ll v)        
{
    if ( tr[u]. r == x && tr[u].l == x ) 
        tr[u].d = tr[u].sum + v, tr[u].sum += v;    
    else
    {
        ll mid = tr[u].l + tr[u].r >> 1;
        if ( mid >= x ) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(ll u, ll l, ll r)
{
    if ( tr[u].l >= l && tr[u].r <= r ) return tr[u];
    else
    {
        ll mid = tr[u].l + tr[u].r >> 1;
        if ( mid >= r ) return query(u << 1, l, r);
        else if ( mid < l ) return query(u << 1 | 1, l, r);
        else
        {
            Node left = query(u << 1, l, r);       
            Node right = query(u << 1 | 1, l, r);   
            Node res;                             
            pushup(res, left, right);               
            return res;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    ll d;
    a[1]=1;a[2]=1;

    for(ll i=3;i<=85;i++)
     a[i]=a[i-1]+a[i-2];
    while(t--)
    {
        cin >> n ;
        for ( ll i = 1; i <= n; i ++ ) 
        {
            cin>>w[i];
            w[i]=a[w[i]];
        }
        build(1, 1, n);
        ll l, r;
        cin>>m;
        while ( m -- )
        {
            cin>>l>>r;
            Node left = query(1, 1, l);               
            Node right = {0, 0, 0, 0};                
            if ( l + 1 <= r ) right = query(1, l + 1, r);   
            cout<<abs(gcd(left.sum, right.d))<<'\n';  
            
        }
    }
    return 0;
}
