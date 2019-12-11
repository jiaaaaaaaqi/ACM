/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月21日 星期日 18时29分54秒
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
	scanf("%d%d", &n, &m);
	if(n==0 && m==0) {
		printf("0\n");
		return 0;
	}
	int mx = max(abs(n), abs(m));
	int ans = mx*4;
	if(n==mx) {
		if(m==-mx) {
			ans = ans;
		} else if(m == (-mx+1)) {
			ans = ans-4;
		} else {
			ans = ans-3;
		}
	} else if(n == -mx) {
		if(m==mx) {
			ans = ans-2;
		} else {
			ans = ans-1;
		}
	} else {
		if(m == mx) {
			if(n==mx) {
				ans = ans-3;
			} else {
				ans = ans-2;
			}
		} else if(m == -mx)	{
			if(n==-mx) {
				ans = ans-1;
			} else {
				ans = ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

