#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int ans[100005];
int d[100005];

void init() {
	memset(d, 0, sizeof(d));
	memset(ans, 0, sizeof(ans));
}

int main() {
	int n;
	while(scanf("%d", &n), n) {
		init();
		for(int i=1; i<=n; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			d[l] += 1;
			d[r+1] -= 1;
		}
		for(int i=1; i<=n; i++) {
			ans[i] = ans[i-1] + d[i];
		}
		for(int i=1; i<=n; i++) {
			printf("%d%c", ans[i], i==n ? '\n':' ');
		}
	}
	return 0;
}