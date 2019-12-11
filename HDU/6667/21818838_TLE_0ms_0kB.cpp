/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年09月19日 星期四 21时12分18秒
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

struct Node {
	int a, b;
	bool operator < (Node x) const {
		return a>x.a;
	}
} node[maxn];

int main() {
    // freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &node[i].a, &node[i].b);
		}
		sort(node+1, node+1+n);
		queue<int> q;
		ll ans = 0;
		int now = 2;
		for(int i=1; i<=n; i++) {
			while(now<=n && node[i].a) {
				if(node[i].a > node[now].b) {
					ans += node[now].b;
					node[i].a -= node[now].b;
					node[now].b = 0;
					now++;
				} else {
					ans += node[i].a;
					node[now].b -= node[i].a;
					node[i].a = 0;
				}
			}

			while(node[i].a && !q.empty()) {
				int x = q.front();
				if(node[i].a > node[x].b) {
					ans += node[x].b;
					node[i].a -= node[x].b;
					node[x].b = 0;
				} else {
					ans += node[i].a;
					node[x].b -= node[i].a;
					node[i].a = 0;
					q.push(x);
				}
			}
			if(node[i].b)	q.push(i);
		}
		printf("%lld\n", ans);
	}
   return 0;
}

