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
const int    maxm = 1e7 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, k;
int cas, tol, T;

int pri[maxm];
bool ispri[maxm];
int a[maxn];

void handle() {
	tol = 0;
	mes(ispri, 1);
	mes(pri, 0);
	int mx = 1e7;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			for(int j=2; i*j<=mx; j++) {
				ispri[i*j] = 0;
			}
		}
	}
}

int main() {
	handle();
	scanf("%d%d%d", &n, &m, &k);
	int l = m-n+1;
	int cnt = 0;
	for(int i=n; i<=m; i++) {
		int p = lower_bound(pri+1, pri+1+tol, i)-pri;
		a[i] = pri[p+k-1];
	}
	int ans = -1, mn = 0;
	for(int i=l; i>=1; i--) {
		int b = m-i+1;
		mn = max(mn, a[b]+1-b);
		if(i >= mn) {
			ans = i;
		}
	}
	printf("%d\n", ans);
//	for(int i=1; i<=l; i++) {
//		bool flag = true;
//		for(int x=n; x<=m-i+1; x++) {
//			if(i < a[x]+1-x) {
//				flag = false;
//			}
//		}
//		if(flag) {
//			printf("%d\n", i);
//			break;
//		}
//	}
    return 0;
}
