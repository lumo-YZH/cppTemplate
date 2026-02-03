#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
typedef pair<ll,ll>PLL;
#define fi first
#define se second
ll a[N];
ll eular(ll x)//少于或等于N ([1,N]),且与N互质的正整数(包括1)的个数 
{
    ll res=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            res=res/i*(i-1);// eular(n)=n*(1-1/p1)*(1-1/p2)..
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)res=res/x*(x-1);
    return res;
}
void euler(int n)//o(sqrt(n))
{
    for (int i=1;i<=n;i++) p[i]=i;

    for (int i=2;i<=n;i++)
    {
        if (p[i]==i)//这代表i是质数
        {
            for (int j=i;j<=n;j+=i)
            {
                p[j]=p[j]/i*(i-1);
                //把i的倍数更新掉
                //因为该数 j 为质数的倍数 所以质因子只有该质数 i
                //通过 在 1 到 该质数 j 中， 去除所有 i 的倍数
                //所以p[j] - p[j]/i;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t,n;
    t=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<eular(n)<<'\n';
    }
}