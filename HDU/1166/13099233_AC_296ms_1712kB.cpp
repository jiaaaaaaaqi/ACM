#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int n;
int sum[50005];

void update(int pos, int val) {
	while(pos <= n) {
		sum[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(int pos) {
	int ans = 0;
	while(pos) {
		ans += sum[pos];
		pos -= (pos & (-pos));
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	int cas=1;
	while(T--) {
		scanf("%d", &n);
		memset(sum, 0, sizeof(sum));
		printf("Case %d:\n", cas++);
		for(int i=1, x; i<=n; i++) {
			scanf("%d", &x);
			update(i, x);
		}
		char s[10];
		while(scanf("%s", s)) {
			if(s[0] == 'E') {
				break;
			} else if(s[0] == 'A') {
				int i, j;
				scanf("%d%d", &i, &j);
				update(i, j);
			} else if(s[0] == 'S') {
				int i,j;
				scanf("%d%d", &i, &j);
				update(i, -j);
			} else {
				int i,j;
				scanf("%d%d",&i, &j);
				printf("%d\n", query(j) - query(i-1));
			}
		}
	}
	return 0;
}