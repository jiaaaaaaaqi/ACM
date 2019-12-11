
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 110000
#define lmin 1
#define rmax n
#define lson l,(l+r)/2,rt<<1
#define rson (l+r)/2+1,r,rt<<1|1
#define root lmin,rmax,1
#define now l,r,rt
#define int_now int l,int r,int rt
#define INF 0x3f3f3f3f
#define eqs 1e-6
#define LL __int64
#define mod 10007
#define zero(x) ( fabs(x) < eqs ? 0 : x )
#define mem(a,b) (memset(a),b,sizeof(a))
int cl[maxn<<2] ;
int lazy[maxn<<2] ;
/*
void push_up(int_now)
{
    cl[rt] = cl[rt<<1] | cl[rt<<1|1] ;
}
*/
void push_up(int_now) {
	cl[rt] = cl[rt << 1] | cl[rt << 1 | 1];
}
/*
void push_down(int_now)
{
    if( lazy[rt] )
    {
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt] ;
        cl[rt<<1] = cl[rt<<1|1] = lazy[rt] ;
        lazy[rt] = 0 ;
    }
}
*/

void push_down(int_now) {
	if(lazy[rt]) {
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		cl[rt << 1] = cl[rt << 1 | 1] = lazy[rt];
		lazy[rt] = 0;
	}
}
/*
void creat(int_now) {
	cl[rt] = lazy[rt] = 0 ;
	if( l != r ) {
		creat(lson);
		creat(rson);
		push_up(now);
	} else
		cl[rt] = 1 ;
}
*/
void creat(int_now) {
	if(l == r) {
		cl[rt] = 1;
		return ;
	}
	creat(lson);
	creat(rson);
	push_up(now);
}
/*
void update(int ll,int rr,int x,int_now) {
	if( ll > r || rr < l )
		return ;
	if( ll <= l && r <= rr ) {
		cl[rt] = lazy[rt] = 1<<(x-1);
		return ;
	}
	push_down(now);
	update(ll,rr,x,lson);
	update(ll,rr,x,rson);
	push_up(now);
}
*/

void update(int ll, int rr, int x, int_now) {
	if(ll <= l && r <= rr) {
		cl[rt] = 1 << (x - 1);
		lazy[rt] = 1 << (x - 1);
		return ;
	}
	push_down(now);
	int mid = (l + r) >> 1;
	if(ll <= mid)
		update(ll, rr, x, lson);
	if(rr > mid)
		update(ll, rr, x, rson);
	push_up(now);
}

int query(int ll,int rr,int_now) {
	if(ll > r || rr < l)
		return 0;
	if(ll <= l && r <= rr)
		return cl[rt] ;
	push_down(now);
	return query(ll,rr,lson) | query(ll,rr,rson);
}
int ans(int x) {
	int aa = 0 ;
	while(x) {
		if(x & 1)
			aa++ ;
		x >>= 1 ;
	}
	return aa ;
}
int main() {
	int n , ls , m ;
	int l , r , x ;
	char str[10] ;
	while(~scanf("%d %d %d", &n, &ls, &m)) {
		creat(root);
		while(m--) {
			scanf("%s", str);
			if(str[0] == 'C') {
				scanf("%d %d %d", &l, &r, &x);
				if(l > r)
					swap(l,r);
				update(l,r,x,root);
			} else {
				scanf("%d %d", &l, &r);
				if(l > r)
					swap(l,r);
				printf("%d\n",ans( query(l,r,root) ) );
			}
		}
	}
	return 0;
}

