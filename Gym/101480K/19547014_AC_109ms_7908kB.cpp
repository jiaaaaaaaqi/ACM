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

int ind[maxn];
vector<int> vv[maxn];
int vis[maxn];

void solve() {
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(ind[i] == 0)
			q.push(i);
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(vis[u])	continue;
		vis[u] = 1;
		for(auto v : vv[u]) {
			if(vis[v])	continue;
			vis[v] = 2;
			ind[v]--;
			for(auto nst : vv[v]) {
				if(vis[nst])	continue;
				ind[nst]--;
				if(ind[nst] == 0)
					q.push(nst);
			}
		}
	}
	int nn = n/2;
	for(int i=1; i<=nn; i++) {
		if(!vis[i] && ind[i])	vis[i] = 1;
	}
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=2*n; i++) {
		ind[i] = 0;
		vv[i].clear();
	}
	for(int i=1, v; i<=n; i++) {
		scanf("%d", &v);
		vv[i].push_back(v);
		ind[v]++;
	}
	for(int i=1, v; i<=n; i++) {
		scanf("%d", &v);
		vv[i+n].push_back(v);
		ind[v]++;
	}
	n <<= 1;
	solve();
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		if(vis[i] == 1) {
			if(cnt)	printf(" ");
			printf("%d", i);
			cnt++;
		}
	}
	printf("\n");
	return 0;
}
