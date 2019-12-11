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
const int maxn = 100005;
const int maxm = 305;
using namespace std;

int n, m, tol, T;
int suf[maxn];
int ans[maxn];

void init() {
    memset(suf, 0, sizeof suf);
    memset(ans, 0, sizeof ans);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++)	suf[i] = i;
        for(int i=1; i<=m; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            suf[l] = max(suf[l], r);
        }
        int L = 1;
        int R = 0;
        set<int > s;
        s.clear();
        for(int i=1; i<=n; i++)	s.insert(i);
        for(int i=1; i<=n; i++) {
            if(R >= suf[i])	continue;
            while(L < i) {
                s.insert(ans[L]);
                L++;
            }
            while(R < suf[i]) {
                R++;
                int x = *s.begin();
                ans[R] = x;
                s.erase(x);
            }
        }
        for(int i=1; i<=n; i++)	printf("%d%c", ans[i], i==n ? '\n' : ' ');
    }
    return 0;
}
