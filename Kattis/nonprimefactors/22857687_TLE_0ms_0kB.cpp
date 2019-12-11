/*************************************************************** 
	> File Name		: C.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Wed 13 Nov 2019 09:59:57 PM CST
 ***************************************************************/

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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int ans[maxn];

int solve(int n) {
	int cnt = 0, ans = 1;
	for(int i=2; i*i<=n; i++) {
		if(n%i == 0) {
			cnt++;
			int x = 0;
			while(n%i == 0) {
				x++;
				n /= i;
			}
			ans = ans*(x+1);
		}
	}
	if(n>1)	ans = ans*2, cnt++;
	return ans-cnt;
}

void handle() {
	int mx = 2e6;
	for(int i=2; i<=mx; i++) {
		ans[i] = solve(i);
	}
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}

