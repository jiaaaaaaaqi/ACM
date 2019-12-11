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
const int maxn = 105;
const int maxm = 50005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
char s[maxn][maxn];
bool vis[maxn][maxn];
struct Node {
    int x;
    int y;
    int r;
};
Node node[maxm];

bool check(int i, int j, int k) {
    if(i-k < 1)	return false;
    if(i+k > n)	return false;
    if(j-k < 1)	return false;
    if(j+k > m)	return false;
    return true;
}

int main() {
    memset(vis, 0, sizeof vis);
    scanf("%d%d", &n, &m);
    tol = 0;
    for(int i=1; i<=n; i++)	scanf("%s", s[i]+1);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int k = 1;
            bool f = false;
            for(; k<=max(n, m); k++) {
                if(!check(i, j, k)) break;
                if(s[i][j] == '*' && s[i][j-k] == '*' && s[i][j+k] == '*' && s[i-k][j] == '*' && s[i+k][j] == '*') {
                    f = true;
                    vis[i][j] = true;
                    vis[i-k][j] = true;
                    vis[i+k][j] = true;
                    vis[i][j-k] = true;
                    vis[i][j+k] = true;
                } else	break;
            }
            if(f) {
                k--;
                node[++tol].x = i;
                node[tol].y = j;
                node[tol].r = k;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i][j] == '*' && !vis[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", tol);
    for(int i=1; i<=tol; i++) {
        printf("%d %d %d\n", node[i].x, node[i].y, node[i].r);
    }
    return 0;
}