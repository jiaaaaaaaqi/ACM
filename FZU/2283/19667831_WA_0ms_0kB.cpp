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
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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

char s[10][10], c, cc;

bool ok(int id) {
	if(id == 1) {
		for(int i=1; i<=3; i++) {
			if(s[i][1]==c && s[i][2]==c && s[i][3]==c)
				return true;
		}
		for(int j=1; j<=3; j++) {
			if(s[1][j]==c && s[2][j]==c && s[3][j]==c)
				return true;
		}
		if(s[1][1]==c && s[2][2]==c && s[3][3]==c)
			return true;
		if(s[1][3]==c && s[2][2]==c && s[3][1]==c)
			return true;
	} else {
		for(int i=1; i<=3; i++) {
			if(s[i][1]==cc && s[i][2]==cc && s[i][3]==cc)
				return true;
		}
		for(int j=1; j<=3; j++) {
			if(s[1][j]==cc && s[2][j]==cc && s[3][j]==cc)
				return true;
		}
		if(s[1][1]==cc && s[2][2]==cc && s[3][3]==cc)
			return true;
		if(s[1][3]==cc && s[2][2]==cc && s[3][1]==cc)
			return true;		
	}
	return false;
}

bool dfs(int x, int y, int cnt) {
	if(x==4)	return false;
	if(cnt == 4)	return false;
	if(s[x][y] != '.') {
		if(y==n)	return dfs(x+1, 1, cnt);
		else	return dfs(x, y+1, cnt);
	}
	if(cnt&1) {
		if(y==n) {
			if(!dfs(x+1, 1, cnt))	return true;
		} else {
			if(!dfs(x, y+1, cnt))	return true;
		}
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				if(s[i][j] != '.')	continue;
				s[i][j] = c;
				if(ok(1))	return true;
				if(y==n) {
					if(!dfs(x+1, y, cnt+1))	return true;
				} else {
					if(!dfs(x, y+1, cnt+1))	return true;
				}
				s[i][j] = '.';
			}
		}
	} else {
		if(y==n) {
			if(!dfs(x+1, 1, cnt))	return true;
		} else {
			if(!dfs(x, y+1, cnt))	return true;
		}
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				if(s[i][j] != '.')	continue;
				s[i][j] = cc;
				if(ok(1))	return true;
				if(y==n) {
					if(!dfs(x+1, y, cnt+1))	return true;
				} else {
					if(!dfs(x, y+1, cnt+1))	return true;
				}
				s[i][j] = '.';
			}
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		char ccc[5];
		n = 3;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%s", ccc+1);
				s[i][j] = ccc[1];
			}
		}
		scanf("%s", ccc+1);
		c = ccc[1];
		if(c == 'o')	cc = 'x';
		else	cc = 'o';
		bool ans = ok(1) || dfs(1, 1, 1);
		if(ans)	printf("Kim win!\n");
		else	printf("Cannot win!\n");
	}
	return 0;
}

