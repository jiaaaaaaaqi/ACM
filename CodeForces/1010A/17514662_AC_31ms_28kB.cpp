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
const int maxn = 1005;
const int maxm = 100000;
const int mod = 998244353;
using namespace std;

int n, tol, T;
double a[maxn];
double b[maxn];

int main() {
    double m;
    scanf("%d", &n);
    scanf("%lf", &m);
    double m1 = m;
    bool flag = false;
    for(int i=1; i<=n; i++) {
        scanf("%lf", &a[i]);
        if(a[i] == 1)	flag = true;
    }
    for(int i=1; i<=n; i++)	{
        scanf("%lf", &b[i]);
        if(b[i] == 1)	flag = true;
    }
    if(flag) {
        printf("-1\n");
        return 0;
    }
    double ans = 0;
    ans = m / (b[1] - 1);
    m += ans;
    for(int i=n; i>=1; i--) {
        ans = m / (a[i] - 1);
        m += ans;
        if(i != 1) {
            ans = m / (b[i] - 1);
            m += ans;
        }
    }
    printf("%.10f\n", m - m1);
    return 0;
}