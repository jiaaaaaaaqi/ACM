/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月21日 星期三 15时50分37秒
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
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
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int q[maxn];
int a[maxn], L[maxn], R[maxn];
int pre[maxn], suf[maxn], p[maxn];
int vis[maxn];

void getR() {
	for(int i=1; i<=n; i++)	vis[i] = 0;
    int head=1, tail = 0;
    for(int i=1; i<=n; i++) {
        while(head<=tail && q[head]<=vis[a[i]]) {
            R[q[head]] = i-1;
            head++;
        }
        while(head<=tail && a[i]>a[q[tail]]) {
            R[q[tail]] = i-1;
            tail--;
        }
        q[++tail] = i;
        vis[a[i]] = i;
    }
    while(head<=tail) {
        R[q[tail]] = n;
        vis[a[q[tail]]] = 0;
        tail--;
    }
//     cout << "R:" << endl;
//     for(int i=1; i<=n; i++)    printf("%d%c", R[i], i==n ? '\n' : ' ');
}

void getL() {
	for(int i=1; i<=n; i++)	vis[i] = inf;
    int head=1, tail = 0;
    for(int i=n; i>=1; i--) {
		while(head<=tail && q[head]>=vis[a[i]]) {
            L[q[head]] = i+1;
            head++;
        }
        while(head<=tail && a[i]>a[q[tail]]) {
            L[q[tail]] = i+1;
            tail--;
        }
        q[++tail] = i;
        vis[a[i]] = i;
    }
    while(head<=tail) {
        L[q[tail]] = 1;
        vis[a[q[tail]]] = 0;
        tail--;
    }
    // cout << "L:" << endl;
    // for(int i=1; i<=n; i++)    printf("%d%c", L[i], i==n ? '\n' : ' ');
}

void get_pre_suf() {
    for(int i=1; i<=n; i++)
        p[i] = -1;
    for(int i=1; i<=n; i++) {
        pre[i] = p[a[i]];
        p[a[i]] = i;
    }
    for(int i=1; i<=n; i++)
        p[i] = -1;
    for(int i=n; i>=1; i--) {
        suf[i] = p[a[i]];
        p[a[i]] = i;
    }
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        int k;
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        getR();
        getL();
        get_pre_suf();
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            // printf("max=%d L=%d R=%d\n", a[i], L[i], R[i]);
            int lenl = i-L[i]+1, lenr = R[i]-i+1;
            int len = max(1, a[i] - k);
            // printf("len%d = %d\n", i, len);
            if(lenl < lenr) {
                int tmpr = R[i];
                for(int j=i; j>=L[i]; j--) {
                    int nex;
                    if(suf[j] == -1)
                        nex = tmpr;
                    else
                        nex = suf[j]-1;
                    tmpr = min(tmpr, nex);
                    int RR = max(i, j+len-1);
                    ans += max(0, tmpr-RR+1);
                    // printf("!!!%d L=%d R=%d ans=%d\n", i, j, RR, max(0, tmpr-RR+1));
                }
            } else {
                int tmpl = L[i];
                for(int j=i; j<=R[i]; j++) {
                    int nex;
                    if(pre[j] == -1)
                        nex = tmpl;
                    else
                        nex = pre[j]+1;
                    tmpl = max(tmpl, nex);
                    int LL = min(i, j-len+1);
                    ans += max(0, LL-tmpl+1);
                    // printf("@@@%d L=%d R=%d ans=%d\n", i, LL, j, max(i, LL-tmpl+1));
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
