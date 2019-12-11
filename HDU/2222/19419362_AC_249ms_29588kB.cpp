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
const int    maxn = 1e6 + 10;
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
    int next[maxn][27], fail[maxn], last[maxn], cnt[maxn];
    int root, tol;
    int newnode() {
        for(int i=1; i<=26; i++)
            next[tol][i] = -1;
        cnt[tol++] = 0;
        return tol - 1;
    }
    void init() {
        tol = 0;
        root = newnode();
    }
    void insert(char *s) {
        int len = strlen(s+1);
        int rt = root;
        for(int i=1; i<=len; i++) {
            int k = s[i]-'a'+1;
            if(next[rt][k] == -1) {
                next[rt][k] = newnode();
            }
            rt = next[rt][k];
        }
        cnt[rt]++;
    }
    void build() {
        queue<int> q;
        fail[root] = root;
        for(int i=1; i<=26; i++) {
            if(next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            last[u] = cnt[fail[u]] ? fail[u] : last[fail[u]];
            q.pop();
            for(int i = 1; i <= 26; i++) {
                if(next[u][i] == -1)
                    next[u][i] = next[fail[u]][i];
                else {
                    fail[next[u][i]] = next[fail[u]][i];
                    q.push(next[u][i]);
                }
            }
        }
    }
    int calc(int rt) {
        int ans = 0;
        while(rt) {
            ans += cnt[rt];
            cnt[rt] = 0;
            rt = last[rt];
        }
        return ans;
    }
    int query(char *s) {
        int len = strlen(s+1);
        int rt = root;
        int ans = 0;
        for(int i = 1; i <= len; i++) {
            int k = s[i]-'a'+1;
            rt = next[rt][k];
            if(cnt[rt])	ans += calc(rt);
            else if(last[rt])	ans += calc(last[rt]);
        }
        return ans;
    }
} ac;
char s[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        ac.init();
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%s", s+1);
            ac.insert(s);
        }
        ac.build();
        scanf("%s", s+1);
        printf("%d\n", ac.query(s));
    }
    return 0;
}
