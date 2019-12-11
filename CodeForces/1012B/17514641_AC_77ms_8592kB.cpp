#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
const int maxm = 1000005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
int fa[maxn];
int X[maxn];
int Y[maxn];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void build(int x, int y) {
    int u = find(x);
    int v = find(y);
    fa[v] = u;
}

int main() {
    int q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1; i<=q; i++)	fa[i] = i;
    int x, y;
    for(int i=1; i<=q; i++) {
        scanf("%d%d", &x, &y);
        if(X[x]) {
            build(i, X[x]);
        }
        X[x] = fa[i];
        if(Y[y]) {
            build(i, Y[y]);
        }
        Y[y] = fa[i];
    }
	ll ans = -1;
    for(int i=1; i<=q; i++)
        find(i);
    for(int i=1; i<=q; i++)
        if(fa[i] == i)	ans++;
    for(int i=1; i<=n; i++)
        if(!X[i])	ans++;
    for(int i=1; i<=m; i++)
        if(!Y[i])	ans++;
    printf("%I64d\n", ans);
    return 0;
}