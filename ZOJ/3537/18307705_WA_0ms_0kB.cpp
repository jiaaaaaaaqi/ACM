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
const int    maxn = 3e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int sgn(int x) {
	if(abs(x) <= eps)	return 0;
	else	return x > 0 ? 1 : -1;
}

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) {
		x = _x, y = _y;
	}
	Point operator - (Point a) const {
		return Point(x-a.x, y-a.y);
	}
	int operator ^ (Point a) const {
		return x*a.y - y*a.x;
	}
	bool operator < (Point a) const {
		return x!=a.x ? x<a.x : y<a.y;
	}
	double distance(Point a) const {
		return hypot(1.0*(x-a.x), 1.0*(y-a.y));
	}
} p[maxn];
struct cmp {
	Point p;
	cmp(Point _p) {
		p = _p;
	}
	bool operator()(Point _a, Point _b) const {
		Point a = _a, b = _b;
		int d = sgn((a-p) ^ (b-p));
		if(d == 0)
			return sgn(a.distance(p)-b.distance(p)) < 0;
		else
			return d > 0;
	}
};
int dp[maxn][maxn];

bool ok() {
	bool s[3];
	mes(s, false);
	for(int i=1; i<=n; i++) {
		int j = i%n + 1;
		int k = j%n + 1;
		s[sgn((p[j]-p[i]) ^ (p[k]-p[i]))+1] = true;
		if(s[0] && s[2])	return false;
	}
	return true;
}

int calc(int i, int j) {
	return abs(p[i].x+p[j].x)%m * abs(p[i].y+p[j].y)%m;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		mes(p, 0);
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		if(ok()) {
			for(int i=1; i<=n; i++) {
				if(p[i] < p[1]) 
					swap(p[i], p[1]);
			}
			sort(p+1, p+1+n, cmp(p[1]));
//			for(int i=1; i<=n; i++) {
//				printf("%d %d\n", p[i].x, p[i].y);
//			}
			mes(dp, inf);
			for(int i=1; i<=n; i++) {
				dp[i][i] = 0;
				dp[i][i+1] = 0;
				dp[i][i+2] = 0;
			}
			for(int d=4; d<=n; d++) {
				for(int i=1, j=d; j<=n; i++, j++) {
					for(int k=i+1; k<j; k++) {
						dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+calc(i, k) + calc(k, j));
					}
				}
			}
			printf("%d\n", dp[1][n]);
		} else {
			printf("I can't cut.\n");
		}
	}
	return 0;
}
