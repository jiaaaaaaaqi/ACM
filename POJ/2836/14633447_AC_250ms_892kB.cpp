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
const int maxn = 20;
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
struct Node {
    int x;
    int y;
};
Node node[maxn];
int dp[1<<16];
int state[1<<16];
int area[1<<16];

void init() {
    tol = 0;
    memset(dp, inf, sizeof dp);
    memset(node, 0, sizeof node);
    memset(area, 0, sizeof area);
    memset(state, 0, sizeof state);
}

void handle() {
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int s = (1 << (i-1)) | (1 << (j-1));
            for(int k=1; k<=n; k++) {
                if((node[k].x - node[i].x) * (node[k].x - node[j].x) <= 0) {
                    if((node[k].y - node[i].y) * (node[k].y - node[j].y) <= 0) {
						s |= (1 << (k-1));
                    }
                }
            }
            int a;
            if(node[i].x-node[j].x == 0)	a = abs(node[i].y - node[j].y);
            else if(node[i].y-node[j].y == 0)	a = abs(node[i].x - node[j].x);
			else	a = abs(node[i].y - node[j].y) * abs(node[i].x - node[j].x);
            state[tol] = s;
            area[tol++] = a;
        }
    }
}

int main() {
    while(scanf("%d", &n), n) {
        init();
        for(int i=1; i<=n; i++)	scanf("%d%d", &node[i].x, &node[i].y);
        handle();
        dp[0] = 0;
        for(int i=0; i<(1<<n); i++) {
			for(int j=0; j<tol; j++) {
				dp[i|state[j]] = min(dp[i|state[j]], dp[i] + area[j]);
			}
        }
        printf("%d\n", dp[(1<<n) - 1]);
    }
    return 0;
}
