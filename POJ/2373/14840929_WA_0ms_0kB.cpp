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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1000005;
const int maxm = 12;
using namespace std;

int n, m, T, tol;
int dp[maxn];
bool vis[maxn];
deque<int > q;

void init() {
    memset(dp, inf, sizeof dp);
    memset(vis, 0, sizeof vis);
}

int main() {
    while(~scanf("%d%d", &m, &n)) {
        init();
        int a, b;
        scanf("%d%d", &a, &b);
        for(int i=1; i<=m; i++) {
            int be, en;
            scanf("%d%d", &be, &en);
            for(int j=be+1; j<en; j++)	
				dp[j]++;
        }
        if(n&1) {
            printf("-1\n");
            continue;
        }
        dp[0] = 0;
        q.push_back(0);
        for(int i=0; i<=n; i+=2) {
            while(!q.empty() && i - 2*a >= 0 && dp[i - 2*a] < q.back())	q.pop_back();
            q.push_back(i-2*a);
            if(dp[i] > inf || i < 2*a)	continue;
            while(!q.empty() && q.front() + 2*b < i)	q.pop_front();
            dp[i] = dp[q.front()] + 1;
        }
        if(dp[n] >= inf)	printf("-1\n");
        else	printf("%d\n", dp[n]);
    }
    return 0;
}
