#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
const ll mod = 1e9+7;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
#define il inline
#define mem(p) memset(&p, 0, sizeof(p))
ll n, m, t,k;
struct mat
{
    ll a[20][20], r, c;
};
il mat mul(mat x, mat y)
{
    mat p;
    mem(p);
    for (int i = 0; i < x.r; i++)
        for (int j = 0; j < y.c; j++)
            for (int k = 0; k < x.c; k++)
                p.a[i][j] = (p.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
    p.r = x.r, p.c = y.c;
    return p;
}
mat p, ans;
il void fast(ll k)//p^k*ans
{
    mem(ans),mem(p);
    p.r = p.c = 4;
    ans.r = 4, ans.c = 1;
    ans.a[0][0]=36;
    ans.a[1][0]=11;
    ans.a[2][0]=5;
    ans.a[3][0]=1;
    // 1 5 1 -1
    // 1 0 0 0
    // 0 1 0 0
    // 0 0 1 0
    p.a[0][0]=p.a[0][2]=p.a[1][0]=p.a[2][1]=p.a[3][2]=1;
    p.a[0][1]=5,p.a[0][3]=-1;
    while (k)
    {
        if (k & 1)
            ans = mul(p,ans);
        p = mul(p, p);
        k >>= 1;
    }
    cout << (ans.a[0][0]+mod)%mod << '\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while (cin>>n)
    {
        
        if(n==1)
            cout<<1<<'\n';
        else if(n==2)
            cout<<5<<'\n';
        else if(n==3)
            cout<<11<<'\n';
        else if(n==4)
            cout<<36<<'\n';
        else
            fast(n-4);
    }
    return 0;
}