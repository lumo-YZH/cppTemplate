#include<bits/stdc++.h>
#define MAXN 100010
#define EXP 20//32
const int INF=0x3f3f3f3f;
using namespace std;


int root[MAXN],LSH[MAXN];
struct Tree{
    int tot;
    int L[MAXN*EXP],R[MAXN*EXP],SUM[MAXN*EXP];
    
    void init()
    {
        tot=0;
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        memset(SUM,0,sizeof(SUM));
    }
    
    int build(int l,int r)
    {
        int id=++tot;
        if(l<r)
        {
            int mid=(l+r)/2;
            L[id]=build(l,mid);
            R[id]=build(mid+1,r);
        }
        return id;
    }
    
    int update(int pre,int l,int r,int x)
    {
        int id=++tot;
        L[id]=L[pre];R[id]=R[pre];SUM[id]=SUM[pre]+1;
        if(l<r)
        {
            int mid=(l+r)/2;
            if(x<=mid) L[id]=update(L[pre],l,mid,x);
            else R[id]=update(R[pre],mid+1,r,x);
        }
        return id;
    }
    
    int Kth(int u,int v,int l,int r,int k)//求第k小的数的下标
    {
        if (l >= r) return l;
        int x = SUM[L[v]] - SUM[L[u]];
        int mid=(l+r)/2;
        if (x >= k) return Kth(L[u], L[v], l, mid, k);
        else return Kth(R[u], R[v], mid+1, r, k-x);
    }

      
    int lessOrEqualK(int u,int v,int l,int r,int k)//求小于等于k的有多少个
    {
        int mid = (l + r) / 2;
        int ans = 0;
        if (l == r) {
            return SUM[v] - SUM[u];
        }
        if (k <= mid) {
            ans += lessOrEqualK(L[u], L[v], l, mid, k);
        } else {
            ans += SUM[L[v]] - SUM[L[u]];//左区间的全部符合题意，直接加上
            ans += lessOrEqualK(R[u], R[v], mid + 1, r, k);
        }
        return ans;
    }
}tree;

int t,n,m,a[MAXN],l,r,k;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++){cin>>a[i];LSH[i]=a[i];}
        sort(LSH+1, LSH+1+n);
        int N = unique(LSH+1, LSH+1+n)-LSH-1;
        tree.init();

        root[0]=tree.build(1,N);
        for(int i=1;i<=n;i++)
        {
            int tmp = lower_bound(LSH+1, LSH+1+N, a[i])-LSH;
            root[i]=tree.update(root[i-1],1,N,tmp);
        }

        //查询[l,r]中小于等于k的元素的数量
        for(int i=1;i<=m;i++){
            cin>>l>>r>>k;
            int tmp = upper_bound(LSH+1, LSH+1+N, k)-LSH-1;//离散化
            int ans=tree.lessOrEqualK(root[l-1],root[r],1,N,tmp);
            if(tmp==0)ans=0;
            cout<<ans<<"\n";
        }

        // 查询[l,r]中第k小的值
        // for(int i=1;i<=m;i++){
        //     cin>>l>>r>>k;
        //     int ans=tree.ask(root[l-1],root[r],1,N,k);
        //     cout<<b[ans]<<"\n";
        // }
    }

    return 0;
}
