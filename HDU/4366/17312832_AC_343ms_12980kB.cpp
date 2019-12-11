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
const int    maxn = 5e4 + 10;
const int    maxm = 1e6 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int ab, lo, id;
	bool operator < (Node a) const {
		if(ab == a.ab)	return lo > a.lo; 
		return ab > a.ab;
	}
} node[maxn];
int in[maxn];
int mp[maxm];
int ans[maxn];
int out[maxn];
int a[maxn <<2];
std::vector<int> vec[maxn];

void init() {
	tol = 1;
	mes(mp, 0);
	for(int i=1; i<=n; i++)	vec[i].clear();
}

void dfs(int u) {
	in[u] = tol++;
	int len = vec[u].size();
	for(int i=0; i<len; i++) {
		int v = vec[u][i];
		dfs(v);
	}
	out[u] = tol;
}

void pushup(int rt) {
	a[rt] = max(a[rt<<1], a[rt<<1|1]);
}

void build(int l, int r, int rt) {
	a[rt] = -1;
	if(l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	pushup(rt);
}

void update(int l, int r, int p, int v, int rt) {
	if(l == r) {
		a[rt] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	if(p <= mid)
		update(l, mid, p, v, rt<<1);
	else
		update(mid+1, r, p, v, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int pl, int pr, int rt) {
	if(l > r)	return -1;
	if(pl <= l && r <= pr) {
		return a[rt];
	}
	int mid = (l + r) >> 1;
	int ans = -1;
	if(pl <= mid)
		ans = max(ans, query(l, mid, pl, pr, rt<<1));
	if(pr > mid)
		ans = max(ans, query(mid+1, r, pl, pr, rt<<1|1));
	return ans;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		for(int i=2; i<=n; i++) {
			int x;
			scanf("%d%d%d", &x, &node[i].lo, &node[i].ab);
			mp[node[i].lo] = i;
			node[i].id = i;
			x++;
			vec[x].push_back(i);
		}
		dfs(1);
		sort(node+2, node+1+n);
		build(1, tol, 1);
//		for(int i=1; i<=n; i++) {
//			printf("%d %d %d\n", i, in[i], out[i]);
//		}
		for(int i=2, j; i<=n; i=j) {
			j = i;
			while(j <= n && node[i].ab == node[j].ab) {
				int l = in[node[j].id];
				int r = out[node[j].id];
				if(l == r)	ans[node[j].id] = -1;
				else {
					int x = query(1, tol, l+1, r-1, 1);
					if(x == -1)
						ans[node[j].id] = -1;
					else
						ans[node[j].id] = mp[x] - 1;
				}
				j++;
			}
			j = i;
			while(j <= n && node[i].ab == node[j].ab) {
				int l = in[node[j].id];
				update(1, tol, l, node[j].lo, 1);
				j++;
			}
		}
		while(m--) {
			int x;
			scanf("%d", &x);
			printf("%d\n", ans[x+1]);
		}
	}
	return 0;
}