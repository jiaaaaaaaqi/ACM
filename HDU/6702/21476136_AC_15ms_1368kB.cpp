/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月24日 星期六 09时41分57秒
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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

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

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		ll A, B, C;
		C = 0;
		scanf("%lld%lld", &A, &B);
		for(int i=32; i>=1; i--) {
			int p1 = (A&(1<<(i-1))) ? 1 : 0;
			int p2 = (B&(1<<(i-1))) ? 1 : 0;
			if(p1 & p2)	C += (1ll<<(i-1));
		}
		printf("%lld\n", max(C, 1ll));
	}
    return 0;
}

