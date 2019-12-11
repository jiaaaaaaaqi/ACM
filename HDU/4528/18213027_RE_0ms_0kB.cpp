/*
		  .
		 ';;;;;.
		'!;;;;;;!;`
	   '!;|&#@|;;;;!:
	  `;;!&####@|;;;;!:
	 .;;;!&@$$%|!;;;;;;!'.`:::::'.
	 '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
	 :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`	'!%&#########@$!:.
	 ;!;;!!;;;;;|$$&@##$;;;::'''''::;;;;|&|%@$|;;;;;;;;;;;;;;;;!$;
	 ;|;;;;;;;;;;;;;;;;;;!%@#####&!:::;!;;;;;;;;;;!&####@%!;;;;$%`
	`!!;;;;;;;;;;!|%%|!!;::;;|@##%|$|;;;;;;;;;;;;!|%$#####%;;;%&;
	:@###&!:;;!!||%%%%%|!;;;;;||;;;;||!$&&@@%;;;;;;;|$$##$;;;%@|
	;|::;;;;;;;;;;;;|&&$|;;!$@&$!;;;;!;;;;;;;;;;;;;;;;!%|;;;%@%.
   `!!;;;;;;;!!!!;;;;;$@@@&&&&&@$!;!%|;;;;!||!;;;;;!|%%%!;;%@|.
%&&$!;;;;;!;;;;;;;;;;;|$&&&&&&&&&@@%!%%;!||!;;;;;;;;;;;;;$##!
!%;;;;;;!%!:;;;;;;;;;;!$&&&&&&&&&&@##&%|||;;;!!||!;;;;;;;$&:
':|@###%;:;;;;;;;;;;;;!%$&&&&&&@@$!;;;;;;;!!!;;;;;%&!;;|&%.
 !@|;;;;;;;;;;;;;;;;;;|%|$&&$%&&|;;;;;;;;;;;;!;;;;;!&@@&'
  .:%#&!;;;;;;;;;;;;;;!%|$$%%&@%;;;;;;;;;;;;;;;;;;;!&@:
  .%$;;;;;;;;;;;;;;;;;;|$$$$@&|;;;;;;;;;;;;;;;;;;;;%@%.
	!&!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|@#;
	 `%$!;;;;;;;;;;;$@|;;;;;;;;;;;;;;;;;;;;;;;;!%$@#@|.
	   .|@%!;;;;;;;;;!$&%||;;;;;;;;;;;;;;;;;!%$$$$$@#|.
		   ;&$!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;%#####|.
		   |##$|!;;;;;;::'':;;;;;;;;;;;;;!%$$$@#@;
		  ;@&|;;;;;;;::'''''':;;;;;;;|$&@###@|`
		.%##@|;;;;:::''''''''''::;!%&##$'
	  `$##@$$@@&|!!;;;:'''''::::;;;;;|&#%.
	;&@##&$%!;;;;;;::''''''''::;!|%$@#@&@@:
	 .%@&$$|;;;;;;;;;;:'''':''''::;;;%@#@@#%.
	:@##@###@$$$$$|;;:'''':;;!!;;;;;;!$#@@#$;`
	 `%@$$|;;;;;;;;:'''''''::;;;;|%$$|!!&###&'
	 |##&%!;;;;;::''''''''''''::;;;;;;;!$@&:`!'
	:;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:				 !@#$'
	  |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:			  '%%!%&;
	  |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`			'%$|!%&;
	  |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:		   .|%;:!&%`
	  !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;		  `%&%!!$&:
	  '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;		 !$!;:!$&:
	   |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'	  `%$|%%;|&$'
		|&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
		`%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
		!&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
	   '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
	   .!%%&%'`|$;	   :|$#%|@#&;%#%.
*/
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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, k;
int cas, tol, T;

struct Node{
	int x, y;
	int cnt;
	int fe, fd;
};
int sx, sy, ex, ey, dx, dy;
char s[maxn][maxn];
bool vis[maxn][maxn];
int dis[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void init() {
	mes(vis, 0);
}

bool check(int x1, int y1, int x2, int y2) {
	if(x1 == x2) {
		if(y2 > y1) {
			for(int j=y1+1; j<y2; j++) {
				if(s[x1][j] != '.')	return false;
			}
		}
		if(y1 > y2) {
			for(int j=y1-1; j>y2; j--) {
				if(s[x1][j] != '.')	return false;
			}
		}
	}
	if(y1 == y2) {
		if(x2 > x1) {
			for(int i=x1+1; i<x2; i++) {
				if(s[i][y1] != '.')	return false;
			}
		}
		if(x1 > x2) {
			for(int i=x1-1; i>x2; i--) {
				if(s[i][y1] != '.')	return false;
			}
		}
	}
	return true;
}

int bfs() {
	queue<Node> q;
	Node now, nex;
	now.x = sx, now.y = sy;
	now.cnt = 0;
	now.fe = now.fd = 0;
	if(sx == ex || sy == ey) {
		if(check(sx, sy, ex, ey)) {
			now.fe = 1;
		}
	}
	if(sx == dx || sy == dy) {
		if(check(sx, sy, dx, dy)) {
			now.fd = 1;
		}
	}
	q.push(now);
	vis[sx][sy] = true;
	while(!q.empty()) {
		now = q.front();
		q.pop();
		if(now.fd && now.fe)	return now.cnt;
		for(int i=0; i<=4; i++) {
			int x = now.x + dis[i][0];
			int y = now.y + dis[i][1];
			if(x < 1 || y < 1)	continue;
			if(x > n || y > m)	continue;
			if(vis[x][y])		continue;
			if(s[x][y] != '.')	continue;
			if(now.cnt + 1 > k)	continue;
			nex = now;
			nex.cnt++;
			nex.x = x, nex.y = y;
			vis[x][y] = true;
			if(!nex.fe) {
				if(x == ex || y == ey) {
					if(check(x, y, ex, ey)) {
						nex.fe = 1;
					}
				}
			}
			if(!nex.fd) {
				if(x == dx || y == dy) {
					if(check(x, y, dx, dy)) {
						nex.fd = 1;
					}
				}
			}
			q.push(nex);
		}
	}
	return -1;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d%d", &n, &m, &k);
		for(int i=1; i<=n; i++) {
			scanf("%s", s[i]+1);
			for(int j=1; j<=m; j++) {
				if(s[i][j] == 'D')	dx = i, dy = j;
				if(s[i][j] == 'S')	sx = i, sy = j;
				if(s[i][j] == 'E')	ex = i, ey = j;
			}
		}
		int ans = bfs();
		printf("Case %d:\n", cas++);
		printf("%d\n", ans);
	}
	return 0;
}
