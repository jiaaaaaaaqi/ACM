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

const int maxn = 200005;

vector<int> v[maxn];
int num[maxn];
int n, m;

void init() {
	memset(num, 0, sizeof(num));
	for(int i=1; i<=n; i++)
		v[i].clear();
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++ ) {
			scanf("%d", &num[i]);
			for(int j=1; j<i; j++) {
				if(num[i] > num[j]) {
					v[i].push_back(j);
				}
				if(num[i] < num[j]) {
					v[j].push_back(i);
				}
			}
		}
		for(int i=0; i<m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			/*
			if(find(v[x].begin(), v[x].end(), y) != v[x].end()) {
				int pos = find(v[x].begin(), v[x].end(), y) - v[x].begin();
				v[x].erase(v[x].begin() + pos);
			}
			if(find(v[y].begin(), v[y].end(), x) != v[y].end()) {
				int pos = find(v[y].begin(), v[y].end(), x) - v[y].begin();
				v[y].erase(v[y].begin() + pos);
			}
			*/
			int pos1 = find(v[x].begin(), v[x].end(), y) - v[x].begin();
			if(pos1 != v[x].size()) {
				v[x].erase(v[x].begin() + pos1);
			}
			int pos2 = find(v[y].begin(), v[y].end(), x) - v[y].begin();
			if(pos2 != v[y].size()) {
				v[y].erase(v[y].begin() + pos2);
			}
		}
		for(int i=1; i<=n; i++) {
			printf("%d%c", v[i].size(), i==n ? '\n' : ' ');
		}
	}
	return 0;
}