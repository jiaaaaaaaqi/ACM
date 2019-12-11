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

int mod = 20071027;
const int maxn = 400000 * 110;

int tol;
char str[300005];
char s[105];
int dp[300005];
int node[maxn][26];
bool vis[maxn];

void init() {
	tol = 1;
	memset(dp, 0, sizeof(dp));
	memset(vis, false, sizeof(vis));
	memset(node[0], 0, sizeof(node[0]));
}

void insert(char *str) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++)  {
		k = str[i] - 'a';
		if(node[root][k] == 0) {
			memset(node[tol], 0, sizeof(node[tol]));
			node[root][k] = tol++;
		}
		root = node[root][k];
	}
	vis[root] = true;
}

void calc(char *str, int len) {
	int k;
	for(int i=1; i<len; i++) {
		int root = 0;
		for(int j=i; j<len; j++) {
			k = str[j] - 'a';
			if(node[root][k] == 0)
				break;
			root = node[root][k];
			if(vis[root]) {
				dp[j] = (dp[i-1] + dp[j]) % mod;
//				printf("dp[%d] = %d\n", j, dp[j]);
			}
		}
	}
}

int main() {
	int cas = 1;
	while(~scanf("%s", str+1)) {
		init();
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", s);
			insert(s);
		}
		str[0] = '1';
		dp[0] = 1;
		int len = strlen(str);
		calc(str, len);
		int ans = dp[len-1];
		printf("Case %d: %d", cas++, ans % mod);
	}
	return 0;
}
