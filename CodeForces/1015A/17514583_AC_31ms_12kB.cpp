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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 50005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
bool vis[105];
int ans[105];

int main() {
	memset(vis, 0, sizeof vis);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		for(int j=l; j<=r; j++)	vis[j] = true;
	}
	tol = 0;
	for(int i=1; i<=m; i++) {
		if(!vis[i])	ans[++tol] = i;
	}
	printf("%d\n", tol);
	for(int i=1; i<=tol; i++)	printf("%d%c", ans[i], i==tol ? '\n' : ' ');
    return 0;
}