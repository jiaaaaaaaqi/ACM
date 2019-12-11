#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;
const int maxn = 505;

int n, m;
int degree[maxn];
bool maps[maxn][maxn];
int ans[maxn];

void init() {
	memset(ans, 0, sizeof(ans));
	memset(maps, 0, sizeof(maps));
	memset(degree, 0, sizeof(degree));
}

void topsort() {
	int cnt = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=1; i<=n; i++) {
		if(degree[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int top = q.top();
		q.pop();
		ans[cnt++] = top;
		for(int i=1; i<=n; i++) {
			if(maps[top][i]) {
				maps[top][i] = false;
				degree[i]--;
				if(degree[i] == 0) {
					q.push(i);
				}
			}
		}
	}
}

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		for(int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(maps[u][v] == 0) {
				maps[u][v] = true;
				degree[v]++;
			}
		}
		topsort();
		for(int i=0; i<n; i++) 
			printf("%d%c", ans[i], i==n-1 ? '\n':' '); 
	}
	return 0;
}