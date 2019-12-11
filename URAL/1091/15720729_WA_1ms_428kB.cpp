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
#define lowbit(x) (x & (-x))
#define fi		first
#define	se		second
#define INOPEM  freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 1e18+100;
const int maxn = 1e5;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int ans = 0;
ll C[55][55];

void handle() {
	memset(C, 0, sizeof C);
	C[0][0] = 1;
	for(int i=1; i<=50; i++) {
		for(int j=0; j<=i; j++) {
			C[i][j] = j==0 ? 1 : C[i-1][j-1] + C[i-1][j];
		}
	}
}

void dfs(int idx, int num, bool flag) {
	if(n / num < m)	return ;
	if(ans > 10000)	return ;
	if(flag) 	ans += C[n/num][m];
	else		ans -= C[n/num][m];
	for(int i=idx+1; i<n; i++) {
		dfs(i, num * i, !flag);
	}
}

int main() {
	handle();
	while(~scanf("%d%d", &m, &n)) {
		ans = 0;
		for(int i=2; i<n; i++) {
			if(n/i < m)	break;
			dfs(i, i, 1);
			if(ans > 10000) {
				ans = 10000;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
