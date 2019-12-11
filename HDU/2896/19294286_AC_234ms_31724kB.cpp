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

struct AC {
	struct Node{
		int next[135];
		int fail, id;
		
		void init() {
			mes(next, 0);
			fail = id = 0;
		}
	} node[maxn];
	int tol;
	
	void init() {
		tol = 0;
		node[0].init();
	}
	
	void insert(char *s, int id) {
		int len = strlen(s+1);
		int rt = 0;
		for(int i=1; i<=len; i++) {
			int k = s[i];
			if(!node[rt].next[k]) {
				node[++tol].init();
				node[rt].next[k] = tol;
			}
			rt = node[rt].next[k];
		}
		node[rt].id = id;
	}
	
	void build() {
		queue<int> q;
		while(!q.empty())	q.pop();
		node[0].fail = -1;
		q.push(0);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i=0; i<=130; i++) {
				if(!node[u].next[i])	continue;
				int k = node[u].next[i];
				if(u == 0) {
					node[k].fail = 0;
				} else {
					int v = node[u].fail;
					while(v != -1) {
						if(node[v].next[i]) {
							node[k].fail = node[v].next[i];
							break;
						}
						v = node[v].fail;
					}
					if(v == -1) {
						node[k].fail = 0;
					}
				}
				q.push(k);
			}
		}
	}
	
	set<int> st;
	void calc(int rt) {
		while(rt) {
			int id = node[rt].id;
			if(id)	st.insert(id);
			rt = node[rt].fail;
		}
	}
	
	int query(char *s, int id) {
		st.clear();
		int len = strlen(s+1);
		int ans = 0, rt = 0;
		for(int i=1; i<=len; i++) {
			int k = s[i];
			if(node[rt].next[k]) {
				rt = node[rt].next[k];
			} else {
				int v = node[rt].fail;
				while(v!=-1 && node[v].next[k]==0)
					v = node[v].fail;
				if(v == -1) {
					rt = 0;
				}
				else {
					rt = node[v].next[k];
				}
			}
			if(node[rt].id) {
				calc(rt);
			}
		}
		int sz = st.size();
		if(sz>0 && sz<=3) {
			printf("web %d:", id);
			for(auto i : st) {
				printf(" %d", i);
			}
			printf("\n");
			return 1;
		} else {
			return 0;
		}
	}
} ac;
char s[maxn];

int main() {
	while(~scanf("%d", &n)) {
		ac.init();
		for(int i=1; i<=n; i++) {
			scanf("%s", s+1);
			ac.insert(s, i);
		}
		ac.build();
		scanf("%d", &m);
		int ans = 0;
		for(int i=1; i<=m; i++) {
			scanf("%s", s+1);
			ans += ac.query(s, i);
		}
		printf("total: %d\n", ans);
	}
	return 0;
}
