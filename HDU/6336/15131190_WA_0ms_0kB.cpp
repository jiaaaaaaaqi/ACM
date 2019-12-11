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
const int maxn = 1e5+10;
const int maxm = 10000007;
const int mod = 1e9+7;
using namespace std;

int n, m, tol, T;
int L;
int A[15];
int M[100][100];
ll sx[30];
ll sy[30];
ll sum;

void init() {
    sum = 0;
    memset(A, 0, sizeof A);
    memset(M, 0, sizeof M);
    memset(sx, 0, sizeof sx);
    memset(sy, 0, sizeof sy);
}

ll solve(int x, int y) {
    ll ans = 0;
    int cx = x/L;
    int cy = y/L;
    int t = cx * cy;
    ans += 1ll * t * sum;
    int x1 = x % L;
    int y1 = y % L;
    ll s = 0;
    for(int i=1; i<=x1; i++)	s += sx[i];
    ans += s * cy;
    s = 0;
    for(int i=1; i<=y1; i++)	s += sy[i];
    ans += s * cx;
    for(int i=1; i<=x1; i++) {
        for(int j=1; j<=y1; j++) {
            ans += M[i][j];
        }
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &L);
        for(int i=0; i<L; i++)	scanf("%d", &A[i]);
        int cursor = 0;
        for(int i=1; i<=4*L; i++) {
            for(int j=1; j<=i; j++) {
                M[j][i - j+1] = A[cursor];
                cursor = (cursor + 1) % L;
            }
        }
        L <<= 1;
        for(int i=1; i<=L; i++) {
            for(int j=1; j<=L; j++) {
                sy[j] += M[i][j];
                sx[i] += M[i][j];
            }
            sum += sx[i];
        }
        /*
        for(int i=1; i<=L; i++)	for(int j=1; j<=L; j++)	printf("%d%c",M[i][j], j==L ? '\n' : ' \t');
        for(int i=1; i<=L; i++)	printf("sx%d = %d\n", i, sx[i]);
        for(int i=1; i<=L; i++)	printf("sy%d = %d\n", i, sy[i]);
        */
        int q;
        scanf("%d", &q);
        while(q--) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1++, y1++, x2++, y2++;
            ll ans = solve(x2, y2);
            ans -= solve(x1-1, y2);
            ans -= solve(x2, y1-1);
            ans += solve(x1-1, y1-1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
