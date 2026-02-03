#include<iostream>
#include<vector>
#define p_b push_back
using namespace std;
const int N=1e5+1;
int n,m,r,a[N],dfn[N],L[N<<2],R[N<<2];
long long md,s[N<<2],lzy[N<<2];
int fa[N],deep[N],siz[N],son[N],top[N];
vector<int>e[N],tl;
void dfs1(int x){
    deep[x]=deep[fa[x]]+1;
    siz[x]=1;
    for(int u:e[x]){
        if(u==fa[x])continue;
        fa[u]=x;
        dfs1(u);
        siz[x]+=siz[u];
        if(siz[u]>siz[son[x]])son[x]=u;//重儿子
    }
}
void dfs2(int x){
    dfn[x]=tl.size();
    tl.p_b(x);
    if(son[x]){
        top[son[x]]=top[x];
        dfs2(son[x]);
        for(int u:e[x]){
            if(u==fa[x]||u==son[x])continue;
            top[u]=u;//轻节点起点
            dfs2(u);
        }
    }
}
void pushup(int u){
    s[u]=(s[u<<1]+s[u<<1|1])%md;
}
void build(int u,int l,int r){
    L[u]=l,R[u]=r;
    if(l==r)s[u]=a[tl[l]];
    else{
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void maketag(int u,long long x){
    (lzy[u]+=x)%=md;
    (s[u]+=x*(R[u]-L[u]+1))%=md;
}
void pushdown(int u){
    if(lzy[u]){
        maketag(u<<1,lzy[u]);
        maketag(u<<1|1,lzy[u]);
        lzy[u]=0;
    }
}
void update(int u,int l,int r,long long x){
    if(l<=L[u]&&R[u]<=r)maketag(u,x);
    else if(L[u]<=r&&l<=R[u]){
        pushdown(u);
        update(u<<1,l,r,x);
        update(u<<1|1,l,r,x);
        pushup(u);
    }
}
long long query(int u,int l,int r){
    if(l<=L[u]&&R[u]<=r)return s[u]%md;
    if(L[u]>r||R[u]<l)return 0;
    pushdown(u);
    return (query(u<<1,l,r)+query(u<<1|1,l,r))%md;
}
long long lca(int x,int y)
{
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return deep[x]<deep[y]?x:y;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>r>>md;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].p_b(v),e[v].p_b(u);
    }
    dfs1(r);
    tl.p_b(0);//dfs序
    top[r]=r;
    dfs2(r);
    build(1,1,n);
    for(short opt;m--;){
        cin>>opt;
        if(opt==1){//顶点x到y的最短路径权值加z
            int x,y,z;
            cin>>x>>y>>z;
            z%=md;
            while(top[x]!=top[y]){
                if(deep[top[x]]<deep[top[y]])swap(x,y);
                update(1,dfn[top[x]],dfn[x],z);
                x=fa[top[x]];
            }
            if(deep[x]>deep[y])swap(x,y);
            update(1,dfn[x],dfn[y],z);
        }
        else if(opt==2){//顶点x到y的最短路径权值之和
            int x,y;
            cin>>x>>y;
            long long ans=0;
            while(top[x]!=top[y]){
                if(deep[top[x]]<deep[top[y]])swap(x,y);
                (ans+=query(1,dfn[top[x]],dfn[x]))%=md;
                x=fa[top[x]];
            }
            if(deep[x]>deep[y])swap(x,y);
            cout<<(ans+query(1,dfn[x],dfn[y]))%md<<'\n';
        }
        else if(opt==3){// 顶点x及其子树权值都加z
            int x,z;
            cin>>x>>z;
            z%=md;
            update(1,dfn[x],dfn[x]+siz[x]-1,z);
        }
        else if(opt==4){// 顶点x及其子树权值之和
            int x;
            cin>>x;
            cout<<query(1,dfn[x],dfn[x]+siz[x]-1)%md<<'\n';
        }
    }
    return 0;
}