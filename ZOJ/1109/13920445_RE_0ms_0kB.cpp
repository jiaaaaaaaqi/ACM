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

const int maxn = 100005 * 26;

int tol;
int vis[maxn];
int node[maxn][26];
char ans[100005][12];

void init() {
	tol = 1;
	memset(vis, 0, sizeof(vis));
	memset(node[0], 0, sizeof(node[0]));
	memset(ans, 0, sizeof(ans));
}

void insert(char *str, int pos) {
	int len = strlen(str);
	int root = 0;
	int k = 0;
	for(int i=0; i<len; i++) {
		k = str[i] - 'a';
		if(node[root][k] == 0) {
			memset(node[tol], 0, sizeof(node[tol]));
			node[root][k] = tol++;
		}
		root = node[root][k];
	}
	vis[root] = pos;
}

int query(char *str) {
	int len = strlen(str);
	int root = 0;
	int k = 0;
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
	char str[50];
	int n = 0;
	while(1) {
		memset(str, 0, sizeof(str));
		gets(str);
		if(str[0] == '\0')
			break;
		char str1[15];
		char str2[15];
		int len = strlen(str);
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		int i;
		for(i=0; i<len; i++) {
			if(str[i] == ' ')
				break;
			str1[i] = str[i];
		}
		while(str[i++] == ' ');
		i--;
		strncpy(str2, str+i, len-i);
//		printf("%s %s\n", str1, str2);
		strcpy(ans[n], str1);
		insert(str2, n);
		n++;
	}
	memset(str, 0, sizeof(str));
	while(gets(str) != NULL) {
		int pos = query(str);
		if(pos == 0) {
			printf("eh\n");
		} else{
			printf("%s\n", ans[pos]);
		}
		memset(str, 0, sizeof(str));
	}
	return 0;
}
