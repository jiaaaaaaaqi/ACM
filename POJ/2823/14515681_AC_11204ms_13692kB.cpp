#include<map>
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
const int maxn = 1000005;
const int maxm = 305;
using namespace std;

int n, m, tol;
deque< pair<int, int> > q;
int num[maxn];
int ans[maxn];

void calcmin() {
    memset(ans, 0, sizeof ans);
    q.clear();
    for(int i=1; i<=n; i++) {
        while(!q.empty() && q.back().second > num[i])
            q.pop_back();
        while(!q.empty() && q.front().first < i - m + 1)
            q.pop_front();
        q.push_back(make_pair(i, num[i]));
        ans[i] = q.front().second;
    }
}

void calcmax() {
    memset(ans, 0, sizeof ans);
    q.clear();
    for(int i=1; i<=n; i++) {
        while(!q.empty() && q.back().second < num[i])
            q.pop_back();
        while(!q.empty() && q.front().first < i - m + 1)
            q.pop_front();
        q.push_back(make_pair(i, num[i]));
        ans[i] = q.front().second;
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i=1; i<=n; i++)	scanf("%d", &num[i]);
        calcmin();
        for(int i=m; i<=n; i++)	printf("%d%c", ans[i], i == n ? '\n' : ' ');
        calcmax();
        for(int i=m; i<=n; i++)	printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
