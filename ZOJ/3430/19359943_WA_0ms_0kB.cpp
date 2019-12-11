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
const int    maxn = 6e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 100000;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct AC {
    map<char, int> mp;
    struct Node {
        int next[260];
        int cnt, fail, used;
        void init() {
            mes(next, -1);
            cnt = fail = 0;
        }
    } node[maxn];
    char t[maxn];
    int tmp[maxn], s[maxn];

    void handle() {
        for(int i=0; i<=25; i++) {
            mp['A'+i] = i;
        }
        for(int i=26; i<=51; i++) {
            mp['a'+i-26] = i;
        }
        for(int i=52; i<=61; i++) {
            mp['0'+i-52] = i;
        }
        mp['+'] = 62;
        mp['/'] = 63;
    }

    char get(int x) {
        if(x == 0)	return 0;
        else	return 1;
    }

    int solve() {
        int tl = strlen(t+1);
        mes(s, 0);
        mes(tmp, 0);
        int tpl = 0;
        for(int i=1; i<=tl; i++) {
            if(t[i] == '=')	break;
            int x = mp[t[i]];
            for(int j=1; j<=6; j++) {
                int bit = 6-j+1;
                tmp[++tpl] = get(x&(1<<(bit-1)));
            }
        }
        while(t[tl] == '=') {
            tl--;
            tpl-=2;
        }
//        for(int i=1; i<=tpl; i++) {
//			printf("%d%c", tmp[i], i==tpl ? '\n' : ' ');
//        }
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

    int sz;
    void init() {
        sz = 0;
        node[sz].init();
    }

    void insert(int len) {
        int rt = 0;
        for(int i=1; i<=len; i++) {
            int k = s[i];
            if(node[rt].next[k] == -1) {
                node[++sz].init();
                node[rt].next[k] = sz;
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
                int k = node[u].next[i];
                if(k == -1) {
                    if(u == 0)	k = 0;
                    else	k = node[node[u].fail].next[i];
                } else {
                    if(u == 0)	node[k].fail = 0;
                    else {
                        int v = node[u].fail;
                        while(v != -1) {
                            if(node[v].next[i] != -1) {
                                node[k].fail = node[v].next[i];
                                break;
                            }
                            v = node[v].fail;
                        }
                        if(v == -1)	node[k].fail = 0;
                    }
                    q.push(k);
                }
            }
        }
    }

    void calc(int rt) {
        while(rt) {
//            if(node[rt].cnt)
                node[rt].used = 1;
            rt = node[rt].fail;
        }
    }

    int query(int len) {
        for(int i=0; i<=sz; i++) {
            node[i].used = 0;
        }
        int rt = 0, ans = 0;
        for(int i=1; i<=len; i++) {
            int k = s[i];
            if(node[rt].next[k] != -1) {
                rt = node[rt].next[k];
            } else {
                int v = node[rt].fail;
                while(v!=-1 && node[v].next[k]==-1)
                    v = node[v].fail;
                if(v == -1)	rt = 0;
                else {
                    rt = node[v].next[k];
                }
            }
            if(node[rt].cnt)	calc(rt);
        }
        for(int i=0; i<=sz; i++) {
            ans += node[i].used;
        }
        return ans;
    }

} ac;

int main() {
    ac.handle();
//    while(1) {
//        scanf("%s", ac.t+1);
//        int len = ac.solve();
//        for(int i=1; i<=len; i++) {
//            printf("%c", ac.s[i]);
//        }
//        printf("\n");
//    }
    while(~scanf("%d", &n)) {
        ac.init();
        for(int i=1; i<=n; i++) {
            scanf("%s", ac.t+1);
            int len = ac.solve();
            ac.insert(len);
        }
        ac.build();
        scanf("%d", &m);
        for(int i=1; i<=m; i++) {
            scanf("%s", ac.t+1);
            int len = ac.solve();
            printf("%d\n", ac.query(len));
        }
        printf("\n");
    }
    return 0;
}
