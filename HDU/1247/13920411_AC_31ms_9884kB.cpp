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

const int maxn = 50010 * 26;

int tol;
int node[maxn][26];
char str[50010][50];
bool vis[maxn];
char tmp1[50];
char tmp2[50];

void init() {
	tol = 1;
	memset(vis, 0, sizeof(vis));
	memset(str, 0, sizeof(str));
	memset(node[0], 0, sizeof(node[0]));
}

void build(char *str) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++) {
		k = str[i] - 'a';
		if(node[root][k] == 0) {
			memset(node[tol], 0, sizeof(node[tol]));
			node[root][k] = tol++;
		}
		root = node[root][k];
	}
	vis[root] = true;
}

bool query(char *str) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++) {
		k = str[i] - 'a';
		if(node[root][k] == 0)
			return false;
		root = node[root][k];
	}
	if(vis[root])
		return true;
	else
		return false;
}

int main() {
	int n = 0;
	init();
	while(~scanf("%s", str[n])) {
		build(str[n]);
		n++;
	}
	int ans = 0;
	for(int i=0; i<n; i++) {
		int len = strlen(str[i]);
		for(int j=1; j<len-1; j++) {
			memset(tmp1, 0, sizeof(tmp1));
			memset(tmp2, 0, sizeof(tmp2));
			strncpy(tmp1, str[i], j);
			strncpy(tmp2, str[i]+j, len-j);
			if(query(tmp1) && query(tmp2)) {
				printf("%s\n", str[i]);
				break;
			}
		}
	}
	return 0;
}
