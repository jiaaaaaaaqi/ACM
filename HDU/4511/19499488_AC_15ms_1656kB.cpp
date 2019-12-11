/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月29日 星期一 15时04分26秒
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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>

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

struct Point {
	double x, y;
	Point() {

	}
	Point(double _x, double _y) {
		x = _x, y = _y;
	}
} point[55];

struct AC {
	int node[505][55], fail[505], cnt[505];
	double dp[55][505];
	int root, sz;
	int newnode() {
		mes(node[++sz], 0);
		cnt[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(int s[], int len) {
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = s[i];
			if(node[rt][k] == 0)	node[rt][k] = newnode();
			rt = node[rt][k];
		}
		cnt[rt] = 1;
	}
	void build() {
		fail[root] = root;
		queue<int> q;
		while(!q.empty())	q.pop();
		for(int i=1; i<=n; i++) {
			if(node[root][i] == 0) {
				node[root][i] = root;
			} else {
				fail[node[root][i]] = root;
				q.push(node[root][i]);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			cnt[u] |= cnt[fail[u]];
			for(int i=1; i<=n; i++) {
				if(node[u][i] == 0) {
					node[u][i] = node[fail[u]][i];
				} else {
					fail[node[u][i]] = node[fail[u]][i];
					q.push(node[u][i]);
				}
			}
		}
	}
	double calc(Point a, Point b) {
		double x = a.x - b.x;
		double y = a.y - b.y;
		return sqrt(x*x+y*y);
	}
	double solve() {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=sz; j++) {
				dp[i][j] = DBL_MAX;
			}
		}
		dp[1][node[root][1]] = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=sz; j++) {
				if(dp[i][j] == DBL_MAX)	continue;
				for(int k=i+1; k<=n; k++) {
					int nst = node[j][k];
					if(cnt[nst])	continue;
					dp[k][nst] = min(dp[k][nst], dp[i][j] + calc(point[i], point[k]));
				}
			}
		}
		double ans = DBL_MAX;
		for(int j=1; j<=sz; j++)
			ans = min(ans, dp[n][j]);
		return ans;
	}
} ac;
int s[105];

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		for(int i=1, x, y; i<=n; i++) {
			scanf("%d%d", &x, &y);
			point[i] = Point(1.0*x, 1.0*y);
		}
		ac.init();
		for(int i=1, k; i<=m; i++) {
			scanf("%d", &k);
			for(int i=1; i<=k; i++) {
				scanf("%d", &s[i]);
			}
			ac.insert(s, k);
		}
		ac.build();
		double ans = ac.solve();
		if(ans == DBL_MAX)
			printf("Can not be reached!\n");
		else
			printf("%.2f\n", ans);
	}
	return 0;
}

