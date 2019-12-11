#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1505;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
const double eps = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s1[maxn][maxn/10];
char s2[maxn][maxn/10];
map<ull, bool> vis;

void init() {
	vis.clear();
	memset(s1, 0, sizeof s1);
	memset(s2, 0, sizeof s2);
}

ull Hash(ull tmp, char *s) {
	int len = strlen(s);
	for(int i=0; i<len; i++) {
		tmp = tmp * 17 + (ull)s[i];
		tmp %= inf;
	}
	return tmp;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)	scanf("%s", s1[i]);
		for(int i=1; i<=m; i++)	scanf("%s", s2[i]);
		int ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				ull tmp = Hash(1, s1[i]);
				tmp = Hash(tmp, s2[j]);
//				printf("~~~%llu\n", tmp);
				if(vis[tmp] == 0) {
					ans++;
					vis[tmp] = true;
				}
			}
		}
		printf("Case %d: %d\n", cas++, ans);
	}
    return 0;
}
