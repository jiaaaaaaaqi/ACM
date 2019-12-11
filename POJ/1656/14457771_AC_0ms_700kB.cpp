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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100;
const int maxm = 105;
using namespace std;

int n, m, tol;
int maxans, minans;
int node[maxn][maxn];


int main() {
    int k;
    n = 101;
    while(~scanf("%d", &k)) {
        char str[10];
        memset(node, 0, sizeof node);
        while(k--) {
            scanf("%s", str);
            int x1, y1, r;
            scanf("%d%d%d", &x1, &y1, &r);
            int x2 = x1 + r - 1;
            int y2 = y1 + r - 1;
            if(str[0] == 'W') {
				for(int i=x1; i<=x2; i++) {
					for(int j=y1; j<=y2; j++) {
						node[i][j] = 0;
					}
				}
            } else if(str[0] == 'B') {
				for(int i=x1; i<=x2; i++) {
					for(int j=y1; j<=y2; j++) {
						node[i][j] = 1;
					}
				}
            } else if(str[0] == 'T') {
				int ans = 0;
				for(int i=x1; i<=x2; i++) {
					for(int j=y1; j<=y2; j++) {
						if(node[i][j]) {
							ans++;
						}
					}
				}
				printf("%d\n", ans);
            }
        }
    }
    return 0;
}
