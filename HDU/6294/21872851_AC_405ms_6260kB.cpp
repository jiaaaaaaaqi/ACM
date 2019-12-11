/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sun 22 Sep 2019 04:26:24 PM CST
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

int a[maxn];
char s[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		scanf("%s", s+1);
		mes(a, 0);
		if(s[n-1] >= s[n])	a[n-1] = 1;
		else	a[n-1] = 0;
		for(int i=n-2; i>=1; i--) {
			if(s[i] == s[i+1])	a[i] = a[i+1];
			else	if(s[i] < s[i+1])	a[i] = 0;
			else	a[i] = 1;
		}
		for(int i=1; i<=n-1; i++) {
			if(a[i] == 1)	printf(">");
			else	printf("<");
		}
		printf("\n");
	}
	return 0;
}

