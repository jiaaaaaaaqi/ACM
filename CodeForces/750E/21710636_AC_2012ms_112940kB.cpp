/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 11 Sep 2019 11:46:45 PM CST
 ***************************************************************/

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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];
struct Mat {
	int mat[6][6];
	void init() {
		for(int i=1; i<=5; i++) {
			for(int j=1; j<=5; j++) {
				mat[i][j] = (j==i ? 0 : inf);
			}
		}
	}
} node[maxn*4];

Mat mmul(Mat A, Mat B) {
	Mat ans;
	mes(ans.mat, inf);
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=5; j++) {
			for(int k=1; k<=5; k++) {
				ans.mat[i][j] = min(ans.mat[i][j], A.mat[i][k]+B.mat[k][j]);
			}
		}
	}
	return ans;
}

void pushup(int rt) {
	node[rt] = mmul(node[rt<<1], node[rt<<1|1]);
}

void build(int l, int r, int rt) {
	if(l == r) {
		node[rt].init();
		if(s[l] == '2') {
			node[rt].mat[1][1] = 1;
			node[rt].mat[1][2] = 0;
		} else if(s[l] == '0') {
			node[rt].mat[2][2] = 1;
			node[rt].mat[2][3] = 0;
		} else if(s[l] == '1') {
			node[rt].mat[3][3] = 1;
			node[rt].mat[3][4] = 0;
		} else if(s[l] == '7') {
			node[rt].mat[4][4] = 1;
			node[rt].mat[4][5] = 0; 
		} else if(s[l] == '6') {
			node[rt].mat[4][4] = 1;
			node[rt].mat[5][5] = 1;
		}
		return ;
	}
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

Mat query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt];
	}
	int mid = l+r>>1;
	Mat ans;
	ans.init();
	if(pl<=mid)	ans = mmul(ans, query(l, mid, pl, pr, rt<<1));
	if(pr>mid)	ans = mmul(ans, query(mid+1, r, pl, pr, rt<<1|1));
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	build(1, n, 1);
	int l, r;
	while(m--) {
		scanf("%d%d", &l, &r);
		Mat ans = query(1, n, l, r, 1);
		printf("%d\n", ans.mat[1][5] == inf ? -1 : ans.mat[1][5]);
	}
	return 0;
}

