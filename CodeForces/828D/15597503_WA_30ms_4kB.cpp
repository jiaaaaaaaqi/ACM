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
const int maxn = 2e5+10;
const int maxm = 250;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;

int main() {
//    while(1) {
    scanf("%d%d", &n, &m);
    int l, r, mi, pos;
    if(n % 2 == 0) {
        pos = n/2;
        mi = (m-2) / 2;
        l = pos - mi + 1;
        r = pos + mi;
        if(m % 2 == 1)	l--;
    } else {
        pos = n/2 + 1;
        mi = (m-2) / 2;
        l = pos - mi;
        r = pos + mi;
        if(m % 2 == 0)	r--;
    }
//        printf("%d %d\n", l, r);
    int ans = n - m + 1;
    printf("%d\n", ans);
    for(int i=1; i<l-1; i++)	printf("%d %d\n", i, i+1);
    printf("%d %d\n", l-1, r+1);
    for(int i=l; i<=r; i++)	printf("%d %d\n", i, r+1);
    for(int i=r+1; i<n; i++)printf("%d %d\n", i, i+1);
//    }
    return 0;
}
