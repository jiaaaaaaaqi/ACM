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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 150;
const int maxm = 250;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
char s[maxn][maxn];

int main() {
    scanf("%d%d", &n, &m);
    int mxx, mxy, mnx, mny;
    mxx = 0;
    mxy = 0;
    mnx = inf;
    mny = inf;
    bool flag1 = false;
    bool flag2 = false;
    for(int i=1; i<=n; i++) {
        scanf("%s", s[i]+1);
        for(int j=1; j<=m; j++) {
            if(s[i][j] == 'W')	flag1 = true;
            if(s[i][j] == 'B')	flag2 = true;
			if(s[i][j] == 'B') {
				mxx = max(mxx, i);
				mxy = max(mxy, j);
				mnx = min(mnx, i);
				mny = min(mny, j);
			}
        }
    }
    if(!flag1) {
        if(n != m)
            printf("-1\n");
        if(n == m)
            printf("0\n");
		return 0;
	}
    if(!flag2) {
		printf("1\n");
		return 0;
    }
    int l;
    int ans = 0;
    for(int i=mnx; i<=mxx; i++) {
		for(int j=mny; j<=mxy; j++) {
			if(s[i][j] == 'W')	ans++;
		}
    }
    if(mxx - mnx > mxy - mny) {
		l = mxy - mny + 1;
		int tmp = m - l;
		int tmp2 = (mxx - mnx) - (mxy - mny);
		if(tmp >= tmp2)
			ans += tmp2 * (mxx - mnx + 1);
		else {
			printf("-1\n");
			return 0;
		}
    } else {
		l = mxx - mnx + 1;
		int tmp = n - l;
		int tmp2 = (mxy - mny) - (mxx - mnx);
		if(tmp >= tmp2) {
			ans += tmp2 * (mxy - mny + 1);			
		} else {
			printf("-1\n");
			return 0;
		}
    }
    printf("%d\n", ans);
    return 0;
}
