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
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int l, r;
	ll sum, lazy;
} node[maxn * 40];
ll a[maxn];
int rt[maxn];

void init() {
	tol = 0;
	mes(a, 0);
	mes(rt, 0);
}

void pushup(int rt) {
	node[rt].sum = node[node[rt].l].sum + node[node[rt].r].sum;
}

void build(int l, int r, int &rt) {
	rt = ++tol;
	node[rt].sum = node[rt].lazy = 0;
	if(l == r) {
		node[rt].sum = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, node[rt].l);
	build(mid+1, r, node[rt].r);
	pushup(rt);
}

void update(int l, int r, int &x, int y, int pl, int pr, ll val) {
	x = ++tol;
	node[x] = node[y];
	if(pl <= l && r <= pr) {
		node[x].sum += 1ll * (r - l + 1) * val;
		node[x].lazy += 1ll * val;
		return ;
	}
	int mid = (l + r) >> 1;
	if(pl <= mid)
		update(l, mid, node[x].l, node[y].l, pl, pr, val);
	if(pr > mid)
		update(mid+1, r, node[x].r, node[y].r, pl, pr, val);
}

ll query(int l, int r, int pl, int pr, ll lazy, int rt) {
	if(pl <= l && r <= pr) {
		return node[rt].sum + 1ll * (r - l + 1) * lazy;
	}
	lazy += 1ll * node[rt].lazy;
	int mid = (l + r) >> 1;
	ll ans = 0;
	if(pl <= mid)
		ans += query(l, mid, pl, pr, lazy, node[rt].l);
	if(pr > mid)
		ans += query(mid+1, r, pl, pr, lazy, node[rt].r);
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
		}
		T = 0;
		build(1, n, rt[T]);
		char s[10];
		while(m--) {
			scanf("%s", s+1);
			if(s[1] == 'C') {
				int l, r;
				ll d;
				scanf("%d%d%lld", &l, &r, &d);
				T++;
				update(1, n, rt[T], rt[T-1], l, r, d);
			} else if(s[1] == 'Q') {
				int l, r;
				scanf("%d%d", &l, &r);
				ll ans = query(1, n, l, r, 0ll, rt[T]);
				printf("%lld\n", ans);
			} else if(s[1] == 'H') {
				int l, r, t;
				scanf("%d%d%d", &l, &r, &t);
				ll ans = query(1, n, l, r, 0ll, rt[t]);
				printf("%lld\n", ans);
			} else if(s[1] == 'B'){
				int t;
				scanf("%d", &t);
				T = t;
			}
		}
	}
	return 0;
}
