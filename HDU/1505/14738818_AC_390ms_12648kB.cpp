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
const int maxn = 1200;
const int maxm = 30005;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
struct Node {
    int h;
    int l;
};
Node q[maxn];
char str[maxn << 1][maxn << 1];
int maps[maxn][maxn];

void init() {
    memset(maps, 0, sizeof maps);
    memset(str, 0, sizeof str);
}

ll solve(int num[]) {
    ll ans = 0;
    int head = 0;
    int tail = 0;
    for(int i=1; i<=m; i++) {
        int y = 0;
        while(head < tail && q[tail-1].h > num[i]) {
            q[tail-1].l += y;
            ans = max(ans, (ll)q[tail-1].h * q[tail-1].l);
            y++;
            tail--;
        }
        q[tail].h = num[i];
        q[tail++].l = 1;
    }
    int y = 0;
    while(head < tail) {
        q[tail-1].l += y;
        ans = max(ans, (ll)q[tail-1].h * q[tail-1].l);
        y++;
        tail--;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        getchar();
        for(int i=1; i<=n; i++) {
            int j = 1;
            char ch;
            while(scanf("%c", &ch)) {
                if(ch == 'R')	maps[i][j] = 0, j++;
                else if(ch == 'F')	maps[i][j] = maps[i-1][j] + 1, j++;
                else	continue;
                if(j == m + 1)	break;
            }
        }
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            ll res = solve(maps[i]);
            ans = max(ans, res);
        }
        printf("%lld\n", ans * 3);
    }
    return 0;
}
