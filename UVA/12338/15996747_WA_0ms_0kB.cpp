#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)	x & (-x)
#define  mes(a, b)	memset(a, b, sizeof a)
#define  fi 		first
#define  se 		second
#define  INOPEM		freopen("in.txt", "r", stdin)
#define  OUTOPEN	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e3 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
ull seed = 131;

std::vector<ull> vec[maxn];
char s[maxm];

void init() {
	for(int i=1; i<=n; i++)
		vec[i].clear();
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i=1; i<=n; i++) {
			scanf("%s", s+1);
			int len = strlen(s+1);
			ull ans = 0;
			for(int j=1; j<=len; j++) {
				ans = ans * seed + s[j];
				vec[i].push_back(ans);
			}
		}
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", cas++);
		int u, v;
		while(q--) {
			scanf("%d%d", &u, &v);
			if(u == v) {
				printf("%d\n", vec[u].size());
				continue;
			}
			int l = 0;
			int r = min(vec[u].size(), vec[v].size());
			int mid;
			while(l <= r) {
				mid = (l + r) >> 1;
				if(vec[u][mid] == vec[v][mid]) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			if(vec[u][mid] == vec[v][mid])
				mid++;
			printf("%d\n", mid);
		}
	}
	return 0;
}