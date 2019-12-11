#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 105;

int n, m;
int ind[maxn];
vector<int> maps[maxn];

void init() {
	memset(ind, 0, sizeof ind);
	for(int i=0; i<maxn; i++) {
		maps[i].clear();
	}
}

bool topu() {
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(ind[i] == 0)  {
			q.push(i);
		}
	}
	int ans = 0;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		ans ++;
		for(int j=0; j<maps[t].size(); j++) {
			ind[maps[t][j]]--;
			if(ind[maps[t][j]] == 0) {
				q.push(maps[t][j]);
			}
		}
	}
	printf("%d\n", ans);
	if(ans == n)
		return true;
	else
		return false;
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			u++;
			v++;
			ind[v]++;
			maps[u].push_back(v);
		}
		bool ans = topu();
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}