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
const int    maxn = 600;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn][maxn];

bool check(int x, int y) {
    if(x < 1 || y < 1)	return 1;
    if(x > n || y > n)	return 1;
    if(a[x][y])			return 1;
    return 0;
}

void solve1() {
    int cnt = 1;
    int x = 1, y = 1;
    a[x][y] = cnt;
    for(int i=0; i<=3; i=(i+1)%4) {
        if(i == 0) {
            for(int j=0; j<=3; j=(j+1)%4) {
                if(j == 0) {
                    y++;
                    a[x][y] = ++cnt;
                } else if(j ==1) {
                    x++;
                    a[x][y] = ++cnt;
                } else if(j == 2) {
                    y--;
                    a[x][y] = ++cnt;
                } else {
                    x++;
                    a[x][y] = ++cnt;
                    if(check(x+1, y))
                        break;
                }
            }
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
        } else if(i == 1) {
            for(int j=0; j<=3; j=(j+1)%4) {
                if(j == 0) {
                    x--;
                    a[x][y] = ++cnt;
                } else if(j == 1) {
                    if(check(x, y+1)) {
                        while(!check(x-1, y)) {
                            x--;
                            a[x][y] = ++cnt;
                        }
                        return ;
                    }
                    y++;
                    a[x][y] = ++cnt;
                } else if(j == 2) {
                    x++;
                    a[x][y] = ++cnt;
                } else if(j == 3) {
                    y++;
                    a[x][y] = ++cnt;
                    if(check(x, y+1))
                        break;
                }
            }
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
        } else if(i == 2) {
            for(int j=0; j<=3; j=(j+1)%4) {
                if(j == 0) {
                    y--;
                    a[x][y] = ++cnt;
                } else if(j == 1) {
                    x--;
                    a[x][y] = ++cnt;
                } else if(j == 2) {
                    y++;
                    a[x][y] = ++cnt;
                } else if(j == 3) {
                    x--;
                    a[x][y] = ++cnt;
                    if(check(x-1, y))
                        break;
                }
            }
            if(check(x, y-1))
                return ;
            y--;
            a[x][y] = ++cnt;
            if(check(x, y-1))
                return ;
            y--;
            a[x][y] = ++cnt;
        } else if(i == 3) {
            for(int j=0; j<=3; j=(j+1)%4) {
                if(j == 0) {
                    x++;
                    a[x][y] = ++cnt;
                } else if(j == 1) {
                    if(check(x, y-1)) {
                        while(!check(x+1, y)) {
                            x++;
                            a[x][y] = ++cnt;
                        }
                        return ;
                    }
                    if(check(x, y-1))
                        return ;
                    y--;
                    a[x][y] = ++cnt;
                } else if(j == 2) {
                    if(check(x-1, y))
                        return ;
                    x--;
                    a[x][y] = ++cnt;
                } else if(j == 3) {
                    if(check(x, y-1))
                        return ;
                    y--;
                    a[x][y] = ++cnt;
                    if(check(x, y-1))
                        break;
                }
            }
            if(check(x+1, y))
                return ;
            x++;
            a[x][y] = ++cnt;

            if(check(x+1, y))
                return ;
            x++;
            a[x][y] = ++cnt;
        }
    }
}
//
//void debug() {
//	printf("debug:\n");
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=n; j++) {
//            printf("%d%c", a[i][j], j==n ? '\n' : ' ');
//        }
//    }
//    printf("\n");
//}

void solve2() {
    int x = 1, y = 2;
    int cnt = 1;
    a[x][y] = 1;
    for(int i=0; i<=3; i=(i+1)%4) {
        if(i == 0) {
            if(check(x, y-1))
                return ;
            y--;
            a[x][y] = ++cnt;
        } else if(i == 1) {
            if(check(x+1, y))
                return ;
            x++;
            a[x][y] = ++cnt;
            if(check(x+1, y))
                break;
        } else if(i == 2) {
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
        } else {
            if(check(x+1, y))
                return ;
            x++;
            a[x][y] = ++cnt;
        }
    }
    if(check(x, y+1))
        return ;
    y++;
    a[x][y] = ++cnt;

    if(check(x, y+1))
        return ;
    y++;
    a[x][y] = ++cnt;

//    debug();

    for(int i=0; i<=3; i=(i+1)%4) {
        if(check(x, y+1)) {
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
            break;
        }
        if(check(x, y+2)) {
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
            break;
        }
        if(i == 0) {
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
        } else if(i == 1) {
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
        } else if(i == 2) {
            if(check(x+1, y))
                return ;
            x++;
            a[x][y] = ++cnt;
        } else {
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
            if(check(x, y+1)) {
                if(check(x-1, y))
                    return ;
                x--;
                a[x][y] = ++cnt;

                if(check(x-1, y))
                    return ;
                x--;
                a[x][y] = ++cnt;
                break;
            }
            if(check(x, y+2)) {
                if(check(x, y+1))
                    return ;
                y++;
                a[x][y] = ++cnt;
                if(check(x-1, y))
                    return ;
                x--;
                a[x][y] = ++cnt;
                break;
            }
        }
    }

//    debug();

    for(int i=0; i<=3; i=(i+1)%4) {
        if(i == 0) {
            if(check(x, y-1))
                return ;
            y--;
            a[x][y] = ++cnt;
        } else if(i == 1) {
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
        } else if(i == 2) {
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
        } else {
            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
            if(check(x-1, y))
                break;
        }
    }

//    debug();
    while(!check(x, y-1)) {
        y--;
        a[x][y] = ++cnt;
    }
    if(check(x+1, y))
        return ;
    x++;
    a[x][y] = ++cnt;

//	debug();

    for(int i=0; i<2; i=(i+1)%2) {
        if(cnt >= n*n+1)
            return ;
        if(i == 0) {
            for(int j=0; j<=3; j=(j+1)%4) {
                if(j == 0) {
                    if(check(x, y+1))
                        return ;
                    y++;
                    a[x][y] = ++cnt;
                } else if(j == 1) {
                    if(check(x+1, y))
                        return ;
                    x++;
                    a[x][y] = ++cnt;
                } else if(j == 2) {
                    if(check(x, y-1))
                        return ;
                    y--;
                    a[x][y] = ++cnt;
                } else {
                    if(check(x+1, y))
                        return ;
                    x++;
                    a[x][y] = ++cnt;
                    if(check(x+1, y))
                        break;
                }
            }
//            debug();
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;

            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;

            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;

            if(check(x-1, y))
                return ;
            x--;
            a[x][y] = ++cnt;
        } else {
            for(int j=0; j<=3; j=(j+1)%4) {
                if(j == 0) {
                    if(check(x, y-1))
                        return ;
                    y--;
                    a[x][y] = ++cnt;
                } else if(j == 1) {
                    if(check(x-1, y))
                        return ;
                    x--;
                    a[x][y] = ++cnt;
                } else if(j == 2) {
                    if(check(x, y+1))
                        return ;
                    y++;
                    a[x][y] = ++cnt;
                    if(check(x-1, y))
                        break;
                } else {
                    if(check(x-1, y))
                        return ;
                    x--;
                    a[x][y] = ++cnt;
                }
            }
            if(check(x, y+1))
                return ;
            y++;
            a[x][y] = ++cnt;
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        mes(a, 0);
        scanf("%d", &n);
        if(n & 1)	solve1();
        else	solve2();
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                printf("%d%c", a[i][j], j==n ? '\n' : ' ');
            }
        }
    }
    return 0;
}
