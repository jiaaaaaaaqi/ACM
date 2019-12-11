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
#pragma comment(linker, "/STACK:102400000,102400000")
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
    ll sum, cnt;
} node[maxn * 50];
struct Edge {
    int id;
    ll val;
    bool operator < (Edge a) const {
        return id < a.id;
    }
} edge[maxn << 1];
int rt[maxn << 1];
int last[maxn];
vector<ll> vv;

void init() {
    tol = 0;
    vv.clear();
    mes(rt, 0);
    mes(last, 0);
}

int getid(ll x) {
    return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void update(int l, int r, int &x, int y, int pos, ll val) {
    x = ++tol;
    node[x] = node[y];
    node[x].sum += val;
    if(val > 0)	node[x].cnt++;
    else	node[x].cnt--;
    if(l == r)	return ;
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(l, mid, node[x].l, node[y].l, pos, val);
    else
        update(mid+1, r, node[x].r, node[y].r, pos, val);
}

ll query(int l, int r, int x, int k) {
    if(node[x].cnt <= k)	return node[x].sum;
    if(l == r) {
		if(node[x].cnt > k) {
			return (1ll)*(node[x].sum / node[x].cnt) * k;
		} else {
			return 0;
		}
    }
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
    while(~scanf("%d%d%d%lld", &n, &m, &x, &p)) {
        init();
        int tot = 0;
        for(int i=1; i<=n; i++) {
            int l, r;
            ll v;
            scanf("%d%d%lld", &l, &r, &v);
            tot++;
            edge[tot].id = l, edge[tot].val = v;
            tot++;
            edge[tot].id = r+1, edge[tot].val = -v;
            vv.push_back(v);
        }
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        sort(edge+1, edge+1+tot);
        node[0].cnt = node[0].sum = 0ll;
        for(int i=1; i<=tot; i++) {
            int pos = edge[i].id;
            ll v = edge[i].val;
            int tmp = getid(abs(v));
            update(1, vv.size(), rt[i], rt[i-1], abs(v), v);
            last[pos] = i;
        }
        for(int i=1; i<=x; i++) {
            if(last[i])	continue;
            last[i] = last[i-1];
        }
        ll ans = 1ll;
        while(m--) {
            int pos;
            ll a, b, c;
            scanf("%d%lld%lld%lld", &pos, &a, &b, &c);
            ll k = ((a%c) * (ans%c) % c + b%c) % c;
            if(!k) {
                printf("0\n");
                ans = 0;
                continue;
            }
            if(ans > p)
                ans = query(1, vv.size(), rt[last[pos]], k) * 2;
            else
                ans = query(1, vv.size(), rt[last[pos]], k);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
