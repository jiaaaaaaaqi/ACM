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
const int maxn = 10000;
const int maxm = 400;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
bool vis[maxn][maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        int x, y, a, b;
        memset(vis, 0, sizeof vis);
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if(a == 0 && b == 0) {
			printf("0\n");
			continue;
        }
		if(x <= 1 && a != 0) {
			printf("INF\n");
			continue;
		}
		if(y <= 1 && b != 0) {
			printf("INF\n");
			continue;
		}
        int ans = 0;
        int tmp;
        bool flag = false;
        while(a >= x || b >= y) {
            tmp = a / x;
            ans += tmp;
            a -= tmp * x;
            a += tmp;
            b += tmp;
            //printf("%d %d\n", a, b);
            if(vis[a][b]) {
				flag = true;
				break;
            }
            vis[a][b] = true;
            tmp = b / y;
            if(tmp == 0)	continue;
            ans += tmp;
            b -= tmp * y;
            a += tmp;
            b += tmp;
            //printf("%d %d\n", a, b);
            if(vis[a][b]) {
				flag = true;
				break;
            }
            vis[a][b] = true;
        }
		if(!flag)	printf("%d\n", ans);
		else	printf("INF\n");
    }
    return 0;
}
