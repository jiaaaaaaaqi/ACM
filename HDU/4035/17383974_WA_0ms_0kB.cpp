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
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

std::vector<int> vec[maxn];
double A[maxn];
double B[maxn];
double C[maxn];
double k[maxn];
double e[maxn];

void init() {
	for(int i=0; i<=n; i++)
		vec[i].clear();
	mes(A, 0);
	mes(B, 0);
	mes(C, 0);
}

//void dfs(int u, int f) {
//	int len = vec[u].size();
//	if(len == 1) {
//		A[u] = k[u];
//		B[u] = C[u] = 1 - k[u] - e[u];
//		return ;
//	}
//	if(A[u] != 0.0)	{
//		return ;
//	}
//	for(int i=0; i<len; i++) {
//		int v = vec[u][i];
//		if(v == f)	continue;
//		dfs(v, u);
//	}
//	double tmpa = 0.0;
//	double tmpb = 0.0;
//	double tmpc = 0.0;
//	for(int i=0; i<len; i++) {
//		int v = vec[u][i];
//		if(v == f)	continue;
//		tmpa += A[v];
//		tmpb += B[v];
//		tmpc += C[v];
//	}
//	double tmp = 1.0 - (1.0 - e[u] - k[u]) * tmpb;
//	A[u] = (k[u] + (1.0 - e[u] - k[u]) * tmpa) / tmp;
//	B[u] = (1 - k[u] - e[u]) / tmp;
//	C[u] = (1.0 - e[u] - k[u]) * C[u] + 1;
//}

void dfs(int u, int f) {
	int len = vec[u].size();
	if(len == 1) {
		A[u] = k[u];
		B[u] = C[u] = 1 - k[u] - e[u];
		return ;
	}
	if(A[u] != 0.0)
		return ;
	for(int i=0; i<len; i++) {
		int v = vec[u][i];
		if(v == f)	continue;
		dfs(v, u);
	}
	double tmpa = 0.0, tmpb = 0.0, tmpc = 0.0;
	for(int i=0; i<len; i++) {
		int v = vec[u][i];
		if(v == f)	continue;
		tmpa += A[v];
		tmpb += B[v];
		tmpc += C[v];
	}
	double tmp = (1 - (1 - k[u] - e[u]) / len * tmpb);
	A[u] = (k[u] + (1 - k[u] - e[u]) / len * tmpa) / tmp;
	B[u] = (1 - k[u] - e[u]) / len / tmp;
	C[u] = (1 - k[u] - e[u]) * (tmpc / len + 1) / tmp;
}

int main() {
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i=1; i<n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for(int i=1; i<=n; i++) {
			scanf("%lf%lf", &k[i], &e[i]);
			k[i] /= 100.0;
			e[i] /= 100.0;
		}
		dfs(1, 0);
		printf("Case %d: ", cas++);
		double ans = C[1] / (1 - A[1]);
		if(fabs(ans - 1.0) <= eps) {
			printf("impossible\n");
		} else {
			printf("%.6f\n", ans);
		}
	}
	return 0;
}