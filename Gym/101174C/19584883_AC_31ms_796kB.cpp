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

int n, m;
int cas, tol, T;

ll so[maxn];

int main() {
	int d;
	so[0] = 0;
	for(int i=1; i<=1000; i++) {
		so[i] = so[i-1] + i;
	}
	scanf("%d%d%d", &d, &n, &m);
	for(int i=0; i<=n; i++) {
		int nn = n-i;
		int mm = m+i;
		if(nn < 4)	nn = 0;
		if(mm < 3)	mm = 0;
		int p1, p2;
		if(nn >= 4)
			p1 = lower_bound(so+1, so+1+1000, nn+6)-so;
		else
			p1 = 3;
		if(p1 == 3) {
			for(int j=3-d; j>=1; j--) {
				int x = 0;
				if(j==3) {
					x = 3;
				}
				if(mm == x) {
					printf("%d\n", i);
					return 0;
				}
			}
		} else {
			int age = p1-d;
			if(mm+3 == so[age]) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	return 0;
}
