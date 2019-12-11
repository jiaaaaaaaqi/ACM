#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 550;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int tol, T;

bool vis[15];
vector< pair<int, int> > vec[15];
int ans;

void dfs(int i, int tmp) {
	if(i == 12) {
		ans = max(tmp, ans);
		return;
	}
	for(auto j : vec[i]) {
		int w = j.fi;
		int v = j.se;
		if(vis[v])	continue;
		vis[v] = true;
		dfs(i+1, tmp + w);
		vis[v] = false;
	}
}

int main() {
    scanf("%d", &T);
    while(T--) {
		memset(vis, 0, sizeof vis);
		for(int i=1; i<=11; i++)	vec[i].clear();
		for(int i=1; i<=11; i++) {
			for(int j=1; j<=11; j++) {
				int x;
				scanf("%d", &x);
				if(x == 0)	continue;
				vec[i].push_back(make_pair(x, j));
			}
		}
//		for(int i=1; i<=11; i++) {
//			for(auto j : vec[i]) {
//				printf("%d %d %d\n", i, j.se, j.fi);
//			}
//		}
		ans = 0;
		dfs(1, 0);
		cout << ans << endl;
    }
    return 0;
}
