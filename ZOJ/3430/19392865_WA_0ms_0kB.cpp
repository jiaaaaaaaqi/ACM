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
const int    maxn = 520*64;
const int    maxm = 1e6 + 10;
const ll     mod  = 100000;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

#include<assert.h>
struct AC {
    int mp[260];
    char t[maxm];
    int tmp[maxm], s[maxm];

    void handle() {
    	mes(mp, 0);
        for(int i=0; i<=25; i++) {
            mp[i+'A'] = i;
        }
        for(int i=26; i<=51; i++) {
            mp[i-26+'a'] = i;
        }
        for(int i=52; i<=61; i++) {
            mp[i-52+'0'] = i;
        }
        mp['+'] = 62;
        mp['/'] = 63;
    }

    int get(int x) {
        if(x == 0)	return 0;
        else	return 1;
    }

    int solve() {
        int tl = strlen(t+1);
        mes(s, 0);
        mes(tmp, 0);
        int tpl = 0;
        for(int i=1; i<=tl; i++) {
            if(t[i] == '=') {
				tpl -= 2;
            } else {
				int x = mp[t[i]];
				for(int j=1; j<=6; j++) {
					int bit = 6-j+1;
					tmp[++tpl] = get(x&(1<<(bit-1)));
				}
            }
        }
        int sl = 0;
        for(int i=1; i<=tpl; i+=8) {
            int x = 0;
            for(int j=i; j<=i+7; j++) {
                x = x*2+tmp[j];
            }
            s[++sl] = x;
        }
        return sl;
    }
    /*************************************************************/
struct Node{
		int next[260];
		int fail, cnt;
		
		void init() {
			mes(next, 0);
			fail = cnt = 0;
		}
	} node[maxn];
	int tol;
	bool vis[maxn];
	
	void init() {
		tol = 0;
		node[0].init();
	}
	
	void insert(int len) {
		int rt = 0;
		for(int i=1; i<=len; i++) {
			int k = s[i];
			if(!node[rt].next[k]) {
				node[++tol].init();
				node[rt].next[k] = tol;
			}
			rt = node[rt].next[k];
		}
		node[rt].cnt++;
	}
	
	void build() {
		queue<int> q;
		while(!q.empty())	q.pop();
		node[0].fail = -1;
		q.push(0);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i=0; i<=256; i++) {
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
	
	int calc(int rt) {
		int ans = 0;
		while(rt) {
			if(!vis[rt])
				ans += node[rt].cnt;
			vis[rt] = 0;
			rt = node[rt].fail;
		}
		return ans;
	}
	
	int query(int len) {
		mes(vis, 0);
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
			ans += calc(rt);
		}
		return ans;
	}

} ac;

int main() {
    ac.handle();
    while(~scanf("%d", &n)) {
        ac.init();
        for(int i=1; i<=n; i++) {
            mes(ac.t, 0);
            scanf("%s", ac.t+1);
            int len = ac.solve();
            ac.insert(len);
        }
        ac.build();
        scanf("%d", &m);
        for(int i=1; i<=m; i++) {
            mes(ac.t, 0);
            scanf("%s", ac.t+1);
            int len = ac.solve();
            printf("%d\n", ac.query(len));
        }
        printf("\n");
    }
    return 0;
}