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
	int sta;
};
int sx, sy, ex, ey, dx, dy;
char s[maxn][maxn];
int ok[maxn][maxn];
bool vis[maxn][maxn][5];
int dis[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void init() {
	mes(ok, 0);
	mes(vis, 0);
}

int bfs() {
	queue<Node> q;
	Node now, nex;
	now.x = sx, now.y = sy;
	now.cnt = 0;
	now.sta = ok[sx][sy];
	vis[now.x][now.y][now.sta] = true;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		if(now.sta == 3)	return now.cnt;
		for(int i=0; i<4; i++) {
			int x = now.x + dis[i][0];
			int y = now.y + dis[i][1];
			if(x < 1 || y < 1)		continue;
			if(x > n || y > m)		continue;
			if(s[x][y] != '.')		continue;
			if(now.cnt + 1 > k)		continue;
			if(vis[x][y][now.sta])	continue;
			nex = now;
			nex.cnt++;
			nex.x = x, nex.y = y;
			nex.sta |= ok[x][y];
			vis[nex.x][nex.y][nex.sta] = true;
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
				if(s[i][j] == 'S')	sx = i, sy = j, s[i][j] = '.';
				if(s[i][j] == 'E')	ex = i, ey = j;
			}
		}
		for(int j=dy+1; j<=m; j++) {
			if(s[dx][j] != '.')	break;
			ok[dx][j] |= 1;
		}
		for(int j=dy-1; j>=1; j--) {	
			if(s[dx][j] != '.')	break;
			ok[dx][j] |= 1;
		}
		for(int i=dx+1; i<=n; i++) {
			if(s[i][dy] != '.')	break;
			ok[i][dy] |= 1;
		}
		for(int i=dx-1; i>=1; i--) {
			if(s[i][dy] != '.')	break;
			ok[i][dy] |= 1;
		}
		for(int j=ey+1; j<=m; j++) {
			if(s[ex][j] != '.')	break;
			ok[ex][j] |= 2;
		}
		for(int j=ey-1; j>=1; j--) {	
			if(s[ex][j] != '.')	break;
			ok[ex][j] |= 2;
		}
		for(int i=ex+1; i<=n; i++) {
			if(s[i][ey] != '.')	break;
			ok[i][ey] |= 2;
		}
		for(int i=ex-1; i>=1; i--) {
			if(s[i][ey] != '.')	break;
			ok[i][ey] |= 2;
		}
		int ans = bfs();
		printf("Case %d:\n", cas++);
		printf("%d\n", ans);
	}
	return 0;
}
/*
1
3 4 100
S...
..XE
...D
*/
