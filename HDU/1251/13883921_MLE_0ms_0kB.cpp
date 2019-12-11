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

const int maxn = 1000005;

int num[maxn];
int node[maxn][26];
int tol = 1;


void update(char *str) {
	int len=strlen(str);
	int root=0,k;
	for(int i=0; i<len; ++i) {
		k=str[i]-'a';
		if(node[root][k]==0) {
			num[tol]=0;
			node[root][k]=tol++;
		}
		num[node[root][k]]++;
		root=node[root][k];
	}
}

int query(char *str) {
	int root = 0;
	int len = strlen(str);
	for(int i=0; i<len; i++) {
		int k = str[i] - 'a';
		if(node[root][k]) {
			root = node[root][k];
		} else {
			return 0;
		}
	}
	return num[root];
}

int main() {
	tol = 1;
	memset(num, 0, sizeof(num));
	memset(node, 0, sizeof(node));
	char str[15];
	while(1) {
		gets(str);
		if(str[0] == '\0')
			break;
		update(str);
	}
	while(~scanf("%s", str)) {
		int ans = query(str);
		printf("%d\n", ans);
	}
}