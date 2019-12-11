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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[2000005];
char s1[maxn][55];
struct Trie {
    int next[26];
    int fail, id, cnt;
} trie[maxm];
std::queue<int> q;
std::map<int, int> mp;

void init() {
    mes(trie[0].next, 0);
    trie[0].fail = trie[0].id = trie[0].cnt = 0;
    tol = 1;
}

void insert(char *s, int id) {
    int len = strlen(s + 1);
    int root = 0;
    for (int i = 1; i <= len; i++) {
        int k = s[i] - 'A';
        if (!trie[root].next[k]) {
            mes(trie[tol].next, 0);
            trie[tol].fail = 0;
            trie[tol].id = 0;
            trie[tol].cnt = 0;
            trie[root].next[k] = tol++;
        }
        root = trie[root].next[k];
    }
    trie[root].id = id;
    trie[root].cnt = 1;
}

void build() {
    while (!q.empty())
        q.pop();
    trie[0].fail = -1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (trie[u].next[i]) {
                int k = trie[u].next[i];
                if (u == 0)
                    trie[k].fail = 0;
                else {
                    int v = trie[u].fail;
                    while (v != -1) {
                        if (trie[v].next[i]) {
                            trie[k].fail = trie[v].next[i];
                            break;
                        }
                        v = trie[v].fail;
                    }
                    if (v == -1)
                        trie[k].fail = 0;
                }
                q.push(k);
            }
        }
    }
}

void calc(int u) {
    while (u) {
        int x = trie[u].id;
        if (trie[u].cnt) {
            mp[x] += trie[u].cnt;
        }
        u = trie[u].fail;
    }
}

void search(char *s) {
    int len = strlen(s + 1);
    int root = 0;
    for (int i = 1; i <= len; i++) {
        if (!isupper(s[i])) {
            root = 0;
            continue;
        }
        int k = s[i] - 'A';
        if (trie[root].next[k])
            root = trie[root].next[k];
        else {
            root = trie[root].fail;
            while (root != -1 && trie[root].next[k] == 0)
                root = trie[root].fail;
            if (root == -1)
                root = 0;
            else
                root = trie[root].next[k];
        }
        if (trie[root].id)
            calc(root);
    }
    for (auto it : mp) {
        printf("%s: %d\n", s1[it.fi] + 1, it.se);
    }
}

int main() {
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%s", s1[i] + 1);
            insert(s1[i], i);
        }
        build();
        int ans = 0;
        scanf("%s", s + 1);
        search(s + 1);
    }
    return 0;
}