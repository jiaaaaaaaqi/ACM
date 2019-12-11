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
#define  INOPEM     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef long long int ll;
typedef unsigned long long int ull;
const int    maxn = 1e4+10;
const int    maxm = 100000;
const int    mod  = 256;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
struct Node{
    int id;
    int v, k;
    Node() {
        id = v = k = 0;
    }
} node[maxn];
bool vis[maxn][260];

void init() {
    memset(vis, 0, sizeof vis);
}

bool find() {
    int st = 1;
    int ans = 0;
    while(1) {
        if(st > n)
            return true;
        int id = node[st].id;
        if(vis[st][ans])
            return false;
        vis[st][ans] = true;
        int v = node[st].v;
        int k = node[st].k;
        if(id == 1) {
            ans = (ans + v) % mod;
            st = st + 1;
            continue;
        }
        if(id == 2) {
            if(ans == v)
                st = k;
            else
                st = st + 1;
            continue;
        }
        if(id == 3) {
            if(ans != v)
                st = k;
            else
                st = st + 1;
            continue;
        }
        if(id == 4) {
            if(ans < v)
                st = k;
            else
                st = st + 1;
        }
        if(id == 5) {
            if(ans > v)
                st = k;
            else
                st = st + 1;
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        char s[10];
        for(int i=1; i<=n; i++) {
            scanf("%s", s);
            if(strcmp(s, "add") == 0)
                scanf("%d", &node[i].v);
            else
                scanf("%d%d", &node[i].v, &node[i].k);
            if(strcmp(s, "add") == 0)   node[i].id = 1;
            if(strcmp(s, "beq") == 0)   node[i].id = 2;
            if(strcmp(s, "bne") == 0)   node[i].id = 3;
            if(strcmp(s, "blt") == 0)   node[i].id = 4;
            if(strcmp(s, "bgt") == 0)   node[i].id = 5;
        }
        bool ans = find();
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}