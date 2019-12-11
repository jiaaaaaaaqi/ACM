#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 120005;
const int maxm = 1 << 29;
using namespace std;

int n, m, tol;
int num[maxn];
map<int, int> cnt;
map<int, bool> vis;

int main() {
    while(~scanf("%d", &n)) {
		if(n == 1) {
			scanf("%d", &num[0]);
			printf("1\n");
			continue;
		}
		int ans = n;
		vis.clear();
		cnt.clear();
		memset(num, 0, sizeof num);
		for(int i=1; i<=n; i++) {
			scanf("%d", &num[i]);
			vis[num[i]] = true;
			cnt[num[i]]++;
		}
		for(int i=1; i<=n; i++) {
			int x = num[i];
			for(int j=1; j<=30; j++) {
				int x = (1 << j);
				if(x == 2 * num[i] && cnt[num[i]] == 1)	continue;
				if(vis[x - num[i]]) {
					ans--;
					break;
				}
			}
		}
		printf("%d\n", ans);
    }
    return 0;
}