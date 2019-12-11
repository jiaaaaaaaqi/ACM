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
const double pi   = 4.0*atan(1.0);
const int    inf  = 0x3f3f3f3f;
const ll     INF  = 1e18+100;
const int    maxn = 1e5;
const int    maxm = 1e9+10;
const int    mod  = 1e9+7;
using namespace std;

int n, m;
int T, tol;
ull C[40][40];

void handle() {
	memset(C, 0, sizeof C);
	C[0][0] = 1;
	for(int i=1; i<=40; i++) {
		for(int j=0; j<=i; j++) {
			C[i][j] = j==0 ? 1 : C[i-1][j-1] + C[i-1][j];
		}
	}
}

int main() {
    handle();
    int a, b;
	while(~scanf("%d%d%d", &n, &a, &b)) {
		ull ans = 0;
		ull sum = 0;
		for(int i=0; i<=a; i++) {
			sum += C[n][i];
		}
		ans = sum;
		sum = 0;
		for(int i=0; i<=b; i++) {
			sum += C[n][i];			
		}
		ans = ans * sum;
		printf("%I64u\n", ans);
	}
    return 0;
}
