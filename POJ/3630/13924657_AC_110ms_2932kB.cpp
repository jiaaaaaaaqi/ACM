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

const int maxn = 100005;

char str[20];
int node[maxn][10];
bool vis[maxn];
int tol;

void init() {
	tol = 1;
	memset(vis, 0, sizeof(vis));
	memset(node[0], 0, sizeof(node[0]));
}

bool insert(char *str) {
	int len = strlen(str);
	int root = 0;
	bool flag = false;
	for(int i=0; i<len; i++) {
		int k = str[i] - '0';
		if(node[root][k] == 0) {
			memset(node[tol], 0, sizeof(node[tol]));
			node[root][k] = tol++;
			flag = true;
		}
		if(vis[node[root][k]] == true)
			return false;
		root = node[root][k];
	}
	vis[root] = true;
	return flag;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int n;
		scanf("%d", &n);
		bool flag = true;
		for(int i=0; i<n; i++) {
			scanf("%s", str);
			if(!flag)
				continue;
			if(!insert(str)) {
				flag = false;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
