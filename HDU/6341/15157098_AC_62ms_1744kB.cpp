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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+10;
const int maxm = 10000007;
const int mod = 1e9+7;
using namespace std;

int n, m, tol, T;
char s[20];
int e[20][20];
int t[20][20];
bool vis[30];
int ans;

void init() {
    ans = inf;
    memset(e, 0, sizeof e);
    memset(t, 0, sizeof t);
}

void change(int x, int y) {
	memset(t, 0, sizeof  t);
    for(int i1=4*x-3, j2=4*y-3; i1<=4*x; i1++, j2++) {
        for(int j1=4*y-3, i2=4*x; j1<=4*y; j1++, i2--) {
            t[i1][j1] = e[i2][j2];
        }
    }
    for(int i=4*x-3; i<=4*x; i++) {
        for(int j=4*y-3; j<=4*y; j++) {
            e[i][j] = t[i][j];
        }
    }
}

bool check(int x, int y) {
    for(int i=4*x-3; i<=4*x; i++) {
        memset(vis, 0, sizeof vis);
        for(int j=1; j<=4*y; j++) {
            if(vis[e[i][j]])	return false;
            vis[e[i][j]] = true;
        }
    }
    for(int j=4*y-3; j<=4*y; j++) {
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=4*x; i++) {
            if(vis[e[i][j]])	return false;
            vis[e[i][j]] = true;
        }
    }
    return true;
}

void dfs(int x, int y, int cnt) {
	if(y>4) {
		ans = check(4, 4) ? min(ans, cnt) : ans;
		return ;
	}
	if(cnt > ans)	return ;
	for(int i=0; i<4; i++) {
		if(i)	change(x, y);
		if(!check(x, y))	continue;
		if(x == 4)	dfs(1, y+1, cnt + i);
		else	dfs(x+1, y, cnt + i);
	}
	change(x, y);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        char ch;
        for(int i=1; i<=16; i++) {
            scanf("%s", s+1);
            for(int j=1; j<=16; j++) {
                ch = s[j];
                e[i][j] = isdigit(ch) ? ch - '0' : ch - 'A' + 10;
            }
        }
//		for(int i=1; i<=16; i++)	for(int j=1; j<=16; j++)	printf("%d%c", e[i][j], j==16 ? '\n' : ' ');
//		change(2, 1);
//		cout << endl;
//		for(int i=1; i<=16; i++)	for(int j=1; j<=16; j++)	printf("%d%c", e[i][j], j==16 ? '\n' : ' ');
		dfs(1, 1, 0);
		printf("%d\n", ans);
    }
    return 0;
}
