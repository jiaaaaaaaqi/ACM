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

const int maxn = 200010;

int tol;
int vis[maxn];
int node[maxn][26];
char ans[maxn][12];

void init() {
	tol = 1;
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	memset(node[0], 0, sizeof(node[0]));
}

void insert(char *str, int pos) {
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
	vis[root] = pos;
	return ;
}

int query(char *str) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++) {
		k = str[i] - 'a';
		if(node[root][k] == 0)
			return 0;
		root = node[root][k];
	}
	return vis[root];
}

int main() {
	init();
	char str[50] = {0};
	int num = 1;
	while(gets(str)) {
		if(str[0] == '\0')
			break;
		char str1[50];
		char str2[50];
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		sscanf(str, "%s %s", str1, str2);
		memset(str, 0, sizeof(str));
		strcpy(ans[num], str1);
		insert(str2, num);
		num++;
	}
	memset(str, 0, sizeof(str));
	while(~scanf("%s", str)) {
		int pos = query(str);
		if(pos == 0) {
			printf("eh\n");
		} else {
			printf("%s\n", ans[pos]);
		}
	}
	return 0;
}