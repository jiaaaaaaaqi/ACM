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

const int maxn = 100002;

char str[20];
int node[maxn][5];
bool vis[maxn];
int tol;

void init() {
	tol = 1;
	memset(vis, 0, sizeof(vis));
	memset(node[0], 0, sizeof(node[0]));
}

bool build(char *str) {
	int len = strlen(str);
	int root = 0;
	int k;
	bool flag = false;
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
	int cas = 1;
	init();
	while(~scanf("%s", str)) {
		bool flag = true;
		build(str);
		while(1) {
			scanf("%s", str);
			if(str[0] == '9')
				break;
			if(flag) {
				if(!build(str)) {
					flag = false;
				}
			}
		}
		if(flag)
			printf("Set %d is immediately decodable\n", cas++);
		else
			printf("Set %d is not immediately decodable\n", cas++);
		init();
	}
	return 0;
}
