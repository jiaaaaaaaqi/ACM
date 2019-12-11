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
const int    maxn = 1e5 + 500;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int cnt;
int a[maxn];
char s[maxn];
int sa[maxn];
int tp[maxn];
int rk[maxn];
bool vis[150];
int bel[maxn];
int tax[maxn];
char ss[maxn];
int pos[1005];
int height[maxn];

void init() {
    mes(a, 0);
    mes(s, 0);
    mes(pos, 0);
    mes(bel, 0);
}

void rsort(int n, int m) {
    for(int i=0; i<=m; i++) tax[i] = 0;
    for(int i=1; i<=n; i++) tax[rk[tp[i]]]++;
    for(int i=1; i<=m; i++) tax[i] += tax[i-1];
    for(int i=n; i>=1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}

int cmp(int *f, int x, int y, int w) {
    return f[x] == f[y] && f[x+w] == f[y+w];
}

void SA(int *a, int n, int m) {
    for(int i=1; i<=n; i++) rk[i] = a[i], tp[i] = i;
    rsort(n, m);
    for(int p=1, w=1, i; p<n; w<<=1, m=p) {
        for(p=0, i=n-w+1; i<=n; i++)        tp[++p] = i;
        for(i=1; i<=n; i++) if(sa[i] > w)   tp[++p] = sa[i] - w;
        rsort(n, m), swap(rk, tp);
        rk[sa[1]] = p = 1;
        for(i=2; i<=n; i++) rk[sa[i]] = cmp(tp, sa[i], sa[i-1], w) ? p : ++p;
    }
    int j, k = 0;
    for(int i=1; i<=n; height[rk[i++]] = k)
        for(k = k ? k-1 : k, j = sa[rk[i]-1]; a[i+k] == a[j+k]; k++);
}

bool check(int head, int tail) {
    int tot = 0;
    mes(vis, 0);
    for(int i=head; i<=tail; i++) {
        if(!vis[bel[sa[i]]]) {
            vis[bel[sa[i]]] = true;
            tot++;
        }
        if(tot > m) return true;
    }
    return false;
}

bool ok(int len) {
    bool ans = false;
    int head = 1, tail = 1;
    for(int i=2; i<=n; i++) {
        if(height[i] >= len)    tail++;
        else {
            if(check(head, tail)) {
                if(!ans)    cnt = 0;
                ans = true;
                pos[++cnt] = sa[head];
            }
            head = tail = i;
        }
    }
    if(head < tail) {
        if(check(head, tail)) {
            if(!ans)    cnt = 0;
            ans = true;
            pos[++cnt] = sa[head];
        }
    }
    return ans;
}

void output(int len) {
//    printf("%d\n", cnt);
    for(int i=1; i<=cnt; i++) {
        for(int j=0; j<len; j++) {
            printf("%c", s[pos[i] + j]);
        }
        printf("\n");
    }
}

int main() {
    int k;
    int first = 0;
    while(scanf("%d", &k), k) {
        init();
        n = 1;
        for(int K=1; K<=k; K++) {
            scanf("%s", ss);
            for(int i=0; ss[i]!='\0'; i++, n++) {
                s[n] = ss[i];
                bel[n] = K;
            }
            s[n++] = '$';
        }
        n--;
        for(int i=1; i<=n; i++)
            a[i] = s[i];
        SA(a, n, 130);
//        for(int i=1; i<=n; i++)
//            printf("%d%c", sa[i], i==n ? '\n' : ' ');
        m = k / 2;
        int l = 1, r = n;
        int ans = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(ok(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r=  mid - 1;
            }
        }
        if(ans == 0) {
            printf("?\n");
        } else {
            output(ans);
        }
        printf("\n");
    }
    return 0;
}
