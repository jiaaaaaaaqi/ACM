/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Wed 18 Sep 2019 08:48:42 PM CST
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
	int x, y, k, t;
} node[maxn];

vector<int> vx, vy;

bool ok(int x, int y) {
	for(int i=1; i<=n; i++) {
		if((abs(x-node[i].x) + abs(y-node[i].y)) % node[i].k != node[i].t)
			return false;
	}
	return true;
}

ll calc(int x, int y) {
	ll d = y-x;
	if(d < 0)	return 0;
	return d/60+1;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		vx.clear(), vy.clear();
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d%d", &node[i].x, &node[i].y, &node[i].k, &node[i].t);
			vx.pb(node[i].x), vy.pb(node[i].y);
		}
		vx.pb(-1), vy.pb(-1);
		vx.pb(m), vy.pb(m);
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		vx.erase(unique(vx.begin(), vx.end()), vx.end());
		vy.erase(unique(vy.begin(), vy.end()), vy.end());
		int totx = vx.size(), toty = vy.size();
		ll ans = 0;
		for(int i=0; i<totx-1; i++) {
			for(int j=0; j<toty-1; j++) {
				int x = vx[i]+1, y = vy[j]+1;
				for(int f=0; f<60; f++) {
					for(int g=0; g<60; g++) {
						if(ok(x+f, y+g))	ans += calc(x+f, vx[i+1]) * calc(y+g, vy[j+1]);
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

