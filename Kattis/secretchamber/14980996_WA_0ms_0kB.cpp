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
bool maps[50][50];
bool vis[50][50];

void init() {
    memset(maps, 0, sizeof maps);
}

bool dfs(int u, int v) {
    if(maps[u][v] == true)	return true;
    for(int i=1; i<=26; i++) {
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
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i=1; i<=n; i++) {
            char str1[10], str2[10];
            scanf("%s%s", str1, str2);
            char a = str1[0], b = str2[0];
            int u = a - 'a' + 1;
            int v = b - 'a' + 1;
            maps[u][v] = true;
        }
        /*
        for(int i=1; i<=26; i++) {
			for(int j=1; j<=26; j++) {
				printf("%d ", maps[i][j]);
			}
			printf("\n");
        }
        */
        char str1[100];
        char str2[100];
        while(m--) {
            memset(vis, 0, sizeof vis);
            scanf("%s%s", str1, str2);
            int len = strlen(str1);
            int len2 = strlen(str2);
            if(len != len2) {
                printf("no\n");
                continue;
            }
            bool flag = true;
            for(int i=0; i<len; i++) {
                int u = str1[i] - 'a' + 1;
                int v = str2[i] - 'a' + 1;
                if(u == v)	continue;
                if(!dfs(u, v)) {
                    flag = false;
                    break;
                }
            }
            if(flag)	printf("yes\n");
            else	printf("no\n");
        }
    }
    return 0;
}
