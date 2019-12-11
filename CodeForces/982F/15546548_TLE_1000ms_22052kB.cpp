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

using namespace std;
const int mx = 5e5 + 5;
vector <int> mat[mx];
int n, m, tol;
int vis[mx];
int mark[mx];
int path[mx];
int path2[mx];
int maxn;
int cnt = 0;
void dfs(int st, int u, int x) {
	cnt++;
    if(vis[u]) {
        if(u == st) {
            if(maxn == 0)	tol++;
            if(maxn && x > maxn)	return ;
            else {
                memset(path2, 0, sizeof path2);
                for(int i=0; i<=x; i++)	path2[i] = path[i];
                maxn = x;
            }
        }
        return ;
    }
    if(maxn && x > maxn)	return ;
    vis[u] = true;
    int len = mat[u].size();
    for(int i=0; i<len; i++) {
        int v= mat[u][i];
        path[x] = v;
        dfs(st, v, x+1);
    }
    vis[u] = false;
    return ;
}

int main() {
    tol = 0;
    scanf("%d%d", &n, &m);
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        mat[u].push_back(v);
    }
    tol>>=1;
    bool flag = true;
    while(flag) {
        flag = false;
        maxn = 0;
        for(int i = 1; i <= n; i++) {
            if(!mark[i]) {
                memset(vis, 0, sizeof vis);
                path[0] = i;
                dfs(i, i, 1);
            }
        }
        if(maxn) {
            flag = true;
            for(int i=maxn-2; i>=0; i--) {
                mark[path2[i]]++;
            }
        }
        if(cnt>=1e7)
			break;
    }
//    printf("\n");




//    for(int i=1; i<=n; i++)	printf("%d %d\n", i, mark[i]);
    int ans = 1;
    for(int i=1; i<=n; i++)
        if(mark[ans] <  mark[i])
            ans = i;
    if(mark[ans] >= tol)	printf("%d\n", ans);
    else	printf("-1\n");
    return 0;
}
