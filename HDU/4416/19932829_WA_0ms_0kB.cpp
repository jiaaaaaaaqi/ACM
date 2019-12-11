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

char s[maxm], t[maxm];
int a[maxn], sa[maxn], rk[maxn], tp[maxn], tax[maxn], height[maxn];
int tmpans[maxn];

void rsort(int n, int m) {
    for (int i = 0; i <= m; i++) tax[i] = 0;
    for (int i = 1; i <= n; i++) tax[rk[tp[i]]]++;
    for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}

int cmp(int *f, int x, int y, int w) {
    return f[x] == f[y] && f[x + w] == f[y + w];
}

void SA(int *a, int n, int m) {
    for(int i=1; i<=n; i++)	rk[i] = a[i], tp[i] = i;
    rsort(n, m);
    for(int w = 1, p = 1, i; p < n; w <<= 1, m = p) {
        for(p = 0, i = n - w + 1; i <= n; i++)	tp[++p] = i;
        for(i = 1; i <= n; i++)	if(sa[i] > w)	tp[++p] = sa[i] - w;
        rsort(n, m), swap(rk, tp);
        rk[sa[1]] = p = 1;
        for(i = 2; i <= n; i++)	rk[sa[i]] = cmp(tp, sa[i], sa[i-1], w) ? p : ++p;
    }
    n--;
    int j, k = 0;
    for(int i=1; i<=n; height[rk[i++]] = k)
        for(k = k ? k-1 : k, j = sa[rk[i]-1]; a[i+k] == a[j+k]; k++);
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        n = 0;
        scanf("%d", &m);
        scanf("%s", s+1);
        int slen = strlen(s+1);
        for(int i=1; i<=slen; i++) {
            a[++n] = s[i];
        }
        for(int i=1; i<=m; i++) {
            a[++n] = i+'z';
            scanf("%s", t+1);
            int tlen = strlen(t+1);
            for(int j=1; j<=tlen; j++) {
                a[++n] = t[j];
            }
        }
        a[++n] = 0;
        SA(a, n, m+'z');
//        for(int i=1; i<=n; i++) {
//			printf("%d %d %d\n", sa[i], sa[i-1], height[i]);
//        }
        mes(tmpans, 0);
        int tmp = inf;
        for(int i=2; i<=n; i++) {
			if(sa[i] <= slen) {
				tmp = min(tmp, height[i]);
				tmpans[sa[i]] = max(tmpans[sa[i]], tmp);
			} else {
				tmp = inf;
			}
        }
        tmp = inf;
        for(int i=n; i>=2; i--) {
			if(sa[i-1] <= slen) {
				tmp = min(tmp, height[i]);
				tmpans[sa[i-1]] = max(tmpans[sa[i-1]], tmp);
			} else {
				tmp = inf;
			}
        }
        ll ans = 1ll*(slen+1)*slen / 2;
        for(int i=2; i<=n; i++) {
			if(sa[i]<=slen && sa[i-1]<=slen)
				tmpans[sa[i]] = max(tmpans[sa[i]], height[i]);
        }
        for(int i=1; i<=slen; i++) {
			ans -= tmpans[i];
        }
        printf("Case %d: %lld\n", cas++, ans);
    }
    return 0;
}

