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

struct Seg{
	ll ans1, ans2, ans3, ans4;
}seg[maxn << 2];
//ans1	奇奇	奇奇+偶奇	奇偶+奇奇
//ans2	偶偶	偶偶+奇偶	偶奇+偶偶
//ans3	奇偶	奇偶+奇偶	奇奇+偶偶
//ans4	偶奇	偶奇+偶奇	偶偶+偶奇

void pushup(int rt) {
	seg[rt].ans1 = max(max(seg[rt<<1].ans1, seg[rt<<1|1].ans1), max(seg[rt<<1].ans1 + seg[rt<<1|1].ans4, seg[rt<<1].ans3 + seg[rt<<1|1].ans1));
	seg[rt].ans2 = max(max(seg[rt<<1].ans2, seg[rt<<1|1].ans2), max(seg[rt<<1].ans2 + seg[rt<<1|1].ans3, seg[rt<<1].ans4 + seg[rt<<1|1].ans2));
	seg[rt].ans3 = max(max(seg[rt<<1].ans3, seg[rt<<1|1].ans3), max(seg[rt<<1].ans3 + seg[rt<<1|1].ans3, seg[rt<<1].ans1 + seg[rt<<1|1].ans2));
	seg[rt].ans4 = max(max(seg[rt<<1].ans4, seg[rt<<1|1].ans4), max(seg[rt<<1].ans4 + seg[rt<<1|1].ans4, seg[rt<<1].ans2 + seg[rt<<1|1].ans1));	
}

void build(int l, int r, int rt) {
	seg[rt].ans1 = seg[rt].ans2 = seg[rt].ans3 = seg[rt].ans4 = -INF;
	if(l == r) {
		ll x;
		scanf("%lld", &x);
		if(l & 1)	seg[rt].ans1 = x;
		else	seg[rt].ans2 = x;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void update(int l, int r, int p, int v, int rt) {
	if(l == r) {
		seg[rt].ans1 = seg[rt].ans2 = seg[rt].ans3 = seg[rt].ans4 = -INF;
		if(l & 1)	seg[rt].ans1 = v;
		else	seg[rt].ans2 = v;
		return ;
	}
	int mid = (l + r) >> 1;
	if(p <= mid)	update(l, mid, p, v, rt<<1);
	else	update(mid+1, r, p, v, rt<<1|1);
	pushup(rt);
}

Seg query(int l, int r, int pl, int pr, int rt) {
	if(pl <= l && r <= pr) {
		return seg[rt];
	}
	int mid = (l + r) >> 1;
	Seg ansl, ansr, ans;
	int flagl = 0;
	int flagr = 0;
	if(pl <= mid) {
		flagl = 1;
		ansl = query(l, mid, pl, pr, rt<<1);
	}
	if(pr > mid) {
		flagr = 1;
		ansr = query(mid+1, r, pl, pr, rt<<1|1);
	}
	if(flagl && !flagr)
		return ansl;
	if(flagr && !flagl)
		return ansr;
	ans.ans1 = max(max(ansl.ans1, ansr.ans1), max(ansl.ans1 + ansr.ans4, ansl.ans3 + ansr.ans1));
	ans.ans2 = max(max(ansl.ans2, ansr.ans2), max(ansl.ans2 + ansr.ans3, ansl.ans4 + ansr.ans2));
	ans.ans3 = max(max(ansl.ans3, ansr.ans3), max(ansl.ans3 + ansr.ans3, ansl.ans1 + ansr.ans2));
	ans.ans4 = max(max(ansl.ans4, ansr.ans4), max(ansl.ans4 + ansr.ans4, ansl.ans2 + ansr.ans1));
	return ans;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		build(1, n, 1);
		while(m--) {
			int id;
			scanf("%d", &id);
			if(id == 0) {
				int l, r;
				scanf("%d%d", &l, &r);
				Seg ans = query(1, n, l, r, 1);
				printf("%lld\n", max(max(ans.ans1, ans.ans2), max(ans.ans3, ans.ans4)));
			} else {
				int p;
				ll v;
				scanf("%d%lld", &p, &v);
				update(1, n, p, v, 1);
			}
		}
	}
	return 0;
}
