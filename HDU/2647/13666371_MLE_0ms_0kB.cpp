#include<bits/stdc++.h>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;
const int maxn = 10005;

int n, m;
int add[maxn];
int degree[maxn];
bool maps[maxn][maxn];

void init() {
	memset(add, 0, sizeof(add));
	memset(degree, 0, sizeof(degree));
	memset(maps, false, sizeof(maps));
}

int topu() {
	priority_queue<int, vector<int>, greater<int> > q;
	int cnt = 0;
	int ans = 0;
	for(int i=1; i<=n; i++) {
		if(degree[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int top = q.top();
		q.pop();
		cnt++;
		for(int i=1; i<=n; i++) {
			if(maps[top][i]) {
				maps[top][i] = false;
				degree[i] --;
				if(degree[i] == 0) {
					q.push(i);
					add[i] = max(add[top] + 1, add[i]);
				}
			}
		}
	}
	if(cnt == n) {
		for(int i=0; i<n; i++) {
			ans += (888 + add[i]);
		}
		return ans;
	} else {
		return -1;
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			maps[v][u] = true;
			degree[u]++;
		}
		int ans = topu();
		printf("%d\n", ans);
	}
	return 0;
}