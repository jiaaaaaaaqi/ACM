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

ull n, m;
int cas, tol, T;

ull solve1(int A, int B) {
	ull tmp = 0;
	ll ans = 0;
	bool flag = 0;
	while(1) {
		for(int i=1; i<=A; i++) {
			tmp = tmp*2+1;
			if(tmp > m)	return ans;
		}
		if(flag && tmp>=n && tmp<=m)	ans++;
		for(int i=1; i<=B; i++) {
			tmp = tmp*2;
			if(tmp>m)	return ans;
		}
		if(tmp>=n && tmp<=m)	ans++;
		flag = true;
	}
}

bool ok(int A) {
	ull ans = 0;
	for(int i=1; i<=A; i++)
		ans = ans*2+1;
	return (ans>=n && ans<=m);
}

int main() {
	scanf("%llu%llu", &n, &m);
	int up = log2(1.0*m)+1;
	ull ans = 0;
	for(int A=1; A<=up; A++) {
		for(int B=1; B<=up; B++) {
			ans += solve1(A, B);
//			printf("%d %d %llu\n", A, B, ans);
		}
		if(ok(A))
			ans++;
	}
	printf("%llu\n", ans);
}
/*
1 9223372036854775807
*/
