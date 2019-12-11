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
const int maxn = 1000;
const int maxm = 400;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
bool maps[300][300];
bool vis[300][300];

void init() {
    memset(maps, false, sizeof maps);
}

bool dfs(int u, int v) {
    if(maps[u][v] == true)	return true;
    for(int i='a'; i<='z'; i++) {
        if(maps[u][i] && !vis[u][i]) {
            vis[u][i] = true;
            if(dfs(i, v)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    char str1[200];
    char str2[200];
    for(int i=1; i<=n; i++) {
        memset(str1, 0, sizeof str1);
        memset(str2, 0, sizeof str2);
        scanf("%s%s", str1, str2);
        char a = str1[0], b = str2[0];
        maps[a][b] = true;
    }
    for(int i='a'; i<='z'; i++)	maps[i][i] = true;
    while(m--) {
        memset(str1, 0, sizeof str1);
        memset(str2, 0, sizeof str2);
        memset(vis, false, sizeof vis);
        scanf("%s%s", str1, str2);
        int len = strlen(str1);
        int len2 = strlen(str2);
        if(len != len2) {
            printf("no\n");
            continue;
        }
        bool flag = true;
        for(int i=0; i<len; i++) {
			char u = str1[i];
			char v = str2[i];
            if(!dfs(u, v)) {
                flag = false;
                break;
            }
        }
        if(flag)	printf("yes\n");
        else	printf("no\n");
    }
    return 0;
}
