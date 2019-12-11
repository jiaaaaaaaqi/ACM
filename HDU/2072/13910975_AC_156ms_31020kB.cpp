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

int tol, num;
int node[maxn][26];
char str[maxn];
char ans[maxn];
bool vis[maxn];

void init() {
	num = 0;
	tol = 1;
	memset(str, 0, sizeof(str));
	memset(vis, 0, sizeof(vis));
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
	if(!vis[root])
		num++;
	vis[root] = true;
	return ;
}

int main() {
	while(1) {
		init();
		gets(str);
		if(strcmp(str, "#") == 0)
			break;
		int len = strlen(str);
		int j = 0;
		for(int i=0; i<=len; i++) {
			if(islower(str[i])) {
				ans[j++] = str[i];
			} else {
				if(j == 0)
					continue;
				ans[j] = '\0';
				build(ans);
				memset(ans, 0, sizeof(ans));
				j = 0;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}
