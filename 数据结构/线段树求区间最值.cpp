/*
缁炬寧顔岄弽鎴犳樊閹躲倕灏梻瀛樻付婢讹拷/鐏忓繐鈧厧姘ㄩ弰顖涘瘻閻撗冨斧閺夈儳绮伴崙铏规畱閺佺増宓侀惃鍕€庢惔蹇撶紦闁姳绔存０妞剧癌閸欏鐖查敍宀€鍔ч崥搴㈢槨娑撯偓娑擃亣濡悙鍦樊閹讹拷
鏉╂瑤閲滈懞鍌滃仯閻ㄥ嫬鐡欓懞鍌滃仯娑撴柨瀵橀崥顐ョ箹娑擃亣濡悙鍦畱閸婇棿鑵戦惃鍕付婢讹拷/鐏忓繐鈧拷
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int MAX_LEN =1000 ;
int seg_tree[MAX_LEN << 2];
int Lazy[MAX_LEN << 2];
int arr[MAX_LEN];
//娴犲簼绗呭鈧稉濠冩纯閺傦拷 閼哄倻鍋�
void push_up (int root) {
    seg_tree[root] = max(seg_tree[root << 1], seg_tree[root << 1 | 1]);      //閺堚偓鐏忓繐鈧吋鏁糾in
}
//娴犲簼绗傞崥鎴滅瑓閺囧瓨鏌婇敍灞戒箯閸欏啿顒㈢€涳拷
void push_down (int root, int L, int R) {
    if(Lazy[root]){
        Lazy[root << 1] += Lazy [root];
        Lazy[root << 1 | 1] += Lazy[root];
        int mid = (L + R) >> 1;
        seg_tree[root << 1] +=  Lazy[root] * (mid - L + 1);
        seg_tree[root << 1 | 1] += Lazy[root] * (R - mid);
        Lazy[root] = 0;
    }
}
//瀵ょ儤鐖�
//[L,R]鐏忚鲸妲哥€电懓绨瞐rr閺佹壆绮嶉柌宀勬桨閻ㄥ嫭鏆�
void build (int root, int L, int R) {
    Lazy[root] = 0;
    if(L == R) {
        seg_tree[root] = arr[L];
        return ;
    }
    int mid = (L + R) >> 1;
    build(root << 1, L, mid);
    build(root << 1 | 1, mid + 1, R);
    push_up(root);
}

//閸栨椽妫块弻銉嚄
//閺屻儲澹橀崠娲？[LL,RR]閻ㄥ嫭娓舵径锟�/鐏忓繐鈧拷
int query (int root, int L, int R, int LL, int RR) {
    if (LL <= L && R <= RR) return seg_tree[root];
    push_down(root, L, R);     //濮ｅ繑顐肩拋鍧楁６闁棄骞撳Λ鈧弻顧抋zy 閺嶅洩顔�
    int Ans = 0;
    int mid = (L + R) >> 1;
    if(LL <= mid) Ans = max(Ans, query(root << 1, L, mid, LL, RR));    //閺堚偓鐏忓繐鈧吋鏁糾in
    if(RR > mid) Ans = max(Ans, query(root << 1 | 1, mid + 1, R, LL, RR)); //閺堚偓鐏忓繐鈧吋鏁糾in
    return Ans;
}
//閸栨椽妫挎穱顔芥暭 +-閺屾劕鈧拷
//娴ｅ灝绶遍崠娲？[LL,RR]閻ㄥ嫬鈧ジ鍏橀崝鐘辩瑐val
void update_Interval(int root, int L, int R, int LL, int RR, int val){
     if (LL <= L && R <= RR) {
         Lazy[root] += val;
         seg_tree[root] += val * (R - L + 1);
        return ;
     }
     push_down(root, L, R);
     int mid = (L + R) >> 1;
     if (LL <= mid) update_Interval(root << 1, L, mid, LL, RR, val);
     if (RR > mid) update_Interval(root << 1 | 1, mid + 1, R, LL , RR, val);
     push_up(root);
}
//閸楁洜鍋ｆ穱顔芥暭 閸欘垯浜掗弨閫涜礋閺屾劕鈧》绱濋幋鏍偓锟�+-閺屾劕鈧拷
//閹跺os娴ｅ秶鐤嗛惃鍕偓鍏兼暭閹存仸al
void update(int root, int L, int R, int pos, int val) {
    if(L == R){
        seg_tree[root] = val;    //閻愬湱娲块幒銉ュ綁娑撶儤鐓囬崐锟�
        return ;
    }
    int mid = (L + R) >> 1;
    if(pos <= mid) update(root << 1, L, mid, pos, val);
    else update(root << 1 | 1, mid + 1, R, pos, val);
    push_up(root);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,1,n,1,r));
    }
    return 0;
}
/*
5 4
3 2 4 5 1
1 2
2 4
3 5
2 3
*/