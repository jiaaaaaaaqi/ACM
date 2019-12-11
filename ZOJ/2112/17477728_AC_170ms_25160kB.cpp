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
	int sum;
} node[maxn * 40];
struct Ask{
	int l, r, k;
	int id;
} ask[maxn / 3];
int a[maxn];
int S[maxn];
int rt[maxn];
int use[maxn];//use表示的树状数组过程到达的是哪一个子树
vector<int> vv;
int L, R;

int getid(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void init() {
	tol = 0;
	mes(a, 0);
	mes(S, 0);
	mes(rt, 0);
	vv.clear();
	mes(use, 0);
	mes(ask, 0);
	mes(node, 0);
}

int Sum(int pos) {
	int ans = 0;
	for(int i=pos; i; i-=lowbit(i)) 
		ans += node[node[use[i]].l].sum;
	return ans;
}

void update(int l, int r, int &x, int y, int pos, int val) {
	x = ++tol;
	node[tol] = node[y];
	node[tol].sum += val;
	if(l == r)	return ;
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(l, mid, node[x].l, node[y].l, pos, val);
	else
		update(mid+1, r, node[x].r, node[y].r, pos, val);
}

void add(int pos, int k, int v) {
	for(int i=pos; i<=n; i+=lowbit(i)) {
		update(1, vv.size(), S[i], S[i], k, v);
	}
}

int query(int l, int r, int x, int y, int k) {
	if(l == r)	return l;
	int mid = (l + r) >> 1;
	int tmp = Sum(R) - Sum(L) + node[node[y].l].sum - node[node[x].l].sum;
	if(k <= tmp) {
		//往现在到达的x，y位置的两棵树的左边查询，use记录树状数组对应的是那些树
		for(int i=L; i; i-=lowbit(i))	use[i] = node[use[i]].l;
		for(int i=R; i; i-=lowbit(i))	use[i] = node[use[i]].l;
		return query(l, mid, node[x].l, node[y].l, k);
	} else {
		//往现在到达的x，y位置的两棵树的右边查询，use记录树状数组对应的是那些树
		for(int i=L; i; i-=lowbit(i))	use[i] = node[use[i]].r;
		for(int i=R; i; i-=lowbit(i))	use[i] = node[use[i]].r;
		return query(mid+1, r, node[x].r, node[y].r, k-tmp);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		node[0].l = node[0].r = rt[0] = 0;
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			vv.push_back(a[i]);
		}
		for(int i=1; i<=m; i++) {
			char ss[5];
			scanf("%s", ss);
			if(ss[0] == 'Q') {
				ask[i].id = 1;
				scanf("%d%d%d", &ask[i].l, &ask[i].r, &ask[i].k);
			} else {
				ask[i].id = 0;
				scanf("%d%d", &ask[i].l, &ask[i].r);
				vv.push_back(ask[i].r);
			}
		}
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		for(int i=1; i<=n; i++) {
			int id = getid(a[i]);
			update(1, vv.size(), rt[i], rt[i-1], id, 1);
		}
		for(int i=1; i<=m; i++) {
			if(ask[i].id) {
				L = ask[i].l-1, R = ask[i].r;
				//从S数的L和R位置开始, use表示的从L,R的S树开始
				for(int j=L; j; j-=lowbit(j))	use[j] = S[j];
				for(int j=R; j; j-=lowbit(j))	use[j] = S[j];
				int pos = query(1, vv.size(), rt[L], rt[R], ask[i].k);
				printf("%d\n", vv[pos-1]);
			} else {
				int id = getid(a[ask[i].l]);
				add(ask[i].l, id, -1);
				id = getid(ask[i].r);
				add(ask[i].l, id, 1);
				a[ask[i].l] = ask[i].r;
			}
		}
	}
	return 0;
}
