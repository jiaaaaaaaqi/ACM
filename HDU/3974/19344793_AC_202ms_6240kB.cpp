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

int ind[maxn], in[maxn], out[maxn];
vector<int> vv[maxn];
int node[maxn<<2], lazy[maxn<<2];

void init() {
	tol = 0;
	mes(ind, 0);
	for(int i=1; i<=n; i++) 
		vv[i].clear();
}

void dfs(int u) {
	in[u] = ++tol;
	for(auto i : vv[u]) {
		dfs(i);
	}
	out[u] = ++tol;
}

void build(int l, int r, int rt) {
	node[rt] = lazy[rt] = -1;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void pushdown(int rt) {
	if(lazy[rt] != -1) {
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		node[rt<<1] = node[rt<<1|1] = lazy[rt];
		lazy[rt] = -1;
	}
}

void update(int l, int r, int pl, int pr, int v, int rt) {
	if(pl<=l && r<=pr) {
		node[rt] = lazy[rt] = v;
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt);
	if(pl <= mid)
		update(l, mid, pl, pr, v, rt<<1);
	if(pr > mid)
		update(mid+1, r, pl, pr, v, rt<<1|1);
}

int query(int l, int r, int p, int rt) {
	if(l == r)	return node[rt];
	int mid = l+r>>1;
	pushdown(rt);
	if(p <= mid)
		return query(l, mid, p, rt<<1);
	else
		return query(mid+1, r, p, rt<<1|1);
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i=1, u, v; i<n; i++) {
			scanf("%d%d", &u, &v);
			vv[v].push_back(u);
			ind[u]++;
		}
		for(int i=1; i<=n; i++) {
			if(ind[i] == 0) {
				dfs(i);
				break;
			}
		}
		build(1, tol, 1);
		scanf("%d", &m);
		char cc[5];
		int id, v;
		printf("Case #%d:\n", cas++);
		while(m--) {
			scanf("%s", cc+1);
			if(cc[1] == 'C') {
				scanf("%d", &id);
				int ans = query(1, tol, in[id], 1);
				printf("%d\n", ans);
			} else {
				scanf("%d%d", &id, &v);
				update(1, tol, in[id], out[id], v, 1);
			}
		}
	}
	return 0;
}
