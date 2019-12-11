#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEM     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 2147493647;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

struct Mat {
    ll mat[8][8];
};

Mat mfmul(Mat a, Mat b) {
    Mat ans;
    mes(ans.mat, 0);
    for (int k = 1; k <= 7; k++) {
        for (int i = 1; i <= 7; i++) {
            for (int j = 1; j <= 7; j++) {
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                ans.mat[i][j] %= mod;
            }
        }
    }
    return ans;
}

Mat mfpow(Mat A, int b) {
    Mat ans;
    mes(ans.mat, 0);
    for (int i = 1; i <= 7; i++)
        ans.mat[i][i] = 1;
    while (b) {
        if (b & 1)
            ans = mfmul(ans, A);
        A = mfmul(A, A);
        b >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        ll f1, f2;
        scanf("%lld%lld%lld", &n, &f1, &f2);
        if (n == 1) {
            printf("%lld\n", f1);
            continue;
        }
        if (n == 2) {
            printf("%lld\n", f2);
            continue;
        }
        Mat A;
        mes(A.mat, 0);
        A.mat[1][1] = 1;
        A.mat[1][2] = 2;
        A.mat[1][3] = 1;
        A.mat[1][4] = 4;
        A.mat[1][5] = 6;
        A.mat[1][6] = 4;
        A.mat[1][7] = 1;
        A.mat[2][1] = 1;
        A.mat[3][3] = 1;
        A.mat[3][4] = 4;
        A.mat[3][5] = 6;
        A.mat[3][6] = 4;
        A.mat[3][7] = 1;
        A.mat[4][4] = 1;
        A.mat[4][5] = 3;
        A.mat[4][6] = 3;
        A.mat[4][7] = 1;
        A.mat[5][5] = 1;
        A.mat[5][6] = 2;
        A.mat[5][7] = 1;
        A.mat[6][6] = 1;
        A.mat[6][7] = 1;
        A.mat[7][7] = 1;
        A = mfpow(A, n - 2);
        ll ans = A.mat[1][1] * f2 % mod + A.mat[1][2] * f1 % mod;
        ans %= mod;
        ans += A.mat[1][3] * 16 % mod + A.mat[1][4] * 8 % mod + A.mat[1][5] * 4 % mod;
        ans %= mod;
        ans += A.mat[1][6] * 2 % mod + A.mat[1][7];
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}