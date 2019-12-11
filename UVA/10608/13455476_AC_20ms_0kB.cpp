#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 30005;
int fa[maxn];
int cnt[maxn];

void init(int n) {
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<=n; i++)
		fa[i] = i;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		init(n);
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int x = find(u);
			int y = find(v);
			if(x != y) {
				fa[y] = x;
			}
		}
		int ans = 0;
		for(int i=1; i<=n; i++) {
			find(i);
			cnt[fa[i]]++;
			ans = max(ans, cnt[fa[i]]);
		}
		printf("%d\n", ans);
	}
	return 0;
} 