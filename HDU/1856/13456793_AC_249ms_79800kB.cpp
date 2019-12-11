#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 10000005;

int fa[maxn];
int cnt[maxn];

void init(int n) {
	for(int i=0; i<=maxn; i++) {
		fa[i] = i;
		cnt[i] = 0;
	}
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void bind(int u, int v) {
	int x = find(u);
	int y = find(v);
	if(x != y) {
		fa[y] = x;
	}
	return ;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			printf("1\n");
			continue;
		}
		init(n);
		int maxi, mini;
		maxi = -1;
		mini = 0x3f3f3f3f;
		for(int i=1; i<=n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			bind(u, v);
			maxi = max(maxi, max(u, v));
			mini = min(mini, min(u, v));
		}
		int ans = 0;
		for(int i=mini; i<=maxi; i++) {
			find(i);
			cnt[fa[i]]++;
			ans = max(ans, cnt[fa[i]]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
