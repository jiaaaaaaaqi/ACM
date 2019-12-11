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

int tol;
int anstol;
char str[26];
int ans[maxn];
int node[maxn][28];
bool vis[maxn];
vector<int> v[maxn];

void init() {
	tol = 1;
	memset(vis, false, sizeof(vis));
	memset(node[0], 0, sizeof(node[0]));
	for(int i=0; i<maxn; i++)
		v[i].clear();
}

int getnum(char c) {
	if(islower(c))
		return c - 'a';
	else if(c == '*')
		return 26;
	else if(c == '?')
		return 27;
}

void insert(char *str, int id) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++)  {
		k = getnum(str[i]);
		if(node[root][k] == 0) {
			memset(node[tol], 0, sizeof(node[tol]));
			node[root][k] = tol++;
		}
		root = node[root][k];
	}
	vis[root] = true;
	v[root].push_back(id);
}

void dfs(char *str, int root, int pos, int len) {
	if(node[root][26]) {
		for(int i=pos; i<=len; i++) {
			dfs(str, node[root][26], i, len);
		}
	}
	if(pos == len && v[root].size()) {
		int k = v[root].size();
		for(int i=0; i<k; i++) {
			ans[anstol++] = v[root][i]; 
		}
		return ;
	}
	int k = getnum(str[pos]);
	if(node[root][k]) {
		dfs(str, node[root][k], pos+1, len);
	}
	if(node[root][27]) {
		dfs(str, node[root][27], pos+1, len);
	}
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=0; i<n; i++) {
			scanf("%s", str);
			insert(str, i);
		}
		for(int i=0; i<m; i++) {
			scanf("%s", str);
			anstol = 0;
			int len = strlen(str);
			dfs(str, 0, 0, len);
			if(anstol == 0) {
				printf("Not match\n");
			} else {
				sort(ans, ans+anstol);
				anstol = unique(ans, ans+anstol) - ans;
				for(int i=0; i<anstol; i++) {
					printf("%d ", ans[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
