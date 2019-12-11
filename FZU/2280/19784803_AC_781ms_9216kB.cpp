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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int val[maxn], len[maxn];
char s[maxn][maxn];
ull Hash[maxn][maxn], seed = 131;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%s%d", s[i]+1, &val[i]);
			len[i] = strlen(s[i]+1);
			reverse(s[i]+1, s[i]+1+len[i]);
			Hash[i][0] = 0;
			for(int j=1; j<=len[i]; j++) {
				Hash[i][j] = Hash[i][j-1]*seed + s[i][j];
			}
		}
		scanf("%d", &m);
		while(m--) {
			int id;
			scanf("%d", &id);
			if(id == 1) {
				int p, v;
				scanf("%d%d", &p, &v);
				val[p] = v;
			} else {
				int p;
				scanf("%d", &p);
				int ans = 0;
				for(int i=1; i<=n; i++) {
					if(len[i] < len[p])	continue;
					if(val[i] > val[p])	continue;
					if(Hash[i][len[p]] == Hash[p][len[p]]) {
						ans++;
					}
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
