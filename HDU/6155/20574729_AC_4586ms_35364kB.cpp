#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Mat {
	ll mat[4][4];
	void init() {
		for(int i=0; i<=3; i++) {
			for(int j=0; j<=3; j++) {
				mat[i][j] = 0;
			}
		}
	}
} a[maxn<<2];
char s[maxn];
int lazy[maxn<<2];

Mat mmul(Mat A, Mat B) {
	Mat ans;
	ans.init();
	for(int k=1; k<=3; k++) {
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				ans.mat[i][j] += A.mat[i][k]*B.mat[k][j]%mod;
				while(ans.mat[i][j]>=mod)	ans.mat[i][j] -= mod;
			}
		}
	}
	return ans;
}

void change(int rt) {
	for(int j=1; j<=3; j++)
		swap(a[rt].mat[1][j], a[rt].mat[2][j]);
	for(int i=1; i<=3; i++)
		swap(a[rt].mat[i][1], a[rt].mat[i][2]);
}

void pushdown(int rt) {
    if(lazy[rt]) {
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        lazy[rt<<1] &= 1;
        lazy[rt<<1|1] &= 1;
		change(rt<<1);
		change(rt<<1|1);
        lazy[rt] = 0;
    }
}

void pushup(int rt) {
	a[rt] = mmul(a[rt<<1|1], a[rt<<1]);
}

void build(int l, int r, int rt) {
	lazy[rt] = 0;
	a[rt].init();
    if(l == r) {
		if(s[l] == '1') {
			a[rt].mat[1][1] = a[rt].mat[2][1] = a[rt].mat[2][2] = a[rt].mat[2][3] = a[rt].mat[3][3] = 1;
		} else {
			a[rt].mat[1][1] = a[rt].mat[1][2] = a[rt].mat[1][3] = a[rt].mat[2][2] = a[rt].mat[3][3] = 1;
		}
        return ;
    }
    int mid = l+r>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void update(int l, int r, int pl, int pr, int rt) {
    if(pl<=l && r<=pr) {
		change(rt);
		lazy[rt] = (lazy[rt]+1)&1;
	    return ;
    }
    pushdown(rt);
    int mid = l+r>>1;
    if(pl <= mid)	update(l, mid, pl, pr, rt<<1);
    if(pr > mid)	update(mid+1, r, pl, pr, rt<<1|1);
	pushup(rt);
}

Mat query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr)	return a[rt];
	pushdown(rt);
	int mid = l+r>>1;
	Mat ans;ans.init();
	for(int i=1; i<=3; i++)	ans.mat[i][i] = 1;
	if(pl <= mid)	ans = mmul(query(l, mid, pl, pr, rt<<1), ans);
	if(pr > mid)	ans = mmul(query(mid+1, r, pl, pr, rt<<1|1), ans);
	return ans;
}

int main() {
	// INOPEN;
	// {
	//     Mat A, B;
	//     A.init(), B.init();
	//     A.mat[1][1] = A.mat[1][2] = A.mat[1][3] = A.mat[2][2] = A.mat[3][3] = 1;
	//     B.mat[1][1] = B.mat[2][1] = B.mat[2][2] = B.mat[2][3] = B.mat[3][3] = 1;
	//     Mat ans = mmul(mmul(mmul(A, A), B), B);
	//     
	//     for(int i=1; i<=3; i++) {
	//         for(int j=1; j<=3; j++) {
	//             printf("%lld%c", ans.mat[i][j], j==3 ? '\n' : ' ');
	//         }
	//     }
	// }
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		scanf("%s", s+1);
		build(1, n, 1);
		int id, l, r;
		while(m--) {
			scanf("%d%d%d", &id, &l, &r);
			if(id == 1) {
				update(1, n, l, r, 1);
			} else {
				Mat ans = query(1, n, l, r, 1);
				ll res = (ans.mat[1][3] + ans.mat[2][3])%mod;
				printf("%lld\n", res);
			}
			// if(id==1 && l==1 && r==2) {
			//     Mat ans = query(1, n, 1, 4, 1);
			//     cout << endl;
			//     for(int i=1; i<=3; i++) {
			//         for(int j=1; j<=3; j++) {
			//             printf("%lld%c", ans.mat[i][j], j==3 ? '\n' : ' ');
			//         }
			//     }
			// }
		}
	}
	return 0;
}

