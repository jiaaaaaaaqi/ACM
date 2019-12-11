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
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, k;
int cas, tol, T;

int a[maxn];
int sg[maxn];

void dfs(int x) {
	if(sg[x] != -1)	return ;
	vector<bool> vis(maxn, false);
	for(int i=0; i<=m; i++) {
		int up = x-i;
		if(up <= 0)	continue;
		int nxt = up - a[up];
		if(nxt < 0)	continue;
		dfs(nxt);
		vis[sg[nxt]] = true;
	}
	for(int i=0; ; i++) {
		if(!vis[i]) {
			sg[x] = i;
			return ;
		}
	}
}

int main() {
	scanf("%d%d", &T, &m);
	int ans = 0;
	while(T--) {
		scanf("%d", &n);
		mes(sg, -1);
		a[0] = sg[0] = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			if(a[i] > i)
				sg[i] = 0;
		}
		dfs(n);
		ans ^= sg[n];
	}
	if(ans!=0)	
		printf("Alice can win.\n");
	else	
		printf("Bob will win.\n");
	return 0;
}
