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
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEM     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1000005;
const int    maxm = 10001 * 50;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct AC {
    struct Trie {
        int next[26];
        int fail, cnt;
    } trie[maxm];
    int tol;
    std::queue<int> q;

    void init() {
        while (!q.empty())
            q.pop();
        for (int i = 0; i < maxm; i++) {
            mes(trie[i].next, 0);
            trie[i].fail = 0;
            trie[i].cnt = 0;
        }
        tol = 1;
    }

    void insert(char *s) {
        int len = strlen(s + 1);
        int root = 0;
        for (int i = 1; i <= len; i++) {
            int k = s[i] - 'a';
            if (!trie[root].next[k]) {
                trie[root].next[k] = tol++;
            }
            root = trie[root].next[k];
        }
        trie[root].cnt++;
    }

    void build() {
        trie[0].fail = -1;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (trie[u].next[i]) {
                    if (u == 0)
                        trie[trie[u].next[i]].fail = 0;
                    else {
                        int v = trie[u].fail;
                        while (v != -1) {
                            if (trie[v].next[i]) {
                                trie[trie[u].next[i]].fail = trie[v].next[i];
                                break;
                            }
                            v = trie[v].fail;
                        }
                        if (v == -1)
                            trie[trie[u].next[i]].fail = 0;
                    }
                    q.push(trie[u].next[i]);
                }
            }
        }
    }

    int calc(int u) {
        int ans = 0;
        while (u) {
            ans += trie[u].cnt;
            trie[u].cnt = 0;
            u = trie[u].fail;
        }
        return ans;
    }

    int match(char *s) {
        int len = strlen(s + 1);
        int ans = 0, root = 0;
        for (int i = 1; i <= len; i++) {
            int k = s[i] - 'a';
            if (trie[root].next[k]) {
                root = trie[root].next[k];
            }
            else {
                int p = trie[root].fail;
                while (p != -1 && trie[p].next[k] == 0)
                    p = trie[p].fail;
                if (p == -1)
                    root = 0;
                else
                    root = trie[p].next[k];
            }
            if (trie[root].cnt)
                ans += calc(root);
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
        int ans = ac.match(s);
        printf("%d\n", ans);
    }
    return 0;
}