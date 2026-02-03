#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define ls node<<1
#define rs node<<1|1
#define LL long long
using namespace std;
const int maxx=1e5+10;
int read(){
	char x=getchar(); int u=0,fg=0;
	while(!isdigit(x)){ if(x=='-') fg=1; x=getchar(); }
	while(isdigit(x)){ u=(u<<3)+(u<<1)+(x^48); x=getchar(); }
	return fg?-u:u;
}
struct segment{
	int l,r,h;
	bool up;
	bool operator <(const segment tmp)const{
		return h<tmp.h;
	}
}s[maxx<<1];
int tr[maxx<<2],lazy[maxx<<2]; 
int n,cnt,L,R;
void tag(int node,int l,int r,bool add){
	if(add){
		++lazy[node];
		++tr[node];
	}
	else{
		--lazy[node];
		--tr[node];
	}
}
void push_up(int node){
	tr[node]=min(tr[ls],tr[rs]);
}
void push_down(int node,int l,int r,int mid){
	if(!lazy[node]) return;
	int x=lazy[node];
	lazy[ls]+=x;
	lazy[rs]+=x;
	tr[ls]+=x;
	tr[rs]+=x;
	lazy[node]=0;
}
void update(int node,int l,int r,int x,int y,bool add){
	if(x<=l && y>=r){
		tag(node,l,r,add);
		return ;
	}
	if(l>=r) return ;
	int mid=(l+r)>>1;
	push_down(node,l,r,mid);
	if(mid>=y) update(ls,l,mid,x,y,add);
	else if(x>mid) update(rs,mid+1,r,x,y,add);
	else {
		update(ls,l,mid,x,mid,add);
		update(rs,mid+1,r,mid+1,y,add);
	}
	push_up(node);
}
LL query(int node,int l,int r){
	if(tr[node]) return r-l+1;
	if(l>=r) return 0;
	int mid=(l+r)>>1;
	push_down(node,l,r,mid);
	return query(ls,l,mid)+query(rs,mid+1,r);
}
int main(){
	int a,b,c,d;
	LL ans,len,high,t;
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0; L=maxx; R=-maxx;
		if(!n) break;
		while(n--){
			cin>>a>>b>>c>>d;
			a++;
			if(a>c) swap(a,c);		//原题数据有点问题，这里进行些处理
			if(b>d) swap(b,d);
			s[cnt].l=s[cnt|1].l=a;
			s[cnt].h=b;
			s[cnt].r=s[cnt|1].r=c;
			s[cnt|1].h=d;
			s[cnt].up=1;
			s[cnt|1].up=0;
			L=min(L,a);
			R=max(R,c);
			cnt+=2;
		}
		sort(s,s+cnt);
		update(1,L,R,s[0].l,s[0].r,s[0].up);
		len=query(1,L,R); ans=0;
		For(i,1,cnt-1){
			high=s[i].h-s[i-1].h;
			if(high) ans+=len*high;
			update(1,L,R,s[i].l,s[i].r,s[i].up);
			len=query(1,L,R);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

