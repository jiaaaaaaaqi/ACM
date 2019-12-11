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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, mod;
int cas, tol, T;
char s[maxn];
int x[maxn];
int a[maxn][maxn];

void init() {
	mes(a, 0);
	mes(x, 0);
}

int solve(char ch) {
	if(ch == '*')	return 0;
	else	return ch - 'a' + 1;
}

int fpow(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1)	
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int inv(int x) {
	return fpow(x, mod-2);
}

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}

int gauss(int equ, int var) {
	int max_r, col, k;
	for(k=0, col=0; k<equ && col < var; k++, col++) {
		max_r = k;
		for(int i=k+1; i<equ; i++) {
			if(abs(a[i][col]) > abs(a[max_r][col])) {
				max_r = i;
			}
		}
		if(a[max_r][col] == 0) {
			k--;
			continue;
		}
		swap(a[k], a[max_r]);
		for(int i=k+1; i<equ; i++) {
			if(a[i][col]) {
				int LCM = lcm(abs(a[i][col]), abs(a[k][col]));
				int ta = LCM / abs(a[i][col]);
				int tb = LCM / abs(a[k][col]);
				if(a[i][col] * a[k][col] < 0)
					ta = -tb;
				for(int j=col; j<=var; j++) {
					a[i][j] = (a[i][j] * ta - a[k][j] * tb) % mod;
					a[i][j] += mod;
					a[i][j] %= mod;
				}
			}
		}
	}
	for(int i=k; i<equ; i++) {
		if(a[i][col]) {
			return -1;
		}
	}
	if(k < var)	return var - k;
	for(int i=var-1; i>=0; i--) {
		int tmp = a[i][var];
		for(int j=i+1; j<var; j++) {
			if(a[i][j]) {
				tmp -= a[i][j] * x[j];
				tmp = (tmp % mod + mod) % mod;
			}
		}
		x[i] = (tmp * inv(a[i][i])) % mod;
	}
	return 0;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%s", &mod, &s);
		n = strlen(s);
		for(int i=0; i<n; i++) {
			int fk = solve(s[i]);
			a[i][n] = fk;
			for(int j=0; j<n; j++) {
				a[i][j] = fpow(fk, j);
			}
		}
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<=n; j++) {
//				printf("%d%c", a[i][j], j==n ? '\n' : ' ');
//			}
//		}
		gauss(n, n);
		for(int i=0; i<n; i++) {
			printf("%d%c", x[i], i==n-1 ? '\n' : ' ');
		}
	}
	return 0;
}
