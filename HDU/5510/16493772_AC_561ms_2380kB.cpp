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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e3 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[505][maxn];
int nex[maxn];
bool vis[maxn];

void init() {
    mes(s, 0);
    mes(vis, 0);    
}

void make_next_table(char *s, int len) {
    mes(nex, 0);
    nex[0] = -1;
    int i=1, j=0;
    while(i < len) {
        if(j == -1 || s[i] == s[j]) {
            nex[++i] = ++j;
        } else {
            j = nex[j];
        }
    }
}

bool kmp(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    make_next_table(s2, len2);
    // for(int i=1; i<=len2; i++)
    //     printf("%d%c", nex[i], i==len2 ? '\n' : ' ');
    int i=0, j=0;
    while(i < len1) {
        if(j == -1 || s1[i] == s2[j]) {
            i++, j++;
        } else {
            j = nex[j];
        }
        if(j == len2)
            return true;
    }
    return false;
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%s", s[i]);
        int ans = -1;
        for(int i=2; i<=n; i++) {
            for(int j=1; j<i; j++) {
                if(vis[j])  continue;
                if(kmp(s[i], s[j])) {
                    vis[j] = true;
                }
                else {
                    ans = i;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}