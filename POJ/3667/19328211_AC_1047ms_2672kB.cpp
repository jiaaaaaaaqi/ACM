/*
          .
         ';;;;;.
        '!;;;;;;!;`
       '!;|&#@|;;;;!:
      `;;!&####@|;;;;!:
     .;;;!&@$$%|!;;;;;;!'.`:::::'.
     '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
     :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`    '!%&#########@$!:.
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
    :;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:                 !@#$'
      |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:              '%%!%&;
      |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`            '%$|!%&;
      |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:           .|%;:!&%`
      !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;          `%&%!!$&:
      '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;         !$!;:!$&:
       |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'      `%$|%%;|&$'
        |&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
        `%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
        !&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
       '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
       .!%%&%'`|$;       :|$#%|@#&;%#%.
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
const int    maxn = 5e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int lsum[maxn<<2], rsum[maxn<<2], asum[maxn<<2], lazy[maxn<<2];

void pushdown(int l, int r, int rt) {
	if(lazy[rt] != -1) {
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		rsum[rt<<1] = asum[rt<<1] = lsum[rt<<1] = lazy[rt] ? l : 0;
		rsum[rt<<1|1] = asum[rt<<1|1] = lsum[rt<<1|1] = lazy[rt] ? r : 0;
		lazy[rt] = -1;
	}
}

void pushup(int l, int r, int rt) {
	lsum[rt] = lsum[rt<<1];
	rsum[rt] = rsum[rt<<1|1];
	if(lsum[rt] == l)	lsum[rt] += lsum[rt<<1|1];
	if(rsum[rt] == r)	rsum[rt] += rsum[rt<<1];
	asum[rt] = max(max(asum[rt<<1], asum[rt<<1|1]), rsum[rt<<1]+lsum[rt<<1|1]);
}

void build(int l, int r, int rt) {
	lsum[rt] = rsum[rt] = asum[rt] = r-l+1;
	lazy[rt] = -1;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void update(int l, int r, int pl, int pr, int v, int rt) {
	if(pl<=l && r<=pr) {
		lazy[rt] = v;
		lsum[rt] = rsum[rt] = asum[rt] = v ? r-l+1 : 0;
		return ;
	}
	int mid = l+r>>1;
	pushdown(mid-l+1, r-mid, rt);
	if(pl <= mid)
		update(l, mid, pl, pr, v, rt<<1);
	if(pr > mid)
		update(mid+1, r, pl, pr, v, rt<<1|1);
	pushup(mid-l+1, r-mid, rt);
}

int query(int l, int r, int k, int rt) {
	if(l == r)	return l;
	int mid = l+r>>1;
	pushdown(mid-l+1, r-mid, rt);
	if(asum[rt<<1] >= k)	return query(l, mid, k, rt<<1);
	else if(rsum[rt<<1]+lsum[rt<<1|1] >= k)	return mid-rsum[rt<<1]+1;
	else	return query(mid+1, r, k, rt<<1|1);
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
		build(1, n, 1);
		int id, l, r;
		while(m--) {
			scanf("%d", &id);
			if(id == 1) {
				scanf("%d", &l);
				if(asum[1] < l) {
					printf("0\n");
					continue;
				} else {
					int pos = query(1, n, l, 1);
					printf("%d\n", pos);
					r = pos + l-1;
					update(1, n, pos, r, 0, 1);
				}
			} else {
				scanf("%d%d", &l, &r);
				r = l+r-1;
				update(1, n, l, r, 1, 1);
			}
		}
    }
    return 0;
}
