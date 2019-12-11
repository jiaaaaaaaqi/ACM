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
bool vis[mx];
bool mark1[mx] = {0};
bool mark2[mx] = {0};
int path1[mx];
int path2[mx];
int maxn;

double TIME() {
    return 1.0*clock()/CLOCKS_PER_SEC;
}

void dfs(int st, int u, int x) {
    if(vis[u]) {
        if(u == st) {
            if(maxn == 0)	tol++;
            if(maxn && x < maxn)	return ;
            else {
                memset(path2, 0, sizeof path2);
                for(int i=0; i<=x; i++)	path2[i] = path1[i];
                maxn = x;
            }
        }
        return ;
    }
    if(maxn && x < maxn)	return ;
    vis[u] = true;
    int len = mat[u].size();
    for(int i=0; i<len; i++) {
        int v= mat[u][i];
        path1[x] = v;
        dfs(st, v, x+1);
    }
    vis[u] = false;
    return ;
}

int low[mx];
int dfn[mx];
int sta[mx];
int cnt1=0;
int top=0, d=0;;
int stasize = 0;

void DFS(int u) {
    int v;
    dfn[u] = low[u] = ++cnt1;
    sta[stasize++] = u;
    vis[u] = true;
    int len = mat[u].size();
    for(int i=0; i<len; i++) {
        v = mat[u][i];
        if(!dfn[v]) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        top++;
        if(sta[stasize-1] != u)	d++;
        do {
            v = sta[--stasize];
            vis[v] = false;
        } while(u != v);
    }
}

void tarjan() {
    for(int i=1; i<=n; i++) {
        if(!dfn[i]) {
            DFS(i);
        }
    }
}

int st, ed;
void Dfs(int he, int u, bool &flag, bool l, int x) {
//	printf("%d %d %d\n", mark1[u], he, l);
    if(mark1[u] && l) {
        flag = true;
        ed = u;
        for(int i=0; i<x-1; i++) {
            int u1 = path1[i];
            int v1 = path1[i+1];
            vector<int>::iterator it = find(mat[u1].begin(), mat[u1].end(), v1);
            mat[u1].erase(it);
        }
        return ;
    }
    vis[u] = true;
    int len = mat[u].size();
    for(int i=0; i<len; i++) {
        int v = mat[u][i];
        if(vis[v] && v!=he)	continue;
        path1[x] = v;
        Dfs(he, v, flag, 1, x+1);
        if(flag)	return ;
    }
    vis[u] = false;
}

void find(int cn) {
    int i = 0;
    bool flag = false;
    while(1) {
        if(path2[i] == st && !flag) {
            flag = true;
        } else if(path2[i] == ed) {
            return ;
        } else {
            if(flag) {
                mark2[path2[i]] = true;
            }
        }
        i++;
        if(i == cn)	i = 0;
    }
}

int solve(int cn) {
    for(int i=0; i<cn; i++) {
        if(mark2[path2[i]] == false)	return path2[i];
    }
    return -1;
}

int main() {
    tol = 0;
    scanf("%d%d", &n, &m);
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        mat[u].push_back(v);
    }
    memset(low, 0, sizeof low);
    memset(dfn, 0, sizeof dfn);
    d = cnt1 = top = stasize = 0;
    tarjan();
    if(d != 1) {
        printf("-1\n");
        return 0;
    }

    maxn = 0;
    path1[0] = 1;
    dfs(1, 1, 1);
    for(int i=0; i<maxn; i++)	mark1[path2[i]] = true;

//	printf("\n");
//	for(int i=1; i<=n; i++) {
//		for(int j=0; j<mat[i].size(); j++) {
//			printf("%d %d\n", i, mat[i][j]);
//		}
//	}
    for(int i=0; i<maxn-1; i++) {
        int u = path2[i];
        int v = path2[i+1];
        vector<int>::iterator it = find(mat[u].begin(), mat[u].end(), v);
        mat[u].erase(it);
    }

    memset(low, 0, sizeof low);
    memset(dfn, 0, sizeof dfn);
    d = cnt1 = top = stasize = 0;
    tarjan();
    if(d > 1) {
        printf("-1\n");
        return 0;
    }

//	printf("\n");
//	for(int i=1; i<=n; i++) {
//		for(int j=0; j<mat[i].size(); j++) {
//			printf("%d %d\n", i, mat[i][j]);
//		}
//	}

    bool flag = true;
    st = 0;
    while(flag) {
        flag = false;
        for(int i=0; i<maxn; i++) {
            if(mark2[path2[i]])	continue;
            memset(path1, 0, sizeof path1);
            memset(vis, 0, sizeof vis);
            st = path2[i];
            path1[0] = st;
            Dfs(st, st, flag, 0, 1);
            if(flag) {
                find(maxn);
                break;
            }
        }
    }
    int ans = solve(maxn);
    cout << ans << endl;
    return 0;
}
