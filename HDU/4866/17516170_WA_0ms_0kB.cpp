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
	ll sum, cnt;
}node[maxn * 40];
struct Edge{
	int id;
	ll val;
	bool operator < (Edge a) const {
		return id < a.id;
	}
}edge[maxn << 1];
int rt[maxn << 1];
int last[maxn];
vector<int> vv;

void init() {
	tol = 0;
	vv.clear();
	mes(rt, 0);
	mes(last, 0);
}

int getid(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void update(int l, int r, int &x, int y, int p, int v) {
	x = ++tol;
	node[x] = node[y];
	node[x].sum += v;
	if(v > 0)	node[x].cnt++;
	else	node[x].cnt--;
	if(l == r)	return ;
	int mid = l + r >> 1;
	if(p <= mid)
		update(l, mid, node[x].l, node[y].l, p, v);
	else
		update(mid+1, r, node[x].r, node[y].r, p, v);
}

ll query(int l, int r, int x, int k) {
	if(l == r)	return k ? node[x].sum : 0ll;
	int mid = l + r >> 1;
	int cnt = node[node[x].l].cnt;
	if(k <= cnt)
		return query(l, mid, node[x].l, k);
	else
		return node[node[x].l].sum + query(mid+1, r, node[x].r, k-cnt);
}

int main() {
	int x;
	ll p;
	while(~scanf("%d%d%d%d", &n, &m, &x, &p)) {
		init();
		int tot = 0;
		for(int i=1; i<=n; i++) {
			int l, r;
			ll v;
			scanf("%d%d%lld", &l, &r, &v);
			tot++;
			edge[tot].id = l;
			edge[tot].val = v;
			tot++;
			edge[tot].id = r+1;
			edge[tot].val = -v;
			vv.push_back(v);
		}
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		sort(edge+1, edge+1+tot);
		for(int i=1; i<=tot; i++) {
			int pos = edge[i].id;
			ll v = edge[i].val;
			int tmp = getid(abs(v));
			update(1, vv.size(), rt[i], rt[i-1], tmp, v);
			last[pos] = i;
		}
		for(int i=1; i<=x; i++) {
			if(last[i])	continue;
			last[i] = last[i-1];
		}
		ll ans = 1ll;
		while(m--) {
			int p;
			ll a, b, c;
			scanf("%d%lld%lld%lld", &p, &a, &b, &c);
			ll k = (a * ans % c + b) % c;
			if(ans > p)
				ans = query(1, vv.size(), rt[last[p]], k) * 2;
			else
				ans = query(1, vv.size(), rt[last[p]], k);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
