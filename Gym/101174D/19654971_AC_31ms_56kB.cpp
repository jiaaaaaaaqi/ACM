#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, A, B, D;
int cas, tol, T;
bool vis[100];
ll C[55][55];
double dp[12][12][12];

void handle() {
	C[0][0] = 1;
	C[1][0] = C[1][1] =1;
	for(int i=2; i<=50; i++) {
		for(int j=0; j<=i; j++) {
			C[i][j] = j==0 ? 1 : C[i-1][j-1] + C[i-1][j];
		}
	}
}

void dfs(int x, int y, int z) {
	if(x+y==m || y+z==m) {
		dp[x][y][z] = 0;
		return ;
	}
	if(dp[x][y][z] != -1.0)	return ;
	double t = 0, sum = 0;
	for(int a=0; a<=A-x; a++) {
		for(int b=0; b<=B-y; b++) {
			for(int c=0; c<=A-z; c++) {
				if(a+b+c > D)	continue;
				if(a==0 && b==0 && c==0) {
					t = 1.0*C[x+y+z+n-tol][D-a-b-c]/C[n][D];
					continue;
				} else {
					dfs(x+a, y+b, z+c);
					sum += 1.0*C[A-x][a]*C[B-y][b]*C[A-z][c]*C[x+y+z+n-tol][D-a-b-c]*dp[x+a][y+b][z+c]/C[n][D];
				}
			}
		}
	}
	dp[x][y][z] = (1.0+sum)/(1.0-t);
	return ;
}

int main() {
	scanf("%d%d%d", &n, &D, &m);
	handle();
	mes(vis, 0);
	for(int i=1, x; i<=m; i++) {
		scanf("%d", &x);
		vis[x] = true;
	}
	A = B = 0;
	for(int i=1, x; i<=m; i++) {
		scanf("%d", &x);
		if(vis[x])	B++;
		else	A++;
	}
//	printf("%d %d\n", A, B);
	tol = 2*A+B;
	for(int i=0; i<=A; i++) {
		for(int j=0; j<=B; j++) {
			for(int k=0; k<=A; k++) {
				dp[i][j][k] = -1.0;
			}
		}
	}
	dfs(0, 0, 0);
	printf("%.5f\n", dp[0][0][0]);
	return 0;
}
