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

const int maxn = 1000005;
const int maxm = 10005;

int n, m;
int num[maxn];
int ans[maxm];
int nex[maxm];

void init() {
	memset(num, 0, sizeof(num));
	memset(ans, 0, sizeof(ans));
	memset(nex, 0, sizeof(nex));	
}

void getnex() {
	int j = 0;
	int k = -1;
	nex[0] = -1;
	while(j < m) {
		if(k == -1 || ans[j] == ans[k]) {
			j++;
			k++;
			nex[j] = k;
		} else {
			k = nex[k];
		}
	}
}

int kmp() {
	getnex();
	int i = 0, j = 0;
	while(i < n) {
		if(j == -1 || num[i] == ans[j]) {
			i++;
			j++;
		} else {
			j = nex[j];
		}
		if(j == m)
			return i - m + 1;
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) {
			scanf("%d", &num[i]);
		}
		for(int i=0; i<m; i++) {
			scanf("%d", &ans[i]);
		}
		int res = kmp();
		printf("%d\n", res);
	}
	return 0;
}