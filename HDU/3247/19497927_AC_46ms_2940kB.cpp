/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月29日 星期一 11时10分00秒
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
const int    maxn = 6e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[1010];
struct AC {
	int node[maxn][2], fail[maxn], cnt[maxn], vir[maxn];
	int root, sz;
	int newnode() {
		mes(node[++sz], 0);
		cnt[sz] = vir[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(char *s, int f, int id) {
		int len = strlen(s+1);
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = s[i]-'0';
			if(node[rt][k] == 0) {
				node[rt][k] = newnode();
			}
			rt = node[rt][k];
		}
		if(f == 1)	cnt[rt] |= (1<<(id-1));
		else	vir[rt] = 1;
	}
	void build() {
		queue<int> q;
		while(!q.empty())	q.pop();
		fail[root] = root;
		for(int i=0; i<=1; i++) {
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
			vir[u] |= vir[fail[u]];
			cnt[u] |= cnt[fail[u]];
			for(int i=0; i<=1; i++) {
				if(node[u][i] == 0) {
					node[u][i] = node[fail[u]][i];
				} else {
					fail[node[u][i]] = node[fail[u]][i];
					q.push(node[u][i]);
				}
			}
		}
	}
	int dis[maxn], point[500];
	bool vis[maxn];
	int cc[500][500], dp[500][1030];
	void bfs(int st) {
		queue<int> q;
		while(!q.empty())	q.pop();
		for(int i=1; i<=sz; i++)	dis[i] = inf;
		mes(vis, 0);
		q.push(point[st]);
		dis[point[st]] = 0;
		vis[point[st]] = 1;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i=0; i<=1; i++) {
				int k = node[u][i];
				if(vir[k])	continue;
				if(vis[k])	continue;
				dis[k] = dis[u]+1;
				vis[k] = true;
				q.push(k);
			}
		}
		for(int i=1; i<=tol; i++) {
			cc[st][i] = dis[point[i]];
		}
	}
	void handle() {
		tol = 0;
		point[++tol] = 1;
		for(int i=1; i<=sz; i++) {
			if(cnt[i]) {
				point[++tol] = i;
			}
		}
		for(int i=1; i<=tol; i++) {
			bfs(i);
		}
	//     for(int i=1; i<=tol; i++) {
	//         for(int j=1; j<=tol; j++) {
	//             printf("%d%c", cc[i][j], j==tol ? '\n' : ' ');
	//         }
	//     }
	//     for(int i=1; i<=tol; i++) {
	//         printf("cnt[%d] = %d\n", i, cnt[point[i]]);
	//     }
	}
	int solve() {
		int mx = (1<<n)-1;
		for(int i=1; i<=tol; i++) {
			for(int j=0; j<=mx; j++) {
				dp[i][j] = inf;
			}
		}
		dp[1][0] = 0;
		for(int j=0; j<=mx; j++) {
			for(int i=1; i<=tol; i++) {
				if(dp[i][j] == inf)	continue;
				// printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
				for(int k=1; k<=tol; k++) {
					if(i == k)	continue;
					dp[k][j|cnt[point[k]]] = min(dp[k][j|cnt[point[k]]], dp[i][j]+cc[i][k]);
				}
			}
		}
		int ans = inf;
		for(int i=1; i<=tol; i++) {
			ans = min(ans, dp[i][mx]);
		}
		return ans;
	}
} ac;

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		ac.init();
		for(int i=1; i<=n; i++) {
			scanf("%s", s+1);
			ac.insert(s, 1, i);
		}
		for(int i=1; i<=m; i++) {
			scanf("%s", s+1);
			ac.insert(s, 2, i);
		}
		ac.build();
		ac.handle();
		int ans = ac.solve();
		printf("%d\n", ans);
	}
	return 0;
}
/*
3 2
101
010
1111
001
011
*/
