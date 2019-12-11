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

const int maxn = 10000005;

int tol;
int node[maxn][15];
char str[10000];
bool vis[maxn];

void init() {
	tol = 1;
	memset(str, 0, sizeof(str));
	memset(vis, false, sizeof(vis));
	memset(node[0], 0, sizeof(node[0]));
}

bool build(char *str) {
	int k;
	bool flag = false;
	int len = strlen(str);
	int root = 0;
	for(int i=0; i<len; i++) {
		k = str[i] - '0';
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
		bool flag = true;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", str);
			if(!flag)
				continue;
			if(!build(str)) {
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
