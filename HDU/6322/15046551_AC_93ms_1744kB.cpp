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
const int maxn = 100005;
const int maxm = 1000005;
const int mod = 10007;
using namespace std;

int T, tol;
int n, m;

int main() {
    scanf("%d", &T);
    while(T--) {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", n==1 ? 5 : n+5);
    }
    return 0;
}