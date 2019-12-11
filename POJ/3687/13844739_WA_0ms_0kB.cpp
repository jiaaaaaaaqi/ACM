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

const int maxn = 205;

int n, m;
int ans[maxn];
int ind[maxn];
bool maps[maxn][maxn];

void init() {
	memset(ans, 0, sizeof ans);
	memset(ind, 0, sizeof ind);
	memset(maps, 0, sizeof maps);
}

bool topu() {
	int num = 0;
	priority_queue<int> pq;
	for(int i=1; i<=n; i++) {
		if(ind[i] == 0) {
			pq.push(i);
		}
	}
	while(!pq.empty()) {
		int t = pq.top();
		pq.pop();
		ans[num++] = t;
		for(int i=1; i<=n; i++) {
			if(maps[t][i] == true) {
				ind[i]--;
				if(ind[i] == 0)
					pq.push(i);
			}
		}
	}
	if(num == n)
		return true;
	else 
		return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			maps[v][u] = true;
			ind[u] ++;
		}
		bool bo = topu();
		if(bo) {
			for(int i=n-1; i>=0; i--) {
				printf("%d%c", ans[i], i==0 ? '\n' : ' ');
			}
		} else {
			printf("-1\n");
		}
		printf("\n");
	}
	return 0;
}