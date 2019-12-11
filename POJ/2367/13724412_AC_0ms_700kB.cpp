#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 105;
int n, m;
vector<int> maps[maxn];
int ans[maxn];
int ind[maxn];

void init(int n) {
	for(int i=0; i<n; i++) {
		maps[i].clear();
	}
	memset(ans, 0, sizeof ans);
	memset(ind, 0, sizeof ind);
}

void tupo() {
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(ind[i] == 0) {
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		ans[cnt++] = t;
		for(int i=0; i<maps[t].size(); i++) {
			ind[maps[t][i]]--;
			if(ind[maps[t][i]] == 0) {
				q.push(maps[t][i]);
			}
		}
	}
}

int main() {
	while(~scanf("%d", &n)) {
		init(n);
		for(int i=1; i<=n; i++) {
			int v;
			while(scanf("%d", &v), v) {
				maps[i].push_back(v);
				ind[v]++;
			}
		}
		tupo();
		for(int i=0; i<n; i++) 
			printf("%d%c", ans[i], i==n-1 ? '\n' : ' ');
	}
	return 0;
}
