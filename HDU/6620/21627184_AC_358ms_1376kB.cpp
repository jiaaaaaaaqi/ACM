/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 04 Sep 2019 04:17:35 PM CST
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

int a[20];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		n = 4;
		int p = 0;
		int pi, pj;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d", &a[(i-1)*4+j]);
				if(a[(i-1)*4+j] == 0)	p = (i-1)*4+j, pi = i, pj = j;
			}
		}
		int ans = 0;
		for(int i=1; i<=16; i++) {
			if(a[i] == 0)	continue;
			for(int j=1; j<i; j++) {
				if(a[j] == 0)	continue;
				if(a[j] > a[i])	ans = !ans;
			}
		}
		bool flag = 0;
		if(ans == 0 && (pi==4||pi==2))	flag = 1;
		if(ans == 1 && (pi==1||pi==3))	flag = 1;
		if(flag)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}

