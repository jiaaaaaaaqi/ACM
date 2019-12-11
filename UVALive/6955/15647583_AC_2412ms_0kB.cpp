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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int maxm = 1005000;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
struct Node {
    ll x, y;
};
Node node[maxn];

int check(int i, int j, int k) {
    ll ans1 = (node[i].x - node[j].x) * (node[i].y - node[k].y);
    ll ans2 = (node[i].x - node[k].x) * (node[i].y - node[j].y);
    if(ans1 == ans2)	return 1;
    else	return 0;
    }

//x1-x2  x1-x3
//y1-y2  y1-y3

int main() {
    srand(time(0));
    while(~scanf("%d%d", &n, &m)) {
        memset(node, 0, sizeof node);
        for(int i=0; i<n; i++)	scanf("%lld%lld", &node[i].x, &node[i].y);
        if(n <= 2) {
            printf("possible\n");
            continue;
        }
        int ans = n*m;
        bool flag = false;
        for(int T=1; T<=1000; T++) {
            int sum = 2;
            int x = rand() % n;
            int y = rand() % n;
            while(x == y)	y = rand() % n;
            for(int i=0; i<n; i++) {
                if(i == x || i == y)	continue;
                sum += check(x, y, i);
                if(sum * 100 >= ans) {
                    flag = true;
                    break;
                }
            }
            if(flag)	break;
        }
        printf("%s\n", flag ? "possible" : "impossible");
    }
    return 0;
}
