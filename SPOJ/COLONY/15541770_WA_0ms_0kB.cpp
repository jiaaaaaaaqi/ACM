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
const int maxn = 110;
const int maxm = 2010;
const int mod = 998244353;
using namespace std;

ll n, m;
int T, tol;
ll x;

void handle(ll n, ll x) {
    int cnt = 0;
    while(n != 0) {
        ll mid = 1 << (n-1);
        if(x > mid) {
            x -= mid;
        } else {
            cnt++;
        }
        n--;
    }
    if(cnt & 1) {
        printf("blue");
    } else {
        printf("red");
    }
    printf("\n");
}

int main() {
	
    scanf("%I64d%I64d", &n, &x);
    handle(n, x+1);
    return 0;
}
