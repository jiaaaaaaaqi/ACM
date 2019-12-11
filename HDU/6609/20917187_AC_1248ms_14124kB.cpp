/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月29日 星期一 15时08分04秒
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
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

vector<int> vv;

int a[maxn], c[maxn];
int cnt[maxn<<2];
ll node[maxn<<2];

int getid(int x) {
    return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

void pushup(int rt) {
    cnt[rt] = cnt[rt<<1]+cnt[rt<<1|1];
    node[rt] = node[rt<<1] + node[rt<<1|1];
}

void update(int l, int r, int p, int rt) {
    if(l == r) {
        node[rt] += vv[p-1];
        cnt[rt]++;
        return ;
    }
    int mid = l+r>>1;
    if(p <= mid)    update(l, mid, p, rt<<1);
    else    update(mid+1, r, p, rt<<1|1);
    pushup(rt);
}

int query(int l, int r, ll val, int rt) {
    if(l == r) {
        return val/vv[l-1];
    }
    int mid = l+r>>1;
    if(node[rt<<1] >= val)
        return query(l, mid, val, rt<<1);
    else
        return query(mid+1, r, val-node[rt<<1], rt<<1|1) + cnt[rt<<1];
}

int solve(ll val) {
    return query(1, vv.size(), val, 1);
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        vv.clear();
        mes(node, 0);
        mes(cnt, 0);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            vv.push_back(a[i]);
        }
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        for(int i=1; i<=n; i++) {
            a[i] = getid(a[i]);
        }
        ll sum = 0;
        c[1] = 0;
        sum = vv[a[1]-1];
        update(1, vv.size(), a[1], 1);
        for(int i=2; i<=n; i++) {
            // printf("%d %d\n", i, m-vv[a[i]-1]);
            sum += vv[a[i]-1];
            if(sum <= m) {
                c[i] = 0;
                update(1, vv.size(), a[i], 1);
                continue;
            }
            c[i] = (i-1) - solve(m-vv[a[i]-1]);
            update(1, vv.size(), a[i], 1);
        }
        for(int i=1; i<=n; i++) {
            printf("%d ", c[i]);
        }
        puts("");
    }
    return 0;
}