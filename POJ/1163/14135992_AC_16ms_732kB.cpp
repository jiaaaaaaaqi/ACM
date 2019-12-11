#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
using namespace std;

int n;
int num[105][105];

void init() {
	memset(num, 0, sizeof(num));
}

int solve() {
	for(int i=n-1; i>=1; i--) {
		for(int j=1; j<=i; j++) {
			num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);
		}
	}
	return num[1][1];
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				scanf("%d", &num[i][j]);
			}
		}
		int ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}
