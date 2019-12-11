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
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)
#define double long double

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 550;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
const double eps = 1e-8;
using namespace std;

int n, m;
int tol, T;

double x[maxn];
double a, b, c, d;

bool judge(double num, double i) {
    if (fabs(a*i*i*i + b*i*i + c*i + d - num) > eps) return false;
    return true;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        memset(x, 0, sizeof x);
        scanf("%d", &n);
        for(int i=1; i<=n; i++)	
			cin >> x[i];
        if(n <= 4) {
            printf("YES\n");
            continue;
        } else {
            double x1 = x[1];
            double x2 = x[2];
            double x3 = x[3];
            double x4 = x[4];

			double tmp = -x1 + 3*x2 - 3*x3 + x4;
			a = tmp / 6;
			tmp = x1 + x3 - 2*x2 - 12*a;
			b = tmp / 2;
			c = x2 - x1 - 7*a - 3*b;
			d = x1 - a - b - c;
            bool flag = true;
//            printf("%Lf %Lf %Lf %Lf\n", a, b, c, d);
            for(int i=5; i<=n; i++) {
                //ll tmp1 = (double)(a*i*i*i + b*i*i + c*i + d);
                if(!judge(x[i], i)) {
                    flag = false;
                    break;
                }
            }
            if(flag)	printf("YES\n");
            else		printf("NO\n");
        }
    }
    return 0;
}
