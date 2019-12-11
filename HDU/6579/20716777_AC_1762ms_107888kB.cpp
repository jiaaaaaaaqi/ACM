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

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int d[maxn][32], p[maxn][32];

void add(int x, int id, int *d, int *p) {
	for(int i=31; i>=1; i--) {
		if(x == 0)	return ;
		if(x&(1<<(i-1))) {
			if(d[i] == 0) {
				d[i] = x;
				p[i] = id;
				// printf("%d %d\n", i, p[i]);
				break;
			} else {
				if(p[i] < id) {
					swap(d[i], x);
					swap(p[i], id);
				}
				x ^= d[i];
			}
		}
	}
}

int query(int l, int r, int *d, int *p) {
	// printf("d=%d p=%d\n", d[1], p[1]);
	// printf("d=%d p=%d\n", d[2], p[2]);
	int ans = 0;
	for(int i=31; i>=1; i--) {
		if(p[i] < l)	continue;
		ans = max(ans, ans^d[i]);
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		int x;
		scanf("%d%d", &n, &m);
		for(int i=1; i<=31; i++)
			d[0][i] = p[0][i] = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			for(int j=1; j<=31; j++) {
				p[i][j] = p[i-1][j];
				d[i][j] = d[i-1][j];
			}
			add(x, i, d[i], p[i]);
		}
		int ans = 0;
		while(m--) {
			int id;
			scanf("%d", &id);
			if(id == 0) {
				int l, r;
				scanf("%d%d", &l, &r);
				l = (l^ans)%n+1;
				r = (r^ans)%n+1;
				if(l > r)	swap(l, r);
				ans = query(l, r, d[r], p[r]);
				printf("%d\n", ans);
			} else {
				scanf("%d", &x);
				x ^= ans;
				n++;
				for(int j=1; j<=31; j++) {
					p[n][j] = p[n-1][j];
					d[n][j] = d[n-1][j];
				}
				add(x, n, d[n], p[n]);
			}
		}
	}
	return 0;
}

