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
const ll     mod  = 100000;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
/*-------------------------------------------------------------*/
struct Mat {
    int sz;
    ll mat[110][110];
    void init() {
        mes(mat, 0);
    }
};

Mat mmul(Mat a, Mat b) {
    Mat ans;
    ans.init();
    ans.sz = a.sz;
    for(int i=1; i<=a.sz; i++) {
        for(int j=1; j<=a.sz; j++) {
            for(int k=1; k<=a.sz; k++) {
                ans.mat[i][j] += a.mat[i][k]*b.mat[k][j];
            }
        }
    }
    return ans;
}

Mat mpow(Mat a, ll b) {
    Mat ans;
    ans.init();
    ans.sz = a.sz;
    for(int i=1; i<=ans.sz; i++) {
        ans.mat[i][i] = 1;
    }
    while(b) {
        if(b&1)	ans = mmul(ans, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return ans;
}
/*-------------------------------------------------------------*/

struct AC {
    struct Node {
        int next[5];
        int fail, flag;
        void init() {
            mes(next, -1);
            fail = flag = 0;
        }
    } node[200];
    int sz;

    void init() {
        sz = 0;
        node[0].init();
    }

    int getid(char c) {
        if(c == 'A')	return 1;
        if(c == 'T')	return 2;
        if(c == 'C')	return 3;
        if(c == 'G')	return 4;
    }

    void insert(char *s) {
        int len = strlen(s+1);
        int rt = 0;
        for(int i=1; i<=len; i++) {
            int k = getid(s[i]);
            if(node[rt].next[k] == -1) {
                node[++sz].init();
                node[rt].next[k] = sz;
            }
            rt = node[rt].next[k];
        }
        node[rt].flag = true;
    }

    void build() {
        queue<int> q;
        while(!q.empty())	q.pop();
        node[0].fail = -1;
        q.push(0);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u && node[node[u].fail].flag) {
                node[u].flag = 1;
            }
            for(int i=1; i<=4; i++) {
                if(node[u].next[i] == -1) {
					if(u == 0)
						node[u].next[i] = 0;
					else
						node[u].next[i] = node[node[u].fail].next[i];
                } else {
					int k = node[u].next[i];
					if(u == 0) {
						node[k].fail = 0;
					} else {
						int v = node[u].fail;
						while(v != -1) {
							if(node[v].next[i] != -1) {
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
    }
} ac;

char s[15];

int main() {
    scanf("%d%d", &m, &n);
    ac.init();
    for(int i=1; i<=m; i++) {
        scanf("%s", s+1);
        ac.insert(s);
    }
    ac.build();
    Mat a;
    a.init();
    a.sz = ac.sz+1;
    for(int i=0; i<=ac.sz; i++) {
        for(int j=1; j<=4; j++) {
            int k = ac.node[i].next[j];
            if(!ac.node[k].flag) {
                a.mat[i+1][k+1]++;
            }
        }
    }
	a = mpow(a, n);
	ll ans = 0;
	for(int i=1; i<=a.sz; i++) {
		ans += a.mat[1][i];
		ans %= mod;
	}
	printf("%lld\n", ans);
    return 0;
}
