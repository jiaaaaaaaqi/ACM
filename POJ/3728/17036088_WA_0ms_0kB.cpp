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
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int v;
    int next;
} node[maxn];
int val[maxn];
int head[maxn];
int deep[maxn];
int fa[maxn][30];
int mxv[maxn][30];
int mnv[maxn][30];
int down[maxn][30];
int up[maxn][30];

void init() {
    tol = 1;
    mes(up, 0);
    mes(fa, -1);
    mes(val, 0);
    mes(mxv, 0);
    mes(mnv, 0);
    mes(down, 0);
    mes(deep, 0);
    mes(head, -1);
}

void addnode(int u, int v) {
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u, int f, int d) {
    deep[u] = d;
    for(int i=head[u]; ~i; i=node[i].next) {
        int v = node[i].v;
        if(v == f)	continue;
        fa[v][0] = u;
        mxv[v][0] = max(val[u], val[v]);
        mnv[v][0] = min(val[u], val[v]);
        up[v][0] = max(0, val[u] - val[v]);
        down[v][0] = max(0, val[v] - val[u]);
        dfs(v, u, d+1);
    }
}

void update() {
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=1; i<=n; i++) {
            if(fa[i][j-1]) {
                fa[i][j] = fa[fa[i][j-1]][j-1];
                int k = fa[i][j-1];
                mxv[i][j] = max(mxv[i][j-1], mxv[k][j-1]);
                mnv[i][j] = min(mnv[i][j-1], mnv[k][j-1]);
                up[i][j] = max(max(up[i][j-1], up[k][j-1]), max(0, mxv[k][j-1] - mnv[i][j-1]));
                down[i][j] = max(max(down[i][j-1], down[k][j-1]), max(0, mxv[i][j-1] - mnv[k][j-1]));
            }
        }
    }
}

int lca(int u, int v) {
    if(deep[u] < deep[v])	swap(u, v);
    int f = deep[u] - deep[v];
    for(int i=0; (1<<i)<=f; i++) {
        if(f & (1<<i)) {
            u = fa[u][i];
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

int query_up(int u, int f, int &minval) {
    int ans = 0;
    minval = inf;
    for(int i=(int)log2(n); i>=0; i--) {
        if(f & (1<<i)) {
            ans = max(ans, up[u][i]);
            ans = max(ans, mxv[u][i] - minval);
            minval = min(minval, mnv[u][i]);
            u = fa[u][i];
        }
    }
    return ans;
}

int query_down(int u, int f, int &maxval) {
    int ans = 0;
    maxval = 0;
    for(int i=(int)log2(n); i>=0; i--) {
        if(f & (1<<i)) {
            ans = max(ans, down[u][i]);
            ans = max(ans, maxval - mnv[u][i]);
            maxval = max(maxval, mxv[u][i]);
            u = fa[u][i];
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    init();
    for(int i=1; i<=n; i++)
        scanf("%d", &val[i]);
    int u, v;
    for(int i=1; i<n; i++) {
        scanf("%d%d", &u, &v);
        addnode(u, v);
        addnode(v, u);
    }
    dfs(1, 0, 1);
    update();
//    for(int i=1; i<=n; i++) {
//        for(int j=0; (1<<j)<=n; j++) {
//            printf("%d ", mxv[i][j]);
//        }
//        printf("\n");
//    }
    scanf("%d", &m);
    while(m--) {
        scanf("%d%d", &u, &v);
        int t = lca(u, v);
        int maxval, minval;
        int ans1, ans2;
        ans1 = query_up(u, deep[u] - deep[t], minval);
        ans2 = query_down(v, deep[v] - deep[t], maxval);
//        printf("!!!%d %d\n", ans1, ans2);
        int ans = max(max(ans1, ans2), max(0, maxval - minval));
        printf("%d\n", ans);
    }
    return 0;
}
