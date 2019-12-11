/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月12日 星期一 16时03分49秒
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int num;
    ll cnt;
    Node() {
    }
    Node(int a, int b) {
        num = a, cnt = b;
    }
    bool operator < (Node a) const {
        return cnt==a.cnt ? num<a.num : cnt>a.cnt;
    }
} node[maxn];
vector<ull> vv;
ll mp1[maxn], mp2[maxn];

int getid(ull x) {
    return lower_bound(vv.begin(), vv.end(), x) - vv.begin()+1;
}

ull a[maxn], b[maxn];
unsigned long long k1, k2, mod;
unsigned long long rng() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        int p;
        scanf("%d%d%d", &n, &m, &p);
        vv.clear();
        if(p == 2) {
            scanf("%llu%llu%llu", &k1, &k2, &mod);
            for (int i = 0; i < n; ++i) {
                a[i] = rng() % mod;
                vv.pb(a[i]);
            }
            scanf("%llu%llu%llu", &k1, &k2, &mod);
            for (int i = 0; i < m; ++i) {
                b[i] = rng() % mod;
                vv.pb(b[i]);
            }
        } else {
            for(int i=0; i<n; i++) {
                scanf("%llu", &a[i]);
                vv.pb(a[i]);
            }
            for(int i=0; i<m; i++) {
                scanf("%llu", &b[i]);
                vv.pb(b[i]);
            }
        }
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        int len = vv.size();
        for(int i=1; i<=len; i++)  mp1[i] = mp2[i] = 0;
        for(int i=0; i<n; i++)  a[i] = getid(a[i]), mp1[a[i]]++;
        for(int i=0; i<m; i++)  b[i] = getid(b[i]), mp2[b[i]]++;
        tol = 0;
        for(int i=1; i<=len; i++) {
            if(mp1[i] == 0) continue;
            if(mp2[i] == 0) continue;
            node[++tol] = Node(i, mp1[i] + mp2[i]);
        }
        sort(node+1, node+1+tol);
        ll sum1, sum2;
        sum1 = n, sum2 = m;
        int flag = 0;
        for(int i=1; i<=tol; i++) {
            flag = !flag;
            if(flag == 1) {
                sum2 -= mp2[node[i].num];
            } else {
                sum1 -= mp1[node[i].num];
            }
        }
        if(sum1 > sum2) printf("Cuber QQ\n");
        else    printf("Quber CC\n");
    }
    return 0;
}