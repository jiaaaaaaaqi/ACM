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

vector<int> vv[maxn];
int fa[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			vv[i].clear();
		}
		for(int i=2; i<=n; i++) {
			int x;scanf("%d", &x);
			vv[x].pb(i);
			fa[i] = x;
		}
		int flag = false;
		for(int i=2; i<=n; i++) {
			if(vv[i].size() == 0) {
				if(vv[fa[i]].size()>1) {
					flag = true;
					break;
				}
				int cnt = 0;
				int p = i;
				while(1) {
					cnt++;
					if(p==0 || vv[p].size()>1)	break;
					p = fa[p];
				}
				if(cnt%2==0)	flag = true;
			}
		}
		if(flag)	printf("Takeru\n");
		else	printf("Meiya\n");
	}
	return 0;
}