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

struct Node{
	int l, r;
	int sum;
} node[maxn * 40];
int a[maxn];
int rt[maxn];
bool vis[maxn];
int deep[maxn];
int fa[maxn][20];
vector<int> vec[maxn];
vector<int> vv;

void init() {
	tol = 0;
	mes(a, 0);
	mes(fa, 0);
	mes(vis, 0);
	mes(deep, 0);
	vv.clear();
	for(int i=1; i<=n; i++)
		vec[i].clear();
}

int getid(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void lca_dfs(int u, int f, int d) {
	deep[u] = d;
	int len = vec[u].size();
	for(int i=0; i<len; i++) {
		int v = vec[u][i];
		if(v == f)	continue;
		if(fa[v][0])continue;
		fa[v][0] = u;
		lca_dfs(v, u, d+1);
	}
}

void lca_update() {
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i<=n; i++) {
			fa[i][j] = fa[fa[i][j-1]][j-1];
		}
	}
}

int lca_query(int u, int v) {
	if(deep[u] < deep[v])	swap(u, v);
	int f = deep[u] - deep[v];
	for(int i=0; (1<<i)<=f; i++) {
		if(f & (1<<i)) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	if(u != v) {
		for(int i=(int)log2(n); i>=0; i--) {
			if(fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		u = fa[u][0];
	}
	return u;
}

void hjt_update(int l, int r, int &x, int y, int pos) {
	tol++;
	node[tol] = node[y];
	node[tol].sum++;
	x = tol;
	if(l == r)	return ;
	int mid = (l + r) >> 1;
	if(pos <= mid)
		hjt_update(l, mid, node[x].l, node[y].l, pos);
	else
		hjt_update(mid+1, r, node[x].r, node[y].r, pos);
}

void hjt_build(int u, int f) {
	vis[u] = true;
	int len = vec[u].size();
	for(int i=0; i<len; i++) {
		int v = vec[u][i];
		if(vis[v])	continue;
		if(v == f)	continue;
		hjt_update(1, n, rt[v], rt[u], getid(a[v]));
//		printf("%d %d\n", u, v);
		hjt_build(v, u);
	}
}

int hjt_query(int l, int r, int x, int y, int k) {
	if(l == r) 
		return l;
	int mid = (l + r) >> 1;
	int lca = lca_query(x, y);
	int sum = node[node[x].l].sum + node[node[y].l].sum - node[node[lca].l].sum - node[node[fa[lca][0]].l].sum;
	if(k <= sum)
		return hjt_query(l, mid, node[x].l, node[y].l, k);
	else
		return hjt_query(mid+1, r, node[x].r, node[y].r, k-sum);
}

int main() {
	scanf("%d%d", &n, &m);
	init();
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		vv.push_back(a[i]);
	}
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	for(int i=1; i<n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	fa[1][0] = 1;
	lca_dfs(1, 1, 1);
	lca_update();
	hjt_update(1, n, rt[1], rt[0], getid(a[1]));
	hjt_build(1, 1);
	while(m--) {
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		int ans = hjt_query(1, n, rt[u], rt[v], k);
		printf("%d\n", vv[ans-1]);
	}
	return 0;
}
