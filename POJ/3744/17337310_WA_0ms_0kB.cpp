#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
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
const int    maxn = 1e8 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[1000];
double dp[1000];
bool vis[100000005];

int main(){
    double p, q;
    while(scanf("%d%lf", &n,&p)!=EOF) {
        q = 1.0 - p;
        tol = 0;
        a[++tol] = 1;
        vis[tol] = 0;
        for(int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            if(x == 1)
                vis[1] = 1;
            a[++tol] = x;
            vis[tol] = 1;
            a[++tol] = x+1;
            vis[tol] = 0;
            a[++tol] = x+2;
            vis[tol] = 0;
        }
        if (vis[1]) {
            printf("0.0000000\n");
            continue;
        }
        dp[1] = 1.0;
        for(int i = 2; i <= tol; i++) {
            if(vis[i]) {
                dp[i] = 0.0;
            } else{
                dp[i] = 0.0;
                if(i != 2) {
                    dp[i] += q * dp[i - 2];
                }
                dp[i] += p * dp[i - 1];
            }
            //printf("%d  %.7f\n", i, dp[i]);
        }
        printf("%.7f\n", dp[tol]);
    }
    return 0;
}