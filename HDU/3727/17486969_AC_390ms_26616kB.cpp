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

struct Node {
    int l, r;
    int sum;
} node[maxn * 25];
struct Ask {
    int id;
    int l, r, k;
} ask[maxn << 1];
int rt[maxn];
vector<int> vv;

void init() {
    n = 0;
    tol = 0;
    mes(rt, 0);
    vv.clear();
}

int getid(int x) {
    return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void update(int l, int r, int &x, int y, int pos) {
    x = ++tol;
    node[x] = node[y];
    node[x].sum++;
    if(l == r)	return ;
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(l, mid, node[x].l, node[y].l, pos);
    else
        update(mid+1, r, node[x].r, node[y].r, pos);
}

int query1(int l, int r, int x, int y, int k) {
    if(l == r)	return l;
    int mid = (l + r) >> 1;
    int cnt = node[node[y].l].sum - node[node[x].l].sum;
    if(k <= cnt)
        return query1(l, mid, node[x].l, node[y].l, k);
    else
        return query1(mid+1, r, node[x].r, node[y].r, k-cnt);
}

int query2(int l, int r, int x, int k) {
    if(l == r)	return node[x].sum;
    int mid = (l + r) >> 1;
    if(k <= mid)
        return query2(l, mid, node[x].l, k);
    else
        return node[node[x].l].sum + query2(mid+1, r, node[x].r, k);
}

int main() {
    cas = 1;
    char str[10];
    while(~scanf("%d", &m)) {
        init();
        int tot = 0;
        for(int i=1; i<=m; i++) {
            scanf("%s", str+1);
            int len = strlen(str+1);
            if(str[1] == 'I') {
                ask[++tot].id = 1;
                scanf("%d", &ask[tot].l);
                vv.push_back(ask[tot].l);
            } else {
                if(str[len] == '1') {
                    ask[++tot].id = 2;
                    scanf("%d%d%d", &ask[tot].l, &ask[tot].r, &ask[tot].k);
                } else if(str[len] == '2') {
                    ask[++tot].id = 3;
                    scanf("%d", &ask[tot].k);
                } else {
                    ask[++tot].id = 4;
                    scanf("%d", &ask[tot].k);
                }
            }
        }
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        node[0].sum = 0;
        ll ans1, ans2, ans3;
        ans1 = ans2 = ans3 = 0;
        for(int i=1; i<=m; i++) {
            int id = ask[i].id;
            if(id == 1) {
                n++;
                update(1, 100000, rt[n], rt[n-1], getid(ask[i].l));
            } else if(id == 2) {
                ans1 += vv[query1(1, 100000, rt[ask[i].l-1], rt[ask[i].r], ask[i].k) - 1];
            } else if(id == 3) {
                ans2 += query2(1, 100000, rt[n], getid(ask[i].k));
            } else {
                ans3 += vv[query1(1, 100000, rt[0], rt[n], ask[i].k) - 1];
            }
        }
        printf("Case %d:\n", cas++);
        printf("%lld\n", ans1);
        printf("%lld\n", ans2);
        printf("%lld\n", ans3);
    }
    return 0;
}
