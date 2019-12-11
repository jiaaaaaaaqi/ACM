#include<map>
#include<set>
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
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 100002;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int tol, T;

ll dp[2][maxn];
int a[2][maxn];
int b[2][maxn];

void init() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(dp, 0, sizeof dp);
}

int main() {
    scanf("%d", &T);
    while(T--) {
		init();
		int l0, l1, s0, s1;
		scanf("%d%d%d%d%d", &n, &l0, &l1, &s0, &s1);
		for(int i=1; i<n; i++)	scanf("%d", a[0] + i);
		for(int i=1; i<n; i++)	scanf("%d", a[1] + i);
		for(int i=1; i<n; i++)	scanf("%d", b[0] + i);
		for(int i=1; i<n; i++)	scanf("%d", b[1] + i);
		dp[0][1] = l0;
		dp[1][1] = l1;
		for(int i=1; i<n; i++) {
			dp[0][i+1] = min(dp[0][i] + a[1][i], dp[1][i] + b[0][i]);
			dp[1][i+1] = min(dp[0][i] + a[0][i], dp[1][i] + b[1][i]);
		}
		ll ans = min(dp[0][n] + s0, dp[1][n] + s1);
		cout << ans << endl;
    }
    return 0;
}
