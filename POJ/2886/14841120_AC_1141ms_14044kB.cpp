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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 500005;
const int maxm = 305;
using namespace std;

int n, m, tol, T;
struct Node {
    char name[15];
    int k;
};
Node node[maxn];
int sum[maxn << 2];
int RPrime[]= {
    0,1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,
    20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,
    554400
};

int fact[]= {
    0,1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,
    144,160,168,180,192,200,216
};

void pushup(int root) {
    sum[root] = sum[root << 1] + sum[root << 1 | 1];
}

void build(int left, int right, int root) {
    if(left == right) {
        sum[root] = 1;
        return ;
    }
    int mid = (left +right) >> 1;
    build(left, mid, root << 1);
    build(mid+1, right, root << 1 | 1);
    pushup(root);
}

int update(int left, int right, int k, int root) {
    if(left == right) {
        sum[root]--;
        return left;
    }
    int mid = (left + right) >> 1;
    int ans;
    if(sum[root << 1] >= k)	ans = update(left, mid, k, root << 1);
    else	ans = update(mid+1, right, k-sum[root << 1], root << 1 | 1);
    pushup(root);
    return ans;
}

int main() {
    int k;
    while(~scanf("%d%d", &n, &k)) {
        for(int i=1; i<=n; i++)
            scanf("%s%d", node[i].name, &node[i].k);
        build(1, n, 1);
        int ansnum;
        for(int i=1; RPrime[i]<=n; i++) {
            m = RPrime[i];
            ansnum = fact[i];
        }
        tol = n;
        int pos;
        for(int i=1; i<=m; i++) {
            tol--;
            pos = update(1, n, k, 1);
            if(tol == 0)	break;
            if(node[pos].k > 0)
                k = ((k + node[pos].k - 2)  % tol + tol) %tol + 1;
            else
                k = ((k + node[pos].k - 1) % tol + tol) % tol + 1;

        }
        printf("%s %d\n", node[pos].name, ansnum);
    }
    return 0;
}
/*
7 3
a 3
b 2
c -5
d 4
e 8 
f 2 
g -6

*/

