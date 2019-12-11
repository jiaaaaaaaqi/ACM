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
#define  INOPEM     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef long long int ll;
typedef unsigned long long int ull;
const int    maxn = 1e5 + 10;
const int    maxm = 100000;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
char s[maxn];
int ans1[maxn];
int cnt[maxn];

void init(int len) {
    for(int i=0; i<=len; i++) {
        ans1[i] = 0;
        cnt[i] = 0;
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        init(len);
        int t = 0;
        ll sum = 0;
        for (int i = 1; i <= len; i++) {
            int digit = s[i] - '0' + t;
            if (digit & 1) {
                ans1[i] = ans1[i - 1] + 1;
                cnt[i] = 1;
                t++;
            } else {
                ans1[i] = ans1[i - 1] + 2;
                cnt[i] = 0;
                t += 2;
            }
            sum += ans1[i];
        }
        ll ans = 0;
        ll to = 0;
        for (int i = 1; i <= len; i++) {
            if(s[i] == '1') {
                if (cnt[i] == 1)
                    ans += sum;
                else
                    ans += sum - (len - i + 1);
            } else if(s[i] == '0') {
                if(cnt[i] == 1)
                    ans += sum + (len - i + 1);
                else
                    ans += sum;
            }
            ans1[i] -= to;
            sum -= (len-i+1) * ans1[i];
            to += ans1[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
