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

const int maxn = 50005;

struct Node {
	int val, id;
	bool operator < (const Node a) const {
		return val > a.val;
	}
};
int n, m;
int en[maxn];
int ans[maxn];
int ind[maxn];
vector<int> maps[maxn];
	
void init() {
	memset(en, 0, sizeof(en));
	memset(ans, 0, sizeof(ans));
	memset(ind, 0, sizeof(ind));
	for(int i=0; i<=n; i++) {
		maps[i].clear();
	}
}

void topu() {
	priority_queue<Node> q;
	Node now, nex;
	int num = 0;
	for(int i=1; i<=n; i++) {
		if(ind[i] == 0) {
			now.id = i;
			now.val = en[i];
			q.push(now);
		}
	}
	while(!q.empty()) {
		now = q.top();
		q.pop();
		ans[num++] = now.id;
		int len = maps[now.id].size();
		for(int i=0; i<len; i++) {
			nex.id = maps[now.id][i];
			nex.val = en[nex.id];
			ind[nex.id]--;
			if(ind[nex.id] == 0) {
				q.push(nex);
			}
		}		 
	}
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i=0; i<n; i++) {
			int p;
			scanf("%d%d", &p, &en[i]);
		}
		scanf("%d", &m);
		for(int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			ind[v]++;
			maps[u].push_back(v);
		}
		topu();
		for(int i=0; i<n; i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}