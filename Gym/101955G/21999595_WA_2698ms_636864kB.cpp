/*************************************************************** 
  > File Name    : a.cpp
  > Author       : Jiaaaaaaaqi
  > Created Time : Mon 30 Sep 2019 10:38:35 PM CST
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
const int    maxn = 6e3 + 10;
const int    maxm = 1e7;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll maps[maxn][maxn];
int cnt[maxn][maxn];
vector<pii> vis;
vector<pii> vv[maxm+10];

bool ok(int x) {
	if(x<0 || x>6000)	return false;
	return true;
}

inline void read(int &x) {
	x = 0;
    char ch = getchar(); int f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
	x *= f;
}

int main() {
	// freopen("in", "r", stdin);
	for(int i=0; i<=maxm; i++)	vv[i].clear();
	for(int i=1; i<=3200; i++) {
		for(int j=1; j<=3200; j++) {
			if(i*i+j*j <= maxm)
				vv[i*i+j*j].pb(make_pair(i, j));
		}
	}
	read(T);
	cas = 1;
	while(T--) {
		vis.clear();
		printf("Case #%d:\n", cas++);
		read(n), read(m);
		for(int i=1, x, y, w; i<=n; i++) {
			scanf("%d%d%d", &x, &y, &w);
			maps[x][y] += w;
			cnt[x][y] = 1;
			vis.pb(make_pair(x, y));
		}
		ll ans = 0;
		int id, x, y, w, k;
		while(m--) {
			read(id), read(x), read(y);
			x = (x+ans)%6000+1;
			y = (y+ans)%6000+1;
			if(id == 1) {
				read(w);
				cnt[x][y]++;
				maps[x][y] += w;
				vis.pb(make_pair(x, y));
			} else if(id == 2) {
				maps[x][y] = 0;
				cnt[x][y] = 0;
			} else if(id == 3) {
				read(k), read(w);
				int tx, ty;
				for(auto i : vv[k]) {
					tx = x+i.fi, ty = y+i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
					tx = x-i.fi, ty = y+i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
					tx = x+i.fi, ty = y-i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
					tx = x-i.fi, ty = y-i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
				}
				tx = x, ty = y+w;
				if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
				tx = x, ty = y-w;
				if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
				tx = x+w, ty = y;
				if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
				tx = x-w, ty = y;
				if(ok(tx) && ok(ty) && maps[tx][ty])	maps[tx][ty] += w*cnt[tx][ty];
			} else {
				read(k);
				int tx, ty;
				ans = 0;
				for(auto i : vv[k]) {
					tx = x+i.fi, ty = y+i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
					tx = x-i.fi, ty = y+i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
					tx = x+i.fi, ty = y-i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
					tx = x-i.fi, ty = y-i.se;
					if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
				}
				tx = x, ty = y+w;
				if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
				tx = x, ty = y-w;
				if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
				tx = x+w, ty = y;
				if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
				tx = x-w, ty = y;
				if(ok(tx) && ok(ty) && maps[tx][ty])	ans += maps[tx][ty]*cnt[tx][ty];
				printf("%lld\n", ans);
			}
		}
		for(auto s : vis)	maps[s.fi][s.se] = 0, cnt[s.fi][s.se] = 0;
	}
	return 0;
}

