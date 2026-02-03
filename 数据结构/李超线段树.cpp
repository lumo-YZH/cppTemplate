#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
#define M 50005
using namespace std;
int n , cnt;
double k[N] , b[N];
char s[15];
template < typename T >
inline void read( T & res ) {
	res = 0;
	T pd = 1;
	char aa = getchar();
	while ( aa < '0' || aa > '9' ) {
		if ( aa == '-' ) {
			pd = -pd;
		}
		aa = getchar();
	}
	while ( aa >= '0' && aa <= '9' ) {
		res = ( res << 1 ) + ( res << 3 ) + ( aa - '0' );
		aa = getchar();
	}
	res *= pd;
	return;
}
inline double w( int id , int pos ) {
	return k[id] * ( pos - 1.0 ) + b[id];
}
struct SegmentTree {
	#define ls root << 1
	#define rs root << 1 | 1
	int t[M << 2];
	inline void update( int root , int l , int r , int p ) {
		if ( w( p , l ) <= w( t[root] , l ) && w( p , r ) <= w( t[root] , r ) ) {
			return;//情况1
		}
		if ( w( p , l ) > w( t[root] , l ) && w( p , r ) > w( t[root] , r ) ) {
			t[root] = p;//情况2
			return;
		}
		int mid = ( l + r ) >> 1;//情况3
		if ( k[p] > k[t[root]] ) {//斜率讨论法
			if ( w( p , mid ) > w( t[root] , mid ) ) {
				update( ls , l , mid , t[root] );
				t[root] = p;
			} else {
				update( rs , mid + 1 , r , p );
			}
		} else {
			if ( w( p , mid ) > w( t[root] , mid ) ) {
				update( rs , mid + 1 , r , t[root] );
				t[root] = p;
			} else {
				update( ls , l , mid , p );
			}
		}
	}
	inline double query( int root , int l , int r , int pos ) {
		if ( l == r ) {
			return w( t[root] , pos );
		}
		int mid = ( l + r ) >> 1;
		//查询时取便历到的最值
		if ( pos <= mid ) {
			return max( w( t[root] , pos ) , query( ls , l , mid , pos ) );
		} else {
			return max( w( t[root] , pos ) , query( rs , mid + 1 , r , pos ) );
		}
	}
}tree;
int main () {
	read(n);
	int tem;
	while ( n-- ) {
		scanf("%s",s);
		if ( s[0] == 'P' ) {
			cnt++;
			scanf("%lf%lf",&b[cnt],&k[cnt]);
			tree.update( 1 , 1 , M , cnt ); 
		} else {
			read(tem);
			printf("%d\n",(int)tree.query( 1 , 1 , M , tem ));
		}
	}
	return 0;
}
