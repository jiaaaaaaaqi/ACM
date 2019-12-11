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

const int maxn = 30;
int n, m;
vector<int> maps[maxn];
int ind[maxn];
int ans[maxn];
int preind[maxn];

void init(int n) {
	for(int i=0; i<=n; i++) {
		maps[i].clear();
	}
	memset(ans, 0, sizeof(ans));
	memset(ind, 0, sizeof(ind));
}

int topu() {
	memset(ans, 0, sizeof(ans));
	memcpy(preind, ind, sizeof(ind));
	queue<int> q;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		if(preind[i] == 0) {
			q.push(i);
		}
	}
	bool flag = false;
	while(!q.empty()) {
		if(q.size() > 1)
			flag = true;
		int t = q.front();
		q.pop();
		ans[cnt++] = t;
		for(int i=0; i<maps[t].size(); i++) {
			preind[maps[t][i]]--;
			if(preind[maps[t][i]] == 0)
				q.push(maps[t][i]);
		}
	}
	if(cnt < n)
		return -1;
	if(flag)
		return 0;
	return 1;
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init(n);
		bool flag = false;
		int acc = -1;
		int err = -1;
		char ch[10];
		for(int i=1; i<=m; i++) {
			scanf("%s", ch);
			if(flag)
				continue;
			int u = ch[0] - 'A';
			int v = ch[2] - 'A';
			maps[u].push_back(v);
			ind[v]++;
			int k = topu();
			if(k == -1) {
				flag = true;
				err = i;
			} else if(k == 1) {
				flag = true;
				acc = i;
			}
		}
		if(err == -1 && acc == -1) {
			printf("Sorted sequence cannot be determined.\n");
		} else if(acc != -1) {
			printf("Sorted sequence determined after %d relations: ", acc);
			for(int i=0; i<n; i++) 
				printf("%c", ans[i] + 'A');
			printf("\n");
		} else if(err != -1) {
			printf("Inconsistency found after %d relations.\n", err);
		}
	}
	return 0;
}
