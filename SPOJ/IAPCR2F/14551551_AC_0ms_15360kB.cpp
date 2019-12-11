#include<map>
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
const int maxm = 1<<11;
const int mod = 200;
using namespace std;

int n, m, tol;
int fa[maxn];
int ans[maxn];
int vis[maxn];
int num[maxn];

void init() {
	memset(fa, -1, sizeof fa);
	memset(ans, 0, sizeof ans);
	memset(vis, 0, sizeof vis);
	memset(num, 0, sizeof num);
}

int find(int x) {
	return fa[x] == -1 ? x : fa[x]=find(fa[x]);
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) 	scanf("%d", &num[i]);
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(u > v)	swap(u, v);
			int x = find(u);
			int y = find(v);
			if(x != y)
				fa[y] = x;
		}
		tol = 0;
		for(int i=1; i<=n; i++) {
			int x = find(i);
			if(x == i) {
				vis[++tol] = i;
			} else {
				num[x] += num[i];
			}
		}
		int cnt = 0;
		for(int i=1; i<=tol; i++) {
			ans[++cnt] = num[vis[i]];
		}
		sort(ans+1, ans+cnt+1);
		printf("Case %d: %d\n", cas++, cnt);
		for(int i=1; i<=cnt; i++) {
			printf("%d%c", ans[i], i==cnt ? '\n' : ' ');
		}
	}
	return 0;
}
