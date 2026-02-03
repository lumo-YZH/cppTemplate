#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e6+5;
const ll mod = 1e9+7;
typedef pair<ll,ll>PLL;
#define N 50010
#define INF 1000000000
#define rg register
struct Node
{
       ll x,y;
}p[N],p0,S[N];
ll n,top,T;
bool cmp(Node a,Node b)
{
       rg double A=atan2(a.y-p0.y,a.x-p0.x);
       rg double B=atan2(b.y-p0.y,b.x-p0.x);
       if(A!=B)return A<B;
       else    return a.x<b.x;
}
ll chaji(ll x1,ll y1,ll x2,ll y2)//计算叉积 
{
       return (1LL*x1*y2-1LL*x2*y1);
}
ll Compare(Node a,Node b,Node c)//计算向量 
{
       return chaji((b.x-a.x),(b.y-a.y),(c.x-a.x),(c.y-a.y));
}
void Find()//寻找凸包 
{
       p0=(Node){INF,INF};
       rg ll k=0;
       for(rg ll i=0;i<n;++i)//找到最下方的点 
            if(p0.y>p[i].y||(p0.y==p[i].y&&p0.x>p[i].x))
                p0=p[i],k=i;
       swap(p[k],p[0]);
       sort(&p[1],&p[n],cmp);//关于最下方的点排序 
       S[0]=p[0];S[1]=p[1];
       top=1;//栈顶 
       for(rg ll i=2;i<n;)//求出凸包 
       {
             if(top&&Compare(S[top-1],p[i],S[top])>=0) top--;
             else   S[++top]=p[i++];  
       }
}
ll Dis(Node a,Node b)//计算两点的距离的平方和 
{
       return 1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y);
}
ll GetMax()//求出直径 
{
       rg ll re=0;
       if(top==1)//仅有两个点
          return Dis(S[0],S[1]); 
       S[++top]=S[0];//把第一个点放到最后
       ll j=2;
       for(ll i=0;i<top;++i)//枚举边 
       {
              while(Compare(S[i],S[i+1],S[j])<Compare(S[i],S[i+1],S[j+1]))
                  j=(j+1)%top;
              re=max(re,max(Dis(S[i],S[j]),Dis(S[i+1],S[j])));
       }
       return re;

}
int main()
{    
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n)
    {
       for(ll i=0;i<n;++i)
            cin>>p[i].x>>p[i].y;
       ll ans=INF;
       Find();
       ans=GetMax();
       cout<<ans<<'\n';
    }
}

