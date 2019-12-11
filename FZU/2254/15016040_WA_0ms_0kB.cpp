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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const int maxm = 400;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
char str[maxn][20];
int maps[maxn][maxn];
int dis[maxn];
bool vis[maxn];

void init() {
	memset(str, 0, sizeof str);
	memset(vis, 0, sizeof vis);
	memset(dis, inf, sizeof dis);
	memset(maps, inf, sizeof maps);
}

int prim() {
	int ans = 0;
	for(int i=1; i<=n; i++)	dis[i] = maps[1][i];
	dis[1] = 0;
	vis[1] = true;
	for(int k=2; k<=n; k++) {
		int p = 0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p] > dis[i]) {
				p = i;
			}
		}
		vis[p] = true;
		ans += dis[p];
		for(int i=1; i<=n; i++) {
			 if(!vis[i] && dis[i] > dis[i] + maps[p][i]) {
				dis[i] = dis[p] + maps[p][i];
			 }
		}
	}
	return ans;
}

int main() {
	int w;
	while(~scanf("%d%d%d", &n, &m, &w)) {
		init();
		for(int i=1; i<=n; i++)	scanf("%s", str[i]+1);
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				int nn = 0;
				for(int k=1; k<=m; k++) {
					if(str[i][k] != str[j][k])	nn++;
				}
				maps[i][j] = maps[j][i] = min(m, nn*w);
			}
		}
		int ans = prim();
		printf("%d\n", ans + m);
	}
	return 0;
}
