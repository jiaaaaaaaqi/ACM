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
int maxsum;
string ans;
char str[110];
int deg[maxn];
int num[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
char digit[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int node[maxn][26];

void init() {
	tol = 1;
	memset(deg, 0, sizeof(deg));
	memset(node[0], 0, sizeof(node[0]));
}

void insert(char *str, int val) {
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
		deg[root] += val;
	}
}

void dfs(int be, int en, int root, string s) {
	if(be == en) {
		if(deg[root] > maxsum) {
			maxsum = deg[root];
			ans = s;
		}
	}
	int k = str[be] - '0';
	int len = num[k];
	for(int i=0; i<len; i++) {
		int x = digit[k][i] - 'a';
		if(node[root][x] == 0)
			continue;
		dfs(be+1, en, node[root][x], s+digit[k][i]);
	}
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			int val;
			scanf("%s %d", str, &val);
			insert(str, val);
		}
		scanf("%d", &n);
		printf("Scenario #%d:\n", cas++);
		for(int i=0; i<n; i++) {
			scanf("%s", str);
			bool flag = false;
			int len = strlen(str);
			for(int j=1; j<len; j ++) {
				if(flag) {
					printf("MANUALLY\n");
					continue;
				}
				maxsum = 0;
				ans.clear();
				dfs(0, j, 0, "\0");
				if(maxsum == 0) {
					printf("MANUALLY\n");
					flag = true;
				} else {
					cout << ans << endl;
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

/*
2
7
another 5
contest 6
follow 3
give 13
integer 6
new 14
program 4
1
6391
*/
