#include<bits/stdc++.h>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 50005;

int n;
int sum[maxn];

void init() {
	memset(sum, 0, sizeof(sum));
}

int lowbit(int x) {
	return x & (-x);
}

void update(int pos, int val) {
	while(pos <= n) {
		sum[pos] += val;
		pos += lowbit(pos);
	}
}

int query(int pos) {
	int ans = 0;
	while(pos > 0) {
		ans += sum[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			int x;
			scanf("%d", &x);
			update(i, x);
		}
		char str[10];
		printf("Case %d:\n", cas++);
		while(1) {
			scanf("%s", str);
			if(str[0] == 'E') {
				break;
			} else if(str[0] == 'A') {
				int pos, val;
				scanf("%d%d", &pos, &val);
				update(pos, val);
			} else if(str[0] == 'S') {
				int pos, val;
				scanf("%d%d", &pos, &val);
				update(pos, -val); 
			} else if(str[0] == 'Q') {
				int pos1, pos2;
				scanf("%d%d", &pos1, &pos2);
				int ans = query(pos2) - query(pos1 - 1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}