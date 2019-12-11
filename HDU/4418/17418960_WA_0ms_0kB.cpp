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
const int    maxn = 2e2 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-9;
using namespace std;

int n, m;
int cas, tol, T;
int src, des;

int has[maxn];
double x[maxn];
double p[maxn];
double a[maxn][maxn];

void init() {
	tol = 0;
	mes(a, 0);
	mes(x, 0);
	mes(p, 0);
	mes(has, -1);
}

void bfs(int src) {
	queue<int> q;
	while(!q.empty())
		q.pop();
	q.push(src);
	has[src] = tol++;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=1; i<=m; i++) {
			if(fabs(p[i]) < eps)	continue;
			int v = (u + i) % n;
			if(has[v] == -1) {
				has[v] = tol++;
				q.push(v);
			}
		}
	}
}

void build() {
	for(int i=0; i<n; i++) {
		if(has[i] == -1)	continue;
		double ans = 0.0;
		a[has[i]][has[i]] = 1.0;
		if(i == des || i == n-des) {
			x[has[i]] = 0;
			continue;
		}
		for(int j=1; j<=m; j++) {
			int v = (i + j) % n;
			a[has[i]][has[v]] = -1.0 * p[j];
			ans += j * p[j];
		}
		x[has[i]] = ans;
	}
}

int gauss(int equ, int var) {
	int i, j, k, col, max_r;
	for(k=0, col=0; k<equ && col<var; k++, col++) {
		max_r = k;
		for(i=k+1; i<equ; i++) {
			if(fabs(a[i][col]) > fabs(a[max_r][col])) {
				max_r = i;
			}
		}
		if(fabs(a[max_r][col] < eps))	return 0;
		if(k != max_r) {
			swap(a[k], a[max_r]);
			swap(x[k], x[max_r]);
		}
		x[k] /= a[k][col];
		for(j=col+1; j<var; j++) {
			a[k][j] /= a[k][col];
		}
		a[k][col] = 1;
		for(i=0; i<equ; i++) {
			if(i != k) {
				x[i] -= x[k] * a[i][k];
				for(j=col+1; j<var; j++) {
					a[i][j] -= a[k][j] * a[i][col];
				}
				a[i][col] = 0;
			}
		}
	}
	return 1;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		int D;
		scanf("%d%d%d%d%d", &n, &m, &des, &src, &D);
		for(int i=1; i<=m; i++) {
			scanf("%lf", &p[i]);
			p[i] /= 100;
		}
		if(src == des) {
			printf("0.00\n");
			continue;
		}
		n = 2 * n - 2;
		if(D == 1)
			src = n - src;
		bfs(src);
		if(has[des] == -1 && has[n - des] == -1) {
			printf("Impossible !\n");
			continue;
		}
		build();
		if(gauss(tol, tol)) {
			printf("%.2f\n", x[has[src]]);
		} else {
			printf("Impossible !\n");
		}
	}
	return 0;
}
