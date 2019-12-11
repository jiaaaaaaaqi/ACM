#include<map>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 10005;

int n, m;
int add[maxn];
int degree[maxn];
vector<int> maps[maxn];

void init() {
	memset(add, 0, sizeof(add));
	memset(degree, 0, sizeof(degree));
	memset(maps, false, sizeof(maps));
}

int topu() {
	queue<int> q;
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		if(degree[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		cnt++;
		int len = maps[top].size();
		for(int i=0; i<len; i++) {
			degree[maps[top][i]] --;
			if(degree[maps[top][i]] == 0) {
				q.push(maps[top][i]);
				add[maps[top][i]] = max(add[top] + 1, add[maps[top][i]]);
			}
		}
	}
	if(cnt == n) {
		int ans = 0;
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
			maps[v].push_back(u);
			degree[u]++;
		}
		int ans = topu();
		printf("%d\n", ans);
	}
	return 0;
}