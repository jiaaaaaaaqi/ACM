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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Mat {
    double mat[5][5];
    void init() {
        for(int i=1; i<=2; i++) {
            for(int j=1; j<=2; j++) {
                mat[i][j] = 0.0;
            }
        }
    }
};
int a[15];

Mat mmul(Mat A, Mat B) {
    Mat ans;
    ans.init();
    for(int i=1; i<=2; i++) {
        for(int j=1; j<=2; j++) {
            for(int k=1; k<=2; k++) {
                ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
            }
        }
    }
    return ans;
}

Mat mpow(Mat A, int b) {
    Mat ans;
    ans.init();
    for(int i=1; i<=2; i++)
        ans.mat[i][i] = 1.0;
    while(b) {
        if(b & 1)
            ans = mmul(ans, A);
        A = mmul(A, A);
        b >>= 1;
    }
    return ans;
}

int main() {
    double p, q;
    while(~scanf("%d%lf", &n, &p)) {
        mes(a, 0);
        q = 1.0 - p;
        int flag = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            if(a[i] == 1) {
                flag = 1;
            }
        }
        if(flag) {
            printf("0.0000000\n");
            continue;
        }
        a[n+1] = 0;
        n++;
        sort(a+1, a+1+n);
        double ans = 1.0;
        Mat A;
        for(int i=2; i<=n; i++) {
            if(a[i] == a[i-1])	continue;
            int tmp = a[i] - a[i-1] + 1;
            if(tmp == 2) {
                ans *= 0.0;
            } else {
                A.mat[1][1] = p;
                A.mat[1][2] = q;
                A.mat[2][1] = 1.0;
                A.mat[2][2] = 0.0;
                A = mpow(A, tmp-2);
//                for(int i=1; i<=2; i++) {
//					for(int j=1; j<=2; j++) {
//						printf("%f%c", A.mat[i][j], j==2 ? '\n' : ' ');
//					}
//                }
                ans *= (1 - A.mat[1][1]);
            }
        }
        printf("%.7f\n", ans);
    }
    return 0;
}
