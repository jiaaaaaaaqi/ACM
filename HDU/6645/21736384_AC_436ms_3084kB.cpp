/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 13 Sep 2019 10:12:06 PM CST
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

struct Node {
	int id, val;
	bool operator < (Node a) const {
		return val<a.val;
	}
};
int a[maxn];
int ind[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			if(i != 1)	ind[i/2]++;
		}
		priority_queue<Node> q;
		for(int i=1; i<=n; i++) {
			if(ind[i] == 0) {
				q.push(Node{ i, a[i] });
			}
		}
		ll ans[2] = { 0 };
		int flag = 0;
		while(!q.empty()) {
			Node now = q.top();
			q.pop();
			ans[flag] += now.val;
			flag = !flag;
			ind[now.id/2]--;
			if(ind[now.id/2] == 0) {
				q.push(Node{ now.id/2, a[now.id/2] });
			}
		}
		printf("%lld %lld\n", ans[0], ans[1]);
	}
	return 0;
}

