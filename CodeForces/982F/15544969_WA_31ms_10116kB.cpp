#include <cstdio>
#include <cstring> 
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
const int mx = 5e5 + 5;
int n, m, tot, cnt[mx], mark[mx];
bool vis[mx];
vector <int> mat[mx];

bool dfs(int u, int fa) {
	//printf("u = %d\n", u);
	vis[u] = true;
	int len = mat[u].size();
	for (int i = 0; i < len; i++) {
		int v = mat[u][i];
		if (v == fa) {
			cnt[u]++;
			mark[u] = true;
			return true;
		}
		else if (vis[v]) {
			continue;
		}
		else {
			if (dfs(v,fa)) {
				cnt[u]++;
				mark[u] = true;
				return true;
			}
		}
	}
	return false;
} 

int main() {
	memset(cnt, 0, sizeof(cnt));
	memset(mark, 0, sizeof(mark));
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		mat[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			memset(vis, false, sizeof(vis));
			if (dfs(i,i)) tot++;
			
		}
	}
	if (tot == 0) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == tot) {
			printf("%d\n",i);
			return 0;
		}
		//printf("cnt[%d] = %d\n",i, cnt[i]);
	}
		
	puts("-1");
	return 0;
} 