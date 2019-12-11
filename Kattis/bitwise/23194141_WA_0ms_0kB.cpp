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

int a[maxn], l[maxn], p[40];
int cnt[maxn];

bool check(int R) {
	mes(p, inf);
	int ans = 0;
	for(int i=1; i<=n+n; i++) {
		cnt[i] = 0, l[i] = 0;
		for(int j=1; j<=31; j++) {
			if((a[i]&(1<<(j-1))) && (R&(1<<(j-1))))
				p[j] = i, ans |= (1<<(j-1));
		}
		if(ans == R) {
			l[i] = i;
			for(int j=1; j<=31; j++) l[i] = min(l[i], p[j]);
		}
	}
	// for(int i=1; i<=n+n; i++)	printf("%d%c", l[i], i==n+n ? '\n':' ');
	ans = 0;
	for(int i=1; i<=n; i++) {
		if(l[i] >= 1) {
			if(!cnt[l[i]])	ans++;
			cnt[l[i]]++;
		}
		if(ans >= m)	return true;
	}
	int L = 1;
	for(int i=n+1; i<=n+n; i++) {
		while(L<=i && l[L]<=i-n) {
			if(l[L] == i-n) {
				cnt[l[L]]--;
				if(!cnt[l[L]])	ans--;
			} 
			L++;
		}
		if(l[i] >= i-n+1) {
			if(!cnt[l[i]])	ans++;
			cnt[l[i]]++;
		}
		if(ans >= m)	return true;
	}
	return false;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)	scanf("%d", &a[i]), a[i+n] = a[i];
	int ans = 0;
	for(int i=31; i>=1; i--) {
		if(check(ans | (1<<(i-1))))	ans |= (1<<(i-1));
	}
	printf("%d\n", ans);
	return 0;
}

