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

const int maxn = 400010;

int tol;
int tim[maxn];
int node[maxn][26];
char ans[10010][50];

void init() {
	tol = 1;
	memset(tim, 0, sizeof(tim));
	memset(node[0], 0, sizeof(node[0]));
}

void insert(char *str) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++) {
		k = str[i] - 'a';
		if(node[root][k] == 0)  {
			memset(node[tol], 0, sizeof(node[tol]));
			node[root][k] = tol++;
		}
		root = node[root][k];
		tim[root]++;
	}
	return ;
}

void query(char *str) {
	printf("%s ", str);
	int i;
	int root = 0;
	int len = strlen(str);
	for(i=0; i<len; i++) {
		int k = str[i] - 'a';
		root = node[root][k];
		if(tim[root] == 1)
			break;
	}
	str[i+1] = '\0';
	printf("%s\n", str);
	return ;
}

int main() {
	init();
	int num = 0;
	while(scanf("%s", ans[num]) != EOF) {
		insert(ans[num]);
		num++;
	}
	for(int i=0; i<num; i++) {
		query(ans[i]);
	}
	return 0;
}