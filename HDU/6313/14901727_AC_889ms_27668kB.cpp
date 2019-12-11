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
const int maxn = 100005;
const int maxm = 100000;
const int mod = 998244353;
using namespace std;

int n, m, tol, T;
int block;
int maps[3000][3000];

int main() {
    int p = 47;
    for(int i=0; i<p; i++)
        for(int j=0; j<p; j++)
            for(int k=0; k<p; k++)
                maps[i*p+j][ k*p+(j*k+i)%p] = 1;
    n = 2000;
    printf("%d\n", n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d", maps[i][j]);
        }
        printf("\n");
    }
    return 0;
}
