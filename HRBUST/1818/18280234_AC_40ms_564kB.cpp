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

int n, m;
int cas, tol, T;

int a[maxn], sum[maxn];
int dp1[maxn][maxn], dp2[maxn][maxn];

int main() {
	sum[0] = 0;
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		mes(dp1, inf), mes(dp2, 0);
		for(int i=1; i<=n; i++)
			dp1[i][i] = dp2[i][i] = 0;
		for(int d=2; d<=n; d++) {
			for(int i=1, j=d; j<=n; i++, j++) {
				for(int k=i; k<j; k++) {
					dp1[i][j] = min(dp1[i][j], dp1[i][k]+dp1[k+1][j]+sum[j]-sum[i-1]);
					dp2[i][j] = max(dp2[i][j], dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
				}
//				printf("dp[%d][%d] = %d\n", i, j, dp1[i][j]);
			}
		}
		printf("%d %d\n", dp1[1][n], dp2[1][n]);
	}
	return 0;
}