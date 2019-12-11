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

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 100000 * 15;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int trie[maxm][27];
int id[maxm];
char ans[maxn][11];

void init() {
    tol = 1;
    mes(id, 0);
    mes(trie[0], 0);
}

void insert(char *s, int val) {
    int len = strlen(s);
    int root = 0;
    int k;
    for(int i=0; i<len; i++) {
        k = s[i] - 'a';
        if(trie[root][k] == 0) {
            mes(trie[tol], 0);
            trie[root][k] = tol++;
        }
        root = trie[root][k];
    }
    id[root] = val;
}

bool find(char *s) {
    int len = strlen(s);
    int root = 0;
    int k;
    bool flag = true;
    for(int i=0; i<len; i++) {
        k = s[i] - 'a';
        if(trie[root][k] == 0) {
            flag = false;
            break;
        }
        root = trie[root][k];
    }
    if(flag && id[root]) 
        printf("%s\n", ans[id[root]]);
    else
        printf("eh\n");
}

int main() {
    init();
    char s[22];
    char s1[11];
    for(int i=1; ; i++) {
        gets(s);
        if(s[0] == '\0')    break;
        sscanf(s, "%s%s", ans[i], s1);
        insert(s1, i);
    }
    while(~scanf("%s", s)) {
        find(s);
    }
    return 0;
}