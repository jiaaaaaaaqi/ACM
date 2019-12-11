/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 13 Sep 2019 11:32:01 PM CST
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

int a[maxn], b[maxn];
int sta[maxn], pos[maxn];
bool vis[maxn], notexit[maxn];
int res[maxn];

int solve() {
	for(int i=1; i<=n; i++) {
		vis[i] = pos[i] = 0;
	}
	int top = 0;
	for(int i=1; i<=n; i++) {
		if(notexit[i])	continue;
		if(top==0 || a[i]>sta[top]) {
			sta[++top] = a[i];
			pos[i] = top;
		} else {
			int p = lower_bound(sta+1, sta+1+top, a[i])-sta;
			sta[p] = a[i];
			pos[i] = p;
		}
	}
	int ans = top;
	for(int i=n; top&&i>=1; i--) {
		if(notexit[i])	continue;
		if(pos[i] == top) {
			vis[i] = true;
			top --;
		}
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		mes(notexit, 0);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=1; i<=n; i++) {
			scanf("%d", &b[i]);
		}
		int ans = solve();
		for(int i=n; i>=1; i--) {
			if(vis[b[i]])	ans = solve();
			notexit[b[i]] = 1;
			res[i] = ans;
		}
		for(int i=1; i<=n; i++) {
			printf("%d%c", res[i], i==n ? '\n' : ' ');
		}
	}
	return 0;
}

