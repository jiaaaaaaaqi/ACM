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

int pri[maxn];
bool ispri[maxn];
int ans[maxn];

int solve(int n) {
	int cnt = 0, ans = 1;
	for(int i=1; pri[i]*pri[i]<=n; i++) {
		if(n%pri[i] == 0) {
			cnt++;
			int x = 0;
			while(n%pri[i] == 0) {
				x++;
				n /= pri[i];
			}
			ans = ans*(x+1);
		}
	}
	if(n>1)	ans = ans*2, cnt++;
	return ans-cnt;
}

void handle() {
	int mx = 2e6;
	tol = 0;
	mes(pri, 0), mes(ispri, 1);
	for(int i=2; i<=mx; i++) {
		if(ispri[i])	pri[++tol] = i;
		for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0)	break;
		}
	}
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

