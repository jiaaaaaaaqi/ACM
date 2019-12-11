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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int vis[maxn];
int lg2[maxn];
int dpmax[maxn][30];
int dpmin[maxn][30];

void handle() {
	for(int i=0; i<=n; i++) {
		lg2[i] = log2(1.0*i);
	}
    for(int i=1; i<=n; i++) {
        if(a[i]) {
            dpmax[i][0] = a[i];
            dpmin[i][0] = a[i];
        } else {
            dpmax[i][0] = -inf;
            dpmin[i][0] = inf;
        }
    }
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=1; i<=n; i++) {
            if(i+(1<<j)-1 <= n) {
                dpmax[i][j] = max(dpmax[i][j-1], dpmax[i+(1<<(j-1))][j-1]);
                dpmin[i][j] = min(dpmin[i][j-1], dpmin[i+(1<<(j-1))][j-1]);
            }
        }
    }
}

int querymax(int l, int r) {
    int k = lg2[r-l+1];
    return max(dpmax[l][k], dpmax[r-(1<<k)+1][k]);
}

int querymin(int l, int r) {
    int k = lg2[r-l+1];
    return min(dpmin[l][k], dpmin[r-(1<<k)+1][k]);
}

bool ok(int len) {
    for(int i=1; i<=m; i++) {
        vis[i] = false;
    }
    int cnt = 0;
    int ans = 0;
    for(int i=1; i<=len; i++) {
        if(a[i] != 0) {
            vis[a[i]]++;
            if(vis[a[i]] == 1)
                ans++;
        } else	cnt++;
    }
    int mx = querymax(1, len);
    int mn = querymin(1, len);
    if(mx == -inf) {
        if(cnt == len)	return true;
    } else {
        if(mx-mn+1 <= ans+cnt && ans+cnt==len)	return true;
    }
    int l = 1, r = len;
    while(r < n) {
        r++;
        if(a[r] != 0) {
            vis[a[r]]++;
            if(vis[a[r]] == 1)
                ans++;
        } else {
            cnt++;
        }

        if(a[l] != 0) {
            vis[a[l]]--;
            if(vis[a[l]] == 0)
                ans--;
        } else {
            cnt--;
        }
        l++;
        mx = querymax(l, r);
        mn = querymin(l, r);
        if(mx == -inf) {
            if(cnt == len)	return true;
        } else {
            if(mx-mn+1 <= ans+cnt && ans+cnt==len)	return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        handle();
        int L = 1, R = n, ans = 0;
        while (L <= R) {
            int mid = (L+R) / 2;
            if (ok(mid)) L = mid+1, ans=mid;
            else R = mid-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
