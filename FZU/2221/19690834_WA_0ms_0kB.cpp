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

bool solve() {
	int a1 = 0, b1 = n/2, c1 = n-n/2;
	int a2 = 1, b2 = m-1, c3 = 0;
	if(b1 >= b2)	return true;
	else	return false;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		if(n<=3 || m<=3) {
			bool flag = true;
			if(n==1 && m==2)	flag = false;
			if(n==1 && m==3)	flag = false;
			if(n==2 && m==3)	flag = false;
			if(flag)	printf("Yes\n");
			else	printf("No\n");
		} else {
			bool ans = solve();
			if(ans)	printf("Yes\n");
			else	printf("No\n");
		}
	}
	return 0;
}
