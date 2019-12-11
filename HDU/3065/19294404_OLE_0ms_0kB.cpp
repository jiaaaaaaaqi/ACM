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
const int    maxn = 5e4 + 10;
const int    maxm = 2e6 + 10;
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
		int next[131];
		int fail, id;
		
		void init() {
			mes(next, 0);
			fail = id = 0;
		}
	} node[maxn];
	map<int, int> mp;
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
	
	void calc(int rt) {
		while(rt) {
			if(node[rt].id) {
				if(mp.count(node[rt].id))
					mp[node[rt].id]++;
				else
					mp[node[rt].id] = 1;
			}
			rt = node[rt].fail;
		}
	}
	
	map<int, int> query(char *s) {
		mp.clear();
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
		return mp;
	}
} ac;
char s[maxm];
char ss[55][1005];

int main() {
	while(~scanf("%d", &n)) {
		mes(s, 0);
		mes(ss, 0);
		ac.init();
		for(int i=1; i<=n; i++) {
			scanf("%s", ss[i]+1);
			ac.insert(ss[i], i);
		}
		ac.build();
		scanf("%s", s+1);
		auto mp = ac.query(s);
		for(auto i : mp) {
			printf("%s: %d\n", ss[i.fi]+1, i.se);
		}
	}
	return 0;
}
