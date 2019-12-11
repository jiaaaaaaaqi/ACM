/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月14日 星期三 12时14分47秒
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    char name[20];
    int p, t;
    bool operator < (Node a) const {
        if(p == a.p)    return t<a.t;
        else    return p>a.p;
    }
} node[maxn];

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) {
            mes(node[i].name, 0);
            node[i].p = node[i].t = 0;
        }
        for(int i=1; i<=n; i++) {
            scanf("%s%d%d", node[i].name+1, &node[i].p, &node[i].t);
        }
        int goal = n*m;
        if(goal%10 == 5) {
            sort(node+1, node+1+n);
            goal /= 10;
            printf("%s\n", node[goal+1].name+1);
        } else {
            printf("Quailty is very great\n");
        }
    }
    return 0;
}