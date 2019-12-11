/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年12月04日 星期三 12时58分24秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], p[40];

bool check(int R) {
	for(int i=1; i<=31; i++) {
		if(R&(1<<(i-1)) && p[i]) {
			int cnt = 0, ans = 0;
			for(int j=0; j<n; j++) {
				ans = (ans|a[(p[i]+j)])&R;
				if(ans == R) cnt++, ans = 0;	}
			if(cnt >= m)	return true;
		}
	}
	return false;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	mes(p, 0);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]), a[i+n] = a[i];
		for(int j=1; j<=31; j++) {
			if(a[i]&(1<<(j-1)))	p[j] = i;
		}
	}
	int ans = 0;
	for(int i=31; i>=1; i--) {
		if(check(ans|(1<<(i-1))))	ans |= (1<<(i-1));
	}
	printf("%d\n", ans);
	return 0;
}

