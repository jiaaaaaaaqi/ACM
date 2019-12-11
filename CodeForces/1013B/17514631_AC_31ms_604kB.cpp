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
const int maxn = 100005;
const int maxm = 1000005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
int num[maxn];
bool vis1[maxn];
bool vis2[maxn];

int main() {
    memset(num, 0, sizeof num);
    memset(vis1, 0, sizeof vis1);
    memset(vis2, 0, sizeof vis2);
    scanf("%d%d", &n, &m);
    bool flag = false;
    for(int i=1; i<=n; i++) {
        scanf("%d", &num[i]);
        if(vis1[num[i]]) {
            flag = true;
        }
        vis1[num[i]] = true;
        vis2[num[i]] = true;
    }
    if(flag) {
        printf("0\n");
        return 0;
    }
    for(int i=1; i<=n; i++) {
        int x = num[i] & m;
        if(x == num[i])	continue;
        if(vis1[x]) {
            printf("1\n");
            return 0;
        }
    }
    for(int i=1; i<=n; i++) {
        int x = num[i] & m;
        if(x == num[i])	continue;
        if(vis2[x]) {
            printf("2\n");
            return 0;
        }
        vis2[x] = true;
    }
    printf("-1\n");
    return 0;
}