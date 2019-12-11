/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月05日 星期一 14时56分12秒
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

struct Node{
    int num[15];
} node[maxn];
int a[25];

bool cmp1(Node a, Node b) {
    for(int i=1; i<n; i++) {
        int x = a.num[i+1]-a.num[i];
        int y = b.num[i+1]-b.num[i];
        if(x == y)  continue;
        else    return x<y;
    }
    return 0;
}

bool cmp2(Node a, Node b) {
    for(int i=0; i<n; i++) {
        int x = a.num[i+1]-a.num[i];
        int y = b.num[i+1]-b.num[i];
        if(x == y)  continue;
        else    return x<y;
    }
    return 0;
}

int main() {
    // freopen("out4", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        int k;
        scanf("%d%d", &n, &k);
        if(n <= 8) {
            for(int i=1; i<=n; i++) {
                a[i] = i;
            }
            int cnt = 0;
            do {
                cnt++;
                for(int i=1; i<=n; i++) {
                    node[cnt].num[i] = a[i];
                }
            } while(next_permutation(a+1, a+1+n));
            sort(node+1, node+1+cnt, cmp1);
            for(int i=1; i<=n; i++) {
                printf("%d%c", node[k].num[i], i==n ? '\n' : ' ');
            }
        } else {
            int x = 8;
            for(int i=n-1; i>=n-8; i--) {
                a[x--] = i;
            }
            // for(int i=1; i<=8; i++) {
            //     printf("%d%c", a[i], i==8 ? '\n' : ' ');
            // }
            int nn = n;
            n = 8;
            int cnt = 0;
            do {
                cnt++;
                for(int i=1; i<=8; i++) {
                    node[cnt].num[i] = a[i];
                }
                node[cnt].num[0] = 0;
            } while(next_permutation(a+1, a+1+8));
            // sort(node+1, node+1+cnt, cmp2);
            n = nn; 
            if(n >= 9)
                printf("%d ", n);
            for(int i=1; i<=n-9; i++) {
                printf("%d ", i);
            }
            for(int i=1; i<=8; i++) {
                printf("%d%c", node[k].num[i], i==8 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
