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

typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

const int maxn = 200005;

int mod = 10007;
char str[maxn];
int nex[maxn];
int dp[maxn];

void init() {
	memset(str, 0, sizeof(str));
	memset(dp, 0, sizeof(dp));
}

void getnex() {
	int len = strlen(str);
	int i = 0;
	int j = -1;
	nex[0] = -1;
	while(i < len) {
		if(j == -1 || str[i] == str[j]) 
			nex[++i] = ++j;
		else
			j = nex[j];
	}
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int n;
		scanf("%d", &n);
		scanf("%s", str);
		getnex();
		/*
		for(int i=0; i<n; i++)
			printf("%d%c", nex[i], i == n-1 ? '\n' : ' ');
		*/
		dp[0] = 0;
		int ans = 0;
		for(int i=1; i<n; i++) {
			dp[i] = dp[nex[i]] + 1;
			ans += dp[i];
			ans %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}