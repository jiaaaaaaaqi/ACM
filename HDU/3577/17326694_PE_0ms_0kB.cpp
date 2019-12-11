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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int l, r;
	bool operator < (Node a) const {
		return r > a.r;
	}
};
struct Seg{
	int a;
	int lazy;
} seg[maxn << 2];

void pushdown(int rt) {
	if(seg[rt].lazy) {
		seg[rt<<1].lazy += seg[rt].lazy;
		seg[rt<<1|1].lazy += seg[rt].lazy;
		seg[rt<<1].a += seg[rt].lazy;
		seg[rt<<1|1].a += seg[rt].lazy;
		seg[rt].lazy = 0;
	}
}

void pushup(int rt) {
	seg[rt].a = max(seg[rt<<1].a, seg[rt<<1|1].a);
}

void build(int l, int r, int rt) {
	seg[rt].a = seg[rt].lazy = 0;
	if(l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void update(int l, int r, int pl, int pr, int v, int rt) {
	if(pl <= l && r <= pr) {
		seg[rt].a += v;
		seg[rt].lazy += v;
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	if(pl <= mid)	
		update(l, mid, pl, pr, v, rt<<1);
	if(pr > mid)
		update(mid+1, r, pl, pr, v, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int pl, int pr, int rt) {
	if(pl <= l && r <= pr) {
		return seg[rt].a;
	}
	int mid = (l + r) >> 1;
	pushdown(rt);
	int ans = 0;
	if(pl <= mid)
		ans = max(ans, query(l, mid, pl, pr, rt<<1));
	if(pr > mid)
		ans = max(ans, query(mid+1, r, pl, pr, rt<<1|1));
	return ans;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		printf("Case %d:\n", cas++);
		priority_queue<Node> q;
		Node tmp;
		scanf("%d%d", &n, &m);
		build(1, 1000000, 1);
		int a, b;
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &a, &b);
			// while(!q.empty()) {
			// 	tmp = q.top();
			// 	int l = tmp.l;
			// 	int r = tmp.r;
			// 	if(r <= b) {
			// 		q.pop();
			// 		update(1, 1000000, l, r-1, -1, 1);
			// 	} else {
			// 		break;
			// 	}
			// }
			int ans = query(1, 1000000, a, b-1, 1);
//			printf("ans = %d\n", ans);
			if(ans != n) {
				printf("%d ", i);
				update(1, 1000000, a, b-1, 1, 1);
				tmp.l = a;
				tmp.r = b;
				q.push(tmp);
			}
		}
	}
	return 0;
}
