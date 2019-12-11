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

const int maxn = 55;

int num[maxn];
int ans[maxn];
map<int, bool> vis;

void init() {
	memset(num, 0, sizeof(num));
	memset(ans, 0, sizeof(ans));
	vis.clear();
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		init();
		for(int i=0; i<n; i++) 
			scanf("%d", &num[i]);
		int m = 0;
		for(int i=n-1; i>=0; i--) {
			if(!vis[num[i]]) {
				ans[m++] = num[i];
			}
			vis[num[i]] = true;
		}
		printf("%d\n", m);
		for(int i=m-1; i>=0; i--) {
			printf("%d%c", ans[i], i==0 ? '\n' : ' ');
		}
	}
	return 0;
}