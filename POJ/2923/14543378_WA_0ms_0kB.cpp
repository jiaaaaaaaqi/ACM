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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 11;
const int maxm = 1 << 11;
const int mod = 200;
using namespace std;

int n, m, tol;
int c1, c2;
int state[maxm];
int dp[maxm];
int num[maxn];
bool vis[maxm];

void init() {
	tol = 0;
    memset(dp, inf, sizeof dp);
    memset(num, 0, sizeof num);
	memset(vis, 0, sizeof vis);
}

bool ok(int st) {
	memset(vis, 0, sizeof vis);
	vis[0] = 1;
	int sum = 0;
	for(int i=0; i<n; i++) {
		if(st & (1<<i)) {
			sum += num[i];
			for(int j=c1; j>=num[i]; j--) {
				if(vis[j - num[i]]) {
					vis[num[i]] = 1;
				}
			}
		}
	}
	if(sum > c1 + c2)	return 0;
	for(int i=0; i<=c1; i++) {
		if(c1 - i <= c2 && vis[i]) {
			return 1;
		}
	}
	return 0;
}

void handle() {
	for(int i=0; i<(1<<n); i++) {
		if(!ok(i))	continue;
		state[tol++] = i;
	}
}

int main() {
    int T;
    int cas = 1;
    scanf("%d", &T);
    while(T--) {
		init();
		scanf("%d%d%d", &n, &c1, &c2);
		for(int i=0; i<n; i++)		scanf("%d", &num[i]);
		handle();
		dp[0] = 0;
		for(int i=0; i<tol; i++) {
			for(int j=(1<<n)-1; j>=num[i]; j--) {
				if(dp[j] == inf)	continue;
				if(j & state[i])	continue;
				dp[j | state[i]] = min(dp[j | state[i]], dp[j] + 1);
			}
		}
		printf("Scenario #%d:\n", cas++);
		printf("%d\n", dp[(1<<n)-1]);
    }
    return 0;
}
