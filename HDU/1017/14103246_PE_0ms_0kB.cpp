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

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 10005;
const int mod = 10007;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int cas = 1;
		int n, m;
		while(scanf("%d%d", &n, &m), n||m) {
			int ans = 0;
			for(int b=1; b<n; b++) {
				for(int a=1; a<b; a++) {
					int x = a * a + b * b + m;
					int y = a * b;
					if(x % y == 0)
						ans++;
				}
			}
			printf("Case %d: %d\n", cas++, ans);
		}
		printf("\n");
	}
	return 0;
} 